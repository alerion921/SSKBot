#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9math.h>
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "d3d9.lib")

class CProfileManager;
class CActiveAccount;
class CPlayerManager;
class CPlayer;
class CInfo;
class CObject;
class CObject_Projectile;
class IPlayerControlObject;
class CObject_PlayerControlObject;
class CObject_Vehicle;
class CHealth;
class CTemplate;
class CPhysics;
class CCamera;
class CSoldierPtr;
class CSoldier;
class CWeapon;
class CWeaponTarget;
class CDeviation;
class CSkeleton;
class CBone;
class CRenderer;
class CClassManager;
class CTextWriter;
class CGame;
class CObjectManager;
class CRayTest;
class CPhysicsManager;
class CDebugTextWriter;
class CDebugLineDrawer;
class CActionBuffer;
class CInputDeviceManager;
class CInputDevice;
class CInputManager;
class CMainConsole;
class CControlMap;
class CControlMapManager;
class CHudManager;
class CHudManagerTV;
class CHudMouse;
class CMinimap;
class CCrosshair;
class CCommander_Assets;
class CComponent;
class CComponent_WeaponBasedRecoil; 
class CComponent_LPTargetComp;
class CTemplate_Camera; 
class CTemplate_RotationalBundle;
class CTemplate_Bundle;
class CTemplate_SimpleObject;
class CTemplate_PlayerControlObject;
class CTemplate_GenericProjectile;
class CTemplate_GenericFireArm;
class CHudNode_MiniMap;
class CGameConfig;
class CPostProductionFrameWork;
class CGlobalSettings;
class CLocalProfileManager;
class CLocalProfile;
class CGeometry;
class CCollisionMesh;
class CCollisionBox;
class CMaterialManager;
class CMaterial;

template<class T>
class CRef
{
public:
	int refCount;
	T* Ptr;
};


class CProfileManager
{
public:
char cUnknown1[8];
CActiveAccount* ActiveAccount; //0008
};
 
class CActiveAccount
{
public:
    string Email; //0x0000  
    string Password; //0x001C  
    char cUnknown1[16]; //0x0038  
    __int32 PID; //0x0048  
    string Name; //0x004C  
};//Size=0x0068(104)

class CGameConfig
{
public:
	virtual void vFunction0();
	virtual void vFunction1();
	virtual void vFunction2();
	virtual void vFunction3();
	virtual void vFunction4();
	virtual void vFunction5();
	virtual void vFunction6();
	virtual void vFunction7();
	virtual void vFunction8();
	virtual void vFunction9();
	virtual void vFunction10();
	virtual void vFunction11();
	virtual void vFunction12();
	virtual void vFunction13();
	virtual void vFunction14();
	virtual void vFunction15();
	virtual void vFunction16();
	virtual void vFunction17();
	virtual void vFunction18();
	virtual void vFunction19();
	virtual void vFunction20();
	virtual void vFunction21();
	virtual void vFunction22();
	virtual void vFunction23();
	virtual void vFunction24();
	virtual void vFunction25();
	virtual DWORD GetFrameCount();
	 virtual void function27();
    virtual void function28();
    virtual void function29();
    virtual void function30();
    virtual void function31();
    virtual void function32();
    virtual void function33();
    virtual void function34();
    virtual void function35();
    virtual void function36();
    virtual void function37();
    virtual void function38();
    virtual void function39();
    virtual void function40();
    virtual void function41();
    virtual void function42();
    virtual void function43();
    virtual void function44();
    virtual void function45();
    virtual void function46();
    virtual void function47();
    virtual void function48();
    virtual void function49();
    virtual void function50();
    virtual void function51();
    virtual void function52();
    virtual void function53();
    virtual void function54();
    virtual void function55();
    virtual void function56();
    virtual void function57();
    virtual void function58();
    virtual string* getMapName( void );
    virtual string* getGameMode( void );
    virtual string* getMapDir( void );
    virtual int getMapSize( void );
    virtual void function63();
    virtual void function64();
    virtual void function65();
    virtual void function66();
    virtual void function67();
    virtual void function68();
    virtual void function69();
    virtual void function70();
    virtual void function71();
};

class CControlMap
{
public:
 virtual void Function0();
 char unknown0[4];
 string cmap_name; //0008

 char unknown3[28];
 float Unknown4; //0040
 float Unknown5; //0044
 float Unknown6; //0048
 BYTE invertMouse; //004C
 char unknown7[3];
 float mouse_sensitivity; //0050
 float Unknown8; //0054
 float DegreesPerPixelX; //0058
 float DegreesPerPixelY; //005C
 float Unknown9; //0060
 float Unknown10; //0064
 float yaw_factor; //0068
 float pitch_factor; //006C
};

class CMainConsole
{
public:
 virtual void Function0();// 0
 virtual void Function1(); // 4
 virtual void Exec(dice::std::string* strCommand /*&string("command")*/, dice::std::string* strUnknown/* = &string("")*/,int iUnknown1 = 0,int iUnknown2 = 0, int iUnknown3 = 0,int iUnknown4 = 0,int iUnknown5 = 1 ); // 8
 virtual void Function3(); // C
 virtual void Print( string* strText ); // 10
 virtual void Function5();// 14
 virtual void Function6();// 18
 virtual void Function7();// 1C
 virtual void Draw( int iNumOfLines );// 20
 virtual void Function9();
 virtual void Function10();
 virtual void Function11();
 virtual void Function12();
 virtual void Function13();
 virtual void Function14();
 virtual void Function15();
 virtual void Function16();
 virtual void Function17();
 virtual void Function18();
 virtual void Function19();
 virtual void Function20();
 virtual void Function21();
 virtual void Function22();
 virtual void Function23();
 virtual void Function24();
 virtual void Function25();
 virtual void Function26();
 virtual void Function27();
 virtual void Function28();
 virtual void Function29();
 virtual void Function30();
 virtual void Function31();
 virtual void Function32();
 virtual void Function33();
 virtual void Function34();
 virtual void Function35();
 virtual void Function36();
 virtual void Function37();
 virtual void Function38();
 virtual void Function39();
 virtual void Function40();
 virtual bool bIsConsoleOpen( void );
 BYTE m_bOpen; //0004
 char unknown0[39];
 __int32 Unknown1; //002C
 char unknown2[28];
 char m_szText[128]; //004C
 char unknown3[8];
 __int32 m_iCharCount; //00D4
};

class CPlayerManager
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual CPlayer* GetPlayerByIndex(int Index); //virtual CPlayer* GetPlayerByIndex(int Index);
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual CPlayer* GetLocalPlayer();//virtual CPlayer* GetLocalPlayer();

char _0x0004[4];
	CPlayer* ActivePlayer; //0x0008 
char _0x000C[8];
	DWORD NumberOfPlayers; //0x0014 
char _0x0018[8];
	DWORD PlayersPerTeam; //0x0020 
char _0x0024[8];
	DWORD NumberOfPlayers_; //0x002C 
char _0x0030[32];
	__int32 TotalPlayers; //0x0050 
char _0x0054[12];
	CPlayer* LocalPlayer; //0x0060 
char _0x0064[28];

};//Size=0x0080

class IPlayerControlObject
{
public:
	virtual void function0(); //
	virtual void function1(); //
	virtual void function2(); //
	virtual void function3(); //
	virtual CPlayer* getPlayer(); //
	virtual CSoldier* getSoldier(); //
	virtual void function6(); //
	virtual void function7(); //
	virtual void function8(); //
	virtual void function9(); //
	virtual void function10(); //
	virtual void function11(); //
	virtual void function12(); //
	virtual void function13(); //
	virtual void function14(); //
	virtual void function15(); //
	virtual void function16(); //
	virtual CCamera* getCamera(); //
	virtual void function18(); //
	virtual void function19(); //
	virtual void function20(); //
	virtual void function21(); //
	virtual void function22(); //
	virtual void function23(); //
	virtual map<int, IPlayerControlObject*> getPassangers(); //
	virtual void function25(); //
	virtual void function26(); //
	virtual void function27(); //
	virtual void function28(); //
	virtual CWeapon* getWeapon(int); //
	virtual void function30(); //
	virtual void function31(); //
	virtual void function32(); //
	virtual void function33(); //
	virtual void function34(); //
	virtual void function35(); //
	virtual void function36(); //
	virtual void function37(); //
	virtual int getTeam(); //
};//Size=0x0004(4)

class CPlayerPtr
{
public:
char _0x0000[4];
	CPlayer* Ptr; //0x0004 
char _0x0008[56];
};//Size=0x0040


class CPlayer
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual char* GetName(); //virtual char* GetName();
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); // virtual CVehicle* Vehicle();
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual bool Alive();  //virtual bool Alive(); 
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual float getFOV(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void setSoldierObject(CObject* soldier); //
	virtual CObject* getSoldierObject(); //defaultvehicle
	virtual CCamera* getFreeCamera(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual int GetTeam(); //virtual int GetTeam();
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual int SquadID(); //virtual int SquadID();
	virtual void Function65(); //
	virtual bool IsCommander(); //virtual bool IsCommander();
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual void Function84(); //
	virtual void Function85(); //
	virtual int Ping(); //virtual int Ping();
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual int FlagHolder(); //virtual int FlagHolder();
	virtual CCamera* GetViewMatrix(); //virtual CCamera* GetViewMatrix();
	virtual void Function93(); //
	virtual void Function94(); //
	virtual CCamera* GetPlayerView(void); //virtual CCamera* GetPlayerView(void);
	virtual void Function96(); //
	virtual void Function97(); //

char _0x0004[84];
	__int32 Kit; //0x0058 
char _0x005C[4];
	string Name; //0x0060 
char _0x007C[4];
	CInfo* PlayerObj; //0x0080 
	CCamera* Camera; //0x0084 
char _0x0088[44];
	__int32 PlayerSeat; //0x00B4 
	__int32 PlayerCode; //0x00B8 wtf?
char _0x00BC[4];
	float viewFOV; //0x00C0   
	float Zoom; //0x00C4 
char _0x00C8[4];
	CSoldierPtr* SoldierObj; //0x00CC 
	char _0x00D0[5]; //0x00D0 
	BYTE iAlive; //0x00D5 
char _0x00D6[2];
	__int32 iTeam; //0x00D8 
char _0x00DC[28];
	DWORD iPing; //0x00F8 
char _0x00FC[16];
	__int32 Squad_Number; //0x010C 
	BYTE commander; //0x0110 
	BYTE Squad_Leader; //0x0111 
char _0x0112[102];
	BYTE InVehicle; //0x0178  1 = OnFoot || 2 = OnVehicle
	char N00F34823[3]; //0x0179 
char _0x017C[8];
	BYTE primary_fire_down; //0x0184 
	BYTE secondary_fire_down; //0x0185 
	BYTE N0039672D; //0x0186 
	BYTE Sprinting; //0x0187 
char _0x0188[68];
	__int32 Weapon_Ammo; //0x01CC 
char _0x01D0[8];
	__int32 Weapon_MaxAmmo; //0x01D8 
char _0x01DC[8];
	__int32 Weapon_Firemode; //0x01E4 
char _0x01E8[8];
	__int32 Weapon_Zoomed; //0x01F0 
char _0x01F4[8];
	__int32 Weapon_Mags; //0x01FC 
char _0x0200[8];
	__int32 Weapon_Max_Mags; //0x0208 
char _0x020C[8];
	float Weapon_Heat_Primary; //0x0214 
char _0x0218[56];
	__int32 Vehicle_Pilot; //0x0250 
	BYTE weaponInfiniteAmmo; //0x0254 
	WORD N003D7618; //0x0255 
	BYTE N003D7619; //0x0257 
	float Weapon_Overheat_Primary; //0x0258 
	float Weapon_Overheat_Secondary; //0x025C 
char _0x0260[464];

};//Size=0x0430

class CInfo
{
public:
	    virtual void Function0();
		CObject* Ptr; //0x004 CObject* Ptr; //0x0004
//public:
//char _0x0000[4];
//	CObject* Ptr; //0x0004  CRef<CObject*>ObjPtr;
//char _0x0008[52];
};//Size=0x003C

class CGeometry
{
public:
};

class CCollisionMesh
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual CCollisionBox* GetCollisionBox( int i = 0 ); //
	virtual BYTE Intersect(int unknown0_0, int unknown1_0,
	D3DXMATRIX* in_object_matrix, D3DXMATRIX* in_object_matrix_transpose,
	D3DXVECTOR3* in_ray_start, D3DXVECTOR3* in_ray_dir_end,
	D3DXVECTOR3* out_inter_normal, D3DXVECTOR3* out_inter_point,
	float* out_unknown2, float* out_unknown3,
	int* out_material, BOOL in_unknown4_0, BOOL in_unknown5_1, BOOL in_unknown6_1);
};

