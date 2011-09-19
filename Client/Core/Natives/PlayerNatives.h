//============== IV: Multiplayer - http://code.iv-multiplayer.com ==============
//
// File: PlayerNatives.h
// Project: Client.Core
// Author(s): jenksta
//            Einstein
//            Sebihunter
// License: See LICENSE in root directory
//
//==============================================================================

#pragma once

#include "../Natives.h"

class CPlayerNatives
{
private:
	static SQInteger IsConnected(SQVM * pVM);
	static SQInteger GetLocal(SQVM * pVM);
	static SQInteger GetName(SQVM * pVM);
	static SQInteger GetHealth(SQVM * pVM);
	static SQInteger GetArmour(SQVM * pVM);
	static SQInteger GetCoordinates(SQVM * pVM);
	static SQInteger GetVelocity(SQVM * pVM);
	static SQInteger IsInAnyVehicle(SQVM * pVM);
	static SQInteger IsInVehicle(SQVM * pVM);
	static SQInteger GetVehicleId(SQVM * pVM);
	static SQInteger GetSeatId(SQVM * pVM);
	static SQInteger IsOnFoot(SQVM * pVM);
	static SQInteger GetModel(SQVM * pVM);
	static SQInteger IsSpawned(SQVM * pVM);
	static SQInteger GetHeading(SQVM * pVM);
	static SQInteger GetMoney(SQVM * pVM);
	static SQInteger GetState(SQVM * pVM);
	static SQInteger GetWeapon(SQVM * pVM);
	static SQInteger GetAmmo(SQVM * pVM);
	static SQInteger GetInterior(SQVM * pVM);
	static SQInteger GetPadState(SQVM * pVM);
	static SQInteger GetPreviousPadState(SQVM * pVM);
	static SQInteger GetPing(SQVM * pVM);
	static SQInteger GetColor(SQVM * pVM);

public:
	static void      Register(CScriptingManager * pScriptingManager);
};
