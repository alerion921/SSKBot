#pragma once

#define WINVER 0x0500
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS


#ifndef NDEBUG
#undef _DEBUG
#define NDEBUG
#endif
#if (defined(_DEBUG) || !defined(NDEBUG)) 
#pragma comment (lib, "d3dx9d.lib")
#else
#pragma comment (lib, "d3dx9.lib")
#endif

#include <Windows.h>
#include <Tlhelp32.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <limits>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <tchar.h>
//#include <dinput.h>

#include "SpreadTable.h"
#include "Models.h"
#include "BF2STD.h"
#include "Console.h"
#include "ObjectDefines.h"

#include "detours.h"
#pragma comment(lib, "detours.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(linker, "/export:__imp__DirectInput8Create@20")

using namespace std;

//==============================================================
//DEFINES
//==============================================================
#define M_E        2.71828182845904523536
#define M_LOG2E    1.44269504088896340736
#define M_LOG10E   0.434294481903251827651
#define M_LN2      0.693147180559945309417
#define M_LN10     2.30258509299404568402

#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#define M_1_PI     0.318309886183790671538
#define M_2_PI     0.636619772367581343076
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2    1.41421356237309504880
#define M_SQRT1_2  0.707106781186547524401

#define BONE_M_PENIS 0
#define BONE_R_HIP 1
#define BONE_R_KNEE_0 2
#define BONE_R_KNEE_1 3
#define BONE_R_FOOT_0 4
#define BONE_R_FOOT_1 5
#define BONE_L_HIP 6
#define BONE_L_KNEE_0 7
#define BONE_L_KNEE_1 8
#define BONE_L_FOOT_0 9
#define BONE_L_FOOT_1 10
#define BONE_M_STOMACH_0 11
#define BONE_M_STOMACH_1 12
#define BONE_M_CHEST 13
#define BONE_R_SHOULDER_0 14
#define BONE_R_SHOULDER_1 15
#define BONE_R_ELBOW_0 16
#define BONE_R_ELBOW_1 17
#define BONE_R_ARM 18
#define BONE_R_WRIST_0 19
#define BONE_R_WRIST_1 20
#define BONE_R_HAND_MIDDLEFINGER_0 21
#define BONE_R_HAND_MIDDLEFINGER_1 22
#define BONE_R_HAND_MIDDLEFINGER_2 23
#define BONE_R_HAND_FOREFINGER_0 24
#define BONE_R_HAND_FOREFINGER_1 25
#define BONE_R_HAND_FOREFINGER_2 26
#define BONE_R_HAND_THUMB_0 27
#define BONE_R_HAND_THUMB_1 28
#define BONE_R_HAND_THUMB_2 29
#define BONE_L_SHOULDER_0 30
#define BONE_L_SHOULDER_1 31
#define BONE_L_ELBOW_0 32
#define BONE_L_ELBOW_1 33
#define BONE_L_WRIST_0 34
#define BONE_L_WRIST_1 35
#define BONE_L_HAND_MIDDLEFINGER_0 36
#define BONE_L_HAND_MIDDLEFINGER_1 37
#define BONE_L_HAND_MIDDLEFINGER_2 38
#define BONE_L_HAND_FOREFINGER_0 39
#define BONE_L_HAND_FOREFINGER_1 40
#define BONE_L_HAND_FOREFINGER_2 41
#define BONE_L_HAND_THUMB_0 42
#define BONE_L_HAND_THUMB_1 43
#define BONE_L_HAND_THUMB_2 44
#define BONE_M_NECK_0 45 
#define BONE_M_NECK_1 46
#define BONE_M_NECK_2 47
#define BONE_M_NECK_3 48
#define BONE_M_NECK_4 49
#define BONE_R_JAW_0 50
#define BONE_L_JAW_0 51
#define BONE_R_EYE_0 52
#define BONE_L_EYE_0 53
#define BONE_L_JAW_1 54
#define BONE_R_JAW_1 55
#define BONE_R_EYE_1 56
#define BONE_L_EYE_1 57
#define BONE_R_JAW_2 58
#define BONE_L_JAW_2 59
#define BONE_L_MOUTH_0 60
#define BONE_R_MOUTH_0 61
#define BONE_R_MOUTH_1 62
#define BONE_L_MOUTH_1 63

//Matrix Defines
#define V3_X 0
#define V3_Y 1
#define V3_Z 2
#define V3_ORIGIN 3

#define ASSERT_INTERFACE( x ) if( ! x ){ MessageBoxA( 0, "is missing", #x, 0 ); } 

#define GET_XAXIS_FROMMATRIX( out_vector, pMatrix) { D3DXVec3Normalize( out_vector, &D3DXVECTOR3((pMatrix)->_11,(pMatrix)->_12,(pMatrix)->_13)); } 
#define GET_YAXIS_FROMMATRIX( out_vector, pMatrix) { D3DXVec3Normalize( out_vector, &D3DXVECTOR3((pMatrix)->_21,(pMatrix)->_22,(pMatrix)->_23)); } 
#define GET_ZAXIS_FROMMATRIX( out_vector, pMatrix) { D3DXVec3Normalize( out_vector, &D3DXVECTOR3(((pMatrix))->_31,(pMatrix)->_32,(pMatrix)->_33)); } 
#define GET_ORIGIN_FROMMATRIX( out_vector, pMatrix){ (out_vector)->x = (pMatrix)->_41; (out_vector)->y = (pMatrix)->_42; (out_vector)->z = (pMatrix)->_43; } 

#define GET_XAXIS(out_vector, pMatrix) { D3DXVec3Normalize(out_vector, &D3DXVECTOR3((pMatrix)->_11,(pMatrix)->_12,(pMatrix)->_13)); }
#define GET_YAXIS(out_vector, pMatrix) { D3DXVec3Normalize(out_vector, &D3DXVECTOR3((pMatrix)->_21,(pMatrix)->_22,(pMatrix)->_23)); }
#define GET_ZAXIS(out_vector, pMatrix) { D3DXVec3Normalize(out_vector, &D3DXVECTOR3(((pMatrix))->_31,(pMatrix)->_32,(pMatrix)->_33)); }
#define GET_ORIGIN(out_vector, pMatrix){ (out_vector)->x = (pMatrix)->_41; (out_vector)->y = (pMatrix)->_42; (out_vector)->z = (pMatrix)->_43; }

#define GET_ORIGIN_FROM_MATRIX( out_vector, pMatrix) { GET_AXIS_FROMMATRIX( out_vector, pMatrix, 4); }

#define MATRIXX	0
#define MATRIXY	1
#define MATRIXZ	2
#define ORIGIN	3

#define PITCH 0
#define YAW 1
#define ROLL 2 

#define Class0  "Special Forces"
#define Class1  "Sniper"
#define Class2  "Assault"
#define Class3  "Support"
#define Class4  "Engineer"
#define Class5  "Medic"
#define Class6  "Anti Tank"

#define STANDING 0
#define CROUCHING 1
#define PRONE 2

#define MAXPLAYERS 255

#define HOOK(func,addy) o##func = (t##func)DetourFunction((PBYTE)addy,(PBYTE)hk##func) //hook using detours 1.5
#define UNHOOK(func,addy) o##func = (t##func)DetourFunction((PBYTE)addy,(PBYTE)o##func) //unhook using detours 1.5
#define D3D_RELEASE(D3D_PTR) if( D3D_PTR ){ D3D_PTR->Release(); D3D_PTR = NULL; }

//Class Name Defines
#define BF2_MAINCONSOLE         "MainConsole"
#define BF2_MAINCONSOLEOBJ		"MainConsoleObjects"
#define BF2_PROFILEMANAGER      "ProfileManager"
#define BF2_INPUTMANAGER        "InputManager"
#define BF2_SERVERSETTINGS      "ServerSettingsManager"
#define BF2_PHYSICSMANAGER      "BasicPhysicsSystem"
#define BF2_INPUTDEVICEMANAGER  "InputDeviceManager"
#define BF2_CONTROLMAPMANAGER   "ControlMapManager"
#define BF2_OBJECTMANAGER       "ObjectManager"
#define BF2_OBJECTTEMPLATEMGR	"ObjectTemplateManager"
#define BF2_TEMPLATEMANAGER     "TemplateManager"
#define BF2_PLAYERMANAGER       "PlayerManager"
#define BF2_CONTROLMAPMANAGER	"ControlMapManager"
#define BF2_HUDMANAGER          "HudManager"
#define BF2_BASICPHYSICSSYS		"BasicPhysicsSystem"
#define BF2_DEBUGTEXTWRITER     "DebugTextWriter"
#define BF2_DEBUGLINEDRAWER     "DebugLineDrawer"
#define RENDDX9_RENDERER        "Renderer"
#define BF2_SPREADTABLE			"SpreadTable"
#define BF2_GAME				"Game"
#define BF2_PLAYER				"Player";
#define BF2_OBJECT				"Object";
#define BF2_HEALTH				"Health";
#define BF2_LOCALPROFILE		"LocalProfile";
#define BF2_SOLDIER				"Soldier";
#define BF2_SOLDIERPTR			"CSoldierPtr";
#define BF2_SPREADTABLE			"SpreadTable";
#define BF2_WEAPON				"Weapon";
#define BF2_DEVIATION			"Deviation";
#define BF2_GLOBALSETTINGS		"GlobalSettings";
#define BF2_DEBUGCIRCLEDRAWER	"DebugCircleDrawer";
#define BF2_DEBUGRENDERER		"DebugRenderer";
#define BF2_PostProductionFrameWork	"PostProductionFrameWork"
#define BF2_LOCALPROFILEMANAGER	"LocalProfileManager"
#define BF2_MATERIALMANAGER	    "MaterialManager"
#define BF2_NETWORKMANAGER      "NetworkManager"

//Class Offset Defines - BF2 1.50
#define BF2_CLASSMANAGER_OFFSET 0x09FF960
#define BF2_PLAYERMANAGER_OFFSET 0xA08F60
#define BF2_SPREADTABLE_OFFSET 0x9F4DB0
#define BF2_GAME_OFFSET 0x99E348
#define BF2_HUDMANAGER_OFFSET 0x9E0970
#define BF2_ACTIONBUFFER_OFFSET 0x06A47D0
#define BF2_GETPLAYERVIEW_OFFSET 0x05A4AE0
#define BF2_MAINCONSOLE_OFFSET 0x0A03010
#define RENDDX9_RENDERER_OFFSET 0x023D098

#define BF2_ACTIONBUFFER_VTABLE 13
#define BF2_GETPLAYERVIEW_VTABLE 4
#define BF2_ENDSCENE_VTABLE 0
#define BF2_DRAWINDEXPRIMITIVE 1
#define BF2_RESET 2
#define BF2_SETSTREAMSOURCE 3
#define BF2_SETRENDERSTATE 4
#define NOSPAMBLOCK_OFFSET 0x000E2AB8 //for chatmessage spamming

#define SPEEDHACK_W 0x57
#define SPEEDHACK_S 0x53
float SpeedModifier = 999999999.0f;

#define ES 0 //EndScene
#define DIP 1 //DrawIndexPrimitive
#define RES 2 //Reset
#define SSS 3 //SetStreamSource
#define SRS 4 //SetRenderState
#define PRS 5 //Present
#define BS 6 //BeginScene

#define ES_VTable 0
#define DIP_VTable 1
#define SSS_VTable 2
#define RES_VTable 3
#define BS_VTable 4
#define PRS_VTable 5
#define RNDSCRN_VTable 6

#define SMOOTH_FOV		0.75f
#define MAX_ANGLE_CHANGE D3DXToRadian(10.0f)

#define COVER_ANGLE		D3DXToRadian(30.0f)
#define COVER_ANGLE_TV	D3DXToRadian(25.0f)

#define MAX_ANGLE D3DXToRadian(MaxAimAngle)

//Colour Defines
#define d3dColorWhite D3DCOLOR_XRGB( 255, 255, 255 )
#define d3dColorSilver D3DCOLOR_XRGB( 200, 200, 200 )
#define d3dColorRed D3DCOLOR_XRGB( 255, 0, 0 )
#define d3dColorPink D3DCOLOR_XRGB( 255, 0, 255 )
#define d3dColorBlue D3DCOLOR_ARGB(155, 0, 0, 255 )
#define d3dColorYellow D3DCOLOR_XRGB( 255, 255, 0 )
#define d3dColorGreen D3DCOLOR_XRGB(0, 255, 0 )
#define d3dColorLightBlue D3DCOLOR_XRGB(0, 191, 255 )
#define d3dColorBlack D3DCOLOR_XRGB(0, 0, 0 )
#define d3dColorGrey D3DCOLOR_ARGB( 160 ,160, 160, 160 )
#define d3dColorOrange D3DCOLOR_XRGB(255, 128, 0)
#define d3dColorFuscia D3DCOLOR_XRGB(255, 151, 53)
#define d3dColorLightGreen D3DCOLOR_XRGB(51, 255, 51)
#define d3dColorCustom D3DCOLOR_XRGB(204, 204, 255)

//Weapon Defines
#define	Assault_Rifles 0 
#define Grenade_Launcher 1 
#define Carbines 2
#define Light_Machine_Guns 3 
#define Sniper_Rifles 4
#define Pistols 5 
#define AT_AA 6
#define Submachine_Guns 7
#define Shotguns 8
#define Knife 9
#define Defibrillator 10
#define Explosive_Weapon 11
#define Hand_Grenade 12


// the player input keys
#define PINumKeys			64

#define PIYaw				0 //X
#define PIPitch				1 //Y
#define PIRoll				2
#define PIThrottle			3
#define PIMouseLookX		4
#define PIMouseLookY		5
#define PICameraX			6
#define PICameraY			7
#define PIFire				8
#define PIAction			9
#define PIUse				10
#define PIMouseLook			11
#define PIAltSprint			12
#define PISprint			13
#define PIWeaponSelect1		14
#define PIWeaponSelect2		15
#define PIWeaponSelect3		16
#define PIWeaponSelect4		17
#define PIWeaponSelect5		18
#define PIWeaponSelect6		19
#define PIWeaponSelect7		20
#define PIWeaponSelect8		21
#define PIWeaponSelect9		22
#define PIPositionSelect1	23
#define PIPositionSelect2	24
#define PIPositionSelect3	25
#define PIPositionSelect4	26
#define PIPositionSelect5	27
#define PIPositionSelect6	28
#define PIPositionSelect7	29
#define PIPositionSelect8	30
#define PIAltFire			31
#define PIReload			32
#define PISelectFunc		33
#define PIDrop				34
#define PIToggleCameraMode	35
#define PIToggleCamera		36
#define PILie				37
#define PICrouch			38
#define PICameraMode1		39
#define PICameraMode2		40
#define PICameraMode3		41
#define PICameraMode4		42
#define PISelectPrimWeapon	43
#define PISelectSecWeapon	44
#define PIToggleWeapon		45
#define PIToggleFireRate	46
#define PIFlareFire			47
#define PIRadio1			48
#define PIRadio2			49
#define PIRadio3			50
#define PIRadio4			51
#define PIRadio5			52
#define PIRadio6			53
#define PIRadio7			54
#define PIRadio8			55
#define PIScreenShot		56
#define PIToolTip			57
#define PISayAll			58
#define PISayTeam			59
#define PINextItem			60
#define PIPrevItem			61
#define PICommunication		62
#define PIShowScoreBoard	63
#define PINone				64

// input devices
#define IDFAll			-1
#define IDFNone			00
#define IDFMouse		01
#define IDFKeyboard		02

// classes types
//#define TEMPLATE_FLOATINGBUNDLE_ID		0x9478
//#define TEMPLATE_SPRING_ID				0x9481
//#define TEMPLATE_FORCEOBJECT_ID			0x9489
#define TEMPLATE_ITEM_ID				0x9492
#define TEMPLATE_SIMPLEOBJECT_ID		0x947E

#define TEMPLATE_CAMERA_ID				0x9472
#define TEMPLATE_ENGINE_ID				0x9476
#define TEMPLATE_ROTATIONALBUNDLE_ID	0x947D
#define TEMPLATE_WING_ID				0x9483
#define TEMPLATE_FREECAMERA_ID			0x948B
#define TEMPLATE_OVERHEADCAMERA_ID		0x948C
#define TEMPLATE_SOLDIER_ID				0x9493
#define TEMPLATE_KIT_ID					0x9496
#define TEMPLATE_ITEMCONTAINER_ID		0x9499
#define TEMPLATE_ANTENNABUNDLE_ID		0x949C
#define TEMPLATE_ANTENNA_ID				0x949D
#define TEMPLATE_OBJECTSPAWNER_ID		0x94A1
#define TEMPLATE_KITPART_ID				0x94A3
#define TEMPLATE_SUPPLYDEPOT_ID			0x94A4
#define TEMPLATE_CONTROLPOINT_ID		0x94A5

#define TEMPLATE_LANDINGGEAR_ID			0x94AE
#define TEMPLATE_OBSTACLE_ID			0x94AF
#define TEMPLATE_TARGETOBJECT_ID		0x94BE
#define TEMPLATE_ROTOR_ID				0x94CB
#define TEMPLATE_GENERICFIREARM_ID		0x94D3
#define TEMPLATE_GENERICPROJECTILE_ID	0x9539
#define TEMPLATE_LADDER_ID				0x9C40
#define TEMPLATE_REMOTECONTROLEDOBJECT_ID	0x9C42
#define TEMPLATE_TURNABLEREMOTECONTROLEDOBJECT_ID	0x9C43
#define TEMPLATE_LADDERCONTAINER_ID		0x9C46
#define TEMPLATE_SUPPLYOBJECT_ID		0x9C47

#define TEMPLATE_PLAYERCONTROLOBJECT_ID	0xc4C2
#define TEMPLATE_DESTROYABLEOBJECT_ID	0xC4D0
#define TEMPLATE_DESTROYABLEWINDOWSBUNDLE_ID 0xC4DC
#define TEMPLATE_DESTROYABLEWINDOW_ID	0xC4DD
#define TEMPLATE_PARACHUTE_ID			0xC5A8

#define PHYSICS_DYNAMIC_NODE_ID			0xc422

#define COMPONENT_TOGGLECAMERA_ID		0x94E6
#define COMPONENT_AMMO_ID				0xC4F4
#define COMPONENT_DEVIATION_ID			0xC4FC
#define COMPONENT_FIRE_ID				0xC4F1
#define COMPONENT_RECOIL_ID				0xC4F8
#define COMPONENT_ANIMATION_ID			0xC504
#define COMPONENT_ZOOM_ID				0xC508
#define COMPONENT_TARGET_ID				0xC50C
#define COMPONENT_DETONATION_ID			0xC54F
#define COMPONENT_FOLLOW_ID				0xC55B

//Skeleton Bones
#define SKELETON_BONE_FOOTL		5
#define SKELETON_BONE_FOOTR		10
#define SKELETON_BONE_STOMACH	11
#define SKELETON_BONE_BREAST	12
#define SKELETON_BONE_HANDL		20
#define SKELETON_BONE_HANDR		35
#define SKELETON_BONE_NECK		47
#define SKELETON_BONE_CHIN		50
#define SKELETON_BONE_HEAD		56

#define OVERLAY_CONSOLE_ID1		0x13C70
#define OVERLAY_CONSOLE_ID2		0x13882
#define OVERLAY_HUD_ID1			0x13C88
#define OVERLAY_HUD_ID2			0x138A0
#define OVERLAY_DYNAMIC_ID1		0x13C90
#define OVERLAY_DYNAMIC_ID2		0x138A7

//==============================================================
//FLOATS
//==============================================================
float lag, iLag;
float Damage;
float ttl;
float pms;
float fRealDistance;
float fPlayerDistance;
float fPlayerDirection;
float fYawDegreeDifference;
float AddWidth, AddHeight, AddLeft, SubHeight, Distance;
float tHealth, vHealth; 
float AimAngle, posaim, negaim;
float projectile_speed;
float bullet_gravity;
float bullet_drop;
float bullet_delay;
float projectile_damage;
float knifedist = 5.0f;
float angle_x;
float angle_y;
float InputBuffer[64];
float EnemyNearbyDist = 10.0f;
float flAspect;
float AimDistance, BulletDelay, TimeToImpact;
float DebugHP;
float aCosX, aCosY, aCosZ;
float CosX, CosY, CosZ;
float aimX, aimY, aimZ;
float TVaimX, TVaimY, TVaimZ;
float movedx, movedy;
float mousex, mousey;
float GravityMultiplier;

float tvDistanceX;
float tvDistanceY;
float tvLength;

float AngleLength;
float HudMousePos;
float HudDist;
float maxdist = 99999.00f;

float vNoSpread = 1;

float test = 2.15f;

//float max_damage = gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Player_Weapon->Weapon_Template->w_damage;
//float lag = gPlayerManager->GetLocalPlayer()->Ping() / 1000.f;

//==============================================================
//BOOLS
//==============================================================
bool weapon_high_drop;
bool weapon_explosive;
bool weapon_high_damage;
bool MissileFired;
bool Ballistic;
bool grenade;
bool TargetLocked = false;
bool bGrabbedVP = false;
bool bInitOnce = true;
bool bInitFonts = true;
bool bInitLines = true;
bool bGetLocalPlayer;
bool LastFrameAimKey = false;  
bool bAntiShake = 0;
bool bNoSpread = 0;
bool AimKeyPressed = false;
bool bHookView = 0;
bool bHookObjectWrapper = 0;
bool hooked = false;
bool AimKeyReleased;
bool xokay = false;
bool Activated = false;
bool bReset = false;
bool d3dReset = false;
bool TargetAngle = false;
bool DrawMenu = false;
bool getESdevice = true;
bool getDIPdevice = true;
bool ViewDistance = false;
bool bBPanel = false;
bool AsusWallhack = false;