class CCollisionBox
{
public:
	D3DXVECTOR3 m_min; //0x0000 
	D3DXVECTOR3 m_max; //0x000C 
 
}; //Size=0x0018

/*class CObject
{
public:
	virtual void function0(); ////char _0x0000[4];
	DWORD ObjectFlags; //0x0004 Untested
	char _0x0008[4]; //0x0008 
	CObject* Obj_Root; //0x000C 
	__int32 object_id; //0x0010
	CTemplate* Obj_Template; //0x0014 
	char z_cUnknown1[16]; //0x0018  	//char _0x0018[36];
    CObject* object_hierarchy_root; //0x0028  
    CObject* object_hierarchy_left; //0x002C  
    CObject* object_hierarchy_right; //0x0030  
	char z_cUnknown2[4]; //0x0034
	CGeometry* object_mesh; //0038
	CHealth* Health; //0x003C -> Object Armor
	CCollisionMesh* object_collision; //0040 //char _0x0040[4]; //0x0040  
	CPhysics* Obj_Physics; //0x0044 
	char _0x0048[64]; //0x0048
	D3DXMATRIX Matrix; //0x0088 
	D3DXMATRIX Matrix_Transpose; //0x00C8
	char z_cUnknown5[28]; //0x00CC
	float boundingSphereRadius; //0x00E8
	char z_cUnknown6[28]; //0x00EC  
	string object_name; // 0x0108
    byte unknown10[40]; //0x0124  
    __int32 object_end; //0x014C
};*/

class CObject
{
public:
	virtual void Function0(); //0x0000 
	DWORD ObjectFlags; //0x0004 
char _0x0008[4];
	CObject* Obj_Root; //0x000C 
	__int32 object_id; //0x0010 
	CTemplate* Obj_Template; //0x0014 
char _0x0018[16];
	CObject* object_hierarchy_root; //0x0028 
	CObject* object_hierarchy_left; //0x002C 
	CObject* object_hierarchy_right; //0x0030 
char _0x0034[4];
	CGeometry* object_mesh; //0x0038 
	CHealth* Health; //0x003C 
	CCollisionMesh* object_colision; //0x0040 
	CPhysics* Obj_Physics; //0x0044 
char _0x0048[64];
	D3DXMATRIX Matrix; //0x0088 
	D3DXMATRIX Matrix_Transpose; //0x00C8 
	string object_name; //0x0108 
char _0x0124[40];
	__int32 object_end; //0x014C 
char _0x0150[32];
	CPlayerPtr* Obj_PlayerPtr; //0x0170 
	CSoldierPtr* Obj_SoldierPtr; //0x0174 
char _0x0178[36];
	__int32 Obj_Ctrl_Team; //0x019C 
char _0x01A0[92];
	CWeapon* Obj_PrimaryWeapon; //0x01FC 
	CWeapon* Obj_SecondaryWeapon; //0x0200 
char _0x0204[60];

};//Size=0x0240

class CHealth
{
public:
char _0x0000[16];
	float Health; //0x0010 
char _0x0014[108];

};//Size=0x0080

/*class CTemplate
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual int GetTemplateType(void); //virtual int GetTemplateType(void);
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //

	char _0x0004[176]; //176
	float w_gravitymodifier; //0x00B4 
	char _0x00B8[444];
	float N01209E0D; //0x0274 
	float w_velocity; //0x0278 
	char _0x0284[20];
	float w_damage; //0x029C 
	char _0x02A0[188];
};//Size=0x035C*/
class CTemplate
{
public:
	virtual int addRef(); //
	virtual int getRef(); //
	virtual int release(); //
	virtual void* queryInterface(int id); //
	virtual int GetTemplateType(); //
	virtual void function5(); //
	virtual void function6(); //
	virtual void function7(); //
	virtual void function8(); //
	virtual void function9(); //
	virtual string* getTemplateName(); //
	virtual void function11(); //
	virtual void function12(); //
	virtual void function13(); //
	virtual void function14(); //
	virtual void function15(); //
	virtual void function16(); //
	virtual DWORD getFlags(); //
	virtual void function18(); //
	virtual void function19(); //
	virtual void function20(); //
	virtual void function21(); //
	virtual CComponent* getComponent(int id); //

	char unknown0[8]; //0x0004
	string name; //0x000C
	string networkableInfo; //0x0028
	__int32 TemplateID; //0x0044
	char unknown5[40];
	float drag; //0070
	D3DXVECTOR3 dragOffset; //0074
	D3DXVECTOR3 dragModifier; //0080
	float mass; //008C
	D3DXVECTOR3 centerOfMassOffset; //0090
	D3DXVECTOR3 centerOfCollisionOffset; //009C
	D3DXVECTOR3 inertiaModifier; //00A8
	float w_gravitymodifier; //0x00B4 
char _0x00B8[448];
	float w_velocity; //0x0278 
char _0x027C[32];
	float w_damage; //0x029C 
char _0x02A0[32];
	CTemplate_GenericProjectile* projectile_template; //0x02C0 
char _0x02C4[140];
	__int32 VehicleCategory; //0x0350 
char _0x0354[52];
	float w_firerate_; //0x0388 
};//Size=0x0060(96)


/*
class CPhysics
{
public:
char _0x0000[108];
	D3DXVECTOR3 Position; //0x006C 
	D3DXVECTOR3 Speed; //0x0078 
char _0x0084[16];
	D3DXVECTOR3 Rotation; //0x0094 
char _0x00A0[32];

};//Size=0x00C0
*/

class CCamera
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual D3DXMATRIX* GetViewMatrix(int param = 0); //26
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
    virtual void Function21(); //
	virtual float GetInsideFOV(void); //virtual float GetInsideFOV(void);

	__int32 Valid; //0x0004 
	__int32 Perspective; //0x0008 
	char _0x000C[172];
	D3DXMATRIX Matrix; //0x00B8 
	char _0x00F8[16];
};//Size=0x0108

class CSoldierPtr
{
public:
char _0x0000[4];
	CSoldier* Ptr; //0x0004 
char _0x0008[56];
};//Size=0x0040

class CSoldier
{
public:
char _0x0000[20];
	CTemplate* Obj_Template; //0x0014 
char _0x0018[36];
	CHealth* Health; //0x003C 
char _0x0040[4];
	CPhysics* Obj_Physics; //0x0044
char _0x0048[64];
	D3DXMATRIX Matrix; //0x0088
char _0x00C8[240];
	CWeapon* Player_Weapon; //0x01B8 
	char _0x01BC[36];
	__int32 Current_Weapon_Slot; //0x01E0 Soldier_Selected_Weapon
char _0x01E4[64];
	float Body_Yaw; //0x0224 
	float Right_Speed; //0x0228 
	float Forward_Speed; //0x022C 
	__int32 sPosture; //0x0230 
	__int32 sCurPosture; //0x0234 
	float Head_Pitch; //0x0238 
	float Head_Pitch_Change; //0x023C 
	float Head_Yaw; //0x0240 
	float Head_Yaw_Change; //0x0244 
char _0x0248[64];
	CSkeleton* Skeleton_1P; //0x0288 
char _0x028C[4];
	CSkeleton* Skeleton_3P; //0x0290 
char _0x0294[20];
};//Size=0x02A8

class CVehicle
{
public:
		char unknown0[8]; //0x0000
	CTemplate_PlayerControlObject* vehicleTemplate; //0x0008  
		char unknown12[4]; //0x000C
	__int32 hasDriver; //0x0010  
	__int32 vehicleSeat; //0x0014  
	CInfo* ownerPlayer; //0x0018  
	CSoldierPtr* ownerSoldier; //0x001C  
	map<int, CCamera*> cameraMap; //0x0020  
		char unknown44[4]; //0x002C
	CCamera* vehicleCamera; //0x0030  
	map<int, IPlayerControlObject*> passangerMap; //0x0034  
		char unknown64[100]; //0x0040
	CWeapon* weaponPrimary; //0x00A4  
	CWeapon* weaponSecondary; //0x00A8  
		char unknown172[28]; //0x00AC
	__int32 team; //0x00C8  
};//Size=0x00CC(204)

/*class CObject_PlayerControlObject: public CObject
{
public:
	byte unknown10[32];
	CRef<CPlayer>* vehicle_player; //0170
	CRef<CSoldier>* vehicle_soldier; //0174
	byte unknown11[132];
	CWeapon* vehicle_primary_weapon; //01FC
	CWeapon* vehicle_secondary_weapon; //0200
};*/

class CObject_PlayerControlObject: public CObject
{
public:
char _0x0000[368];
	CPlayerPtr* VehiclePlayer; //0x0170 
	CSoldierPtr* VehicleSoldier; //0x0174 
char _0x0178[132];
	CWeapon* VehiclePrimaryWeapon; //0x01FC 
	CWeapon* VehicleSecondaryWeapon; //0x0200 
char _0x0204[572];
};//Size=0x0440

class CWeapon
{
public:
char _0x0000[136];
	D3DXMATRIX w_matrix; //0x0088 
char _0x00C8[212];
	CWeaponTarget* Weapon_Target; //0x019C 
	CDeviation* Weapon_Deviation; //0x01A0 
char _0x01A4[20];
	float Weapon_Heat_Primary; //0x01B8 
	float Weapon_Heat_Secondary; //0x01BC 
char _0x01C0[40];
	CTemplate* Weapon_Template; //0x01E8 
char _0x01EC[596];
};//Size=0x0440

class CObject_Projectile: public CObject
{
};

class CWeaponTarget
{
public:
char _0x0000[28];
	CRef<CObject>* TargetPtr; //0x001C 
char _0x0020[24];
	CComponent_LPTargetComp* Component; //0x0038 
char _0x003C[4];
	BYTE targetIsLocked; //0x0040 
	BYTE targetGotUnlocked; //0x0041 
char _0x0042[2];
	CRef<CObject_Projectile>* TargetProjectilePtr; //0x0044 
char _0x0048[1016];
};


