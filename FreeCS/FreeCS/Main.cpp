#include "Head.h"
const string ReleaseDate = "[2023-10-10 18:00]";
const string ApplicableVersion = "1573";
EasyGUI::EasyGUI Free_GUI_VAR;
EasyGUI::EasyGUI_IO Free_GUI_IO;
BOOL MenuShowState;
//----------------------------------------------------
namespace Config_Var
{
	const string DefaultConfig = "0\n5\n0\n1\n0\n1\n1\n100\n1\n100\n3\n100\n3\n100\n3\n1\n5\n1\n150\n1\n0.015\n0.004\n1\n250\n1\n162\n1\n0\n1\n1\n160\n800\n350\n1\n1\n25\n220\n1\n1\n45\n0\n255\n255\n255\n250\n0\n1\n1\n1\n";
	BOOL UI_Legit_Aimbot = Variable::string_int_(System::Get_File("FreeCS.cfg", 1));
	int UI_Legit_Aimbot_Key = Variable::string_int_(System::Get_File("FreeCS.cfg", 2));
	BOOL UI_Legit_Aimbot_BodyAim = Variable::string_int_(System::Get_File("FreeCS.cfg", 3));
	BOOL UI_Legit_Aimbot_JudgingWall = Variable::string_int_(System::Get_File("FreeCS.cfg", 4));
	BOOL UI_Legit_Aimbot_TriggerOnAiming = Variable::string_int_(System::Get_File("FreeCS.cfg", 5));
	BOOL UI_Legit_Aimbot_RemoveRecoil = Variable::string_int_(System::Get_File("FreeCS.cfg", 6));
	BOOL UI_Legit_Aimbot_AutoShoot = Variable::string_int_(System::Get_File("FreeCS.cfg", 7));
	int UI_Legit_Aimbot_AutoShoot_Interval = Variable::string_int_(System::Get_File("FreeCS.cfg", 8));
	BOOL UI_Legit_Aimbot_AdaptiveAimbot = Variable::string_int_(System::Get_File("FreeCS.cfg", 9));
	int UI_Legit_Aimbot_A_Range_PISTOL = Variable::string_int_(System::Get_File("FreeCS.cfg", 10));
	float UI_Legit_Aimbot_A_Smooth_PISTOL = Variable::string_float_(System::Get_File("FreeCS.cfg", 11));
	int UI_Legit_Aimbot_A_Range_RIFLE = Variable::string_int_(System::Get_File("FreeCS.cfg", 12));
	float UI_Legit_Aimbot_A_Smooth_RIFLE = Variable::string_float_(System::Get_File("FreeCS.cfg", 13));
	int UI_Legit_Aimbot_A_Range_SNIPER = Variable::string_int_(System::Get_File("FreeCS.cfg", 14));
	float UI_Legit_Aimbot_A_Smooth_SNIPER = Variable::string_float_(System::Get_File("FreeCS.cfg", 15));
	BOOL UI_Legit_Triggerbot = Variable::string_int_(System::Get_File("FreeCS.cfg", 16));
	int UI_Legit_Triggerbot_Key = Variable::string_int_(System::Get_File("FreeCS.cfg", 17));
	int UI_Legit_Triggerbot_ShootInterval = Variable::string_int_(System::Get_File("FreeCS.cfg", 18));
	int UI_Legit_Triggerbot_ShootDuration = Variable::string_int_(System::Get_File("FreeCS.cfg", 19));
	BOOL UI_Legit_PreciseAim = Variable::string_int_(System::Get_File("FreeCS.cfg", 20));
	float UI_Legit_PreciseAim_DefaultSensitivity = Variable::string_float_(System::Get_File("FreeCS.cfg", 21));
	float UI_Legit_PreciseAim_EnableSensitivity = Variable::string_float_(System::Get_File("FreeCS.cfg", 22));
	BOOL UI_Legit_Backtracking = Variable::string_int_(System::Get_File("FreeCS.cfg", 23));//None
	int UI_Legit_Backtracking_Time = Variable::string_int_(System::Get_File("FreeCS.cfg", 24));//None
	BOOL UI_Misc_BunnyHop = Variable::string_int_(System::Get_File("FreeCS.cfg", 25));
	int UI_Misc_BunnyHop_100Tri = Variable::string_int_(System::Get_File("FreeCS.cfg", 26));
	BOOL UI_Misc_ESP = Variable::string_int_(System::Get_File("FreeCS.cfg", 27));
	int UI_Misc_ESP_Key = Variable::string_int_(System::Get_File("FreeCS.cfg", 28));
	BOOL UI_Misc_HitSound = Variable::string_int_(System::Get_File("FreeCS.cfg", 29));
	BOOL UI_Misc_Sonar = Variable::string_int_(System::Get_File("FreeCS.cfg", 30));
	int UI_Misc_Sonar_Key = Variable::string_int_(System::Get_File("FreeCS.cfg", 31));
	int UI_Misc_Sonar_Range_Far = Variable::string_int_(System::Get_File("FreeCS.cfg", 32));
	int UI_Misc_Sonar_Range_Near = Variable::string_int_(System::Get_File("FreeCS.cfg", 33));
	BOOL UI_Misc_Radar = Variable::string_int_(System::Get_File("FreeCS.cfg", 34));
	BOOL UI_Misc_Radar_FollowAngle = Variable::string_int_(System::Get_File("FreeCS.cfg", 35));
	float UI_Misc_Radar_Range = Variable::string_float_(System::Get_File("FreeCS.cfg", 36));
	int UI_Misc_Radar_Size = Variable::string_int_(System::Get_File("FreeCS.cfg", 37));
	BOOL UI_Legit_RemoveRecoil = Variable::string_int_(System::Get_File("FreeCS.cfg", 38));
	BOOL UI_Legit_RemoveRecoil_LateralRepair = Variable::string_int_(System::Get_File("FreeCS.cfg", 39));
	int UI_Settings_MenuKey = Variable::string_int_(System::Get_File("FreeCS.cfg", 40));
	BOOL UI_Settings_CustomMenuColor = Variable::string_int_(System::Get_File("FreeCS.cfg", 41));
	vector<int> UI_Settings_MenuColor = { Variable::string_int_(System::Get_File("FreeCS.cfg", 42)) ,Variable::string_int_(System::Get_File("FreeCS.cfg", 43)) ,Variable::string_int_(System::Get_File("FreeCS.cfg", 44)) };
	int UI_Settings_MenuAlpha = Variable::string_int_(System::Get_File("FreeCS.cfg", 45));
	BOOL UI_Settings_ShowDebugWindow = Variable::string_int_(System::Get_File("FreeCS.cfg", 46));
	BOOL UI_Settings_SaveConfig = false;
	BOOL UI_Settings_RestartCS = false;
	BOOL UI_Settings_QuitCS = false;
	BOOL UI_Settings_SendCommand = false;
	BOOL UI_Settings_SendTestCommand = false;
	BOOL UI_Settings_RestartFreeCS = false;
	BOOL UI_Settings_CloseFreeCS = false;
	BOOL UI_Settings_Res_3840;
	BOOL UI_Settings_Res_2560;
	BOOL UI_Settings_Res_1920;
	BOOL UI_Settings_Res_1440;
	BOOL UI_Settings_Res_1280;
	BOOL UI_Settings_Res_960;
	BOOL UI_Settings_WaterMark = Variable::string_int_(System::Get_File("FreeCS.cfg", 47));
	int UI_Misc_ESP_RenderSleep = Variable::string_int_(System::Get_File("FreeCS.cfg", 48));
	BOOL UI_Misc_AutoClearDecals = Variable::string_int_(System::Get_File("FreeCS.cfg", 49));
}
namespace Memory_CS
{
	BOOL CS_Window_State = true;
	System::Memory CS_Mem_ = { "" };
	HWND CS_Window_HWND;
	DWORD64 Module_client;
	DWORD64 Module_engine;
	uintptr_t LocalPlayer;
	vector<short> LocalPlayer_Active_Weapon = { 0,0 };
	namespace Offsets
	{
		constexpr ::std::int64_t timestamp = 1694683129;
		constexpr ::std::ptrdiff_t cs_gamerules_data = 0x0;
		constexpr ::std::ptrdiff_t m_ArmorValue = 0x117CC;
		constexpr ::std::ptrdiff_t m_Collision = 0x320;
		constexpr ::std::ptrdiff_t m_CollisionGroup = 0x474;
		constexpr ::std::ptrdiff_t m_Local = 0x2FCC;
		constexpr ::std::ptrdiff_t m_MoveType = 0x25C;
		constexpr ::std::ptrdiff_t m_OriginalOwnerXuidHigh = 0x31D4;
		constexpr ::std::ptrdiff_t m_OriginalOwnerXuidLow = 0x31D0;
		constexpr ::std::ptrdiff_t m_SurvivalGameRuleDecisionTypes = 0x1328;
		constexpr ::std::ptrdiff_t m_SurvivalRules = 0xD00;
		constexpr ::std::ptrdiff_t m_aimPunchAngle = 0x303C;
		constexpr ::std::ptrdiff_t m_aimPunchAngleVel = 0x3048;
		constexpr ::std::ptrdiff_t m_angEyeAnglesX = 0x117D0;
		constexpr ::std::ptrdiff_t m_angEyeAnglesY = 0x117D4;
		constexpr ::std::ptrdiff_t m_bBombDefused = 0x29C0;
		constexpr ::std::ptrdiff_t m_bBombPlanted = 0x9A5;
		constexpr ::std::ptrdiff_t m_bBombTicking = 0x2990;
		constexpr ::std::ptrdiff_t m_bFreezePeriod = 0x20;
		constexpr ::std::ptrdiff_t m_bGunGameImmunity = 0x9990;
		constexpr ::std::ptrdiff_t m_bHasDefuser = 0x117DC;
		constexpr ::std::ptrdiff_t m_bHasHelmet = 0x117C0;
		constexpr ::std::ptrdiff_t m_bInReload = 0x32B5;
		constexpr ::std::ptrdiff_t m_bIsDefusing = 0x997C;
		constexpr ::std::ptrdiff_t m_bIsQueuedMatchmaking = 0x74;
		constexpr ::std::ptrdiff_t m_bIsScoped = 0x9974;
		constexpr ::std::ptrdiff_t m_bIsValveDS = 0x7C;
		constexpr ::std::ptrdiff_t m_bSpotted = 0x93D;
		constexpr ::std::ptrdiff_t m_bSpottedByMask = 0x980;
		constexpr ::std::ptrdiff_t m_bStartedArming = 0x3400;
		constexpr ::std::ptrdiff_t m_bUseCustomAutoExposureMax = 0x9D9;
		constexpr ::std::ptrdiff_t m_bUseCustomAutoExposureMin = 0x9D8;
		constexpr ::std::ptrdiff_t m_bUseCustomBloomScale = 0x9DA;
		constexpr ::std::ptrdiff_t m_clrRender = 0x70;
		constexpr ::std::ptrdiff_t m_dwBoneMatrix = 0x26A8;
		constexpr ::std::ptrdiff_t m_fAccuracyPenalty = 0x3340;
		constexpr ::std::ptrdiff_t m_fFlags = 0x104;
		constexpr ::std::ptrdiff_t m_flC4Blow = 0x29A0;
		constexpr ::std::ptrdiff_t m_flCustomAutoExposureMax = 0x9E0;
		constexpr ::std::ptrdiff_t m_flCustomAutoExposureMin = 0x9DC;
		constexpr ::std::ptrdiff_t m_flCustomBloomScale = 0x9E4;
		constexpr ::std::ptrdiff_t m_flDefuseCountDown = 0x29BC;
		constexpr ::std::ptrdiff_t m_flDefuseLength = 0x29B8;
		constexpr ::std::ptrdiff_t m_flFallbackWear = 0x31E0;
		constexpr ::std::ptrdiff_t m_flFlashDuration = 0x10470;
		constexpr ::std::ptrdiff_t m_flFlashMaxAlpha = 0x1046C;
		constexpr ::std::ptrdiff_t m_flLastBoneSetupTime = 0x2928;
		constexpr ::std::ptrdiff_t m_flLowerBodyYawTarget = 0x9ADC;
		constexpr ::std::ptrdiff_t m_flNextAttack = 0x2D80;
		constexpr ::std::ptrdiff_t m_flNextPrimaryAttack = 0x3248;
		constexpr ::std::ptrdiff_t m_flSimulationTime = 0x268;
		constexpr ::std::ptrdiff_t m_flTimerLength = 0x29A4;
		constexpr ::std::ptrdiff_t m_hActiveWeapon = 0x2F08;
		constexpr ::std::ptrdiff_t m_hBombDefuser = 0x29C4;
		constexpr ::std::ptrdiff_t m_hMyWeapons = 0x2E08;
		constexpr ::std::ptrdiff_t m_hObserverTarget = 0x339C;
		constexpr ::std::ptrdiff_t m_hOwner = 0x29DC;
		constexpr ::std::ptrdiff_t m_hOwnerEntity = 0x14C;
		constexpr ::std::ptrdiff_t m_hViewModel = 0x3308;
		constexpr ::std::ptrdiff_t m_iAccountID = 0x2FD8;
		constexpr ::std::ptrdiff_t m_iClip1 = 0x3274;
		constexpr ::std::ptrdiff_t m_iCompetitiveRanking = 0x1A84;
		constexpr ::std::ptrdiff_t m_iCompetitiveWins = 0x1B88;
		constexpr ::std::ptrdiff_t m_iCrosshairId = 0x11838;
		constexpr ::std::ptrdiff_t m_iDefaultFOV = 0x333C;
		constexpr ::std::ptrdiff_t m_iEntityQuality = 0x2FBC;
		constexpr ::std::ptrdiff_t m_iFOV = 0x31F4;
		constexpr ::std::ptrdiff_t m_iFOVStart = 0x31F8;
		constexpr ::std::ptrdiff_t m_iGlowIndex = 0x10488;
		constexpr ::std::ptrdiff_t m_iHealth = 0x100;
		constexpr ::std::ptrdiff_t m_iItemDefinitionIndex = 0x2FBA;
		constexpr ::std::ptrdiff_t m_iItemIDHigh = 0x2FD0;
		constexpr ::std::ptrdiff_t m_iMostRecentModelBoneCounter = 0x2690;
		constexpr ::std::ptrdiff_t m_iObserverMode = 0x3388;
		constexpr ::std::ptrdiff_t m_iShotsFired = 0x103E0;
		constexpr ::std::ptrdiff_t m_iState = 0x3268;
		constexpr ::std::ptrdiff_t m_iTeamNum = 0xF4;
		constexpr ::std::ptrdiff_t m_lifeState = 0x25F;
		constexpr ::std::ptrdiff_t m_nBombSite = 0x2994;
		constexpr ::std::ptrdiff_t m_nFallbackPaintKit = 0x31D8;
		constexpr ::std::ptrdiff_t m_nFallbackSeed = 0x31DC;
		constexpr ::std::ptrdiff_t m_nFallbackStatTrak = 0x31E4;
		constexpr ::std::ptrdiff_t m_nForceBone = 0x268C;
		constexpr ::std::ptrdiff_t m_nModelIndex = 0x258;
		constexpr ::std::ptrdiff_t m_nTickBase = 0x3440;
		constexpr ::std::ptrdiff_t m_nViewModelIndex = 0x29D0;
		constexpr ::std::ptrdiff_t m_rgflCoordinateFrame = 0x444;
		constexpr ::std::ptrdiff_t m_szCustomName = 0x304C;
		constexpr ::std::ptrdiff_t m_szLastPlaceName = 0x35C4;
		constexpr ::std::ptrdiff_t m_thirdPersonViewAngles = 0x31E8;
		constexpr ::std::ptrdiff_t m_vecOrigin = 0x138;
		constexpr ::std::ptrdiff_t m_vecVelocity = 0x114;
		constexpr ::std::ptrdiff_t m_vecViewOffset = 0x108;
		constexpr ::std::ptrdiff_t m_viewPunchAngle = 0x3030;
		constexpr ::std::ptrdiff_t m_zoomLevel = 0x33E0;
		constexpr ::std::ptrdiff_t anim_overlays = 0x2990;
		constexpr ::std::ptrdiff_t clientstate_choked_commands = 0x4D30;
		constexpr ::std::ptrdiff_t clientstate_delta_ticks = 0x174;
		constexpr ::std::ptrdiff_t clientstate_last_outgoing_command = 0x4D2C;
		constexpr ::std::ptrdiff_t clientstate_net_channel = 0x9C;
		constexpr ::std::ptrdiff_t convar_name_hash_table = 0x301A0;
		constexpr ::std::ptrdiff_t dwClientState = 0x59F19C;
		constexpr ::std::ptrdiff_t dwClientState_GetLocalPlayer = 0x180;
		constexpr ::std::ptrdiff_t dwClientState_IsHLTV = 0x4D48;
		constexpr ::std::ptrdiff_t dwClientState_Map = 0x28C;
		constexpr ::std::ptrdiff_t dwClientState_MapDirectory = 0x188;
		constexpr ::std::ptrdiff_t dwClientState_MaxPlayer = 0x388;
		constexpr ::std::ptrdiff_t dwClientState_PlayerInfo = 0x52C0;
		constexpr ::std::ptrdiff_t dwClientState_State = 0x108;
		constexpr ::std::ptrdiff_t dwClientState_ViewAngles = 0x4D90;
		constexpr ::std::ptrdiff_t dwEntityList = 0x4E0102C;
		constexpr ::std::ptrdiff_t dwForceAttack = 0x322EE98;
		constexpr ::std::ptrdiff_t dwForceAttack2 = 0x322EEA4;
		constexpr ::std::ptrdiff_t dwForceBackward = 0x322EEE0;
		constexpr ::std::ptrdiff_t dwForceForward = 0x322EED4;
		constexpr ::std::ptrdiff_t dwForceJump = 0x52BCD88;
		constexpr ::std::ptrdiff_t dwForceLeft = 0x322EE50;
		constexpr ::std::ptrdiff_t dwForceRight = 0x322EE5C;
		constexpr ::std::ptrdiff_t dwGameDir = 0x63AE00;
		constexpr ::std::ptrdiff_t dwGameRulesProxy = 0x5330594;
		constexpr ::std::ptrdiff_t dwGetAllClasses = 0xE0CFA4;
		constexpr ::std::ptrdiff_t dwGlobalVars = 0x59EE60;
		constexpr ::std::ptrdiff_t dwGlowObjectManager = 0x535BAD0;
		constexpr ::std::ptrdiff_t dwInput = 0x525E600;
		constexpr ::std::ptrdiff_t dwInterfaceLinkList = 0x99CF84;
		constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDEB99C;
		constexpr ::std::ptrdiff_t dwMouseEnable = 0x523A260;
		constexpr ::std::ptrdiff_t dwMouseEnablePtr = 0x523A230;
		constexpr ::std::ptrdiff_t dwPlayerResource = 0x322D1D0;
		constexpr ::std::ptrdiff_t dwRadarBase = 0x5237B04;
		constexpr ::std::ptrdiff_t dwSensitivity = 0xDEFBB8;
		constexpr ::std::ptrdiff_t dwSensitivityPtr = 0xDEFBB8;
		constexpr ::std::ptrdiff_t dwSetClanTag = 0x8DAB0;
		constexpr ::std::ptrdiff_t dwViewMatrix = 0x4DF1E74;
		constexpr ::std::ptrdiff_t dwWeaponTable = 0x525F6DC;
		constexpr ::std::ptrdiff_t dwWeaponTableIndex = 0x326C;
		constexpr ::std::ptrdiff_t dwYawPtr = 0xDEF948;
		constexpr ::std::ptrdiff_t dwZoomSensitivityRatioPtr = 0xDF53B8;
		constexpr ::std::ptrdiff_t dwbSendPackets = 0xDD2D2;
		constexpr ::std::ptrdiff_t dwppDirect3DDevice9 = 0xA62C0;
		constexpr ::std::ptrdiff_t find_hud_element = 0x2B8226C0;
		constexpr ::std::ptrdiff_t force_update_spectator_glow = 0x3DB90A;
		constexpr ::std::ptrdiff_t interface_engine_cvar = 0x3FA9C;
		constexpr ::std::ptrdiff_t is_c4_owner = 0x3E9120;
		constexpr ::std::ptrdiff_t m_bDormant = 0xED;
		constexpr ::std::ptrdiff_t m_bIsLocalPlayer = 0x3628;
		constexpr ::std::ptrdiff_t m_flSpawnTime = 0x103C0;
		constexpr ::std::ptrdiff_t m_pStudioHdr = 0x2950;
		constexpr ::std::ptrdiff_t m_pitchClassPtr = 0x523A158;
		constexpr ::std::ptrdiff_t m_yawClassPtr = 0xDEF948;
		constexpr ::std::ptrdiff_t model_ambient_min = 0x5A1194;
		constexpr ::std::ptrdiff_t set_abs_angles = 0x1E8FC0;
		constexpr ::std::ptrdiff_t set_abs_origin = 0x1E8E00;
	}
	using namespace Offsets;
	void Source_ExecuteCommand(string Str) noexcept
	{
		COPYDATASTRUCT m_cData; m_cData.cbData = strlen(Str.c_str()) + 1; m_cData.dwData = 0; m_cData.lpData = (void*)Str.c_str();
		SendMessage(CS_Window_HWND, WM_COPYDATA, 0, (LPARAM)&m_cData);
	}
	vector<short> Active_Weapon() noexcept//[0]ActiveWeaponID / [1]ActiveWeaponType
	{
		short Active_Weapon_ID_ = CS_Mem_.Read<short>(CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + ((CS_Mem_.Read<uintptr_t>(LocalPlayer + m_hActiveWeapon) & 0xFFF) - 1) * 0x10) + m_iItemDefinitionIndex);
		if (Active_Weapon_ID_ == 4 || Active_Weapon_ID_ == 2 || Active_Weapon_ID_ == 36 || Active_Weapon_ID_ == 30 || Active_Weapon_ID_ == 1 || Active_Weapon_ID_ == 63
			|| Active_Weapon_ID_ == 64 || Active_Weapon_ID_ == 32 || Active_Weapon_ID_ == 61 || Active_Weapon_ID_ == 3)
		{
			return { Active_Weapon_ID_ ,1 };//PISTOL
		}
		else if (Active_Weapon_ID_ == 10 || Active_Weapon_ID_ == 16 || Active_Weapon_ID_ == 8 || Active_Weapon_ID_ == 60
			|| Active_Weapon_ID_ == 13 || Active_Weapon_ID_ == 7 || Active_Weapon_ID_ == 39 || Active_Weapon_ID_ == 28 || Active_Weapon_ID_ == 14
			|| Active_Weapon_ID_ == 17 || Active_Weapon_ID_ == 33 || Active_Weapon_ID_ == 24 || Active_Weapon_ID_ == 19 || Active_Weapon_ID_ == 26 || Active_Weapon_ID_ == 23
			|| Active_Weapon_ID_ == 34)
		{
			return { Active_Weapon_ID_ ,2 };//RIFLE
		}
		else if (Active_Weapon_ID_ == 40 || Active_Weapon_ID_ == 9 || Active_Weapon_ID_ == 38 || Active_Weapon_ID_ == 11)
		{
			return { Active_Weapon_ID_ ,3 };//SNIPER
		}
		else return { Active_Weapon_ID_ ,0 };
	}
	int* Ang_Pos(int X, int Y, int 距离, float 角度, float 偏角) noexcept
	{
		float radian = ((角度 + 偏角) * 3.1415926535) / 180;
		int ReturnValue[2] = { X + 距离 * sin(radian),Y + 距离 * cos(radian) };
		return ReturnValue;
	}
}
using namespace Config_Var;
using namespace Memory_CS;
//----------------------------------------------------
void Thread_Menu() noexcept
{
	System::Log("Load Thread: Thread_Menu()");
	Free_GUI_VAR.Window_Create(1010, 580, System::Rand_String(30), true);
	while (true)
	{
		static int UI_Panel = 0;//Panel
		static vector<int> WindowSize = { 0 ,0 };
		if (!MenuShowState)WindowSize = { 0 ,0 };
		Free_GUI_VAR.Window_SetSize({ (int)Variable::Animation<class CS_Menu_Animation_1>(WindowSize[0],4),(int)Variable::Animation<class CS_Menu_Animation_2>(WindowSize[1],4) });//Animation
		if (!Free_GUI_VAR.Window_Move() && MenuShowState)
		{
			if (!UI_Settings_CustomMenuColor)Free_GUI_VAR.GUI_BackGround(1368);
			else Free_GUI_VAR.GUI_BackGround(1369);
			Free_GUI_VAR.GUI_Block_Panel(20, 20, 100, Free_GUI_VAR.Window_GetSize()[1] - 40, "", { "Legit","Misc","Settings" }, UI_Panel);
			if (UI_Panel == 0)//Legit
			{
				const auto Block_Legit_Aimbot_ = Free_GUI_VAR.GUI_Block(150, 30, 280, "Aimbot");
				Free_GUI_VAR.GUI_Checkbox(Block_Legit_Aimbot_, 1, "Enabled", UI_Legit_Aimbot);
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_1>(Block_Legit_Aimbot_, 1, UI_Legit_Aimbot_Key);
				Free_GUI_VAR.GUI_Checkbox({ Block_Legit_Aimbot_[0] + 20,Block_Legit_Aimbot_[1] }, 2, "Body aim(else head)", UI_Legit_Aimbot_BodyAim);
				Free_GUI_VAR.GUI_Checkbox({ Block_Legit_Aimbot_[0] + 20,Block_Legit_Aimbot_[1] }, 3, "Judging wall", UI_Legit_Aimbot_JudgingWall);
				Free_GUI_VAR.GUI_Checkbox({ Block_Legit_Aimbot_[0] + 20,Block_Legit_Aimbot_[1] }, 4, "Trigger on aiming", UI_Legit_Aimbot_TriggerOnAiming);
				Free_GUI_VAR.GUI_Checkbox({ Block_Legit_Aimbot_[0] + 20,Block_Legit_Aimbot_[1] }, 5, "Remove recoil", UI_Legit_Aimbot_RemoveRecoil);
				Free_GUI_VAR.GUI_Checkbox({ Block_Legit_Aimbot_[0] + 20,Block_Legit_Aimbot_[1] }, 6, "Auto shoot", UI_Legit_Aimbot_AutoShoot, { 255,150,150 });
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_2>(Block_Legit_Aimbot_, 7, "Auto shoot interval ~ms", 0, 500, UI_Legit_Aimbot_AutoShoot_Interval, { 255,150,150 });
				Free_GUI_VAR.GUI_Checkbox(Block_Legit_Aimbot_, 8, "Adaptive aimbot", UI_Legit_Aimbot_AdaptiveAimbot, { 200,200,150 });
				const auto Block_Legit_Aimbot_Armory_ = Free_GUI_VAR.GUI_Block(150, 330, 220, "Armory");
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_3>({ Block_Legit_Aimbot_Armory_[0] - 10,Block_Legit_Aimbot_Armory_[1] }, 1, "PISTOL range", 0, 100, UI_Legit_Aimbot_A_Range_PISTOL);
				Free_GUI_VAR.GUI_Slider<float, class Free_Menu_4>({ Block_Legit_Aimbot_Armory_[0] - 10,Block_Legit_Aimbot_Armory_[1] }, 2, "PISTOL smooth", 3, 30, UI_Legit_Aimbot_A_Smooth_PISTOL);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_5>({ Block_Legit_Aimbot_Armory_[0] - 10,Block_Legit_Aimbot_Armory_[1] }, 3, "RIFLE range", 0, 100, UI_Legit_Aimbot_A_Range_RIFLE);
				Free_GUI_VAR.GUI_Slider<float, class Free_Menu_6>({ Block_Legit_Aimbot_Armory_[0] - 10,Block_Legit_Aimbot_Armory_[1] }, 4, "RIFLE smooth", 3, 30, UI_Legit_Aimbot_A_Smooth_RIFLE);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_7>({ Block_Legit_Aimbot_Armory_[0] - 10,Block_Legit_Aimbot_Armory_[1] }, 5, "SNIPER range", 0, 100, UI_Legit_Aimbot_A_Range_SNIPER);
				Free_GUI_VAR.GUI_Slider<float, class Free_Menu_8>({ Block_Legit_Aimbot_Armory_[0] - 10,Block_Legit_Aimbot_Armory_[1] }, 6, "SNIPER smooth", 3, 30, UI_Legit_Aimbot_A_Smooth_SNIPER);
				const auto Block_Legit_Triggerbot_ = Free_GUI_VAR.GUI_Block(580, 30, 130, "Triggerbot");
				Free_GUI_VAR.GUI_Checkbox(Block_Legit_Triggerbot_, 1, "Enabled", UI_Legit_Triggerbot);
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_9>(Block_Legit_Triggerbot_, 1, UI_Legit_Triggerbot_Key);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_10>(Block_Legit_Triggerbot_, 2, "Shoot interval ~ms", 1, 500, UI_Legit_Triggerbot_ShootInterval);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_11>(Block_Legit_Triggerbot_, 3, "Shoot duration ~ms", 1, 1000, UI_Legit_Triggerbot_ShootDuration);
				const auto Block_Legit_PreciseAim_ = Free_GUI_VAR.GUI_Block(580, 180, 130, "Precise aim");
				Free_GUI_VAR.GUI_Checkbox(Block_Legit_PreciseAim_, 1, "Enabled", UI_Legit_PreciseAim);
				Free_GUI_VAR.GUI_Slider<float, class Free_Menu_12>(Block_Legit_PreciseAim_, 2, "Default sensitivity", 0, 0.022, UI_Legit_PreciseAim_DefaultSensitivity);
				Free_GUI_VAR.GUI_Slider<float, class Free_Menu_13>(Block_Legit_PreciseAim_, 3, "Enable sensitivity", 0, 0.015, UI_Legit_PreciseAim_EnableSensitivity);
				const auto Block_Legit_RemoveRecoil_ = Free_GUI_VAR.GUI_Block(580, 330, 100, "Remove recoil");
				Free_GUI_VAR.GUI_Checkbox(Block_Legit_RemoveRecoil_, 1, "Enabled", UI_Legit_RemoveRecoil);
				Free_GUI_VAR.GUI_Checkbox({ Block_Legit_RemoveRecoil_[0] + 20,Block_Legit_RemoveRecoil_[1] }, 2, "Lateral repair", UI_Legit_RemoveRecoil_LateralRepair);
				const auto Block_Legit_Backtracking_ = Free_GUI_VAR.GUI_Block(580, 450, 100, "Backtracking");
				Free_GUI_VAR.GUI_Checkbox(Block_Legit_Backtracking_, 1, "Enabled", UI_Legit_Backtracking, { 200,200,150 });
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_14>(Block_Legit_Backtracking_, 2, "Maximum time", 0, 500, UI_Legit_Backtracking_Time);
				Free_GUI_VAR.GUI_Tips(Block_Legit_Aimbot_, 6, "Prefer Ragebot.", { 255,150,150 });
				Free_GUI_VAR.GUI_Tips(Block_Legit_Aimbot_, 8, "More biological than normal aimbot.");
				Free_GUI_VAR.GUI_Tips(Block_Legit_Triggerbot_, 1, "Shoot when aiming at the enemy.");
				Free_GUI_VAR.GUI_Tips(Block_Legit_PreciseAim_, 1, "Reduce the sensitivity of the reticle when aiming at the enemy.");
				Free_GUI_VAR.GUI_Tips(Block_Legit_RemoveRecoil_, 2, "Operations that only return landscape");
				WindowSize = { 1010,580 };
			}
			else if (UI_Panel == 1)//Misc
			{
				const auto Block_Misc_Misc_ = Free_GUI_VAR.GUI_Block(150, 30, 210, "Misc");
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Misc_, 1, "Bunny hop", UI_Misc_BunnyHop);
				Free_GUI_VAR.GUI_Text(Block_Misc_Misc_, 2, "99% trigger", { 200,200,150 });
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_15>(Block_Misc_Misc_, 2, UI_Misc_BunnyHop_100Tri);
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Misc_, 3, "ESP", UI_Misc_ESP);
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_16>(Block_Misc_Misc_, 3, UI_Misc_ESP_Key);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_17>(Block_Misc_Misc_, 4, "Draw delay ~ms", 1, 30, UI_Misc_ESP_RenderSleep);
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Misc_, 5, "Hit sound", UI_Misc_HitSound);
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Misc_, 6, "Auto clear decals", UI_Misc_AutoClearDecals);
				const auto Block_Misc_Sonar_ = Free_GUI_VAR.GUI_Block(150, 260, 130, "Sonar");
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Sonar_, 1, "Enabled", UI_Misc_Sonar);
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_18>(Block_Misc_Sonar_, 1, UI_Misc_Sonar_Key);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_19>(Block_Misc_Sonar_, 2, "Range far", 500, 1000, UI_Misc_Sonar_Range_Far);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_20>(Block_Misc_Sonar_, 3, "Range near", 0, 500, UI_Misc_Sonar_Range_Near);
				const auto Block_Misc_Radar_ = Free_GUI_VAR.GUI_Block(580, 270, 160, "Radar");
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Radar_, 1, "Enabled", UI_Misc_Radar);
				Free_GUI_VAR.GUI_Checkbox({ Block_Misc_Radar_[0] + 20,Block_Misc_Radar_[1] }, 2, "Follow angle", UI_Misc_Radar_FollowAngle);
				Free_GUI_VAR.GUI_Slider<float, class Free_Menu_21>(Block_Misc_Radar_, 3, "Radar range", 0.2, 25, UI_Misc_Radar_Range);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_22>(Block_Misc_Radar_, 4, "Radar size", 150, 500, UI_Misc_Radar_Size);
				const auto Block_Misc_Resolution_ = Free_GUI_VAR.GUI_Block(580, 30, 220, "Screen resolution");
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 1, "3840 × 2160", 78, UI_Settings_Res_3840);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 2, "2560 × 1440", 78, UI_Settings_Res_2560);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 3, "1920 × 1080", 78, UI_Settings_Res_1920);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 4, "1440 × 1080", 78, UI_Settings_Res_1440);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 5, "1280 × 1024", 78, UI_Settings_Res_1280);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 6, "1280 × 960", 78, UI_Settings_Res_960);
				Free_GUI_VAR.GUI_Tips(Block_Misc_Misc_, 3, "Being covered by a window will reduce the frame rate. (NVIDIA GeForce Overlay)");
				Free_GUI_VAR.GUI_Tips(Block_Misc_Sonar_, 1, "Makes a subtle sound when approaching an enemy.");
				Free_GUI_VAR.GUI_Tips({ Block_Misc_Resolution_[0] + 10,Block_Misc_Resolution_[1] }, 1, "Flexible switching of window resolution.");
				WindowSize = { 1010,460 };
			}
			else if (UI_Panel == 2)//Settings
			{
				const auto Block_Settings_Settings_ = Free_GUI_VAR.GUI_Block(150, 30, 490, "Settings");
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 1, "FreeCS", Free_GUI_VAR.Global_Get_EasyGUI_Color());
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 1, "            for CS:GO (External)", { 100,100,100 });
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 2, "Release date: " + ReleaseDate, { 100,100,100 });
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 3, "Applicable CS:GO Version: " + ApplicableVersion, { 100,100,100 });
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 4, "Menu key");
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_23>(Block_Settings_Settings_, 4, UI_Settings_MenuKey);
				Free_GUI_VAR.GUI_Checkbox(Block_Settings_Settings_, 5, "Custom menu color", UI_Settings_CustomMenuColor);
				Free_GUI_VAR.GUI_ColorSelector(Block_Settings_Settings_, 5, UI_Settings_MenuColor);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_24>(Block_Settings_Settings_, 6, "Alpha", 150, 255, UI_Settings_MenuAlpha);
				Free_GUI_VAR.GUI_Checkbox(Block_Settings_Settings_, 7, "Watermark", UI_Settings_WaterMark);
				Free_GUI_VAR.GUI_Checkbox(Block_Settings_Settings_, 8, "Show console window [Debug]", UI_Settings_ShowDebugWindow);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 9, "SaveConfig", 85, UI_Settings_SaveConfig);
				if (CS_Window_HWND)Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 10, "Restart CS", 81, UI_Settings_RestartCS);
				else Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 10, "Start CS", 85, UI_Settings_RestartCS);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 11, "Quit CS", 90, UI_Settings_QuitCS);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 12, "SendCommand to CS", 55, UI_Settings_SendCommand);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 13, "SendTestCommand to CS", 40, UI_Settings_SendTestCommand);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 14, "Restart FreeCS", 70, UI_Settings_RestartFreeCS);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 15, "Close", 100, UI_Settings_CloseFreeCS);
				Free_GUI_VAR.GUI_Tips({ Block_Settings_Settings_[0] + 10,Block_Settings_Settings_[1] }, 9, "If you want to reset the default config you can delete FreeCS.cfg in the same folder.");
				Free_GUI_VAR.GUI_Tips({ Block_Settings_Settings_[0] + 10,Block_Settings_Settings_[1] }, 12, "Set your personal parameters.");
				WindowSize = { 580,550 };
			}
			Free_GUI_VAR.Draw_GUI();
		}
	}
}
void Thread_Misc() noexcept
{
	System::Log("Load Thread: Thread_Misc()");
	Window::Windows WaterMark_Window_Var;
	const auto Render_Window_HWND_ = WaterMark_Window_Var.Create_RenderBlock_Alpha(Window::Get_Resolution()[0], 30, System::Rand_String(20));//Create RenderWindow
	Window::Render WaterMark_Render_Var; WaterMark_Render_Var.CreatePaint(Render_Window_HWND_, 0, 0, Window::Get_Resolution()[0], 30);
	while (true)
	{
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (System::Sleep_Tick<class Memory_Offsets_Sleep_Class_>(500))//Reload Offsets and Memory
		{
			CS_Mem_ = { "csgo.exe" };//CS Process
			CS_Window_HWND = CS_Mem_.Get_ProcessHWND();
			Module_client = CS_Mem_.Get_Module("client.dll");
			Module_engine = CS_Mem_.Get_Module("engine.dll");
			LocalPlayer = CS_Mem_.Read<uintptr_t>(Module_client + dwLocalPlayer);
			CS_Window_State = CS_Window_HWND && Window::Get_WindowEnable(CS_Window_HWND);
			if (CS_Window_State)
			{
				if (UI_Misc_AutoClearDecals)Source_ExecuteCommand("r_cleardecals");//清除血迹
				LocalPlayer_Active_Weapon = Active_Weapon();//screening weapons
			}
		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (UI_Settings_WaterMark)//WaterMark
		{
			WaterMark_Window_Var.Set_Window_Pos(0, 0);
			if (System::Sleep_Tick<class WaterMark_Window_Sleep_Class_>(200))//Sleep no in thread.
			{
				const auto Menu_Color = Free_GUI_IO.GUIColor;
				static string WaterMark_String = "";
				short WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 4.8;
				if (!CS_Window_HWND)WaterMark_String = "FreeCS | CS not found | " + System::Time_String();
				else {
					WaterMark_String = "FreeCS | " + System::Time_String();
					WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 5.2;
				}
				const vector<int> Watermark_Pos = { Window::Get_Resolution()[0] - WaterMark_String_Size - 10,10 };
				WaterMark_Render_Var.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });
				WaterMark_Render_Var.RenderA_SolidRect(Watermark_Pos[0], Watermark_Pos[1], WaterMark_String_Size, 14, { 1,1,1,150 });
				WaterMark_Render_Var.RenderA_GradientRect(Watermark_Pos[0], Watermark_Pos[1], WaterMark_String_Size / 2, 1, { Menu_Color[0] / 2, Menu_Color[1] / 2, Menu_Color[2] / 2,255 }, { Menu_Color[0], Menu_Color[1], Menu_Color[2],255 });
				WaterMark_Render_Var.RenderA_GradientRect(Watermark_Pos[0] + WaterMark_String_Size / 2, Watermark_Pos[1], WaterMark_String_Size / 2 + 1, 1, { Menu_Color[0], Menu_Color[1], Menu_Color[2],255 }, { Menu_Color[0] / 2, Menu_Color[1] / 2, Menu_Color[2] / 2,255 });
				WaterMark_Render_Var.Render_String(Watermark_Pos[0] + 3, Watermark_Pos[1] + 1, WaterMark_String, "Small Fonts", 12, { 255,255,255 });
				WaterMark_Render_Var.DrawPaint();
				WaterMark_Window_Var.Fix_inWhile();
			}
		}
		else WaterMark_Window_Var.Set_Window_Pos(9999, 9999);
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (UI_Settings_Res_3840)Window::Set_Resolution(3840, 2160);
		else if (UI_Settings_Res_2560)Window::Set_Resolution(2560, 1440);
		else if (UI_Settings_Res_1920)Window::Set_Resolution(1920, 1080);
		else if (UI_Settings_Res_1440)Window::Set_Resolution(1440, 1080);
		else if (UI_Settings_Res_1280)Window::Set_Resolution(1280, 1024);
		else if (UI_Settings_Res_960)Window::Set_Resolution(1280, 960);
		if (UI_Settings_SaveConfig)//SaveConfig
		{
			System::Create_File("FreeCS.cfg",
				to_string(UI_Legit_Aimbot) + "\n" +
				to_string(UI_Legit_Aimbot_Key) + "\n" +
				to_string(UI_Legit_Aimbot_BodyAim) + "\n" +
				to_string(UI_Legit_Aimbot_JudgingWall) + "\n" +
				to_string(UI_Legit_Aimbot_TriggerOnAiming) + "\n" +
				to_string(UI_Legit_Aimbot_RemoveRecoil) + "\n" +
				to_string(UI_Legit_Aimbot_AutoShoot) + "\n" +
				to_string(UI_Legit_Aimbot_AutoShoot_Interval) + "\n" +
				to_string(UI_Legit_Aimbot_AdaptiveAimbot) + "\n" +
				to_string(UI_Legit_Aimbot_A_Range_PISTOL) + "\n" +
				to_string(UI_Legit_Aimbot_A_Smooth_PISTOL) + "\n" +
				to_string(UI_Legit_Aimbot_A_Range_RIFLE) + "\n" +
				to_string(UI_Legit_Aimbot_A_Smooth_RIFLE) + "\n" +
				to_string(UI_Legit_Aimbot_A_Range_SNIPER) + "\n" +
				to_string(UI_Legit_Aimbot_A_Smooth_SNIPER) + "\n" +
				to_string(UI_Legit_Triggerbot) + "\n" +
				to_string(UI_Legit_Triggerbot_Key) + "\n" +
				to_string(UI_Legit_Triggerbot_ShootInterval) + "\n" +
				to_string(UI_Legit_Triggerbot_ShootDuration) + "\n" +
				to_string(UI_Legit_PreciseAim) + "\n" +
				to_string(UI_Legit_PreciseAim_DefaultSensitivity) + "\n" +
				to_string(UI_Legit_PreciseAim_EnableSensitivity) + "\n" +
				to_string(UI_Legit_Backtracking) + "\n" +
				to_string(UI_Legit_Backtracking_Time) + "\n" +
				to_string(UI_Misc_BunnyHop) + "\n" +
				to_string(UI_Misc_BunnyHop_100Tri) + "\n" +
				to_string(UI_Misc_ESP) + "\n" +
				to_string(UI_Misc_ESP_Key) + "\n" +
				to_string(UI_Misc_HitSound) + "\n" +
				to_string(UI_Misc_Sonar) + "\n" +
				to_string(UI_Misc_Sonar_Key) + "\n" +
				to_string(UI_Misc_Sonar_Range_Far) + "\n" +
				to_string(UI_Misc_Sonar_Range_Near) + "\n" +
				to_string(UI_Misc_Radar) + "\n" +
				to_string(UI_Misc_Radar_FollowAngle) + "\n" +
				to_string(UI_Misc_Radar_Range) + "\n" +
				to_string(UI_Misc_Radar_Size) + "\n" +
				to_string(UI_Legit_RemoveRecoil) + "\n" +
				to_string(UI_Legit_RemoveRecoil_LateralRepair) + "\n" +
				to_string(UI_Settings_MenuKey) + "\n" +
				to_string(UI_Settings_CustomMenuColor) + "\n" +
				to_string(UI_Settings_MenuColor[0]) + "\n" +
				to_string(UI_Settings_MenuColor[1]) + "\n" +
				to_string(UI_Settings_MenuColor[2]) + "\n" +
				to_string(UI_Settings_MenuAlpha) + "\n" +
				to_string(UI_Settings_ShowDebugWindow) + "\n" +
				to_string(UI_Settings_WaterMark) + "\n" +
				to_string(UI_Misc_ESP_RenderSleep) + "\n" +
				to_string(UI_Misc_AutoClearDecals) + "\n"
			);
		}
		if (UI_Settings_RestartCS)
		{
			Source_ExecuteCommand("quit");
			System::Open_Website("steam://rungameid/730");//Start CS
		}
		if (UI_Settings_QuitCS)Source_ExecuteCommand("quit");
		if (UI_Settings_SendCommand)//Send Var to Source
		{
			Source_ExecuteCommand("sv_cheats 1");//开启作弊
			Source_ExecuteCommand("fps_max 0");//关闭帧数限制
			Source_ExecuteCommand("cl_radar_scale 0.4");//地图缩放
			Source_ExecuteCommand("cl_hud_radar_scale 1.15");//地图大小
			Source_ExecuteCommand("cl_radar_always_centered 1");//人物为中心
			Source_ExecuteCommand("cl_radar_rotate 1");//人物视角为中心旋转的地图
			Source_ExecuteCommand("cl_radar_icon_scale_min 0.4");//小地图人物提示大小(小点点)
			Source_ExecuteCommand("cl_radar_square_with_scoreboard 0");//地图为圆形
			Source_ExecuteCommand("net_graph 1");//显示fps loss ping
			Source_ExecuteCommand("net_graphproportionalfont 0.5");//fps loss ping 大小为0.5
			Source_ExecuteCommand("hud_scaling 0.7");//hud大小
			Source_ExecuteCommand("sensitivity 1.5");//鼠标灵敏度设置为1.5
			Source_ExecuteCommand("zoom_sensitivity_ratio_mouse 0.63"); //开镜鼠标灵敏度设置为0.63
			Source_ExecuteCommand("cl_bob_lower_amt 5");//手臂晃动
			Source_ExecuteCommand("cl_crosshairalpha 255;cl_crosshaircolor 2;cl_crosshairdot 0;cl_crosshair_t 0;cl_crosshairgap  -3;cl_crosshairsize 2;cl_crosshairstyle 4;cl_crosshairthickness 1;cl_crosshair_outlinethickness 0;cl_crosshair_drawoutline 0;");//准星
			Source_ExecuteCommand("m_yaw 0.015");//4比3模式横向灵敏度 默认0.022
			Source_ExecuteCommand("m_pitch 0.022");//默认垂直灵敏度
			Source_ExecuteCommand("bind \"F1\" \"+jump;-attack;-attack2;-jump\"");//F1跳投（先按住开火键）
			Source_ExecuteCommand("bind \"F2\" noclip");//F2飞行（跑图用）
		}
		if (UI_Settings_SendTestCommand)//Send Test Var to Source
		{
			Source_ExecuteCommand("sv_cheats 1");//开启作弊
			Source_ExecuteCommand("sv_infinite_ammo 1");//无限弹药
			Source_ExecuteCommand("mp_roundtime_defuse 60");//回合时间60分钟
			Source_ExecuteCommand("bot_stop 1");//机器人静止
			Source_ExecuteCommand("mp_buy_anywhere 1");//任何地方购买武器装备
			Source_ExecuteCommand("mp_buytime 99999");//超长购买时间
			Source_ExecuteCommand("mp_startmoney 16000");//回合初始金钱
			Source_ExecuteCommand("god");//无敌
			Source_ExecuteCommand("sv_showimpacts 1");//弹点显示
			Source_ExecuteCommand("sv_showimpacts_time 15");//弹点显示时间
			Source_ExecuteCommand("sv_grenade_trajectory 1");//投掷物轨迹
			Source_ExecuteCommand("sv_grenade_trajectory_dash 1");//设置成点划线
			Source_ExecuteCommand("sv_grenade_trajectory_thickness 1");//轨迹线的粗度
			Source_ExecuteCommand("sv_grenade_trajectory_time 20");//轨迹线保留时间
			Source_ExecuteCommand("mp_humanteam any");//可选任何队伍
			Source_ExecuteCommand("mp_restartgame 1");//重开比赛
		}
		if (UI_Settings_RestartFreeCS)System::Self_Restart();
		if (UI_Settings_CloseFreeCS)exit(0);
		if (UI_Settings_ShowDebugWindow)ShowWindow(GetConsoleWindow(), true);//ShowConsoleWindow
		else ShowWindow(GetConsoleWindow(), false);//HideConsoleWindow
		Free_GUI_IO = Free_GUI_VAR.Get_IO();
		if (!UI_Settings_CustomMenuColor)Free_GUI_IO.GUIColor = { (int)floor(sin((float)GetTickCount64() / 3500 * 2 + 2) * 127 + 128),(int)floor(sin((float)GetTickCount64() / 3500 * 2 + 2 + 2) * 127 + 128),(int)floor(sin((float)GetTickCount64() / 3500 * 2 + 4 + 2) * 127 + 128) };
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (CS_Window_State)//Misc Funtions
		{
			//--------------------------------------
			if (UI_Misc_HitSound)//HitSound
			{
				static int OldDamage = 0;
				static int OldKill = 0;
				int Damage = CS_Mem_.Read<int>(LocalPlayer + 0x99a8);//hit value
				int Kill = CS_Mem_.Read<int>(LocalPlayer + 0x99a0);//kill value
				if (Damage > OldDamage || Damage < OldDamage && CS_Mem_.Read<BOOL>(LocalPlayer + m_iHealth))//当击中人物
				{
					//if (Kill > OldKill)Source_ExecuteCommand("playvol buttons/light_power_on_switch_01.wav 1");//kill
					if (Kill > OldKill)Source_ExecuteCommand("playvol buttons/arena_switch_press_02.wav 1");//kill
					else if (Damage > OldDamage)Source_ExecuteCommand("playvol buttons/arena_switch_press_02.wav 1");//hit
					OldDamage = Damage;
					OldKill = Kill;
				}
			}
			//--------------------------------------
		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		Sleep(1);
	}
}
void Thread_Funtion_Aimbot() noexcept
{
	System::Log("Load Thread: Thread_Funtion_Aimbot()");
	while (true)
	{
		Sleep(1);
		if (CS_Window_State && UI_Legit_Aimbot && System::Get_Key(UI_Legit_Aimbot_Key))//When the cs window is at the front. Press Key
		{
			short Aim_Range; float Aim_Smooth;
			if (LocalPlayer_Active_Weapon[1] == 1)//PISTOL
			{
				Aim_Range = UI_Legit_Aimbot_A_Range_PISTOL / 5;
				Aim_Smooth = UI_Legit_Aimbot_A_Smooth_PISTOL;
			}
			else if (LocalPlayer_Active_Weapon[1] == 2)//RIFLE
			{
				Aim_Range = UI_Legit_Aimbot_A_Range_RIFLE / 5;
				Aim_Smooth = UI_Legit_Aimbot_A_Smooth_RIFLE;
			}
			else if (LocalPlayer_Active_Weapon[1] == 3)//SNIPER
			{
				Aim_Range = UI_Legit_Aimbot_A_Range_SNIPER / 5;
				Aim_Smooth = UI_Legit_Aimbot_A_Smooth_SNIPER;
			}
			else continue;
			if (Aim_Range == 0)continue;
			if (UI_Legit_Aimbot_AutoShoot)//activate trigger
			{
				if (Aim_Range == 20)Aim_Range = 100;
				System::Mouse_Move(2, 0);
				Sleep(1);
				System::Mouse_Move(-2, 0);
			}
			short Aim_Parts;
			if (UI_Legit_Aimbot_BodyAim)Aim_Parts = 5;//Parts 8Head 5Body
			else Aim_Parts = 8;
			Variable::Vector3 Recoil_Angle;
			if (UI_Legit_Aimbot_RemoveRecoil)Recoil_Angle = CS_Mem_.Read<Variable::Vector3>(CS_Mem_.Read<uintptr_t>(Module_engine + dwClientState) + dwClientState_ViewAngles) + CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_aimPunchAngle) * 2;//RemoveRecoil
			else Recoil_Angle = CS_Mem_.Read<Variable::Vector3>(CS_Mem_.Read<uintptr_t>(Module_engine + dwClientState) + dwClientState_ViewAngles);//original angle
			const auto CrosshairId = CS_Mem_.Read<int32_t>(LocalPlayer + m_iCrosshairId);
			const auto playerm = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + (CrosshairId - 1) * 0x10);//entity
			for (short i = 0; i <= 20; ++i)
			{
				const auto player = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + i * 0x10);//Get All EntityID
				if (!CS_Mem_.Read<BOOL>(LocalPlayer + m_iHealth) || !CS_Mem_.Read<BOOL>(player + m_iHealth) || CS_Mem_.Read<int32_t>(player + m_iTeamNum) == CS_Mem_.Read<int32_t>(LocalPlayer + m_iTeamNum) || !CS_Mem_.Read<BOOL>(player + m_bSpotted) || CS_Mem_.Read<BOOL>(player + m_bDormant))
					continue;
				if ((UI_Legit_Aimbot_TriggerOnAiming && !CS_Mem_.Read<BOOL>(playerm + m_iHealth)) || (UI_Legit_Aimbot_JudgingWall && !CS_Mem_.Read<BOOL>(player + m_bSpotted)))//TriggerOnAiming & JudgingWall
					continue;
				const auto boneMatrix = CS_Mem_.Read<uintptr_t>(player + m_dwBoneMatrix);
				const auto angle = Variable::CalculateAngle(CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_vecOrigin) + CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_vecViewOffset),
					Variable::Vector3{CS_Mem_.Read<float>(boneMatrix + 0x30 * Aim_Parts + 0x0C), CS_Mem_.Read<float>(boneMatrix + 0x30 * Aim_Parts + 0x1C), CS_Mem_.Read<float>(boneMatrix + 0x30 * Aim_Parts + 0x2C)}, Recoil_Angle);
				const auto FovG = hypot(angle.x, angle.y);
				if (FovG <= Aim_Range)
				{
					Aim_Range = FovG;
					if (!angle.IsZero())System::Mouse_Move(-angle.y * (33 - Aim_Smooth) * 2, angle.x * (33 - Aim_Smooth));
					if (UI_Legit_Aimbot_AutoShoot && CS_Mem_.Read<BOOL>(playerm + m_iHealth) && FovG <= 1)
					{
						Source_ExecuteCommand("+attack");
						Sleep(1);
						Source_ExecuteCommand("-attack");
						Sleep(UI_Legit_Aimbot_AutoShoot_Interval);//Auto Shoot Interval
					}
				}
			}
		}
		else Sleep(10);
	}
}
void Thread_Funtion_AdaptiveAimbot() noexcept
{
	System::Log("Load Thread: Thread_Funtion_AdaptiveAimbot()");
	while (true)
	{
		Sleep(1);
		if (CS_Window_State && UI_Legit_Aimbot_AdaptiveAimbot && System::Get_Key(VK_LBUTTON))//When the cs window is at the front. Press Key
		{
			if (LocalPlayer_Active_Weapon[1] != 2)continue;
			float Aim_Range = 2.5;
			if (abs(CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_aimPunchAngle).x) * 2 >= Aim_Range)Aim_Range = abs(CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_aimPunchAngle).x) * 0.5;
			for (short i = 0; i <= 20; ++i)
			{
				const auto player = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + i * 0x10);
				if (!CS_Mem_.Read<BOOL>(LocalPlayer + m_iHealth) || !CS_Mem_.Read<BOOL>(player + m_iHealth) || CS_Mem_.Read<int32_t>(player + m_iTeamNum) == CS_Mem_.Read<int32_t>(LocalPlayer + m_iTeamNum) || !CS_Mem_.Read<BOOL>(player + m_bSpotted) || CS_Mem_.Read<BOOL>(player + m_bDormant))
					continue;
				const auto boneMatrix = CS_Mem_.Read<uintptr_t>(player + m_dwBoneMatrix);
				const auto angle = Variable::CalculateAngle(CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_vecOrigin) + CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_vecViewOffset), Variable::Vector3{ CS_Mem_.Read<float>(boneMatrix + 0x30 * 8 + 0x0C), CS_Mem_.Read<float>(boneMatrix + 0x30 * 8 + 0x1C), CS_Mem_.Read<float>(boneMatrix + 0x30 * 8 + 0x2C) }, CS_Mem_.Read<Variable::Vector3>(CS_Mem_.Read<uintptr_t>(Module_engine + dwClientState) + dwClientState_ViewAngles) + CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_aimPunchAngle) * 2);
				const auto FovG = hypot(angle.x, angle.y);
				if (!angle.IsZero() && FovG <= Aim_Range)
				{
					Aim_Range = FovG;
					if (System::Get_Key(VK_CONTROL) || FovG <= 0.5)System::Mouse_Move(-angle.y * 20, angle.x * 20);
					else System::Mouse_Move(-angle.y * 10, angle.x * 5);
				}
			}
		}
		else Sleep(10);
	}
}
void Thread_Funtion_Triggerbot() noexcept
{
	System::Log("Load Thread: Thread_Funtion_Triggerbot()");
	while (true)
	{
		if (CS_Window_State && UI_Legit_Triggerbot && System::Get_Key(UI_Legit_Triggerbot_Key))//When the cs window is at the front. Press Key
		{
			System::Sleep_ns(500);//Nano sleep
			const auto playerm = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + (CS_Mem_.Read<int32_t>(LocalPlayer + m_iCrosshairId) - 1) * 0x10);
			if (!CS_Mem_.Read<BOOL>(LocalPlayer + m_iHealth) || CS_Mem_.Read<int32_t>(playerm + m_iTeamNum) == CS_Mem_.Read<int32_t>(LocalPlayer + m_iTeamNum) || LocalPlayer_Active_Weapon[0] == 42 || LocalPlayer_Active_Weapon[0] == 59 || LocalPlayer_Active_Weapon[0] >= 500)
				continue;
			if (CS_Mem_.Read<BOOL>(playerm + m_iHealth))//Aim people is live
			{
				Source_ExecuteCommand("+attack");//Shoot!!
				Sleep(UI_Legit_Triggerbot_ShootDuration);
				Source_ExecuteCommand("-attack");
				Sleep(UI_Legit_Triggerbot_ShootInterval);
			}
		}
		else Sleep(10);
	}
}
void Thread_Funtion_PreciseAim() noexcept
{
	System::Log("Load Thread: Thread_Funtion_PreciseAim()");
	while (true)
	{
		if (CS_Window_State && UI_Legit_PreciseAim)//When the cs window is at the front. Press Key
		{
			System::Sleep_ns(2000);//Nano sleep
			if (LocalPlayer_Active_Weapon[0] == 42 || LocalPlayer_Active_Weapon[0] == 59 || LocalPlayer_Active_Weapon[0] >= 500)
			{
				Source_ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity));
				Sleep(10);
				continue;
			}
			const auto playerm = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + (CS_Mem_.Read<int32_t>(LocalPlayer + m_iCrosshairId) - 1) * 0x10);
			if (!CS_Mem_.Read<BOOL>(LocalPlayer + m_iHealth) || CS_Mem_.Read<int32_t>(playerm + m_iTeamNum) == CS_Mem_.Read<int32_t>(LocalPlayer + m_iTeamNum))
				continue;
			if (CS_Mem_.Read<BOOL>(playerm + m_iHealth))Source_ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_EnableSensitivity));
			else Source_ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity));
		}
		else Sleep(10);
	}
}
void Thread_Funtion_RemoveRecoil() noexcept
{
	System::Log("Load Thread: Thread_Funtion_RemoveRecoil()");
	while (true)
	{
		if (CS_Window_State)//When the cs window is at the front.
		{
			static auto OldPunch = Variable::Vector3{};
			if (System::Get_Key(VK_LBUTTON) && UI_Legit_RemoveRecoil)//If Press Key
			{
				const auto AimPunch = CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_aimPunchAngle);//RecoilAngle
				const auto NewPunch = Variable::Vector3{ OldPunch.x - AimPunch.x * 2.f,OldPunch.y - AimPunch.y * 2.f,0 };
				if (UI_Legit_RemoveRecoil_LateralRepair)System::Mouse_Move(-NewPunch.y * 39, 0);//X
				else System::Mouse_Move(-NewPunch.y * 39, NewPunch.x * 32);//X,Y
				OldPunch.x = AimPunch.x * 2.f;
				OldPunch.y = AimPunch.y * 2.f;
			}
			else OldPunch.x = OldPunch.y = 0;
			Sleep(1);
		}
		else Sleep(10);
	}
}
void Thread_Funtion_BunnyHop() noexcept
{
	System::Log("Load Thread: Thread_Funtion_BunnyHop()");
	while (true)
	{
		if (CS_Window_State && UI_Misc_BunnyHop && System::Get_Key(VK_SPACE) && CS_Mem_.Read<BOOL>(LocalPlayer + m_iHealth))//When the cs window is at the front. Press Key
		{
			if (CS_Mem_.Read<BOOL>(LocalPlayer + m_fFlags) & (1 << 0))
			{
				Source_ExecuteCommand("+jump");
				Sleep(1);
				Source_ExecuteCommand("-jump");
			}
			if (System::Get_Key(UI_Misc_BunnyHop_100Tri))System::Sleep_ns(100);
			else Sleep(1);
		}
		else Sleep(10);
	}
}
void Thread_Funtion_ESP() noexcept
{
	System::Log("Load Thread: Thread_Funtion_ESP()");
	const auto FreeCS_ESP_RenderWindow = Window::NVIDIA_Overlay();
	Window::Render FreeCS_ESP_Render_Paint_Var; FreeCS_ESP_Render_Paint_Var.CreatePaint(FreeCS_ESP_RenderWindow, 0, 0, Window::Get_Resolution()[0], Window::Get_Resolution()[1]);
	while (true)
	{
		Sleep(UI_Misc_ESP_RenderSleep);
		FreeCS_ESP_Render_Paint_Var.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//Clear Paint
		if (CS_Window_State && UI_Misc_ESP && (UI_Misc_ESP_Key == 0 || System::Get_Key(UI_Misc_ESP_Key)))//When the cs window is at the front. Press Key
		{
			MoveWindow(FreeCS_ESP_RenderWindow, Window::Get_WindowResolution(CS_Window_HWND)[2], Window::Get_WindowResolution(CS_Window_HWND)[3], Window::Get_WindowResolution(CS_Window_HWND)[0], Window::Get_WindowResolution(CS_Window_HWND)[1], TRUE);//Bigger
			const auto vm = CS_Mem_.Read<Variable::view_matrix_t>(Module_client + dwViewMatrix);
			for (short i = 0; i <= 20; ++i)
			{
				const auto entity = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + i * 0x10);
				if (CS_Mem_.Read<BOOL>(entity + m_iHealth) && CS_Mem_.Read<int32_t>(entity + m_iTeamNum) != CS_Mem_.Read<int32_t>(LocalPlayer + m_iTeamNum))
				{
					auto 敌人坐标 = CS_Mem_.Read<Variable::Vector3>(entity + m_vecOrigin); 敌人坐标.z = 敌人坐标.z + 40;
					const auto screenpos = WorldToScreen(Window::Get_WindowResolution(CS_Window_HWND)[0], Window::Get_WindowResolution(CS_Window_HWND)[1], 敌人坐标, vm);
					FreeCS_ESP_Render_Paint_Var.RenderA_GradientLine(Window::Get_WindowResolution(CS_Window_HWND)[0] / 2, Window::Get_WindowResolution(CS_Window_HWND)[1], screenpos.x + 4, screenpos.y + 3, { 0,0,0,0 }, { Free_GUI_IO.GUIColor[0],Free_GUI_IO.GUIColor[1],Free_GUI_IO.GUIColor[2],180 });
					FreeCS_ESP_Render_Paint_Var.Render_HollowCircle(screenpos.x + 4, screenpos.y, 10, { Free_GUI_IO.GUIColor[0] / 2,Free_GUI_IO.GUIColor[1] / 2,Free_GUI_IO.GUIColor[2] / 2 }, 2);
					FreeCS_ESP_Render_Paint_Var.Render_String(screenpos.x + 8, screenpos.y + 2, to_string(CS_Mem_.Read<int32_t>(entity + m_iHealth)), "Small Fonts", 10, Free_GUI_IO.GUIColor);
				}
			}
		}
		else Sleep(100);
		FreeCS_ESP_Render_Paint_Var.DrawPaint();
	}
}
void Thread_Funtion_Sonar() noexcept
{
	System::Log("Load Thread: Thread_Funtion_Sonar()");
	while (true)
	{
		Sleep(1);
		if (CS_Window_State && UI_Misc_Sonar && (UI_Misc_Sonar_Key == 0 || System::Get_Key(UI_Misc_Sonar_Key)))//When the cs window is at the front. Press Key
		{
			const auto 自身坐标 = CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_vecOrigin);//LocalPlayer Pos
			for (short i = 0; i <= 20; ++i)
			{
				Sleep(1);
				if (UI_Misc_Sonar_Key != 0 && !System::Get_Key(UI_Misc_Sonar_Key))continue;//fast
				const auto entity = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + i * 0x10);
				if (!CS_Mem_.Read<BOOL>(LocalPlayer + m_iHealth) || !CS_Mem_.Read<BOOL>(entity + m_iHealth) || CS_Mem_.Read<int32_t>(entity + m_iTeamNum) == CS_Mem_.Read<int32_t>(LocalPlayer + m_iTeamNum))
					continue;
				const Variable::Vector3 敌人坐标 = CS_Mem_.Read<Variable::Vector3>(entity + m_vecOrigin);
				if (hypot(自身坐标.x - 敌人坐标.x, 自身坐标.y - 敌人坐标.y) <= UI_Misc_Sonar_Range_Near)Source_ExecuteCommand("playvol buttons/button16.wav 1");
				else if (hypot(自身坐标.x - 敌人坐标.x, 自身坐标.y - 敌人坐标.y) <= UI_Misc_Sonar_Range_Far)Source_ExecuteCommand("playvol ui/xp_remaining.wav 1");
				if (hypot(自身坐标.x - 敌人坐标.x, 自身坐标.y - 敌人坐标.y) <= UI_Misc_Sonar_Range_Far)Sleep(30);
			}
		}
		else Sleep(10);
	}
}
void Thread_Funtion_Radar() noexcept
{
	System::Log("Load Thread: Thread_Funtion_Radar()");
	Window::Windows RadarWindowsBL; Window::Render RenderDBBL;
	const auto RadarRenderWindow = RadarWindowsBL.Create_Window(UI_Misc_Radar_Size, UI_Misc_Radar_Size + 15, System::Rand_String(22), true);//Create Render Window
	RadarWindowsBL.Set_WindowAlpha(180);
	RadarWindowsBL.Set_Window_Pos(17, 40);//To Game Radar Pos
	RenderDBBL.CreatePaint(RadarRenderWindow, 0, 0, 500, 500 + 15);//Create Paint
	while (true)
	{
		Sleep(10);//Low Down CPU
		if ((CS_Window_State || MenuShowState || Window::Get_WindowEnable(RadarWindowsBL.Get_HWND())) && UI_Misc_Radar)//When the cs window is at the front. Press Key
		{
			const short RadarSizeAnimation = Variable::Animation<class Class_Radar_Window_Size>(UI_Misc_Radar_Size, 5);
			const float RadarRangeAnimation = Variable::Animation<class Class_Radar_Window_Range>(UI_Misc_Radar_Range, 5);
			RadarWindowsBL.Set_Window_Size(RadarSizeAnimation, RadarSizeAnimation + 15);//Animation
			const auto LocalPlayerPos = CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_vecOrigin);//localPlayerPos
			const auto viewAngles = CS_Mem_.Read<Variable::Vector3>(CS_Mem_.Read<uintptr_t>(Module_engine + dwClientState) + dwClientState_ViewAngles);
			if (!RadarWindowsBL.Window_Move(15))
			{
				RenderDBBL.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//BackGround
				RenderDBBL.Render_GradientRect(0, 0, RadarWindowsBL.Get_Window_Size()[0], 14, { Free_GUI_IO.GUIColor[0] / 2,Free_GUI_IO.GUIColor[1] / 2,Free_GUI_IO.GUIColor[2] / 2 }, { Free_GUI_IO.GUIColor[0] / 3,Free_GUI_IO.GUIColor[1] / 3,Free_GUI_IO.GUIColor[2] / 3 }, false);
				RenderDBBL.Render_GradientRect(0, 14, RadarWindowsBL.Get_Window_Size()[0], 1, { Free_GUI_IO.GUIColor[0] / 3,Free_GUI_IO.GUIColor[1] / 3,Free_GUI_IO.GUIColor[2] / 3 }, { Free_GUI_IO.GUIColor[0] / 2,Free_GUI_IO.GUIColor[1] / 2,Free_GUI_IO.GUIColor[2] / 2 }, false);//Title Rect
				RenderDBBL.Render_String(3 + 1, 1 + 1, "FreeCS Radar", "Small Fonts", 12, { 0,0,0 });
				RenderDBBL.Render_String(3, 1, "FreeCS Radar", "Small Fonts", 12, Free_GUI_IO.GUIColor);//Title
				if (UI_Misc_Radar_FollowAngle)RenderDBBL.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[1] ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[1] }, { Free_GUI_IO.GUIColor[0] / 5,Free_GUI_IO.GUIColor[1] / 5,Free_GUI_IO.GUIColor[2] / 5 }, { 0,0,0 }, { 0,0,0 });
				else RenderDBBL.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, viewAngles.y, 45)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, viewAngles.y, 45)[1] ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, viewAngles.y, 135)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, viewAngles.y, 135)[1] }, { Free_GUI_IO.GUIColor[0] / 5,Free_GUI_IO.GUIColor[1] / 5,Free_GUI_IO.GUIColor[2] / 5 }, { 0,0,0 }, { 0,0,0 });//Self Aimpos
				RenderDBBL.Render_HollowCircle(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 100 * 3, { 255,255,255 }, 1);//Self Pos
				for (short i = 0; i <= 20; ++i)
				{
					const auto entity = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList + i * 0x10);
					if (CS_Mem_.Read<BOOL>(entity + m_iHealth) && CS_Mem_.Read<int32_t>(entity + m_iTeamNum) != CS_Mem_.Read<int32_t>(LocalPlayer + m_iTeamNum))
					{
						Variable::Vector3 entityPos = CS_Mem_.Read<Variable::Vector3>(entity + m_vecOrigin);
						vector<float> 敌人屏幕坐标;
						if (UI_Misc_Radar_FollowAngle)敌人屏幕坐标 = { RadarSizeAnimation / 2 - Variable::角度转坐标(hypot(LocalPlayerPos.x - entityPos.x, LocalPlayerPos.y - entityPos.y), viewAngles.y - 90 + atan2((LocalPlayerPos.x - entityPos.x), (LocalPlayerPos.y - entityPos.y)) * (180.0f / (float)acos(-1)))[0] / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + Variable::角度转坐标(hypot(LocalPlayerPos.x - entityPos.x, LocalPlayerPos.y - entityPos.y), viewAngles.y - 90 + atan2((LocalPlayerPos.x - entityPos.x), (LocalPlayerPos.y - entityPos.y)) * (180.0f / (float)acos(-1)))[1] / RadarRangeAnimation };
						else 敌人屏幕坐标 = { RadarSizeAnimation / 2 - (LocalPlayerPos.x - entityPos.x) / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + (LocalPlayerPos.y - entityPos.y) / RadarRangeAnimation };
						if (敌人屏幕坐标[0] > RadarSizeAnimation)敌人屏幕坐标[0] = RadarSizeAnimation;
						else if (敌人屏幕坐标[0] < 0) 敌人屏幕坐标[0] = 0;
						if (敌人屏幕坐标[1] > RadarSizeAnimation + 15)敌人屏幕坐标[1] = RadarSizeAnimation + 15;
						else if (敌人屏幕坐标[1] < 15)敌人屏幕坐标[1] = 15;
						if (CS_Mem_.Read<BOOL>(entity + m_bSpotted))RenderDBBL.Render_SolidCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3, Free_GUI_IO.GUIColor, Free_GUI_IO.GUIColor, 1);
						else RenderDBBL.Render_HollowCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3, Free_GUI_IO.GUIColor, 1);
					}
				}
				RenderDBBL.DrawPaint();
			}
		}
		else RadarWindowsBL.Set_Window_Size(0, 0);
		RadarWindowsBL.Fix_inWhile();
	}
}
int main() noexcept
{
	system("cls");//Clear text
	System::Log("Load Thread: main()");
	System::Anti_click();//Console not selected.
	Window::Hide_ConsoleWindow();
	Sleep(200);//Fix RestartBug
	if (!System::Judge_File("FreeCS.cfg"))//Create Config
	{
		System::Create_File("FreeCS.cfg", DefaultConfig);//DefaultConfig
		System::Self_Restart();
	}
	thread Thread_Menu_ = thread(Thread_Menu);
	thread Thread_Misc_ = thread(Thread_Misc);
	Sleep(50);
	thread Thread_Funtion_Aimbot_ = thread(Thread_Funtion_Aimbot);
	thread Thread_Funtion_AdaptiveAimbot_ = thread(Thread_Funtion_AdaptiveAimbot);
	thread Thread_Funtion_Triggerbot_ = thread(Thread_Funtion_Triggerbot);
	thread Thread_Funtion_PreciseAim_ = thread(Thread_Funtion_PreciseAim);
	thread Thread_Funtion_RemoveRecoil_ = thread(Thread_Funtion_RemoveRecoil);
	thread Thread_Funtion_BunnyHop_ = thread(Thread_Funtion_BunnyHop);
	thread Thread_Funtion_ESP_ = thread(Thread_Funtion_ESP);
	thread Thread_Funtion_Sonar_ = thread(Thread_Funtion_Sonar);
	thread Thread_Funtion_Radar_ = thread(Thread_Funtion_Radar);
	while (true)
	{
		if (System::Get_Key(VK_INSERT) && System::Get_Key(VK_DELETE))//Close Key
		{
			Beep(100, 30);
			exit(0);
		}
		static short MenuWindowAlpha = 0;//Animation Alpha
		if (MenuShowState)MenuWindowAlpha = MenuWindowAlpha + UI_Settings_MenuAlpha / 10;
		else MenuWindowAlpha = MenuWindowAlpha - UI_Settings_MenuAlpha / 10;
		if (MenuWindowAlpha >= UI_Settings_MenuAlpha)MenuWindowAlpha = UI_Settings_MenuAlpha;
		else if (MenuWindowAlpha <= 0)MenuWindowAlpha = 0;
		Free_GUI_VAR.Window_SetAlpha(MenuWindowAlpha);//SetWindow AlphaColor
		if (UI_Settings_CustomMenuColor)Free_GUI_VAR.Global_Set_EasyGUI_Color(UI_Settings_MenuColor);//Custom Color
		if (!System::Key_Toggle<class Class_CSMENU_KeyHold_>(UI_Settings_MenuKey))
		{
			Free_GUI_VAR.Window_Show();
			MenuShowState = true;
		}
		else {
			if (MenuWindowAlpha == 0)Free_GUI_VAR.Window_Hide();
			MenuShowState = false;
		}
		Sleep(1);
	}
}
