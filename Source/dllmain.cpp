//RAKS BF2 REVIVE/BATTLELOG FRAMEWORK v1.0
//SOURCE COMPILED FROM RESOURCES AT UNKNOWNCHEATS.ME

#include "Include.h"

//================================================================================================================
//Call AimAssist Function
//================================================================================================================
void ItsAimTime()
{
	//Enable Aimbot
	if(Item25)
	{
		//NORMAL/KNIFE AIM - C Key
		if(aimmode == 0)
		{
			if((GetAsyncKeyState(AimKey) & 0x8000) || Item14)
			{
				if((gPlayerManager->GetLocalPlayer()->InVehicle == 1) && ((gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Current_Weapon_Slot == 1) ||
					(gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Current_Weapon_Slot == 6))) KnifeySpooney();
				else DefaultAim();
			}
			else
			{
				if(BestTarget) BestTarget = NULL;    
				if(pRet) pRet = NULL;
				if(pSavedTarget) pSavedTarget = NULL;
				if(LastFrameAimKey) LastFrameAimKey = false;
				if(bAntiShake == 1) bAntiShake = 0;
				if(KnifeTarget) KnifeTarget = NULL;
				aimmode == 2;
			}
		}
		if(aimmode == 1)
		{
			if(GetAsyncKeyState(TVAimKey) & 0x8000)
			{
				if(gPlayerManager->GetLocalPlayer()->InVehicle) aimtvtarget();
			}
			else
			{
				if(BestTarget) BestTarget = NULL;    
				if(pRet) pRet = NULL;
				if(pSavedTarget) pSavedTarget = NULL;
				if(LastFrameAimKey) LastFrameAimKey = false;
				aimmode == 2;
			}
		}
		if(aimmode == 2)
		{
			if(GetAsyncKeyState(AimKey) & 0x8000)
			{
				if(gPlayerManager->GetLocalPlayer()->InVehicle) //DefaultAim();
					Testf();
			}
			else
			{
				if(BestTarget) BestTarget = NULL;    
				if(pRet) pRet = NULL;
				if(pSavedTarget) pSavedTarget = NULL;
				if(LastFrameAimKey) LastFrameAimKey = false;
				if(bAntiShake == 1) bAntiShake = 0;
			}
		}
	}
}

//================================================================================================================
//Present Hook Function
//================================================================================================================
void __stdcall hkPresent(int a)
{
	_asm pushad;
	
	if(bGetLocalPlayer)
	{
		//Get PlayerViewMatrix
		PlayerViewMatrix = &gPlayerManager->GetLocalPlayer()->GetPlayerView()->Matrix;

		//Get PlayerWeaponMatrix
		PlayerWeaponMatrix = &gPlayerManager->GetLocalPlayer()->SoldierObj->Ptr->Player_Weapon->w_matrix;

		//Draw EnemyAimingAtYou Warning
		if(Item8) EnemyIsAimingAtYou(gPlayerManager->GetLocalPlayer());

		//Draw ObjectESP
		if(Item58) ObjectESP();

		//Draw ESP Stuff
		ESPStuff();
	}

	_asm popad;
	oPresent(a);
}

//================================================================================================================
//DrawOverlay Hook Function
//================================================================================================================
void __stdcall hkDrawOverlay(void)
{
	_asm pushad;
	if(pMenu.Visible == 1)
	{
		GetCursorPos(&Cursor);
		pMenu.DrawBorders();
		BuildMenuTabSelect();
		if(tab1) BuildMenuTab1();
		if(tab2) BuildMenuTab2();
		if(tab3) BuildMenuTab3();
		if(tab4) BuildMenuTab4();
		if(tab5) BuildMenuTab5();
		if(tab6) BuildMenuTab6();
		if(tab7) BuildMenuTab7();
		pMenu.DrawMouse();
	}
	_asm popad;
	return oDrawOverlay();
}