class CDeviation
{
public:
    virtual void function0(); //
    float m_Total; //0x0004  
    float m_CurrentFireDevMod; //0x0008  
    float m_Up; //0x000C  //Up_Devi_Add
    float m_Right; //0x0010  //Right_Devi_Add
    char unknown20[16]; //0x0014
    float m_CurrentMovingDevMod; //0x0024  
    float m_CurrentMiscDevMod; //0x0028  
    float m_CurrentPostureDevMod; //0x002C  
    char unknown48[16]; //0x0030
};//Size=0x0044(68)

class CSkeleton
{
public:
char _0x0000[8];
	CBone* Bones; //0x0008 
char _0x000C[4];
	D3DXMATRIX* matrices; //0x0010 
	__int32 iTotBones; //0x0014 
char _0x0018[232];

};//Size=0x0100

class CBone
{
public:
	__int32 Bone_Number; //0x0000 
	__int16 Bone_Code; //0x0004 
	__int16 Bone_Parent; //0x0006 
char _0x0008[4];
	float Bone_Ofs_x; //0x000C 
	float Bone_Ofs_y; //0x0010 
	float Bone_Ofs_z; //0x0014 
	float Bone_Lenght; //0x0018 
	float Bone_Radius; //0x001C 
	__int32 Bone_Material; //0x0020 
char _0x0024[28];

};//Size=0x0040

//class CObject_PlayerControlObject : public CObject, /*0x0154*/ public IPlayerControlObject
//{
//public:
//};//Size=0x0158(344)

//class CObject_Vehicle : public CObject_PlayerControlObject, /*0x0158*/ public CVehicle
//{
//public:
//};//Size=0x0224(548)

class CPhysicsManager
{
public:
	virtual int addRef(); //
	virtual int getRef(); //
	virtual int release(); //
	virtual void* queryInterface(int id); //
	virtual void function4(); //
	virtual void function5(); //
	virtual void function6(); //
	virtual float getGravity(); //
	virtual void function8(); //
	virtual D3DXVECTOR3* getWind(); //
	virtual void function10(); //
	virtual float getAirDensityZeroAtHeight(); //
		char unknown4[4]; //0x0004
	float gravity; //0x0008  
		char unknown12[12]; //0x000C
	D3DXVECTOR3 wind; //0x0018  
		char unknown36[12]; //0x0024
	float airDensityZeroAtHeight; //0x0030  
};//Size=0x0034(52)

class CPhysics
{
public:
	virtual int addRef(); //
	virtual int getRef(); //
	virtual int release(); //
	virtual void* queryInterface(int id); //
	virtual void function4(); //
	virtual void function5(); //
	virtual void function6(); //
	virtual void function7(); //
	virtual void function8(); //
	virtual void function9(); //
	virtual CObject* getObject(); //
	virtual void function11(); //
	virtual CPhysics* getParentPhysics(); //
	virtual void function13(); //
	virtual D3DXMATRIX* getMatrix(); //
	virtual void setMatrix(D3DXMATRIX* matrix); //
	virtual void function16(); //
	virtual D3DXVECTOR3* getPosition(); //
	virtual void setPosition(D3DXVECTOR3* position); //
	virtual void function19(); //
	virtual void function20(); //
	virtual void function21(); //
	virtual void function22(); //
	virtual D3DXVECTOR3* getImpulseForce(); //
	virtual D3DXVECTOR3* getRotation(); //
	virtual void function25(); //
	virtual void function26(); //
	virtual void function27(); //
	virtual void function28(); //
	virtual void function29(); //
	virtual void function30(); //
	virtual void function31(); //
	virtual void function32(); //
	virtual void function33(); //
	virtual void function34(); //
	virtual void function35(); //
	virtual void function36(); //
	virtual void function37(); //
	virtual void function38(); //
	virtual void function39(); //
	virtual void function40(); //
	virtual void function41(); //
	virtual void function42(); //
	virtual void function43(); //
	virtual void function44(); //
	virtual void function45(); //
	virtual void function46(); //
	virtual void setDrag(float drag); //
	virtual float getDrag(); //
	virtual void function49(); //
	virtual void function50(); //
	virtual void function51(); //
	virtual void function52(); //
	virtual void setMass(float mass); //
	virtual float getMass(); //
	virtual void function55(); //
	virtual void function56(); //
	virtual void function57(); //
	virtual void function58(); //
	virtual void function59(); //
	virtual void function60(); //
	virtual void setGravityModifier(float modefier); //
	virtual float getGravityModifier(); //
	virtual void setHasDriver(bool driver); //
	virtual bool getHasDriver(); //
	virtual void function65(); //
	virtual void function66(); //
	virtual void function67(); //
	virtual void function68(); //
	virtual void function69(); //
	virtual void function70(); //
	virtual void function71(); //
	virtual void function72(); //
	virtual void function73(); //
	virtual void function74(); //
	virtual void function75(); //
	virtual void function76(); //
	virtual void function77(); //
	virtual void function78(); //
	virtual void function79(); //
	virtual void function80(); //
	virtual void function81(); //
	virtual D3DXVECTOR3* getSpeed(); //
	virtual CPhysics* getRootPhysics(); //
	virtual void function84(); //
	virtual void function85(); //
	virtual void function86(); //
	virtual void function87(); //
	virtual void function88(); //
	virtual float getFloaterModifier(); //
		char unknown4[12]; //0x0004
	CObject* ownerObject; //0x0010  
		char unknown20[12]; //0x0014
	D3DXVECTOR3 impulseForce; //0x0020  
		char unknown44[36]; //0x002C
	float drag; //0x0050  
	float mass; //0x0054  
	float gravityModifier; //0x0058  
		char unknown92[4]; //0x005C
	BYTE hasDriver; //0x0060  
		char unknown97[11]; //0x0061
	D3DXVECTOR3 Position; //0x006C  
	D3DXVECTOR3 Speed; //0x0078  
	float floaterMod; //0x0084  
		char unknown136[8]; //0x0088
	__int32 refCount; //0x0090  
	D3DXVECTOR3 Rotation; //0x0094  
		char unknown160[72]; //0x00A0
	D3DXVECTOR3 dragModifier; //0x00E8  
		char unknown244[28]; //0x00F4
	D3DXVECTOR3 inertiaModifier; //0x0110  
};//Size=0x011C(284)

/*
class CRenderer
{
public:
	char _0x0000[8];
	IDirect3D9 * Direct3D_Device; //0x0008 
	IDirect3DDevice9 * Game_Device; //0x000C  
	//char _0x0010[20];
	//D3DXVECTOR2 ScreenInfo; //0x0024 
	char unknown1[1256];
	float ViewDistance; //0x04F8
	char unknown2[419]; //char _0x002C[1648]; //char unknown2[0x3F2];
	//BYTE N00FA8F34; //0x069C 
	//BYTE N01061B57; //0x069D 
	//BYTE N01053840; //0x069E 
	BYTE bDrawWater; //0x069F 
	//BYTE N00FA8F33; //0x06A0 
	//BYTE N01048FDA; //0x06A1 
	BYTE N0104978B; //0x06A2 
	BYTE bShowBodies; //0x06A3 
	BYTE N00FA8F32; //0x06A4 
	BYTE bShowGround; //0x06A5 
	BYTE bShowGrass; //0x06A6 
	BYTE bShowThrees; //0x06A7 
	BYTE bShowFriendlyTags; //0x06A8 Nametags
	//BYTE N00FBAEB4; //0x06A9 
	//BYTE N00FC0334; //0x06AA 
	//BYTE N00FBAEB5; //0x06AB 
	__int32 DrawFps; //0x06AC 
	BYTE N00DCC523; //0x06B0 
	BYTE bShowHud; //0x06B1 
	BYTE bDrawSky; //0x06B2 
	BYTE bDrawSunFlare; //0x06B3 
	BYTE bDrawConsole; //0x06B4 
};//Size=0x06B5
*/

class CRenderer
{
public:
    char unknown0[8]; //0x0000
	IDirect3D9 * Direct3D_Device; //0x0008 
	IDirect3DDevice9 * Game_Device; ; //000C
	char _p001[1256];
	float ViewDistance; //04F8
	char _p002[416];
    BYTE ID07D54FC8; //0x069C  
    BYTE drawObjects; //0x069D  
    BYTE drawDeferred; //0x069E  
    BYTE drawParticles; //0x069F  
    BYTE ID07E1CA70; //0x06A0  
    BYTE drawBundledMeshes; //0x06A1  
    BYTE drawStaticMeshes; //0x06A2  
    BYTE drawSkinnedMeshes; //0x06A3  
    BYTE drawRoads; //0x06A4  
    BYTE drawTerrain; //0x06A5  
    BYTE drawUnderGrowth; //0x06A6  
    BYTE drawOverGrowth; //0x06A7  
    BYTE drawNameTags; //0x06A8  
    BYTE drawTrees; //0x06A9  
    BYTE ID07E1CE70; //0x06AA  
    BYTE ID07E1CDF0; //0x06AB  
    int drawFps; //0x06AC  
    BYTE drawGraphs; //0x06B0  
    BYTE ID07D55048; //0x06B1  
    BYTE drawSkyDome; //0x06B2  
    BYTE drawSunFlare; //0x06B3  
    BYTE drawPostProduction; //0x06B4  
    BYTE ID07D550C8; //0x06B5  
    char unknown1718[6534]; //0x06B6
};//Size=0x203C(8252)

/*
public:
	char _p000[8];
	IDirect3D9 * Direct3D_Device; //0x0008 
	IDirect3DDevice9 * Game_Device; ; //000C
	char _p001[1256];
	float ViewDistance; //04F8
	char _p002[432];
	__int32 drawFps; //06AC
	BYTE drawGraphs; //06B0
	BYTE drawHUD; //06B1
	BYTE drawSkyDome; //06B2
	BYTE drawSunFlare; //06B3
	BYTE drawPostProduction; //06B4
	BYTE ID07D550C8; //06B5
	char _p003[6534]; //0x06B6
*/

class CClassManager
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual int GetClassPtrByName( string* szClassname ); //
};//Size=0x004C(76)

const D3DCOLOR TextOutline = D3DCOLOR_RGBA( 0, 0, 0, 200 );

class CTextWriter
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void DrawText( int x, int y, DWORD txColor, string* Text, BOOL SomeWtfParm = 0 ); 

    void ShadowedText( int x, int y, DWORD txColor, string* Text)
    {
        DrawText( x-1, y, TextOutline, Text );
        DrawText( x+1, y, TextOutline, Text );
        DrawText( x, y-1, TextOutline, Text );
        DrawText( x, y+1, TextOutline, Text );
        DrawText( x, y  , txColor,Text );
    }
};

//class CSpreadTable
//{
//public:
//    float table[1024]; //0x0000  
//};//Size=0x0400(1024) 

struct CSpreadTable
{
	float StaticFloats[1024];
}; 

