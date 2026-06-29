/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod Counter-Strike:Source Extension
 * Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#ifndef _INCLUDE_CSTRIKE_UTIL_H_
#define _INCLUDE_CSTRIKE_UTIL_H_
 //THIS IS THE INCLUDE ENUM DO NOT CHANGE ONLY UPDATE THE INCLUDE
 //This is used to match to old weaponid's to their correct enum value
 //Anything after heavy assault suit will pass the itemdef as they will be the id set in include
enum SMCSWeapon
{
	SMCSWeapon_NONE = 0,
	SMCSWeapon_P228,
	SMCSWeapon_GLOCK,
	SMCSWeapon_SCOUT,
	SMCSWeapon_HEGRENADE,
	SMCSWeapon_XM1014,
	SMCSWeapon_C4,
	SMCSWeapon_MAC10,
	SMCSWeapon_AUG,
	SMCSWeapon_SMOKEGRENADE,
	SMCSWeapon_ELITE,
	SMCSWeapon_FIVESEVEN,
	SMCSWeapon_UMP45,
	SMCSWeapon_SG550,
	SMCSWeapon_GALIL,
	SMCSWeapon_FAMAS,
	SMCSWeapon_USP,
	SMCSWeapon_AWP,
	SMCSWeapon_MP5NAVY,
	SMCSWeapon_M249,
	SMCSWeapon_M3,
	SMCSWeapon_M4A1,
	SMCSWeapon_TMP,
	SMCSWeapon_G3SG1,
	SMCSWeapon_FLASHBANG,
	SMCSWeapon_DEAGLE,
	SMCSWeapon_SG552,
	SMCSWeapon_AK47,
	SMCSWeapon_KNIFE,
	SMCSWeapon_P90,
	SMCSWeapon_SHIELD,
	SMCSWeapon_KEVLAR,
	SMCSWeapon_ASSAULTSUIT,
	SMCSWeapon_NIGHTVISION, //Anything below is CS:GO ONLY
	SMCSWeapon_GALILAR,
	SMCSWeapon_BIZON,
	SMCSWeapon_MAG7,
	SMCSWeapon_NEGEV,
	SMCSWeapon_SAWEDOFF,
	SMCSWeapon_TEC9,
	SMCSWeapon_TASER,
	SMCSWeapon_HKP2000,
	SMCSWeapon_MP7,
	SMCSWeapon_MP9,
	SMCSWeapon_NOVA,
	SMCSWeapon_P250,
	SMCSWeapon_SCAR17,
	SMCSWeapon_SCAR20,
	SMCSWeapon_SG556,
	SMCSWeapon_SSG08,
	SMCSWeapon_KNIFE_GG,
	SMCSWeapon_MOLOTOV,
	SMCSWeapon_DECOY,
	SMCSWeapon_INCGRENADE,
	SMCSWeapon_DEFUSER,
	SMCSWeapon_HEAVYASSAULTSUIT,
	SMCSWeapon_MAXWEAPONIDS, //This only exists here... the include has more. This is for easy array construction
	//The rest are actual item definition indexes for CS:GO
	SMCSWeapon_CUTTERS = 56,
	SMCSWeapon_HEALTHSHOT = 57,
	SMCSWeapon_KNIFE_T = 59,
	SMCSWeapon_M4A1_SILENCER = 60,
	SMCSWeapon_USP_SILENCER = 61,
	SMCSWeapon_CZ75A = 63,
	SMCSWeapon_REVOLVER = 64,
	SMCSWeapon_TAGGRENADE = 68,
	SMCSWeapon_FISTS = 69,
	SMCSWeapon_BREACHCHARGE = 70,
	SMCSWeapon_TABLET = 72,
	SMCSWeapon_MELEE = 74,
	SMCSWeapon_AXE = 75,
	SMCSWeapon_HAMMER = 76,
	SMCSWeapon_SPANNER = 78,
	SMCSWeapon_KNIFE_GHOST = 80,
	SMCSWeapon_FIREBOMB = 81,
	SMCSWeapon_DIVERSION = 82,
	SMCSWeapon_FRAGGRENADE = 83,
	SMCSWeapon_SNOWBALL = 84,
	SMCSWeapon_BUMPMINE = 85,
	SMCSWeapon_MAX_WEAPONS_NO_KNIFES, // Max without the knife item defs, useful when treating all knives as a regular knife.
	SMCSWeapon_BAYONET = 500,
	SMCSWeapon_KNIFE_CLASSIC = 503,
	SMCSWeapon_KNIFE_FLIP = 505,
	SMCSWeapon_KNIFE_GUT = 506,
	SMCSWeapon_KNIFE_KARAMBIT = 507,
	SMCSWeapon_KNIFE_M9_BAYONET = 508,
	SMCSWeapon_KNIFE_TATICAL = 509,
	SMCSWeapon_KNIFE_FALCHION = 512,
	SMCSWeapon_KNIFE_SURVIVAL_BOWIE = 514,
	SMCSWeapon_KNIFE_BUTTERFLY = 515,
	SMCSWeapon_KNIFE_PUSH = 516,
	SMCSWeapon_KNIFE_CORD = 517,
	SMCSWeapon_KNIFE_CANIS = 518,
	SMCSWeapon_KNIFE_URSUS = 519,
	SMCSWeapon_KNIFE_GYPSY_JACKKNIFE = 520,
	SMCSWeapon_KNIFE_OUTDOOR = 521,
	SMCSWeapon_KNIFE_STILETTO = 522,
	SMCSWeapon_KNIFE_WIDOWMAKER = 523,
	SMCSWeapon_KNIFE_SKELETON = 525,
	SMCSWeapon_KNIFE_KUKRI = 526
};