//===========================================================================================================================
//Endscene Hooked Function
//===========================================================================================================================
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	_asm pushad;
    if (bGrabbedVP == false)
	{
	    pDevice->GetViewport(&Viewport); //Get Viewport
		bGrabbedVP = true;
	}

	//Create Fonts / Lines/ Shaders / Textures - Do Once!
	if(gRenderer) 
	{
		if(bInitOnce == true) 
		{
			LogFile << "=======================" << endl;
			LogFile << "Create Required Objects" << endl;
			LogFile << "=======================" << endl;
			LogFile << "Begin Function -> InitStuff" << endl;
			InitStuff(); 
		}

		if(bInitLines == true)
		{
			LogFile << "Begin Function -> InitLines" << endl;
			InitLines();
		}

		if(bInitFonts == true)
		{
			LogFile << "Begin Function -> bInitFonts" << endl;
			InitMenuFont();
			InitWMFont();
			InitWarningFont();
			LogFile << endl;
			bInitFonts = false;
		}
	}

	//Log CRenderer->Game_Device & EndScene pDevice
	if(getESdevice == true) 
	{
		if(bInitFonts == false && bInitOnce == false && bInitLines == false)
		{
			LogFile << "====================" << endl;
			LogFile << "DX3D Device Pointers" << endl;
			LogFile << "====================" << endl;
			LogFile << "CRenderer->Game_Device: " << gRenderer->Game_Device << endl;
			LogFile << "EndScene pDevice: " << pDevice << endl;
			getESdevice = false;
		}
	}

	//Listen for Menu Key (DELETE)
	if(GetAsyncKeyState(VK_DELETE) & 1) 
	{
		switch(pMenu.Visible)
		{
			case 0: 
				pMenu.Visible = 1; 
				break;
			
			case 1: 
				pMenu.Visible = 0; 
				writesettings();
				break;
		}
	}

	//Setup GetPlayerView Hook
	bGetLocalPlayer = SetLocalPlayer();

	//PresentDrawFuncs();

	if(bGetLocalPlayer)
	{
		//Call AimAssist
		ItsAimTime();

		//Hook Player Camera
		if(!bHookView)
		{
			CCamera* pCamera = (CCamera*)gPlayerManager->GetLocalPlayer()->GetPlayerView();
			dwGetPlayerView = VMTPatch(*(PDWORD*)pCamera, 4, (DWORD)&hkGetPlayerView);
			bHookView = 1;
			if(dwGetPlayerView)	
			{
				LogFile << "==================" << endl;
				LogFile << "GetPlayerView Hook" << endl;
				LogFile << "==================" << endl;
				LogFile << "Successful: " << (PDWORD)dwGetPlayerView << endl;
				LogFile << endl;
			}
		}

		//Hook ObjectWrapper
		/*if(!bHookObjectWrapper)
		{
			dwOriginalCOWFunctionOffset = VMTPatch(*(PDWORD*)gObjectManager, 5, (DWORD)&createObjectWrapper);
			bHookObjectWrapper = 1;
			if(dwOriginalCOWFunctionOffset)
			{
				LogFile << "==================" << endl;
				LogFile << "ObjectWrapper Hook" << endl;
				LogFile << "Successful: " << (PDWORD)dwOriginalCOWFunctionOffset << endl;
				LogFile << endl;
			}
		}*/

		//
		if(Item61)
		{
            fPanelFullMaker();
		}
	}

	//Draw Crosshair
	if(Item5)
	{
		if(pDevice)
		{
			if(xhairselect == 0)
			{
				DrawXHair(pDevice, d3dColorRed); 
			}

			if(xhairselect == 1)
			{
				float CenterX = Viewport.Width / 2;
				float CenterY = Viewport.Height / 2;
				DrawXHair1(CenterX+10, CenterY+10, CenterX-10, CenterY-10,1,Red);
				DrawXHair1(CenterX-10, CenterY+10, CenterX+10, CenterY-10,1,Red);
			}

			if(xhairselect == 2) 
			{
				DrawXHair2(pDevice, d3dColorRed);
			}

			if(xhairselect == 3)
			{
				DrawXHair3(pDevice, d3dColorGreen);
			}
            
			if(xhairselect == 4)
			{
				DrawXHair4(pDevice, d3dColorGreen);
			}
		}
	}

	//Draw 2D RADAR
	if(Item16)
	{
		float CenterX = (float)Viewport.Width / 2;
	    float CenterY = (float)Viewport.Height / 2;
		int y = (float)Viewport.Height / 2 + Viewport.Y;
		Radar(CenterX - 100, CenterY, 200, 200);
	}

	//Draw Aim FOV
	if(Item38) DrawABFOV();

	//Draw Watermark
	DrawShadowText(Viewport.Width / 2 - 66, 5, d3dColorGreen, "-] RaX Battlefield 2 HaX [-");

	//Draw Aimmodes
	if(aimmode == 0) DrawShadowText(Viewport.Width / 2 - 35, 39, Orange, "Default Mode");
	else if(aimmode == 1) DrawShadowText(Viewport.Width / 2 - 24, 39, White, "TV Mode");
	else if(aimmode == 2) DrawShadowText(Viewport.Width / 2 - 24, 39, Yellow, "Jet Mode");

	//Draw Time
	D3DCOLOR dTime = D3DCOLOR_XRGB( 255, 0, 0 );                         
	GetTimeFormat(NULL,NULL,NULL,NULL,Timestruct,15);   
	sprintf(TimeString,"[ %s ]",Timestruct); 
	DrawShadowText(Viewport.Width / 2 - 36, 22, dTime, TimeString);


	_asm popad;
	return oEndScene(pDevice);
}

