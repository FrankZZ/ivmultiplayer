//============== IV: Multiplayer - http://code.iv-multiplayer.com ==============
//
// File: CPadState.h
// Project: Shared
// Author(s): jenksta
// License: See LICENSE in root directory
//
//==============================================================================

#pragma once

class CBitStream;

class CPadState
{
public:
	// On Foot Move
	unsigned char ucOnFootMove[4]; // left, right, up, down

	// In Vehicle Move
	unsigned char ucInVehicleMove[4]; // left, right, up, down

	// Triggers (TODO: Implement trigger keys as this analog value instead of binary value)
	//unsigned char ucLeftTrigger;
	//unsigned char ucRightTrigger;

	// Binary Key Count
	enum { KEY_COUNT = 18 };

	// Binary Keys
	struct 
	{
		// On Foot/In Vehicle
		bool bEnterExitVehicle : 1;

		// On Foot
		bool bSprint : 1;
		bool bJump : 1;
		bool bAttack : 1;
		bool bAttack2 : 1;
		bool bAim : 1;
		bool bFreeAim : 1;
		bool bMeleeAttack1 : 1;
		bool bMeleeAttack2 : 1;
		bool bMeleeKick : 1;
		bool bMeleeBlock : 1;

		// In Vehicle
		bool bAccelerate : 1;
		bool bBrake : 1;
		bool bHandbrake : 1;
		bool bHandbrake2 : 1;
		bool bHorn : 1;
		bool bDriveBy : 1;
		bool bHeliPrimaryFire : 1;
	} keys;

	CPadState();

	bool operator== (const CPadState& o) const;
	bool operator!= (const CPadState& o) const;

	bool IsInCombat() const { return (keys.bMeleeAttack1 || keys.bMeleeAttack2 || keys.bMeleeKick || keys.bMeleeBlock); }
	bool IsFiring() const { return (keys.bAttack); }
	bool IsAiming() const { return (keys.bAttack2 || keys.bAim || keys.bFreeAim); }
	bool IsDoingDriveBy() const { return (keys.bDriveBy); }
	bool IsFiringHelicoptor() const { return (keys.bHeliPrimaryFire); }
	bool IsSprinting() const { return (keys.bSprint); }
	bool IsUsingHorn() const { return (keys.bHorn); }
	bool IsJumping() const { return (keys.bJump); }
	bool IsUsingHandbrake() { return (keys.bHandbrake || keys.bHandbrake2); }
	bool IsUsingEnterExitVehicle() { return (keys.bEnterExitVehicle); }
	void Serialize(CBitStream * pBitStream) const;
	bool Deserialize(CBitStream * pBitStream);
};