//==============================================================
//DWORDS
//==============================================================
DWORD dwWorldToScreen;
DWORD* pdwNewGameDevice;
DWORD VTable[7] = { 0 };
DWORD pActionBuffer;
DWORD dwRendBase = NULL;
DWORD dwBF2Base = NULL;
DWORD dwD3D9Base = NULL;
HMODULE dwD3D925Base = NULL;
HANDLE hand	= NULL;

//==============================================================
//INTS
//==============================================================
int mousedown = 0;
int buffthis;
int DrawDebugStuff = 0;
int debugmode = 0;
int DebugID;
int AimFOV = 30;//This being your aimbot fov
int HeadSize = 10; //Size of Circle for Player Skeleton Head
int TVID = -1;
int getonce = 0;

//Vehicle Object IDs
int USMCAttackHeli = 88366;
int USMCBuggy = 90169;
int USMCTank = 91895;
int CHINAAntiAir = 88593;

//Vehicle Types
int JEEP = hfe::world::VehicleType::VTJeep;
int TANK = hfe::world::VehicleType::VTTank;
int APC = hfe::world::VehicleType::VTAPC;
int HELI = hfe::world::VehicleType::VTHelicopter;
int AA = hfe::world::VehicleType::VTAntiAir;
int JET = hfe::world::VehicleType::VTPlane;
int BOAT = hfe::world::VehicleType::VTSea;

//Targeting Systems
int NoTargetSystem = hfe::world::TargetSystem::TSNone;
int TVGuidedMissile = hfe::world::TargetSystem::TSTVGuided;
int HeatSeeking = hfe::world::TargetSystem::TSHeatSeeking;
int LaserGuided = hfe::world::TargetSystem::TSLaserGuided;
int WireGuided = hfe::world::TargetSystem::TSWireGuided;
int Parabellic = hfe::world::TargetSystem::TSParabellic;
//Custom
int Artillery = 6;
int Explosive = 7;

//Player Kits/Classes
int SpecOps = hfe::world::PlayerKit::KTSpecialOps;
int Sniper = hfe::world::PlayerKit::KTSniper;
int Assault = hfe::world::PlayerKit::KTAssult;
int Support = hfe::world::PlayerKit::KTSuport;
int Engineer = hfe::world::PlayerKit::KTEngineer;
int Medic = hfe::world::PlayerKit::KTMedic;
int AntiTank = hfe::world::PlayerKit::KTAntiTank;

//Vehicle Category
int Land = hfe::world::VehicleCategory::VCLand;
int Sea = hfe::world::VehicleCategory::VCSea;
int Air = hfe::world::VehicleCategory::VCAir;
int Helicopter = hfe::world::VehicleCategory::VCHelicopter;
int NoCategory = hfe::world::VehicleCategory::VCNoVehicleCategory;

//Object Templates
int Ladder = world::ObjectTemplate::Ladder;
int Parachute = world::ObjectTemplate::Parachute;
int PlayerControlObject = world::ObjectTemplate::PlayerControlObject;

int AimButton;
int AimKey = 0x04;
int JetAimKey = 0x60;
int TVAimKey = 0x04;
int showmenu = 0;
int showdebug;
int restart = 1;
int drawaimfov;
int Stick2Target = 0;
int Stick2Player = 0;
int pSavedTarget; 
int nospread;
int BEST_ID;
int autoswitchtargets = 0;
int fullautoaim = 0;
int getviewmatrixaddress = 0;
int AutoStabPeople = 0;
int radaron;
int original_team = 0;
int playerclass;
int autoshoot = 0;
int targetid;
int locktarget = 0;
int remfog = 0;
int remtv = 0;
int drawmm = 0;
int unlockwep = 0;
int TVSavedTarget = 0;

int aimmode = 0;
int newaimmode = 0;
int xhairselect = 2;

int done_0 = 0;
int done_6 = 0;
int done_1 = 0;
int done_2 = 0;
int done_3 = 0;
int done_4 = 0;
int done_5 = 0;	
int done_7 = 0;
int done_8 = 0;
int done_9 = 0;

UINT Offset = 0;

//==============================================================
//D3DXVECTOR3
//==============================================================
D3DXVECTOR3 AimSpot, v3TempVec, ViewMatrix, ViewMatrixX, ViewMatrixY, ViewMatrixZ;
D3DXVECTOR3 ObjPos, vOutput, vAimVec;
D3DXVECTOR3 lVMX, lVMY, lVMZ, lORIGIN;
D3DXVECTOR3 VMX, VMY, VMZ;
D3DXVECTOR3 TVMX, TVMY, TVMZ;
D3DXVECTOR3 WepMatrix, WepMatrixX, WepMatrixY, WepMatrixZ;
D3DXVECTOR3 aimanglefov, EnemyW2SPos;
D3DXVECTOR3 vTargetAngles;
D3DXVECTOR3 EnemyPos, LocalPos, EnemyW2SVec3, LocalW2SVec3;
D3DXVECTOR3 aimtarget;
D3DXVECTOR3 tPlayerPosition;
D3DXVECTOR3 GetAimRight, GetAimUp, GetAimDir;
D3DXVECTOR3 vAimNormalize, vTargetPosition;
D3DXVECTOR3 PlayerSpeed;
D3DXVECTOR3 vMyHeadPosition;
D3DXVECTOR3 target_velocity_vec(0.0f, 0.0f, 0.0f);
D3DXVECTOR3 AimDist;
D3DXVECTOR3 VecDistance;
D3DXVECTOR3 AimVec;
D3DXVECTOR3 vMyMatrix[4];
D3DXVECTOR3 viewAxis[3];

//==============================================================
//D3DXMATRIX
//==============================================================
D3DXMATRIX g_NoShake_m;
D3DXMATRIX* playerviewmatrix;
D3DXMATRIX TempMatrix;
D3DXMATRIX* m_OriginalMatrix;
D3DXMATRIX  m_ModifiedMatrix;
D3DXMATRIX* PlayerViewMatrix; 
D3DXMATRIX* PlayerWeaponMatrix;

//==============================================================
//D3DXCOLOR
//==============================================================
D3DXCOLOR ESPCOLOR;
D3DCOLOR ESPColor;

//==============================================================
//Viewport
//==============================================================
D3DVIEWPORT9 Viewport;

//==============================================================
//CPLAYERS
//==============================================================
CPlayer* targetPlayer = NULL;
CPlayer* BestTarget = NULL;
CPlayer* retTarget;
CPlayer* Target = NULL;
CPlayer* TargetPlayer = NULL;
CPlayer* pRet = NULL;
CPlayer* TVTarget = NULL;
CPlayer* KnifeTarget = NULL;

//==============================================================
//LOG STUFF
//==============================================================
ofstream DebugLog;

//==============================================================
//LPDIRECT3D
//==============================================================
LPDIRECT3DVERTEXBUFFER9 Stream_Data;
LPDIRECT3DPIXELSHADER9 Green2, Red2, Blue2, Yellow2, Orange2, Purple2, Teal2, Pink2, Trans2;
IDirect3DTexture9* Primitive = NULL;

IDirect3D9* pDirect3DDevice;
D3DPRESENT_PARAMETERS m_PresentParam;
LPDIRECT3DTEXTURE9 pTexture;
LPD3DXSPRITE pSprite = NULL;
D3DXVECTOR3 vPos;

//==============================================================
//LPDIRECTINPUT
//==============================================================
//IDirectInputDevice8* DIMouse;
//DIMOUSESTATE mouseLastState;
//LPDIRECTINPUT8 DirectInput;

typedef HRESULT(WINAPI* tDirectInput8Create)(HINSTANCE, DWORD, REFIID, LPVOID , LPUNKNOWN);
tDirectInput8Create DirectInput8Create;


bool InitDirInput(HINSTANCE hinstance);
void DetectInput();
HRESULT hr;

//==============================================================
//HOOK STUFF
//==============================================================
typedef HRESULT(WINAPI* D3DXCreateFont_t)(LPDIRECT3DDEVICE9, INT, UINT, UINT, UINT, BOOL, DWORD, DWORD, DWORD, DWORD, LPCTSTR, ID3DXFont*);
D3DXCreateFont_t tpCreateFont;

typedef HRESULT(WINAPI* tBeginScene)(LPDIRECT3DDEVICE9 pDevice);
tBeginScene oBeginScene;

typedef HRESULT(WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;

typedef HRESULT(WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType, INT BaseVertexIndex, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive;

typedef HRESULT(WINAPI* tReset)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
tReset oReset;

typedef void (__stdcall* tRenderScreen)(void* a, void* b, void* c); //10
tRenderScreen oRenderScreen;

typedef void (__stdcall* tPresent)(int); //52 / 17
tPresent oPresent;

typedef void (__stdcall* tDrawOverlay)(void); //51 
tDrawOverlay oDrawOverlay;

DWORD dwGetActionBuffer;
DWORD dwGetPlayerView;
#define SAFE_RELEASE(obj) if(obj) { obj->Release(); obj = NULL; }

DWORD dwOriginalCOWFunctionOffset;
CObject* tmpObject;
int tmpType;
typedef map<CObject*,int> mapType;
mapType objectMap;

//==============================================================
//BLACK PB SS
//==============================================================
extern "C" void* _ReturnAddress(void);
void * _ReturnAddress(void);
#pragma intrinsic(_ReturnAddress)

typedef DWORD(__stdcall * GWTPID) (HWND, LPDWORD);
GWTPID pOrigGWTPID;

//==============================================================
//RANDOM
//==============================================================
std::string ENEMYWARNING = "ENEMY NEARBY";
const char *ENEMYCLOSEBY = ENEMYWARNING.c_str();
PBYTE dwGetViewMatrix;
char szClassManagerPatt[] = "\x89\x35\x99\x99\x99\x99\xFF\x15\x99\x99\x99\x99\x8B\x0D\x99\x99\x99\x99\x8B\x01";
char szClassManagerMask[] = "xx????xx????xx????xx";
HWND hWnd;
HHOOK mouseHook;
unsigned int g_uiStride = NULL; 
string VehHealth;
string str_class;
CPlayer* AimAtMe;

#define AIM_SMOOTH_FOV 0.75f
#define JET_SMOOTH_FOV 0.60f
#define AIMBOT_MAX_ANGLE_CHANGE D3DXToRadian(10.0f)
#define AIMBOT_COVER_ANGLE		D3DXToRadian(30.0f)
#define AIMBOT_COVER_ANGLE_TV	D3DXToRadian(25.0f)


HWND FocusedWindow;
HWND CurrentProcess;

DWORD D3DBaseVTable;
DWORD ResetHookStartAddress, ResetStartReturn;
DWORD ResetHookEndAddress, ResetEndReturn;

string drawthis = "TVOff";
string pixelx; 
string pixely;

//Time Viewer
char Timestruct[16] = "hh':'mm':'ss tt";      
char TimeString[25];     
bool Time;

char AimPredict[8];
char GravityMultiply[8];

char Test[4];

float patched_viewdist = 2.0f;
float original_viewdist = -1.0f;

//For Refresh(),etc
CWeapon* Weapon;
CObject* Vehicle;
CObject* Object;
CSoldier* Soldier;
CTemplate* ObjectTemplate;
CTemplate* WeaponTemplate;
CTemplate_GenericProjectile* AmmoTemplate;
int VehCategory;
int TemplateID;
int WTSystem;

int cp;
int cp2;

BYTE CROSSHAIR1(0x04); //Standard Crosshair
BYTE CROSSHAIR2(0x09); //Shotgun Crosshair
BYTE CROSSHAIR3(0x18); //AH1Z Pilot HUD Crosshair
BYTE CROSSHAIR4(0x1a); //AH1Z Gunner (Minigun) Crosshair
BYTE CROSSHAIR5(0x1c); //MI28 Pilot HUD Crosshair
BYTE CROSSHAIR6(0x24); //MI28 Gunner (Minigun) Crosshair
BYTE CROSSHAIR7(0x27); //Z10 Pilot HUD Crosshair
BYTE CROSSHAIR8(0x28); //Z10 Gunner (Minigun) Crosshair
BYTE CROSSHAIR9(0x17); //PLA-AA Crosshair
BYTE CROSSHAIR10(0x22); //US-AA Crosshair
BYTE CROSSHAIR11(0x35); //RedDot Crosshair
BYTE CROSSHAIR12(0x3B); //TOW Crosshair

//============================================================================================================
//Shader Stuff
//============================================================================================================
char ShaderAdd[] = "ps.1.0 def c0, 0.0f, 0.0f, 0.0f, 0.0f tex t0 add r0, c0, t0";

HRESULT CreateMyShader(IDirect3DDevice9 *pDevice, IDirect3DPixelShader9 **pShader, float red, float green, float blue, float alpha)
{
	ID3DXBuffer *MyBuffer = NULL;
	char MyShader[256];
	sprintf_s(MyShader, "ps.1.1\ndef c0, %f, %f, %f, %f\nmov r0,c0", red / 255, green / 255, blue / 255, alpha / 255);
	D3DXAssembleShader(MyShader, sizeof(MyShader), NULL, NULL, 0, &MyBuffer, NULL);
	if (FAILED(pDevice->CreatePixelShader((const DWORD*)MyBuffer->GetBufferPointer(), pShader)))return E_FAIL;
	return S_OK;
}

struct shaders
{
	IDirect3DPixelShader9 *PixelShader[12];
};

shaders sa;

//====================================================================================================================
//COLOUR BYTES START =================================================================================================
//====================================================================================================================
const BYTE bred[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00
};
const BYTE byellow[60] =
{
	0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x01
};
const BYTE bgreen[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00
};
const BYTE bblue[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00
};
const BYTE bpurple[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00
};
const BYTE bpink[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xFF, 0x00
};
const BYTE borange[58] = {
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA5, 0xFF, 0x00
};
const BYTE blightblue[60] =
{
	0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00
};
const BYTE bPURPLE[60] =
{
	0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
	0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x50, 0x10, 0x40, 0xD0, 0x20, 0xE1
};

//===============================================================================================================
//DXINIT FUNCTION
//===============================================================================================================
LRESULT CALLBACK MsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){ return DefWindowProc(hwnd, uMsg, wParam, lParam); }
void DX_Init(LPDIRECT3DDEVICE9* GameDevice)
{
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "DX", NULL };
	RegisterClassEx(&wc);
	hWnd = CreateWindow("DX", NULL, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, GetDesktopWindow(), NULL, wc.hInstance, NULL);
	LPDIRECT3D9 pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	//LPDIRECT3DDEVICE9 pd3dDevice;
	pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, GameDevice);
	//DWORD* pVTable = (DWORD*)pd3dDevice;
	//pVTable = (DWORD*)pVTable[0];
	//table[ES] = pVTable[42];
	//table[RES] = pVTable[16];
	//table[DIP] = pVTable[82];
	DestroyWindow(hWnd);
	//LogFile << "DX VTable Hooked" << endl;
}

//==================================================================================================================
//DI-INIT FUNCTION
//==================================================================================================================
bool InitDirInput(HINSTANCE hinstance)
{
	HMODULE dinputMod = GetModuleHandle("dinput8.dll");
	DirectInput8Create = (tDirectInput8Create)GetProcAddress(dinputMod, "DirectInput8Create");
	//Create DirectInput Object
	//hr = DirectInput8Create(GetModuleHandle("BF2.exe"),  DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&DirectInput, NULL);

	//Create InputDevice Object
	//hr = DirectInput->CreateDevice(GUID_SysMouse, &DIMouse, NULL);

	return true;
}


//====================================================================================================================
//Create Texture / Shader / Font Functions
//====================================================================================================================
LPDIRECT3DTEXTURE9 SPRITE_TEX;
LPDIRECT3DTEXTURE9 TexRed = NULL;
LPDIRECT3DTEXTURE9 TexYellow = NULL;
LPDIRECT3DTEXTURE9 TexGreen = NULL;
LPDIRECT3DTEXTURE9 TexBlue = NULL;
LPDIRECT3DTEXTURE9 TexPink = NULL;
LPDIRECT3DTEXTURE9 TexPurple = NULL;
LPDIRECT3DTEXTURE9 TexOrange = NULL;
LPDIRECT3DTEXTURE9 TexLB = NULL;

void InitStuff(/*IDirect3DDevice9 *pGameDevice*/)
{
	//Textures
	D3DXCreateTextureFromFileInMemory(pGameDevice, (LPCVOID)&bblue, sizeof(bblue), &TexBlue);
	D3DXCreateTextureFromFileInMemory(pGameDevice, (LPCVOID)&bgreen, sizeof(bgreen), &TexGreen);
	D3DXCreateTextureFromFileInMemory(pGameDevice, (LPCVOID)&bred, sizeof(bred), &TexRed);
	D3DXCreateTextureFromFileInMemory(pGameDevice, (LPCVOID)&byellow, sizeof(byellow), &TexYellow);
	D3DXCreateTextureFromFileInMemory(pGameDevice, (LPCVOID)&bpink, sizeof(bpink), &TexPink);
	D3DXCreateTextureFromFileInMemory(pGameDevice, (LPCVOID)&bpurple, sizeof(bpurple), &TexPurple);
	D3DXCreateTextureFromFileInMemory(pGameDevice, (LPCVOID)&borange, sizeof(borange), &TexOrange);
	D3DXCreateTextureFromFileInMemory(pGameDevice, (LPCVOID)&blightblue, sizeof(blightblue), &TexLB);
	LogFile << "=======================" << endl;
	LogFile << "Create Required Objects" << endl;
	LogFile << "=======================" << endl;
	LogFile << "Textures Created" << endl;

	//Sleep(200);

	//Shaders
	CreateMyShader(pGameDevice, &Blue2, 0, 0, 255, 255);//blue
	CreateMyShader(pGameDevice, &Green2, 0, 255, 0, 255);//green
	CreateMyShader(pGameDevice, &Red2, 255, 0, 0, 255);//red
	CreateMyShader(pGameDevice, &Yellow2, 255, 255, 0, 255);//yellow
	CreateMyShader(pGameDevice, &Orange2, 255, 128, 0, 255);//orange
	CreateMyShader(pGameDevice, &Purple2, 255, 0, 255, 255);//purple
	CreateMyShader(pGameDevice, &Pink2, 255, 51, 255, 255);//pink
	CreateMyShader(pGameDevice, &Teal2, 51, 255, 255, 255);//teal
	CreateMyShader(pGameDevice, &Trans2, 255, 255, 255, 255);//transparent
	LogFile << "Shaders Created" << endl;

	bInitOnce = false;
}

void InitWMFont()
{
	D3DXCreateFont(pGameDevice, 15, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "red", &WatermarkFont);
	LogFile << "Watermark Font Created" << endl;
}

void InitMenuFont()
{
	D3DXCreateFont(pGameDevice, 15, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "red", &pFont);
	LogFile << "Menu Font Created" << endl;
}

void InitWarningFont()
{
	D3DXCreateFont(pGameDevice, 30, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "red", &WarningFont);
	LogFile << "Alert Font Created" << endl;
	LogFile << endl;
}

void InitLines()
{
	D3DXCreateLine(pGameDevice, &skeletonLine);
	D3DXCreateLine(pGameDevice, &snapLine);
	D3DXCreateLine(pGameDevice, &boxLine);
	D3DXCreateLine(pGameDevice, &circleLine);
	D3DXCreateLine(pGameDevice, &menuLine);
	D3DXCreateLine(pGameDevice, &xLine);
	LogFile << "Lines Created" << endl;
	bInitLines = false;
}

//================================================================================================================
//MOUSE HOOK STUFF
//================================================================================================================
void MouseThread()
{
	while(true)
	{
		if(Activated == true) 
		{
			if(gHudManager)
			{
	            float X = gHudManager->HudMouse->MousePosX;
	            float Y = gHudManager->HudMouse->MousePosY;
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(30);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(20);
                Activated = (!Activated);
                //Sleep(100);
            }
        }
	}
}
//================================================================================================================
//SetLocalPlayer Function
//================================================================================================================
bool SetLocalPlayer(void)
{
	if (gPlayerManager && gPlayerManager->GetLocalPlayer() && gPlayerManager->GetLocalPlayer()->PlayerObj && gPlayerManager->GetLocalPlayer()->SoldierObj
		&& gPlayerManager->GetLocalPlayer()->PlayerObj->Ptr	&& gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr && gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Health
		&& gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Health->Health >= 1)
	{
		CPlayer* gMyPlayer = gPlayerManager->GetLocalPlayer();
		GET_XAXIS(&vMyMatrix[MATRIXX], &gMyPlayer->GetPlayerView()->Matrix);
		GET_YAXIS(&vMyMatrix[MATRIXY], &gMyPlayer->GetPlayerView()->Matrix);
		GET_ZAXIS(&vMyMatrix[MATRIXZ], &gMyPlayer->GetPlayerView()->Matrix);
		GET_ORIGIN(&vMyMatrix[ORIGIN], &gMyPlayer->GetPlayerView()->Matrix);
		return 1;
	}
	return 0;
}

//============================================================================================================
//Hook VTable Function
//============================================================================================================
DWORD HookVTable(PDWORD Class, DWORD function, int index)
{
	DWORD oldRights, newRights, oldAddress;
	if (!IsBadReadPtr(Class, 4))
	{
		DWORD* functionAddress = (DWORD*)((PDWORD)(*Class + (index * 4)));
		if (*functionAddress != function)
		{
			if (VirtualProtectEx(GetCurrentProcess(), functionAddress, 4, PAGE_EXECUTE_READWRITE, &oldRights))
			{
				oldAddress = *functionAddress;
				*functionAddress = (DWORD)function;
			}
			VirtualProtectEx(GetCurrentProcess(), functionAddress, 4, oldRights, &newRights);
		}
	}
	return oldAddress;
}

