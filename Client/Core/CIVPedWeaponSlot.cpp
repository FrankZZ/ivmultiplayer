//============== IV: Multiplayer - http://code.iv-multiplayer.com ==============
//
// File: CIVPedWeaponSlot.cpp
// Project: Client.Core
// Author(s): jenksta
// License: See LICENSE in root directory
//
//==============================================================================

#include "CIVPedWeaponSlot.h"
#include "CIVPedWeapons.h"
#include "CGame.h"

CIVPedWeaponSlot::CIVPedWeaponSlot(IVPedWeaponSlot * pWeapon, CIVPedWeapons * pPedWeapons)
{
	m_pPedWeaponSlot = pWeapon;
	m_pPedWeapons = pPedWeapons;
}

eWeaponType CIVPedWeaponSlot::GetType()
{
	if(m_pPedWeaponSlot)
		return m_pPedWeaponSlot->m_type;

	return WEAPON_TYPE_UNARMED;
}

void CIVPedWeaponSlot::SetAmmo(DWORD dwAmmo)
{
	if(m_pPedWeaponSlot)
	{
		if(dwAmmo > 25000)
			dwAmmo = 25000;

		XLivePBufferSetDWORD(m_pPedWeaponSlot->m_pAmmo, 0, dwAmmo);
	}
}

DWORD CIVPedWeaponSlot::GetAmmo()
{
	if(m_pPedWeaponSlot)
	{
		DWORD dwAmmo;
		XLivePBufferGetDWORD(m_pPedWeaponSlot->m_pAmmo, 0, &dwAmmo);
		return dwAmmo;
	}

	return 0;
}

void CIVPedWeaponSlot::Remove()
{
	if(m_pPedWeaponSlot)
	{
		if(m_pPedWeaponSlot->bytePad1)
		{
			CIVWeaponInfo * pWeaponInfo = CGame::GetWeaponInfo(m_pPedWeaponSlot->m_type);

			if(pWeaponInfo)
			{
				int iModelIndex = CGame::GetStreaming()->GetModelIndexFromHash(pWeaponInfo->GetWeaponInfo()->m_dwModelHash);

				if(iModelIndex != -1)
				{
					CIVModelInfo * pModelInfo = CGame::GetModelInfo(iModelIndex);

					if(pModelInfo)
						pModelInfo->GetModelInfo()->dwReferenceCount--;
				}
			}
		}

		m_pPedWeaponSlot->bytePad1 = 0;
		m_pPedWeaponSlot->m_type = WEAPON_TYPE_UNARMED;
		SetAmmo(0);
	}
}

void CIVPedWeaponSlot::SetCurrent()
{
	if(m_pPedWeaponSlot)
		m_pPedWeapons->SetCurrentWeapon(m_pPedWeaponSlot->m_type);
}
