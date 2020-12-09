#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Outpost2DLL.h>
#include <OP2Helper.h>
#include <HFL.h>
#include "ScoutRushFx.h"

/*
  12/9/2020
   - OP2 1.4 compatibility changes (removed IUnit references, using HFL instead)
   - Players are no longer forced to be a specific colony based on their player slot.
   - Blight/lava time limits removed.
   - BaseBuilder no longer needed.
   - Old memes removed.
*/

Export char MapName[]			= "PLY12.map";
Export char LevelDesc[]		    = "6P, LoS, 'Scout Rush'";
Export char TechtreeName[]		= "scouttek.txt";
Export AIModDesc DescBlock	    = { MultiLastOneStanding, 6, 12, 1 };

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		if (HFLInit() == HFLCANTINIT)
		{
			return false;
		}

	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		HFLCleanup();
	}

	return TRUE;
}

Export int InitProc()
{
	// Create player bases
	SetupP1(0);
	SetupP2(1);
	SetupP3(2);
	SetupP4(3);
	SetupP5(4);
	SetupP6(5);

	// Enforce player alliances
	switch (TethysGame::NoPlayers())
	{
	case 6:
		Player[5].AllyWith(3);
		Player[3].AllyWith(5);
		Player[5].AllyWith(1);
		Player[1].AllyWith(5);
	case 5:
		Player[4].AllyWith(2);
		Player[2].AllyWith(4);
		Player[4].AllyWith(0);
		Player[0].AllyWith(4);
	case 4:
		Player[3].AllyWith(1);
		Player[1].AllyWith(3);
	case 3:
		Player[2].AllyWith(0);
		Player[0].AllyWith(2);
	default:
		break;
	}

	// Unit-only missions have this annoying thing where player-owned buildings are disabled even if they have no operational requirements.
	// Automatically idling and reactivating them fixes this.  So, first we idle all structures...
    for(int i = 0; i < TethysGame::NoPlayers(); i++)
    {
        UnitEx curUnit;
        PlayerBuildingEnum unitEnum(i, mapNone);
        while (unitEnum.GetNext(curUnit))
            curUnit.DoIdle();
    }

	// Then re-activate them before the players notice what happened.
    CreateTimeTrigger( 1, 1,  10, "Delayed" );

    SongIds newPlaylist[] = { songEP51, songEP52, songEP41, songEP42, songEP43, songStatic04};
    TethysGame::SetMusicPlayList(6, 0, newPlaylist);

	// Morale option is ignored, since it handles something else (and you have no population anyways...)
	TethysGame::ForceMoraleGreat(-1);

	// Day/night
	TethysGame::SetDaylightEverywhere(1);
	if (TethysGame::UsesDayNight() == 1)
	{
		TethysGame::SetDaylightEverywhere(0);
		GameMap::SetInitialLightLevel(200);
		TethysGame::SetDaylightMoves(1);
	}

	// Annoying disasters (arbitrary time limit that made no sense removed).
    if (TethysGame::CanHaveDisasters() == 1)
	{
		CreateTimeTrigger( 1, 0, 2200, 3300, "Quakes");
		CreateTimeTrigger( 1, 0, 3100, 4500, "Vortex");
		CreateTimeTrigger( 1, 0, 2800, 3900, "EMPMissiles");
	}


	VictoryDefeat();

	return 1;
}

// As above, this automatically reactivates disabled structures at the start of the game.
Export void Delayed()
{
    for(int i = 0; i < TethysGame::NoPlayers(); i++)
    {
        UnitEx curUnit;
        PlayerBuildingEnum unitEnum(i, mapNone);
        while (unitEnum.GetNext(curUnit))
            curUnit.DoUnIdle();
    }
}

Export void Quakes()
{
    TethysGame::SetEarthquake(81+TethysGame::GetRand(161),4+TethysGame::GetRand(56),TethysGame::GetRand(5));
}


// Something to do with the EMP Missile disaster
int e;
int numMissiles;

Export void EMPMissiles()
{
	e = 0;
    numMissiles = TethysGame::GetRand(7)+4;
	CreateTimeTrigger( 1, 1, TethysGame::GetRand(201)+100, "Missiles");
}

Export void Missiles()
{
	if (e < numMissiles)
	{
        int z = TethysGame::GetRand(5+1);
        TethysGame::SetEMPMissile(113, 55, 6, 81+TethysGame::GetRand(161),4+TethysGame::GetRand(56));
        CreateTimeTrigger( 1, 1, TethysGame::GetRand(201)+100, "Missiles");
        e++;
	}
}


Export void Vortex()
{
    TethysGame::SetTornado(81+TethysGame::GetRand(161),4+TethysGame::GetRand(56),TethysGame::GetRand(25)+10,81+TethysGame::GetRand(161),4+TethysGame::GetRand(56),0);
}

Export void AIProc()
{
    for(int i = 0; i < TethysGame::NoPlayers(); i++)
    {
        //unidle code
        UnitEx curUnit;
        PlayerBuildingEnum unitEnum(i, mapNone);
        while (unitEnum.GetNext(curUnit))
        {
            if((curUnit.GetDamage() == 0) && (curUnit.GetLastCommand() != ctMoDevelop) &&
                (curUnit.GetLastCommand() != ctMoIdle) && (curUnit.GetType() == mapGuardPost))
                curUnit.DoIdle();
            else if((curUnit.GetDamage() == 0) && (curUnit.GetLastCommand() == ctMoIdle) && (curUnit.GetType() == mapGuardPost))
            {
                curUnit.SetDamage(1);
                curUnit.DoUnIdle();
            }
        }
    }
}

void __cdecl GetSaveRegions(struct BufferDesc &bufDesc)
{
	bufDesc.bufferStart = 0;
	bufDesc.length = 0;
}


int StatusProc()
{
	return 0; // must return 0
}

Export void NoResponseToTrigger()
{
}