//================================================================================================================
//FindPattern Function
//================================================================================================================
DWORD FindPattern(DWORD start_offset, DWORD size, BYTE* pattern, char mask[])
{
	DWORD pos = 0;
	int searchLen = strlen(mask) - 1;

	for (DWORD retAddress = start_offset; retAddress < start_offset + size; retAddress++)
	{
		if (*(BYTE*)retAddress == pattern[pos] || mask[pos] == '?'){
			if (mask[pos + 1] == '\0')
				return (retAddress - searchLen);
			pos++;
		}
		else
			pos = 0;
	}
	return NULL;
}

//================================================================================================================
//getBFClassManager Function
//================================================================================================================
CClassManager* getBFClassManager(void) {
	HMODULE hModule = NULL;

	while (hModule == NULL) {
		hModule = GetModuleHandle("RendDx9.dll");
		if (hModule == NULL) Sleep(200);
	}

	DWORD dwInitDLL = (DWORD)GetProcAddress(hModule, "initDll");
	CloseHandle(hModule);

	if (dwInitDLL)    {
		DWORD dwPointerOffset = FindPattern(dwInitDLL, dwInitDLL + 512, (BYTE*)szClassManagerPatt, szClassManagerMask);
		if (dwPointerOffset)        {
			DWORD* ptr = (DWORD*)(dwPointerOffset + 2);
			return *((CClassManager**)((DWORD)*ptr));
		}
	}
	return 0;
}

//================================================================================================================
//GetModuleSize Function
//================================================================================================================
DWORD GetModuleSize(DWORD processID){
	HANDLE hSnap;
	MODULEENTRY32 xModule;
	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processID);
	xModule.dwSize = sizeof(MODULEENTRY32);
	if (Module32First(hSnap, &xModule)) {
		while (Module32Next(hSnap, &xModule)) {
			if (!strncmp((char*)xModule.szModule, "pbcl.dll", 8)){
				CloseHandle(hSnap);
				return (DWORD)xModule.modBaseSize;
			}
		}
	}
	CloseHandle(hSnap);
	return 0;
}

//================================================================================================================
//ActionBuffer Function + Hook
//================================================================================================================
CActionBuffer* hkGetActionBuffer()
{
	_asm call dwGetActionBuffer;
	_asm mov gActionBuffer, eax;
	_asm pushad;

	if (gActionBuffer)
	{
		for (int i = 0; i < 64; i++)
		{
			gActionBuffer->InputFlags[i] += InputBuffer[i];
			InputBuffer[i] = 0.0f;
		}
	}

	_asm popad;
	return gActionBuffer;
}

bool HookActionBuffer()
{
	if (gInputManager == 0)
		return false;

	size_t** vtable = (size_t**)gInputManager;

	DWORD oldp = 0;
	VirtualProtect((void*)((*vtable) + 13), 4, PAGE_EXECUTE_READWRITE, &oldp);

	dwGetActionBuffer = (*vtable)[13];
	(*vtable)[13] = (size_t)hkGetActionBuffer;

	if(dwGetActionBuffer)
	{
		LogFile << "==================" << endl;
		LogFile << "Action Buffer Hook" << endl;
		LogFile << "==================" << endl;
		LogFile << "Successful: " << (PDWORD)dwGetActionBuffer << endl;
		LogFile << endl;
	}

	return true;
}

//================================================================================================================
//Hook GetPlayerView FUNCTION
//================================================================================================================
D3DXMATRIX* WINAPI hkGetPlayerView(int iParam)
{
	_asm push iParam;
	_asm call dwGetPlayerView;
	_asm mov m_OriginalMatrix, eax;
	_asm pushad;

	if ((bAntiShake) && (m_OriginalMatrix) && (m_ModifiedMatrix) && (gPlayerManager->GetLocalPlayer()) && (gPlayerManager->GetLocalPlayer()->iAlive))
	{
		m_OriginalMatrix = &m_ModifiedMatrix; 
	}

	_asm popad;
	return m_OriginalMatrix;
}

DWORD VMTPatch(DWORD* dwClass, int iIndex, DWORD dwNewFunction)
{
	DWORD dwProtect = NULL;
	DWORD dwReturnAddress = NULL;
	DWORD dwOffset = (iIndex * 4);

	if (!iIndex) 
		dwOffset = 0x4;

	if (!VirtualProtect (dwClass, dwOffset, PAGE_READWRITE, &dwProtect))
		return FALSE;

	dwReturnAddress = dwClass[iIndex];
	dwClass[iIndex] = dwNewFunction;
	VirtualProtect(dwClass, dwOffset, dwProtect, &dwProtect);
	return dwReturnAddress;
}

//==============================================================================================================
//OBJECTWRAPPER HOOK
//==============================================================================================================
CObject* createObjectWrapper(int para1, int para2, int para3)
{
	_asm push para1;
	_asm push para2;
	_asm push para3;
	_asm call dwOriginalCOWFunctionOffset;
	_asm mov tmpObject, eax;
	_asm pushad;

	if(tmpObject)
	{
		tmpType = tmpObject->Obj_Template->GetTemplateType();
		if(tmpType == (int)TEMPLATE_GENERICPROJECTILE_ID)
			objectMap.insert( std::pair<CObject*,int>(tmpObject, tmpType) );
			//objectMap.insert(mapType::value_type(tmpObject, tmpType));
	}

	_asm popad;
	return tmpObject;
}

//================================================================================================================
//TEAMSWITCH FUNCTION
//================================================================================================================
void ApplyTeamSwitch(int i)
{
	if(gPlayerManager->GetLocalPlayer())
	{
		if(i == 1)
		{
			original_team = gPlayerManager->GetLocalPlayer()->iTeam;

			if(original_team == 1)
				gPlayerManager->GetLocalPlayer()->iTeam = 2;
			else
				gPlayerManager->GetLocalPlayer()->iTeam = 1;
		}
		else if(original_team)
		{
			gPlayerManager->GetLocalPlayer()->iTeam = original_team;
			original_team = 0;
		}
	}
}

//================================================================================================================
//iWrite Function
//================================================================================================================
BOOL iWrite(DWORD Address, void* Data, DWORD Length)
{
	DWORD Old = 0;
	VirtualProtect((void*)(Address), Length, PAGE_EXECUTE_READWRITE, &Old);
	memcpy((void*)Address, Data, Length);
	VirtualProtect((void*)(Address), Length, Old, &Old);
	return 0;
}

//================================================================================================================
//Memory Hacks
//================================================================================================================
//
const BYTE Nop2Bytes[2] = {0x90, 0x90};
//
//Remove / Restore Fog
void RemoveFOG(){
	if (done_0 == 0){
		iWrite((dwRendBase + 0x506F9), (PBYTE)"\xD9\x46\x05", 3);
		done_0 = 1;
	}
}
void RestoreFOG(){
	if (done_0 == 1){
		iWrite((dwRendBase + 0x506F9), (PBYTE)"\xD9\x46\x38", 3);
		done_0 = 0;
	}
}

//Remove / Restore TV Static
void RemoveTVStatic(){
	if(done_6 == 0){
		iWrite((dwBF2Base + 0x38B2A0), (PBYTE)"\x00", 1);
		done_6 = 1;
	}
}
void RestoreTVStatic(){
	if(done_6 == 1){
		iWrite((dwBF2Base + 0x38B2A0), (PBYTE)"\xA0", 1);
		done_6 = 0;
	}
}

//Enable / Disable Minimap
void MiniMapEnable(){
	if (done_4 == 0){
		iWrite(0x007786D9, (PBYTE)"\x74\x0C", 2);
		iWrite(0x007786FF, (PBYTE)"\x74\x0C", 2);
		iWrite(0x00778725, (PBYTE)"\x0F\x85", 2);
		iWrite(0x007787B5, (PBYTE)"\x74\x0C", 2);
		iWrite(0x007787DB, (PBYTE)"\x74\x09", 2);
		iWrite(0x007787FE, (PBYTE)"\x75\x46", 2);
		iWrite(0x007836F9, (PBYTE)"\x74\x06", 2);
		done_4 = 1;
	}
}
void MiniMapDisable(){
	if (done_4 == 1){
		iWrite(0x007786D9, (PBYTE)"\x75\x0C", 2);
		iWrite(0x007786FF, (PBYTE)"\x75\x0C", 2);
		iWrite(0x00778725, (PBYTE)"\x0F\x84", 2);
		iWrite(0x007787B5, (PBYTE)"\x75\x0C", 2);
		iWrite(0x007787DB, (PBYTE)"\x75\x09", 2);
		iWrite(0x007787FE, (PBYTE)"\x74\x46", 2);
		iWrite(0x007836F9, (PBYTE)"\x75\x06", 2);
		done_4 = 0;
	}
}

//Enable / Disable Weapon Unlocks
void WeaponUnlocksOn(){
	if (done_5 == 0){
		iWrite((0x468CBE), (PBYTE)"\x90\x90", 2);
		iWrite((0x5028C5), (PBYTE)"\x90\x90", 2);
		done_5 = 1;
	}
}
void WeaponUnlocksOff(){
	if (done_5 == 1){
		iWrite((0x468CBE), (PBYTE)"\x74\x07", 2);
		iWrite((0x5028C5), (PBYTE)"\x7C\x14", 2);
		done_5 = 0;
	}
}

//Enable / Disable 3DMap
void Enable3DMap() {
	if(done_2 == 0) {
		iWrite((dwRendBase + 0x12E73D), (PBYTE)"\x90\x90", 2);
		done_2 = 1;
	}
}
void Disable3DMap() {
	if(done_2 == 1) {
		iWrite((dwRendBase + 0x12E73D), (PBYTE)"\x75\x0E", 2);
		done_2 = 0;
	}
}

//Enable / Disable EnemyMines
void EnemyMinesOn() {
	if(done_3 == 0) {
		iWrite((dwRendBase + 0x12EA91), (PBYTE)"\x90\x90", 2);
		done_3 = 1;
	}
}
void EnemyMinesOff() {
	if(done_3 == 1) {
		iWrite((dwRendBase + 0x12EA91), (PBYTE)"\x75\x62", 2);
		done_3 = 0;
	}
}

//Enable / Disable RadarBridgeIcons
void RBIconsOn() {
	if(done_7 == 0) {
		iWrite((dwRendBase + 0x1309F9), (PBYTE)"\x90\x90", 2);
		done_7 = 1;
	}
}
void RBIconsOff() {
	if(done_7 == 1) {
		iWrite((dwRendBase + 0x1309F9), (PBYTE)"\x74\x4A", 2);
		done_7 = 0;
	}
}

//Enable / Disable FPS
void EnableDrawFPS(){
	if(done_1 == 0)	{
		gRenderer->drawFps = 1;
		done_1 = 1;
	}
}

void DisableDrawFPS(){
	if(done_1 == 1)	{
		gRenderer->drawFps = 0;
		done_1 = 0;
	}
}

//Enable/Disable ViewDistance
void ViewDistanceOn()
{
	if(ViewDistance == false)
	{
		if(gRenderer && gRenderer->ViewDistance)
		{
		    if(original_viewdist < 0.0f)
		    {
			    original_viewdist = gRenderer->ViewDistance;
		    }
		gRenderer->ViewDistance = maxdist;
		ViewDistance = true;
		}
	}
}
void ViewDistanceOff()
{
	if(ViewDistance == true)
	{
		if(gRenderer && gRenderer->ViewDistance)
		{
		    if(original_viewdist > 0.0f)
		    {
			    gRenderer->ViewDistance = original_viewdist;
		    }
			ViewDistance = false;
		}
	}
}

//Unlimited CommanderAssets 
void fPanelFullMaker()
{
	if(!gHudManager) return;
	if(gPlayerManager->GetLocalPlayer()->commander != 1) return;
	gHudManager->assets->ArtilleryLoading = gHudManager->assets->SuppliesLoading = 0;
	gHudManager->assets->CarsHealth = 1.0f;
	gHudManager->assets->CarsLoadTime = 0.0f;
	gHudManager->assets->ArtilleryReloadTime = 0.0f;
	gHudManager->assets->SuppliesReloadTime = 0.0f;
}

//Logger
void Logger()
{
	int IsPlayerConnected = *(int*)0x9F7D68;
	LogFile << "IsPlayerConnected - " << IsPlayerConnected << endl;
	//if(gHudManager)
	//{
		//gPlayerManager->GetLocalPlayer()->commander = (BYTE)0x01;

		//gHudManager->ResignCommander();

		//gPlayerManager->GetLocalPlayer()->Squad_Leader = (BYTE)0x00;
	//}
}
//==========================================================================================
//Intersect FUNCTION
//==========================================================================================
CObject* Intersect(CObject* pObject, D3DXVECTOR3* pRayStart, D3DXVECTOR3* pRayEnd)
{
	int iMaterial = NULL;
	CObject* pResult = NULL;
	D3DXVECTOR3 vInterpoint, vInterangle;

	CRayTest CRay(pObject);
	if (gObjectManager->Intersect(&pResult, &vInterpoint, &vInterangle, &iMaterial, pRayStart, pRayEnd, &CRay, 1, 0, 1, 0, 1))
		return pResult;

	return NULL;
}

//==========================================================================================
//WorldToMiniMap FUNCTION (Credits: Revolty)
//==========================================================================================
BOOL WorldToMap(D3DXVECTOR3* vecOut)
{
	if(!gHudManager || !gHudManager->minimap)
		return 0;
 
	CHudNode_MiniMap* pMap = gHudManager->minimap;
 
	FLOAT wx =  ((((1.0f / pMap->worldScaleX) * 0.5f) + vecOut->x) * pMap->worldScaleX + 0.5f);
	FLOAT wz = -((((1.0f / pMap->worldScaleZ) * 0.5f) + vecOut->z) * pMap->worldScaleZ + 0.5f);
 
	FLOAT sx = pMap->viewX + 400.0f + (pMap->viewW * 0.5f) + ((wx - floor(wx + 0.5f)) * pMap->viewW);
	FLOAT sy = pMap->viewY + 300.0f + (pMap->viewH * 0.5f) + ((wz - floor(wz + 0.5f)) * pMap->viewH); 
 
	if(!pMap->staticMap)
	{
		FLOAT cosAngle = cos(-pMap->rotation);
		FLOAT sinAngle = sin(-pMap->rotation);
 
		FLOAT dx = sx - (pMap->x + (pMap->width  * 0.5f));
		FLOAT dy = sy - (pMap->y + (pMap->height * 0.5f));
 
		sx = dx + ((cosAngle * dx) - (sinAngle * dy));
		sy = dy + ((sinAngle * dx) + (cosAngle * dy));
	}	
 
	if(pMap->width >= 512.0f)
	{
		if (sx < (pMap->x) || sx > (pMap->x + pMap->width)
		 || sy < (pMap->y) || sy > (pMap->y + pMap->height))
			return 0;
	}
	else {
		if(sqrt(pow((pMap->x + (pMap->width  * 0.5f)) - sx, 2) 
		       + pow((pMap->y + (pMap->height * 0.5f)) - sy, 2)) + 2.0f > (pMap->width * 0.5f))
		    return 0;
	}
 
	vecOut->x = (sx / 800.0f) * Viewport.Width;
	vecOut->y = (sy / 600.0f) * Viewport.Height;
 
	return TRUE;		
}

//==========================================================================================
//DRAW AIMBOT FOV CIRCLE FUNCTION
//==========================================================================================
void DrawABFOV()
{
	float CentX = (float)Viewport.Width / 2;
	float CentY = (float)Viewport.Height / 2;
	if(MaxAimAngle > 30) Circle(CentX, CentY, MaxAimAngle - 25, 360, d3dColorGreen);
	if(MaxAimAngle < 30) Circle(CentX, CentY, MaxAimAngle, 360, d3dColorGreen);
}

//============================================================================================================
//GetLocalBonePos Function
//============================================================================================================
bool GetLocalBonePos(D3DXVECTOR3* pOutput, int iBoneID, CPlayer* pTarget)
{
	D3DXMATRIX Matrix;

	if(!pTarget) return 0;
	if(!pTarget->SoldierObj) return 0;
	if(!pTarget->SoldierObj->Ptr) return 0;

	CSoldier* pSoldier = (CSoldier*)pTarget->SoldierObj->Ptr;

	if (!pSoldier) return 0;

	if (!IsBadReadPtr((void*) pSoldier->Skeleton_3P, 4))
	{
		Matrix = pSoldier->Skeleton_3P->matrices[iBoneID];
		D3DXMatrixMultiply(&Matrix, &Matrix, (D3DXMATRIX*) &pSoldier->Matrix);
		GET_ORIGIN(pOutput, &Matrix);
		return 1;
	}
	return 0;
}

//============================================================================================================
//GetBonePosition Function
//============================================================================================================
BOOL GetBonePos( CPlayer* Local, CPlayer* TargetPlayer, D3DXVECTOR3* output, INT BoneID )
{
	if((!TargetPlayer->SoldierObj) || (!TargetPlayer->SoldierObj->Ptr) || (!TargetPlayer->SoldierObj->Ptr->Skeleton_3P))
		return FALSE;
 
	D3DXMATRIX transformation = TargetPlayer->SoldierObj->Ptr->Skeleton_3P->matrices[BoneID];
	D3DXMatrixMultiply(&transformation, &transformation, &TargetPlayer->SoldierObj->Ptr->Matrix);
	GET_ORIGIN_FROMMATRIX(output, &transformation);

	return TRUE;
}

//============================================================================================================
//GetBoneOrigin Function
//============================================================================================================
D3DXVECTOR3* GetBoneOrigin(int boneNum, D3DXVECTOR3* pVecOut, CPlayer* target)
{    
    if(target == NULL) return FALSE;
    if(target->SoldierObj->Ptr == NULL) return FALSE;
    if(target->SoldierObj->Ptr->Matrix == NULL) return FALSE;
	if(target->SoldierObj->Ptr->Skeleton_3P == NULL) return FALSE;
 
    D3DXMATRIX transformation = target->SoldierObj->Ptr->Skeleton_3P->matrices[boneNum];
    D3DXMatrixMultiply(&transformation, &transformation, &target->SoldierObj->Ptr->Matrix);
 
    pVecOut->x = transformation._41;
    pVecOut->y = transformation._42; 
    pVecOut->z = transformation._43;
 
    return pVecOut;
}

//============================================================================================================
//IsPlayerVisible Function
//============================================================================================================
bool IsVisible(CPlayer* target, D3DXVECTOR3 *target_pos, D3DXVECTOR3 *player_pos)
{
	D3DXVECTOR3 vec_to_target, vec_to_player;
    D3DXVec3Subtract(&vec_to_target, target_pos, player_pos);
	D3DXVec3Subtract(&vec_to_player, player_pos, target_pos);

	if((!gPlayerManager) || (!gPlayerManager->GetLocalPlayer()) || (!gPlayerManager->GetLocalPlayer()->PlayerObj) || (!gPlayerManager->GetLocalPlayer()->PlayerObj->Ptr) || (!gPlayerManager->GetLocalPlayer()->PlayerObj->Ptr->Obj_Root))
		return false;

	CObject* player_object = gPlayerManager->GetLocalPlayer()->PlayerObj->Ptr->Obj_Root;
	CObject* target_object = target->PlayerObj->Ptr->Obj_Root;
	CRayTest raytest( player_object );
	CRayTest raytest2( target_object );
    D3DXVECTOR3 inter_point, inter_angle, inter_point2, inter_angle2;
    int material = 0;
	int material2 = 0;
    CObject* pObject = 0;
	CObject* pObject2 = 0;
    gObjectManager->Intersect(&pObject, &inter_point, &inter_angle, &material, player_pos, &vec_to_target, &raytest, TRUE, FALSE, TRUE, FALSE);
	gObjectManager->Intersect(&pObject2, &inter_point2, &inter_angle2, &material2, target_pos, &vec_to_player, &raytest2, TRUE, FALSE, TRUE, FALSE);

	if(pObject) pObject = pObject->Obj_Root;
	if(pObject2) pObject2 = pObject2->Obj_Root;

	CMaterial* ActMaterial = gMaterialManager->GetMaterial(material);
	CMaterial* ActMaterial2 = gMaterialManager->GetMaterial(material2);
	/*if(GetAsyncKeyState(0x56) & 0x8000)
	{
		LogFile << "========================================================= " << endl;
		if(!pObject) LogFile << "!pObject" << endl;
		if(!pObject2) LogFile << "!pObject2" << endl;
		if(pObject == pObject2) LogFile << "pObject = pObject2" << endl;
		LogFile << "TargetObjectTemplateType : " << (PDWORD)target_object->Obj_Template->GetTemplateType() << endl;
		LogFile << "TargetObjectTemplateName : " << target_object->Obj_Template->name << endl;
		LogFile << "PlayerObjectTemplateType : " << (PDWORD)player_object->Obj_Template->GetTemplateType() << endl;
		LogFile << "PlayerObjectTemplateName : " << player_object->Obj_Template->name << endl;
		if(target_object == pObject) LogFile << "target_object = pObject" << endl;
		if(player_object == pObject2) LogFile << "player_object = pObject2" << endl;
	    if(pObject)
		{			
			LogFile << "Object1TemplateType : " << (PDWORD)pObject->Obj_Template->GetTemplateType() << endl;
			LogFile << "Object1TemplateName : " << pObject->Obj_Template->name << endl;
			LogFile << "Material1: " << material << endl; // 1000,1006,16,26,29,33,30,1007,111,27,31,96,51,28,1003
	    }
		if(pObject2)
		{
			LogFile << "Object2TemplateType : " << (PDWORD)pObject2->Obj_Template->GetTemplateType() << endl;
			LogFile << "Object2TemplateName : " << pObject2->Obj_Template->name << endl;
		}
		LogFile << "Material1Name : " << ActMaterial->name << endl;//28,29,31,30,27,26
		LogFile << "Material2: " << material2 << endl;
		LogFile << "Material2Name : " << ActMaterial2->name << endl;
		LogFile << "========================================================= " << endl;
	}*/

	if((pObject != NULL) && (pObject2 != NULL) && (pObject == pObject2) && ((player_object == pObject2) || (target_object == pObject) ||
		((material == 0 || material == 1000 || material == 1006 
		|| material == 16 || material == 26 || material == 29 || material == 33 || material == 30 || material == 1007 || material == 111
		 || material == 27 || material == 31 || material == 96 || material == 51 || material == 28 || material == 1003) 
		  && (material2 == 0 || material2 == 1000 || material2 == 1006 || material2 == 16 || material2 == 26 || material2 == 29 || material2 == 33
		  || material2 == 30 || material2 == 1007 || material2 == 111 || material2 == 27 || material2 == 31 || material2 == 96 || material2 == 51
		  || material2 == 28 || material2 == 1003))) ) return true;
	else return ((pObject != NULL) && ((player_object == pObject2) || (target_object == pObject)));
}