class CGame
{
public:
    virtual void function0(); //
    virtual void function1(); //
    virtual void function2(); //
    virtual void function3(); //
    virtual void function4(); //
    virtual void function5(); //
    virtual void function6(); //
    virtual void function7(); //
    virtual void function8(); //
    virtual void function9(); //
    virtual void function10(); //
    virtual void function11(); //
    virtual void function12(); //
    virtual void function13(); //
    virtual void function14(); //
    virtual void function15(); //
    virtual void function16(); //
    virtual void function17(); //
    virtual void function18(); //
    virtual void function19(); //
    virtual void function20(); //
    virtual void function21(); //
    virtual void function22(); //
    virtual void function23(); //
    virtual void function24(); //
    virtual void function25(); //
	virtual int getCounter( void ); //
    virtual void function27(); //
    virtual void function28(); //
    virtual void function29(); //
    virtual void function30(); //
    virtual void function31(); //
    virtual void function32(); //
    virtual void function33(); //
    virtual void function34(); //
    virtual void function35(); //
    virtual void function36(); //
    virtual void function37(); //
    virtual void function38(); //
    virtual void function39(); //
    virtual void function40(); //
    virtual void function41(); //
    virtual void function42(); //
    virtual void function43(); //
    virtual void function44(); //
    virtual void function45(); //
    virtual void function46(); //
    virtual void function47(); //
    virtual void function48(); //
    virtual void function49(); //
    virtual void function50(); //
    virtual void function51(); //
    virtual void function52(); //
    virtual void function53(); //
    virtual void function54(); //
    virtual void function55(); //
    virtual void function56(); //
    virtual void function57(); //
    virtual void function58(); //
    virtual void function59(); //
    virtual void function60(); //
    virtual string* getMapName( void ); //
    virtual string* getGameMode( void ); //
};//Size=0x0004(4) 

class CInputManager
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual CActionBuffer* GetNextActionBuffer();
	virtual CActionBuffer* GetCurrentActionBuffer();
};

class CObjectManager
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual CObject* OrigObjectWrapper();// virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual map<int,CObject*>* create_object_map();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual BYTE Intersect( CObject** inter_obj, D3DXVECTOR3* inter_point, D3DXVECTOR3* inter_angle, int* inter_mat, D3DXVECTOR3* ray_start, D3DXVECTOR3* ray_end, CRayTest* ray, BOOL unk1, BOOL unk2, BOOL unk3, BOOL unk4, BOOL unk5 = FALSE );
	char unknown0[28];
	CObject* active_object; //0020
    char unknown1[60];
    map<int, CObject*> object_list; //0x0060 
    char unknown2[68];
	map<int, CObject*> objectMap; //0x00A8 
};

class CRayTest
{
public:
	CRayTest(CObject* obj);
	virtual BYTE TestObject(CObject* obj);
	virtual int  iGetMask(void);
	virtual BYTE function2(int a);
	virtual BYTE TestMaterial(int material);

	DWORD mask;
	CObject* ignore_object;
};

CRayTest::CRayTest(CObject* obj)
{
	mask = 0x100;
	ignore_object = obj;
}
BYTE CRayTest::TestObject(CObject* obj)
{
	if(!obj)
	{
		return byte(mask);
	}

	if(obj->Obj_Root)
		obj = obj->Obj_Root;

	if(obj == ignore_object)
		return FALSE;


	return (obj->ObjectFlags & mask) == mask;
}
int  CRayTest::iGetMask( void )
{
	return mask;
}
BYTE CRayTest::function2(int /*a*/)
{
	return TRUE;
}
BYTE CRayTest::TestMaterial(int /*material*/)
{
	return TRUE;
}

class CDebugLineDrawer
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void DrawLine(void* pLine, DWORD dwColor, float flLength);
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	DWORD dwUnknown; // 4
	DWORD dwUnknown1; // 8
	ID3DXLine* m_pLine;

	void DrawFilledRect(float x0, float y0, float x1, float y1, DWORD dwColor)
	{
		float w = x1 - x0;
		float h = y1 - y0;

		m_pLine->SetWidth(h);
		m_pLine->SetAntialias(0);

		D3DXVECTOR2 VertexList[2];

		VertexList[0].x = x0;
		VertexList[0].y = y0 + (h / 2.0f);

		VertexList[1].x = x0 + w;
		VertexList[1].y = y0 + (h / 2.0f);

		m_pLine->Begin();
		m_pLine->Draw(VertexList, 2, dwColor);
		m_pLine->End();
	}

	void OutlineRect(float x, float y, float w, float h, DWORD dwColor, float flLineWidth = 1.0f)
	{
		m_pLine->SetWidth(flLineWidth);
		m_pLine->SetAntialias(0);

		D3DXVECTOR2 VertexList[5];

		VertexList[0].x = x;
		VertexList[0].y = y;

		VertexList[1].x = x + (w / 2.0f);
		VertexList[1].y = y;

		VertexList[2].x = x + (w / 2.0f);
		VertexList[2].y = y + (h / 2.0f);

		VertexList[3].x = x;
		VertexList[3].y = y + (h / 2.0f);

		VertexList[4].x = x;
		VertexList[4].y = y;

		m_pLine->Begin();
		m_pLine->Draw(VertexList, 5, dwColor);
		m_pLine->End();
	}
};

class CDebugTextWriter
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void DrawText(int x, int y, DWORD txColor, string* Text, BOOL SomeWtfParm = 0);

	void ShadowedText(int x, int y, DWORD txColor, string* Text)
	{
		DrawText(x - 1, y, TextOutline, Text);
		DrawText(x + 1, y, TextOutline, Text);
		DrawText(x, y - 1, TextOutline, Text);
		DrawText(x, y + 1, TextOutline, Text);
		DrawText(x, y, txColor, Text);
	}
};

class CActionBuffer
{
public:
	float InputFlags[64]; //0x0000  
};//Size=0x0040(64)

class CInputDeviceManager
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual CInputDevice* GetDevice(int code);

	char unknown0[4];
	map<int, CInputDevice*> devices; //0008
};

class CInputDevice
{

};

class CControlMapManager
{
public:
 virtual void Function0();
 char unknown0[32];
 CControlMap* active_controlmap; //0024
};

class CHudManagerTV
{
public:
    virtual void Function0();
    byte unknown0[240]; //unknown0[272]
    CHudMouse* HudMouse; //0114
    CHudNode_MiniMap* minimap; //0118
};

class CHudManager
{
public:
	virtual void        Function0();
    virtual void        Function1();
    virtual void        Function2();
    virtual void        Function3();
    virtual void        Function4();
    virtual void        Function5();
    virtual void        Function6();
    virtual void        Function7();
    virtual void        Function8();
    virtual void        Function9();
    virtual void        Function10();
    virtual void        Function11();
    virtual void        Function12();
    virtual void        Function13();
    virtual void        Function14();
    virtual void        Function15();
    virtual void        Function16();
    virtual void        Function17();
    virtual void        Function18();
    virtual void        Function19();
    virtual void        Function20();
    virtual void        Function21();
    virtual void        Function22();
    virtual void        Function23();
    virtual void        Function24();
    virtual void        Function25();
    virtual void        Function26();
    virtual void        Function27();
    virtual void        Function28();
    virtual void        Function29();
    virtual void        Function30();
    virtual void        Function31();
    virtual void        Function32();
    virtual void        Function33();
    virtual void        Function34();
    virtual void        Function35();
    virtual void        Function36();
    virtual void        Function37();
    virtual void        Function38();
    virtual void        Function39();
    virtual void        Function40();
    virtual void        Function41();
    virtual void        Function42();
    virtual void        Function43();
    virtual void        Function44();
    virtual void        Function45();
    virtual void        Function46();
    virtual void        Function47();
    virtual void        Function48();
    virtual void        Function49();
    virtual void        Function50();
    virtual void        Function51();
    virtual void        Function52();
    virtual void        Function53();
    virtual void        Function54();
    virtual void        Function55();
    virtual void        Function56();
    virtual void        Function57();
    virtual void        Function58();
    virtual void        Function59();
    virtual void        Function60();
    virtual void        Function61();
    virtual void        Function62();
    virtual void        Function63();
    virtual void        Function64();
    virtual void        Function65();
    virtual void        Function66();
    virtual void        Function67();
    virtual void        Function68();
    virtual void        Function69();
    virtual void        Function70();
    virtual void        Function71();
    virtual void        Function72();
    virtual void        Function73();
    virtual void        Function74();
    virtual void        Function75();
    virtual void        Function76();
    virtual void        Function77();
    virtual void        Function78();
    virtual void        Function79();
    virtual void        Function80();
    virtual void        Function81();
    virtual void        Function82();
    virtual void        Function83();
    virtual void        Function84();
    virtual void        Function85();
    virtual void        Function86();
    virtual void        Function87();
    virtual void        Function88();
    virtual void        Function89();
    virtual void        Function90();
    virtual void        Function91();
    virtual void        Function92();
    virtual void        Function93();
    virtual void        Function94();
    virtual void        Function95();
    virtual void        Function96();
    virtual void        Function97();
    virtual void        Function98();
    virtual void        Function99();
    virtual void        Function100();
    virtual void        Function101();
    virtual void        Function102();
    virtual void        Function103();
    virtual void        Function104();
    virtual void        Function105();
    virtual void        Function106();
    virtual void        Function107();
    virtual void        Function108();
    virtual void        Function109();
    virtual void        Function110();
    virtual void        Function111();
    virtual void        Function112();
    virtual void        Function113();
    virtual void        Function114();
    virtual void        Function115();
    virtual void        Function116();
    virtual void        Function117();
    virtual void        Function118();
    virtual void        Function119();
    virtual void        Function120();
    virtual void        Function121();
    virtual void        Function122();
    virtual void        Function123();
    virtual void        Function124();
    virtual void        Function125();
    virtual void        Function126();
    virtual void        Function127();
    virtual void        Function128();
    virtual void        Function129();
    virtual void        Function130();
    virtual void        Function131();
    virtual void        Function132();
    virtual void        Function133();
    virtual void        Function134();
    virtual void        Function135();
    virtual void        Function136();
    virtual void        Function137();
    virtual void        Function138();
    virtual void        Function139();
    virtual void        Function140();
    virtual void        Function141();
    virtual void        Function142();
    virtual void        Function143();
    virtual void        Function144();
    virtual void        Function145();
    virtual void        Function146();
    virtual void        Function147();
    virtual void        Function148();
    virtual void        Function149();
    virtual void        Function150();
    virtual void        Function151();
    virtual void        Function152();
    virtual void        Function153();
    virtual void        Function154();
    virtual void        Function155();
    virtual void        Function156();
    virtual void        Function157();
    virtual void        Function158();
    virtual void        Function159();
    virtual void        Function160();
    virtual void        Function161();
    virtual void        Function162();
    virtual void        Function163();
    virtual void        Function164();
    virtual void        Function165();
    virtual void        Function166();
    virtual void        Function167();
    virtual void        Function168();
    virtual void        Function169();
    virtual void        Function170();
    virtual void        Function171();
    virtual void        Function172();
	virtual void        ResignCommander();    //0x2B4
char _0x0004[240];
	CHudMouse* HudMouse; //0x00F4 
	CHudNode_MiniMap* minimap; //0x00F8 
char _0x00FC[52];
	CCrosshair* Crosshair; //0x0130 
char _0x0134[8];
	CCommander_Assets* assets; //0x013C 
char _0x0140[768];

};//Size=0x0440
 
#define CROSSHAIR_NORMAL		0x04 //Normal-Regular
#define CROSSHAIR_ZOOMED		0x34 //Sniper Scope Zoomed
#define CROSSHAIR_SHOTGUN		0x09 //Shotgun

#define CROSSHAIR_ROCKET_LAUNCHER_ZOOM 0x3A //Zoomed Rocket Launcher
#define CROSSHAIR_ROCKET_LAUNCHER 0x00 //Rocket Launcher

#define CROSSHAIR_AH1ZPILOT		0x18 //AH1Z Pilot HUD
#define CROSSHAIR_AH1ZGUNNER	0x1a //AH1Z Gunner (Minigun)