enum SMCSRoundEndReason
{
	SMCSRoundEnd_Invalid = -1, // only exists here
	SMCSRoundEnd_TargetBombed = 0,           /**< [S, GO, SO]  Target Successfully Bombed! */
	SMCSRoundEnd_VIPEscaped,                 /**< [S]          The VIP has escaped! */
	SMCSRoundEnd_VIPKilled,                  /**< [S]          VIP has been assassinated! */
	SMCSRoundEnd_TerroristsEscaped,          /**< [S, GO]      The terrorists have escaped! */
	SMCSRoundEnd_CTStoppedEscape,            /**< [S, GO]      The CTs have prevented most of the terrorists from escaping! */
	SMCSRoundEnd_TerroristsStopped,          /**< [S, GO]      Escaping terrorists have all been neutralized! */
	SMCSRoundEnd_BombDefused,                /**< [S, GO, SO]  The bomb has been defused! */
	SMCSRoundEnd_CTWin,                      /**< [S, GO, SO]  Counter-Terrorists Win! */
	SMCSRoundEnd_TerroristWin,               /**< [S, GO, SO]  Terrorists Win! */
	SMCSRoundEnd_Draw,                       /**< [S, GO, SO]  Round Draw! */
	SMCSRoundEnd_HostagesRescued,            /**< [S, GO, SO]  All Hostages have been rescued! */
	SMCSRoundEnd_TargetSaved,                /**< [S, GO, SO]  Target has been saved! */
	SMCSRoundEnd_HostagesNotRescued,         /**< [S, GO, SO]  Hostages have not been rescued! */
	SMCSRoundEnd_TerroristsNotEscaped,       /**< [S, GO]      Terrorists have not escaped! */
	SMCSRoundEnd_VIPNotEscaped,              /**< [S]          VIP has not escaped! */
	SMCSRoundEnd_GameStart,                  /**< [S, GO, SO]  Game Commencing! */
	SMCSRoundEnd_TerroristsSurrender,        /**< [GO, SO]     Terrorists Surrender */
	SMCSRoundEnd_CTSurrender,                /**< [GO, SO]     CTs Surrender */
	SMCSRoundEnd_TerroristsPlanted,          /**< [GO]         Terrorists Planted the bomb */
	SMCSRoundEnd_CTsReachedHostage,          /**< [GO]         CTs Reached the hostage */
	SMCSRoundEnd_Count
};

int RoundEndReasonFromGame(int reason); // convert from game's value to cstrike.inc
int RoundEndReasonToGame(int reason); // convert from cstrike.inc's value to game