//============================================================================================================
//WorldToScreen Function (Vector Location, Float ScreenX, Float ScreenY)
//============================================================================================================
bool World2Screen(D3DXVECTOR3 vWorldLocation, float fScreenX, float fScreenY)
{
    UINT iCenterX = Viewport.Width / 2;
    UINT iCenterY = Viewport.Height / 2;

    D3DXVECTOR3 vLocal, vTransForm;
    D3DXVECTOR3 vright, vup, vfwd, vorig;

	GET_ORIGIN_FROMMATRIX(&vorig, PlayerViewMatrix);
	GET_XAXIS_FROMMATRIX(&vright, PlayerViewMatrix);
	GET_YAXIS_FROMMATRIX(&vup, PlayerViewMatrix);
	GET_ZAXIS_FROMMATRIX(&vfwd, PlayerViewMatrix);

    D3DXVec3Subtract(&vLocal, &vWorldLocation, &vorig);
            
    vTransForm[0] = D3DXVec3Dot(&vLocal, &vright);
    vTransForm[1] = D3DXVec3Dot(&vLocal, &vup);
    vTransForm[2] = D3DXVec3Dot(&vLocal, &vfwd);

    if(vTransForm.z < 0.01) 
    {
        return 0;
    }

	if(fScreenX && fScreenY)
    {
		float LocalFOV = gPlayerManager->GetLocalPlayer()->Zoom;
		float FOVx10 = LocalFOV * 10;

		fScreenX = iCenterX / vTransForm[2] * ((1.333f + (0.3f / (LocalFOV * 10))) / LocalFOV);
		fScreenY = iCenterY / vTransForm[2] * ((1.333f + (0.3f / (LocalFOV * 10))) / (LocalFOV / 1.333f));

		vWorldLocation.x = iCenterX + fScreenX * vTransForm[0] ;
		vWorldLocation.y = iCenterY - fScreenY * vTransForm[1];
		vWorldLocation.z = vTransForm[2];
	}

    return  vTransForm.z > 0;
}  

//============================================================================================================
//WorldToScreen Function (Credits: Tetsuo Umezawas)
//============================================================================================================
D3DXVECTOR3* WorldToScreen(D3DXVECTOR3* out, D3DXVECTOR3* TargetPos)
{
	UINT screenxc, screenyc;
	D3DXVECTOR3 v3Difference, Dot, vOrigin, VRight, VUp, VForward;
	float angle_xzi, angle_yzi, playerfov;

	screenxc = Viewport.Width/2;
	screenyc = Viewport.Height/2;

	GET_XAXIS_FROMMATRIX(&VRight, PlayerViewMatrix);
	GET_YAXIS_FROMMATRIX(&VUp, PlayerViewMatrix);
	GET_ZAXIS_FROMMATRIX(&VForward, PlayerViewMatrix);
	GET_ORIGIN_FROMMATRIX(&vOrigin, PlayerViewMatrix);

	D3DXVec3Normalize(&v3Difference,D3DXVec3Subtract(&v3Difference, &vOrigin, TargetPos));

	Dot[0] = D3DXVec3Dot(&v3Difference, &VRight);
	Dot[1] = D3DXVec3Dot(&v3Difference, &VUp);
	Dot[2] = D3DXVec3Dot(&v3Difference, &VForward);

	playerfov = gPlayerManager->GetLocalPlayer()->Zoom;
	angle_xzi = screenxc / Dot[2] * ((1.333f+(0.3f/(playerfov*10)))/playerfov);
	angle_yzi = screenyc / Dot[2] * ((1.333f+(0.3f/(playerfov*10)))/(playerfov/1.333f));

	out->x = screenxc + angle_xzi * Dot[0] ;
	out->y = screenyc - angle_yzi * Dot[1];
	out->z = Dot[2];

	return out;
}

//============================================================================================================
//Game Engine WorldToScreen Function
//============================================================================================================
_declspec(naked) bool WINAPI gWorldToScreen(D3DXVECTOR3* pVecInOut)
{
	_asm mov ecx, gDebugTextWriter;
	_asm jmp[dwWorldToScreen];
}