#define CROSSHAIR_MI28PILOT		0x1c //MI28 Pilot HUD
#define CROSSHAIR_MI28GUNNER	0x24 //MI28 Gunner (Minigun)

#define CROSSHAIR_Z10PILOT		0x27 //Z10 Pilot HUD
#define CROSSHAIR_Z10GUNNER		0x28 //Z10 Gunner (Minigun)

#define CROSSHAIR_J10			0x2c //J10
#define CROSSHAIR_SU30			0x2e //SU30
#define CROSSHAIR_SU30_TV       0x30 //SU30 TV MISSILE
#define CROSSHAIR_F35B			0x32 //F35B
#define CROSSHAIR_F15E          0x03 //F15E
#define CROSSHAIR_F15E_TV       0x02 //F15E TV MISSILE
#define CROSSHAIR_FA18E			0x12 //FA18E
#define CROSSHAIR_MIG29			0x1f //MIG29
#define CROSSHAIR_SU34			0x0D //SU34
#define CROSSHAIR_SU34_TV       0x16 //SU34 TV MISSILE

#define CROSSHAIR_CN_AA			0x17 //CHINA-AA 
#define CROSSHAIR_US_AA			0x22 //USMC-AA

#define CROSSHAIR_MEC_APC		0x21 //MEC APC
#define CROSSHAIR_T90			0x07 //T90
#define CROSSHAIR_US_AA1		0x23 //USMC AA Vehicle
#define CROSSHAIR_US_APC		0x0f //USMC APC
#define CROSSHAIR_M1			0x0e //USMC M1 ABRAMS
#define CROSSHAIR_LASER			0x35 //RedDot
#define CROSSHAIR_TOW			0x3B //TOW
#define CROSSHAIR_TV_MEC		0x1d //TV MISSILE MEC
#define CROSSHAIR_TV_US         0x19 //TV MISSILE US
#define CROSSHAIR_TV_CHINA      0x36 //TV MISSILE CHINA
#define CROSSHAIR_DEFIB         0x39 //Defibrillator

class CCrosshair
{
public:
    virtual void Function0();
    char unknown0[0xA0]; //156
    BYTE Type_64;//00A0
    char unknown1[0xD0]; //207
    BYTE Type_32;//0170
};  

class CHudMouse
{
public:
    char unknown0[56];
    float MousePosX; //0038
    float MousePosY; //003C
    float Unknown1; //0040
    float Unknown2; //0044
};
 
class CMiniMap
{
public:
    virtual void Function0();
    char unknown0[905];
    BYTE showKits; //038D
};

class CHudNode
{
public:
		char unknown0[12]; //0x0000
	float x; //0x000C  
	float y; //0x0010  
	float width; //0x0014  
	float height; //0x0018  
		char unknown28[8]; //0x001C
	const char* nodeName; //0x0024  
		char unknown40[20]; //0x0028
};//Size=0x003C(60)

class CHudNode_MiniMap : public CHudNode
{
public:
		char unknown60[72]; //0x003C
	float worldScaleX; //0x0084 1 / GLSWorldSizeX 
	float worldScaleZ; //0x0088 1 / GLSWorldSizeZ 
		char unknown140[1548]; //0x008C
	float zoomMod; //0x0698  
		char unknown1692[160]; //0x069C
	BYTE staticMap; //0x073C  
		char unknown1853[11]; //0x073D
	float clientPosX; //0x0748  
	float clientPosZ; //0x074C  
		char unknown1872[32]; //0x0750
	float rotation; //0x0770  
		char unknown1908[1000]; //0x0774
	float viewX; //0x0B5C  
	float viewY; //0x0B60  
	float viewW; //0x0B64  
	float viewH; //0x0B68  
		char unknown2924[8]; //0x0B6C
	float textureX; //0x0B74  
	float textureY; //0x0B78  
	float textureW; //0x0B7C  
	float textureH; //0x0B80  
};//Size=0x0B84(2948)

 
class CCommander_Assets
{
public:
char _0x0000[16];
	float Artillery1Health; //0x0010 
char _0x0014[4];
	float Artillery2Health; //0x0018 
char _0x001C[20];
	BYTE UAVLoading; //0x0030 
char _0x0031[15];
	float ArtilleryReloadTime; //0x0040 
	BYTE ArtilleryLoading; //0x0044 
char _0x0045[11];
	float SuppliesReloadTime; //0x0050 
char _0x0054[8];
	BYTE SuppliesLoading; //0x005C 
char _0x005D[27];
	float CarsLoadTime; //0x0078 
	float CarsHealth; //0x007C 
char _0x0080[1088];

};//Size=0x04C0

class CComponent
{
public:
	virtual int addRef() = 0; //
	virtual int getRef() = 0; //
	virtual int release() = 0; //
	virtual void* queryInterface(int id) = 0; //
	virtual int getComponentID() = 0; //
};//Size=0x0004(4)

class CComponent_WeaponBasedRecoil : public CComponent
{
public:
	virtual int addRef(); //
	virtual int getRef(); //
	virtual int release(); //
	virtual void* queryInterface(int id); //
	virtual int getComponentID(); //
		char unknown4[4]; //0x0004
	__int32 refCount; //0x0008  
	float recoilForce; //0x000C  
	float recoilSpeed; //0x0010  
	float recoiSpeedGB; //0x0014  
	float recoilSize; //0x0018  
		char unknown28[8]; //0x001C
	float cameraRecoilSpeed; //0x0024  
	float cameraRecoilSize; //0x0028  
};//Size=0x002C(44)

class CComponent_LPTargetComp : public CComponent
{
public:
		char unknown4[8]; //0x0004
	__int32 targetInput; //0x000C  
		char unknown16[69]; //0x0010
	BYTE sendVehicleLockWarning; //0x0055  
		char unknown86[2]; //0x0056
	__int32 connectionEffect; //0x0058  
		char unknown92[24]; //0x005C
	BYTE connectionEffectOnlyWhenZoomed; //0x0074  
		char unknown117[3]; //0x0075
	float maxDistance; //0x0078  
	BYTE setTargetMaxDistance; //0x007C  
	BYTE useCameraDirectionToTarget; //0x007D  
		char unknown126[2]; //0x007E
	__int32 targetSystem; //0x0080  
};//Size=0x0084(132)

class CTemplate_Bundle
{
public:
	virtual int addRef(); //
	virtual int getRef(); //
	virtual int release(); //
	virtual void* queryInterface(int id); //
	virtual void function4(); //addTemplate
	virtual void function5(); //removeTemplate
	virtual void function6(); //
	virtual void function7(); //
	virtual void function8(); //getTemplate
	char unknown4[4]; //0x0004
	CTemplate* subTemplates; //0x0008  
	char unknown26[4]; //0x0018
};//Size=0x001C(28)

class CTemplate_SimpleObject : public CTemplate
{
public:
	virtual int addRef(); //
	virtual int getRef(); //
	virtual int release(); //
	virtual void* queryInterface(int id); //
	virtual void function4(); //
	virtual string* getGeometry(); //
	virtual void mapMaterial(UINT, string*, UINT); //
	virtual void function7(); //
	virtual void function8(); //
	virtual void function9(); //
	virtual void function10(); //
	virtual D3DXVECTOR3* getRelativePositionOffset(); //
	virtual void function12(); //
	virtual bool getHasMobilePhysics(); //
		char unknown100[4]; //0x0064
	__int32 geometryPart; //0x0068  
	__int32 collisionPart; //0x006C  
	float drag; //0x0070  
	D3DXVECTOR3 dragOffset; //0x0074  
	D3DXVECTOR3 dragModefier; //0x0080  
	float mass; //0x008C  
	D3DXVECTOR3 centerOfMassOffset; //0x0090  
	D3DXVECTOR3 centerOfCollisionOffset; //0x009C  
	D3DXVECTOR3 inertiaModefier; //0x00A8  
	float gravityModifier; //0x00B4  
	float floaterMod; //0x00B8  
		char unknown188[24]; //0x00BC
	float treeCollisionDiameter; //0x00D4  
	__int32 otherCollisionLod; //0x00D8  
	DWORD physicsFlags; //0x00DC  
	__int32 physicsType; //0x00E0  
		char unknown228[4]; //0x00E4
	__int32 grip; //0x00E8  
	float handleCollisionSpeed; //0x00EC  
	__int32 collisionGroups; //0x00F0  
	__int32 material; //0x00F4  
	BYTE isPortalPassing; //0x00F8  
		char unknown249[3]; //0x00F9
	D3DXVECTOR3 portalPassingPosition; //0x00FC  
	vector<void*> materialMap; //0x0108  
	BYTE animatedUVTranslation; //0x0118  
		char unknown281[3]; //0x0119
	D3DXVECTOR2 animatedUVTranslationSpeed; //0x011C  
	D3DXVECTOR2 animatedUVTranslationMax; //0x0124  
	D3DXVECTOR2 animatedUVTranslationSize; //0x012C  
	__int32 animatedUVTranslationIndex; //0x0134  
	BYTE animatedUVTranslationReverse; //0x0138  
	BYTE animatedUVRotation; //0x0139  
		char unknown314[2]; //0x013A
	D3DXVECTOR2 animatedUVRotationScale; //0x013C  
	__int32 animatedUVRotationIndex; //0x0144  
	float animatedUVRotationRadius; //0x0148  
	BYTE animatedUVRotationReverse; //0x014C  
	BYTE rotateAsAnimatedUV; //0x014D  
		char unknown334[2]; //0x014E
	string rotateAsAnimatedUVObject; //0x0150  
	BYTE rotateAsAnimatedUVReverse; //0x016C  
		char unknown365[3]; //0x016D
	string geometry; //0x0170  
	string aiTemplate; //0x018C  
	string collisionMesh; //0x01A8  
		char unknown452[28]; //0x01C4
	D3DXVECTOR3 relativePositionOffset; //0x01E0  
		char unknown492[4]; //0x01EC
	D3DXVECTOR3 anchor; //0x01F0  
	D3DXVECTOR3 anchorOffset; //0x01FC  
		char unknown520[8]; //0x0208
};//Size=0x0210(528)

