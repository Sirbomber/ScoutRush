#include <Outpost2DLL.h>
#include "ScoutRushFx.h"

Unit cc[6];
bool hasCC[6];
Trigger DummyVictory;

void InitRes(int i)
{
	switch (Player[i].Difficulty())
	{
	case 0:
		Player[i].SetOre(0);
		Player[i].SetFoodStored(0);
		Player[i].SetWorkers(0);
		Player[i].SetScientists(0);
		Player[i].SetKids(0);
		Player[i].MarkResearchComplete(5505);
		Player[i].MarkResearchComplete(10000);
		break;
	case 1:
		Player[i].SetOre(0);
		Player[i].SetFoodStored(0);
		Player[i].SetWorkers(0);
		Player[i].SetScientists(0);
		Player[i].SetKids(0);
		Player[i].MarkResearchComplete(5505);
		break;
	case 2:
		Player[i].SetOre(0);
		Player[i].SetFoodStored(0);
		Player[i].SetWorkers(0);
		Player[i].SetScientists(0);
		Player[i].SetKids(0);
	}

	// Enable Lynxes if Morale Steady is on.
	if (TethysGame::UsesMorale())
	{
		Player[i].MarkResearchComplete(3851);
	}
}

void InitVecs(int x, int y, int i)
{
	Unit Unit1;
	map_id wpn = Player[i].IsEden() ? mapLaser : mapMicrowave;
	int curX = 0, curY = 0;
	for (int vecsSoFar = 0; vecsSoFar < TethysGame::InitialUnits(); vecsSoFar++)
	{
		TethysGame::CreateUnit(Unit1, mapLynx, LOCATION(x + curX, y + curY), i, wpn, 0);
		Unit1.DoSetLights(1);
		curX++;
		if (curX == 4)
		{
			curX = 0;
			curY++;
		}
	}
}