//===========================================================================================================================
//DrawIndexedPrimitive Hooked Function
//===========================================================================================================================
HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType, INT BaseVertexIndex, UINT MinIndex, UINT  NumVertices, UINT StartIndex, UINT PrimitiveCount)
{
	//_asm pushad;
	if (pDevice->GetStreamSource(0, &Stream_Data, &Offset, &g_uiStride) == D3D_OK)
		Stream_Data->Release();

	//Log CRenderer->Direct3D_Device &  DrawIndexedPrimitive pDevice
	if(getDIPdevice == true)
	{
		if(bInitFonts == false && bInitOnce == false && bInitLines == false)
		{
			LogFile << "CRenderer->Direct3D_Device: " << gRenderer->Direct3D_Device << endl;
			LogFile << "DrawIndexedPrimitive pDevice: " << pDevice << endl;
			LogFile << endl;
			getDIPdevice = false;
		}
	}

	//Draw Chams
	if (bGetLocalPlayer)
	{
		//CHAMS - USMC SOLDIERS
		if(Item26)
		{
			if(USMCSoldiers)
			{
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Blue2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Green2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//CHAMS - CHINA SOLDIERS
		if(Item27)
		{
			if(PLASoldiers)
			{
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Yellow2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Red2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//CHAMS - MEC SOLDIERS
		if(Item28)
		{
			if(MECSoldiers)
			{
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Purple2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Pink2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//CHAMS - EURO SOLDIERS
		if(Item29)
		{
			if(EUROSoldiers)
			{
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Teal2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Orange2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//CHAMS - VEHICLES
		if(Item30)
		{
			if(VehiclesAll)
			{
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Orange2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Red2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//CHAMS - WEAPONS
		if(Item31)
		{
			if(WeaponsAll)
			{
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Purple2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Pink2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//CHAMS - GROUND WEAPONS
		if (Item32) 
		{
			if (GroundWeapons)
			{	
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Yellow2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Red2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//CHAMS - EXPLOSIVES
		if (Item33) 
		{
			if (Explosives)
			{	
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Yellow2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Red2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//CHAMS - HANDS
		if (Item34)
		{
			if (Hands)
			{
				pGameDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pGameDevice->SetPixelShader(Blue2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pGameDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pGameDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pGameDevice->SetPixelShader(Green2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//ASUS WALLHACK
		if(Item56)
		{
			pGameDevice->SetRenderState( D3DRS_SRCBLEND, 0x5 );
		    pGameDevice->SetRenderState( D3DRS_DESTBLEND, 0x2 );
		    pGameDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );

		    oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
		}

		//WALLHACK
		if(Item57)
		{
			if(VehiclesAll || Explosives || GroundWeapons || AssetsAll)
			{
				pGameDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pGameDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_TRUE);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//NO FOG
	    if(Item6)
	    {
		    pDevice->SetRenderState(D3DRS_FOGENABLE, false);
	    }

		//Removes Player's Hands
		if(Item18){
			if(Hands)
			{
				return 0;
			}
		}

	    //Remove Sky/Overlay
	    if (Item7){
		    if (Sky)
		    {
			    return 0;
		    }
	    }
	    if (Item52){
		    if (ScopeOverlay)
		    {
			    return 0;
		    }
	    }
	    if (Item52){
		    if (TankOverlay)
		    {
			    return 0;
		    }
	    }


	}	

	//_asm popad;
	return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
}

//======================================================================================================================
//Loop Function
//======================================================================================================================
void LoopTime()
{
	while(!GetAsyncKeyState(VK_END) & 1)
	{
		//MINIMAP ON/OFF
		if(Item4) MiniMapEnable();
		else MiniMapDisable();

		//FOG ON/OFF
		//if(Item6) RemoveFOG();
		//else RestoreFOG();

		//VIEWDISTANCE ON/OFF
		if(Item51) ViewDistanceOn();
		else ViewDistanceOff();


		//DRAWFPS ON/OFF
		if(Item15) EnableDrawFPS();
		else DisableDrawFPS();

		//TV STATIC ON/OFF
		if(Item43) RemoveTVStatic();
		else RestoreTVStatic();

		//WEAPON UNLOCKS ON/OFF
		if(Item20) WeaponUnlocksOn();
		else WeaponUnlocksOff();

		//3D MAP ON/OFF
		if(Item53) Enable3DMap();
		else Disable3DMap();

		//ENEMY MINES ON/OFF
		if(Item54) EnemyMinesOn();
		else EnemyMinesOff();

		//RADAR BRIDGE ICONS ON/OFF
		if(Item55) RBIconsOn();
		else RBIconsOff();

		//SPEEDHACK ON KEYPRESS - W/S
		if(Item19) {
			if (GetAsyncKeyState(SPEEDHACK_W) & 0x8000){InputBuffer[3] = SpeedModifier;}
			if (GetAsyncKeyState(SPEEDHACK_S) & 0x8000){InputBuffer[3] = -SpeedModifier;}

			//Decrease Speed Modifier
			if (GetAsyncKeyState(VK_LCONTROL) & 0x8000){
				if (GetAsyncKeyState(VK_SUBTRACT) & 1){
					SpeedModifier = (SpeedModifier -10000000.0f);
					LogFile << "SpeedModifier Decreased" << endl;
				}
			}
			//Increase Speed Modifier
			if (GetAsyncKeyState(VK_LCONTROL) & 0x8000){
				if (GetAsyncKeyState(VK_ADD) & 1){
					SpeedModifier = (SpeedModifier +10000000.0f);
					LogFile << "SpeedModifier Increased" << endl;
				}
			}
		}

		//TEAM SWAP ON KEYPRESS (F5)
		if(GetAsyncKeyState(VK_F5) & 1) {
			if (Item21){
				if(!original_team){ApplyTeamSwitch(1);}
				else{ApplyTeamSwitch(0);}
				LogFile << "Team Swap Key Pressed (F5)" << endl;
			}
		}

		//FORCE COMMANDER ON KEYPRESS (F6)
		if(GetAsyncKeyState(VK_F6) & 1) {
			if (Item22)	{
				if(gPlayerManager->GetLocalPlayer()->commander == 0x00){gPlayerManager->GetLocalPlayer()->commander = (BYTE)0x01;}
				else{gPlayerManager->GetLocalPlayer()->commander = (BYTE)0x00;}
				LogFile << "Force Commander Key Pressed (F6)" << endl;
			}
		}

		//FORCE SQUAD LEADER ON KEYPRESS (F7)
		if(GetAsyncKeyState(VK_F7) & 1) {
			if (Item23) {
				if(gPlayerManager->GetLocalPlayer()->Squad_Leader == 0x00){gPlayerManager->GetLocalPlayer()->Squad_Leader = (BYTE)0x01;}
				else{gPlayerManager->GetLocalPlayer()->Squad_Leader = (BYTE)0x00;}
				LogFile << "Force Squad Leader Key Pressed (F7)" << endl;
			}
		}

		//Squad Jumping Enabled - Listen for Squad Jump Keypress - F8
		if(GetAsyncKeyState(VK_F8) & 1)	{
			if (Item24) {
				int currentsquad = gPlayerManager->GetLocalPlayer()->Squad_Number;
				if (currentsquad == 8)
				{
					gPlayerManager->GetLocalPlayer()->Squad_Number = 0;
					currentsquad = 0;
				}
				else{gPlayerManager->GetLocalPlayer()->Squad_Number = currentsquad + 1;}
				LogFile << "Jump Squads Key Pressed (F8)" << endl;
			}
		}

		//Logger
		if(GetAsyncKeyState(VK_NUMPAD5) & 1) Logger();

		//Clear Log
		//if(GetAsyncKeyState(VK_NUMPAD1) & 1) LogFile.clear();

		//Sleep
		Sleep(200);
	}
}

//============================================================================================================
//MAIN THREAD - Grab Required Addresses + Update Pointers + Apply DX Hooks etc
//============================================================================================================
DWORD WINAPI Main(LPVOID lpParam)
{
	LogFile << "==============" << endl;
	LogFile << "Module Handles" << endl;
	LogFile << "==============" << endl;
	while (hand == 0) hand = GetCurrentProcess();
	LogFile << "CurrentProcess(hand) Found: " << (PDWORD)hand << endl;
	while (dwRendBase == 0)	dwRendBase = (DWORD)GetModuleHandle("RendDX9.dll");
	LogFile << "RendDx9.dll Found: " << (PDWORD)dwRendBase << endl;
	while (dwD3D9Base == 0) dwD3D9Base = (DWORD)GetModuleHandle("d3d9.dll");
	LogFile << "d3d9.dll Found: " << (PDWORD)dwD3D9Base << endl;
	while (dwBF2Base == 0)	dwBF2Base = (DWORD)GetModuleHandle("BF2.exe");
	LogFile << "BF2.exe Found: " << (PDWORD)dwBF2Base << endl;
	LogFile << endl;

	LogFile << "==============" << endl;
	LogFile << "Class Pointers" << endl;
	LogFile << "==============" << endl;

	InitDirInput(GetModuleHandle("BF2.exe"));
	while (!gClassManager){
		gClassManager = *((CClassManager**)(DWORD)0x09FF960);
		//gClassManager = getBFClassManager();
	}

	Sleep(200);

    gProfileManager = (CProfileManager*)gClassManager->GetClassPtrByName(&string("ProfileManager"));
	LogFile << "Profile Manager: " << (PDWORD)gProfileManager << endl;
	dwWorldToScreen = FindPattern(((DWORD)dwRendBase) + 0x80000, 0x20000, (PBYTE)"\x55\x8B\xEC\x81\xEC\x00\x00\x00\x00\x8B\xD\x00\x00\x00\x00\x8B\x1\x56\x57\xFF\x50\x00\x8B\xF0\x8B\x16\x8B\xCE\xFF\x52\x00\xD9\x40", "xxxxx????xx????xxxxxx?xxxxxxxx?xx");
	LogFile << "WorldToScreen: " << dwWorldToScreen << endl;
	gRenderer = (CRenderer*)gClassManager->GetClassPtrByName(&string(RENDDX9_RENDERER));
	LogFile << "Renderer: " << (PDWORD)gRenderer << endl;
	gMainConsole = (CMainConsole*)gClassManager->GetClassPtrByName(&string(BF2_MAINCONSOLE));
	LogFile << "MainConsole: " << (PDWORD)gMainConsole << endl;
	//gMainConsoleObjects = (CMainConsoleObjects*)gClassManager->GetClassPtrByName(&string(BF2_MAINCONSOLEOBJ));
	//LogFile << "MainConsoleObjects: " << (PDWORD)gMainConsoleObjects << endl;
	gPlayerManager = (CPlayerManager*)gClassManager->GetClassPtrByName(&string(BF2_PLAYERMANAGER));
	LogFile << "PlayerManager: " << (PDWORD)gPlayerManager << endl;
	//gTemplateManager = (CTemplateManager*)gClassManager->GetClassPtrByName(&string(BF2_OBJECTTEMPLATEMGR));
	//LogFile << "ObjectTemplateManager: " << (PDWORD)gTemplateManager << endl;
	gObjectManager = (CObjectManager*)gClassManager->GetClassPtrByName(&string(BF2_OBJECTMANAGER));
	LogFile << "ObjectManager: " << (PDWORD)gObjectManager << endl;
	gInputDeviceManager = (CInputDeviceManager*)gClassManager->GetClassPtrByName(&string(BF2_INPUTDEVICEMANAGER));
	LogFile << "InputDeviceManager: " << (PDWORD)gInputDeviceManager << endl;
	gInputManager = (CInputManager*)gClassManager->GetClassPtrByName(&string(BF2_INPUTMANAGER));
	LogFile << "InputManager: " << (PDWORD)gInputManager << endl;
	gControlMapManager = (CControlMapManager*)gClassManager->GetClassPtrByName(&string(BF2_CONTROLMAPMANAGER));
	LogFile << "ControlMapManager: " << (PDWORD)gControlMapManager << endl;
	gHudManager = (CHudManager*)gClassManager->GetClassPtrByName(&string(BF2_HUDMANAGER));
	LogFile << "HudManager: " << (PDWORD)gHudManager << endl;
	gPhysics = (CPhysics*)gClassManager->GetClassPtrByName(&string(BF2_BASICPHYSICSSYS));
	LogFile << "BasicPhysicsSystem: " << (PDWORD)gPhysics << endl;
	gPhysicsManager = (CPhysicsManager*)gClassManager->GetClassPtrByName(&string(BF2_PHYSICSMANAGER));
	LogFile << "PhysicsManager: " << (PDWORD)gPhysicsManager << endl;
	gDebugTextWriter = (CDebugTextWriter*)gClassManager->GetClassPtrByName(&string(BF2_DEBUGTEXTWRITER));
	LogFile << "DebugTextWriter: " << (PDWORD)gDebugTextWriter << endl;
	gDebugLineDrawer = (CDebugLineDrawer*)gClassManager->GetClassPtrByName(&string(BF2_DEBUGLINEDRAWER));
	LogFile << "DebugLineDrawer: " << (PDWORD)gDebugLineDrawer << endl;
	//CRenderer *g_pRenderer = *(CRenderer**)(dwRendBase + 0x23D098);
	gPostProductionFramework = (CPostProductionFrameWork*)gClassManager->GetClassPtrByName(&string(BF2_PostProductionFrameWork));
    LogFile << "PostProductionFramework: " << (PDWORD)gPostProductionFramework << endl;
	gMaterialManager = (CMaterialManager*)gClassManager->GetClassPtrByName(&string(BF2_MATERIALMANAGER));
	LogFile << "MaterialManager: " << (PDWORD)gMaterialManager << endl;
	LogFile << endl;
	
	if(gRenderer)
	{
		//oRenderScreen = (tRenderScreen)HookVTable((PDWORD)gRenderer,(DWORD)hkRenderScreen, 10);
		//LogFile << "RenderScreen: " << (PDWORD)oRenderScreen << endl;
	
		oDrawOverlay = (tDrawOverlay)HookVTable((PDWORD)gRenderer, (DWORD)&hkDrawOverlay, 51);
		oPresent = (tPresent)HookVTable((PDWORD)gRenderer, (DWORD)&hkPresent, 52);
		
		LogFile << "==================" << endl;
		LogFile << "gRenderer Pointers" << endl;
		LogFile << "==================" << endl;
		LogFile << "DrawOverlay: " << oDrawOverlay << endl;	
		LogFile << "Present: " << oPresent << endl;
		LogFile << endl;

		if(!pGameDevice)
		{
			LogFile << "============" << endl;
			LogFile << "Game Devices" << endl;
			LogFile << "============" << endl;
			pGameDevice = gRenderer->Game_Device;
			//DX_Init(&pGameDevice);
			LogFile << "pGameDevice: " << pGameDevice << endl;
			pDirect3DDevice = gRenderer->Direct3D_Device;
			LogFile << "pDirect3DDevice: " << pDirect3DDevice << endl;
			pdwNewGameDevice = (DWORD*)pGameDevice;
			pdwNewGameDevice = (DWORD*)pdwNewGameDevice[0];
			LogFile << "pdwNewGameDevice: " << pdwNewGameDevice << endl;
			LogFile << endl;
		}

		if(!pLine) pLine = gDebugLineDrawer->m_pLine;
	}

	if(pGameDevice)
	{		
		//Perform D3D9 Function Hooks
		if(hooked == false)
		{
			HOOK(EndScene, pdwNewGameDevice[42]);
			HOOK(DrawIndexedPrimitive, pdwNewGameDevice[82]);

			LogFile << "=========================" << endl;
			LogFile << "pdwNewGameDevice Pointers" << endl;
			LogFile << "=========================" << endl;
			LogFile << "EndScene: " << oEndScene << endl;
			LogFile << "DrawIndexedPrimitive: " << oDrawIndexedPrimitive << endl;
			LogFile << endl;
			hooked = true;
		}
	}

	//Hook Action Buffer
	HookActionBuffer();

	//Mouse Hook
	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MouseThread, 0, 0, 0);

	//Run Loop Function
	LoopTime();

	//FreeLibraryAndExitThread((HMODULE)lpParam, 0);

	//AddFontResourceEx("C:\\fonts\\SniffinPaint.ttf", FR_PRIVATE, 0);
	//AddFontResourceEx("C:\\fonts\\ModernVision.ttf", FR_PRIVATE, 0);

	return 0;
}

//================================================================================================================
//PB BLACK SS Function
//================================================================================================================
BOOL WINAPI myGWTPID(HWND hWnd, LPDWORD lpdwProcessId)
{
	DWORD pbclBase = (DWORD)GetModuleHandle("pbcl.dll");
	DWORD bf2pid = GetProcessId(GetCurrentProcess());
	DWORD pbclSize = GetModuleSize(bf2pid);
	DWORD returnAddress = (DWORD)_ReturnAddress();

	if ((returnAddress > pbclBase) && (returnAddress < pbclBase + pbclSize))
		return 0;

	return pOrigGWTPID(hWnd, lpdwProcessId);
}

void startThread(){
    HANDLE DllThread = CreateThread(0, 0, Main, 0, 0, 0);
	Sleep(1000);
    CloseHandle(DllThread);
}

//================================================================================================================
//DLLMAIN Function
//================================================================================================================
BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)	
	{
		//Setup Log File
		LogFile.open("\\RAKS-BF2_FW-LOG.txt");
		LogFile << "=============================" << endl;
		LogFile << "RaKS BF2 Revive Framework Log" << endl;
		LogFile << "=============================" << endl;
		LogFile << "DLL Attached Successfully" << endl;
		LogFile << endl;

		//Setup Black PBSS
		HMODULE user32Mod = LoadLibrary("user32.dll");
		DWORD* GWTPIDaddy = (DWORD*)GetProcAddress(user32Mod, "GetWindowThreadProcessId");
		pOrigGWTPID = (GWTPID)DetourFunction((PBYTE)GWTPIDaddy, (PBYTE)myGWTPID);
		LogFile << "===============" << endl;
		LogFile << "Black PBSS Hook" << endl;
		LogFile << "===============" << endl;
		LogFile << "Successful: " << (PDWORD)GWTPIDaddy << endl;
		LogFile << endl;

		//Read Settings File
		readsettings();

		//Create Thread
		startThread();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		LogFile << endl;
		LogFile << "DLL Detached Successfully" << endl;

		//Close Log File
		LogFile.close();	
	}
	return TRUE;
}