class CTemplate_PlayerControlObject : public CTemplate_SimpleObject, public CTemplate_Bundle /*0x0210*/
{
public:
	virtual int addRef(); //
	virtual int getRef(); //
	virtual int release(); //
	virtual void* queryInterface(int id); //
	__int32 refCount; //0x0230  
	string vehicleName; //0x0234  
		char unknown592[48]; //0x0250
	D3DXVECTOR3 seatPosition; //0x0280  
		char unknown652[4]; //0x028C
	void* seatAnimationSystem; //0x0290  
	float seatLeftRotationLimit; //0x0294  
	float seatRightRotationLimit; //0x0298  
	D3DXVECTOR3 soldierExitPosition; //0x029C  
	D3DXVECTOR3 soldierExitRotation; //0x02A8  
	D3DXVECTOR3 nameTagOffset; //0x02B4  
		char unknown704[16]; //0x02C0
	float cameraShakeTriggers; //0x02D0  
	BYTE dontClearTeamOnExit; //0x02D4  
	BYTE destroyOnExit; //0x02D5  
	BYTE dontAllowExit; //0x02D6  
	BYTE hasRestrictedExit; //0x02D7  
	D3DXVECTOR3 altSoldierExitPosition; //0x02D8  
	float regWhenMinInput; //0x02E4  
	__int32 regulateYawInput; //0x02E8  
	__int32 regulatePitchInput; //0x02EC  
	__int32 regulateRollInput; //0x02F0  
	__int32 regulateVerticalPosInput; //0x02F4  
	D3DXVECTOR2 regulateYaw; //0x02F8  
	D3DXVECTOR2 regulatePitch; //0x0300  
	D3DXVECTOR2 regulateRoll; //0x0308  
	D3DXVECTOR2 regulateVerticalPos; //0x0310  
	float maxVertRegAngle; //0x0318  
	float noVertRegAngle ; //0x031C  
	__int32 pcoId; //0x0320  
	DWORD pcoFlags; //0x0324  
		char unknown808[40]; //0x0328
	__int32 vehicleCategory; //0x0350  
	__int32 controlsCategory; //0x0354  
	__int32 vehicleType; //0x0358  
	__int32 toolTipType; //0x035C  
	BYTE artPos; //0x0360  
		char unknown865[43]; //0x0361
	float exitSpeedMod; //0x038C  
	__int32 disableSpawnPointsOnEnter; //0x0390  
	__int32 vehicleCameraShake; //0x0394  
	float vehicleFov; //0x0398  
	BYTE toggleWeapon; //0x039C  
		char unknown925[3]; //0x039D
	float cockpitLod; //0x03A0  
	float cockpitSubGeom; //0x03A4  
	string soundFilter; //0x03A8  
		char unknown964[12]; //0x03C4
	float shakeFactor; //0x03D0  
	float sprintRecoverTime; //0x03D4  
	float sprintDissipationTime; //0x03D8  
	float sprintLimit; //0x03DC  
	float sprintFactor; //0x03E0  
	BYTE allowDucking; //0x03E4  
	BYTE disableInputWhileDucking; //0x03E5  
	BYTE autoUseAbility; //0x03E6  
		char unknown999[1]; //0x03E7
	__int32 specialToggleWeaponInput; //0x03E8  
	float listenerObstruction; //0x03EC  
	float groundContactVolume; //0x03F0  
	float damagedAmbintSoundLimit; //0x03F4  
	__int32 crewKitIndex; //0x03F8  
	BYTE maintainCameraOnExit; //0x03FC  
	BYTE maintainCameraOnEnter; //0x03FD  
	BYTE neverDrawAs1p; //0x03FE  
	BYTE isOpenVehicle; //0x03FF  
	float boundingRadiusModifierWhenOccupied; //0x0400  
		char unknown1028[64]; //0x0404
};//Size=0x0444(1092)

class CTemplate_RotationalBundle : public CTemplate_SimpleObject, public CTemplate_Bundle /*0x0210*/
{
public:
	D3DXVECTOR3 minRotation; //0x022C  
	D3DXVECTOR3 maxRotation; //0x0238  
	D3DXVECTOR3 pivotPosition; //0x0244  
	D3DXVECTOR3 maxSpeed; //0x0250  
	D3DXVECTOR3 maxResetSpeed; //0x025C  
	D3DXVECTOR3 acceleration; //0x0268  
	D3DXVECTOR3 deAcceleration; //0x0274  
	D3DXVECTOR3 continousRotationSpeed; //0x0280  
	DWORD inputToYaw; //0x028C  
	DWORD inputToPitch; //0x0290  
	DWORD inputToRoll; //0x0294  
	BYTE automaticReset; //0x0298  
	BYTE snapToZeroOnNoInput; //0x0299  
	BYTE useDeAcceleration; //0x029A  
	BYTE restoreRotationOnExit; //0x029B  
	BYTE automaticYawStabilization; //0x029C  
	BYTE automaticPitchStabilization; //0x029D  
	BYTE rememberExcessInput; //0x029E  
	BYTE lesserYawAtSpeedSet; //0x029F  
	float lesserYawAtSpeed; //0x02A0  
	BYTE startAutoRotateOnEnter; //0x02A4  
	BYTE debugAutoRotate; //0x02A5  
		char unknown678[2]; //0x02A6
	D3DXVECTOR2 regulateYaw; //0x02A8  
	D3DXVECTOR2 regulatePitch; //0x02B0  
	D3DXVECTOR2 regulateRoll; //0x02B8  
	BYTE capMaxSpeed; //0x02C0  
		char unknown705[3]; //0x02C1
};//Size=0x02C4(708)


class CTemplate_GenericFireArm: public CTemplate
{
public:
	byte unknown4[80];
	float fire_velocity; //0278
	byte unknown5[4];
	string projectile_template_name; //0x0280 
    char _0x029C[36];
	CTemplate_GenericProjectile* projectile_template; //0x02C0 
};


class CTemplate_GenericProjectile
{
public:
char _0x0000[564];
	__int32 timeToLive_0; //0x0234 
	float timeToLive_1; //0x0238 
	float timeToLive_2; //0x023C 
	float timeToLive_3; //0x0240 
char _0x0244[8];
	float maxTraceScaler; //0x024C 
	float minTraceScaler; //0x0250 
	float traceScaler; //0x0254 
	float traceSizeModifier; //0x0258 
	float timeToRemoveTK; //0x025C 
char _0x0260[76];
	float armingDelay; //0x02AC 
char _0x02B0[4];
	float startDelay; //0x02B4 
char _0x02B8[4];
	float damage; //0x02BC 
	float minDamage; //0x02C0 
	float distToStartLoseDamage; //0x02C4 
	float distToMinDamage; //0x02C8 
	float acceleration; //0x02CC 
	float maxSpeed; //0x02D0 
	BYTE hasOnTimeEffect; //0x02D4 
	BYTE invisible; //0x02D5 
	BYTE addToProjectileList; //0x02D6 
	BYTE useProjectileCamera; //0x02D7 
	BYTE damageOwner; //0x02D8 
	BYTE damageMandownSoldiers; //0x02D9 
	BYTE visibleOn3dMap; //0x02DA 
char _0x02DB[1];
	__int32 mapIcon; //0x02DC 
	__int32 localPredictOnClient; //0x02E0 
char _0x02E4[348];
};//Size=0x0440

class CTemplate_Camera : public CTemplate_RotationalBundle
{
public:
	__int32 hasTarget; //0x02C4  
	__int32 cameraId; //0x02C8  
	BYTE CVMInside; //0x02CC  
	BYTE CVMChase; //0x02CD  
	BYTE CVMFlyBy; //0x02CE  
	BYTE CVMTrace; //0x02CF  
	BYTE CVMExternTrace; //0x02D0  
	BYTE CVMFrontChase; //0x02D1  
	BYTE CVMNose; //0x02D2  
		char unknown723[1]; //0x02D3
	D3DXVECTOR3 nosePos; //0x02D4  
	__int32 toggleMouseLook; //0x02E0  
	float followStiffness; //0x02E4  
	float chaseDistance; //0x02E8  
	float chaseAngle; //0x02EC  
	D3DXVECTOR3 chaseOffset; //0x02F0  
	float cameraSwayRodLength; //0x02FC  
	float cameraSwaySensitivity; //0x0300  
	float cameraSwayDofMax; //0x0304  
	float cameraSwayDofMin; //0x0308  
	float cameraSwayRightMax; //0x030C  
	float cameraSwayRightMin; //0x0310  
	float cameraSwaySpringStrength; //0x0314  
	float cameraSwaySpringDamping; //0x0318  
		char unknown796[80]; //0x031C
	float cameraShakeSensitivity; //0x036C  
	float cameraShakeStartSpeed; //0x0370  
	float cameraShakeMaxSpeed; //0x0374  
	float bounceLength; //0x0378  
	float bounceSensitivity; //0x037C  
	float bounceStrength; //0x0380  
	float bounceDamping; //0x0384  
	float worldFOV; //0x0388  
	float insideFOV; //0x038C  
	BYTE allowInsideDynamicLights; //0x0390  
	BYTE allowInsideStaticSun; //0x0391  
		char unknown914[2]; //0x0392
	D3DXVECTOR3 insideStaticSunDirection; //0x0394  
	D3DXVECTOR3 insideStaticSunColor; //0x03A0  
	D3DXVECTOR3 insideStaticSunDamageColor; //0x03AC  
	float insideDamageFrequency; //0x03B8  
	float insideDamageThreshold; //0x03BC  
	D3DXVECTOR3 insideStaticSunAmbientColor; //0x03C0  
	__int32 cockpitLod; //0x03CC  
	__int32 cockpitSubGeom; //0x03D0  
};//Size=0x03D4(980)

class CPostProductionFrameWork
{
public:
	virtual void Function0();
	char _p000[24];
	BYTE Unknown1; //001C
	BYTE Unknown2; //001D
	BYTE Unknown3; //001E
	BYTE Unknown4; //001F
	float fogColor_r; //0020
	float fogColor_g; //0024
	float fogColor_b; //0028
	float fogStart; //002C
	float fogEnd; //0030
	float fogBase1; //0034
	float fogBase2; //0038
};

class CGlobalSettings
{
public:
virtual void Function0();
__int32 refCount; //0048
string defaultUser; //004C
string namePrefix; //0068
}; 

class CLocalProfileManager
{
public:
virtual void Function0();
char unknown0[4];
__int32 refCount; //0008
CLocalProfile* activeLocalProfile; //000C
char unknown1[40];
string rememberedPassword; //0038
}; 

class CLocalProfile
{
public:
string profileFolder; //0000
string name; //001C
string nick; //0038
string gamespyNick; //0054
string email; //0070
string password; //008C
float totalPlayedTime; //00A8
__int32 numTimesLoggedIn; //00AC
}; 

class CMaterialManager
{
public:
    virtual void Function0();
    virtual void Function1();
    virtual void Function2();
    virtual void Function3();
    virtual void Function4();
    virtual void Function5();
    virtual void Function6();
    virtual void Function7();
    virtual void Function8();
    virtual CMaterial* GetActiveMaterial(void);
    virtual CMaterial* GetMaterial(unsigned int mat_num);
    virtual void Function11();
    virtual void Function12();
    virtual void Function13();
    virtual void Function14();
    virtual void Function15();
    virtual void Function16();
    virtual void Function17();
    virtual void Function18();
    virtual void Function19();
    virtual void Function20();
    virtual void Function22();
    virtual float GetCollisionDamageMultiplier( int projectile, int collided);
    char unknown0[4];
    list<CMaterial*> material_list; //0008
     
    __int32 active_material; //0014
};
     
class CMaterial
{
public:
    virtual void Function0();
    string name; //0004
     
    __int32 type; //0020
    float friction; //0024
    float elasticity; //0028
    float resistance; //002C
    float projectileCollisionHardness; //0030
    float damageLoss; //0034
    float minDamageLoss; //0038
    float maxDamageLoss; //003C
    float penetrationDeviation; //0040
    BYTE overridNeverPenetrate; //0044
    BYTE hasWaterPhysics; //0045
    BYTE isBarbWire; //0046
    BYTE isOneSided; //0047
    BYTE isSeeThrough; //0048
};