//================================================================================================================
//IsValidPlayer Function
//================================================================================================================
bool IsValidPlayer(CPlayer* target){
	if ((target->SoldierObj) && (target->SoldierObj->Ptr) && (target->SoldierObj->Ptr->Health) && (target->SoldierObj->Ptr->Health->Health > 0))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

//================================================================================================================
//CompensateDeviation (No Spread) Function (Credits: SFAB1)
//================================================================================================================
void CompDev(D3DXVECTOR3* output)
{   
	D3DXVECTOR3 GetAimRight, GetAimUp, GetAimDir;

	if((!gPlayerManager) || (!gPlayerManager->GetLocalPlayer()) || (!gPlayerManager->GetLocalPlayer()->SoldierObj) || (!gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr) || (!gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Player_Weapon))
		return;

	//float fire_speed = gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Player_Weapon->Weapon_Template->w_velocity;
	float fire_speed = WeaponTemplate->w_velocity;
	static float * gSpreadTable = (float*)0x9F4DB0;

    CGameConfig* Counter = *((CGameConfig**)(DWORD)0x99E348);

    int FireMode = gPlayerManager->GetLocalPlayer()->Weapon_Firemode;
 
	UINT uiIndex;

    if(FireMode == 0)
		uiIndex = (Counter->GetFrameCount() + 2 ) & 0x3FF;
    else
		uiIndex = (Counter->GetFrameCount() + 1 ) & 0x3FF;

	CDeviation* cdev = gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Player_Weapon->Weapon_Deviation;

	if( cdev->m_Total > 0.0099999998f )
	{
	    float spread_up = (gSpreadTable[uiIndex] * (cdev->m_Total + cdev->m_Up));
        spread_up *= fire_speed * 0.0099999998f;
 
	    float spread_right = (gSpreadTable[(uiIndex + 1) % 1024] * (cdev->m_Total + cdev->m_Right));
        spread_right *= fire_speed * 0.0099999998f;

	    //GET_XAXIS_FROMMATRIX(&GetAimRight, &gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Player_Weapon->w_matrix);
	    //GET_YAXIS_FROMMATRIX(&GetAimUp, &gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Player_Weapon->w_matrix);
	    //GET_ZAXIS_FROMMATRIX(&GetAimDir, &gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Player_Weapon->w_matrix);
		GET_XAXIS_FROMMATRIX(&GetAimRight, PlayerViewMatrix);
	    GET_YAXIS_FROMMATRIX(&GetAimUp, PlayerViewMatrix);
	    GET_ZAXIS_FROMMATRIX(&GetAimDir, PlayerViewMatrix);
	
        D3DXVECTOR3 aimright(*&GetAimRight);
        aimright *= spread_right;

        D3DXVECTOR3 aimup(*&GetAimUp);
        aimup *= spread_up;
 
        D3DXVECTOR3 aimdir(*&GetAimDir);
        aimdir *= fire_speed;
        aimdir -= aimright;
        aimdir -= aimup;

        D3DXVec3Normalize(&aimdir ,&aimdir);
        *output += aimdir;
	}
}

//================================================================================================================
//AimCorrection Function (Credits: SpongeBobSP)
//================================================================================================================
D3DXVECTOR3 AimCorrection(D3DXVECTOR3 PlayerVelocity, D3DXVECTOR3 EnemyVelocity, D3DXVECTOR3 Output, float TargetDistance, float ProjectileSpeed, float ProjectileGravity)
{
	//For Sniper Prediction Add -> ProjectileSpeed = Projectile Speed / 3;
    Output = Output + ((EnemyVelocity * AimPrediction) * (lag + (TargetDistance / fabs(ProjectileSpeed))));
	Output = Output - (PlayerVelocity * (lag + (TargetDistance / fabs(ProjectileSpeed))));
	float m_grav = fabs(ProjectileGravity);
	float m_dist = TargetDistance / fabs(ProjectileSpeed);
	Output.y += GravityMultiplier * m_grav * m_dist * m_dist; //Drop Adjustment
	//Output.y += 0.5f * (14.730 * m_grav) * m_dist * m_dist; //Drop Adjustment
	//Output.x += 0.5 * EnemyVelocity.x * m_dist; // Lead Correction
	
	return Output;
}

//================================================================================================================
// Calculate the projectile trajectory & target trajectory
//================================================================================================================
inline double CalcFutureTargetPosition(double time, D3DXVECTOR3* proj_disp, D3DXVECTOR3* target_disp, D3DXVECTOR3* target_speed, D3DXVECTOR3* target_predict_point)
{
	*target_predict_point = (*target_disp - *proj_disp) + ( (*target_speed) * time );
	double dist_aim = D3DXVec3Length(target_predict_point);

	return dist_aim;
}

//================================================================================================================
//Calculate Ballistic Angle
//================================================================================================================
inline void CalculateBallisticAngle(double projectile_speed, double dist_aim, double time_to_live, double* aiming_height)
{
	double dy = *aiming_height;
	double dx2 = dist_aim * dist_aim - dy * dy;
	double dx = sqrt(dx2);
	double angle = acos(dx / (time_to_live * projectile_speed));
	*aiming_height += (tan(angle) * dx);
}

//================================================================================================================
//Calculate Ballistic Time
//================================================================================================================
inline 
double CalculateBallisticTime(double projectile_speed, double dist_aim, double* aiming_height)
{
	double dy = *aiming_height; //aiming_vector->y;
	double dx2 = dist_aim * dist_aim - dy * dy;
	double dx = sqrt(dx2);

	double g = -bullet_gravity;
	double v2 = projectile_speed * projectile_speed;

	double sq = v2 * v2 - g * (g * dx2 + 2.0 * dy * v2);

	//if(sq < 0.0) return FALSE;

	double angle = (M_PI_2 - atan( (v2 + sqrt(sq)) / (g * dx)));
	*aiming_height += (tan(angle) * dx);

	double tti = dx / (projectile_speed * cos(angle));
	return tti;
}

//================================================================================================================
//Calculate Missile Time
//================================================================================================================
inline double CalculateMissileTime(double projectile_speed, double dist_aim)
{
	double tti = dist_aim / projectile_speed;
	return tti;
}

//================================================================================================================
//Aimbot - TVMissile AutoClick Function
//================================================================================================================
void AutoClick()
{
	if(!gHudManager) return;
	float X = gHudManager->HudMouse->MousePosX;
	float Y = gHudManager->HudMouse->MousePosY;

    if(Activated == true) 
	{
       for(;;)
       {
           mouse_event(MOUSEEVENTF_LEFTDOWN, X, Y, 0, 0);
           mouse_event(MOUSEEVENTF_LEFTUP, X, Y, 0, 0);
           Activated = (!Activated);
           Sleep(100);
       }
    }
	return;
}

//================================================================================================================
//Aimbot - GetDistance2Enemy Function
//================================================================================================================
float GetDistanceToEnemy(CPlayer *pTargetPlayer)
{
    D3DXVECTOR3 lpos, playerpos;
    GET_ORIGIN_FROMMATRIX(&playerpos, &pTargetPlayer->PlayerObj->Ptr->Matrix);
	GET_ORIGIN_FROMMATRIX(&lpos, PlayerViewMatrix);
	D3DXVECTOR3 vdistancetotarget = playerpos - lpos;

    return D3DXVec3Length(&vdistancetotarget);
}

//================================================================================================================
//Aimbot - GetYDistance2Enemy Function
//================================================================================================================
float GetYDistance( CPlayer *pTarget, CPlayer *pLocal )
{
    float yLocal = pLocal->SoldierObj->Ptr->Matrix._42;
    float yEnemy = pTarget->SoldierObj->Ptr->Matrix._42;
    return yEnemy - yLocal;
}

//================================================================================================================
//Aimbot - GetXDistance2Enemy Function
//================================================================================================================
float GetXDistance( CPlayer *pTarget, CPlayer *pLocal )
{
    return sqrt(pow(GetDistanceToEnemy(pTarget), 2) - pow(GetYDistance(pTarget, pLocal), 2));
}  

//================================================================================================================
//Aimbot - Get2DDistance (CLOSEST2CROSSHAIR) Function
//================================================================================================================
float Get2DDistance(D3DXVECTOR3* pWorldPos)
{
	float flCenterX = -1;
	float flCenterY = -1;

	if(gWorldToScreen(pWorldPos))
	{
		flCenterX = Viewport.Width / 2 - pWorldPos->x;
		flCenterY = Viewport.Height / 2 - pWorldPos->y;
		return (float)sqrt(flCenterX * flCenterX + flCenterY * flCenterY);
	}
	return -1;
}

//================================================================================================================
//Aimbot - VectorAngles Function
//================================================================================================================
void VectorAngles( const float* forward, float* angles )
{
	float tmp, yaw, pitch;

	if(forward[2] == 0 && forward[0] == 0)
	{
		yaw = 0;

		if(forward[2] > 0)
			pitch = 90;
		else
			pitch = 270;
	}
	else 
	{
		yaw = (atan2(forward[2], -forward[0]) * 180 / M_PI)-90;

		if(yaw < 0)
			yaw += 360;

		tmp = sqrt(forward[0] * forward[0] + forward[2] * forward[2]);
		pitch = (atan2( forward[1], tmp) * 180 / M_PI);

		if(pitch < 0)
			pitch += 360;
	}

	angles[0] = -pitch;
	angles[1] = yaw;
	angles[2] = 0;
}

//================================================================================================================
//Aimbot - CorrectAimLead Function
//================================================================================================================
float CorrectAimLead(D3DXVECTOR3 enemyposition, D3DXVECTOR3 myposition, float Distance, float bulletSpeed, float bulletGravity)
{
	float altitude_diff = enemyposition.y - myposition.y;
	float angle, time, h; 

	for(;; angle += 0.001)
	{
		float Vx = cos(angle) * bulletSpeed;
		float Vy = sin(angle) * bulletSpeed;
		time = Distance / Vx;
		
		h = Vy * time + 0.5 * bulletGravity * pow(time, 2);
		if(h > altitude_diff)
			 break;
	}
	 
	for(;; angle -= 0.00001)
	{
		float Vx = cos(angle) * bulletSpeed;
		float Vy = sin(angle) * bulletSpeed;
		time = Distance / Vx;
		
		h = Vy * time + 0.5 * bulletGravity * pow(time, 2);
		if(h < altitude_diff)
			 break;
	}

	return h;
}

//================================================================================================================
//GetTargetDistance Function
//================================================================================================================
float GetTargetDistance(D3DXVECTOR3 targetPos, D3DXVECTOR3 localPos)
{
	float dx, dy;
	dx = targetPos.x - localPos.x;
	dy = targetPos.y - localPos.y;

	float Dist2Enemy = (float)sqrt(((float)dx * (float)dx) + ((float)dy * (float)dy));

	return Dist2Enemy;
}

//================================================================================================================
//Aimbot Math Function - AngleVectors
//================================================================================================================
void AngleVectors(const D3DXVECTOR3 angles, D3DXVECTOR3 right, D3DXVECTOR3 up, D3DXVECTOR3 forward)
{
    float angle;
    static float sr, sp, sy, cr, cp, cy;

    angle = angles[YAW] * (M_PI*2 / 360);
    sy = sin(angle);
    cy = cos(angle);

    angle = angles[PITCH] * (M_PI*2 / 360);
    sp = sin(angle);
    cp = cos(angle);
    
	angle = angles[ROLL] * (M_PI*2 / 360);
    sr = sin(angle);
    cr = cos(angle);

    if(forward)
    {
        forward[0] = cp*cy;
        forward[1] = cp*sy;
        forward[2] = -sp;
    }

    if(right)
    {
        right[0] = (-1*sr*sp*cy+-1*cr*-sy);
        right[1] = (-1*sr*sp*sy+-1*cr*cy);
        right[2] = -1*sr*cp;
    }

    if(up)
    {
        up[0] = (cr*sp*cy+-sr*-sy);
        up[1] = (cr*sp*sy+-sr*cy);
        up[2] = cr*cp;
    }
}

//================================================================================================================
//Aimbot - SoldierAngleToPix Function
//================================================================================================================
void SoldierAngleToPix( float* out_x, float* out_y, float angle_x, float angle_y )
{
	CControlMap* cmap = GetControlMap();

	float fov = gPlayerManager->GetLocalPlayer()->Camera->GetInsideFOV();
	float ms = cmap->mouse_sensitivity;

	float m;
	m = 1.1f / (fov * 5.0f * ms);

	*out_x = ((angle_x) * m / D3DXToRadian(cmap->DegreesPerPixelX));
	*out_y = -((angle_y) * m / D3DXToRadian(cmap->DegreesPerPixelY));
}

//================================================================================================================
//VecToAngles Function
//================================================================================================================
void VecToAngles(const D3DXVECTOR3 value1, D3DXVECTOR3 angles)
{
    float forward;
    float yaw, pitch;
    
    if( value1[1] == 0 && value1[0] == 0 )
    {
        yaw = 0;
        if ( value1[2] > 0 ) {
            pitch = 90;
        }
        else {
            pitch = 270;
        }
    }
    else
    {
        if( value1[0] ) 
        {
            yaw = ( atan2 ( value1[1], value1[0] ) * 180 / M_PI );
        }
        else if( value1[1] > 0 )
        {
            yaw = 90;
        }
        else 
        {
            yaw = 270;
        }
        if( yaw < 0 )
        {
            yaw += 360;
        }

        forward = sqrt( value1[0]*value1[0] + value1[1]*value1[1] );
        pitch =( atan2(value1[2], forward) * 180 / M_PI );
        if( pitch < 0 ) 
        {
            pitch += 360;
        }
    }

    angles[PITCH] = -pitch;
    angles[YAW] = yaw;
    angles[ROLL] = 0;
}

//================================================================================================================
//GetDistanceFromXHair Function
//================================================================================================================
float getDistFromCrosshair(CPlayer* pClosestSoldier)
{
    D3DXVECTOR3 screenM;
    D3DXVECTOR3 returningVector;
    if (IsValidPlayer(pClosestSoldier))
    {
        screenM.x = (float)Viewport.Width / 2;
        screenM.y = (float)Viewport.Height / 2;
        screenM.z = 0;

        D3DXVECTOR3 cloestSoldPos;
		GET_ORIGIN_FROMMATRIX(&cloestSoldPos, &pClosestSoldier->PlayerObj->Ptr->Matrix);

        if(gWorldToScreen(&cloestSoldPos))
        {
			returningVector.x = cloestSoldPos.x - screenM.x;
            returningVector.y = cloestSoldPos.y - screenM.y;
            returningVector.z = 0;
            float returndist = sqrtf((returningVector.x * returningVector.x) + (returningVector.y * returningVector.y));

            if (returndist < MaxAimAngle)
				return returndist;
         }
         else
         {
			return 10000.0f;
         }
    }
    return 10000.0f;
}  

//================================================================================================================
// ISJET FUNCTION
//================================================================================================================
BOOL isJET(int tempID)
{
	if(tempID == air_f35b || tempID == usair_f18 || tempID == usair_f15 || tempID == USAIR_F15_GuidedMissileController ||
		tempID == air_su30mkk || tempID == air_j10 || tempID == air_su30mkk_Gunner || tempID == air_su39 ||
		tempID == ruair_su34 || ruair_mig29 || ruair_su34_CoPilot) return TRUE;

	return FALSE;
}

//================================================================================================================
// ISHELI Function
//================================================================================================================
BOOL isHeli(int tempID)
{
	if(tempID == ahe_ah1z || tempID == usthe_uh60 || tempID == AHE_AH1Z_COgunner || tempID == USTHE_UH60_Left_Gunner || tempID == USTHE_UH60_Right_Gunner || tempID == USTHE_UH60_CoPilot
		|| tempID == USTHE_UH60_Passenger2 || tempID == ahe_z10 || tempID == chthe_z8 || tempID == AHE_Z10_COgunner || tempID == CHTHE_Z8_LLavett_CupolaBase || tempID == CHTHE_Z8_RLavett_CupolaBase
		|| tempID == chthe_z8_RPassenger || tempID == chthe_z8_LPassenger || tempID == chthe_z8_RearPassenger || tempID == ahe_havoc || tempID == the_mi17 || tempID == AHE_HAVOC_COgunner
		|| tempID == The_mi17_LLavett_CupolaBase || tempID == The_mi17_RLavett_CupolaBase || tempID == the_mi17_Cargo_Passenger_Left || tempID == the_mi17_Cargo_Passenger_Right
		|| tempID == the_mi17_Cargo_Passenger_Middle) return TRUE;

	return FALSE;
}

//================================================================================================================
// ISAIRVEHICLE FUNCTION
//================================================================================================================
BOOL isAirVeh(int tempID)
{
	if( isJET(tempID) || isHeli(tempID)) return TRUE;

	return FALSE;
}

//================================================================================================================
//Is Using GernadeLN
//================================================================================================================
bool IsUsingGernadeLN(CPlayer* LocalPlayer)
{
	if( (LocalPlayer->PlayerObj != 0)
		&& (Soldier != 0)
		&& (LocalPlayer->InVehicle == 1)
		&& (LocalPlayer->Kit == 2)
		&& (Soldier->Current_Weapon_Slot == 4) )
		return true;
	else return false;
}

//================================================================================================================
//Is Using Gernade
//================================================================================================================
bool IsUsingGernade(CPlayer* LocalPlayer)
{
	if( (LocalPlayer->PlayerObj != 0)
		&& (Soldier != 0)
		&& (LocalPlayer->InVehicle == 1)
		&& (LocalPlayer->Kit != 2)
		&& (LocalPlayer->Kit != 6)
		&& (Soldier->Current_Weapon_Slot == 4) )
		return true;
	else return false;
}

//================================================================================================================
//Is Using Tank Cannon
//================================================================================================================
bool IsUsingTankCN(CPlayer* LocalPlayer)
{
	int TemplateID = LocalPlayer->PlayerObj->Ptr->Obj_Template->TemplateID;
	if( (LocalPlayer->PlayerObj != 0)
		&& (Soldier != 0)
		&& (LocalPlayer->InVehicle == 2)
		&& (TemplateID == ustnk_m1a2 || TemplateID == tnk_type98 || TemplateID == rutnk_t90)
		&& (!LocalPlayer->secondary_fire_down))
		return true;
	else return false;
}

//=============================================================================================================================
//RefreshInfo Function (Source: BlackOmega)
//=============================================================================================================================
BOOL Refresh()
{
	CWeapon* Cur_Weapon;
	CPlayer* pLocalPlayer = (CPlayer*)gPlayerManager->GetLocalPlayer(); 

	if(!pLocalPlayer || !IsValidPlayer(pLocalPlayer) || pLocalPlayer->PlayerSeat < 0)
		return FALSE;

	if(Object != pLocalPlayer->PlayerObj->Ptr)
	{

		Vehicle = 0;
		Soldier = 0;

		Object = pLocalPlayer->PlayerObj->Ptr;
		VehCategory = Object->Obj_Template->VehicleCategory;
		TemplateID = Object->Obj_Template->TemplateID;

		switch(Object->Obj_Template->GetTemplateType())
		{
			case TEMPLATE_SOLDIER_ID:
				Soldier = pLocalPlayer->SoldierObj->Ptr;
				break;

			case TEMPLATE_PARACHUTE_ID:
				Vehicle = Object;
				assert( Vehicle->Obj_SoldierPtr && Vehicle->Obj_SoldierPtr->Object );

				if(!Vehicle->Obj_SoldierPtr || !Vehicle->Obj_SoldierPtr->Ptr)
					return FALSE;
				Soldier = Vehicle->Obj_SoldierPtr->Ptr;
				assert(Soldier && Soldier->Obj_Template->GetTemplateType() == TEMPLATE_SOLDIER_ID);
				Vehicle = 0;
				//Object = Soldier;
				break;

			case TEMPLATE_PLAYERCONTROLOBJECT_ID:
				Vehicle = Object;
				assert( Vehicle->Obj_SoldierPtr && Vehicle->Obj_SoldierPtr->Object );

				if(!Vehicle->Obj_SoldierPtr || !Vehicle->Obj_SoldierPtr->Ptr)
					return FALSE;
				Soldier = Vehicle->Obj_SoldierPtr->Ptr;
				assert(Soldier && Soldier->Obj_Template->GetTemplateType() == TEMPLATE_SOLDIER_ID);
				break;

			default:
				Object = 0;
				Soldier = 0;
				Weapon = 0;
				return FALSE;
		}
	}

	if(Object == Vehicle)
	{
		if(pLocalPlayer->secondary_fire_down && Vehicle->Obj_SecondaryWeapon)
			Cur_Weapon = Vehicle->Obj_SecondaryWeapon;
		else if(Vehicle->Obj_PrimaryWeapon)
			Cur_Weapon = Vehicle->Obj_PrimaryWeapon;
		else if(Soldier) Cur_Weapon = Soldier->Player_Weapon;
		else Cur_Weapon = 0;
	}
	else Cur_Weapon = Soldier->Player_Weapon;

	if(!Cur_Weapon || !Cur_Weapon->Weapon_Template)
		return FALSE;

	if(Cur_Weapon != Weapon)
	{
		Weapon = Cur_Weapon;

		WeaponTemplate = Weapon->Weapon_Template;
		AmmoTemplate = WeaponTemplate->projectile_template;

		if(!AmmoTemplate) return FALSE;
		Damage = AmmoTemplate->damage;

		CComponent_LPTargetComp* Weapon_TS = (CComponent_LPTargetComp*) WeaponTemplate->getComponent(COMPONENT_TARGET_ID);
		if(Weapon_TS)
		{
			WTSystem = Weapon_TS->targetSystem;
		}
		else
		{
			WTSystem = NoTargetSystem;
		}

		if(gPhysicsManager) bullet_gravity = gPhysicsManager->gravity * WeaponTemplate->w_gravitymodifier;
		else bullet_gravity = 0.0f;

		ttl = AmmoTemplate->timeToLive_1;
		if(ttl > 1.0f) ttl = 1.0f;
		
	    if(WTSystem == TVGuidedMissile) newaimmode = 1;
		else if(VehCategory == Air && WTSystem != LaserGuided && ((TemplateID != (int)USAIR_F15_GuidedMissileController) && (TemplateID != (int)ruair_su34_CoPilot) && 
			(TemplateID != (int)air_su30mkk_Gunner)) ) newaimmode = 2;
		else newaimmode = 0;

	}

	//if(pLocalPlayer->InVehicle == 2 || (IsUsingGernadeLN(pLocalPlayer) || IsUsingGernade(pLocalPlayer))) TAimbone = SKELETON_BONE_STOMACH;
	//else TAimbone = Aimbone;

	if(Item45 && pLocalPlayer->InVehicle == 2) lag = (float)pLocalPlayer->iPing / 1000.f;
	else lag = 0.0f;

	//For Free-Style Raging Mode
	if(Item14)
	{
		if(pLocalPlayer->Zoom > 1.0f && pLocalPlayer->InVehicle == 1 && pLocalPlayer->Sprinting == 0)
		{
			Sleep(25);
			InputBuffer[PIAltFire] = 1.0f;
			if(pLocalPlayer->Zoom > 1.0f)
				return FALSE;
		}
	
		if(pLocalPlayer->Weapon_Ammo == 0 && pLocalPlayer->Weapon_Mags == 1) 
			return FALSE;
	}

	return TRUE;
}

//============================================================================================================================
//AIMBOT MATHS FUNCTION - CALCULATEAIMVECTOR  (Source: BlackOmega)
//============================================================================================================================
BOOL CalculateAimVector(D3DXVECTOR3* target_position, CPhysics* pn)
{
	CPlayer* pLocalPlayer = (CPlayer*)gPlayerManager->GetLocalPlayer(); 
	D3DXVECTOR3 ClientVelocity = pLocalPlayer->SoldierObj->Ptr->Obj_Physics->Speed;
	bool missilefired;

	D3DXVECTOR3 target_velocity_vec(0.0f, 0.0f, 0.0f);
	if(pn)
	{
		target_velocity_vec = pn->Speed;
	}

	float projectile_speed = WeaponTemplate->w_velocity;

	D3DXVECTOR3* local_origin = &vMyMatrix[ORIGIN];
	D3DXVECTOR3 projectile_position( *local_origin );

	if(WTSystem == TVGuidedMissile || WTSystem == LaserGuided || WTSystem == WireGuided)
	{
		missilefired = true;
	}
	else missilefired = false;

	D3DXVECTOR3 aiming_vector = (*target_position - projectile_position);

	double dist_aim = D3DXVec3Length(&aiming_vector);

	double time_to_impact = dist_aim / projectile_speed;

	double tti1 = 0.0;
	double tti2 = (double)ttl;

	bool grenade = IsUsingGernade(pLocalPlayer);

	int count = 0;
	bool ballistic = ((WTSystem == NoTargetSystem) || (WTSystem == Parabellic));
	double height, dist;

	do
	{
		dist = CalcFutureTargetPosition( time_to_impact, &projectile_position, 
												target_position, &target_velocity_vec,
												&aiming_vector);
		height = (double)aiming_vector.y;
		double time_to_impact2;
		if (ballistic)
			time_to_impact2 = CalculateBallisticTime(projectile_speed, dist, &height);
		else
			time_to_impact2 = CalculateMissileTime(projectile_speed, dist);


		double diff = time_to_impact - time_to_impact2;
		// diff near zero means: at certain TTL, they impact together
		if (fabs(diff) < 0.0001) // 1/10000 game unit
			break;

		// projectile haven't reach target, must increase tti value
		if (diff < 0.0)
		{
			tti1 = time_to_impact;
			time_to_impact = (time_to_impact + tti2) * 0.5;
		}
		else // projectile overflown target, must decrease TTI
		{
			tti2 = time_to_impact;
			time_to_impact = (time_to_impact + tti1) * 0.5;
		}
	} while (++count < 16); // avoid infinite loop OR too long calculation

	if (ballistic)
	{
		if (grenade)
		{
			// for hand grenade, move target forward a little bit ~ 1m
			height = (double)aiming_vector.y;
			CalculateBallisticTime(projectile_speed, dist -1.0, &height);
			//CalculateBallisticAngle(projectile_speed, dist -1.5, time_to_impact, &height);
		}
		
		// height correction
		/*(double)*/aiming_vector.y = (float)height;
	}

	aiming_vector += (target_velocity_vec * (lag + (float)time_to_impact));

	if (missilefired == false)
	{
		// projectile firing platform is also moving. So, we have to compensate
		//*target_position -= (*local_info.GetMovementSpeed()) * (local_info.GetLag() + (float)time_to_impact);
		aiming_vector -= (ClientVelocity * (lag + (float)time_to_impact));
	}

	D3DXVec3Normalize(&aiming_vector, &aiming_vector);
	*target_position = (D3DVECTOR)aiming_vector;

	return TRUE;
}

//============================================================================================================================
//AIMBOT MATHS - CALCULATE BULLET FUNCTION
//============================================================================================================================
BOOL CalculateBullet(D3DXVECTOR3* aim_pos, CPhysics* pn)
{
	D3DXVECTOR3 local_origin;
	GET_ORIGIN_FROMMATRIX(&local_origin, PlayerViewMatrix);

	float projectile_speed = WeaponTemplate->w_velocity;

	if(MissileFired == true)
	{
		CObject_Projectile* op = 0;

		if((Weapon->Weapon_Target->TargetProjectilePtr) && (WTSystem != HeatSeeking))
		{
			op = Weapon->Weapon_Target->TargetProjectilePtr->Ptr;
		}

		if(op != 0)
		{
			//Special case: Tow/Eryx projectile has in-fly position
			if(WTSystem != TVGuidedMissile)
			{
				GET_ORIGIN_FROMMATRIX(&local_origin, &op->Matrix);
			}
			projectile_speed = D3DXVec3Length(&op->Obj_Physics->Speed);
			if(projectile_speed == 0.0f) 
				projectile_speed = (float)WeaponTemplate->projectile_template->maxSpeed;
		}
		else
		{
		    //For GenericProjectile, Velocity is returned from ProjectileTemplate
			projectile_speed = (float)WeaponTemplate->projectile_template->maxSpeed;
		}

		//This is needed to compensate for HitReg deception in Bf2 for missile projectiles
		projectile_speed = projectile_speed * 1.22799999f;
	}

	D3DXVECTOR3 target_predict_point = *aim_pos - local_origin;

	float Tdist_aim = D3DXVec3Length(&target_predict_point);
		
	float timeToImpact = Tdist_aim / projectile_speed;

	D3DXVECTOR3 vTargetVelocity(0.0f, 0.0f, 0.0f);

	if(pn)
	{
		vTargetVelocity = pn->Speed;
	}

	target_predict_point += (vTargetVelocity * timeToImpact);

	float dist_aim = D3DXVec3Length(&(target_predict_point));

	if(grenade)
	{
		// For hand grenade, move target forward a little bit ~ 1m
		dist_aim = dist_aim - 1.0f;
	}

	if(Ballistic)
	{
		float dy = target_predict_point.y;
		float dx2 = dist_aim * dist_aim - dy * dy;
		float dx = sqrtf(dx2);

		float g = - bullet_gravity;

		float v2 = projectile_speed * projectile_speed;

		float sq = v2 * v2 - g * (g * dx2 + 2.0f * dy * v2);

		if(sq < 0.0f) return FALSE;

		float angle = M_PI_2 - atan( (v2 + sqrtf(sq)) / (g * dx));

		bullet_drop = tanf(angle) * dx;
		bullet_delay = dx / (projectile_speed * cosf(angle));
	}
	else
	{
		bullet_drop = 0.0f;
		bullet_delay = dist_aim / projectile_speed;
	}

	return TRUE;
}

//============================================================================================================================
//AIMBOT MATHS - GETAIMVECTOR FUNCTION
//============================================================================================================================
BOOL GetAimVector(D3DXVECTOR3* output, CPlayer* TargetPlayer)
{
	CPlayer* pLocalPlayer = (CPlayer*)gPlayerManager->GetLocalPlayer(); 

	CPhysics* ClientPN = pLocalPlayer->SoldierObj->Ptr->Obj_Physics;
	CPhysics* TargetPN = TargetPlayer->SoldierObj->Ptr->Obj_Physics;

	D3DXVECTOR3 ClientVelocity;
	D3DXVECTOR3 ClientRotation(0.0f, 0.0f, 0.0f);

	D3DXVECTOR3 TargetVelocity;
	D3DXVECTOR3 TargetRotation(0.0f, 0.0f, 0.0f);

	if(pLocalPlayer->InVehicle == 2)
		ClientRotation = ClientPN->Rotation;

	if(TargetPlayer->InVehicle == 2)
		TargetRotation = TargetPN->Rotation;

	D3DXVECTOR3 lPlayerPos;
	GET_ORIGIN_FROMMATRIX(&lPlayerPos, PlayerViewMatrix);

	ClientVelocity = (ClientPN->Speed + ClientRotation);

	if(WTSystem == TVGuidedMissile || WTSystem == LaserGuided || WTSystem == WireGuided || WTSystem == HeatSeeking)
	{
		MissileFired = true;
	}
	else MissileFired = false;

	Ballistic = ((WTSystem == NoTargetSystem) || (WTSystem == Parabellic));
	grenade = IsUsingGernade(pLocalPlayer);

	if(!CalculateBullet(output, TargetPN))
		return FALSE;

	if(Ballistic)
	{
	    //Compensate the bullet drop
	    output->y += bullet_drop;
	}

	if(TargetPN)
	{
		TargetVelocity = (TargetPN->Speed + TargetRotation);
	}

	// Correction for target's dislocation
	*output += (TargetVelocity * AimPrediction) * (lag + bullet_delay);

	//And for local's dislocation
	if(MissileFired == false)
	{
		*output -= ClientVelocity * (lag + bullet_delay);
	}

	D3DXVec3Normalize( output, D3DXVec3Subtract(output, output, &lPlayerPos) );
}

//================================================================================================================
//AIMBOT - GETAIMBONE FUNCTION
//================================================================================================================
BOOL GetAimBone(CPlayer* LocalPlayer, CPlayer* TargetPlayer, D3DXVECTOR3* retPos)
{
	if((!TargetPlayer) || (!TargetPlayer->SoldierObj) || (!TargetPlayer->SoldierObj->Ptr) || (!TargetPlayer->SoldierObj->Ptr->Skeleton_3P))
		return FALSE;

	// On Foot
	if(TargetPlayer->InVehicle == 1)
	{
		if(WTSystem == NoTargetSystem)
		{
			if(!GetBonePos(LocalPlayer, TargetPlayer, retPos, Aimbone))
				return FALSE;
		}
		else
		{
			if(!GetBonePos(LocalPlayer, TargetPlayer, retPos, SKELETON_BONE_STOMACH))
				return FALSE;
		}
	}
	// On Vehicle
	else
	{
		//M95 Damage - 190.0f
		if((Damage >= 190.0f) && (!GetBonePos(LocalPlayer, TargetPlayer, retPos, SKELETON_BONE_HEAD)) )
		{
			GET_ORIGIN(retPos, &TargetPlayer->PlayerObj->Ptr->Matrix);
		}
		else if(Damage < 190.0f)
			return FALSE;
	}

	return TRUE;
}

//================================================================================================================
//Aimbot - GetClosestTarget2XHair Function (Credits: SkyMaster1980)
//================================================================================================================
BOOL ClosestToCrosshair(int iAimAt)
{
	CPlayer* pLocalPlayer = (CPlayer*)gPlayerManager->GetLocalPlayer(); 
    float fNearest = (float)INT_MAX;
    D3DXVECTOR3 lPlayerPos, tPlayerPos;
    GET_ORIGIN_FROMMATRIX(&lPlayerPos, PlayerViewMatrix);

	for (int i = 0; i < 255; i++)
	{
		CPlayer* TargetPlayer = (CPlayer*)gPlayerManager->GetPlayerByIndex(i);

		if((!TargetPlayer) || (TargetPlayer == pLocalPlayer))
			continue;

		if(!IsValidPlayer(TargetPlayer))
			continue;

		if(TargetPlayer->iTeam == pLocalPlayer->iTeam)
			continue;

		if(!GetBonePos(pLocalPlayer, TargetPlayer, &tPlayerPos, Aimbone))
		{
		     GET_ORIGIN(&tPlayerPos, &TargetPlayer->PlayerObj->Ptr->Matrix);
		}

		if(!gWorldToScreen(&tPlayerPos) && !Item14)
			continue;

		if(!IsVisible(TargetPlayer, &tPlayerPos, &lPlayerPos))
			continue;

		if(pLocalPlayer->InVehicle == 1)
		{
			if(TargetPlayer->InVehicle == 2)
			{
				if(WTSystem != WireGuided)
				{
					if(!Item41)
						continue;	
				}
			}
		}

		if(Item39 && !Item14)
		{
			float returndist = getDistFromCrosshair(TargetPlayer);
			if(returndist > MaxAimAngle)
				continue;
		}

		D3DXVECTOR3 Pos = (tPlayerPos - lPlayerPos);
		float AimDistance = D3DXVec3Length(&Pos);
					
		if(AimDistance > MaxAimDistance)
			continue;

		float cosX = D3DXVec3Dot(&Pos, &vMyMatrix[MATRIXX]);
        float cosY = D3DXVec3Dot(&Pos, &vMyMatrix[MATRIXY]);

		float Dist = sqrt((cosX * cosX) + (cosY * cosY));
		if(Dist > fNearest) continue;

		if(Dist < fNearest)
		{
			fNearest = Dist;
			iAimAt = i;
		}
	}

	return TRUE;
}


//================================================================================================================
//GetTarget Function
//================================================================================================================
CPlayer* GetTarget()
{
	D3DXVECTOR3 vOut, lPlayerPos, TargetDirection, lViewOrigin, vTargetAngles, tPlayerPos, tPlayerPosOnScreen, screenM, ReturnVec;
	CPlayer* pLocalPlayer = (CPlayer*)gPlayerManager->GetLocalPlayer(); 

	float fNearest = (float)INT_MAX;

   	if(!pLocalPlayer)
       	return 0; 

	if(!IsValidPlayer(pLocalPlayer))
		return 0;

	if(!Refresh())
		return 0;

	if(newaimmode != aimmode)
	{
		aimmode = newaimmode;
		return 0;
	}

	GET_ORIGIN_FROMMATRIX(&lPlayerPos, PlayerViewMatrix);

	if(LastFrameAimKey == false)
	{
		for(int i = 0; i < 255; i++)
		{
			CPlayer* tPlayer = gPlayerManager->GetPlayerByIndex(i); 
			
			if((!tPlayer) || (tPlayer == pLocalPlayer))
				continue;

			if(!IsValidPlayer(tPlayer))
				continue;

			if(tPlayer->iTeam == pLocalPlayer->iTeam)
				continue; 

			GET_ORIGIN_FROMMATRIX(&tPlayerPos, &tPlayer->PlayerObj->Ptr->Matrix);
			tPlayerPosOnScreen = tPlayerPos + D3DXVECTOR3(0, 1, 0);

			if(!gWorldToScreen(&tPlayerPosOnScreen) && !Item14)
				continue;

			if(!GetBonePos(pLocalPlayer, tPlayer, &AimSpot, Aimbone))
			{
			     GET_ORIGIN(&AimSpot, &tPlayer->PlayerObj->Ptr->Matrix);
			}

			if(tPlayer->InVehicle == 1 || tPlayer->InVehicle == 2)
			{
				if(!IsVisible(tPlayer, &AimSpot, &lPlayerPos))
					continue;
			}

			if(pLocalPlayer->InVehicle == 1)
			{
				if(tPlayer->InVehicle == 2)
				{
					if(WTSystem != WireGuided)
					{
						if(!Item41)
							continue;	
					}
				}
			}

			if(Item39 && !Item14)
			{
				float returndist = getDistFromCrosshair(tPlayer);
				if(returndist > MaxAimAngle)
					continue;
			}

			D3DXVECTOR3 vAimDist = AimSpot - lPlayerPos;
			AimDistance = D3DXVec3Length(&vAimDist);
					
			if(AimDistance > MaxAimDistance)
				continue;

			v3TempVec = AimSpot - lPlayerPos;
			D3DXVec3Normalize(&v3TempVec, &v3TempVec);

			float cosX = D3DXVec3Dot(&v3TempVec, &vMyMatrix[MATRIXX]);
            float cosY = D3DXVec3Dot(&v3TempVec, &vMyMatrix[MATRIXY]);

		    float Dist = sqrt((cosX * cosX) + (cosY * cosY));
		    if(Dist > fNearest) continue;

		    if(Dist < fNearest)
		    {
			    fNearest = Dist;
			    pRet = tPlayer;
			    pSavedTarget = i;
			    LastFrameAimKey = true;
			}
		}
	}

	if(LastFrameAimKey == true)
	{
		CPlayer* tPlayer = gPlayerManager->GetPlayerByIndex(pSavedTarget);

		if((!tPlayer) || (tPlayer == pLocalPlayer))
			return 0;

		if(!IsValidPlayer(tPlayer))
			return 0;

		if(tPlayer->iTeam == pLocalPlayer->iTeam)
       		return 0; 

		GET_ORIGIN_FROMMATRIX(&tPlayerPos, &tPlayer->PlayerObj->Ptr->Matrix);
		tPlayerPosOnScreen = tPlayerPos + D3DXVECTOR3(0, 1, 0);

		if(!gWorldToScreen(&tPlayerPosOnScreen) && !Item14)
       		return 0; 

		if(!GetBonePos(pLocalPlayer, tPlayer, &AimSpot, Aimbone))
		{
			GET_ORIGIN(&AimSpot, &tPlayer->PlayerObj->Ptr->Matrix);
		}

		if(tPlayer->InVehicle == 1 || tPlayer->InVehicle == 2)
		{
			if(!IsVisible(tPlayer, &AimSpot, &lPlayerPos))
				return 0;
		}

		if(pLocalPlayer->InVehicle == 1)
		{
			if(tPlayer->InVehicle == 2)
			{
				if(WTSystem != WireGuided)
				{
					if(!Item41)
						return 0;	
				}
			}
		}

		D3DXVECTOR3 vAimDist = AimSpot - lPlayerPos;
		AimDistance = D3DXVec3Length(&vAimDist);

		if(AimDistance > MaxAimDistance)
			return 0;

		if(!GetAimVector(&AimSpot, tPlayer)) return 0;
		D3DXVec3Normalize(&v3TempVec, &AimSpot);

		pRet = tPlayer;
	}

	int AimBoxX = tPlayerPosOnScreen.x - 3;
	int AimBoxY = tPlayerPosOnScreen.y - 3;
	PlayerBox(AimBoxX, AimBoxY, 6, 6, d3dColorGreen);
    return pRet;
}

//================================================================================================================
//TV MISSILE AIM FUNCTION
//================================================================================================================
void aimtvtarget()
{
	BestTarget = GetTarget();
	if(BestTarget == NULL || IsValidPlayer(BestTarget) == FALSE)
		return;

    GET_XAXIS(&TVMX, PlayerViewMatrix);
    GET_YAXIS(&TVMY, PlayerViewMatrix);
	GET_ZAXIS(&TVMZ, PlayerViewMatrix);

	float check = D3DXVec3Dot(&TVMZ, &v3TempVec);
	if (fabs(check) < AIMBOT_COVER_ANGLE_TV)
		return;
	
	aCosX = asinf(D3DXVec3Dot(&TVMX, &v3TempVec));
	aCosY = asinf(D3DXVec3Dot(&TVMY, &v3TempVec));
	aCosZ = asinf(D3DXVec3Dot(&TVMZ, &v3TempVec));

	if (aCosX > AIMBOT_MAX_ANGLE_CHANGE)
		aCosX = AIMBOT_MAX_ANGLE_CHANGE;
	else if (aCosX < -AIMBOT_MAX_ANGLE_CHANGE)
		aCosX = -AIMBOT_MAX_ANGLE_CHANGE;

	if (aCosY > AIMBOT_MAX_ANGLE_CHANGE)
		aCosY = AIMBOT_MAX_ANGLE_CHANGE;
	else if (aCosY < -AIMBOT_MAX_ANGLE_CHANGE)
		aCosY = -AIMBOT_MAX_ANGLE_CHANGE;

	if(!aCosX || !aCosY || !aCosZ)
		return;

	if(!gControlMapManager)
		return;
	if(!gControlMapManager->active_controlmap)
		return;
	if(!gControlMapManager->active_controlmap->DegreesPerPixelX || !gControlMapManager->active_controlmap->DegreesPerPixelY)
		return;

	//SoldierAngleToPix( &movedx, &movedy, aCosX, aCosY );

    aCosX /= gControlMapManager->active_controlmap->DegreesPerPixelX;
	aCosY /= gControlMapManager->active_controlmap->DegreesPerPixelY; 
	aCosX *= 30 / aCosZ;
	aCosY *= 30 / aCosZ;

	if(!gHudManager)
		return;

	if(!gHudManager->HudMouse)
		return;

	if(!gHudManager->HudMouse->MousePosX || !gHudManager->HudMouse->MousePosY)
		return;	

	if(WTSystem == TVGuidedMissile || WTSystem == LaserGuided)
	{
		gHudManager->HudMouse->MousePosX = (aCosX * AIM_SMOOTH_FOV);
	    gHudManager->HudMouse->MousePosY = (-aCosY * AIM_SMOOTH_FOV);
		Activated = true;
	}
}
//
//Test
//

void Testf()
{
	CPlayer* pLocalPlayer = (CPlayer*)gPlayerManager->GetLocalPlayer();

	D3DXVECTOR3 vOut[4];
	GET_XAXIS_FROMMATRIX(&vOut[MATRIXX], PlayerViewMatrix); 
	GET_YAXIS_FROMMATRIX(&vOut[MATRIXY], PlayerViewMatrix); 
	GET_ZAXIS_FROMMATRIX(&vOut[MATRIXZ], PlayerViewMatrix);

	//float CenterX = Viewport.Width / 2;
	//float CenterY = Viewport.Height / 2;
    //D3DXVECTOR3 MViewVector(CenterX, CenterY, 0);

	D3DXMATRIX vRotation;
	D3DXMatrixRotationYawPitchRoll(&vRotation, D3DXToRadian(90), D3DXToRadian(-90), D3DXToRadian(0));
	D3DXMatrixMultiply(&m_ModifiedMatrix, &vRotation, PlayerViewMatrix);
	//D3DXMATRIX TransMat;

	//D3DXMatrixTranslation(&TransMat, Cursor.x, Cursor.y, 0);


}

    
//================================================================================================================
//DEFAULTAIM FUNCTION
//================================================================================================================
void DefaultAim()
{
	CPlayer* pLocalPlayer = (CPlayer*)gPlayerManager->GetLocalPlayer();
	BestTarget = GetTarget();

   	if(BestTarget == NULL || IsValidPlayer(BestTarget) == FALSE) 
	{
		if(BestTarget) BestTarget = NULL; 
		if(LastFrameAimKey) LastFrameAimKey = false;
		if(pRet) pRet = NULL;
		if(pSavedTarget) pSavedTarget = NULL;
		if(bAntiShake) bAntiShake = 0;
		return;
	}

	D3DXVECTOR3 vOut[4];
	GET_XAXIS_FROMMATRIX(&vOut[MATRIXX], PlayerViewMatrix); 
	GET_YAXIS_FROMMATRIX(&vOut[MATRIXY], PlayerViewMatrix); 
	GET_ZAXIS_FROMMATRIX(&vOut[MATRIXZ], PlayerViewMatrix);

	float flAngleX = D3DXToDegree(asinf(D3DXVec3Dot(&vOut[MATRIXX], &v3TempVec)));
	float flAngleY = D3DXToDegree(-asinf(D3DXVec3Dot(&vOut[MATRIXY], &v3TempVec)));

	if(pLocalPlayer->InVehicle == 1)
	{
		if(Item43) bAntiShake = 1;
		else bAntiShake = 0;

		if(bAntiShake)
		{
			D3DXMatrixRotationYawPitchRoll(&TempMatrix, D3DXToRadian(flAngleX), D3DXToRadian(flAngleY), D3DXToRadian(0));
		}	

		if(Item12) 
		{
			CompDev(&v3TempVec);
		}
	}

	if(pLocalPlayer->InVehicle == 2)
	{
		if(Item12) 
		{
			//CompDev(&v3TempVec);
		}
	}

	float flAspectRatio = pLocalPlayer->Camera->GetInsideFOV() / pLocalPlayer->viewFOV / 5.0f;
	float flAimerX = (D3DXToDegree(asinf(D3DXVec3Dot(&vOut[MATRIXX], &v3TempVec))) * flAspectRatio);
	float flAimerY = (D3DXToDegree(-asinf(D3DXVec3Dot(&vOut[MATRIXY], &v3TempVec))) * flAspectRatio);
	
	if(aimmode == 2)
	{
		if(pLocalPlayer->InVehicle == 2)
		{
		  InputBuffer[PIYaw] = ((0.75f * flAimerX) * JET_SMOOTH_FOV);
		  InputBuffer[PIPitch] = ((0.85f * flAimerY) * JET_SMOOTH_FOV);
		  InputBuffer[PIRoll] = ((0.75f * flAimerX) * 0.333333333333f);
		}
	}
	else
	{
	  //Autofire or Manual Fire
	  if(Item36 || Item14)
	  {
		  InputBuffer[PIMouseLookX] = flAimerX;
		  InputBuffer[PIMouseLookY] = flAimerY;

		  if(bAntiShake)
		  { 
			  if(pLocalPlayer->InVehicle == 1)
			  {
			 	  D3DXMatrixMultiply(&m_ModifiedMatrix, &TempMatrix, PlayerViewMatrix);
			  }
		  }

		  if(pLocalPlayer->Weapon_Firemode == 2)
		  {
			  if(Weapon->Weapon_Heat_Primary > 0.90f)
			  {
				  cp = 0;
			  }
			  if(Weapon->Weapon_Heat_Primary < 0.20f && cp == 0)
			  {
				  cp = 1;
			  }
              if(InputBuffer[PIFire] == 0.0f && cp == 1) InputBuffer[PIFire] = 1.0f;
		  }
		  else 
		  {
		      if(InputBuffer[PIFire] == 1.0f) 
		      {
			      InputBuffer[PIFire] = 0.0f;	
		      }
		      else 
		      {
			      InputBuffer[PIFire] = 1.0f;
		      }
		  }
	  }
	  else
	  {
		    InputBuffer[PIMouseLookX] = flAimerX;
		    InputBuffer[PIMouseLookY] = flAimerY;
		
		    if(bAntiShake) 
		    {
			    if(pLocalPlayer->InVehicle == 1)
			    {
				    D3DXMatrixMultiply(&m_ModifiedMatrix, &TempMatrix, PlayerViewMatrix);
			    }
		    }
	   }
	}
}

//================================================================================================================
//KNIFE AIM FUNCTION
//================================================================================================================
void KnifeySpooney()
{
    CPlayer* kPlayer = 0;
    float nDist = 2.0f;
	D3DXVECTOR3 lPlayerPosition, tPlayerPosition;
	CPlayer* pLocalPlayer = gPlayerManager->GetLocalPlayer();

	GET_ORIGIN_FROMMATRIX(&lPlayerPosition, PlayerViewMatrix);

    for(int i = 0; i < 255; i++)
	{
		KnifeTarget = gPlayerManager->GetPlayerByIndex(i);

		if(KnifeTarget == NULL || IsValidPlayer(KnifeTarget) == FALSE) 
			continue;
		
		if(KnifeTarget == pLocalPlayer || KnifeTarget->iTeam == pLocalPlayer->iTeam || KnifeTarget->InVehicle == 2)
			continue;
		
		if(!GetBonePos(pLocalPlayer, KnifeTarget, &tPlayerPosition, SKELETON_BONE_STOMACH))
		{
			GET_ORIGIN_FROMMATRIX(&tPlayerPosition, &KnifeTarget->PlayerObj->Ptr->Matrix);
		}

		if(!IsVisible(KnifeTarget, &tPlayerPosition, &lPlayerPosition))
			continue;

		D3DXVECTOR3 VecDistance = tPlayerPosition - lPlayerPosition;   
		float tDistance = D3DXVec3Length( &VecDistance );
		GET_XAXIS_FROMMATRIX(&ViewMatrixX, PlayerViewMatrix);
		GET_YAXIS_FROMMATRIX(&ViewMatrixY, PlayerViewMatrix);

		float flAspectRatio = pLocalPlayer->Camera->GetInsideFOV() / pLocalPlayer->viewFOV / 5.0f;	

		if(tDistance < nDist)
		{
			if(!GetBonePos(pLocalPlayer, KnifeTarget, &tPlayerPosition, SKELETON_BONE_STOMACH))
			{
				GET_ORIGIN(&tPlayerPosition, &KnifeTarget->PlayerObj->Ptr->Matrix);
			}

			InputBuffer[PIMouseLookX] = D3DXToDegree(asinf(D3DXVec3Dot(&ViewMatrixX, &VecDistance)) * flAspectRatio);
			InputBuffer[PIMouseLookY] = D3DXToDegree(-asinf(D3DXVec3Dot(&ViewMatrixY, &VecDistance)) * flAspectRatio);
			
			if(InputBuffer[PIFire] == 1.0f) 
			{
				InputBuffer[PIFire] = 0.0f;	
			}
			else 
			{
				InputBuffer[PIFire] = 1.0f;
			}
		}
	}

	return;
}

//============================================================================================================
//Validate Weapon Function
//============================================================================================================
bool ValidWeapon()
{
	if(gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Current_Weapon_Slot == 1)
		return TRUE;

	if(gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Current_Weapon_Slot == 6)
		return TRUE;

	return FALSE;
}

//============================================================================================================
//2D RADAR
//============================================================================================================
void Radarfunc(int x, int y, int width, int height, D3DCOLOR color)
{
    FillRGB(x, y+height, width, 1, color, pGameDevice);
    FillRGB(x-1 ,y-1, 1, height+1, color, pGameDevice);
    FillRGB(x, y-1, width, 1, color, pGameDevice);
    FillRGB(x+width ,y-1, 1 , height+1, color, pGameDevice);
     
    int middley = (height-1)/2;
    int middlex = (width-1)/2;
     
    FillRGB(x, y+middley, width, 1, color, pGameDevice);
    FillRGB(x+middlex, y-1, 1, height+1, color, pGameDevice);
     
    int radary = y + middley;
    int radarx = x + middlex;
     
    D3DXVECTOR3 viewpoint, targetpoint, vright, vup, vforward, local, dot, viewangles;
     
    if(gPlayerManager)
    {
    	CPlayer *pLocalPlayer = gPlayerManager->GetLocalPlayer();
     
    	if(pLocalPlayer && pLocalPlayer->Alive() )
		{
    		for ( int i = 0; i <= 255; i++ )   
    		{  
    			CPlayer* pPlayer = gPlayerManager->GetPlayerByIndex( i );  
    			if ( pPlayer != NULL )  
    			{ 
					if ( pPlayer->Alive() && pPlayer != pLocalPlayer && IsValidPlayer(pPlayer))
    				{
						float drawx = (pPlayer->SoldierObj->Ptr->Obj_Physics->Position.x - pLocalPlayer->SoldierObj->Ptr->Obj_Physics->Position.x);
						float drawy = (pPlayer->SoldierObj->Ptr->Obj_Physics->Position.z - pLocalPlayer->SoldierObj->Ptr->Obj_Physics->Position.z);
     
    					VectorAngles(vMyMatrix[MATRIXZ] , viewangles);
     
    					float yaw = (viewangles[1] + 90) * (M_PI*2 / 360);
     
    					float rotx = drawy * cos(yaw) + drawx * sin(yaw);
    					float roty = drawx * cos(yaw) - drawy * sin(yaw);
    						
    					if(fabs(drawx) < 75.0f && fabs(drawy) < 75.0f)
    					{
    						if( pPlayer->iTeam != pLocalPlayer->iTeam )
    						{
    							FillRGB(radarx + rotx, radary + roty, 5, 5, Red, pGameDevice);
    						}
    						else
    						{
    							FillRGB(radarx + rotx, radary + roty, 5, 5, Green, pGameDevice);
    						}
    					}
    				}
    			}
    		}
    	}
    }
}

void Radar(int x, int y, int w, int h)
{
    int ww = w + 1;
    int hh = h + 1;
    y = y - ((h-1)/2);
     
    FillRGB(x, y, ww, hh, Custom, pGameDevice);        // Body color
    Radarfunc(x, y, ww, hh, d3dxColorLightBlue);     // Body outline
}

//============================================================================================================
//AimWarning Function (Credits: TIGERHax / freeheadshot)
//============================================================================================================
void EnemyIsAimingAtYou(CPlayer* pLocalPlayer)
{
    D3DXVECTOR3 vLocal, vEnemy;
	CPlayer* tAim;
    float fMaxAngle = 999, fAimingPercent, fAngle;

    for(int i = 0; i < 255; i++)
    {
        CPlayer* pTarget = gPlayerManager->GetPlayerByIndex(i);

		if((!pTarget) || (!pTarget->SoldierObj) || (!pTarget->SoldierObj->Ptr) || (pTarget == pLocalPlayer) || (pTarget->iTeam == pLocalPlayer->iTeam))
            continue;

		if(!IsValidPlayer(pTarget))
			continue;

		GET_ORIGIN_FROMMATRIX(&vLocal, PlayerViewMatrix);
		GET_ORIGIN_FROMMATRIX(&vEnemy, &pTarget->PlayerObj->Ptr->Matrix);

        if(IsVisible(pTarget, &vEnemy, &vLocal))
        {
            D3DXVECTOR3 vDistance = vLocal - vEnemy;
            D3DXVec3Normalize(&vDistance, &vDistance);

            D3DXMATRIX  mH;
            D3DXMatrixMultiply		(&mH, &pTarget->SoldierObj->Ptr->Skeleton_3P->matrices[47], &pTarget->SoldierObj->Ptr->Matrix);
            D3DXVECTOR3 vRight		(mH._11, mH._12, mH._13);
            D3DXVECTOR3 vUp			(mH._21, mH._22, mH._23);
            D3DXVECTOR3 vForward	(mH._31, mH._32, mH._33);

            fAngle = D3DXToDegree(acos(D3DXVec3Dot(&vForward, &vDistance)));

            if( fMaxAngle > fAngle && fAngle <= 60 )
            {
                fMaxAngle = fAngle;
                fAimingPercent = 100-(fMaxAngle*(100/60));
            }

			tAim = pTarget;
        }
    }

	if(fMaxAngle != 999)
	{
		if(fAimingPercent > 0 && fAimingPercent < 90)
		{
			char cPlayerAim[120];
			sprintf(cPlayerAim, "%s is aiming at you %.0f %%", tAim->Name.c_str(), fAimingPercent);
			Textf(Viewport.Width / 2 - 175, 15, d3dColorYellow, cPlayerAim);
		}

		if(fAimingPercent > 90)
		{
			char cPlayerAim[120];
			sprintf(cPlayerAim, "%s is aiming at you %.0f %%", tAim->Name.c_str(), fAimingPercent);
			Textf(Viewport.Width / 2 - 175, 15, d3dColorRed, cPlayerAim);
		}
	}
}  

//================================================================================================================
//Bone ESP / Player Skeleton ESP (Credits: Nov)
//================================================================================================================
void drawBones(CPlayer* target, D3DXCOLOR color)
{  
	D3DXVECTOR3 bonevecs[13];
	if(target->SoldierObj->Ptr->Skeleton_3P && target->SoldierObj->Ptr->Skeleton_3P->matrices)
	{
		static int bones[13] = {56, 46, 11, 3, 7, 4, 9, 15, 31, 17, 33, 27, 36};
		for(int i = 0; i < 13; i++)
		{
			D3DXMATRIX trans;
			D3DXMatrixMultiply(&trans, &target->SoldierObj->Ptr->Skeleton_3P->matrices[bones[i]], &target->SoldierObj->Ptr->Matrix);
			D3DXVECTOR3 screen = D3DXVECTOR3(trans._41, trans._42, trans._43);

			if(gWorldToScreen(&screen) && screen.z > 0.0f && screen.z < 1.0f)
			{	
				bonevecs[i].x = screen.x;
				bonevecs[i].y = screen.y;
			}
			else
			{
				return;
			}	
		}

		DrawSkeleton(bonevecs[0].x, bonevecs[0].y, bonevecs[1].x, bonevecs[1].y, color); // head->neck
		DrawSkeleton(bonevecs[1].x, bonevecs[1].y, bonevecs[2].x, bonevecs[2].y, color); // neck->core
		DrawSkeleton(bonevecs[2].x, bonevecs[2].y, bonevecs[3].x, bonevecs[3].y, color); // thighs
		DrawSkeleton(bonevecs[2].x, bonevecs[2].y, bonevecs[4].x, bonevecs[4].y, color); // upper legs
		DrawSkeleton(bonevecs[3].x, bonevecs[3].y, bonevecs[5].x, bonevecs[5].y, color); // upper legs
		DrawSkeleton(bonevecs[4].x, bonevecs[4].y, bonevecs[6].x, bonevecs[6].y, color); // lower legs
		DrawSkeleton(bonevecs[1].x, bonevecs[1].y, bonevecs[7].x, bonevecs[7].y, color); // shoulders
		DrawSkeleton(bonevecs[1].x, bonevecs[1].y, bonevecs[8].x, bonevecs[8].y, color); // shoulders
		DrawSkeleton(bonevecs[7].x, bonevecs[7].y, bonevecs[9].x, bonevecs[9].y, color); // arms
		DrawSkeleton(bonevecs[8].x, bonevecs[8].y, bonevecs[10].x, bonevecs[10].y, color); // arms
		DrawSkeleton(bonevecs[9].x, bonevecs[9].y, bonevecs[11].x, bonevecs[11].y, color); // wrists
		DrawSkeleton(bonevecs[10].x, bonevecs[10].y, bonevecs[12].x, bonevecs[12].y, color); // wrists
	}
}

//================================================================================================================
//SnapLines Function
//================================================================================================================
void drawLines( CPlayer* pLocalPlayer, CPlayer* pTarget, CSkeleton* pTargetSkeleton )
{
	D3DXVECTOR3 linevecs[1];
	D3DXMATRIX tLines;
	D3DXMatrixMultiply(&tLines , &pTarget->SoldierObj->Ptr->Skeleton_3P->matrices[56], &pTarget->SoldierObj->Ptr->Matrix);
	D3DXVECTOR3 screenpos = D3DXVECTOR3( tLines._41, tLines._42, tLines._43 );

	if(gWorldToScreen(&screenpos) && screenpos.z > 0.0f && screenpos.z < 1.0f)
	{
		linevecs[1].x = screenpos.x;
		linevecs[1].y = screenpos.y;
	}
	else
	{
		return;
	}

	if(pTarget->InVehicle == 1){DrawSnapLines(linevecs[1].x, linevecs[1].y, Viewport.Width/2, Viewport.Height, d3dColorRed);} //Player on Foot - Draw Red Snapline
	if(pTarget->InVehicle == 2){DrawSnapLines(linevecs[1].x, linevecs[1].y, Viewport.Width/2, Viewport.Height, d3dColorGreen );} //Player in Vehicle - Draw Green Snapline
}

//================================================================================================================
// DISPLAY WARNING FUNCTION
//================================================================================================================
void DisplayWarning(int WarningSystem, float dist)
{
	const char* Warning;
	char cWarning[120];

	if(dist > 100.0f) return;

	if(WarningSystem == TVGuidedMissile) Warning = "TV-Missile Approaching";
	else if(WarningSystem == HeatSeeking) Warning = "Enemy-Lock (DeployFlares)";
	else if(WarningSystem == WireGuided && dist < 30.0f) Warning = "Missile Approaching";
	else if(WarningSystem == Artillery) Warning = "Artillery";
	else if(WarningSystem == Explosive && dist < 10.0f) Warning = "Explosive Nearby";
	else return;

	sprintf(cWarning, "|| WARNING : %s [%.0f] ||", Warning, dist);

	if(dist < 10.0f) Textf(Viewport.Width / 2 - 180, Viewport.Height / 2 + 350, d3dColorRed, cWarning);
	else if(dist < 50.0) Textf(Viewport.Width / 2 - 180, Viewport.Height / 2 + 350, d3dColorOrange, cWarning);
	else Textf(Viewport.Width / 2 - 180, Viewport.Height / 2 + 350, d3dColorYellow, cWarning);
}

//================================================================================================================
// DRAW OBJECTESP FUNCTION
//================================================================================================================
void ObjectESP()
{
	if(!gObjectManager) return;
	if(!gPlayerManager && !gPlayerManager->GetLocalPlayer()) return;

	CPlayer* pLocalPlayer = gPlayerManager->GetLocalPlayer();

	//map<int,CObject*> objectmap = *gObjectManager->create_object_map();

	//for(map<int, CObject*>::iterator i = objectmap.begin(); i != objectmap.end(); i++)
	//{
		//CObject* ActiveObject = i->second;
	for(mapType::iterator iter = objectMap.begin(); iter != objectMap.end(); iter++)
	{
		if(!iter->first) objectMap.erase(iter); 

		CObject* ActiveObject = iter->first;

		if(ActiveObject)
		{
			if(ActiveObject->Obj_Template)
			{
				if(ActiveObject->Obj_Template->GetTemplateType() == TEMPLATE_GENERICPROJECTILE_ID)
				{
					D3DXVECTOR3 vLocalOrigin, vTarget;
			        const char* ObjectTempName = ActiveObject->Obj_Template->name.c_str();
					string ObjectName;
					char distance[15];
					int radius = 8;
					int DangerSystem = NoTargetSystem;
	
				    if(strstr(ObjectTempName, "_m67_")) 
				    {
				        ObjectName = "HandGernade";
						DangerSystem = Explosive;
					    radius = 35;
				    }
				    else if(strstr(ObjectTempName, "_claymore_")) 
				    {
					    radius = 13;
					    ObjectName = "Claymore";
						DangerSystem = Explosive;
				    }
				    else if(strstr(ObjectTempName, "tv")) 
				    { 
						ObjectName = "TVMissile";
						DangerSystem = TVGuidedMissile;
				    }
				    else if(strstr(ObjectTempName, "missile")) 
				    {  
					    ObjectName = "GuidedMissile";
						DangerSystem = WireGuided;
				    }
					else if(strstr(ObjectTempName, "igla")) 
				    { 
						ObjectName = "HS-Missile";
						DangerSystem = HeatSeeking;
				    }
					//else if(strstr(ObjectTempName, "TNK")) 
				    //{   
						//ObjectName = "Tank-Shell";
				    //}
					else if(strstr(ObjectTempName, "at_pre")) 
				    { 
						ObjectName = "AT-Missile";
						DangerSystem = WireGuided;
				    }
					else if(strstr(ObjectTempName, "at_mine")) 
				    {
					    ObjectName = "AT-Mine";
						DangerSystem = Explosive;
				    }
					//else if(strstr(ObjectTempName, "ART")) 
				    //{ 
						//ObjectName = "ArtilleryShell";
						//DangerSystem = Artillery;
				    //}
					//else if(strstr(ObjectTempName, "_smoke_")) 
				    //{ 
						//ObjectName = "SmokeGernade";
				    //}
					//else if(strstr(ObjectTempName, "gl_")) 
				    //{
					    //radius = 13;
						//ObjectName = "GL-Shell";
				    //}
					//else if(strstr(ObjectTempName, "GL_")) 
				    //{
					    //radius = 13;
						//ObjectName = "GL-Shell";
				    //}
					//else if(strstr(ObjectTempName, "ARS")) 
				    //{
						//ObjectName = "ArtilleryShell";
						//DangerSystem = Artillery;
				    //}
					//else if(strstr(ObjectTempName, "Type98")) 
				    //{  
						//ObjectName = "Tank-Shell";
				    //}
					else if(strstr(ObjectTempName, "eryx")) 
				    {					         
						ObjectName = "AT-Missile";
						DangerSystem = WireGuided;
				    }
					else if(strstr(ObjectTempName, "aim9m_")) 
				    {					         
					    ObjectName = "HS-Missile";
						DangerSystem = HeatSeeking;
				    }
					//else if(strstr(ObjectTempName, "Launcher_")) 
				    //{					         
						//ObjectName = "Missile";
				    //}
					//else if(strstr(ObjectTempName, "bomb")) 
				    //{					        
						//ObjectName = "Jet-Bomb";
				    //}
					else if(strstr(ObjectTempName, "aa11_")) 
				    {					        
						ObjectName = "HS-Missile";
						DangerSystem = HeatSeeking;
				    }
					//else if(strstr(ObjectTempName, "T90")) 
				    //{					         
						//ObjectName = "Tank-Shell";
				    //}
					else if(strstr(ObjectTempName, "c4")) 
				    {
					    radius = 13;
						ObjectName = "C4-Explosive";
						DangerSystem = Explosive;
				    }
					else if(strstr(ObjectTempName, "sa19")) 
				    {
						ObjectName = "HS-Missile";
						DangerSystem = HeatSeeking;
				    }
					else continue;

					
			        GET_ORIGIN_FROMMATRIX(&vLocalOrigin, &pLocalPlayer->SoldierObj->Ptr->Matrix);
			        GET_ORIGIN_FROMMATRIX(&vTarget, &ActiveObject->Matrix);

			        D3DXVECTOR3 vDistance = vLocalOrigin - vTarget;
			        float flDistance = D3DXVec3Length(&vDistance);
					if(flDistance > 200.0f && DangerSystem != TVGuidedMissile) continue;
					if(flDistance > 500.0f) continue;
					sprintf(distance, "[%.2fm]", flDistance);
					std::string tDist(distance);

					if(gWorldToScreen(&vTarget))
					{
					    Circle(vTarget.x, vTarget.y, radius, 20, d3dColorGreen );
					    gDebugTextWriter->ShadowedText(vTarget.x, vTarget.y , d3dColorWhite, &ObjectName);
					    gDebugTextWriter->ShadowedText(vTarget.x, vTarget.y + 10 , d3dColorWhite, &tDist);
						if(ActiveObject->Obj_Ctrl_Team == pLocalPlayer->iTeam)
						{
							string Obj_Team = "FRIEND";
							gDebugTextWriter->ShadowedText(vTarget.x, vTarget.y + 20 , d3dColorLightBlue, &Obj_Team);
						}
						else
						{
							string Obj_Team = "ENEMY";
							gDebugTextWriter->ShadowedText(vTarget.x, vTarget.y + 20 , d3dColorRed, &Obj_Team);
						}
					}

					if(Item59)
					{
						if((ActiveObject->Obj_Ctrl_Team != pLocalPlayer->iTeam) || (DangerSystem == Explosive) ) 
							DisplayWarning(DangerSystem, flDistance);
					}

					if(Item60)
					{
						if(flDistance <= 25.0f)
						{
							if((DangerSystem == HeatSeeking) && (ActiveObject->Obj_Ctrl_Team != pLocalPlayer->iTeam) )
							{
							    if(InputBuffer[PIFlareFire] == 1.0f) 
		                        {
			                        InputBuffer[PIFlareFire] = 0.0f;	
		                        }
		                        else 
		                        {
			                        InputBuffer[PIFlareFire] = 1.0f;
		                        }
							}
						}
					}
				  
				}
			}
		}
	}
}

//=================================================================================================
//3D BOXES FUNCTION
//=================================================================================================
void draw3DBoxes(CPlayer* Local, CPlayer* Target, D3DXCOLOR TeamColor)
{
	D3DXVECTOR3 org, vMin, vMax, bone;
	GET_ORIGIN_FROMMATRIX(&org, &Target->SoldierObj->Ptr->Matrix);

	/*
	   .5------8
	 .' |    .'|
	6---+--7'  |
	|   |  |   |
	|  ,4--+---3
	|.'    | .'
	1------2'
 
	1 = min
	8 = max
 
*/
	//STANDING
	if(Target->SoldierObj->Ptr->sPosture == 0)
	{
	    vMin = D3DXVECTOR3(-0.4, -1.0, -0.5);
		vMax = D3DXVECTOR3(0.4, 0.6, 0.5);
	}
	//CROUCHING
	else if(Target->SoldierObj->Ptr->sPosture == 1)
	{
		vMin = D3DXVECTOR3(-0.4, -1.0, -0.5);
		vMax = D3DXVECTOR3(0.4, 0.3, 0.5);
	}
	//PRONING
	else if(Target->SoldierObj->Ptr->sPosture == 2)
	{
		vMin = D3DXVECTOR3(-0.4, -1.0, -1.2);
		vMax = D3DXVECTOR3(0.4, -0.5, 1.0);
	}

	D3DXVECTOR3 _min = org + vMin;
	D3DXVECTOR3 _max = org + vMax;

	D3DXVECTOR3 crnr2 = D3DXVECTOR3(_max.x, _min.y, _min.z);
	D3DXVECTOR3 crnr3 = D3DXVECTOR3(_max.x, _min.y, _max.z);
	D3DXVECTOR3 crnr4 = D3DXVECTOR3(_min.x, _min.y, _max.z);
	D3DXVECTOR3 crnr5 = D3DXVECTOR3(_min.x, _max.y, _max.z);
	D3DXVECTOR3 crnr6 = D3DXVECTOR3(_min.x, _max.y, _min.z);
	D3DXVECTOR3 crnr7 = D3DXVECTOR3(_max.x, _max.y, _min.z);

	if (gWorldToScreen(&_min) &&
		gWorldToScreen(&_max) &&
		gWorldToScreen(&crnr2) &&
		gWorldToScreen(&crnr3) &&
		gWorldToScreen(&crnr4) && 
		gWorldToScreen(&crnr5) && 
		gWorldToScreen(&crnr6) && 
		gWorldToScreen(&crnr7) )
	{
		DrawBoxLines(_min.x, _min.y, crnr2.x, crnr2.y, TeamColor);
		DrawBoxLines(_min.x, _min.y, crnr4.x, crnr4.y, TeamColor);
		DrawBoxLines(_min.x, _min.y, crnr6.x, crnr6.y, TeamColor);
		DrawBoxLines(_max.x, _max.y, crnr5.x, crnr5.y, TeamColor);
		DrawBoxLines(_max.x, _max.y, crnr7.x, crnr7.y, TeamColor);
		DrawBoxLines(_max.x, _max.y, crnr3.x, crnr3.y, TeamColor);
		DrawBoxLines(crnr2.x, crnr2.y, crnr7.x, crnr7.y, TeamColor);
		DrawBoxLines(crnr2.x, crnr2.y, crnr3.x, crnr3.y, TeamColor);
		DrawBoxLines(crnr4.x, crnr4.y, crnr5.x, crnr5.y, TeamColor);
		DrawBoxLines(crnr4.x, crnr4.y, crnr3.x, crnr3.y, TeamColor);
		DrawBoxLines(crnr6.x, crnr6.y, crnr5.x, crnr5.y, TeamColor);
		DrawBoxLines(crnr6.x, crnr6.y, crnr7.x, crnr7.y, TeamColor);
	}
}

//============================================================================================================
//BoxESP Function
//============================================================================================================
void drawBoxes(CPlayer* Local, CPlayer* Target, D3DXCOLOR TeamColor)
{
	if(Target->InVehicle == 2) 
		return;

	D3DXVECTOR3 vHeadScr, vBodyScr;
	bool bGetHeadPos = GetBonePos(Local, Target, &vHeadScr, 46);
	if(!bGetHeadPos)
		return;

	bool bGetBodyPos = GetBonePos(Local, Target, &vBodyScr, 11);
	if(!bGetBodyPos)
		return;

	bool bGetHeadScr = gWorldToScreen(&vHeadScr);
	if(!bGetHeadScr)
		return;

	bool bGetBodyScr = gWorldToScreen(&vBodyScr);
	if(!bGetBodyScr)
		return;

	D3DXVECTOR3 vLength = vHeadScr - vBodyScr;
	float BaseSize = D3DXVec3Length(&vLength);
	float BoxHeight = BaseSize * 2;
	float BoxWidth = BaseSize;
	PlayerBox(vBodyScr.x - BoxWidth, vHeadScr.y - BoxHeight / 2, BoxWidth * 2, BoxHeight * 2.35, TeamColor);
}

//================================================================================================================
//Draw ESP Features
//================================================================================================================
void ESPStuff()
{
	char distance[128];
	string tPosture, tName;
	float EnemyDistance, ClosestEnemy = (float) INT_MAX;
	D3DXVECTOR3 lPlayerPos, tPlayerPos, tPlayerPosOnScreen;
	D3DXMATRIX tVehiclePos;
	D3DXVECTOR3 screenM, ReturnVec;

	if(!gPlayerManager)
		return;

	if(!gPlayerManager->GetLocalPlayer())
		return;

	CPlayer* lPlayer = (CPlayer*)gPlayerManager->GetLocalPlayer();

	GET_ORIGIN_FROMMATRIX(&lPlayerPos, PlayerViewMatrix);

	for (int i = 0; i < 255; i++)
	{
		CPlayer* tPlayer = (CPlayer*)gPlayerManager->GetPlayerByIndex(i);

		if(!tPlayer)
			continue;

		if(!IsValidPlayer(tPlayer))
			continue;

		//Get Target Position
		GET_ORIGIN_FROMMATRIX(&tPlayerPos, &tPlayer->PlayerObj->Ptr->Matrix);
		tPlayerPosOnScreen = tPlayerPos + D3DXVECTOR3(0, 1, 0);

		//Calculate Target Distance
		D3DXVECTOR3 vecDistance = tPlayerPos - lPlayerPos;
		EnemyDistance = D3DXVec3Length(&vecDistance);
		sprintf(distance, "[%.0f]", EnemyDistance);
		std::string tDist(distance);

		//Check if Distance is Within Max ESP Distance
		if(EnemyDistance > espdist) 
			continue;

		//Get Target Name
		tName = tPlayer->Name.c_str();
		
		//Get Target Kit
		playerclass = tPlayer->Kit;

		//Get Target Class
		if(playerclass == 0) str_class = "Special Forces";
		else if(playerclass == 1) str_class = "Sniper";
		else if(playerclass == 2) str_class = "Assault";
		else if(playerclass == 3) str_class = "Support";
		else if(playerclass == 4) str_class = "Engineer";
		else if(playerclass == 5) str_class = "Medic";
		else if(playerclass == 6) str_class = "Anti-Tank";

		//Get Target Posture
		int TargetPosture = tPlayer->SoldierObj->Ptr->sPosture;
		if(TargetPosture == 0){tPosture = "Standing";}
		if(TargetPosture == 1){tPosture = "Crouching";}
		if(TargetPosture == 2){tPosture = "Prone";}

		//Get TargetAimPosition
		if(!GetBonePos(lPlayer, tPlayer, &aimtarget, Aimbone))
			continue;

		//If TargetAimPosition on Screen
		if(gWorldToScreen(&tPlayerPosOnScreen))
		{
			if(tPlayer->iTeam != lPlayer->iTeam)
			{
				//ENEMY INFANTRY VISIBLE
				if(IsVisible(tPlayer, &aimtarget, &lPlayerPos))
				{
					if(tPlayer->InVehicle == 2) ESPCOLOR = d3dColorGreen;			
					else ESPCOLOR = d3dColorRed;
					if(Item1){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 55, tPlayerPosOnScreen.y - 10, d3dColorWhite, &tDist);}
					if(Item2){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 25, tPlayerPosOnScreen.y - 10, ESPCOLOR, &tName);}
						
					if(Item3)
					{
						tHealth = tPlayer->SoldierObj->Ptr->Health->Health;
						DrawHealthBar3(tPlayerPosOnScreen.x - 15, tPlayerPosOnScreen.y - 20, tHealth, 25, 4, d3dColorGreen, d3dColorRed);
					}
						
					if(Item9){drawBones(tPlayer, ESPCOLOR);}
					if(Item10){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x + 25, tPlayerPosOnScreen.y - 10, d3dColorWhite, &tPosture);}
					if(Item11){drawLines(lPlayer, tPlayer, tPlayer->SoldierObj->Ptr->Skeleton_3P);}
		
					if(Item35)
					{
						if(EnemyDistance < EnemyNearbyDist) 
						{
							if(EnemyDistance < ClosestEnemy)
							{
								ClosestEnemy = EnemyDistance;
								Textf(Viewport.Width / 2 - 80, Viewport.Height / 2 + 200, d3dColorRed, "%s is %.1f", tPlayer->Name.c_str(), EnemyDistance);
							}
						}
					}		

					if(Item37){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 25, tPlayerPosOnScreen.y, d3dColorWhite, &str_class);}
					if(Item42){drawBoxes(lPlayer, tPlayer, ESPCOLOR);}
					if(Item17){draw3DBoxes(lPlayer, tPlayer, ESPCOLOR);}
				
					if(tPlayer->InVehicle == 2)
					{
						if(tPlayer->Vehicle_Pilot)
						{
							if(Item3)
							{
								vHealth = tPlayer->PlayerObj->Ptr->Health->Health;
								tHealth = tPlayer->SoldierObj->Ptr->Health->Health;
								DrawHealthBar3(tPlayerPosOnScreen.x - 45, tPlayerPosOnScreen.y - 20, vHealth / 10, 25, 4, d3dColorGreen, d3dColorWhite);
							}
						}
					}
				}
				else //ENEMY INFANTRY NOT VISIBLE
				{
					if(tPlayer->InVehicle == 2) ESPCOLOR = d3dColorPink;
					else ESPCOLOR = d3dColorOrange;
					if(Item1){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 55, tPlayerPosOnScreen.y - 10, d3dColorWhite, &tDist);}
					if(Item2){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 25, tPlayerPosOnScreen.y - 10, ESPCOLOR, &tName);}

					if(Item3)
					{
						tHealth = tPlayer->SoldierObj->Ptr->Health->Health;
						DrawHealthBar3(tPlayerPosOnScreen.x - 15, tPlayerPosOnScreen.y - 20, tHealth, 25, 4, d3dColorGreen, d3dColorRed);
					}

					if(Item9){drawBones(tPlayer, ESPCOLOR);}
					if(Item10){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x + 25, tPlayerPosOnScreen.y - 10, d3dColorWhite, &tPosture);}

					if(Item35)
					{
						if(EnemyDistance < EnemyNearbyDist) 
						{
							if(EnemyDistance < ClosestEnemy)
							{
								ClosestEnemy = EnemyDistance;
								Textf(Viewport.Width / 2 - 80, Viewport.Height / 2 + 200, d3dColorRed, "%s is %.1f", tPlayer->Name.c_str(), EnemyDistance);
							}
						}
					}			

					if(Item37){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 25, tPlayerPosOnScreen.y, d3dColorWhite, &str_class);}
					if(Item42){drawBoxes(lPlayer, tPlayer, ESPCOLOR);}
					if(Item17){draw3DBoxes(lPlayer, tPlayer, ESPCOLOR);}

					if(tPlayer->InVehicle == 2)
					{
						if(tPlayer->Vehicle_Pilot)
						{
							if(Item3)
							{
								vHealth = tPlayer->PlayerObj->Ptr->Health->Health;
								tHealth = tPlayer->SoldierObj->Ptr->Health->Health;
								DrawHealthBar3(tPlayerPosOnScreen.x - 45, tPlayerPosOnScreen.y - 20, vHealth / 10, 25, 4, d3dColorGreen, d3dColorWhite);
							}
						}
					}
				}
			}
						
			if(tPlayer->iTeam == lPlayer->iTeam)
			{
				if(Item13)
				{	
					//TEAMMATE VISIBLE
					if(IsVisible(tPlayer, &aimtarget, &lPlayerPos))
					{
						if(tPlayer->InVehicle == 2) ESPCOLOR = d3dColorSilver;
						else ESPCOLOR = d3dColorLightBlue;
						if(Item1){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 55, tPlayerPosOnScreen.y - 10, d3dColorWhite, &tDist);}
						if(Item2){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 25, tPlayerPosOnScreen.y - 10, ESPCOLOR, &tName);}
						
						if(Item3)
						{
							tHealth = tPlayer->SoldierObj->Ptr->Health->Health;
							DrawHealthBar3(tPlayerPosOnScreen.x - 15, tPlayerPosOnScreen.y - 20, tHealth, 25, 4, d3dColorGreen, d3dColorRed);
						}

						if(tPlayer->InVehicle == 2)
						{
							if(tPlayer->Vehicle_Pilot){
								if(Item3)
								{
									vHealth = tPlayer->PlayerObj->Ptr->Health->Health;
									VehHealth = NumberToString(vHealth);
									gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x -45, tPlayerPosOnScreen.y - 20, d3dColorWhite, &VehHealth);
								}
							}
						}

						if(Item9){drawBones(tPlayer, ESPCOLOR);}
						if(Item10){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x + 25, tPlayerPosOnScreen.y - 10, d3dColorWhite, &tPosture);}
						if(Item37){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 25, tPlayerPosOnScreen.y, d3dColorWhite, &str_class);}
						if(Item42){drawBoxes(lPlayer, tPlayer, ESPCOLOR);}
						if(Item17){draw3DBoxes(lPlayer, tPlayer, ESPCOLOR);}
					}
					else //TEAMMATE NOT VISIBLE
					{
						if(tPlayer->InVehicle == 2) ESPCOLOR = d3dColorCustom;
						else ESPCOLOR = d3dColorYellow;
						if(Item1){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 55, tPlayerPosOnScreen.y - 10, d3dColorWhite, &tDist);}
						if(Item2){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 25, tPlayerPosOnScreen.y - 10, ESPCOLOR, &tName);}
						
						if(Item3)
						{
							tHealth = tPlayer->SoldierObj->Ptr->Health->Health;
							DrawHealthBar3(tPlayerPosOnScreen.x - 15, tPlayerPosOnScreen.y - 20, tHealth, 25, 4, d3dColorGreen, d3dColorRed);
						}
	
						if(tPlayer->InVehicle == 2)
						{
							if(tPlayer->Vehicle_Pilot){
								if(Item3)
								{
									vHealth = tPlayer->PlayerObj->Ptr->Health->Health;
									VehHealth = NumberToString(vHealth);
									gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x -45, tPlayerPosOnScreen.y - 20, d3dColorWhite, &VehHealth);
								}
							}
						}

						if(Item9){drawBones(tPlayer, ESPCOLOR);}
						if(Item10){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x + 25, tPlayerPosOnScreen.y - 10, d3dColorWhite, &tPosture);}
						if(Item37){gDebugTextWriter->ShadowedText(tPlayerPosOnScreen.x - 25, tPlayerPosOnScreen.y, d3dColorWhite, &str_class);}
						if(Item42){drawBoxes(lPlayer, tPlayer, ESPCOLOR);}
						if(Item17){draw3DBoxes(lPlayer, tPlayer, ESPCOLOR);}
					}
				}
			}
		}
	}
}