#if SOURCE_ENGINE == SE_CSGO
//These are the ItemDefintion indexs they are used as a reference to create GetWeaponIdFromDefIdx
/*
enum CSGOItemDefs
{
	CSGOItemDef_NONE = 0,
	CSGOItemDef_DEAGLE,
	CSGOItemDef_ELITE,
	CSGOItemDef_FIVESEVEN,
	CSGOItemDef_GLOCK,
	CSGOItemDef_P228,
	CSGOItemDef_USP,
	CSGOItemDef_AK47,
	CSGOItemDef_AUG,
	CSGOItemDef_AWP,
	CSGOItemDef_FAMAS,
	CSGOItemDef_G3SG1,
	CSGOItemDef_GALIL,
	CSGOItemDef_GALILAR,
	CSGOItemDef_M249,
	CSGOItemDef_M3,
	CSGOItemDef_M4A1,
	CSGOItemDef_MAC10,
	CSGOItemDef_MP5NAVY,
	CSGOItemDef_P90,
	CSGOItemDef_SCOUT,
	CSGOItemDef_SG550,
	CSGOItemDef_SG552,
	CSGOItemDef_TMP,
	CSGOItemDef_UMP45,
	CSGOItemDef_XM1014,
	CSGOItemDef_BIZON,
	CSGOItemDef_MAG7,
	CSGOItemDef_NEGEV,
	CSGOItemDef_SAWEDOFF,
	CSGOItemDef_TEC9,
	CSGOItemDef_TASER,
	CSGOItemDef_HKP2000,
	CSGOItemDef_MP7,
	CSGOItemDef_MP9,
	CSGOItemDef_NOVA,
	CSGOItemDef_P250,
	CSGOItemDef_SCAR17,
	CSGOItemDef_SCAR20,
	CSGOItemDef_SG556,
	CSGOItemDef_SSG08,
	CSGOItemDef_KNIFE_GG,
	CSGOItemDef_KNIFE,
	CSGOItemDef_FLASHBANG,
	CSGOItemDef_HEGRENADE,
	CSGOItemDef_SMOKEGRENADE,
	CSGOItemDef_MOLOTOV,
	CSGOItemDef_DECOY,
	CSGOItemDef_INCGRENADE,
	CSGOItemDef_C4,
	CSGOItemDef_KEVLAR,
	CSGOItemDef_ASSAULTSUIT,
	CSGOItemDef_HEAVYASSAULTSUIT,
	CSGOItemDef_UNUSED,
	CSGOItemDef_NVG,
	CSGOItemDef_DEFUSER,
	CSGOItemDef_MAXDEFS,
};
*/
class CEconItemView;
class CCSWeaponData;
class CEconItemSchema;
class CEconItemDefinition
{
public:
	void **m_pVtable;
	KeyValues *m_pKv;
	uint16_t m_iDefinitionIndex;
	int GetDefaultLoadoutSlot()
	{
		static int iLoadoutSlotOffset = -1;

		if (iLoadoutSlotOffset == -1)
		{
			if (!g_pGameConf->GetOffset("LoadoutSlotOffset", &iLoadoutSlotOffset) || iLoadoutSlotOffset == -1)
			{
				iLoadoutSlotOffset = -1;
				return -1;
			}
		}

		return *(int *)((intptr_t)this + iLoadoutSlotOffset);
	}
};

CEconItemView *GetEconItemView(CBaseEntity *pEntity, int iSlot);
CCSWeaponData *GetCCSWeaponData(CEconItemView *view);
CEconItemSchema *GetItemSchema();
CEconItemDefinition *GetItemDefintionByName(const char *classname);
SMCSWeapon GetWeaponIdFromDefIdx(uint16_t iDefIdx);
#endif
#if SOURCE_ENGINE == SE_CSSO
SMCSWeapon GetWeaponIdFromName(const char* classname);
#endif
#if SOURCE_ENGINE == SE_CSGO || SOURCE_ENGINE == SE_CSSO
struct ItemDefHashValue;
void CreateHashMaps();
void ClearHashMaps();
ItemDefHashValue *GetHashValueFromWeapon(const char *szWeapon);
#endif
#if SOURCE_ENGINE != SE_CSGO
void *GetWeaponInfo(int weaponID);
#endif

const char *GetWeaponNameFromClassname(const char *weapon);
const char *GetTranslatedWeaponAlias(const char *weapon);
int AliasToWeaponID(const char *weapon);
const char *WeaponIDToAlias(int weaponID);
bool IsValidWeaponID(int weaponId);
#endif