CClassManager*		getBFClassManager(void);
CClassManager*		gClassManager = (NULL);
CProfileManager*    gProfileManager = (NULL);
CMainConsole*		gMainConsole = (NULL);
CControlMapManager* gControlMapManager = (NULL);
CControlMap*		gControlMap = (NULL);
CPlayerManager*		gPlayerManager = (NULL);
CPlayer*			gPlayer = (NULL);
CInfo*				gInfo = (NULL);
CObject*			gObject = (NULL);
CHealth*			gHealth = (NULL);
CLocalProfileManager*		gLocalProfileManager = (NULL);
CTemplate*			gTemplate = (NULL);
CPhysics*			gPhysics = (NULL);
CPhysicsManager*	gPhysicsManager = (NULL);
CMaterialManager*	gMaterialManager = (NULL);
CCamera*			gCamera = (NULL);
CSoldierPtr*		gSoldierPtr = (NULL);
CSoldier*			gSoldier = (NULL);
CWeapon*			gWeapon = (NULL);
CDeviation*			gDeviation = (NULL);
CSkeleton*			gSkeleton = (NULL);
CBone*				gBone = (NULL);
CRenderer*			gRenderer = (NULL);
//CRenderer*			g_pRenderer = (NULL);
CGlobalSettings*	gGlobalSettings = (NULL);
//CHudText*			gHudText = (NULL);
//CHudTextMngr*		gHudTextMngr = (NULL);
CHudManager*		gHudManager = (NULL);
//CHudManagerTV*		gHudManagerTV = (NULL);
CHudMouse*			gHudMouse = (NULL);
CActionBuffer*		gActionBuffer = (NULL);
CInputDeviceManager* gInputDeviceManager = (NULL);
CInputManager*		gInputManager = (NULL);
CObjectManager*		gObjectManager = (NULL);
CPostProductionFrameWork* gPostProductionFramework = (NULL);
CRayTest*			gRayTest = (NULL);
CDebugLineDrawer*	gDebugLineDrawer = (NULL);
CDebugTextWriter*	gDebugTextWriter = (NULL);
//CTemplateManager*	gTemplateManager = (NULL);
//DrawOverlay_t		gDrawOverlay = (NULL);
CMiniMap*			gMiniMap = (NULL);
CPostProductionFrameWork* gPostProductionFrameWork = NULL;

CControlMap* control;
CControlMap* GetControlMap(void)
{
	if(!gControlMapManager)
		return FALSE;
	if(!gControlMapManager->active_controlmap)
		return FALSE;
	if(!gControlMapManager->active_controlmap->DegreesPerPixelX || !gControlMapManager->active_controlmap->DegreesPerPixelY)
		return FALSE;

	control = gControlMapManager->active_controlmap;
	return control; 
}

#define WHITE(alpha)         D3DCOLOR_ARGB(alpha, 255, 255, 255)
#define BLACK(alpha)         D3DCOLOR_ARGB(alpha, 0, 0, 0)
#define RED(alpha)           D3DCOLOR_ARGB(alpha, 255, 0, 0)
#define GREEN(alpha)         D3DCOLOR_ARGB(alpha, 0, 128, 0)
#define LAWNGREEN(alpha)     D3DCOLOR_ARGB(alpha, 124, 252, 0)
#define BLUE(alpha)          D3DCOLOR_ARGB(alpha, 0, 200, 255)
#define DEEPSKYBLUE(alpha)   D3DCOLOR_ARGB(alpha, 0, 191, 255)
#define SKYBLUE(alpha)       D3DCOLOR_ARGB(alpha, 0, 122, 204)
#define YELLOW(alpha)        D3DCOLOR_ARGB(alpha, 255, 255, 0)
#define ORANGE(alpha)        D3DCOLOR_ARGB(alpha, 255, 165, 0)
#define DARKORANGE(alpha)    D3DCOLOR_ARGB(alpha, 255, 140, 0)
#define PURPLE(alpha)        D3DCOLOR_ARGB(alpha, 125, 0, 255)
#define CYAN(alpha)          D3DCOLOR_ARGB(alpha, 0, 255, 255)
#define PINK(alpha)          D3DCOLOR_ARGB(alpha, 255, 20, 147)
#define GRAY(alpha)          D3DCOLOR_ARGB(alpha, 128, 128, 128)
#define DARKGRAY(alpha)      D3DCOLOR_ARGB(alpha, 73, 73, 73)
#define DARKERGRAY(alpha)    D3DCOLOR_ARGB(alpha, 31, 31, 31)

enum circle_type {full, half, quarter};
enum text_alignment {lefted, centered, righted};

#define MAX_FONTS 6

struct vertex
{
    FLOAT x, y, z, rhw;
    DWORD color;
};

class CDraw
{
public:
   CDraw()
   {
      g_pVB = NULL;
      g_pIB = NULL;
      int FontNr = 0;
   }

   struct sScreen
   {
      float Width;
      float Height;
      float x_center;
      float y_center;
   } Screen;

   ID3DXFont *cFont[MAX_FONTS];

   void Sprite(LPDIRECT3DTEXTURE9 tex, float x, float y, float resolution, float scale, float rotation);

   //=============================================================================================
   void Line(float x1, float y1, float x2, float y2, float width, bool antialias, DWORD color);

   void Box(float x, float y, float w, float h, float linewidth, DWORD color);
   void BoxFilled(float x, float y, float w, float h, DWORD color);
   void BoxBordered(float x, float y, float w, float h, float border_width, DWORD color, DWORD color_border);
   void BoxRounded(float x, float y, float w, float h,float radius, bool smoothing, DWORD color, DWORD bcolor);

   void Circle(float x, float y, float radius, int rotate, int type, bool smoothing, int resolution, DWORD color);
   void CircleFilled(float x, float y, float rad, float rotate, int type, int resolution, DWORD color);

   void Text(char *text, float x, float y, int orientation, LPD3DXFONT font, bool bordered, DWORD color, DWORD bcolor);
   void Message(char *text, float x, float y, int font, int orientation);
   //=============================================================================================

   //=============================================================================================
   bool Font();
   void AddFont(char* Caption, float size, bool bold, bool italic);
   void FontReset();
   void OnLostDevice();
   //=============================================================================================

   void GetDevice(LPDIRECT3DDEVICE9 pDev) {pDevice = pDev;}
   void Reset();
private:
   LPDIRECT3DDEVICE9 pDevice;
   LPDIRECT3DVERTEXBUFFER9 g_pVB;    // Buffer to hold vertices
   LPDIRECT3DINDEXBUFFER9  g_pIB;    // Buffer to hold indices

   int FontNr;
   LPD3DXSPRITE sSprite;   
};

CDraw Draw;

//============================================================================
//CDRAW FUNCTIONS
//============================================================================
void CDraw::Reset()
{
   D3DVIEWPORT9 screen;
   pDevice->GetViewport(&screen);

   Screen.Width = screen.Width;
   Screen.Height = screen.Height;
   Screen.x_center = Screen.Width/2;
   Screen.y_center = Screen.Height/2;
}

void CDraw::Line(float x1, float y1, float x2, float y2, float width, bool antialias, DWORD color)
{
   ID3DXLine *m_Line;

   D3DXCreateLine(pDevice, &m_Line);
   D3DXVECTOR2 line[] = {D3DXVECTOR2(x1, y1), D3DXVECTOR2(x2, y2)};
   m_Line->SetWidth(width);
   if(antialias) m_Line->SetAntialias(1);
   m_Line->Begin();
   m_Line->Draw(line, 2, color);
   m_Line->End();
   m_Line->Release();
}

void CDraw::Circle(float x, float y, float radius, int rotate, int type, bool smoothing, int resolution, DWORD color)
{
   std::vector<vertex> circle(resolution + 2);   
   float angle = rotate*D3DX_PI/180;   
   float pi;

   if(type == full) pi = D3DX_PI;        // Full circle
   if(type == half) pi = D3DX_PI/2;      // 1/2 circle
   if(type == quarter) pi = D3DX_PI/4;   // 1/4 circle

   for(int i = 0; i < resolution + 2; i++)
   {
      circle[i].x = (float)(x - radius*cos(i*(2*pi/resolution)));
      circle[i].y = (float)(y - radius*sin(i*(2*pi/resolution)));
      circle[i].z = 0;
      circle[i].rhw = 1;
      circle[i].color = color;
   }
   
   // Rotate matrix
   int _res = resolution + 2;
   for(int i = 0; i < _res; i++)
   {
      circle[i].x = x + cos(angle)*(circle[i].x - x) - sin(angle)*(circle[i].y - y);
      circle[i].y = y + sin(angle)*(circle[i].x - x) + cos(angle)*(circle[i].y - y);
   }

   pDevice->CreateVertexBuffer((resolution + 2) * sizeof(vertex), D3DUSAGE_WRITEONLY, D3DFVF_XYZRHW|D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &g_pVB, NULL);
   
   VOID* pVertices;
   g_pVB->Lock(0, (resolution + 2) * sizeof(vertex), (void**)&pVertices, 0);
   memcpy(pVertices, &circle[0], (resolution + 2) * sizeof(vertex));
   g_pVB->Unlock();


   pDevice->SetTexture(0, NULL);
   pDevice->SetPixelShader(NULL);
   if (smoothing)
   {
      pDevice->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
      pDevice->SetRenderState(D3DRS_ANTIALIASEDLINEENABLE, TRUE);
   }
   pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
   pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
   pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

   pDevice->SetStreamSource(0, g_pVB, 0, sizeof(vertex));
   pDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE);

   pDevice->DrawPrimitive(D3DPT_LINESTRIP, 0, resolution);
   if(g_pVB != NULL) g_pVB->Release();
}

void CDraw::CircleFilled(float x, float y, float rad, float rotate, int type, int resolution, DWORD color)
{
   std::vector<vertex> circle(resolution + 2);
   float angle = rotate*D3DX_PI/180;
   float pi;

   if(type == full) pi = D3DX_PI;        // Full circle
   if(type == half) pi = D3DX_PI/2;      // 1/2 circle
   if(type == quarter) pi = D3DX_PI/4;   // 1/4 circle

   circle[0].x = x;
   circle[0].y = y;
   circle[0].z = 0;
   circle[0].rhw = 1;
   circle[0].color = color;   
   
   for(int i = 1; i < resolution + 2; i++)
   {
      circle[i].x = (float)(x - rad*cos(pi*((i-1)/(resolution/2.0f))));
      circle[i].y = (float)(y - rad*sin(pi*((i-1)/(resolution/2.0f))));
      circle[i].z = 0;
      circle[i].rhw = 1;
      circle[i].color = color;
   }
   
   // Rotate matrix
   int _res = resolution + 2;
   for(int i = 0; i < _res; i++)
   {
      circle[i].x = x + cos(angle)*(circle[i].x - x) - sin(angle)*(circle[i].y - y);
      circle[i].y = y + sin(angle)*(circle[i].x - x) + cos(angle)*(circle[i].y - y);
   }

   pDevice->CreateVertexBuffer((resolution + 2) * sizeof(vertex), D3DUSAGE_WRITEONLY, D3DFVF_XYZRHW|D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &g_pVB, NULL );

   VOID* pVertices;
   g_pVB->Lock(0, (resolution + 2) * sizeof(vertex), (void**)&pVertices, 0);
   memcpy(pVertices, &circle[0], (resolution + 2) * sizeof(vertex));
   g_pVB->Unlock();

   pDevice->SetTexture(0, NULL);
   pDevice->SetPixelShader(NULL);
   pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
   pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
   pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

   pDevice->SetStreamSource(0, g_pVB, 0, sizeof(vertex));
   pDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE);
   pDevice->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, resolution);
   if(g_pVB != NULL) g_pVB->Release();
}