//================================================================================================================
//Read/Write Settings Class
//================================================================================================================
class CIniReader;
class CIniWriter;

class CIniReader
{
public:
	CIniReader(char* szFileName);

	int ReadInteger(char* szSection, char* szKey, int iDefaultValue);
	float ReadFloat(char* szSection, char* szKey, float fltDefaultValue);
	bool ReadBoolean(char* szSection, char* szKey, bool bolDefaultValue);
	std::string  ReadString(char* szSection, char* szKey, const char* szDefaultValue);
private:
	char m_szFileName[255];
};

class CIniWriter
{
public:
	CIniWriter(char* szFileName);
	void WriteInteger(char* szSection, char* szKey, int iValue);
	void WriteFloat(char* szSection, char* szKey, float fltValue);
	void WriteBoolean(char* szSection, char* szKey, bool bolValue);
	void WriteString(char* szSection, char* szKey, string szValue);
private:
	char m_szFileName[255];
};

CIniReader::CIniReader(char* szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, strlen(szFileName));
}
int CIniReader::ReadInteger(char* szSection, char* szKey, int iDefaultValue)
{
	int iResult = GetPrivateProfileInt(szSection, szKey, iDefaultValue, m_szFileName);
	return iResult;
}
float CIniReader::ReadFloat(char* szSection, char* szKey, float fltDefaultValue)
{
	char szResult[255];
	char szDefault[255];
	float fltResult;
	sprintf(szDefault, "%f", fltDefaultValue);
	GetPrivateProfileString(szSection, szKey, szDefault, szResult, 255, m_szFileName);
	fltResult = atof(szResult);
	return fltResult;
}
bool CIniReader::ReadBoolean(char* szSection, char* szKey, bool bolDefaultValue)
{
	char szResult[255];
	char szDefault[255];
	bool bolResult;
	sprintf(szDefault, "%s", bolDefaultValue ? "True" : "False");
	GetPrivateProfileString(szSection, szKey, szDefault, szResult, 255, m_szFileName);
	bolResult = (strcmp(szResult, "True") == 0 ||
		strcmp(szResult, "true") == 0) ? true : false;
	return bolResult;
}
std::string CIniReader::ReadString(char* szSection, char* szKey, const char* szDefaultValue)
{
	//char* szResult = new char[255];
	string szResult;
	GetPrivateProfileString((LPCSTR)szSection, (LPCSTR)szKey, (LPCSTR)szDefaultValue, (LPSTR)szResult.c_str(), 255, (LPCSTR)m_szFileName);
	return szResult;
}

