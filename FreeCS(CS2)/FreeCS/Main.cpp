#include "Head.h"
const string FreeCS_ReleaseDate = "[2023-12-30 23:50]";
//-----------------------------------------------------
namespace FreeCS_Config_Variable
{
	EasyGUI::EasyGUI FreeCS_GUI; EasyGUI::EasyGUI_IO FreeCS_GUI_IO; BOOL FreeCS_GUI_ShowState;
	const string FreeCS_DefaultConfig = "0\n2\n0\n1\n0\n1\n1\n100\n1\n40\n20\n40\n20\n0\n0\n1\n5\n1\n150\n1\n0.015\n0.004\n1\n250\n1\n1\n0\n1\n1\n160\n800\n350\n1\n1\n22\n230\n1\n1\n45\n0\n200\n200\n255\n250\n0\n1\n1\n1\n1\n1\n1\n25\n10\n180\n0\n1\n1\n0\n1\n0\n1\n1\n0\n200\n200\n255\n1\n1\n1\n90\n1\n30\n1\n2\n1\n0\n1\n";
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
	BOOL UI_Legit_Backtracking = Variable::string_int_(System::Get_File("FreeCS.cfg", 23));
	int UI_Legit_Backtracking_Time = Variable::string_int_(System::Get_File("FreeCS.cfg", 24));
	BOOL UI_Misc_BunnyHop = Variable::string_int_(System::Get_File("FreeCS.cfg", 25));
	BOOL UI_Visual_ESP = Variable::string_int_(System::Get_File("FreeCS.cfg", 26));
	int UI_Visual_ESP_Key = Variable::string_int_(System::Get_File("FreeCS.cfg", 27));
	BOOL UI_Misc_HitSound = Variable::string_int_(System::Get_File("FreeCS.cfg", 28));
	BOOL UI_Misc_Sonar = Variable::string_int_(System::Get_File("FreeCS.cfg", 29));
	int UI_Misc_Sonar_Key = Variable::string_int_(System::Get_File("FreeCS.cfg", 30));
	int UI_Misc_Sonar_Range_Far = Variable::string_int_(System::Get_File("FreeCS.cfg", 31));
	int UI_Misc_Sonar_Range_Near = Variable::string_int_(System::Get_File("FreeCS.cfg", 32));
	BOOL UI_Visual_Radar = Variable::string_int_(System::Get_File("FreeCS.cfg", 33));
	BOOL UI_Visual_Radar_FollowAngle = Variable::string_int_(System::Get_File("FreeCS.cfg", 34));
	float UI_Visual_Radar_Range = Variable::string_float_(System::Get_File("FreeCS.cfg", 35));
	int UI_Visual_Radar_Size = Variable::string_int_(System::Get_File("FreeCS.cfg", 36));
	BOOL UI_Legit_RemoveRecoil = Variable::string_int_(System::Get_File("FreeCS.cfg", 37));
	BOOL UI_Legit_RemoveRecoil_LateralRepair = Variable::string_int_(System::Get_File("FreeCS.cfg", 38));
	int UI_Settings_MenuKey = Variable::string_int_(System::Get_File("FreeCS.cfg", 39));
	BOOL UI_Settings_CustomMenuColor = Variable::string_int_(System::Get_File("FreeCS.cfg", 40));
	Variable::Vector4 UI_Settings_MenuColor = { Variable::string_int_(System::Get_File("FreeCS.cfg", 41)) ,Variable::string_int_(System::Get_File("FreeCS.cfg", 42)) ,Variable::string_int_(System::Get_File("FreeCS.cfg", 43)) };
	int UI_Settings_MenuAlpha = Variable::string_int_(System::Get_File("FreeCS.cfg", 44));
	BOOL UI_Misc_ShowDebugWindow = Variable::string_int_(System::Get_File("FreeCS.cfg", 45));
	BOOL UI_Settings_SaveConfig;
	BOOL UI_Settings_RestartCS;
	BOOL UI_Settings_QuitCS;
	BOOL UI_Settings_SendCommand;
	BOOL UI_Settings_SendTestCommand;
	BOOL UI_Settings_RestartFreeCS;
	BOOL UI_Settings_CloseFreeCS;
	BOOL UI_Visual_Res_3840;
	BOOL UI_Visual_Res_2560;
	BOOL UI_Visual_Res_1920;
	BOOL UI_Visual_Res_1440;
	BOOL UI_Visual_Res_1280;
	BOOL UI_Visual_Res_960;
	BOOL UI_Visual_Res_800;
	BOOL UI_Misc_WaterMark = Variable::string_int_(System::Get_File("FreeCS.cfg", 46));
	int UI_Visual_ESP_RenderSleep = Variable::string_int_(System::Get_File("FreeCS.cfg", 47));
	BOOL UI_Misc_AutoClearDecals = Variable::string_int_(System::Get_File("FreeCS.cfg", 48));
	BOOL UI_Visual_ESP_Health = Variable::string_int_(System::Get_File("FreeCS.cfg", 49));
	BOOL UI_Visual_ESP_Snapline = Variable::string_int_(System::Get_File("FreeCS.cfg", 50));
	BOOL UI_Visual_ESP_Skeleton = Variable::string_int_(System::Get_File("FreeCS.cfg", 51));
	Variable::Vector2 UI_Visual_Radar_Pos = { Variable::string_int_(System::Get_File("FreeCS.cfg", 52)) ,Variable::string_int_(System::Get_File("FreeCS.cfg", 53)) };
	int UI_Visual_Radar_Alpha = Variable::string_int_(System::Get_File("FreeCS.cfg", 54));
	BOOL UI_Misc_LockGameWindow = Variable::string_int_(System::Get_File("FreeCS.cfg", 55));
	BOOL UI_Legit_Aimbot_ShowRange = Variable::string_int_(System::Get_File("FreeCS.cfg", 56));
	BOOL UI_Misc_AutoKnife = Variable::string_int_(System::Get_File("FreeCS.cfg", 57));
	int UI_Misc_AutoKnife_Key = Variable::string_int_(System::Get_File("FreeCS.cfg", 58));
	BOOL UI_Misc_AutoTaser = Variable::string_int_(System::Get_File("FreeCS.cfg", 59));
	int UI_Misc_AutoTaser_Key = Variable::string_int_(System::Get_File("FreeCS.cfg", 60));
	BOOL UI_Visual_ESP_ActiveWeapon = Variable::string_int_(System::Get_File("FreeCS.cfg", 61));
	BOOL UI_Visual_ESP_Box = Variable::string_int_(System::Get_File("FreeCS.cfg", 62));
	BOOL UI_Visual_ESP_CustomColor = Variable::string_int_(System::Get_File("FreeCS.cfg", 63));
	Variable::Vector4 UI_Visual_ESP_CustomColor_Color = { Variable::string_int_(System::Get_File("FreeCS.cfg", 64)) ,Variable::string_int_(System::Get_File("FreeCS.cfg", 65)) ,Variable::string_int_(System::Get_File("FreeCS.cfg", 66)) };
	BOOL UI_Visual_ESP_State = Variable::string_int_(System::Get_File("FreeCS.cfg", 67));
	BOOL UI_Visual_ESP_Name = Variable::string_int_(System::Get_File("FreeCS.cfg", 68));
	BOOL UI_Visual_ESP_OutFOV = Variable::string_int_(System::Get_File("FreeCS.cfg", 69));
	int UI_Visual_ESP_OutFOV_Radius = Variable::string_int_(System::Get_File("FreeCS.cfg", 70));
	BOOL UI_Legit_Aimbot_AutoShoot_AutoStop = Variable::string_int_(System::Get_File("FreeCS.cfg", 71));
	int UI_Visual_ESP_OutFOV_Size = Variable::string_int_(System::Get_File("FreeCS.cfg", 72));
	BOOL UI_Visual_ESP_Drops = Variable::string_int_(System::Get_File("FreeCS.cfg", 73));
	int UI_Legit_RemoveRecoil_StartBullet = Variable::string_int_(System::Get_File("FreeCS.cfg", 74));
	BOOL UI_Misc_CloudConfig_Legit;
	BOOL UI_Misc_CloudConfig_Rage;
	BOOL UI_Visual_ESP_HeadDot = Variable::string_int_(System::Get_File("FreeCS.cfg", 75));
	BOOL UI_Legit_Triggerbot_AnyTarget = Variable::string_int_(System::Get_File("FreeCS.cfg", 76));
	BOOL UI_Misc_GlobalTeamCheck = Variable::string_int_(System::Get_File("FreeCS.cfg", 77));
	void Save_LocalConfig()
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
			to_string(UI_Visual_ESP) + "\n" +
			to_string(UI_Visual_ESP_Key) + "\n" +
			to_string(UI_Misc_HitSound) + "\n" +
			to_string(UI_Misc_Sonar) + "\n" +
			to_string(UI_Misc_Sonar_Key) + "\n" +
			to_string(UI_Misc_Sonar_Range_Far) + "\n" +
			to_string(UI_Misc_Sonar_Range_Near) + "\n" +
			to_string(UI_Visual_Radar) + "\n" +
			to_string(UI_Visual_Radar_FollowAngle) + "\n" +
			to_string(UI_Visual_Radar_Range) + "\n" +
			to_string(UI_Visual_Radar_Size) + "\n" +
			to_string(UI_Legit_RemoveRecoil) + "\n" +
			to_string(UI_Legit_RemoveRecoil_LateralRepair) + "\n" +
			to_string(UI_Settings_MenuKey) + "\n" +
			to_string(UI_Settings_CustomMenuColor) + "\n" +
			to_string(UI_Settings_MenuColor.r) + "\n" +
			to_string(UI_Settings_MenuColor.g) + "\n" +
			to_string(UI_Settings_MenuColor.b) + "\n" +
			to_string(UI_Settings_MenuAlpha) + "\n" +
			to_string(UI_Misc_ShowDebugWindow) + "\n" +
			to_string(UI_Misc_WaterMark) + "\n" +
			to_string(UI_Visual_ESP_RenderSleep) + "\n" +
			to_string(UI_Misc_AutoClearDecals) + "\n" +
			to_string(UI_Visual_ESP_Health) + "\n" +
			to_string(UI_Visual_ESP_Snapline) + "\n" +
			to_string(UI_Visual_ESP_Skeleton) + "\n" +
			to_string(UI_Visual_Radar_Pos.x) + "\n" +
			to_string(UI_Visual_Radar_Pos.y) + "\n" +
			to_string(UI_Visual_Radar_Alpha) + "\n" +
			to_string(UI_Misc_LockGameWindow) + "\n" +
			to_string(UI_Legit_Aimbot_ShowRange) + "\n" +
			to_string(UI_Misc_AutoKnife) + "\n" +
			to_string(UI_Misc_AutoKnife_Key) + "\n" +
			to_string(UI_Misc_AutoTaser) + "\n" +
			to_string(UI_Misc_AutoTaser_Key) + "\n" +
			to_string(UI_Visual_ESP_ActiveWeapon) + "\n" +
			to_string(UI_Visual_ESP_Box) + "\n" +
			to_string(UI_Visual_ESP_CustomColor) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.r) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.g) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.b) + "\n" +
			to_string(UI_Visual_ESP_State) + "\n" +
			to_string(UI_Visual_ESP_Name) + "\n" +
			to_string(UI_Visual_ESP_OutFOV) + "\n" +
			to_string(UI_Visual_ESP_OutFOV_Radius) + "\n" +
			to_string(UI_Legit_Aimbot_AutoShoot_AutoStop) + "\n" +
			to_string(UI_Visual_ESP_OutFOV_Size) + "\n" +
			to_string(UI_Visual_ESP_Drops) + "\n" +
			to_string(UI_Legit_RemoveRecoil_StartBullet) + "\n" +
			to_string(UI_Visual_ESP_HeadDot) + "\n" +
			to_string(UI_Legit_Triggerbot_AnyTarget) + "\n" +
			to_string(UI_Misc_GlobalTeamCheck) + "\n"
		);
	}
	void Load_CloudConfig(string FileName) noexcept//加载Github云参数
	{
		System::URL_READ URL_CONFIG = { "Config" };
		if (URL_CONFIG.StoreMem("https://github.com/Coslly/Misc/raw/main/About%20FreeCS/" + FileName + (string)".cfg?raw=true"))
		{
			UI_Legit_Aimbot = Variable::string_int_(URL_CONFIG.Read(1));
			UI_Legit_Aimbot_Key = Variable::string_int_(URL_CONFIG.Read(2));
			UI_Legit_Aimbot_BodyAim = Variable::string_int_(URL_CONFIG.Read(3));
			UI_Legit_Aimbot_JudgingWall = Variable::string_int_(URL_CONFIG.Read(4));
			UI_Legit_Aimbot_TriggerOnAiming = Variable::string_int_(URL_CONFIG.Read(5));
			UI_Legit_Aimbot_RemoveRecoil = Variable::string_int_(URL_CONFIG.Read(6));
			UI_Legit_Aimbot_AutoShoot = Variable::string_int_(URL_CONFIG.Read(7));
			UI_Legit_Aimbot_AutoShoot_Interval = Variable::string_int_(URL_CONFIG.Read(8));
			UI_Legit_Aimbot_AdaptiveAimbot = Variable::string_int_(URL_CONFIG.Read(9));
			UI_Legit_Aimbot_A_Range_PISTOL = Variable::string_int_(URL_CONFIG.Read(10));
			UI_Legit_Aimbot_A_Smooth_PISTOL = Variable::string_float_(URL_CONFIG.Read(11));
			UI_Legit_Aimbot_A_Range_RIFLE = Variable::string_int_(URL_CONFIG.Read(12));
			UI_Legit_Aimbot_A_Smooth_RIFLE = Variable::string_float_(URL_CONFIG.Read(13));
			UI_Legit_Aimbot_A_Range_SNIPER = Variable::string_int_(URL_CONFIG.Read(14));
			UI_Legit_Aimbot_A_Smooth_SNIPER = Variable::string_float_(URL_CONFIG.Read(15));
			UI_Legit_Triggerbot = Variable::string_int_(URL_CONFIG.Read(16));
			UI_Legit_Triggerbot_Key = Variable::string_int_(URL_CONFIG.Read(17));
			UI_Legit_Triggerbot_ShootInterval = Variable::string_int_(URL_CONFIG.Read(18));
			UI_Legit_Triggerbot_ShootDuration = Variable::string_int_(URL_CONFIG.Read(19));
			UI_Legit_PreciseAim = Variable::string_int_(URL_CONFIG.Read(20));
			UI_Legit_PreciseAim_DefaultSensitivity = Variable::string_float_(URL_CONFIG.Read(21));
			UI_Legit_PreciseAim_EnableSensitivity = Variable::string_float_(URL_CONFIG.Read(22));
			UI_Legit_Backtracking = Variable::string_int_(URL_CONFIG.Read(23));
			UI_Legit_Backtracking_Time = Variable::string_int_(URL_CONFIG.Read(24));
			UI_Misc_BunnyHop = Variable::string_int_(URL_CONFIG.Read(25));
			UI_Visual_ESP = Variable::string_int_(URL_CONFIG.Read(26));
			UI_Visual_ESP_Key = Variable::string_int_(URL_CONFIG.Read(27));
			UI_Misc_HitSound = Variable::string_int_(URL_CONFIG.Read(28));
			UI_Misc_Sonar = Variable::string_int_(URL_CONFIG.Read(29));
			UI_Misc_Sonar_Key = Variable::string_int_(URL_CONFIG.Read(30));
			UI_Misc_Sonar_Range_Far = Variable::string_int_(URL_CONFIG.Read(31));
			UI_Misc_Sonar_Range_Near = Variable::string_int_(URL_CONFIG.Read(32));
			UI_Visual_Radar = Variable::string_int_(URL_CONFIG.Read(33));
			UI_Visual_Radar_FollowAngle = Variable::string_int_(URL_CONFIG.Read(34));
			UI_Visual_Radar_Range = Variable::string_float_(URL_CONFIG.Read(35));
			UI_Visual_Radar_Size = Variable::string_int_(URL_CONFIG.Read(36));
			UI_Legit_RemoveRecoil = Variable::string_int_(URL_CONFIG.Read(37));
			UI_Legit_RemoveRecoil_LateralRepair = Variable::string_int_(URL_CONFIG.Read(38));
			UI_Settings_MenuKey = Variable::string_int_(URL_CONFIG.Read(39));
			UI_Settings_CustomMenuColor = Variable::string_int_(URL_CONFIG.Read(40));
			UI_Settings_MenuColor = { Variable::string_int_(URL_CONFIG.Read(41)) ,Variable::string_int_(URL_CONFIG.Read(42)) ,Variable::string_int_(URL_CONFIG.Read(43)) };
			UI_Settings_MenuAlpha = Variable::string_int_(URL_CONFIG.Read(44));
			UI_Misc_ShowDebugWindow = Variable::string_int_(URL_CONFIG.Read(45));
			UI_Misc_WaterMark = Variable::string_int_(URL_CONFIG.Read(46));
			UI_Visual_ESP_RenderSleep = Variable::string_int_(URL_CONFIG.Read(47));
			UI_Misc_AutoClearDecals = Variable::string_int_(URL_CONFIG.Read(48));
			UI_Visual_ESP_Health = Variable::string_int_(URL_CONFIG.Read(49));
			UI_Visual_ESP_Snapline = Variable::string_int_(URL_CONFIG.Read(50));
			UI_Visual_ESP_Skeleton = Variable::string_int_(URL_CONFIG.Read(51));
			UI_Visual_Radar_Pos = { Variable::string_int_(URL_CONFIG.Read(52)) ,Variable::string_int_(URL_CONFIG.Read(53)) };
			UI_Visual_Radar_Alpha = Variable::string_int_(URL_CONFIG.Read(54));
			UI_Misc_LockGameWindow = Variable::string_int_(URL_CONFIG.Read(55));
			UI_Legit_Aimbot_ShowRange = Variable::string_int_(URL_CONFIG.Read(56));
			UI_Misc_AutoKnife = Variable::string_int_(URL_CONFIG.Read(57));
			UI_Misc_AutoKnife_Key = Variable::string_int_(URL_CONFIG.Read(58));
			UI_Misc_AutoTaser = Variable::string_int_(URL_CONFIG.Read(59));
			UI_Misc_AutoTaser_Key = Variable::string_int_(URL_CONFIG.Read(60));
			UI_Visual_ESP_ActiveWeapon = Variable::string_int_(URL_CONFIG.Read(61));
			UI_Visual_ESP_Box = Variable::string_int_(URL_CONFIG.Read(62));
			UI_Visual_ESP_CustomColor = Variable::string_int_(URL_CONFIG.Read(63));
			UI_Visual_ESP_CustomColor_Color = { Variable::string_int_(URL_CONFIG.Read(64)) ,Variable::string_int_(URL_CONFIG.Read(65)) ,Variable::string_int_(URL_CONFIG.Read(66)) };
			UI_Visual_ESP_State = Variable::string_int_(URL_CONFIG.Read(67));
			UI_Visual_ESP_Name = Variable::string_int_(URL_CONFIG.Read(68));
			UI_Visual_ESP_OutFOV = Variable::string_int_(URL_CONFIG.Read(69));
			UI_Visual_ESP_OutFOV_Radius = Variable::string_int_(URL_CONFIG.Read(70));
			UI_Legit_Aimbot_AutoShoot_AutoStop = Variable::string_int_(URL_CONFIG.Read(71));
			UI_Visual_ESP_OutFOV_Size = Variable::string_int_(URL_CONFIG.Read(72));
			UI_Visual_ESP_Drops = Variable::string_int_(URL_CONFIG.Read(73));
			UI_Legit_RemoveRecoil_StartBullet = Variable::string_int_(URL_CONFIG.Read(74));
			UI_Visual_ESP_HeadDot = Variable::string_int_(URL_CONFIG.Read(75));
			UI_Legit_Triggerbot_AnyTarget = Variable::string_int_(URL_CONFIG.Read(76));
			UI_Misc_GlobalTeamCheck = Variable::string_int_(URL_CONFIG.Read(77));
			URL_CONFIG.Release();
		}
	}
}
namespace CS2_SDK
{
	System::Memory CS_MEM = { "" };//初始化内存读写Class
	HWND Global_CS_HWND = 0;//全局CS窗口HWND
	BOOL Global_CS_Window_ShowState = 0;//全局CS窗口显示状态
	uintptr_t Global_Module_client = 0;//全局模块地址存储变量 client.dll
	vector<short> Global_Valid_ClassID = { 0 };//全局有效实体 PlayerID
	uintptr_t Global_LocalPlayer = 0;//全局SDK适用本地人物Pawn
	//----------------------------------------------------------------------------------
	namespace Offsets//CS2 偏移量: https://github.com/a2x/cs2-dumper.git
	{
		string Offsets_Date = "";
		//------------------------------------------------------------------------------
		uintptr_t dwLocalPlayer = 0;
		uintptr_t dwEntityList = 0;
		uintptr_t dwViewAngles = 0;
		uintptr_t dwViewMatrix = 0;
		//------------------------------------------------------------------------------
		uintptr_t m_hPlayerPawn = 0;//PlayerController -> PlayerPawn
		uintptr_t m_iIDEntIndex = 0;
		uintptr_t m_iTeamNum = 0;
		uintptr_t m_iHealth = 0;
		uintptr_t m_fFlags = 0;
		uintptr_t m_aimPunchCache = 0;
		uintptr_t m_vecViewOffset = 0;
		uintptr_t m_bSpotted = 0;//m_entitySpottedState + m_bSpotted  https://www.unknowncheats.me/forum/counter-strike-2-a/577666-tracing.html
		uintptr_t m_iShotsFired = 0;
		uintptr_t m_pClippingWeapon = 0;
		uintptr_t m_vOldOrigin = 0;
		uintptr_t m_bIsScoped = 0;
		uintptr_t m_vecVelocity = 0;
		uintptr_t m_ArmorValue = 0;
		uintptr_t m_iszPlayerName = 0;
		//------------------------------------------------------------------------------
		uintptr_t m_pGameSceneNode = 0;
		uintptr_t m_vecOrigin = 0;
		uintptr_t m_dwBoneMatrix = 0;//m_modelState + m_vecOrigin
		//------------------------------------------------------------------------------
	}
	using namespace Offsets;
	void Send_CMD(string Command_Str) noexcept//发送指令到CS控制台
	{
		COPYDATASTRUCT m_cData; m_cData.cbData = strlen(Command_Str.c_str()) + 1; m_cData.dwData = 0; m_cData.lpData = (void*)Command_Str.c_str();
		SendMessage(Global_CS_HWND, WM_COPYDATA, 0, (LPARAM)&m_cData);
		//-----------------------------------------------------------------------------------
		if (Command_Str == "+jump")System::Key_Click(VK_F13, true);//bind F13 "+jump;-jump";
		if (Command_Str == "+attack")mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		else if (Command_Str == "-attack")mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		if (Command_Str == "+attack2")mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		else if (Command_Str == "-attack2")mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		if (Command_Str == "playvol ui/xp_remaining.wav 1")Beep(150, 20);
		else if (Command_Str == "playvol buttons/button16.wav 1")Beep(300, 20);
		//Movement
		if (Command_Str == "+back")System::Key_Con(0x53, true, 31);//S
		else if (Command_Str == "-back")System::Key_Con(0x53, false, 31);
		if (Command_Str == "+forward")System::Key_Con(0x57, true, 17);//W
		else if (Command_Str == "-forward")System::Key_Con(0x57, false, 17);
		if (Command_Str == "+right")System::Key_Con(0x44, true, 32);//D
		else if (Command_Str == "-right")System::Key_Con(0x44, false, 32);
		if (Command_Str == "+left")System::Key_Con(0x41, true, 30);//A
		else if (Command_Str == "-left")System::Key_Con(0x41, false, 30);
	}
	int* Ang_Pos(int X, int Y, int Dis, float Ang, float Ang_) noexcept//角度距离转坐标
	{
		const float radian = ((Ang + Ang_) * 3.1415926535) / 180;
		int ReturnValue[2] = { X + Dis * sin(radian),Y + Dis * cos(radian) };
		return ReturnValue;
	}
	void Move_Mouse(int X, int Y) noexcept//更加安全的移动鼠标函数
	{
		const short to_ = 200;
		if (X >= to_)X = to_;
		else if (X <= -to_)X = -to_;
		if (Y >= to_)Y = to_;
		else if (Y <= -to_)Y = -to_;
		System::Mouse_Move(X, Y);
	}
	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	uintptr_t Convert(uintptr_t EntityList, uintptr_t Player) noexcept { return CS_MEM.Read<uintptr_t>(CS_MEM.Read<uintptr_t>(EntityList + 8 * ((Player & 0x7FFF) >> 9) + 16) + 120 * (Player & 0x1FF)); }//各种转换**
	uintptr_t LocalPlayer() noexcept { return CS_MEM.Read<uintptr_t>(Global_Module_client + dwLocalPlayer); }//本地人物
	uintptr_t EntityList() noexcept { return CS_MEM.Read<uintptr_t>(Global_Module_client + dwEntityList); }//实体列表
	short Health(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<short>(PlayerPawn + m_iHealth); }//人物血量
	short Armor(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<short>(PlayerPawn + m_ArmorValue); }//人物护甲
	short TeamNumber(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<short>(PlayerPawn + m_iTeamNum); }//人物队伍
	short IDEntIndex(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<short>(PlayerPawn + m_iIDEntIndex); }//人物瞄准的实体ID
	short ItemIndex(uintptr_t WeaponBase) noexcept { return CS_MEM.Read<short>(WeaponBase + 0x124A); }//实体ID转换Index
	short Flags(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<short>(PlayerPawn + m_fFlags); }//人物状态
	short ShotsFired(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<short>(PlayerPawn + m_iShotsFired); }//人物开枪子弹数量
	short Velocity_Speed(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { const auto Velocity = CS_MEM.Read<Variable::Vector3>(PlayerPawn + m_vecVelocity); return hypot(Velocity.x, Velocity.y); }//人物移动速度
	BOOL Spotted(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<BOOL>(PlayerPawn + m_bSpotted); }//人物发现状态
	BOOL Scoped(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<BOOL>(PlayerPawn + m_bIsScoped); }//人物狙击枪开镜
	uintptr_t ClippingWeapon(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<uintptr_t>(PlayerPawn + m_pClippingWeapon); }//人物手持武器 WeaponBase
	Variable::Vector3 AbsOrigin(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<Variable::Vector3>(CS_MEM.Read<uintptr_t>(PlayerPawn + m_pGameSceneNode) + m_vecOrigin); }//实体坐标
	Variable::Vector3 AimPunchAngle(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept//人物手持武器后坐力
	{
		struct UtlVec { DWORD64 count; DWORD64 data; }; const auto PunchCache = CS_MEM.Read<UtlVec>(PlayerPawn + m_aimPunchCache);
		if (PunchCache.count > 0 && PunchCache.count < 0xFFFF)return CS_MEM.Read<Variable::Vector3>(PunchCache.data + (PunchCache.count - 1) * sizeof(Variable::Vector3));
	}
	Variable::Vector3 Origin(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<Variable::Vector3>(PlayerPawn + m_vOldOrigin); }//人物坐标
	Variable::Vector3 ViewOffset(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<Variable::Vector3>(PlayerPawn + m_vecViewOffset); }//人物朝向偏移
	Variable::Vector3 ViewAngles(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<Variable::Vector3>(Global_Module_client + dwViewAngles); }//本地人物朝向
	Variable::Vector3 Velocity(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<Variable::Vector3>(PlayerPawn + m_vecVelocity); }//人物方向移动速度
	string PlayerName(uintptr_t PlayerController) noexcept { return CS_MEM.Read_str(PlayerController + m_iszPlayerName); }//人物控制器名称
	Variable::view_matrix_t ViewMatrix(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept { return CS_MEM.Read<Variable::view_matrix_t>(Global_Module_client + dwViewMatrix); }//本地人物视觉矩阵
	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	uintptr_t Traverse_Player(short i, BOOL ReturnPlayerController = false) noexcept//遍历人物Pawn
	{
		const auto Entitylist = EntityList();
		const auto PlayerController = Convert(Entitylist, i);
		if (ReturnPlayerController)return PlayerController;
		return Convert(Entitylist, CS_MEM.Read<uintptr_t>(PlayerController + m_hPlayerPawn));
	}
	string Player_Name(short i) noexcept//通过ClassID获取名称
	{
		const auto PlayerController = Convert(EntityList(), i);
		if (!PlayerController)return "None";
		else return CS_MEM.Read_str(PlayerController + m_iszPlayerName);
	}
	BOOL Check_Enemy(uintptr_t PlayerPawn) noexcept//判断人物是否是敌人
	{
		return (PlayerPawn != Global_LocalPlayer && Health(PlayerPawn) > 0 && (!FreeCS_Config_Variable::UI_Misc_GlobalTeamCheck || TeamNumber() != TeamNumber(PlayerPawn)) && Origin(PlayerPawn).x != 0);
	}
	Variable::Vector3 BonePos(uintptr_t PlayerPawn, short Bone_ID = 3) noexcept//通过骨骼矩阵获取骨骼坐标
	{
		const auto GameSceneNode = CS_MEM.Read<uintptr_t>(PlayerPawn + m_pGameSceneNode);
		const auto BoneMatrix = CS_MEM.Read<uintptr_t>(GameSceneNode + m_dwBoneMatrix);
		return CS_MEM.Read<Variable::Vector3>(BoneMatrix + Bone_ID * 0x20);
	}
	short Weapon_Type(uintptr_t WeaponBase) noexcept//武器类型 0:无效 1:手枪 2:连发枪 3:狙击枪
	{
		switch (ItemIndex(WeaponBase))
		{
		case 1: return 1;
		case 2: return 1;
		case 3: return 1;
		case 4: return 1;
		case 7: return 2;
		case 8: return 2;
		case 9: return 3;
		case 10: return 2;
		case 11: return 3;
		case 13: return 2;
		case 14: return 2;
		case 16: return 2;
		case 17: return 2;
		case 19: return 2;
		case 23: return 2;
		case 24: return 2;
		case 26: return 2;
		case 28: return 2;
		case 30: return 1;
		case 32: return 1;
		case 33: return 2;
		case 34: return 2;
		case 36: return 1;
		case 38: return 3;
		case 39: return 2;
		case 40: return 3;
		case 60: return 2;
		case 61: return 1;
		case 63: return 1;
		case 64: return 1;
		default: return 0;
		}
	}
	string Weapon_Name(uintptr_t WeaponBase) noexcept//武器名称
	{
		const auto Active_Weapon_ID_ = ItemIndex(WeaponBase);
		if (Active_Weapon_ID_ >= 500 && Active_Weapon_ID_ <= 600)return "KNIFE";
		switch (Active_Weapon_ID_)
		{
		case 1: return "DEAGLE";
		case 2: return "DUAL BERETTAS";
		case 3: return "FN57";
		case 4: return "GLOCK";
		case 7: return "AK47";
		case 8: return "AUG";
		case 9: return "AWP";
		case 10: return "FAMAS";
		case 11: return "G3SG1";
		case 13: return "GALILAR";
		case 14: return "M249";
		case 16: return "M4A1";
		case 17: return "MAC10";
		case 19: return "P90";
		case 23: return "MP5";
		case 24: return "UMP45";
		case 25: return "XM1014";
		case 26: return "BIZON";
		case 27: return "MAG7";
		case 28: return "NEGEV";
		case 29: return "SAWED";
		case 30: return "TEC9";
		case 31: return "TASER";
		case 32: return "P2000";
		case 33: return "MP7";
		case 34: return "MP9";
		case 35: return "NOVA";
		case 36: return "P250";
		case 38: return "SCAR20";
		case 39: return "SG553";
		case 40: return "SSG08";
		case 42: return "KNIFE";
		case 43: return "FLASH";
		case 44: return "GRENADE";
		case 45: return "SMOKE";
		case 46: return "MOLOTOV";
		case 47: return "DECOY";
		case 48: return "INCGRNNADE";
		case 49: return "C4";
		case 59: return "KNIFE";
		case 60: return "M4A1-S";
		case 61: return "USP-S";
		case 63: return "CZ75";
		case 64: return "REVOLVER";
		default: return "NONE";
		}
	}
	BOOL Stop_Move() noexcept//急停
	{
		const auto LocalVel = Velocity();
		if (hypot(LocalVel.x, LocalVel.y) <= 50)return true;//当精准度低了则返回真
		const auto LocalYaw = ViewAngles().y;
		const auto X = (LocalVel.x * cos(LocalYaw / 180 * 3.1415926) + LocalVel.y * sin(LocalYaw / 180 * 3.1415926));
		const auto Y = (LocalVel.y * cos(LocalYaw / 180 * 3.1415926) - LocalVel.x * sin(LocalYaw / 180 * 3.1415926));
		Send_CMD("-back"); Send_CMD("-forward"); Send_CMD("-right"); Send_CMD("-left");
		if (X > 30) { Send_CMD("+back"); Sleep(1); Send_CMD("-back"); }
		else if (X < -30) { Send_CMD("+forward"); Sleep(1); Send_CMD("-forward"); }
		if (Y > 30) { Send_CMD("+right"); Sleep(1); Send_CMD("-right"); }
		else if (Y < -30) { Send_CMD("+left"); Sleep(1); Send_CMD("-left"); }
		return false;
	}
	uintptr_t IDEntIndex_Pawn(uintptr_t PlayerPawn = Global_LocalPlayer) noexcept//瞄准实体的人物Pawn
	{
		const auto Index = IDEntIndex(PlayerPawn);
		if (Index <= 10000)return Convert(EntityList(), Index); else return 0;
	}
	void Valid_ClassID(vector<short>& Class_ID)//从全体人员中过滤掉无效实体
	{
		Class_ID = {};//刷新有效实体ID
		for (short i = 0; i <= 64; ++i)//最大人数64
		{
			const auto PlayerPawn = Traverse_Player(i);
			if (!Check_Enemy(PlayerPawn))//多点检测
				continue;
			Class_ID.push_back(i);
		}
	}
}
using namespace FreeCS_Config_Variable;
using namespace CS2_SDK;
//-----------------------------------------------------
void Thread_Menu() noexcept
{
	System::Log("Load Thread: Thread_Menu()");
	FreeCS_GUI.Window_Create(1010, 640, System::Rand_String(10), true);
	while (true)
	{
		static int UI_Panel = 0;//Panel
		static vector<int> WindowSize = { 0 ,0 };
		if (!FreeCS_GUI_ShowState)WindowSize = { 0 ,0 };
		FreeCS_GUI.Window_SetSize({ (int)Variable::Animation<class FreeCS_Menu_Animation_1>(WindowSize[0],3),(int)Variable::Animation<class FreeCS_Menu_Animation_2>(WindowSize[1],3) });//窗口大小动画
		if (!FreeCS_GUI.Window_Move() && FreeCS_GUI_ShowState)
		{
			if (!UI_Settings_CustomMenuColor)FreeCS_GUI.GUI_BackGround(1368);
			else FreeCS_GUI.GUI_BackGround(1369);
			FreeCS_GUI.GUI_Block_Panel(20, 20, 100, FreeCS_GUI.Window_GetSize().y - 40, "", { "Legit","Visual","Misc","Setting","Debug" }, UI_Panel);
			if (UI_Panel == 0)//Legit
			{
				const auto Block_Legit_Aimbot_ = FreeCS_GUI.GUI_Block(150, 30, 310, "Aim bot");
				FreeCS_GUI.GUI_Checkbox(Block_Legit_Aimbot_, 1, "Enabled", UI_Legit_Aimbot);
				FreeCS_GUI.GUI_KeySelector<class FreeCS_Menu_1>(Block_Legit_Aimbot_, 1, UI_Legit_Aimbot_Key);
				FreeCS_GUI.GUI_Checkbox({ Block_Legit_Aimbot_.x + 20,Block_Legit_Aimbot_.y }, 2, "Body aim (else head)", UI_Legit_Aimbot_BodyAim);
				FreeCS_GUI.GUI_Checkbox({ Block_Legit_Aimbot_.x + 20,Block_Legit_Aimbot_.y }, 3, "Judging wall", UI_Legit_Aimbot_JudgingWall);
				FreeCS_GUI.GUI_Checkbox({ Block_Legit_Aimbot_.x + 20,Block_Legit_Aimbot_.y }, 4, "Trigger on aiming", UI_Legit_Aimbot_TriggerOnAiming);
				FreeCS_GUI.GUI_Checkbox({ Block_Legit_Aimbot_.x + 20,Block_Legit_Aimbot_.y }, 5, "Remove recoil", UI_Legit_Aimbot_RemoveRecoil);
				FreeCS_GUI.GUI_Checkbox({ Block_Legit_Aimbot_.x + 20,Block_Legit_Aimbot_.y }, 6, "Auto shoot", UI_Legit_Aimbot_AutoShoot, { 255,150,150 });
				FreeCS_GUI.GUI_Checkbox({ Block_Legit_Aimbot_.x + 40,Block_Legit_Aimbot_.y }, 7, "Auto stop", UI_Legit_Aimbot_AutoShoot_AutoStop, { 255,150,150 });
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_2>({ Block_Legit_Aimbot_.x + 20,Block_Legit_Aimbot_.y }, 8, "Auto shoot delay", 0, 500, UI_Legit_Aimbot_AutoShoot_Interval, "ms", { 255, 150, 150 });
				FreeCS_GUI.GUI_Checkbox(Block_Legit_Aimbot_, 9, "Adaptive aimbot", UI_Legit_Aimbot_AdaptiveAimbot, { 200,200,150 });
				const auto Block_Legit_Aimbot_Armory_ = FreeCS_GUI.GUI_Block(150, 360, 250, "Armory");
				FreeCS_GUI.GUI_Checkbox(Block_Legit_Aimbot_Armory_, 1, "Show range", UI_Legit_Aimbot_ShowRange);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_3>({ Block_Legit_Aimbot_Armory_.x - 10,Block_Legit_Aimbot_Armory_.y }, 2, "PISTOL range", 0, 100, UI_Legit_Aimbot_A_Range_PISTOL, "%");
				FreeCS_GUI.GUI_Slider<float, class FreeCS_Menu_4>({ Block_Legit_Aimbot_Armory_.x - 10,Block_Legit_Aimbot_Armory_.y }, 3, "PISTOL smooth", 0, 40, UI_Legit_Aimbot_A_Smooth_PISTOL);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_5>({ Block_Legit_Aimbot_Armory_.x - 10,Block_Legit_Aimbot_Armory_.y }, 4, "RIFLE range", 0, 100, UI_Legit_Aimbot_A_Range_RIFLE, "%");
				FreeCS_GUI.GUI_Slider<float, class FreeCS_Menu_6>({ Block_Legit_Aimbot_Armory_.x - 10,Block_Legit_Aimbot_Armory_.y }, 5, "RIFLE smooth", 0, 40, UI_Legit_Aimbot_A_Smooth_RIFLE);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_7>({ Block_Legit_Aimbot_Armory_.x - 10,Block_Legit_Aimbot_Armory_.y }, 6, "SNIPER range", 0, 100, UI_Legit_Aimbot_A_Range_SNIPER, "%");
				FreeCS_GUI.GUI_Slider<float, class FreeCS_Menu_8>({ Block_Legit_Aimbot_Armory_.x - 10,Block_Legit_Aimbot_Armory_.y }, 7, "SNIPER smooth", 0, 40, UI_Legit_Aimbot_A_Smooth_SNIPER);
				const auto Block_Legit_Triggerbot_ = FreeCS_GUI.GUI_Block(580, 30, 160, "Trigger bot");
				FreeCS_GUI.GUI_Checkbox(Block_Legit_Triggerbot_, 1, "Enabled", UI_Legit_Triggerbot);
				FreeCS_GUI.GUI_KeySelector<class FreeCS_Menu_9>(Block_Legit_Triggerbot_, 1, UI_Legit_Triggerbot_Key);
				FreeCS_GUI.GUI_Checkbox({ Block_Legit_Triggerbot_.x + 20,Block_Legit_Triggerbot_.y }, 2, "Any target", UI_Legit_Triggerbot_AnyTarget);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_10>(Block_Legit_Triggerbot_, 3, "Shoot delay", 1, 500, UI_Legit_Triggerbot_ShootInterval, "ms");
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_11>(Block_Legit_Triggerbot_, 4, "Shoot duration", 1, 1000, UI_Legit_Triggerbot_ShootDuration, "ms");
				const auto Block_Legit_PreciseAim_ = FreeCS_GUI.GUI_Block(580, 210, 130, "Precise aim");
				FreeCS_GUI.GUI_Checkbox(Block_Legit_PreciseAim_, 1, "Enabled", UI_Legit_PreciseAim);
				FreeCS_GUI.GUI_Slider<float, class FreeCS_Menu_12>(Block_Legit_PreciseAim_, 2, "Default sensitivity", 0, 0.022, UI_Legit_PreciseAim_DefaultSensitivity);
				FreeCS_GUI.GUI_Slider<float, class FreeCS_Menu_13>(Block_Legit_PreciseAim_, 3, "Enable sensitivity", 0, 0.015, UI_Legit_PreciseAim_EnableSensitivity);
				const auto Block_Legit_RemoveRecoil_ = FreeCS_GUI.GUI_Block(580, 360, 130, "Remove recoil");
				FreeCS_GUI.GUI_Checkbox(Block_Legit_RemoveRecoil_, 1, "Enabled", UI_Legit_RemoveRecoil);
				FreeCS_GUI.GUI_Checkbox({ Block_Legit_RemoveRecoil_.x + 20,Block_Legit_RemoveRecoil_.y }, 2, "Lateral repair", UI_Legit_RemoveRecoil_LateralRepair);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_14>(Block_Legit_RemoveRecoil_, 3, "Start bullet", 1, 10, UI_Legit_RemoveRecoil_StartBullet);
				const auto Block_Legit_Backtracking_ = FreeCS_GUI.GUI_Block(580, 510, 100, "Back tracking");
				FreeCS_GUI.GUI_Checkbox(Block_Legit_Backtracking_, 1, "Enabled", UI_Legit_Backtracking);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_15>(Block_Legit_Backtracking_, 2, "Maximum time", 0, 500, UI_Legit_Backtracking_Time, "ms");
				FreeCS_GUI.GUI_Tips(Block_Legit_Aimbot_, 6, "Prefer Ragebot.", { 255,150,150 });
				FreeCS_GUI.GUI_Tips(Block_Legit_Aimbot_, 9, "More biological than normal aimbot.", { 200,200,150 });
				FreeCS_GUI.GUI_Tips(Block_Legit_Triggerbot_, 1, "Shoot when aiming at the enemy.");
				FreeCS_GUI.GUI_Tips(Block_Legit_PreciseAim_, 1, "Reduce the sensitivity of the reticle when aiming at the enemy.");
				FreeCS_GUI.GUI_Tips(Block_Legit_RemoveRecoil_, 2, "Operations that only return landscape.");
				WindowSize = { 1010,640 };
			}
			else if (UI_Panel == 1)//Visual
			{
				const auto Block_Misc_ESP_ = FreeCS_GUI.GUI_Block(150, 30, 490, "Extra sensory perception");
				FreeCS_GUI.GUI_Checkbox(Block_Misc_ESP_, 1, "Enabled", UI_Visual_ESP);
				FreeCS_GUI.GUI_KeySelector<class FreeCS_Menu_16>(Block_Misc_ESP_, 1, UI_Visual_ESP_Key);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 2, "Box", UI_Visual_ESP_Box);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 3, "Health bar", UI_Visual_ESP_Health);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 4, "Weapon text", UI_Visual_ESP_ActiveWeapon);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 5, "Snap line", UI_Visual_ESP_Snapline);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 6, "Skeleton", UI_Visual_ESP_Skeleton);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 7, "Head dot", UI_Visual_ESP_HeadDot);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 8, "State", UI_Visual_ESP_State);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 9, "Name", UI_Visual_ESP_Name);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 10, "Drops", UI_Visual_ESP_Drops);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 11, "Out of FOV arrow", UI_Visual_ESP_OutFOV);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_17>(Block_Misc_ESP_, 12, "Size", 20, 70, UI_Visual_ESP_OutFOV_Size, "px");
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_18>(Block_Misc_ESP_, 13, "Radius", 0, 100, UI_Visual_ESP_OutFOV_Radius, "%");
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_ESP_.x + 20,Block_Misc_ESP_.y }, 14, "Custom color", UI_Visual_ESP_CustomColor);
				FreeCS_GUI.GUI_ColorSelector(Block_Misc_ESP_, 14, UI_Visual_ESP_CustomColor_Color);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_19>(Block_Misc_ESP_, 15, "Draw delay", 1, 20, UI_Visual_ESP_RenderSleep, "ms");
				const auto Block_Misc_Resolution_ = FreeCS_GUI.GUI_Block(580, 30, 250, "Screen resolution");
				FreeCS_GUI.GUI_Button(Block_Misc_Resolution_, 1, "3840 * 2160", 78, UI_Visual_Res_3840);
				FreeCS_GUI.GUI_Button(Block_Misc_Resolution_, 2, "2560 * 1440", 78, UI_Visual_Res_2560);
				FreeCS_GUI.GUI_Button(Block_Misc_Resolution_, 3, "1920 * 1080", 78, UI_Visual_Res_1920);
				FreeCS_GUI.GUI_Button(Block_Misc_Resolution_, 4, "1440 * 1080", 78, UI_Visual_Res_1440);
				FreeCS_GUI.GUI_Button(Block_Misc_Resolution_, 5, "1280 * 1024", 78, UI_Visual_Res_1280);
				FreeCS_GUI.GUI_Button(Block_Misc_Resolution_, 6, "1280 * 960", 83, UI_Visual_Res_960);
				FreeCS_GUI.GUI_Button(Block_Misc_Resolution_, 7, "800 * 600", 87, UI_Visual_Res_800);
				const auto Block_Misc_Radar_ = FreeCS_GUI.GUI_Block(580, 300, 190, "Radar");
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Radar_, 1, "Enabled", UI_Visual_Radar);
				FreeCS_GUI.GUI_Checkbox({ Block_Misc_Radar_.x + 20,Block_Misc_Radar_.y }, 2, "Follow angle", UI_Visual_Radar_FollowAngle);
				FreeCS_GUI.GUI_Slider<float, class FreeCS_Menu_20>(Block_Misc_Radar_, 3, "Radar range", 0.2, 25, UI_Visual_Radar_Range);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_21>(Block_Misc_Radar_, 4, "Radar size", 150, 500, UI_Visual_Radar_Size, "px");
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_22>(Block_Misc_Radar_, 5, "Radar alpha", 100, 230, UI_Visual_Radar_Alpha);
				FreeCS_GUI.GUI_Tips(Block_Misc_ESP_, 1, "Learn enemy coordinates through walls. (ESP Full screen cannot be used)");
				FreeCS_GUI.GUI_Tips({ Block_Misc_Resolution_.x + 10,Block_Misc_Resolution_.y }, 1, "Flexible switching of window resolution.");
				FreeCS_GUI.GUI_Tips(Block_Misc_Radar_, 1, "Exterior window radar. (Full screen cannot be used)");
				WindowSize = { 1010,550 };
			}
			else if (UI_Panel == 2)//Misc
			{
				const auto Block_Misc_Misc_ = FreeCS_GUI.GUI_Block(150, 30, 310, "Misc");
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 1, "Bunny hop", UI_Misc_BunnyHop);
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 2, "Hit sound", UI_Misc_HitSound);
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 3, "Auto clear decals", UI_Misc_AutoClearDecals);
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 4, "Knife bot", UI_Misc_AutoKnife);
				FreeCS_GUI.GUI_KeySelector<class FreeCS_Menu_23>(Block_Misc_Misc_, 4, UI_Misc_AutoKnife_Key);
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 5, "Taser bot", UI_Misc_AutoTaser);
				FreeCS_GUI.GUI_KeySelector<class FreeCS_Menu_24>(Block_Misc_Misc_, 5, UI_Misc_AutoTaser_Key);
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 6, "Watermark", UI_Misc_WaterMark);
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 7, "Global team check", UI_Misc_GlobalTeamCheck);
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 8, "Lock game window", UI_Misc_LockGameWindow);
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Misc_, 9, "Show console window", UI_Misc_ShowDebugWindow);
				static BOOL Clear_Console = false; FreeCS_GUI.GUI_Button_Small(Block_Misc_Misc_, 9, Clear_Console);
				if (Clear_Console)system("cls");//Clear Console Text
				const auto Block_Misc_Sonar_ = FreeCS_GUI.GUI_Block(580, 150, 130, "Sonar");
				FreeCS_GUI.GUI_Checkbox(Block_Misc_Sonar_, 1, "Enabled", UI_Misc_Sonar);
				FreeCS_GUI.GUI_KeySelector<class FreeCS_Menu_25>(Block_Misc_Sonar_, 1, UI_Misc_Sonar_Key);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_26>(Block_Misc_Sonar_, 2, "Range far", 500, 1000, UI_Misc_Sonar_Range_Far);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_27>(Block_Misc_Sonar_, 3, "Range near", 0, 500, UI_Misc_Sonar_Range_Near);
				const auto Block_Misc_CloudConfig_ = FreeCS_GUI.GUI_Block(580, 30, 100, "Cloud config");
				FreeCS_GUI.GUI_Button(Block_Misc_CloudConfig_, 1, "Legit", 20, UI_Misc_CloudConfig_Legit);
				FreeCS_GUI.GUI_Button(Block_Misc_CloudConfig_, 2, "Rage", 20, UI_Misc_CloudConfig_Rage);
				FreeCS_GUI.GUI_Tips(Block_Misc_Misc_, 4, "Auto attack when conditions such as distance and blood volume are met.");
				FreeCS_GUI.GUI_Tips(Block_Misc_Misc_, 8, "Lock the game window to the front.");
				FreeCS_GUI.GUI_Tips({ Block_Misc_Misc_.x + 3,Block_Misc_Misc_.y }, 9, "Clear console.");
				FreeCS_GUI.GUI_Tips(Block_Misc_Sonar_, 1, "Makes a subtle sound when approaching an enemy.");
				FreeCS_GUI.GUI_Tips({ Block_Misc_CloudConfig_.x + 10,Block_Misc_CloudConfig_.y }, 1, "Load parameter files stored in Github.");
				WindowSize = { 1010,370 };
			}
			else if (UI_Panel == 3)//Settings
			{
				const auto Block_Settings_About_ = FreeCS_GUI.GUI_Block(150, 30, 100, "About");
				FreeCS_GUI.GUI_Text(Block_Settings_About_, 1, "FreeCS", FreeCS_GUI.Global_Get_EasyGUI_Color());
				FreeCS_GUI.GUI_Text(Block_Settings_About_, 1, "            for CS2 (External)", { 100,100,100 });
				FreeCS_GUI.GUI_Text(Block_Settings_About_, 2, "Release date: " + FreeCS_ReleaseDate, { 100,100,100 });
				const auto Block_Settings_Menu_ = FreeCS_GUI.GUI_Block(150, 150, 340, "Menu");
				FreeCS_GUI.GUI_Text(Block_Settings_Menu_, 1, "Menu key");
				FreeCS_GUI.GUI_KeySelector<class FreeCS_Menu_28>(Block_Settings_Menu_, 1, UI_Settings_MenuKey);
				FreeCS_GUI.GUI_Checkbox(Block_Settings_Menu_, 2, "Menu color", UI_Settings_CustomMenuColor);
				FreeCS_GUI.GUI_ColorSelector(Block_Settings_Menu_, 2, UI_Settings_MenuColor);
				FreeCS_GUI.GUI_Slider<int, class FreeCS_Menu_29>(Block_Settings_Menu_, 3, "Menu alpha", 150, 255, UI_Settings_MenuAlpha);
				FreeCS_GUI.GUI_Button(Block_Settings_Menu_, 4, "Save local config", 65, UI_Settings_SaveConfig);
				if (Global_CS_HWND)FreeCS_GUI.GUI_Button(Block_Settings_Menu_, 5, "Restart CS", 81, UI_Settings_RestartCS);
				else FreeCS_GUI.GUI_Button(Block_Settings_Menu_, 5, "Start CS", 85, UI_Settings_RestartCS);
				FreeCS_GUI.GUI_Button(Block_Settings_Menu_, 6, "Quit CS", 90, UI_Settings_QuitCS);
				FreeCS_GUI.GUI_Button(Block_Settings_Menu_, 7, "SendCommand to CS", 55, UI_Settings_SendCommand);
				FreeCS_GUI.GUI_Button(Block_Settings_Menu_, 8, "SendTestCommand to CS", 40, UI_Settings_SendTestCommand);
				FreeCS_GUI.GUI_Button(Block_Settings_Menu_, 9, "Restart FreeCS", 70, UI_Settings_RestartFreeCS);
				FreeCS_GUI.GUI_Button(Block_Settings_Menu_, 10, "Close", 100, UI_Settings_CloseFreeCS);
				FreeCS_GUI.GUI_Tips({ Block_Settings_About_.x + 10,Block_Settings_About_.y }, 1, "No ban record so far in 2020.", { 150,255,150 });
				FreeCS_GUI.GUI_Tips({ Block_Settings_Menu_.x + 10,Block_Settings_Menu_.y }, 4, "If you want to reset the default config you can delete FreeCS.cfg in the same folder.");
				FreeCS_GUI.GUI_Tips({ Block_Settings_Menu_.x + 10,Block_Settings_Menu_.y }, 7, "Set your personal parameters.");
				WindowSize = { 580,520 };
			}
			else if (UI_Panel == 4)//Debug 测试版块
			{
				const auto Block_Debug_List_ = FreeCS_GUI.GUI_Block(150, 30, 660, "Data list");
				static BOOL UI_Debug_Datalist = false;
				FreeCS_GUI.GUI_Checkbox(Block_Debug_List_, 1, "Enabled list", UI_Debug_Datalist);
				if (UI_Debug_Datalist)
				{
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 2, "Cloud offsets date: [" + Offsets_Date + "]");
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 3, "client.dll -> " + to_string(Global_Module_client));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 4, "--------------------------------------------------------------");
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 5, "LocalPlayer -> " + to_string(Global_LocalPlayer));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 6, "LocalPlayer Health: " + to_string(Health()));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 7, "LocalPlayer Armor: " + to_string(Armor()));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 8, "LocalPlayer TeamNum: " + to_string(TeamNumber()));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 9, "LocalPlayer Flags: " + to_string(Flags()));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 10, "LocalPlayer IDEntIndex: " + to_string(IDEntIndex()));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 11, "LocalPlayer Activeweapon: " + Weapon_Name(ClippingWeapon()) + " (" + to_string(ItemIndex(ClippingWeapon())) + ")");
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 12, "LocalPlayer Speed: " + to_string(Velocity_Speed()));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 13, "LocalPlayer Origin: [" + Variable::Float_Precision((Origin().x)) + ", " + Variable::Float_Precision(Origin().y) + ", " + Variable::Float_Precision(Origin().z) + "]");
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 14, "LocalPlayer ViewAngles: [" + Variable::Float_Precision(ViewAngles().x) + ", " + Variable::Float_Precision(ViewAngles().y) + ", " + Variable::Float_Precision(ViewAngles().z) + "]");
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 15, "--------------------------------------------------------------");
					static auto Player_ID = 0;
					FreeCS_GUI.GUI_Slider<int, class Debug_Menu_Player_ID_Test_S__>(Block_Debug_List_, 16, "PlayerID", 0, 64, Player_ID);
					const auto Player_Address = Traverse_Player(Player_ID);
					auto Player_Color = Variable::Vector4{ 200,200,200 };
					if (Check_Enemy(Player_Address))Player_Color = { 255,255,150 };//敌人颜色
					else if (Global_LocalPlayer == Player_Address)Player_Color = { 150,255,255 };//本地人物颜色
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 17, "Player -> " + to_string(Player_Address), Player_Color);
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 18, "Player Name: " + Player_Name(Player_ID));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 19, "Player Health: " + to_string(Health(Player_Address)));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 20, "Player TeamNum: " + to_string(TeamNumber(Player_Address)));
					FreeCS_GUI.GUI_Text(Block_Debug_List_, 21, "Player Origin: [" + Variable::Float_Precision((Origin(Player_Address).x)) + ", " + Variable::Float_Precision(Origin(Player_Address).y) + ", " + Variable::Float_Precision(Origin(Player_Address).z) + "]");
				}
				FreeCS_GUI.GUI_Tips(Block_Debug_List_, 1, "May take up higher performance.", { 255,150,150 });
				WindowSize = { 580,720 };
			}
			FreeCS_GUI.Draw_GUI();//最终绘制GUI
		}
	}
}
void Thread_Misc() noexcept
{
	System::Log("Load Thread: Thread_Misc()");
	Window::Windows Window_Watermark; const auto Window_Watermark_HWND = Window_Watermark.Create_RenderBlock_Alpha(Window::Get_Resolution().x, 30, System::Rand_String(11));//创建水印透明窗口
	Window::Render Window_Watermark_Render; Window_Watermark_Render.CreatePaint(Window_Watermark_HWND, 0, 0, Window::Get_Resolution().x, 30);
	while (true)
	{
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (System::Sleep_Tick<class Thread_Misc_UpdateOffsets>(4000))//刷新偏移量和本地人物地址
		{
			CS_MEM = { "cs2.exe" };//刷新内存Class
			Global_CS_HWND = CS_MEM.Get_ProcessHWND(); Global_Module_client = CS_MEM.Get_Module("client.dll");//刷新CSHWND和client.dll模块
			Global_LocalPlayer = LocalPlayer();//用刷新的模块获取本地人物Pawn
			if (Global_CS_Window_ShowState && UI_Misc_AutoClearDecals)Send_CMD("r_cleardecals");//清除血迹
			System::URL_READ URL_OFFSETS = { "Offsets" };
			if (URL_OFFSETS.StoreMem("https://github.com/Coslly/Misc/raw/main/About%20FreeCS/Offsets.ofs?raw=true"))//自动更新偏移量 Github更新有十分钟延迟
			{
				Offsets_Date = URL_OFFSETS.Read(1); Offsets_Date.erase(0,2);//删除注释符号
				dwLocalPlayer = Variable::string_uint_(URL_OFFSETS.Read(4));
				dwEntityList = Variable::string_uint_(URL_OFFSETS.Read(6));
				dwViewAngles = Variable::string_uint_(URL_OFFSETS.Read(8));
				dwViewMatrix = Variable::string_uint_(URL_OFFSETS.Read(10));
				m_hPlayerPawn = Variable::string_uint_(URL_OFFSETS.Read(12));
				m_iIDEntIndex = Variable::string_uint_(URL_OFFSETS.Read(14));
				m_iTeamNum = Variable::string_uint_(URL_OFFSETS.Read(16));
				m_iHealth = Variable::string_uint_(URL_OFFSETS.Read(18));
				m_fFlags = Variable::string_uint_(URL_OFFSETS.Read(20));
				m_aimPunchCache = Variable::string_uint_(URL_OFFSETS.Read(22));
				m_vecViewOffset = Variable::string_uint_(URL_OFFSETS.Read(24));
				m_bSpotted = Variable::string_uint_(URL_OFFSETS.Read(26));
				m_iShotsFired = Variable::string_uint_(URL_OFFSETS.Read(28));
				m_pClippingWeapon = Variable::string_uint_(URL_OFFSETS.Read(30));
				m_vOldOrigin = Variable::string_uint_(URL_OFFSETS.Read(32));
				m_bIsScoped = Variable::string_uint_(URL_OFFSETS.Read(34));
				m_vecVelocity = Variable::string_uint_(URL_OFFSETS.Read(36));
				m_ArmorValue = Variable::string_uint_(URL_OFFSETS.Read(38));
				m_iszPlayerName = Variable::string_uint_(URL_OFFSETS.Read(40));
				m_pGameSceneNode = Variable::string_uint_(URL_OFFSETS.Read(42));
				m_vecOrigin = Variable::string_uint_(URL_OFFSETS.Read(44));
				m_dwBoneMatrix = Variable::string_uint_(URL_OFFSETS.Read(46));
				URL_OFFSETS.Release();
			}
		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (UI_Misc_WaterMark)//水印
		{
			Window_Watermark.Set_WindowPos(0, 0);
			if (System::Sleep_Tick<class WaterMark_Window_Sleep_Class_>(200))//降低CPU占用
			{
				static string WaterMark_String = "";
				short WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 4.8;
				if (!Global_CS_HWND)WaterMark_String = "FreeCS | CS not found | " + System::Time_String();
				else { WaterMark_String = "FreeCS | " + System::Time_String(); WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 5.2; }
				const Variable::Vector2 Watermark_Pos = { Window::Get_Resolution().x - WaterMark_String_Size - 10,10 };
				Window_Watermark_Render.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });
				Window_Watermark_Render.RenderA_SolidRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size, 14, { 1,1,1,150 });
				if (UI_Settings_CustomMenuColor)
				{
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size / 2, 1, FreeCS_GUI_IO.GUIColor / 2, FreeCS_GUI_IO.GUIColor);
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x + WaterMark_String_Size / 2, Watermark_Pos.y, WaterMark_String_Size / 2 + 1, 1, FreeCS_GUI_IO.GUIColor, FreeCS_GUI_IO.GUIColor / 2);
				}
				else {
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size / 2, 1, { FreeCS_GUI_IO.GUIColor_Rainbow[0], FreeCS_GUI_IO.GUIColor_Rainbow[1], FreeCS_GUI_IO.GUIColor_Rainbow[2],255 }, { FreeCS_GUI_IO.GUIColor_Rainbow[3], FreeCS_GUI_IO.GUIColor_Rainbow[4], FreeCS_GUI_IO.GUIColor_Rainbow[5],255 });
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x + WaterMark_String_Size / 2, Watermark_Pos.y, WaterMark_String_Size / 2 + 1, 1, { FreeCS_GUI_IO.GUIColor_Rainbow[3], FreeCS_GUI_IO.GUIColor_Rainbow[4], FreeCS_GUI_IO.GUIColor_Rainbow[5],255 }, { FreeCS_GUI_IO.GUIColor_Rainbow[6], FreeCS_GUI_IO.GUIColor_Rainbow[7], FreeCS_GUI_IO.GUIColor_Rainbow[8],255 });
				}
				Window_Watermark_Render.Render_String(Watermark_Pos.x + 3, Watermark_Pos.y + 1, WaterMark_String, "Small Fonts", 12, { 255,255,255 }, false);
				Window_Watermark_Render.DrawPaint(true);
			}
		}
		else Window_Watermark.Set_WindowPos(9999, 9999);
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (UI_Visual_Res_3840)Window::Set_Resolution(3840, 2160);
		else if (UI_Visual_Res_2560)Window::Set_Resolution(2560, 1440);
		else if (UI_Visual_Res_1920)Window::Set_Resolution(1920, 1080);
		else if (UI_Visual_Res_1440)Window::Set_Resolution(1440, 1080);
		else if (UI_Visual_Res_1280)Window::Set_Resolution(1280, 1024);
		else if (UI_Visual_Res_960)Window::Set_Resolution(1280, 960);
		else if (UI_Visual_Res_800)Window::Set_Resolution(800, 600);
		if (UI_Settings_SaveConfig)//保存本地参数
		{
			Save_LocalConfig();
			System::Log("Settings: SaveConfig");
		}
		if (UI_Settings_RestartCS)
		{
			Send_CMD("quit");//强力退出CS
			System::Open_Website("steam://rungameid/730");//启动CS
			System::Log("Settings: RestartCS");
		}
		if (UI_Settings_QuitCS)
		{
			Send_CMD("quit");//强力退出CS
			System::Log("Settings: QuitCS");
		}
		if (UI_Settings_SendCommand)//发送私人设置到CS控制台
		{
			Send_CMD("sv_cheats 1");//开启作弊
			Send_CMD("fps_max 0");//关闭帧数限制
			Send_CMD("cl_radar_scale 0.4");//地图缩放
			Send_CMD("cl_hud_radar_scale 1.15");//地图大小
			Send_CMD("cl_radar_always_centered 1");//人物为中心
			Send_CMD("cl_radar_rotate 1");//人物视角为中心旋转的地图
			Send_CMD("cl_radar_icon_scale_min 0.4");//小地图人物提示大小(小点点)
			Send_CMD("cl_radar_square_with_scoreboard 0");//地图为圆形
			//Send_CMD("net_graph 1");//显示fps loss ping
			//Send_CMD("net_graphproportionalfont 0.5");//fps loss ping 大小为0.5
			//Send_CMD("cl_bob_lower_amt 5");//手臂晃动
			Send_CMD("hud_scaling 0.7");//hud大小
			Send_CMD("sensitivity 1.5");//鼠标灵敏度设置为1.5
			Send_CMD("zoom_sensitivity_ratio 0.63"); //开镜鼠标灵敏度设置为0.63
			Send_CMD("m_yaw 0.015");//4比3模式横向灵敏度 默认0.022
			Send_CMD("m_pitch 0.022");//默认垂直灵敏度
			Send_CMD("cl_crosshairalpha 255;cl_crosshaircolor 2;cl_crosshairdot 0;cl_crosshair_t 0;cl_crosshairgap  -3;cl_crosshairsize 2;cl_crosshairstyle 4;cl_crosshairthickness 1;cl_crosshair_outlinethickness 0;cl_crosshair_drawoutline 0;");//准星
			/*
			sv_cheats 1; fps_max 0; cl_radar_scale 0.4; cl_hud_radar_scale 1.15; cl_radar_always_centered 1; cl_radar_rotate 1; cl_radar_icon_scale_min 0.4; cl_radar_square_with_scoreboard 0; hud_scaling 0.7; sensitivity 1.5; zoom_sensitivity_ratio 0.63;m_yaw 0.015; m_pitch 0.022;
			cl_crosshairalpha 255; cl_crosshaircolor 2; cl_crosshairdot 0; cl_crosshair_t 0; cl_crosshairgap - 3; cl_crosshairsize 2; cl_crosshairstyle 4; cl_crosshairthickness 1; cl_crosshair_outlinethickness 0; cl_crosshair_drawoutline 0;
			*/
			System::Log("Settings: SendCommand");
		}
		if (UI_Settings_SendTestCommand)//发送测试服务器指令到CS控制台
		{
			Send_CMD("sv_cheats 1");//开启作弊
			Send_CMD("sv_infinite_ammo 1");//无限弹药
			Send_CMD("mp_roundtime_defuse 60");//回合时间60分钟
			Send_CMD("bot_stop 1");//机器人静止
			Send_CMD("mp_buy_anywhere 1");//任何地方购买武器装备
			Send_CMD("mp_buytime 99999");//超长购买时间
			Send_CMD("mp_startmoney 16000");//回合初始金钱
			Send_CMD("god");//无敌
			Send_CMD("sv_showimpacts 1");//弹点显示
			Send_CMD("sv_showimpacts_time 15");//弹点显示时间
			Send_CMD("mp_humanteam any");//可选任何队伍
			Send_CMD("mp_restartgame 1");//重开比赛
			System::Log("Settings: SendTestCommand");
		}
		if (UI_Settings_RestartFreeCS)System::Self_Restart();
		if (UI_Settings_CloseFreeCS) { Window::NVIDIA_Overlay(); exit(0); }
		if (UI_Misc_ShowDebugWindow)ShowWindow(GetConsoleWindow(), true);//显示控制台
		else ShowWindow(GetConsoleWindow(), false);//隐藏控制台
		if (UI_Misc_CloudConfig_Legit)Load_CloudConfig("Legit");//套用Github云参数
		else if (UI_Misc_CloudConfig_Rage)Load_CloudConfig("Rage");
		if (UI_Misc_LockGameWindow && !FreeCS_GUI_ShowState)SetForegroundWindow(Global_CS_HWND);//锁定CS窗口到最前端
		Global_CS_Window_ShowState = Global_CS_HWND && Window::Get_WindowEnable(Global_CS_HWND);//刷新CS窗口前后位置数据
		FreeCS_GUI_IO = FreeCS_GUI.Get_IO();//刷新GUI状态数据
		if (!UI_Settings_CustomMenuColor)FreeCS_GUI_IO.GUIColor = { FreeCS_GUI_IO.GUIColor_Rainbow[3],FreeCS_GUI_IO.GUIColor_Rainbow[4],FreeCS_GUI_IO.GUIColor_Rainbow[5] };//GUI主题颜色到功能函数
		if (System::Sleep_Tick<class Thread_Misc_UpdateOffsets_Valid_ClassID>(500))Valid_ClassID(Global_Valid_ClassID);//更新全局有效的实体ClassID
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (Global_CS_Window_ShowState && Health())//一些杂项功能
		{
			const auto Local_Pos = Origin();//本地人物坐标
			const auto Local_ActiveWeaponID = ItemIndex(ClippingWeapon());//本地人物手持武器ID
			//--------------------------------------
			/*
			if (UI_Misc_HitSound)//击打音效
			{
				static auto OldDamage = 0; static auto OldKill = 0;
				const auto Damage = CS_MEM.Read<int32_t>(Global_LocalPlayer + NULL);//伤害
				const auto Kill = CS_MEM.Read<int32_t>(Global_LocalPlayer + NULL);//击杀
				if (Health() && (Damage > OldDamage || Damage < OldDamage))//当伤害或是击杀值变化则返回
				{
					if (Kill > OldKill)Send_CMD("playvol buttons/arena_switch_press_02.wav 1");//Kill
					else if (Damage > OldDamage)Send_CMD("playvol buttons/arena_switch_press_02.wav 1");//Hit
					OldDamage = Damage; OldKill = Kill;
				}
			}
			*/
			//--------------------------------------
			if (UI_Misc_BunnyHop && System::Get_Key(VK_SPACE) && Flags() & (1 << 0))//连跳
			{
				Send_CMD("+jump");//跳跃...
				Sleep(1);
				Send_CMD("-jump");
			}
			//--------------------------------------
			if (UI_Legit_RemoveRecoil)//移除后坐力
			{
				static auto OldPunch = Variable::Vector3{};
				if (System::Get_Key(VK_LBUTTON) && ShotsFired() >= UI_Legit_RemoveRecoil_StartBullet)//判断开出的子弹数
				{
					const auto AimPunch = AimPunchAngle();//RecoilAngle
					const auto NewPunch = Variable::Vector3{ OldPunch.x - AimPunch.x * 2,OldPunch.y - AimPunch.y * 2,0 };
					if (UI_Legit_RemoveRecoil_LateralRepair)System::Mouse_Move(-NewPunch.y * 40, 0);//只处理X坐标
					else System::Mouse_Move(-NewPunch.y * 40, NewPunch.x * 28);//X,Y
					OldPunch.x = AimPunch.x * 2;
					OldPunch.y = AimPunch.y * 2;
				}
				else OldPunch.x = OldPunch.y = 0;
			}
			//--------------------------------------
			if (UI_Misc_AutoKnife && (UI_Misc_AutoKnife_Key == 0 || System::Get_Key(UI_Misc_AutoKnife_Key)) && (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500))//自动刀
			{
				for (short i = 0; i < Global_Valid_ClassID.size(); ++i)
				{
					const auto PlayerPawn = Traverse_Player(Global_Valid_ClassID[i]);
					if (!Check_Enemy(PlayerPawn))//多点检测
						continue;
					const auto Player_Pos = Origin(PlayerPawn);//敌人坐标
					const auto Angle = Variable::CalculateAngle(Local_Pos + ViewOffset(), BonePos(PlayerPawn, 3), ViewAngles());
					if (Variable::Coor_Dis_3D(Local_Pos, Player_Pos) <= 60 && hypot(Angle.x, Angle.y) <= 50)//判断距离
					{
						if (Health(PlayerPawn) <= 55 && Health(PlayerPawn) > 30)//血量判断重刀还是轻刀
						{
							Send_CMD("+attack2");
							Sleep(1);
							Send_CMD("-attack2");
						}
						else {
							Send_CMD("+attack");
							Sleep(1);
							Send_CMD("-attack");
						}
					}
				}
			}
			//--------------------------------------
			if (UI_Misc_AutoTaser && (UI_Misc_AutoTaser_Key == 0 || System::Get_Key(UI_Misc_AutoTaser_Key)) && Local_ActiveWeaponID == 31)//自动电击枪
			{
				for (short i = 0; i < Global_Valid_ClassID.size(); ++i)
				{
					const auto PlayerPawn = Traverse_Player(Global_Valid_ClassID[i]);
					if (!Check_Enemy(PlayerPawn))//多点检测
						continue;
					const auto Player_Pos = Origin(PlayerPawn);//敌人坐标
					if (Variable::Coor_Dis_3D(Local_Pos, Player_Pos) <= 150 && PlayerPawn == IDEntIndex_Pawn())//判断距离 && 瞄准
					{
						Send_CMD("+attack");
						Sleep(1);
						Send_CMD("-attack");
					}
				}
			}
			//--------------------------------------
		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (FreeCS_GUI_ShowState)Sleep(3);
		else Sleep(10);
	}
}
void Thread_Funtion_Aimbot() noexcept
{
	System::Log("Load Thread: Thread_Funtion_Aimbot()");
	while (true)
	{
		System::Sleep_ns(600);//比Sleep更快的函数为了更加自然平滑
		if (Global_CS_Window_ShowState && UI_Legit_Aimbot && System::Get_Key(UI_Legit_Aimbot_Key) && Health())//当CS窗口在最前端 && 本地人物活着 && 按键按下
		{
			static short Aim_Range, Aim_Parts;//瞄准范围,瞄准部位
			static float Aim_Smooth;//瞄准平滑度
			static Variable::Vector3 Recoil_Angle;//后坐力角度
			const auto Local_ActiveWeaponID = ItemIndex(ClippingWeapon());//本地人物手持武器ID
			const auto Local_ActiveWeaponType = Weapon_Type(ClippingWeapon());//本地人物手持武器类型
			if (Local_ActiveWeaponType == 1)//PISTOL 手枪
			{
				Aim_Range = UI_Legit_Aimbot_A_Range_PISTOL / 5;
				Aim_Smooth = 40 - UI_Legit_Aimbot_A_Smooth_PISTOL;
			}
			else if (Local_ActiveWeaponType == 2)//RIFLE 步枪
			{
				Aim_Range = UI_Legit_Aimbot_A_Range_RIFLE / 5;
				Aim_Smooth = 40 - UI_Legit_Aimbot_A_Smooth_RIFLE;
			}
			else if (Local_ActiveWeaponType == 3)//SNIPER 狙击枪
			{
				Aim_Range = UI_Legit_Aimbot_A_Range_SNIPER / 5;
				Aim_Smooth = 40 - UI_Legit_Aimbot_A_Smooth_SNIPER;
			}
			else continue;//如果是无效的武器则重新来过(刀,道具,电击枪等)
			if (Aim_Range == 0)continue;//范围为0时则重新来过
			if (Aim_Smooth == 0)Aim_Smooth = 1;//最小平滑度
			if (UI_Legit_Aimbot_BodyAim)Aim_Parts = 3;//瞄准部位 6:头 3:身体
			else Aim_Parts = 6;
			const auto Aim_Punch_Angle_ = AimPunchAngle();
			Aim_Range = Aim_Range + -Aim_Punch_Angle_.x;
			if (UI_Legit_Aimbot_RemoveRecoil)Recoil_Angle = ViewAngles() + Aim_Punch_Angle_ * 2;//移除后坐力
			else Recoil_Angle = ViewAngles();
			const auto CrosshairId = Check_Enemy(IDEntIndex_Pawn());//瞄准的实体Pawn
			for (short i = 0; i < Global_Valid_ClassID.size(); ++i)
			{
				const auto PlayerPawn = Traverse_Player(Global_Valid_ClassID[i]);
				if (!Check_Enemy(PlayerPawn) || (UI_Legit_Aimbot_TriggerOnAiming && !CrosshairId) || (UI_Legit_Aimbot_JudgingWall && !Spotted(PlayerPawn)))//TriggerOnAiming & JudgingWall
					continue;
				const auto Angle = Variable::CalculateAngle(Origin() + ViewOffset(), BonePos(PlayerPawn, Aim_Parts), Recoil_Angle);
				const auto FovG = hypot(Angle.x, Angle.y);
				if (!Angle.IsZero() && FovG <= Aim_Range)
				{
					Aim_Range = FovG - 2;
					if (Scoped())Move_Mouse(-Angle.y * Aim_Smooth * 3.5, Angle.x * Aim_Smooth * 3.5);
					else Move_Mouse(-Angle.y * Aim_Smooth, Angle.x * Aim_Smooth);
					if (UI_Legit_Aimbot_AutoShoot && CrosshairId && (!UI_Legit_Aimbot_AutoShoot_AutoStop || Stop_Move()) && FovG <= 0.8)//AutoShoot & AutoStop
					{
						if (Local_ActiveWeaponType == 3)System::Key_Con(UI_Legit_Aimbot_Key, false);//狙击枪释放
						Send_CMD("+attack");
						if (Local_ActiveWeaponID == 64)Sleep(250);//R8无法开枪修复
						else Sleep(1);
						Send_CMD("-attack");
						Sleep(UI_Legit_Aimbot_AutoShoot_Interval);//Auto Shoot Interval
					}
				}
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_AdaptiveAimbot() noexcept
{
	System::Log("Load Thread: Thread_Funtion_AdaptiveAimbot()");
	while (true)
	{
		System::Sleep_ns(5000);//比Sleep更快的函数为了更加自然平滑
		if (Global_CS_Window_ShowState && UI_Legit_Aimbot_AdaptiveAimbot && System::Get_Key(VK_LBUTTON) && Health() && Weapon_Type(ClippingWeapon()) == 2)//当CS窗口在最前端 && 本地人物活着 && 按键按下 && 步枪
		{
			float Aim_Range = 2.5; const auto PunchAngle = AimPunchAngle();
			if (abs(PunchAngle.x) * 2 >= Aim_Range)Aim_Range = abs(PunchAngle.x) * 1.5;
			for (short i = 0; i < Global_Valid_ClassID.size(); ++i)
			{
				const auto PlayerPawn = Traverse_Player(Global_Valid_ClassID[i]);
				if (!Check_Enemy(PlayerPawn) || !Spotted(PlayerPawn))//当没有被发现则重新来过
					continue;
				const auto Angle = Variable::CalculateAngle(Origin() + ViewOffset(), BonePos(PlayerPawn, 6), ViewAngles() + PunchAngle * 2);//最终瞄准角度
				const auto FovG = hypot(Angle.x, Angle.y);
				if (!Angle.IsZero() && FovG <= Aim_Range)
				{
					Aim_Range = FovG;
					if (System::Get_Key(VK_CONTROL) || FovG <= 1.5)Move_Mouse(-Angle.y * 20, Angle.x * 20);
					else Move_Mouse(-Angle.y * 10, Angle.x * 5);
				}
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_Triggerbot() noexcept
{
	System::Log("Load Thread: Thread_Funtion_Triggerbot()");
	while (true)
	{
		if (Global_CS_Window_ShowState && UI_Legit_Triggerbot && System::Get_Key(UI_Legit_Triggerbot_Key) && Health())//当CS窗口在最前端 && 本地人物活着 && 按键按下
		{
			System::Sleep_ns(600);//纳秒级延时
			const auto Local_ActiveWeaponID = ItemIndex(ClippingWeapon());//本地人物手持武器ID
			if (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500 || Local_ActiveWeaponID == 31)//过滤特殊武器
				continue;
			else if ((UI_Legit_Triggerbot_AnyTarget && IDEntIndex() != -1) || Check_Enemy(IDEntIndex_Pawn()))//当瞄准的人是敌人
			{
				Send_CMD("+attack");//Shoot!! 开枪!!
				Sleep(UI_Legit_Triggerbot_ShootDuration);
				Send_CMD("-attack");
				Sleep(UI_Legit_Triggerbot_ShootInterval);
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_PreciseAim() noexcept
{
	System::Log("Load Thread: Thread_Funtion_PreciseAim()");
	while (true)
	{
		if (Global_CS_Window_ShowState && UI_Legit_PreciseAim && Health())//当CS窗口在最前端 && 本地人物活着
		{
			System::Sleep_ns(2000);//纳秒级延时
			const auto Local_ActiveWeaponID = ItemIndex(ClippingWeapon());//本地人物手持武器ID
			if (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500)//过滤特殊武器
			{
				Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity)); Sleep(10);
				continue;
			}
			if (Check_Enemy(IDEntIndex_Pawn()))Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_EnableSensitivity));
			else Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity));
		}
		else Sleep(20);
	}
}
void Thread_Funtion_ESP() noexcept
{
	System::Log("Load Thread: Thread_Funtion_ESP()");
	const auto FreeCS_ESP_RenderWindow = Window::NVIDIA_Overlay();//初始化英伟达覆盖
	Window::Render ESP_Paint; ESP_Paint.CreatePaint(FreeCS_ESP_RenderWindow, 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y);
	while (true)
	{
		Sleep(UI_Visual_ESP_RenderSleep);
		const auto CS_Scr_Res = Window::Get_WindowResolution(Global_CS_HWND);
		MoveWindow(FreeCS_ESP_RenderWindow, CS_Scr_Res.b, CS_Scr_Res.a, CS_Scr_Res.r, CS_Scr_Res.g, TRUE);//修改 Pos & Size
		ESP_Paint.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//清除画板
		if (Global_CS_HWND && (FreeCS_GUI_ShowState || Global_CS_Window_ShowState))//当CS窗口在最前端 && 菜单在最前端
		{
			if (UI_Visual_ESP && (UI_Visual_ESP_Key == 0 || System::Get_Key(UI_Visual_ESP_Key)))//ESP 透视
			{
				auto Draw_Color = FreeCS_GUI_IO.GUIColor;
				if (UI_Visual_ESP_CustomColor)Draw_Color = UI_Visual_ESP_CustomColor_Color;
				const auto Local_Matrix = ViewMatrix(); const auto Local_Angles = ViewAngles(); const auto Local_Position = Origin();
				for (short i = 0; i < Global_Valid_ClassID.size(); ++i)
				{
					const auto PlayerPawn = Traverse_Player(Global_Valid_ClassID[i]);
					if (!Check_Enemy(PlayerPawn))//多点检测
						continue;
					const auto Top_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, BonePos(PlayerPawn, 6) + Variable::Vector3{0, 0, 8}, Local_Matrix);
					const auto Entity_Position = Origin(PlayerPawn);
					if (Top_Pos.x < -100 || Top_Pos.x > CS_Scr_Res.r + 100)//检测是否在屏幕内
					{
						if (UI_Visual_ESP_OutFOV && Health())//绘制方向指示器
						{
							auto Screen_Pos = Variable::角度转坐标(CS_Scr_Res.g / ((120 - (float)UI_Visual_ESP_OutFOV_Radius) / 10), Local_Angles.y - 90 + atan2((Local_Position.x - Entity_Position.x), (Local_Position.y - Entity_Position.y)) * (180 / acos(-1)));
							Screen_Pos = { CS_Scr_Res.r / 2 - Screen_Pos[0] * ((float)CS_Scr_Res.r / (float)CS_Scr_Res.g),CS_Scr_Res.g / 2 + Screen_Pos[1] };
							ESP_Paint.RenderA_GradientCircle(Screen_Pos[0], Screen_Pos[1], UI_Visual_ESP_OutFOV_Size, { 0,0,0,100 }, { 0,0,0,0 });
							ESP_Paint.RenderA_GradientCircle(Screen_Pos[0], Screen_Pos[1], UI_Visual_ESP_OutFOV_Size, Draw_Color.D_Alpha(System::RainbowColor(3).r), { 0,0,0,0 });
							if (UI_Visual_ESP_ActiveWeapon)ESP_Paint.Render_String(Screen_Pos[0] - 8, Screen_Pos[1] - 4, Weapon_Name(ClippingWeapon(PlayerPawn)), "Small Fonts", 9, { 100,100,100 });
						}
						continue;//不绘制ESP 重来
					}
					const auto Bottom_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Origin(PlayerPawn) - Variable::Vector3{0, 0, 6}, Local_Matrix);
					const auto Hight = Bottom_Pos.y - Top_Pos.y;
					const auto Width = Hight * 0.25;
					const auto Left = Top_Pos.x - Width;
					const auto Right = Top_Pos.x + Width;
					if (Variable::Coor_Dis_3D(Local_Position, Entity_Position) <= 3500)//距离检测 降低CPU占用
					{
						if (UI_Visual_ESP_Snapline)ESP_Paint.RenderA_GradientLine(CS_Scr_Res.r / 2, CS_Scr_Res.g, Left + (Right - Left) / 2, Bottom_Pos.y, { 0,0,0,0 }, Draw_Color.D_Alpha(150));
						if (UI_Visual_ESP_Skeleton)
						{
							static const vector<short> Bone_Flags = { 6,5,4,13,14,15,14,13,4,8,9,10,9,8,4,3,2,1,25,26,27,26,25,1,22,23,24,24 };
							for (short i = 0; i <= Bone_Flags.size() - 2; ++i)
							{
								const auto Bone_ScreenPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, BonePos(PlayerPawn, Bone_Flags[i]), Local_Matrix);
								const auto Bone_ScreenPos_ = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, BonePos(PlayerPawn, Bone_Flags[i + 1]), Local_Matrix);
								ESP_Paint.Render_Line(Bone_ScreenPos.x, Bone_ScreenPos.y, Bone_ScreenPos_.x, Bone_ScreenPos_.y, Draw_Color / 2);
							}
						}
						if (UI_Visual_ESP_HeadDot)
						{
							const auto Head_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, BonePos(PlayerPawn, 6), Local_Matrix);
							ESP_Paint.RenderA_GradientCircle(Head_ScrPos.x, Head_ScrPos.y, 10, Draw_Color.D_Alpha(100), { 0,0,0,0 });
						}
					}
					if (UI_Visual_ESP_Box)
					{
						ESP_Paint.RenderA_HollowRect(Left, Top_Pos.y, Right - Left, Bottom_Pos.y - Top_Pos.y, { 0,0,0,130 }, 3);
						ESP_Paint.RenderA_HollowRect(Left, Top_Pos.y, Right - Left, Bottom_Pos.y - Top_Pos.y, Draw_Color.D_Alpha(200));
					}
					if (UI_Visual_ESP_Health)
					{
						const auto PlayerHealth = Health(PlayerPawn);
						auto Health_Ma = PlayerHealth * 0.01;
						if (PlayerHealth > 100)Health_Ma = 1;
						else if (PlayerHealth < 0)Health_Ma = 0;//限制值 防止绘制出错
						ESP_Paint.RenderA_SolidRect(Left - 6, Top_Pos.y - 1, 4, Bottom_Pos.y - Top_Pos.y + 3, { 0,0,0,130 });
						if (UI_Visual_ESP_CustomColor)ESP_Paint.RenderA_SolidRect(Left - 5, Bottom_Pos.y - Hight * Health_Ma, 2, Bottom_Pos.y - (Bottom_Pos.y - Hight * Health_Ma) + 1, Draw_Color.D_Alpha(200));
						else ESP_Paint.RenderA_SolidRect(Left - 5, Bottom_Pos.y - Hight * Health_Ma, 2, Bottom_Pos.y - (Bottom_Pos.y - Hight * Health_Ma) + 1, { (int)(1 - Health_Ma * 255),(int)(255 * Health_Ma),0,200 });
						if (PlayerHealth < 100 && PlayerHealth > 0)ESP_Paint.Render_SmpStr(Left - 8, Bottom_Pos.y - Hight * Health_Ma - 6, to_string(PlayerHealth), { 150,150,150 }, { 0 }, 0);
					}
					const auto Player_ClippingWeapon_Name = Weapon_Name(ClippingWeapon(PlayerPawn));//人物手持武器名称
					if (UI_Visual_ESP_State)
					{
						auto i = 0;//Line pos
						if (Armor(PlayerPawn)) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "HK", { 200,200,200 }, { 0 }, 0); ++i; }
						if (Player_ClippingWeapon_Name == "C4") { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "C4", { 255,0,0 }, { 0 }, 0); ++i; }
						if (Scoped(PlayerPawn) && (Player_ClippingWeapon_Name == "AWP" || Player_ClippingWeapon_Name == "SSG08")) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "ZOOM", { 0,120,255 }, { 0 }, 0); ++i; }
						if (Spotted(PlayerPawn)) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "HIT", { 200,200,200 }, { 0 }, 0); ++i; }
						if (ShotsFired(PlayerPawn) > 0) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "SHOT", { 200,200,200 }, { 0 }, 0); ++i; }
						if (!(Flags(PlayerPawn) & (1 << 0))) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "AIR", { 200,200,200 }, { 0 }, 0); ++i; }
						if (Variable::Coor_Dis_3D(Local_Position, Entity_Position) >= 2500) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "INV", { 100,0,255 }, { 0 }, 0); ++i; }
					}
					if (UI_Visual_ESP_ActiveWeapon)ESP_Paint.Render_SmpStr(Left, Bottom_Pos.y, Player_ClippingWeapon_Name, { 200,200,200 }, { 0 }, 0);
					if (UI_Visual_ESP_Name)ESP_Paint.RenderA_String(Left - 2, Top_Pos.y - 14, Player_Name(Global_Valid_ClassID[i]), "Segoe UI", 10, { 255,255,255,255 });
				}
			}
			if (UI_Legit_Aimbot && UI_Legit_Aimbot_ShowRange && Health())//Aimbot Range 自瞄范围绘制
			{
				auto Circle_Range = 0;
				const auto Local_ActiveWeaponType = Weapon_Type(ClippingWeapon());//本地人物手持武器类型
				if (Local_ActiveWeaponType == 1)Circle_Range = UI_Legit_Aimbot_A_Range_PISTOL * 5;
				else if (Local_ActiveWeaponType == 2)Circle_Range = UI_Legit_Aimbot_A_Range_RIFLE * 5;
				else if (Local_ActiveWeaponType == 3) { if (Scoped())Circle_Range = UI_Legit_Aimbot_A_Range_SNIPER * 14; else Circle_Range = UI_Legit_Aimbot_A_Range_SNIPER * 5; }
				if (Circle_Range)Circle_Range = Circle_Range + AimPunchAngle().x * -25;
				ESP_Paint.Render_HollowCircle(CS_Scr_Res.r / 2, CS_Scr_Res.g / 2, Variable::Animation<class Render_Aimbot_Range_Animation>(Circle_Range, 2), FreeCS_GUI_IO.GUIColor / 5);
			}
			if (FreeCS_GUI_ShowState)Sleep(5);//菜单打开时降低绘制速度以降低CPU使用率
		}
		else Sleep(20);
		ESP_Paint.DrawPaint();
	}
}
void Thread_Funtion_DropsESP() noexcept
{
	System::Log("Load Thread: Thread_Funtion_DropsESP()");
	Window::Windows RenderWindow; Window::Render WEP_Render;
	const auto Render_Window_HWND = RenderWindow.Create_RenderBlock(Window::Get_Resolution().x, Window::Get_Resolution().y, System::Rand_String(12));
	WEP_Render.CreatePaint(Render_Window_HWND, 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y);
	while (true)
	{
		Sleep(UI_Visual_ESP_RenderSleep);
		const auto CS_Scr_Res = Window::Get_WindowResolution(Global_CS_HWND);
		WEP_Render.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//Clear Paint
		if (Global_CS_HWND && UI_Visual_ESP && (UI_Visual_ESP_Key == 0 || System::Get_Key(UI_Visual_ESP_Key)) && UI_Visual_ESP_Drops && (FreeCS_GUI_ShowState || Global_CS_Window_ShowState) && Health())//当CS窗口在最前端 && 本地人物活着
		{
			MoveWindow(Render_Window_HWND, CS_Scr_Res.b, CS_Scr_Res.a, CS_Scr_Res.r, CS_Scr_Res.g, TRUE);//Pos & Size
			const auto Entitylist = EntityList(); const auto Local_Origin = Origin(); const auto Local_ViewMatrix = ViewMatrix();
			static vector<short> Class_ID = {};//有效实体ID
			if (System::Sleep_Tick<class Drops_ESP_Reload_ClassID_>(1000))//特殊算法为了提高绘制效率
			{
				short Show_Quantity = 0;//计算绘制的实体数量
				Class_ID = {};//刷新有效实体ID
				for (short i = 64; i <= 1024; ++i)//class id 64-1024
				{
					if (Show_Quantity > 30)//限制数量
						continue;
					const auto Entity = Convert(Entitylist, i);
					if (!Entity)
						continue;
					const auto Entity_Pos = AbsOrigin(Entity);
					if (Entity_Pos.x == 0 || Variable::Coor_Dis_3D(Local_Origin, Entity_Pos) > 1500)//距离检测
						continue;
					const auto Entity_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, AbsOrigin(Entity), Local_ViewMatrix);
					if (Entity_ScrPos.x < -300 || Entity_ScrPos.x > CS_Scr_Res.r + 300)//检测是否在屏幕内
						continue;
					if (Weapon_Name(Entity) == "NONE")//检测名称是否有效
						continue;
					Class_ID.push_back(i);
					++Show_Quantity;
				}
			}
			if (Class_ID.size() > 0)
			{
				for (short i = 0; i < Class_ID.size(); ++i)//只遍历有效实体
				{
					const auto Entity = Convert(Entitylist, Class_ID[i]);
					if (Weapon_Name(Entity) == "NONE")//检测名称是否有效
						continue;
					if (AbsOrigin(Entity).x == 0)//过滤掉无效坐标
						continue;
					const auto Entity_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, AbsOrigin(Entity), Local_ViewMatrix);
					WEP_Render.Render_SmpStr(Entity_ScrPos.x - 10, Entity_ScrPos.y, Weapon_Name(Entity), { 200,200,200 }, { 1,1,1 });
				}
			}
			else Sleep(100);
		}
		else { MoveWindow(Render_Window_HWND, 0, 0, 0, 0, TRUE); Sleep(20); }
		WEP_Render.DrawPaint(true);
	}
}
void Thread_Funtion_Sonar() noexcept
{
	System::Log("Load Thread: Thread_Funtion_Sonar()");
	while (true)
	{
		Sleep(1);
		if (Global_CS_Window_ShowState && UI_Misc_Sonar && (UI_Misc_Sonar_Key == 0 || System::Get_Key(UI_Misc_Sonar_Key)) && Health())//当CS窗口在最前端 && 本地人物活着
		{
			const auto Local_Pos = Origin();//本地人物坐标
			for (short i = 0; i <= 64; ++i)
			{
				System::Sleep_ns(150);
				if (UI_Misc_Sonar_Key != 0 && !System::Get_Key(UI_Misc_Sonar_Key))continue;//提高效率
				const auto PlayerPawn = Traverse_Player(i);
				if (!Check_Enemy(PlayerPawn))//多点检测
					continue;
				const auto Pos_Dis = Variable::Coor_Dis_2D(Local_Pos, Origin(PlayerPawn));//敌人坐标距离
				if (Pos_Dis <= UI_Misc_Sonar_Range_Near)Send_CMD("playvol buttons/button16.wav 1");//Near range 近距离
				else if (Pos_Dis <= UI_Misc_Sonar_Range_Far)Send_CMD("playvol ui/xp_remaining.wav 1");//Far range 远距离
				if (Pos_Dis <= UI_Misc_Sonar_Range_Far)Sleep(20);//断开间隔
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_Radar() noexcept
{
	System::Log("Load Thread: Thread_Funtion_Radar()");
	Window::Windows Radar_Window; const auto RadarRenderWindow = Radar_Window.Create_Window(UI_Visual_Radar_Size, UI_Visual_Radar_Size + 15, System::Rand_String(13), true);//创建雷达绘制窗口
	Window::Render Radar_Paint; Radar_Paint.CreatePaint(RadarRenderWindow, 0, 0, 500, 500 + 15);//创建绘制画板
	Radar_Window.Set_WindowPos(UI_Visual_Radar_Pos.x, UI_Visual_Radar_Pos.y);//套用参数的雷达位置
	while (true)
	{
		Sleep(10);//降低CPU占用
		static short Radar_Size_; const short RadarSizeAnimation = Variable::Animation<class Class_Radar_Window_Size>(Radar_Size_, 3);
		if ((Global_CS_Window_ShowState || FreeCS_GUI_ShowState || Window::Get_WindowEnable(Radar_Window.Get_HWND())) && UI_Visual_Radar)//当CS窗口在最前端
		{
			Radar_Size_ = UI_Visual_Radar_Size; UI_Visual_Radar_Pos = Radar_Window.Get_WindowPos();
			if (!Radar_Window.Window_Move(15))
			{
				const float RadarRangeAnimation = Variable::Animation<class Class_Radar_Window_Range>(UI_Visual_Radar_Range, 3);
				const auto LocalPlayerPos = Origin(); const auto ViewAngle = ViewAngles();
				Radar_Paint.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//背景
				Radar_Paint.Render_GradientRect(0, 0, Radar_Window.Get_WindowSize().x, 14, FreeCS_GUI_IO.GUIColor / 2, FreeCS_GUI_IO.GUIColor / 4, false);
				Radar_Paint.Render_GradientRect(0, 14, Radar_Window.Get_WindowSize().x, 1, FreeCS_GUI_IO.GUIColor / 4, FreeCS_GUI_IO.GUIColor / 2, false);//标题背景
				Radar_Paint.Render_String(3 + 1, 1 + 1, "FreeCS Radar", "Small Fonts", 12, { 0,0,0 }, false);
				Radar_Paint.Render_String(3, 1, "FreeCS Radar", "Small Fonts", 12, FreeCS_GUI_IO.GUIColor, false);//标题
				if (UI_Visual_Radar_FollowAngle)Radar_Paint.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[1] ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[1] }, FreeCS_GUI_IO.GUIColor / 5, { 0,0,0 }, { 0,0,0 });
				else Radar_Paint.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 45)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 45)[1] ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 135)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 135)[1] }, FreeCS_GUI_IO.GUIColor / 5, { 0,0,0 }, { 0,0,0 });//Self Aimpos
				Radar_Paint.Render_HollowCircle(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 100 * 3.5, { 255,255,255 }, 1);//自身圆圈
				for (short i = 0; i < Global_Valid_ClassID.size(); ++i)
				{
					const auto PlayerPawn = Traverse_Player(Global_Valid_ClassID[i]);
					if (!Check_Enemy(PlayerPawn))//多点检测
						continue;
					const auto EntityPos = Origin(PlayerPawn);
					static vector<float> 敌人屏幕坐标;
					if (UI_Visual_Radar_FollowAngle)敌人屏幕坐标 = { RadarSizeAnimation / 2 - Variable::角度转坐标(Variable::Coor_Dis_2D(LocalPlayerPos, EntityPos), ViewAngle.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180 / acos(-1)))[0] / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + Variable::角度转坐标(Variable::Coor_Dis_2D(LocalPlayerPos, EntityPos), ViewAngle.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180 / acos(-1)))[1] / RadarRangeAnimation };
					else 敌人屏幕坐标 = { RadarSizeAnimation / 2 - (LocalPlayerPos.x - EntityPos.x) / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + (LocalPlayerPos.y - EntityPos.y) / RadarRangeAnimation };
					if (敌人屏幕坐标[0] > RadarSizeAnimation)敌人屏幕坐标[0] = RadarSizeAnimation;
					else if (敌人屏幕坐标[0] < 0) 敌人屏幕坐标[0] = 0;
					if (敌人屏幕坐标[1] > RadarSizeAnimation + 15)敌人屏幕坐标[1] = RadarSizeAnimation + 15;
					else if (敌人屏幕坐标[1] < 15)敌人屏幕坐标[1] = 15;
					if (Spotted(PlayerPawn))Radar_Paint.Render_SolidCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3.5, FreeCS_GUI_IO.GUIColor, FreeCS_GUI_IO.GUIColor, 1);//敌人圆圈
					else Radar_Paint.Render_HollowCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3.5, FreeCS_GUI_IO.GUIColor, 1);
				}
				Radar_Paint.DrawPaint();
			}
		}
		else Radar_Size_ = 0;
		Radar_Window.Set_WindowSize(RadarSizeAnimation, RadarSizeAnimation + 15);
		Radar_Window.Set_WindowAlpha(Variable::Animation<class Class_Radar_Window_Alpha>(UI_Visual_Radar_Alpha, 3));
	}
}
int main() noexcept
{
	system("cls");//清除文字
	System::Log("Load Thread: main()");
	System::Anti_click();//不被暂停
	Window::Hide_ConsoleWindow();
	Sleep(200);//修复重启进程冲突
	if (!System::Judge_File("FreeCS.cfg"))//创建参数文件
	{
		System::Create_File("FreeCS.cfg", FreeCS_DefaultConfig);//创建默认参数
		System::Self_Restart();
	}
	thread Thread_Menu_ = thread(Thread_Menu);
	thread Thread_Misc_ = thread(Thread_Misc);
	Sleep(50);
	thread Thread_Funtion_Aimbot_ = thread(Thread_Funtion_Aimbot);
	thread Thread_Funtion_AdaptiveAimbot_ = thread(Thread_Funtion_AdaptiveAimbot);
	thread Thread_Funtion_Triggerbot_ = thread(Thread_Funtion_Triggerbot);
	thread Thread_Funtion_PreciseAim_ = thread(Thread_Funtion_PreciseAim);
	thread Thread_Funtion_ESP_ = thread(Thread_Funtion_ESP);
	thread Thread_Funtion_DropsESP_ = thread(Thread_Funtion_DropsESP);
	thread Thread_Funtion_Sonar_ = thread(Thread_Funtion_Sonar);
	thread Thread_Funtion_Radar_ = thread(Thread_Funtion_Radar);
	while (true)
	{
		if (System::Get_Key(VK_INSERT) && System::Get_Key(VK_DELETE)) { Beep(100, 30); Window::NVIDIA_Overlay(); exit(0); }//快速关闭键
		const auto MenuWindowAlpha_ = Variable::Animation<class Main_FreeCS_MenuAlpha_Animation>(UI_Settings_MenuAlpha, 3);//菜单透明度动画
		static short MenuWindowAlpha = 0;
		if (FreeCS_GUI_ShowState)MenuWindowAlpha = MenuWindowAlpha + MenuWindowAlpha_ / 10;
		else MenuWindowAlpha = MenuWindowAlpha - MenuWindowAlpha_ / 10;
		if (MenuWindowAlpha >= MenuWindowAlpha_)MenuWindowAlpha = MenuWindowAlpha_;
		else if (MenuWindowAlpha <= 0)MenuWindowAlpha = 0;
		FreeCS_GUI.Window_SetAlpha(MenuWindowAlpha);//修改菜单透明度
		if (UI_Settings_CustomMenuColor)FreeCS_GUI.Global_Set_EasyGUI_Color(UI_Settings_MenuColor);//自定义菜单颜色
		if (!System::Key_Toggle<class Main_FreeCS_MenuKey>(UI_Settings_MenuKey))
		{
			FreeCS_GUI.Window_Show();
			FreeCS_GUI_ShowState = true;
		}
		else {
			if (MenuWindowAlpha == 0)FreeCS_GUI.Window_Hide();
			FreeCS_GUI_ShowState = false;
		}
		Sleep(1);
	}
}