void CDraw::Box(float x, float y, float w, float h, float linewidth, DWORD color)
{
   if(linewidth == 0 || linewidth == 1)
   {
      BoxFilled(x, y, w, 1, color);             // Top
      BoxFilled(x, y+h-1, w, 1, color);         // Bottom
      BoxFilled(x, y+1, 1, h-2*1, color);       // Left
      BoxFilled(x+w-1, y+1, 1, h-2*1, color);   // Right
   }
   else
   {
      BoxFilled(x, y, w, linewidth, color);                                     // Top
      BoxFilled(x, y+h-linewidth, w, linewidth, color);                         // Bottom
      BoxFilled(x, y+linewidth, linewidth, h-2*linewidth, color);               // Left
      BoxFilled(x+w-linewidth, y+linewidth, linewidth, h-2*linewidth, color);   // Right
   }
}

void CDraw::BoxBordered(float x, float y, float w, float h, float border_width, DWORD color, DWORD color_border)
{
   BoxFilled(x, y, w, h, color);
   Box(x-border_width, y-border_width, w+2*border_width, h+border_width, border_width, color_border);
}

void CDraw::BoxFilled(float x, float y, float w, float h, DWORD color)
{
   vertex V[4];

   V[0].color = V[1].color = V[2].color = V[3].color = color;

   V[0].z = V[1].z = V[2].z = V[3].z = 0;
   V[0].rhw = V[1].rhw = V[2].rhw = V[3].rhw = 0;

   V[0].x = x;
   V[0].y = y;
   V[1].x = x+w;
   V[1].y = y;
   V[2].x = x+w;
   V[2].y = y+h;
   V[3].x = x;
   V[3].y = y+h;

   unsigned short indexes[] = {0, 1, 3, 1, 2, 3};

   pDevice->CreateVertexBuffer(4*sizeof(vertex), D3DUSAGE_WRITEONLY, D3DFVF_XYZRHW|D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &g_pVB, NULL);
   pDevice->CreateIndexBuffer(2*sizeof(short), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_pIB, NULL);

   VOID* pVertices;
   g_pVB->Lock(0, sizeof(V), (void**)&pVertices, 0);
   memcpy(pVertices, V, sizeof(V));
   g_pVB->Unlock();

   VOID* pIndex;
   g_pIB->Lock(0, sizeof(indexes), (void**)&pIndex, 0);
   memcpy(pIndex, indexes, sizeof(indexes));
   g_pIB->Unlock();

   pDevice->SetTexture(0, NULL);
   pDevice->SetPixelShader(NULL);
   pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
   pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
   pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

   pDevice->SetStreamSource(0, g_pVB, 0, sizeof(vertex));
   pDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE);
   pDevice->SetIndices(g_pIB);

   pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);

   g_pVB->Release();
   g_pIB->Release();
}

void CDraw::BoxRounded(float x, float y, float w, float h, float radius, bool smoothing, DWORD color, DWORD bcolor)
{
   BoxFilled(x+radius, y+radius, w-2*radius-1, h-2*radius-1, color);   // Center rect.
   BoxFilled(x+radius, y+1, w-2*radius-1, radius-1, color);            // Top rect.
   BoxFilled(x+radius, y+h-radius-1, w-2*radius-1, radius, color);     // Bottom rect.
   BoxFilled(x+1, y+radius, radius-1, h-2*radius-1, color);            // Left rect.
   BoxFilled(x+w-radius-1, y+radius, radius, h-2*radius-1, color);     // Right rect.

   // Smoothing method
   if (smoothing)
   {
      CircleFilled(x+radius, y+radius, radius-1, 0, quarter, 16, color);             // Top-left corner
      CircleFilled(x+w-radius-1, y+radius, radius-1, 90, quarter, 16, color);        // Top-right corner
      CircleFilled(x+w-radius-1, y+h-radius-1, radius-1, 180, quarter, 16, color);   // Bottom-right corner
      CircleFilled(x+radius, y+h-radius-1, radius-1, 270, quarter, 16, color);       // Bottom-left corner

      Circle(x+radius+1, y+radius+1, radius, 0, quarter, true, 16, bcolor);          // Top-left corner
      Circle(x+w-radius-2, y+radius+1, radius, 90, quarter, true, 16, bcolor);       // Top-right corner
      Circle(x+w-radius-2, y+h-radius-2, radius, 180, quarter, true, 16, bcolor);    // Bottom-right corner
      Circle(x+radius+1, y+h-radius-2, radius, 270, quarter, true, 16, bcolor);      // Bottom-left corner

      Line(x+radius, y+1, x+w-radius-1, y+1, 1, false, bcolor);       // Top line
      Line(x+radius, y+h-2, x+w-radius-1, y+h-2, 1, false, bcolor);   // Bottom line
      Line(x+1, y+radius, x+1, y+h-radius-1, 1, false, bcolor);       // Left line
      Line(x+w-2, y+radius, x+w-2, y+h-radius-1, 1, false, bcolor);   // Right line
   }
   else
   {
      CircleFilled(x+radius, y+radius, radius, 0, quarter, 16, color);             // Top-left corner
      CircleFilled(x+w-radius-1, y+radius, radius, 90, quarter, 16, color);        // Top-right corner
      CircleFilled(x+w-radius-1, y+h-radius-1, radius, 180, quarter, 16, color);   // Bottom-right corner
      CircleFilled(x+radius, y+h-radius-1, radius, 270, quarter, 16, color);       // Bottom-left corner
   }   
}

void CDraw::Text(char *text, float x, float y, int orientation, LPD3DXFONT font, bool bordered, DWORD color, DWORD bcolor)
{
   RECT rect;

   switch(orientation)
   {
   case lefted:
      if(bordered)
      {
         SetRect(&rect, x - 1, y , x - 1, y);
         font->DrawTextA(NULL,text,-1,&rect, DT_LEFT|DT_NOCLIP, bcolor);
         SetRect(&rect, x + 1, y , x + 1, y);
         font->DrawTextA(NULL,text,-1,&rect, DT_LEFT|DT_NOCLIP, bcolor);
         SetRect(&rect, x , y - 1, x, y - 1);
         font->DrawTextA(NULL,text,-1,&rect, DT_LEFT|DT_NOCLIP, bcolor);
         SetRect(&rect, x , y + 1, x, y + 1);
         font->DrawTextA(NULL,text,-1,&rect, DT_LEFT|DT_NOCLIP, bcolor);
      }
      SetRect(&rect, x, y, x, y);
      font->DrawTextA(NULL,text,-1,&rect, DT_LEFT|DT_NOCLIP, color);
      break;
   case centered:
      if(bordered)
      {
         SetRect(&rect, x - 1, y , x - 1, y);
         font->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, bcolor);
         SetRect(&rect, x + 1, y , x + 1, y);
         font->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, bcolor);
         SetRect(&rect, x , y - 1, x, y - 1);
         font->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, bcolor);
         SetRect(&rect, x , y + 1, x, y + 1);
         font->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, bcolor);
      }
      SetRect(&rect, x, y, x, y);
      font->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, color);
      break;
   case righted:
      if(bordered)
      {
         SetRect(&rect, x - 1, y , x - 1, y);
         font->DrawTextA(NULL,text,-1,&rect, DT_RIGHT|DT_NOCLIP, bcolor);
         SetRect(&rect, x + 1, y , x + 1, y);
         font->DrawTextA(NULL,text,-1,&rect, DT_RIGHT|DT_NOCLIP, bcolor);
         SetRect(&rect, x , y - 1, x, y - 1);
         font->DrawTextA(NULL,text,-1,&rect, DT_RIGHT|DT_NOCLIP, bcolor);
         SetRect(&rect, x , y + 1, x, y + 1);
         font->DrawTextA(NULL,text,-1,&rect, DT_RIGHT|DT_NOCLIP, bcolor);
      }
      SetRect(&rect, x, y, x, y);
      font->DrawTextA(NULL,text,-1,&rect, DT_RIGHT|DT_NOCLIP, color);
      break;
   }
}

void CDraw::Message(char *text, float x, float y, int font, int orientation)
{
   RECT rect = {x, y, x, y};

   switch(orientation)
   {
   case lefted:
      cFont[font]->DrawTextA(NULL,text,-1,&rect, DT_CALCRECT|DT_LEFT, BLACK(255));

      BoxRounded(x - 5, rect.top - 5, rect.right - x + 10, rect.bottom - rect.top + 10, 5, true, DARKGRAY(150), SKYBLUE(255));

      SetRect(&rect, x, y, x, y);
      cFont[font]->DrawTextA(NULL,text,-1,&rect, DT_LEFT|DT_NOCLIP, ORANGE(255));
      break;
   case centered:
      cFont[font]->DrawTextA(NULL,text,-1,&rect, DT_CALCRECT|DT_CENTER, BLACK(255));

      BoxRounded(rect.left - 5 , rect.top - 5, rect.right - rect.left + 10, rect.bottom - rect.top + 10, 5, true, DARKGRAY(150), SKYBLUE(255));

      SetRect(&rect, x, y, x, y);
      cFont[font]->DrawTextA(NULL,text,-1,&rect, DT_CENTER|DT_NOCLIP, ORANGE(255));
      break;
   case righted:
      cFont[font]->DrawTextA(NULL,text,-1,&rect, DT_CALCRECT|DT_RIGHT, BLACK(255));

      BoxRounded(rect.left - 5, rect.top - 5, rect.right - rect.left + 10, rect.bottom - rect.top + 10, 5, true, DARKGRAY(150), SKYBLUE(255));

      SetRect(&rect, x, y, x, y);
      cFont[font]->DrawTextA(NULL,text,-1,&rect, DT_RIGHT|DT_NOCLIP, ORANGE(255));
      break;
   }
}

void CDraw::Sprite(LPDIRECT3DTEXTURE9 tex, float x, float y, float resolution, float scale, float rotation)
{
   float screen_pos_x = x;
   float screen_pos_y = y;

   // Texture being used is 64x64:
   D3DXVECTOR2 spriteCentre = D3DXVECTOR2(resolution/2, resolution/2);

   // Screen position of the sprite
   D3DXVECTOR2 trans = D3DXVECTOR2(screen_pos_x, screen_pos_y);
   
   // Build our matrix to rotate, scale and position our sprite
   D3DXMATRIX mat;

   D3DXVECTOR2 scaling(scale, scale);

   // out, scaling centre, scaling rotation, scaling, rotation centre, rotation, translation
   D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, &spriteCentre, rotation, &trans);

   //pDevice->SetRenderState(D3DRS_ZENABLE, false);
   pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
   pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
   pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
   pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
   pDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
   pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
   pDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1);
   pDevice->SetPixelShader(NULL);
   sSprite->Begin(NULL);
   sSprite->SetTransform(&mat); // Tell the sprite about the matrix
   sSprite->Draw(tex, NULL, NULL, NULL, 0xFFFFFFFF);
   sSprite->End();
}

bool CDraw::Font()
{
   for(int i=0; i<FontNr; i++)
      if(cFont[i]) return false;
   return true;
}

void CDraw::AddFont(char* Caption, float size, bool bold, bool italic)
{
   D3DXCreateFont(pDevice, size, 0, (bold) ? FW_BOLD : FW_NORMAL, 1, (italic) ? 1 : 0 , DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, Caption, &cFont[++FontNr]);
}

void CDraw::FontReset()
{
   for(int i = 0; i < FontNr; i++) cFont[i]->OnLostDevice();
   for(int i = 0; i < FontNr; i++) cFont[i]->OnResetDevice();
}

void CDraw::OnLostDevice()
{
   for(int i = 0; i < FontNr; i++) cFont[i]->OnLostDevice();
}  