CIniWriter::CIniWriter(char* szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, strlen(szFileName));
}
void CIniWriter::WriteInteger(char* szSection, char* szKey, int iValue)
{
	char szValue[255];
	sprintf(szValue, "%d", iValue);
	WritePrivateProfileString(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteFloat(char* szSection, char* szKey, float fltValue)
{
	char szValue[255];
	sprintf(szValue, "%f", fltValue);
	WritePrivateProfileString(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteBoolean(char* szSection, char* szKey, bool bolValue)
{
	char szValue[255];
	sprintf(szValue, "%s", bolValue ? "True" : "False");
	WritePrivateProfileString(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteString(char* szSection, char* szKey, string szValue)
{
	WritePrivateProfileString(szSection, szKey, szValue.c_str(), m_szFileName);
}

CIniReader iniReader(".\\RAXBF2Framework.ini");
CIniWriter iniWriter(".\\RAXBF2Framework.ini");

//============================================================================================================
//WRITE SETTINGS
//============================================================================================================
void writesettings()
{
	iniWriter.WriteInteger("ESP", "Nametags", Item2);
	iniWriter.WriteInteger("ESP", "DistanceTags", Item1);
	iniWriter.WriteInteger("ESP", "Healthbars", Item3);
	iniWriter.WriteInteger("ESP", "No Fog", Item6);
	iniWriter.WriteInteger("ESP", "No Sky", Item7);
	iniWriter.WriteInteger("ESP", "Class", Item37);
	iniWriter.WriteInteger("ESP", "Posture", Item10);
	iniWriter.WriteInteger("ESP", "Snaplines", Item11);
	iniWriter.WriteInteger("ESP", "Skeleton", Item9);
	iniWriter.WriteInteger("ESP", "Boxes", Item42);
	iniWriter.WriteInteger("ESP", "DrawTeam", Item13);
	iniWriter.WriteInteger("ESP", "2D RADAR", Item16);
	iniWriter.WriteInteger("ESP", "3D Boxes", Item17);
	iniWriter.WriteFloat("ESP", "ESPDistance", espdist);
	iniWriter.WriteInteger("Team", "Team Swap", Item21);
	iniWriter.WriteInteger("Team", "Force Commander", Item22);
	iniWriter.WriteInteger("Team", "Force Squad Leader", Item23);
	iniWriter.WriteInteger("Team", "Squad Jumping", Item24);
	iniWriter.WriteInteger("Team", "Unlimited CommanderAssets", Item61);
	iniWriter.WriteInteger("Chams", "USMCSoldiers", Item26);
	iniWriter.WriteInteger("Chams", "CHINASoldiers", Item27);
	iniWriter.WriteInteger("Chams", "MECSoldiers", Item28);
	iniWriter.WriteInteger("Chams", "EUROSoldiers", Item29);
	iniWriter.WriteInteger("Chams", "Vehicles", Item30);
	iniWriter.WriteInteger("Chams", "Weapons", Item31);
	iniWriter.WriteInteger("Chams", "GroundWeapons", Item32);
	iniWriter.WriteInteger("Chams", "Explosives", Item33);
	iniWriter.WriteInteger("Chams", "Hands", Item34);
	iniWriter.WriteInteger("Aimbot", "Aimkey", AimKey);
	iniWriter.WriteInteger("Aimbot", "AimAssist", Item25);
	iniWriter.WriteInteger("Aimbot", "NoSpread", Item12);
	iniWriter.WriteInteger("Aimbot", "NoShake", Item43);
	iniWriter.WriteInteger("Aimbot", "Autoshoot", Item36);
	iniWriter.WriteInteger("Aimbot", "LimitAimAngle", Item39);
	iniWriter.WriteInteger("Aimbot", "DrawAimFOV", Item38);
	iniWriter.WriteInteger("Aimbot", "AimAtVehicle", Item41);
	iniWriter.WriteInteger("Aimbot", "Ping Correction", Item45);
	iniWriter.WriteInteger("Aimbot", "AimBone", Aimbone);
	iniWriter.WriteFloat("Aimbot", "AimPrediction", AimPrediction);
	iniWriter.WriteFloat("Aimbot", "MaxAimAngle", MaxAimAngle);
	iniWriter.WriteFloat("Aimbot", "MaxAimDistance", MaxAimDistance);
	iniWriter.WriteInteger("Extras", "Minimap", Item4);
	iniWriter.WriteInteger("Extras", "Crosshair", Item5);
	iniWriter.WriteInteger("Extras", "Speedhack", Item19);
	iniWriter.WriteInteger("Extras", "Unlock Weapons", Item20);
	iniWriter.WriteInteger("Extras", "EnemyNearby", Item35);
	iniWriter.WriteFloat("Extras", "EnemyNearbyDistance", EnemyNearbyDist);
	iniWriter.WriteInteger("Extras", "AimAtYouWarning", Item8);
	iniWriter.WriteInteger("Extras", "DrawFPS", Item15);
	iniWriter.WriteInteger("Extras", "No Hands", Item18);
	iniWriter.WriteInteger("Extras", "TVStatic", Item44);
	iniWriter.WriteFloat("Extras", "SpeedHackModifier", SpeedModifier);
	iniWriter.WriteInteger("Extras", "CustomXHair", xhairselect);
	iniWriter.WriteInteger("Extras", "View Distance", Item51);
	iniWriter.WriteInteger("Extras", "No Overlay", Item52);
	iniWriter.WriteInteger("Extras", "3D Map Icons", Item53);
	iniWriter.WriteInteger("Extras", "Enemy Mines Icon", Item54);
	iniWriter.WriteInteger("Extras", "Radar & Bridge Icons", Item55);
	iniWriter.WriteInteger("Extras", "ASUS Wallhack", Item56);
	iniWriter.WriteInteger("Extras", "Wallhack", Item57);
	iniWriter.WriteInteger("Extras", "ObjectESP", Item58);
	iniWriter.WriteInteger("Extras", "DangerWarning", Item59);
	iniWriter.WriteInteger("Extras", "Auto-Flares", Item60);
}

//============================================================================================================
//READ SETTINGS
//============================================================================================================
void readsettings()
{
	Item2 = iniReader.ReadInteger("ESP", "Nametags", 0);
	Item1 = iniReader.ReadInteger("ESP", "DistanceTags", 0);
	Item3 = iniReader.ReadInteger("ESP", "Healthbars", 0);
	Item6 = iniReader.ReadInteger("ESP", "No Fog", 0);
	Item7 = iniReader.ReadInteger("ESP", "No Sky", 0);
	Item37 = iniReader.ReadInteger("ESP", "Class", 0);
	Item10 = iniReader.ReadInteger("ESP", "Posture", 0);
	Item11 = iniReader.ReadInteger("ESP", "Snaplines", 0);
	Item9 = iniReader.ReadInteger("ESP", "Skeleton", 0);
	Item42 = iniReader.ReadInteger("ESP", "Boxes", 0);
	Item13 = iniReader.ReadInteger("ESP", "DrawTeam", 0);
	Item16 = iniReader.ReadInteger("ESP", "2D RADAR", 0);
	Item17 = iniReader.ReadInteger("ESP", "3D Boxes", 0);
	espdist = iniReader.ReadFloat("ESP", "ESPDistance", 500.000000);
	Item21 = iniReader.ReadInteger("Team", "Team Swap", 0);
	Item22 = iniReader.ReadInteger("Team", "Force Commander", 0);
	Item23 = iniReader.ReadInteger("Team", "Force Squad Leader", 0);
	Item24 = iniReader.ReadInteger("Team", "Squad Jumping", 0);	
	Item61 = iniReader.ReadInteger("Team", "Unlimited CommanderAssets", 0);	
	Item26 = iniReader.ReadInteger("Chams", "USMCSoldiers", 0);
	Item27 = iniReader.ReadInteger("Chams", "CHINASoldiers", 0);
	Item28 = iniReader.ReadInteger("Chams", "MECSoldiers", 0);
	Item29 = iniReader.ReadInteger("Chams", "EUROSoldiers", 0);
	Item30 = iniReader.ReadInteger("Chams", "Vehicles", 0);
	Item31 = iniReader.ReadInteger("Chams", "Weapons", 0);
	Item32 = iniReader.ReadInteger("Chams", "GroundWeapons", 0);
	Item33 = iniReader.ReadInteger("Chams", "Explosives", 0);
	Item34 = iniReader.ReadInteger("Chams", "Hands", 0);
	AimKey = iniReader.ReadInteger("Aimbot", "Aimkey", 0x43);
	JetAimKey = iniReader.ReadInteger("Aimbot", "JetAimKey", 0x43);
	TVAimKey = iniReader.ReadInteger("Aimbot", "TVAimKey", 0x43);
	Item25 = iniReader.ReadInteger("Aimbot", "AimAssist", 0);
	Item12 = iniReader.ReadInteger("Aimbot", "NoSpread", 0);
	Item43 = iniReader.ReadInteger("Aimbot", "NoShake", 0);
	Item36 = iniReader.ReadInteger("Aimbot", "Autoshoot", 0);
	Item39 = iniReader.ReadInteger("Aimbot", "LimitAimAngle", 0);
	Item38 = iniReader.ReadInteger("Aimbot", "DrawAimFOV", 0);
	Item41 = iniReader.ReadInteger("Aimbot", "AimAtVehicle", 0);
	Item45 = iniReader.ReadInteger("Aimbot", "Ping Correction", 0);
	Aimbone = iniReader.ReadInteger("Aimbot", "AimBone", 47);
	AimPrediction = iniReader.ReadFloat("Aimbot", "AimPrediction", 1.000000);
	MaxAimAngle = iniReader.ReadFloat("Aimbot", "MaxAimAngle", 300.000000);
	MaxAimDistance = iniReader.ReadFloat("Aimbot", "MaxAimDistance", 500.000000);
	Item4 = iniReader.ReadInteger("Extras", "Minimap", 0);
	Item5 = iniReader.ReadInteger("Extras", "Crosshair", 0);
	Item19 = iniReader.ReadInteger("Extras", "Speedhack", 0);
	Item20 = iniReader.ReadInteger("Extras", "Unlock Weapons", 0);
	Item35 = iniReader.ReadInteger("Extras", "EnemyNearby", 0);
	EnemyNearbyDist = iniReader.ReadFloat("Extras", "EnemyNearbyDistance", 10.000000);
	Item8 = iniReader.ReadInteger("Extras", "AimAtYouWarning", 0);
	Item15 = iniReader.ReadInteger("Extras", "DrawFPS", 0);
	Item18 = iniReader.ReadInteger("Extras", "No Hands", 0);
	Item44 = iniReader.ReadInteger("Extras", "TVStatic", 0);
	SpeedModifier = iniReader.ReadFloat("Extras", "SpeedHackModifier", 1000000000.000000);
	xhairselect = iniReader.ReadInteger("Extras", "CustomXHair", 3);
	Item51 = iniReader.ReadInteger("Extras", "View Distance", 0);
	Item52 = iniReader.ReadInteger("Extras", "No Overlay", 0);
	Item53 = iniReader.ReadInteger("Extras", "3D Map Icons", 0);
	Item54 = iniReader.ReadInteger("Extras", "Enemy Mines Icon", 0);
	Item55 = iniReader.ReadInteger("Extras", "Radar & Bridge Icons", 0);
	Item56 = iniReader.ReadInteger("Extras", "ASUS Wallhack", 0);
	Item57 = iniReader.ReadInteger("Extras", "Wallhack", 0);
	Item58 = iniReader.ReadInteger("Extras", "ObjectESP", 0);
	Item59 = iniReader.ReadInteger("Extras", "DangerWarning", 0);
	Item60 = iniReader.ReadInteger("Extras", "Auto-Flares", 0);
}

class CVMTHookManager
{
public:
	CVMTHookManager( void )
	{
		memset( this, 0, sizeof( CVMTHookManager ) );
	}

	CVMTHookManager( PDWORD* ppdwClassBase )
	{
		bInitialize( ppdwClassBase );
	}

	~CVMTHookManager( void )
	{
		UnHook();
	}
	bool bInitialize( PDWORD* ppdwClassBase )
	{
		m_ppdwClassBase = ppdwClassBase;
		m_pdwOldVMT = *ppdwClassBase;
		m_dwVMTSize = dwGetVMTCount( *ppdwClassBase );
		m_pdwNewVMT = new DWORD[ m_dwVMTSize ];
		memcpy( m_pdwNewVMT, m_pdwOldVMT, sizeof( DWORD ) * m_dwVMTSize );
		*ppdwClassBase = m_pdwNewVMT;
		return true;
	}
	bool bInitialize( PDWORD** pppdwClassBase ) // fix for pp
	{
		return bInitialize( *pppdwClassBase );
	}

	void UnHook( void )
	{
		if ( m_ppdwClassBase )
		{
			*m_ppdwClassBase = m_pdwOldVMT;
		}
	}

	void ReHook( void )
	{
		if ( m_ppdwClassBase )
		{
			*m_ppdwClassBase = m_pdwNewVMT;
		}
	}

	int iGetFuncCount( void )
	{
		return ( int ) m_dwVMTSize;
	}

	DWORD dwGetMethodAddress( int Index )
	{
		if ( Index >= 0 && Index <= ( int )m_dwVMTSize && m_pdwOldVMT != NULL )
		{
			return m_pdwOldVMT[ Index ];
		}
		return NULL;
	}

	PDWORD pdwGetOldVMT( void )
	{
		return m_pdwOldVMT;
	}

	DWORD dwHookMethod( DWORD dwNewFunc, unsigned int iIndex )
	{
		if ( m_pdwNewVMT && m_pdwOldVMT && iIndex <= m_dwVMTSize && iIndex >= 0 )
		{
			m_pdwNewVMT[ iIndex ] = dwNewFunc;
			return m_pdwOldVMT[ iIndex ];
		}

		return NULL;
	}

private:
	DWORD dwGetVMTCount( PDWORD pdwVMT )
	{
		DWORD dwIndex = 0;

		for ( dwIndex = 0; pdwVMT[ dwIndex ]; dwIndex++ )
		{
			if ( IsBadCodePtr( ( FARPROC ) pdwVMT[ dwIndex ] ) )
			{
				break;
			}
		}
		return dwIndex;
	}
	PDWORD*	m_ppdwClassBase;
	PDWORD	m_pdwNewVMT, m_pdwOldVMT;
	DWORD	m_dwVMTSize;
};