// These bases are all in the same exact layout.  I could've had a generic "SetupBase" that took a location in, but I like being able to see exactly where everything will be.
void SetupP1(int p)
{
	if (!Player[p].IsHuman())
	{
		cc[p].unitID = 0;
		hasCC[p] = false;
		return;
	}

	Unit Unit1;
	Player[p].CenterViewOn(7 + 31, 5 - 1);
	TethysGame::CreateUnit(cc[p], mapCommandCenter, LOCATION(7 + 31, 5 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapVehicleFactory, LOCATION(8 + 31, 8 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapStructureFactory, LOCATION(8 + 31, 12 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapTradeCenter, LOCATION(11 + 31, 5 - 1), p, mapNone, 0);
	hasCC[p] = true;

	InitRes(p);
	InitVecs(12 + 31, 9 - 1, p);
}

void SetupP2(int p)
{
	if (!Player[p].IsHuman())
	{
		cc[p].unitID = 0;
		hasCC[p] = false;
		return;
	}

	Unit Unit1;
	Player[p].CenterViewOn(245 + 31, 5 - 1);
	TethysGame::CreateUnit(cc[p], mapCommandCenter, LOCATION(245 + 31, 5 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapVehicleFactory, LOCATION(246 + 31, 8 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapStructureFactory, LOCATION(246 + 31, 12 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapTradeCenter, LOCATION(249 + 31, 5 - 1), p, mapNone, 0);
	hasCC[p] = true;

	InitRes(p);
	InitVecs(237 + 31, 9 - 1, p);
}

void SetupP3(int p)
{
	if (!Player[p].IsHuman())
	{
		cc[p].unitID = 0;
		hasCC[p] = false;
		return;
	}

	Unit Unit1;
	Player[p].CenterViewOn(26 + 31, 32 - 1);
	TethysGame::CreateUnit(cc[p], mapCommandCenter, LOCATION(26 + 31, 32 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapVehicleFactory, LOCATION(27 + 31, 35 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapStructureFactory, LOCATION(27 + 31, 39 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapTradeCenter, LOCATION(30 + 31, 32 - 1), p, mapNone, 0);
	hasCC[p] = true;

	InitRes(p);
	InitVecs(19 + 31, 34 - 1, p);
}

void SetupP4(int p)
{
	if (!Player[p].IsHuman())
	{
		cc[p].unitID = 0;
		hasCC[p] = false;
		return;
	}

	Unit Unit1;
	Player[p].CenterViewOn(240 + 31, 29 - 1);
	TethysGame::CreateUnit(cc[p], mapCommandCenter, LOCATION(240 + 31, 29 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapVehicleFactory, LOCATION(241 + 31, 32 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapStructureFactory, LOCATION(241 + 31, 36 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapTradeCenter, LOCATION(244 + 31, 29 - 1), p, mapNone, 0);
	hasCC[p] = true;

	InitRes(p);
	InitVecs(248 + 31, 33 - 1, p);
}

void SetupP5(int p)
{
	if (!Player[p].IsHuman())
	{
		cc[p].unitID = 0;
		hasCC[p] = false;
		return;
	}

	Unit Unit1;
	Player[p].CenterViewOn(17 + 31, 50 - 1);
	TethysGame::CreateUnit(cc[p], mapCommandCenter, LOCATION(17 + 31, 50 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapVehicleFactory, LOCATION(18 + 31, 53 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapStructureFactory, LOCATION(18 + 31, 57 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapTradeCenter, LOCATION(21 + 31, 50 - 1), p, mapNone, 0);
	hasCC[p] = true;

	InitRes(p);
	InitVecs(24 + 31, 47 - 1, p);
}

void SetupP6(int p)
{
	if (!Player[p].IsHuman())
	{
		cc[p].unitID = 0;
		hasCC[p] = false;
		return;
	}

	Unit Unit1;
	Player[p].CenterViewOn(245 + 31, 45 - 1);
	TethysGame::CreateUnit(cc[p], mapCommandCenter, LOCATION(245 + 31, 45 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapVehicleFactory, LOCATION(246 + 31, 48 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapStructureFactory, LOCATION(246 + 31, 52 - 1), p, mapNone, 0);
	TethysGame::CreateUnit(Unit1, mapTradeCenter, LOCATION(249 + 31, 45 - 1), p, mapNone, 0);
	hasCC[p] = true;

	InitRes(p);
	InitVecs(237 + 31, 47 - 1, p);
}

void VictoryDefeat()
{
	DummyVictory = CreateVictoryCondition(0, 1, CreateTimeTrigger(1, 1, 1, "NoResponseToTrigger"), "Eliminate all enemy Command Centers");
	CreateTimeTrigger(1, 0, 12, "CheckEndGame");
}

Export void CheckEndGame()
{
	for (int i = 0; i < TethysGame::NoPlayers(); i++)
	{
		if (hasCC[i])
		{
			if (cc[i].unitID == 0 || cc[i].OwnerID() != i || cc[i].GetType() != mapCommandCenter || !cc[i].IsLive())
			{
				hasCC[i] = false;
			}
		}
	}

	// Team 1 victory
	if ((hasCC[0] || hasCC[2] || hasCC[4]) && (!hasCC[1] && !hasCC[3] && !hasCC[5]))
	{
		if (TethysGame::LocalPlayer() % 2 == 0)
		{
			DummyVictory.Enable();
		}
		else
		{
			CreateFailureCondition(1, 1, CreateTimeTrigger(1, 1, 1, "NoResponseToTrigger"), "");
		}
	}

	// Team 2 victory
	else if ((hasCC[1] || hasCC[3] || hasCC[5]) && (!hasCC[0] && !hasCC[2] && !hasCC[4]))
	{
		if (TethysGame::LocalPlayer() % 2 == 1)
		{
			DummyVictory.Enable();
		}
		else
		{
			CreateFailureCondition(1, 1, CreateTimeTrigger(1, 1, 1, "NoResponseToTrigger"), "");
		}
	}

	// Draw
	else if (!hasCC[0] && !hasCC[1] && !hasCC[2] && !hasCC[3] && !hasCC[4] && !hasCC[5])
	{
		CreateFailureCondition(1, 1, CreateTimeTrigger(1, 1, 1, "NoResponseToTrigger"), "");
	}
}