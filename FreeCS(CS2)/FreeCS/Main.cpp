#include "Head.h"
const string ReleaseDate = "[2023-10-14 23:00]";
const string ApplicableVersion = "Oct 13 16 (Test)";
EasyGUI::EasyGUI Free_GUI_VAR;
EasyGUI::EasyGUI_IO Free_GUI_IO;
BOOL MenuShowState;
//----------------------------------------------------
namespace Config_Var
{
	const string DefaultConfig = "0\n5\n0\n1\n0\n1\n1\n100\n1\n100\n3\n100\n3\n100\n3\n1\n5\n1\n150\n1\n0.015\n0.004\n1\n250\n1\n162\n1\n0\n1\n1\n160\n800\n350\n1\n1\n22\n230\n1\n1\n45\n0\n200\n200\n255\n250\n0\n1\n1\n1\n1\n1\n1\n25\n10\n180\n0\n";
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
	BOOL UI_Settings_Res_800;
	BOOL UI_Settings_WaterMark = Variable::string_int_(System::Get_File("FreeCS.cfg", 47));
	int UI_Misc_ESP_RenderSleep = Variable::string_int_(System::Get_File("FreeCS.cfg", 48));
	BOOL UI_Misc_AutoClearDecals = Variable::string_int_(System::Get_File("FreeCS.cfg", 49));
	BOOL UI_Misc_ESP_Health = Variable::string_int_(System::Get_File("FreeCS.cfg", 50));
	BOOL UI_Misc_ESP_Snaplines = Variable::string_int_(System::Get_File("FreeCS.cfg", 51));
	BOOL UI_Misc_ESP_Skeleton = Variable::string_int_(System::Get_File("FreeCS.cfg", 52));
	vector<int> UI_Misc_Radar_Pos = { Variable::string_int_(System::Get_File("FreeCS.cfg", 53)) ,Variable::string_int_(System::Get_File("FreeCS.cfg", 54)) };
	int UI_Misc_Radar_Alpha = Variable::string_int_(System::Get_File("FreeCS.cfg", 55));
	BOOL UI_Settings_LockGameWindow = Variable::string_int_(System::Get_File("FreeCS.cfg", 56));
}
namespace Memory_CS
{
	BOOL CS_Window_State = true;
	System::Memory CS_Mem_ = { "" };
	HWND CS_Window_HWND;
	uintptr_t Module_client;
	uintptr_t LocalPlayer;
	vector<short> LocalPlayer_Active_Weapon = { 0,0 };
	namespace Offsets//https://github.com/a2x/cs2-dumper.git
	{
		uintptr_t dwLocalPlayer = 0x187CFC8;
		uintptr_t dwEntityList = 0x178FC88;
		uintptr_t dwViewAngles = 0x18DCAF0;
		uintptr_t dwViewMatrix = 0x187DAB0;
		//--------------------------------------------------------------------------------------
		const uintptr_t m_hPlayerPawn = 0x7BC;//PlayerController -> PlayerPawn
		const uintptr_t m_iIDEntIndex = 0x152C;
		const uintptr_t m_iTeamNum = 0x3BF;
		const uintptr_t m_iHealth = 0x32C;
		const uintptr_t m_fFlags = 0x3C8;
		const uintptr_t m_aimPunchAngle = 0x1704;
		const uintptr_t m_vecViewOffset = 0xC48;
		const uintptr_t m_bSpotted = 0x1628;//m_entitySpottedState + m_bSpotted
		const uintptr_t m_iShotsFired = 0x1404;
		const uintptr_t m_pClippingWeapon = 0x1290;
		const uintptr_t m_vOldOrigin = 0x1214;
		//--------------------------------------------------------------------------------------
		const uintptr_t m_pGameSceneNode = 0x310;
		const uintptr_t m_dwBoneMatrix = 0x1E0;//CGameSceneNode + (CSkeletonInstance == m_modelState + 0x80)
	}
	using namespace Offsets;
	namespace SDK_Funtions
	{
		void Send_CMD(string Str) noexcept//发送指令到CS控制台
		{
			COPYDATASTRUCT m_cData; m_cData.cbData = strlen(Str.c_str()) + 1; m_cData.dwData = 0; m_cData.lpData = (void*)Str.c_str();
			SendMessage(CS_Window_HWND, WM_COPYDATA, 0, (LPARAM)&m_cData);
			if (Str == "+attack")mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			else if (Str == "-attack")mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			if (Str == "playvol ui/xp_remaining.wav 1")Beep(150, 20);
			else if (Str == "playvol buttons/button16.wav 1")Beep(300, 20);
			if (Str == "+jump")System::Key_Click(VK_F13, true);//bind F13 "+jump;-jump";
		}
		int* Ang_Pos(int X, int Y, int Dis, float Ang, float Ang_) noexcept
		{
			const float radian = ((Ang + Ang_) * 3.1415926535) / 180;
			int ReturnValue[2] = { X + Dis * sin(radian),Y + Dis * cos(radian) };
			return ReturnValue;
		}
		void Move_Mouse(int X, int Y) noexcept//更加安全的移动鼠标函数
		{
			const short to_ = 250;
			if (X >= to_)X = to_;
			else if (X <= -to_)X = -to_;
			if (Y >= to_)Y = to_;
			else if (Y <= -to_)Y = -to_;
			System::Mouse_Move(X, Y);
		}
		uintptr_t LocalPlayer_() noexcept { return CS_Mem_.Read<uintptr_t>(Module_client + dwLocalPlayer); }
		uintptr_t EntityList_() noexcept { return CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList); }
		uintptr_t Traverse_Player(short i) noexcept
		{
			i += 2;
			const auto entity_list = CS_Mem_.Read<uintptr_t>(Module_client + dwEntityList);
			const auto list_entry = CS_Mem_.Read<uintptr_t>(entity_list + (8 * (i & 0x7FFF) >> 9) + 16);
			const auto player = CS_Mem_.Read<uintptr_t>(list_entry + 120 * (i & 0x1FF));
			const auto playerPawn = CS_Mem_.Read<uintptr_t>(player + m_hPlayerPawn);
			const auto list_entry2 = CS_Mem_.Read<uintptr_t>(entity_list + 0x8 * ((playerPawn & 0x7FFF) >> 9) + 16);
			return CS_Mem_.Read<uintptr_t>(list_entry2 + 120 * (playerPawn & 0x1FF));
		}
		template<class A>
		Variable::Vector3 AimPunchAngle(uintptr_t Player_ID = LocalPlayer, const float X_Offset = 0.1f) noexcept
		{
			auto Def_Punch = CS_Mem_.Read<Variable::Vector3>(LocalPlayer + m_aimPunchAngle); Def_Punch.x -= X_Offset;
			if (CS_Mem_.Read<short>(LocalPlayer + m_iShotsFired) <= 1) { Def_Punch = { 0,0 }; return Def_Punch; }
			else return Variable::Animation_AVec<A>(Def_Punch, 3);
		}
		short Health(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<short>(Player_ID + m_iHealth); }
		short IDEntIndex(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<short>(Player_ID + m_iIDEntIndex); }
		short TeamNumber(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<short>(Player_ID + m_iTeamNum); }
		BOOL Spotted(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<short>(Player_ID + m_bSpotted); }
		Variable::Vector3 Origin(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<Variable::Vector3>(Player_ID + m_vOldOrigin); }
		Variable::Vector3 ViewOffset(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<Variable::Vector3>(Player_ID + m_vecViewOffset); }
		uintptr_t BoneMatrix(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<uintptr_t>(CS_Mem_.Read<uintptr_t>(Player_ID + m_pGameSceneNode) + m_dwBoneMatrix); }
		Variable::Vector3 Bone_Pos(uintptr_t Bone_Matrix, short Bone_ID) noexcept { return CS_Mem_.Read<Variable::Vector3>(Bone_Matrix + Bone_ID * 0x20); }
		Variable::Vector3 Local_ViewAngles() noexcept { return CS_Mem_.Read<Variable::Vector3>(Module_client + dwViewAngles); }
		Variable::view_matrix_t Local_ViewMatrix() noexcept { return CS_Mem_.Read<Variable::view_matrix_t>(Module_client + dwViewMatrix); }
		vector<short> Active_Weapon(uintptr_t Player_ID = LocalPlayer) noexcept
		{
			const auto Active_Weapon_ID_ = CS_Mem_.Read<short>(CS_Mem_.Read<uintptr_t>(Player_ID + m_pClippingWeapon) + 0x124A);//[0]ActiveWeaponID / [1]ActiveWeaponType
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
		short Flags(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<short>(Player_ID + m_fFlags); }
		short ShotsFired(uintptr_t Player_ID = LocalPlayer) noexcept { return CS_Mem_.Read<short>(Player_ID + m_iShotsFired); }
		BOOL Det_MultiPoint(uintptr_t Player_ID, BOOL Check_LocalAlive = true) noexcept
		{
			const auto Player_Pos = CS_Mem_.Read<Variable::Vector3>(Player_ID + m_vOldOrigin);
			auto LocalPlayer_Health = CS_Mem_.Read<short>(LocalPlayer + m_iHealth);
			if (!Check_LocalAlive)LocalPlayer_Health = true;
			if (LocalPlayer_Health && 0 < CS_Mem_.Read<short>(Player_ID + m_iHealth) && CS_Mem_.Read<short>(Player_ID + m_iHealth) <= 100 && CS_Mem_.Read<short>(LocalPlayer + m_iTeamNum) != CS_Mem_.Read<short>(Player_ID + m_iTeamNum) && (Player_Pos.x != 0 || Player_Pos.y != 0))return true;
			else return false;
		}
	}
	using namespace SDK_Funtions;
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
		Free_GUI_VAR.Window_SetSize({ (int)Variable::Animation<class CS_Menu_Animation_1>(WindowSize[0],3),(int)Variable::Animation<class CS_Menu_Animation_2>(WindowSize[1],3) });//Animation
		if (!Free_GUI_VAR.Window_Move() && MenuShowState)
		{
			if (!UI_Settings_CustomMenuColor)Free_GUI_VAR.GUI_BackGround(1368);
			else Free_GUI_VAR.GUI_BackGround(1369);
			Free_GUI_VAR.GUI_Block_Panel(20, 20, 100, Free_GUI_VAR.Window_GetSize()[1] - 40, "", { "Legit","Misc","Settings","Debug" }, UI_Panel);
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
				Free_GUI_VAR.GUI_Tips(Block_Legit_RemoveRecoil_, 2, "Operations that only return landscape.");
				WindowSize = { 1010,580 };
			}
			else if (UI_Panel == 1)//Misc
			{
				const auto Block_Misc_Misc_ = Free_GUI_VAR.GUI_Block(150, 30, 300, "Misc");
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Misc_, 1, "Bunny hop", UI_Misc_BunnyHop);
				Free_GUI_VAR.GUI_Text(Block_Misc_Misc_, 2, "99% trigger", { 200,200,150 });
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_15>(Block_Misc_Misc_, 2, UI_Misc_BunnyHop_100Tri);
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Misc_, 3, "ESP", UI_Misc_ESP);
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_16>(Block_Misc_Misc_, 3, UI_Misc_ESP_Key);
				Free_GUI_VAR.GUI_Checkbox({ Block_Misc_Misc_[0] + 20,Block_Misc_Misc_[1] }, 4, "Health", UI_Misc_ESP_Health);
				Free_GUI_VAR.GUI_Checkbox({ Block_Misc_Misc_[0] + 20,Block_Misc_Misc_[1] }, 5, "Snaplines", UI_Misc_ESP_Snaplines);
				Free_GUI_VAR.GUI_Checkbox({ Block_Misc_Misc_[0] + 20,Block_Misc_Misc_[1] }, 6, "Skeleton", UI_Misc_ESP_Skeleton);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_17>(Block_Misc_Misc_, 7, "Draw delay ~ms", 1, 30, UI_Misc_ESP_RenderSleep);
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Misc_, 8, "Hit sound", UI_Misc_HitSound);
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Misc_, 9, "Auto clear decals", UI_Misc_AutoClearDecals);
				const auto Block_Misc_Sonar_ = Free_GUI_VAR.GUI_Block(150, 350, 130, "Sonar");
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Sonar_, 1, "Enabled", UI_Misc_Sonar);
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_18>(Block_Misc_Sonar_, 1, UI_Misc_Sonar_Key);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_19>(Block_Misc_Sonar_, 2, "Range far", 500, 1000, UI_Misc_Sonar_Range_Far);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_20>(Block_Misc_Sonar_, 3, "Range near", 0, 500, UI_Misc_Sonar_Range_Near);
				const auto Block_Misc_Resolution_ = Free_GUI_VAR.GUI_Block(580, 30, 250, "Screen resolution");
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 1, "3840 × 2160", 78, UI_Settings_Res_3840);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 2, "2560 × 1440", 78, UI_Settings_Res_2560);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 3, "1920 × 1080", 78, UI_Settings_Res_1920);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 4, "1440 × 1080", 78, UI_Settings_Res_1440);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 5, "1280 × 1024", 78, UI_Settings_Res_1280);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 6, "1280 × 960", 83, UI_Settings_Res_960);
				Free_GUI_VAR.GUI_Button(Block_Misc_Resolution_, 7, "800 × 600", 85, UI_Settings_Res_800);
				const auto Block_Misc_Radar_ = Free_GUI_VAR.GUI_Block(580, 300, 190, "Radar");
				Free_GUI_VAR.GUI_Checkbox(Block_Misc_Radar_, 1, "Enabled", UI_Misc_Radar);
				Free_GUI_VAR.GUI_Checkbox({ Block_Misc_Radar_[0] + 20,Block_Misc_Radar_[1] }, 2, "Follow angle", UI_Misc_Radar_FollowAngle);
				Free_GUI_VAR.GUI_Slider<float, class Free_Menu_21>(Block_Misc_Radar_, 3, "Radar range", 0.2, 25, UI_Misc_Radar_Range);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_22>(Block_Misc_Radar_, 4, "Radar size", 150, 500, UI_Misc_Radar_Size);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_23>(Block_Misc_Radar_, 5, "Radar alpha", 100, 230, UI_Misc_Radar_Alpha);
				Free_GUI_VAR.GUI_Tips(Block_Misc_Misc_, 3, "Being covered by a window will reduce the frame rate. (NVIDIA GeForce Overlay)");
				Free_GUI_VAR.GUI_Tips(Block_Misc_Sonar_, 1, "Makes a subtle sound when approaching an enemy.");
				Free_GUI_VAR.GUI_Tips({ Block_Misc_Resolution_[0] + 10,Block_Misc_Resolution_[1] }, 1, "Flexible switching of window resolution.");
				WindowSize = { 1010,520 };
			}
			else if (UI_Panel == 2)//Settings
			{
				const auto Block_Settings_Settings_ = Free_GUI_VAR.GUI_Block(150, 30, 520, "Settings");
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 1, "FreeCS", Free_GUI_VAR.Global_Get_EasyGUI_Color());
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 1, "            for CS2 (External)", { 100,100,100 });
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 2, "Release date: " + ReleaseDate, { 100,100,100 });
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 3, "Applicable CS2 Version: " + ApplicableVersion, { 100,100,100 });
				Free_GUI_VAR.GUI_Checkbox(Block_Settings_Settings_, 4, "Lock game window", UI_Settings_LockGameWindow);
				Free_GUI_VAR.GUI_Text(Block_Settings_Settings_, 5, "Menu key");
				Free_GUI_VAR.GUI_KeySelector<class Free_Menu_24>(Block_Settings_Settings_, 5, UI_Settings_MenuKey);
				Free_GUI_VAR.GUI_Checkbox(Block_Settings_Settings_, 6, "Custom menu color", UI_Settings_CustomMenuColor);
				Free_GUI_VAR.GUI_ColorSelector(Block_Settings_Settings_, 6, UI_Settings_MenuColor);
				Free_GUI_VAR.GUI_Slider<int, class Free_Menu_25>(Block_Settings_Settings_, 7, "Alpha", 150, 255, UI_Settings_MenuAlpha);
				Free_GUI_VAR.GUI_Checkbox(Block_Settings_Settings_, 8, "Watermark", UI_Settings_WaterMark);
				Free_GUI_VAR.GUI_Checkbox(Block_Settings_Settings_, 9, "Show console window [Debug]", UI_Settings_ShowDebugWindow);
				static BOOL Clear_Console = false; Free_GUI_VAR.GUI_Button_Small(Block_Settings_Settings_, 9, Clear_Console);
				if (Clear_Console)system("cls");//Clear Console Text
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 10, "SaveConfig", 85, UI_Settings_SaveConfig);
				if (CS_Window_HWND)Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 11, "Restart CS", 81, UI_Settings_RestartCS);
				else Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 11, "Start CS", 85, UI_Settings_RestartCS);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 12, "Quit CS", 90, UI_Settings_QuitCS);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 13, "SendCommand to CS", 55, UI_Settings_SendCommand);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 14, "SendTestCommand to CS", 40, UI_Settings_SendTestCommand);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 15, "Restart FreeCS", 70, UI_Settings_RestartFreeCS);
				Free_GUI_VAR.GUI_Button(Block_Settings_Settings_, 16, "Close", 100, UI_Settings_CloseFreeCS);
				Free_GUI_VAR.GUI_Tips({ Block_Settings_Settings_[0] + 10,Block_Settings_Settings_[1] }, 1, "No ban record so far in 2020.", { 150,255,150 });
				Free_GUI_VAR.GUI_Tips(Block_Settings_Settings_, 4, "Lock the game window to the front.");
				Free_GUI_VAR.GUI_Tips({ Block_Settings_Settings_[0] + 3,Block_Settings_Settings_[1] }, 9, "Clear console.");
				Free_GUI_VAR.GUI_Tips({ Block_Settings_Settings_[0] + 10,Block_Settings_Settings_[1] }, 10, "If you want to reset the default config you can delete FreeCS.cfg in the same folder.");
				Free_GUI_VAR.GUI_Tips({ Block_Settings_Settings_[0] + 10,Block_Settings_Settings_[1] }, 13, "Set your personal parameters.");
				WindowSize = { 580,580 };
			}
			else if (UI_Panel == 3)//Debug
			{
				const auto Block_Debug_List_ = Free_GUI_VAR.GUI_Block(150, 30, 540, "Data list");
				static BOOL UI_Debug_Datalist = false;
				Free_GUI_VAR.GUI_Checkbox(Block_Debug_List_, 1, "Enabled list", UI_Debug_Datalist);
				if (UI_Debug_Datalist)
				{
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 2, "client.dll -> 0x" + Variable::Hex_String(Module_client));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 3, "--------------------------------------------------------------");
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 4, "LocalPlayer -> 0x" + Variable::Hex_String(LocalPlayer));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 5, "LocalPlayer Health: " + to_string(Health()));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 6, "LocalPlayer TeamNum: " + to_string(TeamNumber()));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 7, "LocalPlayer Flags: " + to_string(Flags()));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 8, "LocalPlayer IDEntIndex: " + to_string(IDEntIndex()));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 9, "LocalPlayer Activeweapon: " + to_string(Active_Weapon()[0]));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 10, "LocalPlayer Origin: [" + Variable::Float_Precision((Origin().x)) + ", " + Variable::Float_Precision(Origin().y) + ", " + Variable::Float_Precision(Origin().z) + "]");
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 11, "LocalPlayer ViewAngles: [" + Variable::Float_Precision(Local_ViewAngles().x) + ", " + Variable::Float_Precision(Local_ViewAngles().y) + ", " + Variable::Float_Precision(Local_ViewAngles().z) + "]");
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 12, "--------------------------------------------------------------");
					static auto Player_ID = 0;
					Free_GUI_VAR.GUI_Slider<int, class Debug_Menu_Player_ID_Test_S__>(Block_Debug_List_, 13, "PlayerID", 0, 64, Player_ID);
					const auto Player_Address = Traverse_Player(Player_ID);
					if (Det_MultiPoint(Player_Address))Free_GUI_VAR.GUI_Text(Block_Debug_List_, 14, "Player -> 0x" + Variable::Hex_String(Player_Address), { 255,255,150 });
					else Free_GUI_VAR.GUI_Text(Block_Debug_List_, 14, "Player -> 0x" + Variable::Hex_String(Player_Address));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 15, "Player Health: " + to_string(Health(Player_Address)));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 16, "Player TeamNum: " + to_string(TeamNumber(Player_Address)));
					Free_GUI_VAR.GUI_Text(Block_Debug_List_, 17, "Player Origin: [" + Variable::Float_Precision((Origin(Player_Address).x)) + ", " + Variable::Float_Precision(Origin(Player_Address).y) + ", " + Variable::Float_Precision(Origin(Player_Address).z) + "]");
				}
				Free_GUI_VAR.GUI_Tips(Block_Debug_List_, 1, "May take up higher performance.", { 255,150,150 });
				WindowSize = { 580,600 };
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
			CS_Mem_ = { "cs2.exe" };//CS Process
			CS_Window_HWND = CS_Mem_.Get_ProcessHWND();
			Module_client = CS_Mem_.Get_Module("client.dll");
			LocalPlayer = CS_Mem_.Read<uintptr_t>(Module_client + dwLocalPlayer);
			CS_Window_State = CS_Window_HWND && Window::Get_WindowEnable(CS_Window_HWND);
			if (CS_Window_State)
			{
				if (UI_Misc_AutoClearDecals)Send_CMD("r_cleardecals");//清除血迹
				LocalPlayer_Active_Weapon = Active_Weapon();//screening weapons
			}
		}
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		if (UI_Settings_WaterMark)//WaterMark
		{
			WaterMark_Window_Var.Set_Window_Pos(0, 0);
			if (System::Sleep_Tick<class WaterMark_Window_Sleep_Class_>(200))//Sleep no in thread.
			{
				static string WaterMark_String = "";
				short WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 4.8;
				if (!CS_Window_HWND)WaterMark_String = "FreeCS | CS not found | " + System::Time_String();
				else {
					WaterMark_String = "FreeCS | " + System::Time_String();
					WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 5.2;
				}
				vector<int> Watermark_Pos = { Window::Get_Resolution()[0] - WaterMark_String_Size - 10,10 };
				WaterMark_Render_Var.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });
				WaterMark_Render_Var.RenderA_SolidRect(Watermark_Pos[0], Watermark_Pos[1], WaterMark_String_Size, 14, { 1,1,1,150 });
				if (UI_Settings_CustomMenuColor)
				{
					WaterMark_Render_Var.RenderA_GradientRect(Watermark_Pos[0], Watermark_Pos[1], WaterMark_String_Size / 2, 1, { Free_GUI_IO.GUIColor[0] / 2, Free_GUI_IO.GUIColor[1] / 2, Free_GUI_IO.GUIColor[2] / 2,255 }, { Free_GUI_IO.GUIColor[0], Free_GUI_IO.GUIColor[1], Free_GUI_IO.GUIColor[2],255 });
					WaterMark_Render_Var.RenderA_GradientRect(Watermark_Pos[0] + WaterMark_String_Size / 2, Watermark_Pos[1], WaterMark_String_Size / 2 + 1, 1, { Free_GUI_IO.GUIColor[0], Free_GUI_IO.GUIColor[1], Free_GUI_IO.GUIColor[2],255 }, { Free_GUI_IO.GUIColor[0] / 2, Free_GUI_IO.GUIColor[1] / 2, Free_GUI_IO.GUIColor[2] / 2,255 });
				}
				else {
					WaterMark_Render_Var.RenderA_GradientRect(Watermark_Pos[0], Watermark_Pos[1], WaterMark_String_Size / 2, 1, { Free_GUI_IO.GUIColor_Rainbow[0], Free_GUI_IO.GUIColor_Rainbow[1], Free_GUI_IO.GUIColor_Rainbow[2],255 }, { Free_GUI_IO.GUIColor_Rainbow[3], Free_GUI_IO.GUIColor_Rainbow[4], Free_GUI_IO.GUIColor_Rainbow[5],255 });
					WaterMark_Render_Var.RenderA_GradientRect(Watermark_Pos[0] + WaterMark_String_Size / 2, Watermark_Pos[1], WaterMark_String_Size / 2 + 1, 1, { Free_GUI_IO.GUIColor_Rainbow[3], Free_GUI_IO.GUIColor_Rainbow[4], Free_GUI_IO.GUIColor_Rainbow[5],255 }, { Free_GUI_IO.GUIColor_Rainbow[6], Free_GUI_IO.GUIColor_Rainbow[7], Free_GUI_IO.GUIColor_Rainbow[8],255 });
				}
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
		else if (UI_Settings_Res_800)Window::Set_Resolution(800, 600);
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
				to_string(UI_Misc_AutoClearDecals) + "\n" +
				to_string(UI_Misc_ESP_Health) + "\n" +
				to_string(UI_Misc_ESP_Snaplines) + "\n" +
				to_string(UI_Misc_ESP_Skeleton) + "\n" +
				to_string(UI_Misc_Radar_Pos[0]) + "\n" +
				to_string(UI_Misc_Radar_Pos[1]) + "\n" +
				to_string(UI_Misc_Radar_Alpha) + "\n" +
				to_string(UI_Settings_LockGameWindow) + "\n"
			);
			System::Log("Settings: SaveConfig");
		}
		if (UI_Settings_RestartCS)
		{
			Send_CMD("quit");
			System::Open_Website("steam://rungameid/730");//Start CS
			System::Log("Settings: RestartCS");
		}
		if (UI_Settings_QuitCS)
		{
			Send_CMD("quit");
			System::Log("Settings: QuitCS");
		}
		if (UI_Settings_SendCommand)//Send Var to Source
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
		if (UI_Settings_SendTestCommand)//Send Test Var to Source
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
		if (UI_Settings_CloseFreeCS)exit(0);
		if (UI_Settings_ShowDebugWindow)ShowWindow(GetConsoleWindow(), true);//ShowConsoleWindow
		else ShowWindow(GetConsoleWindow(), false);//HideConsoleWindow
		if (UI_Settings_LockGameWindow && !MenuShowState)SetForegroundWindow(CS_Window_HWND);//Lock CS Window
		CS_Window_State = CS_Window_HWND && Window::Get_WindowEnable(CS_Window_HWND);
		Free_GUI_IO = Free_GUI_VAR.Get_IO();
		if (!UI_Settings_CustomMenuColor)Free_GUI_IO.GUIColor = { Free_GUI_IO.GUIColor_Rainbow[3],Free_GUI_IO.GUIColor_Rainbow[4],Free_GUI_IO.GUIColor_Rainbow[5] };
		//--------------------------------------------------------------------------------------------------------------------------------------------------
		/*
		if (CS_Window_State)//Misc Funtions
		{
			//--------------------------------------
			if (UI_Misc_HitSound)//HitSound
			{
				static auto OldDamage = 0; static auto OldKill = 0;
				const auto Damage = CS_Mem_.Read<int32_t>(LocalPlayer + NULL);//Hit Value
				const auto Kill = CS_Mem_.Read<int32_t>(LocalPlayer + NULL);//Kill Value
				if (Health() && (Damage > OldDamage || Damage < OldDamage))//If hit at Player
				{
					if (Kill > OldKill)Send_CMD("playvol buttons/arena_switch_press_02.wav 1");//Kill
					else if (Damage > OldDamage)Send_CMD("playvol buttons/arena_switch_press_02.wav 1");//Hit
					OldDamage = Damage; OldKill = Kill;
				}
			}
			//--------------------------------------
		}
		*/
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
			static short Aim_Range; static float Aim_Smooth;
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
			if (UI_Legit_Aimbot_AutoShoot)//Activate Trigger
			{
				if (Aim_Range == 20)Aim_Range = 100;
				Move_Mouse(2, 0);
				Sleep(1);
				Move_Mouse(-2, 0);
			}
			short Aim_Parts;
			if (UI_Legit_Aimbot_BodyAim)Aim_Parts = 3;//Parts 6Head 3Body
			else Aim_Parts = 6;
			static Variable::Vector3 Recoil_Angle;
			if (UI_Legit_Aimbot_RemoveRecoil)Recoil_Angle = Local_ViewAngles() + AimPunchAngle<class Class_Aimbot_Recoil_Angle_>() * 2;//RemoveRecoil
			else Recoil_Angle = Local_ViewAngles();//Original Angle
			const auto CrosshairId = IDEntIndex();
			for (short i = 0; i <= 30; ++i)
			{
				const auto Player_T = Traverse_Player(i);//Get All EntityID
				if (!Det_MultiPoint(Player_T))
					continue;
				if ((UI_Legit_Aimbot_TriggerOnAiming && CrosshairId != -1) || (UI_Legit_Aimbot_JudgingWall && !Spotted(Player_T)))//TriggerOnAiming & JudgingWall
					continue;
				const auto Angle = Variable::CalculateAngle(Origin() + ViewOffset(), Bone_Pos(BoneMatrix(Player_T), Aim_Parts), Recoil_Angle);
				const auto FovG = hypot(Angle.x, Angle.y);
				if (!Angle.IsZero() && FovG <= Aim_Range)
				{
					Aim_Range = FovG;
					Move_Mouse(-Angle.y * (33 - Aim_Smooth) * 2, Angle.x * (33 - Aim_Smooth));
					if (UI_Legit_Aimbot_AutoShoot && CrosshairId != -1 && FovG <= 0.8f)
					{
						Send_CMD("+attack");
						Sleep(1);
						Send_CMD("-attack");
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
			const auto PunchAngle = AimPunchAngle<class AdaptiveAimbot_Animation>(LocalPlayer, 0.5);
			if (abs(PunchAngle.x) * 2 >= Aim_Range)Aim_Range = abs(PunchAngle.x) * 0.5;
			for (short i = 0; i <= 30; ++i)
			{
				const auto Player_T = Traverse_Player(i);
				if (!Det_MultiPoint(Player_T) || !Spotted(Player_T))
					continue;
				const auto Angle = Variable::CalculateAngle(Origin() + ViewOffset(), Bone_Pos(BoneMatrix(Player_T), 6), Local_ViewAngles() + PunchAngle * 2);
				const auto FovG = hypot(Angle.x, Angle.y);
				if (!Angle.IsZero() && FovG <= Aim_Range)
				{
					Aim_Range = FovG;
					if (System::Get_Key(VK_CONTROL) || FovG <= 0.8)Move_Mouse(-Angle.y * 20, Angle.x * 20);
					else Move_Mouse(-Angle.y * 10, Angle.x * 5);
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
			if (!Health() || LocalPlayer_Active_Weapon[0] == 42 || LocalPlayer_Active_Weapon[0] == 59 || LocalPlayer_Active_Weapon[0] >= 500)
				continue;
			if (IDEntIndex() != -1)//Aim people is live
			{
				Send_CMD("+attack");//Shoot!!
				Sleep(UI_Legit_Triggerbot_ShootDuration);
				Send_CMD("-attack");
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
				Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity));
				Sleep(10);
				continue;
			}
			if (Health() && IDEntIndex() != -1)Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_EnableSensitivity));
			else Send_CMD("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity));
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
				const auto AimPunch = AimPunchAngle<class class_RemoveRecoil_>();//RecoilAngle
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
		if (CS_Window_State && UI_Misc_BunnyHop && System::Get_Key(VK_SPACE) && Health())//When the cs window is at the front. Press Key
		{
			if (Flags() & (1 << 0))
			{
				Send_CMD("+jump");
				Sleep(1);
				Send_CMD("-jump");
			}
			else {
				if (System::Get_Key(UI_Misc_BunnyHop_100Tri))System::Sleep_ns(100);
				else Sleep(1);
			}
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
			const auto CS_Scr_Res = Window::Get_WindowResolution(CS_Window_HWND);
			MoveWindow(FreeCS_ESP_RenderWindow, CS_Scr_Res[2], CS_Scr_Res[3], CS_Scr_Res[0], CS_Scr_Res[1], TRUE);//Pos & Size
			for (short i = 0; i <= 30; ++i)
			{
				const auto Player_T = Traverse_Player(i);
				if (Det_MultiPoint(Player_T, false))
				{
					const auto ScreenPos = WorldToScreen(CS_Scr_Res[0], CS_Scr_Res[1], Bone_Pos(BoneMatrix(Player_T), 1), Local_ViewMatrix());
					if (UI_Misc_ESP_Snaplines)FreeCS_ESP_Render_Paint_Var.RenderA_GradientLine(CS_Scr_Res[0] / 2, CS_Scr_Res[1], ScreenPos.x, ScreenPos.y, { 0,0,0,0 }, { Free_GUI_IO.GUIColor[0],Free_GUI_IO.GUIColor[1],Free_GUI_IO.GUIColor[2],150 });
					if (UI_Misc_ESP_Health)FreeCS_ESP_Render_Paint_Var.Render_String(ScreenPos.x + 8, ScreenPos.y + 2, to_string(Health(Player_T)), "Small Fonts", 10, { Free_GUI_IO.GUIColor[0] / 2,Free_GUI_IO.GUIColor[1] / 2,Free_GUI_IO.GUIColor[2] / 2 });
					if (UI_Misc_ESP_Skeleton)
					{
						for (short i = 0; i <= 26; ++i)
						{
							static const vector<short> Bone_Flags = { 6,5,4,13,14,15,14,13,4,8,9,10,9,8,4,3,2,1,25,26,27,26,25,1,22,23,24,24 };
							const auto Bone_ScreenPos = WorldToScreen(CS_Scr_Res[0], CS_Scr_Res[1], Bone_Pos(BoneMatrix(Player_T), Bone_Flags[i]), Local_ViewMatrix());
							const auto Bone_ScreenPos_ = WorldToScreen(CS_Scr_Res[0], CS_Scr_Res[1], Bone_Pos(BoneMatrix(Player_T), Bone_Flags[i + 1]), Local_ViewMatrix());
							FreeCS_ESP_Render_Paint_Var.Render_Line(Bone_ScreenPos.x, Bone_ScreenPos.y, Bone_ScreenPos_.x, Bone_ScreenPos_.y, { Free_GUI_IO.GUIColor[0] / 2,Free_GUI_IO.GUIColor[1] / 2,Free_GUI_IO.GUIColor[2] / 2 });
						}
					}
					else FreeCS_ESP_Render_Paint_Var.Render_HollowCircle(ScreenPos.x, ScreenPos.y - 1, 8, { Free_GUI_IO.GUIColor[0] / 2,Free_GUI_IO.GUIColor[1] / 2,Free_GUI_IO.GUIColor[2] / 2 }, 2);
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
			const auto 自身坐标 = Origin();//LocalPlayer Pos
			for (short i = 0; i <= 30; ++i)
			{
				Sleep(1);
				if (UI_Misc_Sonar_Key != 0 && !System::Get_Key(UI_Misc_Sonar_Key))continue;//fast
				const auto Player_T = Traverse_Player(i);
				if (!Det_MultiPoint(Player_T))
					continue;
				const auto 敌人坐标 = Origin(Player_T);
				if (hypot(自身坐标.x - 敌人坐标.x, 自身坐标.y - 敌人坐标.y) <= UI_Misc_Sonar_Range_Near)Send_CMD("playvol buttons/button16.wav 1");
				else if (hypot(自身坐标.x - 敌人坐标.x, 自身坐标.y - 敌人坐标.y) <= UI_Misc_Sonar_Range_Far)Send_CMD("playvol ui/xp_remaining.wav 1");
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
	HWND RadarRenderWindow = RadarWindowsBL.Create_Window(UI_Misc_Radar_Size, UI_Misc_Radar_Size + 15, System::Rand_String(22), true);//Create Render Window
	RadarWindowsBL.Set_WindowAlpha(200);
	RadarWindowsBL.Set_Window_Pos(UI_Misc_Radar_Pos[0], UI_Misc_Radar_Pos[1]);//To Game Radar Pos
	RenderDBBL.CreatePaint(RadarRenderWindow, 0, 0, 500, 500 + 15);//Create Paint
	while (true)
	{
		Sleep(10);//Low Down CPU
		static short Radar_Size_; const short RadarSizeAnimation = Variable::Animation<class Class_Radar_Window_Size>(Radar_Size_, 3);
		if ((CS_Window_State || MenuShowState || Window::Get_WindowEnable(RadarWindowsBL.Get_HWND())) && UI_Misc_Radar)//When the cs window is at the front. Press Key
		{
			Radar_Size_ = UI_Misc_Radar_Size; UI_Misc_Radar_Pos = RadarWindowsBL.Get_Window_Pos();
			if (!RadarWindowsBL.Window_Move(15))
			{
				const float RadarRangeAnimation = Variable::Animation<class Class_Radar_Window_Range>(UI_Misc_Radar_Range, 3);
				const auto LocalPlayerPos = Origin();//localPlayerPos
				const auto ViewAngles = Local_ViewAngles();
				RenderDBBL.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//BackGround
				RenderDBBL.Render_GradientRect(0, 0, RadarWindowsBL.Get_Window_Size()[0], 14, { Free_GUI_IO.GUIColor[0] / 2,Free_GUI_IO.GUIColor[1] / 2,Free_GUI_IO.GUIColor[2] / 2 }, { Free_GUI_IO.GUIColor[0] / 4,Free_GUI_IO.GUIColor[1] / 4,Free_GUI_IO.GUIColor[2] / 4 }, false);
				RenderDBBL.Render_GradientRect(0, 14, RadarWindowsBL.Get_Window_Size()[0], 1, { Free_GUI_IO.GUIColor[0] / 4,Free_GUI_IO.GUIColor[1] / 4,Free_GUI_IO.GUIColor[2] / 4 }, { Free_GUI_IO.GUIColor[0] / 2,Free_GUI_IO.GUIColor[1] / 2,Free_GUI_IO.GUIColor[2] / 2 }, false);//Title Rect
				RenderDBBL.Render_String(3 + 1, 1 + 1, "FreeCS Radar", "Small Fonts", 12, { 0,0,0 });
				RenderDBBL.Render_String(3, 1, "FreeCS Radar", "Small Fonts", 12, Free_GUI_IO.GUIColor);//Title
				if (UI_Misc_Radar_FollowAngle)RenderDBBL.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[1] ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[1] }, { Free_GUI_IO.GUIColor[0] / 5,Free_GUI_IO.GUIColor[1] / 5,Free_GUI_IO.GUIColor[2] / 5 }, { 0,0,0 }, { 0,0,0 });
				else RenderDBBL.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngles.y, 45)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngles.y, 45)[1] ,Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngles.y, 135)[0], Ang_Pos(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngles.y, 135)[1] }, { Free_GUI_IO.GUIColor[0] / 5,Free_GUI_IO.GUIColor[1] / 5,Free_GUI_IO.GUIColor[2] / 5 }, { 0,0,0 }, { 0,0,0 });//Self Aimpos
				RenderDBBL.Render_HollowCircle(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 100 * 3, { 255,255,255 }, 1);//Self Pos
				for (short i = 0; i <= 30; ++i)
				{
					const auto Player_T = Traverse_Player(i);
					if (Det_MultiPoint(Player_T, false))
					{
						const auto EntityPos = Origin(Player_T);
						static vector<float> 敌人屏幕坐标;
						if (UI_Misc_Radar_FollowAngle)敌人屏幕坐标 = { RadarSizeAnimation / 2 - Variable::角度转坐标(hypot(LocalPlayerPos.x - EntityPos.x, LocalPlayerPos.y - EntityPos.y), ViewAngles.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180.0f / (float)acos(-1)))[0] / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + Variable::角度转坐标(hypot(LocalPlayerPos.x - EntityPos.x, LocalPlayerPos.y - EntityPos.y), ViewAngles.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180.0f / (float)acos(-1)))[1] / RadarRangeAnimation };
						else 敌人屏幕坐标 = { RadarSizeAnimation / 2 - (LocalPlayerPos.x - EntityPos.x) / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + (LocalPlayerPos.y - EntityPos.y) / RadarRangeAnimation };
						if (敌人屏幕坐标[0] > RadarSizeAnimation)敌人屏幕坐标[0] = RadarSizeAnimation;
						else if (敌人屏幕坐标[0] < 0) 敌人屏幕坐标[0] = 0;
						if (敌人屏幕坐标[1] > RadarSizeAnimation + 15)敌人屏幕坐标[1] = RadarSizeAnimation + 15;
						else if (敌人屏幕坐标[1] < 15)敌人屏幕坐标[1] = 15;
						if (Spotted(Player_T))RenderDBBL.Render_SolidCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3, Free_GUI_IO.GUIColor, Free_GUI_IO.GUIColor, 1);
						else RenderDBBL.Render_HollowCircle(敌人屏幕坐标[0], 敌人屏幕坐标[1], RadarSizeAnimation / 100 * 3, Free_GUI_IO.GUIColor, 1);
					}
				}
				RenderDBBL.DrawPaint();
			}
		}
		else Radar_Size_ = 0;
		RadarWindowsBL.Set_Window_Size(RadarSizeAnimation, RadarSizeAnimation + 15);
		RadarWindowsBL.Set_WindowAlpha(Variable::Animation<class Class_Radar_Window_Alpha>(UI_Misc_Radar_Alpha, 3));
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
	if (System::Judge_File("FreeCS.ofs"))//Alternate Offsets
	{
		dwLocalPlayer = Variable::string_DWORD_(System::Get_File("FreeCS.ofs", 1));
		dwEntityList = Variable::string_DWORD_(System::Get_File("FreeCS.ofs", 2));
		dwViewAngles = Variable::string_DWORD_(System::Get_File("FreeCS.ofs", 3));
		dwViewMatrix = Variable::string_DWORD_(System::Get_File("FreeCS.ofs", 4));
		System::Log("Settings: Applied to FreeCS.ofs file");
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
		if (System::Get_Key(VK_INSERT) && System::Get_Key(VK_DELETE)) { Beep(100, 30); exit(0); }//Close Key
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