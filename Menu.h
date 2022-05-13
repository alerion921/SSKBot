#pragma once

#include "BF2SDK.h"

template <typename T>
string NumberToString ( T Number )
{
   ostringstream ss;
   ss << Number;
   return ss.str();
}

#define M_PI       3.14159265358979323846
bool bWriteConfig = false;
ofstream LogFile;

//==============================================================
//DECLARES USED IN MENU
//==============================================================
float MaxAimAngle = 300.0f;
float MaxAimDistance = 500.0f;
int Aimbone = 47;
char* cCurBone = "Head";
float AimPrediction = 1.0f;
float espdist = 500.0f;

//==============================================================
//DEVICE --> LPDIRECT3DDEVICE9
//==============================================================
LPDIRECT3DDEVICE9 pGameDevice;

//==============================================================
//FONT --> ID3DXFont / LPD3DXFONT
//==============================================================
LPD3DXFONT pFont = NULL;
LPD3DXFONT WarningFont = NULL;
LPD3DXFONT WatermarkFont = NULL;

//==============================================================
//LINES --> ID3DXLine / LPD3DXLINE
//==============================================================
LPD3DXLINE pLine;
LPD3DXLINE skeletonLine;
LPD3DXLINE snapLine;
LPD3DXLINE boxLine;
LPD3DXLINE menuLine;
LPD3DXLINE circleLine;
LPD3DXLINE xLine;
//==============================================================
//MOUSE --> Cursor
//==============================================================
POINT Cursor;

//==============================================================
//D3DXVECTORS
//==============================================================
D3DXVECTOR2 LineVec[2];
D3DXVECTOR2 CircleVec[2];
D3DXVECTOR2 FilledBoxVec[2];
D3DXVECTOR2 XHairVec[2];
D3DXVECTOR2 SnapLineVec[2]; 
D3DXVECTOR2 SkeletonVec[2];
D3DXVECTOR2 BoxVec[2];

//==============================================================
//COLOURS - XRGB
//==============================================================
#define d3dxColorWhite		D3DCOLOR_XRGB( 255, 255, 255 )
#define d3dxColorRed		D3DCOLOR_XRGB( 255, 0, 0 )
#define d3dxColorBlue		D3DCOLOR_ARGB(155, 0, 0, 255 )
#define d3dxColorYellow		D3DCOLOR_XRGB( 255, 255, 0 )
#define d3dxColorGreen		D3DCOLOR_XRGB(0, 255, 0 )
#define d3dxColorLightBlue	D3DCOLOR_XRGB(0, 191, 255 )
#define d3dxColorBlack		D3DCOLOR_XRGB(0, 0, 0 )
#define d3dxColorGrey		D3DCOLOR_ARGB( 160 ,160, 160, 160 )
#define d3dxColorOrange		D3DCOLOR_XRGB(255, 128, 0)
#define d3dxColorFuscia		D3DCOLOR_XRGB(255, 151, 53)
#define d3dxColorLightGreen D3DCOLOR_XRGB(51, 255, 51)

//==============================================================
//COLOURS - ARGB
//==============================================================
#define Green              D3DCOLOR_ARGB(255, 000, 255, 000)
#define White              D3DCOLOR_ARGB(255, 255, 255, 255)
#define Red                D3DCOLOR_ARGB(255, 255, 000, 000)
#define Blue               D3DCOLOR_ARGB(255, 000, 000, 255)
#define Black              D3DCOLOR_ARGB(255, 000, 000, 000)
#define Black_transparant  D3DCOLOR_ARGB(75, 000, 000, 000)
#define Purple             D3DCOLOR_ARGB(255, 125, 000, 125)
#define Yellow             D3DCOLOR_ARGB(255, 255, 255, 000)
#define Orange             D3DCOLOR_ARGB(255, 255, 125, 000)
#define Grey               D3DCOLOR_ARGB(255, 128, 128, 128)
#define Cyan               D3DCOLOR_ARGB(255, 000, 032, 032)
#define Custom             D3DCOLOR_ARGB(125, 200, 120, 000)

//==============================================================
//COLOURS - REQUIRED FOR MENU
//==============================================================
#define Tab_background     D3DCOLOR_ARGB(155, 000, 000, 000)
#define Tab_rectangle      White
#define Tab_off            White
#define Tab_on             d3dxColorLightBlue
#define Item_off           Tab_off
#define Item_on            Tab_on
#define Item_check         Tab_on
#define Item_current       Orange
#define Menu_background    Tab_background
#define Menu_rectangle     Tab_rectangle
#define Menu_special       D3DCOLOR_ARGB(255,  60,  60,  60)
#define ComboBox_back      White
#define ComboBox_rect      White
#define ComboBox_text      Red
#define Group              White
#define Title              White

//==============================================================
//TEXT DRAWING FUNCTIONS
//==============================================================
void WriteConsoleText(const char* text, int x, int y, DWORD color)
{	
	color |= 0xFF000000;
	RECT pos;
	SetRect(&pos, x, y, 0, 0);
	WarningFont->DrawTextA(NULL, text, -1, &pos, DT_NOCLIP, color);
}

void Textf(int x, int y, DWORD color, const char *fmt, ...)
{
	static char buffer[1024];
	va_list va_alist;
	va_start(va_alist, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, va_alist);
	va_end(va_alist);
	WriteConsoleText(buffer, x, y, color);
}

void MenuText(int x, int y, D3DCOLOR color, const char * Text, int alignment)
{
	RECT FontRect;
	SetRect(&FontRect, x, y, x, y);

	switch(alignment)
	{
		case 0:
			pFont->DrawText(NULL, Text, -1, &FontRect, DT_NOCLIP | DT_CENTER, color);
			break;
		case 1:
			pFont->DrawText(NULL, Text, -1, &FontRect, DT_NOCLIP | DT_LEFT, color);
			break;
		case 2:
			pFont->DrawText(NULL, Text, -1, &FontRect, DT_NOCLIP | DT_RIGHT, color);
			break;
	}
}

void DrawString(int x, int y, D3DCOLOR color, const char *fmt)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = { '\0' };
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	pFont->DrawTextA(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

void DrawShadowText(int x, int y, D3DCOLOR color, char* String)
{
	RECT FontA;
	FontA.bottom = 0;
	FontA.left = x;
	FontA.top = y;
	FontA.right = 0;
	RECT FontS;
	FontS.bottom = 0;
	FontS.left = x + 1;
	FontS.top = y + 1;
	FontS.right = 0;
	WatermarkFont->DrawTextA(NULL, String, -1, &FontS, DT_NOCLIP, 0xFF010101);
	WatermarkFont->DrawTextA(NULL, String, -1, &FontA, DT_NOCLIP, color);
}

//==============================================================
//DRAWLINE FUNCTION
//==============================================================
void DrawLine(int x0, int y0, int x1, int y1, D3DCOLOR color) 
{ 
	pLine->SetWidth(1);
	pLine->SetAntialias(0);
	LineVec[0].x = x0; 
	LineVec[0].y = y0; 
	LineVec[1].x = x1; 
	LineVec[1].y = y1; 
	pLine->Begin();
	pLine->Draw(LineVec, 2, color);
	pLine->End();
}

//=================================================================
//SHAPE FUNCTION - CIRCLE
//=================================================================
void DrawCircleLine(int x0, int y0, int x1 , int y1, D3DCOLOR color)
{
	circleLine->SetWidth(1);
	circleLine->SetAntialias(0);
	CircleVec[0].x = x0; 
	CircleVec[0].y = y0; 
	CircleVec[1].x = x1; 
	CircleVec[1].y = y1; 
	circleLine->Begin();
	circleLine->Draw(CircleVec, 2, color);
	circleLine->End();
}

void Circle(int X, int Y, int radius, int numSides, D3DCOLOR Color)
{
	float Step = (float)(M_PI * 2.0 / numSides);
	int Count = 0;
	for (float a=0; a < M_PI *2.0; a += Step)
	{
		float X1 = (float)(radius * cos(a) + X);
		float Y1 = (float)(radius * sin(a) + Y);
        float X2 = (float)(radius * cos(a + Step) + X);
        float Y2 = (float)(radius * sin(a + Step) + Y);
        if (Count!=0)
        {
			DrawCircleLine(X1, Y1, X2, Y2, Color);
        }
		Count += 2;
	}
}

//=================================================================
//SHAPE FUNCTION - BOXES
//=================================================================
void DrawFilledBox(int x, int y, int w, int h, D3DCOLOR color) //Filled Box
{
	menuLine->SetWidth(w);
	menuLine->SetAntialias(false);
	menuLine->SetGLLines(true);
	FilledBoxVec[0].x = x + w / 2;
	FilledBoxVec[0].y = y;
	FilledBoxVec[1].x = x + w / 2;
	FilledBoxVec[1].y = y + h;
	menuLine->Begin();
	menuLine->Draw(FilledBoxVec, 2, color);
	menuLine->End();
}

void DrawEmptyBox(int x, int y, int w, int h, DWORD color) //Empty Box
{
	DrawLine(x, y, x + w, y, color);
	DrawLine(x + w, y, x + w, y + h, color);
	DrawLine(x + w, y + h, x, y + h, color);
	DrawLine(x, y + h, x, y, color);
}

void FilledBoxBordered(float x, float y, int width, int height, D3DCOLOR fillColor, D3DCOLOR borderColor) //Filled Box with Border
{
    DrawFilledBox(x, y, width, height, fillColor);
    DrawEmptyBox(x-1, y-1, width+2, height+2, borderColor);
}

void FillRGB(int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* dev) //Filled Box - Standalone Function
{
	/*D3DRECT rec = { x, y, x + w, y + h };
	dev->Clear(1, &rec, D3DCLEAR_TARGET, color, 0, 0);*/
	menuLine->SetWidth(w);
	menuLine->SetAntialias(false);
	menuLine->SetGLLines(true);
	FilledBoxVec[0].x = x + w / 2;
	FilledBoxVec[0].y = y;
	FilledBoxVec[1].x = x + w / 2;
	FilledBoxVec[1].y = y + h;
	menuLine->Begin();
	menuLine->Draw(FilledBoxVec, 2, color);
	menuLine->End();
}

//=================================================================
//SHAPE FUNCTION - RECTANGLES
//=================================================================
void DrawEmptyRect(IDirect3DDevice9* dev, int x, int y, int w, int h, D3DCOLOR color) //Empty Rectangle
{
	D3DRECT BarRect = { x, y, x + w, y + h };
	pGameDevice->Clear(1, &BarRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, 0, 0);
}

void DrawFilledRectangle(int x, int y, int w, int h, D3DCOLOR BorderColor) //Filled Rectangle
{
	int px = 1;
	DrawFilledBox(x, (y + h - px), w, px, BorderColor);
	DrawFilledBox(x, y, px, h, BorderColor);
	DrawFilledBox(x, y, w, px, BorderColor);
	DrawFilledBox((x + w - px), y, px, h, BorderColor);
}

//==============================================================
//DRAWING FUNCTION - DOT
//==============================================================
void DrawPoint(int x, int y, int w, int h, DWORD color, IDirect3DDevice9* dev) //Dot Point
{
	FillRGB((int)x, (int)y, (int)w, (int)h, color, dev);
}

//==============================================================
//DRAWING FUNCTION - XHAIRS
//==============================================================
void DrawXHair(IDirect3DDevice9* dev, D3DCOLOR col)
{
	D3DVIEWPORT9 xViewport;
	pGameDevice->GetViewport(&xViewport);
	float ScreenCenterX = (float)xViewport.Width / 2;
	float ScreenCenterY = (float)xViewport.Height / 2;
	D3DRECT rec2 = {ScreenCenterX - 10, ScreenCenterY, ScreenCenterX + 10, ScreenCenterY + 1};
	D3DRECT rec3 = {ScreenCenterX, ScreenCenterY - 10, ScreenCenterX + 1, ScreenCenterY + 10};
	pGameDevice->Clear(1, &rec2, D3DCLEAR_TARGET, col, 0, 0);
	pGameDevice->Clear(1, &rec3, D3DCLEAR_TARGET, col, 0, 0);
}

void DrawXHair1(float x, float y, float x2, float y2, float width, DWORD color)
{
  	xLine->SetWidth(width);
    xLine->SetAntialias(false);
    xLine->SetGLLines(true);
    XHairVec[0].x = x;
    XHairVec[0].y = y;
    XHairVec[1].x = x2;
    XHairVec[1].y = y2;
    xLine->Begin();
    xLine->Draw(XHairVec, 2, color);
    xLine->End();
}

void DrawXHair2(IDirect3DDevice9* dev, D3DCOLOR col)
{
	D3DVIEWPORT9 xViewport;
	pGameDevice->GetViewport(&xViewport);
	float CenterX = (float)xViewport.Width / 2;
	float CenterY = (float)xViewport.Height / 2;
	Circle(CenterX, CenterY, 8, 8, col);
	FillRGB(CenterX-17, CenterY, 10, 1, col, pGameDevice);
	FillRGB(CenterX+9, CenterY, 10, 1, col, pGameDevice);
	FillRGB(CenterX, CenterY-17, 1, 10, col, pGameDevice);
	FillRGB(CenterX, CenterY+9, 1, 10, col, pGameDevice);
	DrawPoint(CenterX, CenterY, 1, 1, col, pGameDevice);
}

void DrawXHair3(IDirect3DDevice9* dev, D3DCOLOR col)
{
	D3DVIEWPORT9 xViewport;
	pGameDevice->GetViewport(&xViewport);
	float CenterX = (float)xViewport.Width / 2;
	float CenterY = (float)xViewport.Height / 2;
	FillRGB(CenterX-20, CenterY, 40, 1,Purple,pGameDevice);//Purple
    FillRGB(CenterX, CenterY-20, 1, 40,Purple,pGameDevice);
    FillRGB(CenterX-17, CenterY, 34, 1,Blue,pGameDevice);//Blue
    FillRGB(CenterX, CenterY-17, 1, 34,Blue,pGameDevice);
    FillRGB(CenterX-14, CenterY, 28, 1,Cyan,pGameDevice);//Cyan
    FillRGB(CenterX, CenterY-14, 1, 28,Cyan,pGameDevice);
    FillRGB(CenterX-11, CenterY, 22, 1,Green,pGameDevice);//Green
    FillRGB(CenterX, CenterY-11, 1, 22,Green,pGameDevice);
    FillRGB(CenterX-9, CenterY, 18, 1,Yellow,pGameDevice);//Yellow
    FillRGB(CenterX, CenterY-9, 1, 18,Yellow,pGameDevice);
    FillRGB(CenterX-6, CenterY, 12, 1,Orange,pGameDevice);//Orange
    FillRGB(CenterX, CenterY-6, 1, 12,Orange,pGameDevice);
    FillRGB(CenterX-3, CenterY, 6, 1,Red,pGameDevice);//Red
    FillRGB(CenterX, CenterY-3, 1, 6,Red,pGameDevice);
}

void DrawXHair4(IDirect3DDevice9* dev, D3DCOLOR col)
{
	D3DVIEWPORT9 xViewport;
	pGameDevice->GetViewport(&xViewport);
	float CenterX = (float)xViewport.Width / 2;
	float CenterY = (float)xViewport.Height / 2;
	DrawXHair1(CenterX+15,CenterY+15,CenterX+3,CenterY+3,2,Green);
    DrawXHair1(CenterX-15,CenterY+15,CenterX-3,CenterY+3,2,Green);
    DrawXHair1(CenterX+15,CenterY-15,CenterX+3,CenterY-3,2,Green);
    DrawXHair1(CenterX-15,CenterY-15,CenterX-3,CenterY-3,2,Green);
    DrawPoint(CenterX, CenterY, 1, 1, Green, pGameDevice);
}

//=================================================================
//ESP LINE FUNCTIONS - SnapLines/SkeletonLines/BoxLines/HealthBars
//=================================================================
void DrawSnapLines(int x0, int y0, int x1, int y1, D3DXCOLOR color) //Snapline Line Function
{ 
	snapLine->SetWidth(1); 
	snapLine->SetAntialias(0); 
	SnapLineVec[0].x = x0; 
	SnapLineVec[0].y = y0; 
	SnapLineVec[1].x = x1; 
	SnapLineVec[1].y = y1; 
	snapLine->Begin(); 
	snapLine->Draw(SnapLineVec, 2, color); 
	snapLine->End(); 
} 

void DrawSkeleton(int x0, int y0, int x1, int y1, D3DXCOLOR color) //Skeleton ESP Line Function
{ 
	skeletonLine->SetWidth(1); 
	skeletonLine->SetAntialias(0); 
	SkeletonVec[0].x = x0; 
	SkeletonVec[0].y = y0; 
	SkeletonVec[1].x = x1; 
	SkeletonVec[1].y = y1; 
	skeletonLine->Begin(); 
	skeletonLine->Draw(SkeletonVec, 2, color); 
	skeletonLine->End(); 
} 

void DrawBoxLines(int x0, int y0, int x1, int y1, D3DXCOLOR color) //ESP Box Line Function
{ 
	boxLine->SetWidth(1); 
	boxLine->SetAntialias(0); 
	BoxVec[0].x = x0; 
	BoxVec[0].y = y0; 
	BoxVec[1].x = x1; 
	BoxVec[1].y = y1; 
	boxLine->Begin(); 
	boxLine->Draw(BoxVec, 2, color); 
	boxLine->End(); 
}

void PlayerBox(int x, int y, int w, int h, DWORD color) //ESP Box Drawing Function
{
	DrawBoxLines(x, y, x + w, y, color);
	DrawBoxLines(x + w, y, x + w, y + h, color);
	DrawBoxLines(x + w, y + h, x, y + h, color);
	DrawBoxLines(x, y + h, x, y, color);
}

void DrawHealthBar3(INT x, INT y, FLOAT health, INT w, INT h, D3DCOLOR color, D3DCOLOR color2) //Health Bar Drawing Function
{
	DrawFilledBox(x, y, w, h - 1, color2);
	UINT hw = (UINT)(((w - 2)*health) / 100);
	DrawFilledBox(x + 1, y + 1, hw, h + 1, color);
}

//================================================================================================================
//MENU CLASS
//================================================================================================================
//TAB1 - ESP
int item2 = 270;
int item1 = 290;
int item3 = 310;
int item37 = 330;
int item10 = 350;
int item11 = 370;
int item9 = 390;
int item42 = 410;
int item13 = 430;
int item16 = 450;
int item17 = 470;

//TAB2 - TEAM
int item21 = 270;
int item22 = 290;
int item23 = 310;
int item24 = 330;
int item61 = 350;

//TAB3 - CHAMS
int item26 = 270;
int item27 = 290;
int item28 = 310;
int item29 = 330;
int item30 = 350;
int item31 = 370;
int item32 = 390;
int item33 = 410;
int item34 = 430;

//TAB4 - AIMBOT
int item25 = 270;
int item12 = 290;
int item43 = 310;
int item36 = 330;
int item39 = 350;
int item38 = 370;
int item41 = 390;
int item14 = 410;
int item45 = 430;

//TAB5 - EXTRAS
int item4 = 270;
int item5 = 290;
int item19 = 310;
int item20 = 330;
int item35 = 350;
int item8 = 370;
int item6 = 390;
int item7 = 410;
int item44 = 430;
int item15 = 450;
int item18 = 470;

//TAB6 - EXTRAS2
int item51 = 270;
int item52 = 290;
int item53 = 310;
int item54 = 330;
int item55 = 350;
int item56 = 370;
int item57 = 390;
int item58 = 410;
int item59 = 430;
int item60 = 450;

//TAB7 - Customs
int item71 = 270;
int item72 = 290;
int item73 = 310;
int item74 = 330;
int item75 = 350;
int item76 = 370;

//UNUSED INTS:
//int item16 = 570;
//int item17 = 590;
//int item18 = 610;

//MENU CHARS
char * mTitle = ".::]RaX Battlefield 2 HaX[::."; //char *
char * mExtra = "http://unknowncheats.me";
char * mCredits = "\nBF2 v1.50 Hack\n\nCoded by RaKS\n\nCredits: UC-FORUM\nModified By: CptMessi";
char * mHackVersion = "Version 1.2";
char * mBF2Version = "BF2 v1.50";
char * mCursor = "+";
char mDescription[256] = "Description: ESP Features.";
char Text[80];

//SCROLL BAR
bool Scroll = false;

//MENU CLASS BEGIN==============================================================================
class menu
{
public:
	menu();

	/* Tab releated */
	void AddTab(char * string, int x, int y, int function);
	void AddCheck(char * string, int x, int y, int function);
	void AddScroll(int x, int y, int height, int position);
	void AddGroup(char * text, int x, int y, int height, int width, int letters);
	void SelectionButton(char ** var, int function, int x, int y);
	void ComboList(char ** var, int x, int y, int width, int function, int maxval);

	/* Customizable tab Related*/
	void AddItemWithValue( char * string, int x, int y, char * value, int function);
	void SwitchItems();
	char* retCAimBone(int AimBone);

	DWORD * SelectionReturn(int x, int y, int function, int maxvalue);
	DWORD * ScrollBar(int x, int y, int height, int position);
	DWORD * ScrollBar_Value(int position);
	DWORD * ReturnFunction(int function, int x, int y);

	/* Menu releated */
	void ShowMenu();
	SHORT MouseClick(int key);
	void DrawMouse();

	/* Look releated */
	void DrawBorders();
	void DrawString(char * string, int x, int y, int color, int f, ID3DXFont * pfont);
	void Rectangle(int x, int y, int w, int h, D3DCOLOR BorderColor);
	void Box(int x, int y, int w, int h, DWORD Color);

	/* Menu defenitions */
	int Visible;

private:
	int Current;
	int List;
	int render;
}; menu pMenu;

menu::menu()
: Visible(0)
{}

void menu::DrawMouse()
{
	MenuText(Cursor.x, Cursor.y, Green, mCursor, 0);
}

void menu::AddTab(char * string, int x, int y, int function) //Box Dimensions [80 width, 30 height]
{
	DrawFilledBox(x - 35, y - 10, 70, 20, Tab_background);
	DrawEmptyBox(x - 35, y - 10, 70, 20, Tab_rectangle);

	if(function < 1)
	{
		MenuText(x, y - 8, Tab_off, string, 0);
	}
	else
	{
		MenuText(x, y - 8, Tab_on, string, 0);
	}
}

void menu::AddCheck(char * string, int x, int y, int function)
{
	if(y > 260 && y < 480)
	{
		DrawEmptyBox(x - 7, y - 7, 14, 14, Black);
		DrawEmptyBox(x - 6, y - 6, 12, 12, Menu_special);

		if (function < 1)
		{
			MenuText(x + 12, y - 8, Item_off, string, 1);
		}
		else
		{
			MenuText(x + 12, y - 8, Item_on, string, 1);
			MenuText(x, y - 8, Item_check, "X", 0);
		}
	}
}

void menu::AddItemWithValue( char * string, int x, int y, char * value, int function)
{
	if(y > 260 && y < 480)
	{
		
		if (function < 1)
		{
			MenuText(x - 8, y - 8, Item_off, string, 1);
		}
		else
		{
			MenuText(x - 8, y - 8, Item_on, string, 1);
		}

		DrawEmptyBox(x + 103, y - 7, 14, 14, Black);
		DrawEmptyBox(x + 104, y - 6, 12, 12, Menu_special);

		DrawEmptyBox(x + 161, y - 7, 14, 14, Black);
		DrawEmptyBox(x + 162, y - 6, 12, 12, Menu_special);

		MenuText(x + 110, y - 8, Item_check, "<", 0);
		MenuText(x + 170, y - 8, Item_check, ">", 0);

		MenuText(x + 120, y - 8, Green, value, 1);
	}
}

void menu::AddScroll(int x, int y, int height, int position)
{
	DrawEmptyBox(x, y, 10, height, Menu_rectangle);
	DrawEmptyBox(x + 1, y + 1, 8, height - 2, Menu_special);
	DrawFilledBox(x + 2, y + 2 + position, 6, 15, Grey);
}

void menu::AddGroup(char * text, int x, int y, int height, int width, int letters)
{
	DrawEmptyBox(x, y, 1, height, Group);
	DrawEmptyBox(x + width, y, 1, height, Group);
	DrawEmptyBox(x, y + height, width, 1, Group);
	MenuText(x + (width / 2), y - 8, Group, text, 0);
	DrawEmptyBox(x, y, (width / 2) - (letters * 4), 1, Group);
	DrawEmptyBox(x + (width / 2) + (letters * 4), y, (width / 2) - (letters * 4), 1, Group);
}

DWORD * menu::ScrollBar(int x, int y, int height, int position)
{
	//Height = y + height	
	if (Cursor.x < x + 10 && Cursor.x > x && Cursor.y < y + (height - 10) && Cursor.y > y)
	{
		if (MouseClick(VK_LBUTTON))
		{
			position = (Cursor.y - y);
			item1 = (y + 30) - (position / 1);
			item2 = (y + 50) - (position / 1);
			item3 = (y + 70) - (position / 1);
			item4 = (y + 90) - (position / 1);
			item5 = (y + 110) - (position / 1);
			item6 = (y + 130) - (position / 1);
			item7 = (y + 150) - (position / 1);
			item8 = (y + 170) - (position / 1);
			item9 = (y + 190) - (position / 1);
			item10 = (y + 210) - (position / 1);
			item11 = (y + 230) - (position / 1);
			item12 = (y + 250) - (position / 1);
			item13 = (y + 270) - (position / 1);
			item14 = (y + 290) - (position / 1);
			item15 = (y + 310) - (position / 1);
			item16 = (y + 330) - (position / 1);
			item17 = (y + 350) - (position / 1);
			item18 = (y + 370) - (position / 1);
		}
	}
	return (DWORD*)position;
}

void menu::SelectionButton(char ** var, int function, int x, int y)
{
	sprintf_s(Text, "%s", var[function]);
	MenuText(x + 1, y - 9, Grey, "<", 0);
	DrawEmptyBox(x - 6, y - 6, 12, 12, Menu_rectangle);
	DrawEmptyBox(x - 7, y - 7, 14, 14, Menu_special);
	MenuText(x + 37, y - 9, White, Text, 0);
	MenuText(x + 73, y - 9, Grey, ">", 0);
	DrawEmptyBox(x + 67, y - 6, 12, 12, Menu_rectangle);
	DrawEmptyBox(x + 66, y - 7, 14, 14, Menu_special);
}

void menu::ComboList(char ** var, int x, int y, int width, int function, int maxval)
{
	//Current item
	int Item = 0;

	char Option1[256];
	char Option2[256];
	char Option3[256];
	char Option4[256];
	char Option5[256];
	char Option6[256];

	DrawFilledBox(x, y, width, 18, ComboBox_back);
	DrawEmptyBox(x, y, width, 18, ComboBox_rect);
	MenuText(x + (width / 2), y + 3, ComboBox_text, Text, 0);
	MenuText(x + (width - 10), y + 3, ComboBox_text, "*", 0);

	if (MouseClick(VK_LBUTTON))
	{
		if (Cursor.x < x + width && Cursor.x > x + (width - 10) && Cursor.y < y + 18 && Cursor.y > y)
		{
			if (List < 1)
			{
				List++;
			}
			else{
				List--;
			}
		}
	}

	if (Cursor.x > x && Cursor.x < x + width)
	{
		if (Cursor.y > y + 38 && Cursor.y < x + 58)	Item = 1;
		if (Cursor.y > y + 58 && Cursor.y < x + 78)	Item = 2;
		if (Cursor.y > y + 78 && Cursor.y < x + 98)	Item = 3;
		if (Cursor.y > y + 98 && Cursor.y < x + 118) Item = 4;
		if (Cursor.y > y + 118 && Cursor.y < x + 138) Item = 5;
		if (Cursor.y > y + 138 && Cursor.y < x + 158) Item = 6;
	}

	if (List)
	{
		DrawFilledBox(x + 20, y + 18, 120 + width, 140, ComboBox_rect);
		DrawFilledBox(x + 20, y + (Item * 20) + 24, 120 + width, 16, Black);
		MenuText(x + (width - 10), y + 3, ComboBox_text, "*", 0);

		if (maxval == 1)
			sprintf_s(Option1, "%s", var[1]);
		MenuText(x + 30, y + 28, ComboBox_text, Option1, 1);
		if (maxval == 2)
			sprintf_s(Option2, "%s", var[2]);
		MenuText(x + 30, y + 48, ComboBox_text, Option2, 1);
		if (maxval == 3)
			sprintf_s(Option3, "%s", var[3]);
		MenuText(x + 30, y + 68, ComboBox_text, Option3, 1);
		if (maxval == 4)
			sprintf_s(Option4, "%s", var[4]);
		MenuText(x + 30, y + 88, ComboBox_text, Option4, 1);
		if (maxval == 5)
			sprintf_s(Option5, "%s", var[5]);
		MenuText(x + 30, y + 108, ComboBox_text, Option5, 1);
		if (maxval == 6)
			sprintf_s(Option6, "%s", var[6]);
		MenuText(x + 30, y + 128, ComboBox_text, Option6, 1);
	}
}

DWORD * menu::SelectionReturn(int x, int y, int function, int maxvalue)
{
	//SelectionReturn Function Off
	if (MouseClick(VK_LBUTTON))
	{
		if (Cursor.x < (x + 6) && Cursor.x >(x - 6) && Cursor.y < (y + 7) && Cursor.y >(y - 7))
		{
			if (function > 0)
			{
				function--;
				Sleep(100);
			}
		}
	}
	
	//SelectionReturn Function On
	if (MouseClick(VK_LBUTTON))
	{
		if (Cursor.x < (x + 79) && Cursor.x >(x + 67) && Cursor.y < (y + 7) && Cursor.y >(y - 7))
		{
			if (function < maxvalue)
			{
				function++;
				Sleep(100);
			}
		}
	}

	return (DWORD*)(function);
}

DWORD * menu::ScrollBar_Value(int position)
{
	position = position / 266;
	return (DWORD*)position;
}

//Listens For Mouse Click to Enable/Disable Functions
DWORD * menu::ReturnFunction(int function, int x, int y)
{
	if(Visible){
		if(MouseClick(VK_LBUTTON))
		{
			if(Cursor.x < x + 10 && Cursor.x > x - 10 && Cursor.y < y + 10 && Cursor.y > y - 10)
			{
				switch(function)
				{
					case 0: function = 1; Sleep(100); break;
					case 1: function = 0; Sleep(100); break;
				}
			}
		}
	}

	return (DWORD*)function;
}

void menu::ShowMenu()
{
	if(GetAsyncKeyState(VK_DELETE) & 1)
	{
		switch(Visible)
		{
			case 0: Visible = 1; break;
			case 1: Visible = 0; break;
		}
	}
}

SHORT menu::MouseClick(int key)
{
	if(GetAsyncKeyState(key) & 0x8000)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void menu::DrawBorders() //ALL Y ADDRESSES ARE +100
{
	/* Main Body Box */
	FillRGB(50, 150, 450, 350, Menu_background, pGameDevice);
	DrawEmptyBox(50, 150, 450, 350, Menu_rectangle);
	DrawEmptyBox(49, 149, 452, 352, Menu_special);

	/* Title Box */
	DrawEmptyBox(50, 150, 450, 20, Menu_rectangle);
	MenuText(275, 152, Title, mTitle, 0);

	/* Item Box */
	DrawEmptyBox(61, 221, 428, 268, Menu_rectangle);
	DrawEmptyBox(60, 220, 430, 270, Menu_special);

	/* Special Box */
	FillRGB(50, 499 + 12, 450, 30, Menu_background, pGameDevice);
	DrawEmptyBox(49, 499 + 12, 452, 30, Menu_special);
	DrawEmptyBox(50, 500 + 12, 450, 28, Menu_rectangle);

	/* BF2 Version Box */
	MenuText(90, 520, Title, mBF2Version, 0);

	/* Hack Version Box */
	MenuText(460, 520, Title, mHackVersion, 0);

	/* URL Box */
	MenuText(275, 520, Title, mExtra, 0);

	/* Function Box */
	DrawEmptyBox(61, 221, 210, 30, Menu_rectangle);
	DrawEmptyBox(270, 221, 1, 30, Menu_rectangle);
	DrawEmptyBox(270, 251, 1, 237, Menu_rectangle);
	DrawEmptyBox(270, 369, 209, 1, Menu_rectangle);
	MenuText(375, 375, Title, mCredits, 0);
	MenuText(375, 227, Title, mDescription, 0);
	MenuText(165, 228, d3dxColorRed, "Functions", 0);
}

void menu::DrawString(char * string, int x, int y, int color, int f, ID3DXFont* pfont)
{
	RECT pText;
	SetRect(&pText, x, y, x, y);

	if(pfont)
	{
		switch(f)
		{
		case 0:
			pFont->DrawText(NULL, string, -1, &pText, DT_NOCLIP | DT_RIGHT, color);
			break;

		case 1:
			pFont->DrawText(NULL, string, -1, &pText, DT_NOCLIP | DT_CENTER, color);
			break;

		case 2:
			pFont->DrawText(NULL, string, -1, &pText, DT_NOCLIP | DT_LEFT, color);
			break;
		}
	}
}

void menu::Box(int x, int y, int w, int h, D3DCOLOR color)
{
	D3DXVECTOR2 mLine[2];
	pLine->SetWidth(w);
	pLine->SetAntialias(false);
	pLine->SetGLLines(true);
	mLine[0].x = x + w / 2;
	mLine[0].y = y;
	mLine[1].x = x + w / 2;
	mLine[1].y = y + h;
	pLine->Begin();
	pLine->Draw(mLine, 2, color);
	pLine->End();
}

void menu::Rectangle(int x, int y, int w, int h, D3DCOLOR BorderColor)
{
	int px = 1;
	Box(x, (y + h - px), w, px, BorderColor);
	Box(x, y, px, h, BorderColor);
	Box(x, y, w, px, BorderColor);
	Box((x + w - px), y, px, h, BorderColor);
}

char *Colors[] = { "Green", "Red", "White", "Blue", "Cyan", "Orange", "Yellow" };
char *ClassX[] = { "Off", "Medic", "Sniper", "Assault", "Heavy Troper", "Engineer" };
char *SpeedX[] = { "Off", "Medium", "Fast", "Super" };

//================================================================================================================
//SETUP D3D9 MENU
//================================================================================================================

//======[Tabs]======//
int tab1 = 1; //ESP
int tab2 = 0; //TEAM
int tab3 = 0; //CHAMS
int tab4 = 0; //AIMBOT
int tab5 = 0; //EXTRAS
int tab6 = 0; //EXTRAS2
int tab7 = 0; //Customs

//======[Tab1]======// ESP
int Item1 = 0; //Distance Tags
int Item2 = 0; //Nametags
int Item3 = 0; //Healthbars
int Item37 = 0; //Player Class
int Item10 = 0; //Player Posture
int Item11 = 0; //Snaplines
int Item9 = 0; //Skeleton ESP
int Item42 = 0; //Box ESP
int Item13 = 0; //Enemy Only ESP
int Item16 = 0; //2D RADAR
int Item17 = 0; //3D BOXES

//======[Tab2]======// TEAM
int Item21 = 0; //Team Swap
int Item22 = 0; //Force Commander
int Item23 = 0; //Force Squad Leader
int Item24 = 0; //Jump Squads
int Item61 = 0; //UnlimitedAssets

//======[Tab3]======// CHAMS
int Item26 = 0; //USMC Soldiers
int Item27 = 0; //CHINA Soldiers
int Item28 = 0; //MEC Soldiers
int Item29 = 0; //EURO Soldiers
int Item30 = 0; //Vehicles
int Item31 = 0; //Weapons
int Item32 = 0; //Ground Weapons
int Item33 = 0; //Explosives
int Item34 = 0; //Hands

//======[Tab4]======// AIMBOT
int Item25 = 0; //Aimbot
int Item12 = 0; //No Spread
int Item43 = 0; //No Shake
int Item36 = 0; //Autoshoot
int Item39 = 0; //Limit Aim Angle
int Item38 = 0; //Aimbot FOV
int Item40 = 0; //Aim at Hidden Objects 
int Item41 = 0; //Aim at Vehicles
int Item14 = 0; //Free-Style
int Item45 = 0; //Ping Correction

//=======[Tab5]======// EXTRAS
int Item4 = 0; //Minimap
int Item5 = 0; //Crosshair
int Item19 = 0; //Speedhack
int Item20 = 0; //Weapon Unlocks
int Item35 = 0; //Enemy Nearby
int Item8 = 0; //AimWarning
int Item6 = 0; //No Fog
int Item7 = 0; //No Sky
int Item44 = 0; //No TV Static
int Item15 = 0; //Draw FPS
int Item18 = 0; //No Hands

//=======[Tab6]======// EXTRAS2
int Item51 = 0; //View Distance
int Item52 = 0; //No Overlay 
int Item53 = 0; //3D Map Icons
int Item54 = 0; //Enemy Mines Icon
int Item55 = 0; //Radar & Bridge Icons
int Item56 = 0; //ASUS Wallhack
int Item57 = 0; //Wallhack
int Item58 = 0; //ObjectESP
int Item59 = 0; //DangerWarning
int Item60 = 0; //Auto-Flares

//=======[Tab7]=======// Customs
int Item71 = 1; // Aim Prediction
int Item72 = 0; // ESP Distance
int Item73 = 0; // Aim Distance
int Item74 = 0; // Aim Angle
int Item75 = 0; // Aim Bone

//////////////////////////////////////////////
//===[Scroll Bar]===//
int Position = 0;   //
int ScrollVal = 0;  //

//============================================================
//CUSTOM TAB STUFF
//============================================================
void menu::SwitchItems()
{
	if(Item71)
	{
		if(GetAsyncKeyState(VK_DOWN) & 1)
		{
			Item71 = 0;
			Item72 = 1;
		}
		else if(GetAsyncKeyState(VK_UP) & 1)
		{
			Item71 = 0;
			Item75 = 1;
		}
	}
	else if(Item72)
	{
		if(GetAsyncKeyState(VK_DOWN) & 1)
		{
			Item72 = 0;
			Item73 = 1;
		}
		else if(GetAsyncKeyState(VK_UP) & 1)
		{
			Item72 = 0;
			Item71 = 1;
		}
	}
	else if(Item73)
	{
		if(GetAsyncKeyState(VK_DOWN) & 1)
		{
			Item73 = 0;
			Item74 = 1;
		}
		else if(GetAsyncKeyState(VK_UP) & 1)
		{
			Item73 = 0;
			Item72 = 1;
		}
	}
	else if(Item74)
	{
		if(GetAsyncKeyState(VK_DOWN) & 1)
		{
			Item74 = 0;
			Item75 = 1;
		}
		else if(GetAsyncKeyState(VK_UP) & 1)
		{
			Item74 = 0;
			Item73 = 1;
		}
	}
	else if(Item75)
	{
		if(GetAsyncKeyState(VK_DOWN) & 1)
		{
			Item75 = 0;
			Item71 = 1;
		}
		else if(GetAsyncKeyState(VK_UP) & 1)
		{
			Item75 = 0;
			Item74 = 1;
		}

	}
}

char* menu::retCAimBone(int AimBone)
{
	char* cBone;
	if(AimBone == 47)
	{
		cBone = "[Head]";
		cCurBone = "Head";
	}
	else if(AimBone == 5)
	{
		cBone = "[FTL]";
		cCurBone = "Left Foot";
	}
	else if(AimBone == 10) 
	{
		cBone = "[FTR]";
		cCurBone = "Right Foot";
	}
	else if(AimBone == 11)
	{
		cBone = "[STM]";
		cCurBone = "Stomach";
	}
	else if(AimBone == 12) 
	{
		cBone = "[BRST]";
		cCurBone = "Breast";
	}
	else if(AimBone == 13) 
	{
		cBone = "[CHST]";
		cCurBone = "Chest";
	}
	else if(AimBone == 20) 
	{
		cBone = "[HNDL]";
		cCurBone = "Left Hand";
	}
	else if(AimBone == 35) 
	{
		cBone = "[HNDR]";
		cCurBone = "Right Hand";
	}
	else
	{
		sprintf(cBone, "[%i]", Aimbone);
		sprintf(cCurBone, "[%i]", Aimbone);
	}

	return cBone;
}

void BuildMenuTab1()
{
	if(tab1)
	{
		pMenu.AddCheck("NameTags", 80, item2, Item2);
		pMenu.AddCheck("DistanceTags", 80, item1, Item1);
		pMenu.AddCheck("HealthBars", 80, item3, Item3);
		pMenu.AddCheck("Player Class", 80, item37, Item37);
		pMenu.AddCheck("Player Posture", 80, item10, Item10);
		pMenu.AddCheck("Snaplines", 80, item11, Item11);
		pMenu.AddCheck("Skeleton ESP", 80, item9, Item9);
		pMenu.AddCheck("Box ESP", 80, item42, Item42);
		pMenu.AddCheck("Draw Team", 80, item13, Item13);
		pMenu.AddCheck("2D RADAR", 80, item16, Item16);
		pMenu.AddCheck("3D Boxes", 80, item17, Item17);
		
		Item2 = (int)pMenu.ReturnFunction(Item2, 80, item2);
		Item1 = (int)pMenu.ReturnFunction(Item1, 80, item1);
		Item3 = (int)pMenu.ReturnFunction(Item3, 80, item3);
		Item37 = (int)pMenu.ReturnFunction(Item37, 80, item37);
		Item10 = (int)pMenu.ReturnFunction(Item10, 80, item10);
		Item11 = (int)pMenu.ReturnFunction(Item11, 80, item11);
		Item9 = (int)pMenu.ReturnFunction(Item9, 80, item9);
		Item42 = (int)pMenu.ReturnFunction(Item42, 80, item42);
		Item13 = (int)pMenu.ReturnFunction(Item13, 80, item13);
		Item16 = (int)pMenu.ReturnFunction(Item16, 80, item16);
		Item17 = (int)pMenu.ReturnFunction(Item17, 80, item17);


		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item2 - 10 && Cursor.y < item2 + 10) sprintf_s(mDescription, "Description: NameTags\nEnable Player NameTags.");
			if (Cursor.y > item1 - 10 && Cursor.y < item1 + 10) sprintf_s(mDescription, "Description: DistanceTags\nEnable Player DistanceTags.");
			if (Cursor.y > item3 - 10 && Cursor.y < item3 + 10) sprintf_s(mDescription, "Description: HealthBars\nEnable Player HealthBars.");
			if (Cursor.y > item37 - 10 && Cursor.y < item37 + 10) sprintf_s(mDescription, "Description: Player Class\nDraw Player Class.");
			if (Cursor.y > item10 - 10 && Cursor.y < item10 + 10) sprintf_s(mDescription, "Description: Player Posture\nDraw Player Posture.");
			if (Cursor.y > item11 - 10 && Cursor.y < item11 + 10) sprintf_s(mDescription, "Description: Snaplines\nDraw Snap Lines to Visible Soldiers.");
			if (Cursor.y > item9 - 10 && Cursor.y < item9 + 10) sprintf_s(mDescription, "Description: Skeleton ESP\nDraw Player Skeleton.");
			if (Cursor.y > item42 - 10 && Cursor.y < item42 + 10) sprintf_s(mDescription, "Description: Box ESP\nDraw Box Around Players.");
			if (Cursor.y > item13 - 10 && Cursor.y < item13 + 10) sprintf_s(mDescription, "Description: Draw Team\nDraws Team ESP Also.");
			if (Cursor.y > item16 - 10 && Cursor.y < item16 + 10) sprintf_s(mDescription, "Description: 2D RADAR\nDraws 2D RADAR.");
			if (Cursor.y > item17 - 10 && Cursor.y < item17 + 10) sprintf_s(mDescription, "Description: 3D Boxes\nDraws 3D Boxes.");
		}
	}
}

void BuildMenuTab2()
{
	if(tab2)
	{
		pMenu.AddCheck("Team Swap", 80, item21, Item21);
		pMenu.AddCheck("Force Commander", 80, item22, Item22);
		pMenu.AddCheck("Force Squad Leader", 80, item23, Item23);
		pMenu.AddCheck("Jump Squads", 80, item24, Item24);
		pMenu.AddCheck("Unlimited CommanderAssets", 80, item61, Item61);

		Item21 = (int)pMenu.ReturnFunction(Item21, 80, item21);
		Item22 = (int)pMenu.ReturnFunction(Item22, 80, item22);
		Item23 = (int)pMenu.ReturnFunction(Item23, 80, item23);
		Item24 = (int)pMenu.ReturnFunction(Item24, 80, item24);
		Item61 = (int)pMenu.ReturnFunction(Item61, 80, item61);
		
		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item21 - 10 && Cursor.y < item21 + 10) sprintf_s(mDescription, "Description: Team Swap\nEnables Team Swap Hotkey.\nPress F5 to Swap Teams");
			if (Cursor.y > item22 - 10 && Cursor.y < item22 + 10) sprintf_s(mDescription, "Description: Force Commander\nEnables Force Commander Hotkey.\nPress F6 to Become Commander");
			if (Cursor.y > item23 - 10 && Cursor.y < item23 + 10) sprintf_s(mDescription, "Description: Force Squad Leader\nEnables Force Squad Leader Hotkey.\nPress F7 to Become Squad Leader");
			if (Cursor.y > item24 - 10 && Cursor.y < item24 + 10) sprintf_s(mDescription, "Description: Jump Squads\nEnables Squad Jumping Hotkey.\nTo Cycle Through Squads\nPress F8");
			if (Cursor.y > item61 - 10 && Cursor.y < item61 + 10) sprintf_s(mDescription, "Description: ~ CommAssets\nEnables Unlimited Comm.\nAssets\n");
		}
	}
}

void BuildMenuTab3()
{
	if(tab3)
	{
		pMenu.AddCheck("USMC Soldiers", 80, item26, Item26);
		pMenu.AddCheck("CHINA Soldiers", 80, item27, Item27);
		pMenu.AddCheck("MEC Soldiers", 80, item28, Item28);
		pMenu.AddCheck("EURO Soldiers", 80, item29, Item29);
		pMenu.AddCheck("Vehicles", 80, item30, Item30);
		pMenu.AddCheck("Weapons", 80, item31, Item31);
		pMenu.AddCheck("Ground Weapons", 80, item32, Item32);
		pMenu.AddCheck("Explosives", 80, item33, Item33);
		pMenu.AddCheck("Hands", 80, item34, Item34);

		Item26 = (int)pMenu.ReturnFunction(Item26, 80, item26);
		Item27 = (int)pMenu.ReturnFunction(Item27, 80, item27);
		Item28 = (int)pMenu.ReturnFunction(Item28, 80, item28);
		Item29 = (int)pMenu.ReturnFunction(Item29, 80, item29);
		Item30 = (int)pMenu.ReturnFunction(Item30, 80, item30);
		Item31 = (int)pMenu.ReturnFunction(Item31, 80, item31);
		Item32 = (int)pMenu.ReturnFunction(Item32, 80, item32);
		Item33 = (int)pMenu.ReturnFunction(Item33, 80, item33);
		Item34 = (int)pMenu.ReturnFunction(Item34, 80, item34);

		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item26 - 10 && Cursor.y < item26 + 10) sprintf_s(mDescription, "Description: USMC Soldiers\nEnable USMC Soldier Chams.");
			if (Cursor.y > item27 - 10 && Cursor.y < item27 + 10) sprintf_s(mDescription, "Description: CHINA Soldiers\nEnable CHINA Soldier Chams.");
			if (Cursor.y > item28 - 10 && Cursor.y < item28 + 10) sprintf_s(mDescription, "Description: MEC Soldiers\nEnable MEC Soldier Chams.");
			if (Cursor.y > item29 - 10 && Cursor.y < item29 + 10) sprintf_s(mDescription, "Description: EURO Soldiers\nEnable EURO Soldiers Chams.");
			if (Cursor.y > item30 - 10 && Cursor.y < item30 + 10) sprintf_s(mDescription, "Description: Vehicles\nEnable Vehicle Chams.");
			if (Cursor.y > item31 - 10 && Cursor.y < item31 + 10) sprintf_s(mDescription, "Description: Weapons\nEnable Weapon Chams.");
			if (Cursor.y > item32 - 10 && Cursor.y < item32 + 10) sprintf_s(mDescription, "Description: Ground Weapons\nEnable Ground Weapon Chams.");
			if (Cursor.y > item33 - 10 && Cursor.y < item33 + 10) sprintf_s(mDescription, "Description: Explosives\nEnable Explosive Chams.");
			if (Cursor.y > item34 - 10 && Cursor.y < item34 + 10) sprintf_s(mDescription, "Description: Hands\nEnable Hand Chams.");
		}
	}
}

void BuildMenuTab4()
{
	if(tab4)
	{
		pMenu.AddCheck("Aimbot", 80, item25, Item25);
		pMenu.AddCheck("No Spread", 80, item12, Item12);
		pMenu.AddCheck("No Shake", 80, item43, Item43);
		pMenu.AddCheck("Autoshoot", 80, item36, Item36);
		pMenu.AddCheck("Limit Aim Angle", 80, item39, Item39);
		pMenu.AddCheck("Draw Aim FOV", 80, item38, Item38);
		pMenu.AddCheck("Aim at Vehicles", 80, item41, Item41);
		pMenu.AddCheck("Free-Style", 80, item14, Item14);
		pMenu.AddCheck("Ping Correction", 80, item45, Item45);

		Item25 = (int)pMenu.ReturnFunction(Item25, 80, item25);
		Item12 = (int)pMenu.ReturnFunction(Item12, 80, item12);
		Item43 = (int)pMenu.ReturnFunction(Item43, 80, item43);
		Item36 = (int)pMenu.ReturnFunction(Item36, 80, item36);
		Item39 = (int)pMenu.ReturnFunction(Item39, 80, item39);
		Item38 = (int)pMenu.ReturnFunction(Item38, 80, item38);
		Item41 = (int)pMenu.ReturnFunction(Item41, 80, item41);
		Item14 = (int)pMenu.ReturnFunction(Item14, 80, item14);
		Item45 = (int)pMenu.ReturnFunction(Item45, 80, item45);

		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item25 - 10 && Cursor.y < item25 + 10) sprintf_s(mDescription, "Description: Aimbot\nEnables Aimbot.\nAim Key = Middle Mouse");
			if (Cursor.y > item12 - 10 && Cursor.y < item12 + 10) sprintf_s(mDescription, "Description: No Spread\nEnables No Spread for Aimbot.");
			if (Cursor.y > item43 - 10 && Cursor.y < item43 + 10) sprintf_s(mDescription, "Description: No Shake\nDisables No Spread Screen Shaking.");
			if (Cursor.y > item36 - 10 && Cursor.y < item36 + 10) sprintf_s(mDescription, "Description: Autoshoot\nAutoshoot when Aimkey Pressed.");
			if (Cursor.y > item39 - 10 && Cursor.y < item39 + 10) sprintf_s(mDescription, "Description: Limit Aim Angle\nLimits Aimbot to Max Aim Angle.");
			if (Cursor.y > item38 - 10 && Cursor.y < item38 + 10) sprintf_s(mDescription, "Description: Draw Aim FOV\nDraws Aimbot FOV Circle.");
			if (Cursor.y > item41 - 10 && Cursor.y < item41 + 10) sprintf_s(mDescription, "Description: Aim at Vehicles\nAimbot can Aim at Vehicles.");
			if (Cursor.y > item14 - 10 && Cursor.y < item14 + 10) sprintf_s(mDescription, "Description: Free-Style\nGo Free-Style Raging Mode.");
			if (Cursor.y > item45 - 10 && Cursor.y < item45 + 10) sprintf_s(mDescription, "Description: Ping Correction\nEnables Ping Correction.");
		}
	}
}

void BuildMenuTab5()
{
	if(tab5)
	{
		pMenu.AddCheck("Minimap", 80, item4, Item4);
		pMenu.AddCheck("Crosshair", 80, item5, Item5);
		pMenu.AddCheck("Speedhack", 80, item19, Item19);
		pMenu.AddCheck("Unlock Weapons", 80, item20, Item20);
		pMenu.AddCheck("Enemy Nearby", 80, item35, Item35);
		pMenu.AddCheck("Aim Warnings", 80, item8, Item8);
		pMenu.AddCheck("No Fog", 80, item6, Item6);
		pMenu.AddCheck("No Sky", 80, item7, Item7);
		pMenu.AddCheck("No TV Static", 80, item44, Item44);
		pMenu.AddCheck("Draw FPS", 80, item15, Item15);
		pMenu.AddCheck("No Hands", 80, item18, Item18);

		Item4 = (int)pMenu.ReturnFunction(Item4, 80, item4);
		Item5 = (int)pMenu.ReturnFunction(Item5, 80, item5);
		Item19 = (int)pMenu.ReturnFunction(Item19, 80, item19);
		Item20 = (int)pMenu.ReturnFunction(Item20, 80, item20);
		Item35 = (int)pMenu.ReturnFunction(Item35, 80, item35);
		Item8 = (int)pMenu.ReturnFunction(Item8, 80, item8);
		Item6 = (int)pMenu.ReturnFunction(Item6, 80, item6);
		Item7 = (int)pMenu.ReturnFunction(Item7, 80, item7);
		Item44 = (int)pMenu.ReturnFunction(Item44, 80, item44);
		Item15 = (int)pMenu.ReturnFunction(Item15, 80, item15);
		Item18 = (int)pMenu.ReturnFunction(Item18, 80, item18);

		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item4 - 10 && Cursor.y < item4 + 10) sprintf_s(mDescription, "Description: Minimap\nEnable Minimap.");
			if (Cursor.y > item5 - 10 && Cursor.y < item5 + 10) sprintf_s(mDescription, "Description: Crosshair\nDraw Crosshair.");
			if (Cursor.y > item19 - 10 && Cursor.y < item19 + 10) sprintf_s(mDescription, "Description: Speedhack\nEnables Vehicle Speedhack.\nEnables Parachute Speedhack.");
			if (Cursor.y > item20 - 10 && Cursor.y < item20 + 10) sprintf_s(mDescription, "Description: Unlock Weapons\nUnlocks all Weapons.");
			if (Cursor.y > item35 - 10 && Cursor.y < item35 + 10) sprintf_s(mDescription, "Description: Enemy Nearby\nDisplays Warning if Enemy Nearby");
			if (Cursor.y > item8 - 10 && Cursor.y < item8 + 10)	sprintf_s(mDescription, "Description: Aim Warnings\nDraws Warning When Enemy\nAiming at You.");
			if (Cursor.y > item6 - 10 && Cursor.y < item6 + 10) sprintf_s(mDescription, "Description: No Fog\nRemoves Fog.");
			if (Cursor.y > item7 - 10 && Cursor.y < item7 + 10) sprintf_s(mDescription, "Description: No Sky\nRemoves Sky.");
			if (Cursor.y > item44 - 10 && Cursor.y < item44 + 10) sprintf_s(mDescription, "Description: No TV Static\nRemoves TV Static.");
			if (Cursor.y > item15 - 10 && Cursor.y < item15 + 10) sprintf_s(mDescription, "Description: Draw FPS\nEnables Draw FPS.");
			if (Cursor.y > item18 - 10 && Cursor.y < item18 + 10) sprintf_s(mDescription, "Description: No Hand\nRemoves Player's Hands.");
		}
	}
}

void BuildMenuTab6()
{
	if(tab6)
	{
		pMenu.AddCheck("View Distance", 80, item51, Item51);
		pMenu.AddCheck("No Overlay", 80, item52, Item52);
		pMenu.AddCheck("3D MAP", 80, item53, Item53);
		pMenu.AddCheck("Enemy Mines Icon", 80, item54, Item54);
		pMenu.AddCheck("Radar & Bridge Icons", 80, item55, Item55);
		pMenu.AddCheck("ASUS Wallhack", 80, item56, Item56);
		pMenu.AddCheck("Wallhack", 80, item57, Item57);
		pMenu.AddCheck("ObjectESP", 80, item58, Item58);
		pMenu.AddCheck("DangerWarning", 80, item59, Item59);
		pMenu.AddCheck("Auto-Flares", 80, item60, Item60);

		Item51 = (int)pMenu.ReturnFunction(Item51, 80, item51);
		Item52 = (int)pMenu.ReturnFunction(Item52, 80, item52);
		Item53 = (int)pMenu.ReturnFunction(Item53, 80, item53);
		Item54 = (int)pMenu.ReturnFunction(Item54, 80, item54);
		Item55 = (int)pMenu.ReturnFunction(Item55, 80, item55);
		Item56 = (int)pMenu.ReturnFunction(Item56, 80, item56);
		Item57 = (int)pMenu.ReturnFunction(Item57, 80, item57);
		Item58 = (int)pMenu.ReturnFunction(Item58, 80, item58);
		Item59 = (int)pMenu.ReturnFunction(Item59, 80, item59);
		Item60 = (int)pMenu.ReturnFunction(Item60, 80, item60);

		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item51 - 10 && Cursor.y < item51 + 10) sprintf_s(mDescription, "Description: View Distance\nEnable Long-Range View.");
			if (Cursor.y > item52 - 10 && Cursor.y < item52 + 10) sprintf_s(mDescription, "Description: No Overlay\nRemoves Overlay.");
			if (Cursor.y > item53 - 10 && Cursor.y < item53 + 10) sprintf_s(mDescription, "Description: 3D MAP\nEnable 3D MAP.");
			if (Cursor.y > item54 - 10 && Cursor.y < item54 + 10) sprintf_s(mDescription, "Description: Enemy Mines Icon\nEnable Enemy Mines\nIcons.");
			if (Cursor.y > item55 - 10 && Cursor.y < item55 + 10) sprintf_s(mDescription, "Description: Radar&Bridge Icons\nEnable Radar&Bridge\nIcons.");
			if (Cursor.y > item56 - 10 && Cursor.y < item56 + 10) sprintf_s(mDescription, "Description: ASUS Wallhack\nEnable ASUS Wallhack.");
			if (Cursor.y > item57 - 10 && Cursor.y < item57 + 10) sprintf_s(mDescription, "Description: Wallhack\nEnable Wallhack.");
			if (Cursor.y > item58 - 10 && Cursor.y < item58 + 10) sprintf_s(mDescription, "Description: ObjectESP\nEnable ObjectESP.");
			if (Cursor.y > item59 - 10 && Cursor.y < item59 + 10) sprintf_s(mDescription, "Description: DangerWarning\nEnable DangerWarning.");
			if (Cursor.y > item60 - 10 && Cursor.y < item60 + 10) sprintf_s(mDescription, "Description: Auto-Flares\nAutomatically Deploy Flares.");
		}
	}
}

void BuildMenuTab7()
{
	if(tab7)
	{
		char cValue[8];

		sprintf( cValue, "[%.2f]", AimPrediction);
		pMenu.AddItemWithValue( "Aim Prediction", 80, item71, cValue, Item71);

		sprintf( cValue, "[%.0fm]", espdist);
		pMenu.AddItemWithValue("ESP Distance", 80, item72, cValue, Item72);

		sprintf( cValue, "[%.0fm]", MaxAimDistance);
		pMenu.AddItemWithValue("Aim Distance", 80, item73, cValue, Item73);

		sprintf( cValue, "[%.1f]", MaxAimAngle);
		pMenu.AddItemWithValue("Aim Angle", 80, item74, cValue, Item74);

		pMenu.AddItemWithValue("Aim Bone", 80, item75, pMenu.retCAimBone(Aimbone), Item75);

		pMenu.SwitchItems();

		if(Item71)
		{
			sprintf_s(mDescription, "Description:Aim Prediction\nAdjust Aim Prediction\n\nCurrent is %.2f.", AimPrediction);

			if(GetAsyncKeyState(VK_RIGHT) & 1)
				AimPrediction = AimPrediction + 0.05f;
			else if(GetAsyncKeyState(VK_LEFT) & 1)
				AimPrediction = AimPrediction - 0.05f;
		}
		else if(Item72)
		{
			sprintf_s(mDescription, "Description:ESP Distance\nAdjust ESP Distance\n\nCurrent is %.0fm.", espdist);

			if(GetAsyncKeyState(VK_RIGHT) & 1)
				espdist = espdist + 1.0f;
			else if(GetAsyncKeyState(VK_LEFT) & 1)
				espdist = espdist - 1.0f;
		}
		else if(Item73)
		{
			sprintf_s(mDescription, "Description:Aim Distance\nAdjust Aim Distance\n\nCurrent is %.0fm.", MaxAimDistance);

			if(GetAsyncKeyState(VK_RIGHT) & 1)
				MaxAimDistance = MaxAimDistance + 1.0f;
			else if(GetAsyncKeyState(VK_LEFT) & 1)
				MaxAimDistance = MaxAimDistance - 1.0f;
		}
		else if(Item74)
		{
			sprintf_s(mDescription, "Description:Aim Angle\nAdjust Aim Angle\n\nCurrent is %.1f.", MaxAimAngle);

			if(GetAsyncKeyState(VK_RIGHT) & 1)
				MaxAimAngle = MaxAimAngle + 1.0f;
			else if(GetAsyncKeyState(VK_LEFT) & 1)
				MaxAimAngle = MaxAimAngle - 1.0f;
		}
		else if(Item75)
		{
			sprintf_s(mDescription, "Description:Aim Bone\nSelect Aim Bone\n\nCurrent is %s.", cCurBone);

			if(GetAsyncKeyState(VK_RIGHT) & 1)
		    {
			    if(Aimbone == 47) Aimbone = 5;
			    else if(Aimbone == 5) Aimbone = 10;
			    else if(Aimbone == 10) Aimbone = 11;
			    else if(Aimbone == 11) Aimbone = 12;
			    else if(Aimbone == 12) Aimbone = 13;
			    else if(Aimbone == 13) Aimbone = 20;
			    else if(Aimbone == 20) Aimbone = 35;
			    else if(Aimbone == 35) Aimbone = 47;
		    }
		    else if(GetAsyncKeyState(VK_LEFT) & 1)
		    {
			    if(Aimbone == 47) Aimbone = 35;
			    else if(Aimbone == 35) Aimbone = 20;
			    else if(Aimbone == 20) Aimbone = 13;
			    else if(Aimbone == 13) Aimbone = 12;
			    else if(Aimbone == 12) Aimbone = 11;
			    else if(Aimbone == 11) Aimbone = 10;
			    else if(Aimbone == 10) Aimbone = 5;
			    else if(Aimbone == 5) Aimbone = 47;
		    }
		}

	}
}

void BuildMenuTabSelect()
{
	pMenu.AddTab("ESP", 97, 185, tab1);
	pMenu.AddTab("Team", 186, 185, tab2);
	pMenu.AddTab("Chams", 275, 185, tab3);
	pMenu.AddTab("Aimbot", 364, 185, tab4);
	pMenu.AddTab("Extras", 453, 185, tab5);
	pMenu.AddTab("Extras2", 97, 205, tab6);
	pMenu.AddTab("Customs", 186, 205, tab7);

	if (tab1 == 0 && (tab2 == 1 || tab3 == 1 || tab4 == 1 || tab5 == 1 || tab6 == 1 || tab7 == 1))
	{
		int xx = 97;
		int yy = 185;

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy +010))
			{
				sprintf_s(mDescription, "Description: ESP Features.");
				tab1 = 1;
				tab2 = 0;
				tab3 = 0;
				tab4 = 0;
				tab5 = 0;
				tab6 = 0;
				tab7 = 0;
			}
		}
	}

	if (tab2 == 0 && (tab1 == 1 || tab3 == 1 || tab4 == 1 || tab5 == 1 || tab6 == 1 || tab7 == 1))
	{
		int xx = 186;
		int yy = 185;

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				sprintf_s(mDescription, "Description: Team Features.");
				tab1 = 0;
				tab2 = 1;
				tab3 = 0;
				tab4 = 0;
				tab5 = 0;
				tab6 = 0;
				tab7 = 0;
			}
		}
	}

	if (tab3 == 0 && (tab1 == 1 || tab2 == 1 || tab4 == 1 || tab5 == 1 || tab6 == 1 || tab7 == 1))
	{
		int xx = 275;
		int yy = 185;

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				sprintf_s(mDescription, "Description: Cham Features.");
				tab1 = 0;
				tab2 = 0;
				tab3 = 1;
				tab4 = 0;
				tab5 = 0;
				tab6 = 0;
				tab7 = 0;
			}
		}
	}

	if (tab4 == 0 && (tab1 == 1 || tab2 == 1 || tab3 == 1 || tab5 == 1 || tab6 == 1 || tab7 == 1))
	{
		int xx = 364;
		int yy = 185;

		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				sprintf_s(mDescription, "Description: Aimbot Features.");
				tab1 = 0;
				tab2 = 0;
				tab3 = 0;
				tab4 = 1;
				tab5 = 0;
				tab6 = 0;
				tab7 = 0;
			}

		}
	}

	if (tab5 == 0 && (tab1 == 1 || tab2 == 1 || tab3 == 1 || tab4 == 1 || tab6 == 1 || tab7 == 1))
	{
		int xx = 453;
		int yy = 185;

		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				sprintf_s(mDescription, "Description: Extra Features.");
				tab1 = 0;
				tab2 = 0;
				tab3 = 0;
				tab4 = 0;
				tab5 = 1;
				tab6 = 0;
				tab7 = 0;
			}

		}
	}

	if(tab6 == 0 && (tab1 == 1 || tab2 == 1 || tab3 == 1 || tab4 == 1 || tab5 == 1 || tab7 == 1))
	{
		int xx = 97;
		int yy = 205;

		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				sprintf_s(mDescription, "Description: Extras2 Features.");
				tab1 = 0;
				tab2 = 0;
				tab3 = 0;
				tab4 = 0;
				tab5 = 0;
				tab6 = 1;
				tab7 = 0;
			}
		}

	}

	if(tab7 == 0 && (tab1 == 1 || tab2 == 1 || tab3 == 1 || tab4 == 1 || tab5 == 1 || tab6 == 1))
	{
		int xx = 186;
		int yy = 205;

		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				sprintf_s(mDescription, "Description: Extras2 Features.");
				tab1 = 0;
				tab2 = 0;
				tab3 = 0;
				tab4 = 0;
				tab5 = 0;
				tab6 = 0;
				tab7 = 1;
			}
		}

	}
}

void BuildMenu()
{
	//Setup Tabs
	pMenu.AddTab("ESP", 97, 205, tab1);
	pMenu.AddTab("Team", 186, 205, tab2);
	pMenu.AddTab("Chams", 275, 205, tab3);
	pMenu.AddTab("Aimbot", 364, 205, tab4);
	pMenu.AddTab("Extras", 453, 205, tab5);

	if(tab1)
	{
		pMenu.AddCheck("NameTags", 80, item2, Item2);
		pMenu.AddCheck("DistanceTags", 80, item1, Item1);
		pMenu.AddCheck("HealthBars", 80, item3, Item3);
		pMenu.AddCheck("Player Class", 80, item37, Item37);
		pMenu.AddCheck("Player Posture", 80, item10, Item10);
		pMenu.AddCheck("Snaplines", 80, item11, Item11);
		pMenu.AddCheck("Skeleton ESP", 80, item9, Item9);
		pMenu.AddCheck("Box ESP", 80, item42, Item42);
		pMenu.AddCheck("Draw Team", 80, item13, Item13);
		pMenu.AddCheck("2D RADAR", 80, item16, Item16);
		
		Item2 = (int)pMenu.ReturnFunction(Item2, 80, item2);
		Item1 = (int)pMenu.ReturnFunction(Item1, 80, item1);
		Item3 = (int)pMenu.ReturnFunction(Item3, 80, item3);
		Item37 = (int)pMenu.ReturnFunction(Item37, 80, item37);
		Item10 = (int)pMenu.ReturnFunction(Item10, 80, item10);
		Item11 = (int)pMenu.ReturnFunction(Item11, 80, item11);
		Item9 = (int)pMenu.ReturnFunction(Item9, 80, item9);
		Item42 = (int)pMenu.ReturnFunction(Item42, 80, item42);
		Item13 = (int)pMenu.ReturnFunction(Item13, 80, item13);
		Item16 = (int)pMenu.ReturnFunction(Item16, 80, item16);

		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item2 - 10 && Cursor.y < item2 + 10)
			{
				sprintf_s(mDescription, "Description: NameTags\nEnable Player NameTags.");
			}
			if (Cursor.y > item1 - 10 && Cursor.y < item1 + 10)
			{
				sprintf_s(mDescription, "Description: DistanceTags\nEnable Player DistanceTags.");
			}
			if (Cursor.y > item3 - 10 && Cursor.y < item3 + 10)
			{
				sprintf_s(mDescription, "Description: HealthBars\nEnable Player HealthBars.");
			}
			if (Cursor.y > item37 - 10 && Cursor.y < item37 + 10)
			{
				sprintf_s(mDescription, "Description: Player Class\nDraw Player Class.");
			}
			if (Cursor.y > item10 - 10 && Cursor.y < item10 + 10)
			{
				sprintf_s(mDescription, "Description: Player Posture\nDraw Player Posture.");
			}
			if (Cursor.y > item11 - 10 && Cursor.y < item11 + 10)
			{
				sprintf_s(mDescription, "Description: Snaplines\nDraw Snap Lines to Visible Soldiers.");
			}
			if (Cursor.y > item9 - 10 && Cursor.y < item9 + 10)
			{
				sprintf_s(mDescription, "Description: Skeleton ESP\nDraw Player Skeleton.");
			}
			if (Cursor.y > item42 - 10 && Cursor.y < item42 + 10)
			{
				sprintf_s(mDescription, "Description: Box ESP\nDraw Box Around Players.");
			}
			if (Cursor.y > item13 - 10 && Cursor.y < item13 + 10)
			{
				sprintf_s(mDescription, "Description: Draw Team\nDraws Team ESP Also.");
			}
			if (Cursor.y > item16 - 10 && Cursor.y < item16 + 10)
			{
				sprintf_s(mDescription, "Description: 2D RADAR\nDraws 2D RADAR.");
			}
		}
	}

	if(tab2)
	{
		pMenu.AddCheck("Team Swap", 80, item21, Item21);
		pMenu.AddCheck("Force Commander", 80, item22, Item22);
		pMenu.AddCheck("Force Squad Leader", 80, item23, Item23);
		pMenu.AddCheck("Jump Squads", 80, item24, Item24);

		Item21 = (int)pMenu.ReturnFunction(Item21, 80, item21);
		Item22 = (int)pMenu.ReturnFunction(Item22, 80, item22);
		Item23 = (int)pMenu.ReturnFunction(Item23, 80, item23);
		Item24 = (int)pMenu.ReturnFunction(Item24, 80, item24);
		
		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item21 - 10 && Cursor.y < item21 + 10)
			{
				sprintf_s(mDescription, "Description: Team Swap\nEnables Team Swap Hotkey.\nPress F5 to Swap Teams");
			}
			if (Cursor.y > item22 - 10 && Cursor.y < item22 + 10)
			{
				sprintf_s(mDescription, "Description: Force Commander\nEnables Force Commander Hotkey.\nPress F6 to Become Commander");
			}
			if (Cursor.y > item23 - 10 && Cursor.y < item23 + 10)
			{
				sprintf_s(mDescription, "Description: Force Squad Leader\nEnables Force Squad Leader Hotkey.\nPress F7 to Become Squad Leader");
			}
			if (Cursor.y > item24 - 10 && Cursor.y < item24 + 10)
			{
				sprintf_s(mDescription, "Description: Jump Squads\nEnables Squad Jumping Hotkey.\nTo Cycle Through Squads\nPress F8");
			}
		}
	}

	if(tab3)
	{
		pMenu.AddCheck("USMC Soldiers", 80, item26, Item26);
		pMenu.AddCheck("CHINA Soldiers", 80, item27, Item27);
		pMenu.AddCheck("MEC Soldiers", 80, item28, Item28);
		pMenu.AddCheck("EURO Soldiers", 80, item29, Item29);
		pMenu.AddCheck("Vehicles", 80, item30, Item30);
		pMenu.AddCheck("Weapons", 80, item31, Item31);
		pMenu.AddCheck("Ground Weapons", 80, item32, Item32);
		pMenu.AddCheck("Explosives", 80, item33, Item33);
		pMenu.AddCheck("Hands", 80, item34, Item34);

		Item26 = (int)pMenu.ReturnFunction(Item26, 80, item26);
		Item27 = (int)pMenu.ReturnFunction(Item27, 80, item27);
		Item28 = (int)pMenu.ReturnFunction(Item28, 80, item28);
		Item29 = (int)pMenu.ReturnFunction(Item29, 80, item29);
		Item30 = (int)pMenu.ReturnFunction(Item30, 80, item30);
		Item31 = (int)pMenu.ReturnFunction(Item31, 80, item31);
		Item32 = (int)pMenu.ReturnFunction(Item32, 80, item32);
		Item33 = (int)pMenu.ReturnFunction(Item33, 80, item33);
		Item34 = (int)pMenu.ReturnFunction(Item34, 80, item34);

		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item26 - 10 && Cursor.y < item26 + 10)
			{
				sprintf_s(mDescription, "Description: USMC Soldiers\nEnable USMC Soldier Chams.");
			}
			if (Cursor.y > item27 - 10 && Cursor.y < item27 + 10)
			{
				sprintf_s(mDescription, "Description: CHINA Soldiers\nEnable CHINA Soldier Chams.");
			}
			if (Cursor.y > item28 - 10 && Cursor.y < item28 + 10)
			{
				sprintf_s(mDescription, "Description: MEC Soldiers\nEnable MEC Soldier Chams.");
			}
			if (Cursor.y > item29 - 10 && Cursor.y < item29 + 10)
			{
				sprintf_s(mDescription, "Description: EURO Soldiers\nEnable EURO Soldiers Chams.");
			}
			if (Cursor.y > item30 - 10 && Cursor.y < item30 + 10)
			{
				sprintf_s(mDescription, "Description: Vehicles\nEnable Vehicle Chams.");
			}
			if (Cursor.y > item31 - 10 && Cursor.y < item31 + 10)
			{
				sprintf_s(mDescription, "Description: Weapons\nEnable Weapon Chams.");
			}
			if (Cursor.y > item32 - 10 && Cursor.y < item32 + 10)
			{
				sprintf_s(mDescription, "Description: Ground Weapons\nEnable Ground Weapon Chams.");
			}
			if (Cursor.y > item33 - 10 && Cursor.y < item33 + 10)
			{
				sprintf_s(mDescription, "Description: Explosives\nEnable Explosive Chams.");
			}
			if (Cursor.y > item34 - 10 && Cursor.y < item34 + 10)
			{
				sprintf_s(mDescription, "Description: Hands\nEnable Hand Chams.");
			}
		}
	}

	if(tab4)
	{
		pMenu.AddCheck("Aimbot", 80, item25, Item25);
		pMenu.AddCheck("No Spread", 80, item12, Item12);
		pMenu.AddCheck("No Shake", 80, item43, Item43);
		pMenu.AddCheck("Autoshoot", 80, item36, Item36);
		pMenu.AddCheck("Limit Aim Angle", 80, item39, Item39);
		pMenu.AddCheck("Draw Aim FOV", 80, item38, Item38);
		pMenu.AddCheck("Aim at Vehicles", 80, item41, Item41);
		pMenu.AddCheck("TV Infantry Aim", 80, item14, Item14);

		Item25 = (int)pMenu.ReturnFunction(Item25, 80, item25);
		Item12 = (int)pMenu.ReturnFunction(Item12, 80, item12);
		Item43 = (int)pMenu.ReturnFunction(Item43, 80, item43);
		Item36 = (int)pMenu.ReturnFunction(Item36, 80, item36);
		Item39 = (int)pMenu.ReturnFunction(Item39, 80, item39);
		Item38 = (int)pMenu.ReturnFunction(Item38, 80, item38);
		Item41 = (int)pMenu.ReturnFunction(Item41, 80, item41);
		Item14 = (int)pMenu.ReturnFunction(Item14, 80, item14);

		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item25 - 10 && Cursor.y < item25 + 10)
			{
				sprintf_s(mDescription, "Description: Aimbot\nEnables Aimbot.\nAim Key = Middle Mouse");
			}
			if (Cursor.y > item12 - 10 && Cursor.y < item12 + 10)
			{
				sprintf_s(mDescription, "Description: No Spread\nEnables No Spread for Aimbot.");
			}
			if (Cursor.y > item43 - 10 && Cursor.y < item43 + 10)
			{
				sprintf_s(mDescription, "Description: No Shake\nDisables No Spread Screen Shaking.");
			}
			if (Cursor.y > item36 - 10 && Cursor.y < item36 + 10)
			{
				sprintf_s(mDescription, "Description: Autoshoot\nAutoshoot when Aimkey Pressed.");
			}
			if (Cursor.y > item39 - 10 && Cursor.y < item39 + 10)
			{
				sprintf_s(mDescription, "Description: Limit Aim Angle\nLimits Aimbot to Max Aim Angle.");
			}
			if (Cursor.y > item38 - 10 && Cursor.y < item38 + 10)
			{
				sprintf_s(mDescription, "Description: Draw Aim FOV\nDraws Aimbot FOV Circle.");
			}
			if (Cursor.y > item41 - 10 && Cursor.y < item41 + 10)
			{
				sprintf_s(mDescription, "Description: Aim at Vehicles\nAimbot can Aim at Vehicles.");
			}
			if (Cursor.y > item14 - 10 && Cursor.y < item14 + 10)
			{
				sprintf_s(mDescription, "Description: TV Infantry Aim\nTV Aimbot can Aim at Infantry.");
			}
		}
	}

	if(tab5)
	{
		pMenu.AddCheck("Minimap", 80, item4, Item4);
		pMenu.AddCheck("Crosshair", 80, item5, Item5);
		pMenu.AddCheck("Speedhack", 80, item19, Item19);
		pMenu.AddCheck("Unlock Weapons", 80, item20, Item20);
		pMenu.AddCheck("Enemy Nearby", 80, item35, Item35);
		pMenu.AddCheck("Aim Warnings", 80, item8, Item8);
		pMenu.AddCheck("No Fog", 80, item6, Item6);
		pMenu.AddCheck("No Sky", 80, item7, Item7);
		pMenu.AddCheck("No TV Static", 80, item44, Item44);

		Item4 = (int)pMenu.ReturnFunction(Item4, 80, item4);
		Item5 = (int)pMenu.ReturnFunction(Item5, 80, item5);
		Item19 = (int)pMenu.ReturnFunction(Item19, 80, item19);
		Item20 = (int)pMenu.ReturnFunction(Item20, 80, item20);
		Item35 = (int)pMenu.ReturnFunction(Item35, 80, item35);
		Item8 = (int)pMenu.ReturnFunction(Item8, 80, item8);
		Item6 = (int)pMenu.ReturnFunction(Item6, 80, item6);
		Item7 = (int)pMenu.ReturnFunction(Item7, 80, item7);
		Item44 = (int)pMenu.ReturnFunction(Item44, 80, item44);

		if (Cursor.x > 80 && Cursor.x < 260)
		{
			if (Cursor.y > item4 - 10 && Cursor.y < item4 + 10)
			{
				sprintf_s(mDescription, "Description: Minimap\nEnable Minimap.");
			}
			if (Cursor.y > item5 - 10 && Cursor.y < item5 + 10)
			{
				sprintf_s(mDescription, "Description: Crosshair\nDraw Crosshair.");
			}
			if (Cursor.y > item19 - 10 && Cursor.y < item19 + 10)
			{
				sprintf_s(mDescription, "Description: Speedhack\nEnables Vehicle Speedhack.\nEnables Parachute Speedhack.");
			}
			if (Cursor.y > item20 - 10 && Cursor.y < item20 + 10)
			{
				sprintf_s(mDescription, "Description: Unlock Weapons\nUnlocks all Weapons.");
			}
			if (Cursor.y > item35 - 10 && Cursor.y < item35 + 10)
			{
				sprintf_s(mDescription, "Description: Enemy Nearby\nDisplays Warning if Enemy Nearby");
			}
			if (Cursor.y > item8 - 10 && Cursor.y < item8 + 10)
			{
				sprintf_s(mDescription, "Description: Aim Warnings\nDraws Warning When Enemy\nAiming at You.");
			}
			if (Cursor.y > item6 - 10 && Cursor.y < item6 + 10)
			{
				sprintf_s(mDescription, "Description: No Fog\nRemoves Fog.");
			}
			if (Cursor.y > item7 - 10 && Cursor.y < item7 + 10)
			{
				sprintf_s(mDescription, "Description: No Sky\nRemoves Sky.");
			}
			if (Cursor.y > item44 - 10 && Cursor.y < item7 + 44)
			{
				sprintf_s(mDescription, "Description: No TV Static\nRemoves TV Static.");
			}
		}
	}

	//Tab settings
	if (tab1 == 0 && (tab2 == 1 || tab3 == 1 || tab4 == 1 || tab5 == 1))
	{
		int xx = 97;
		int yy = 205;

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				tab1 = 1;
				tab2 = 0;
				tab3 = 0;
				tab4 = 0;
				tab5 = 0;
			}
		}
	}

	if (tab2 == 0 && (tab1 == 1 || tab3 == 1 || tab4 == 1 || tab5 == 1))
	{
		int xx = 186;
		int yy = 205;

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				tab1 = 0;
				tab2 = 1;
				tab3 = 0;
				tab4 = 0;
				tab5 = 0;
			}
		}
	}

	if (tab3 == 0 && (tab1 == 1 || tab2 == 1 || tab4 == 1 || tab5 == 1))
	{
		int xx = 275;
		int yy = 205;

		if (GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				tab1 = 0;
				tab2 = 0;
				tab3 = 1;
				tab4 = 0;
				tab5 = 0;
			}
		}
	}

	if (tab4 == 0 && (tab1 == 1 || tab2 == 1 || tab3 == 1 || tab5 == 1))
	{
		int xx = 364;
		int yy = 205;

		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				tab1 = 0;
				tab2 = 0;
				tab3 = 0;
				tab4 = 1;
				tab5 = 0;
			}

		}
	}

	if (tab5 == 0 && (tab1 == 1 || tab2 == 1 || tab3 == 1 || tab4 == 1))
	{
		int xx = 453;
		int yy = 205;

		if(GetAsyncKeyState(VK_LBUTTON))
		{
			if (Cursor.x > (xx - 35) && Cursor.x < (xx + 35) && Cursor.y >(yy - 10) && Cursor.y < (yy + 10))
			{
				tab1 = 0;
				tab2 = 0;
				tab3 = 0;
				tab4 = 0;
				tab5 = 1;
			}

		}
	}

	if(bWriteConfig == false) bWriteConfig = true;
}

class tools;
tools* cTools;

class tools
{
public:
	void Message(char * text, char * title);
	void WriteAsm(void * adress, BYTE * bytes, int size);
};

void tools::Message(char * text, char * title)
{
	MessageBoxA(NULL,        //HWND
		text,                //lpText
		title,               //lpCaption
		MB_ICONINFORMATION); //uType
}

void tools::WriteAsm(void * adress, BYTE * bytes, int size)
{
	DWORD dwProtect = NULL;
	VirtualProtect(adress, size, PAGE_READWRITE, &dwProtect);
	memcpy(adress, (PBYTE)bytes, size);
	VirtualProtect(adress, size, dwProtect, &dwProtect);
}

void WriteFunction(void *adr, void *ptr, int size)
{
	DWORD dwback;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &dwback);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, dwback, &dwback);
}

template <typename T>void WriteFunction(void* adr, T Vaule, T *Input = NULL)
{
	if (Input == 0)
		WriteFunction((void*)adr, (void*)&Vaule, sizeof(T));
	else
		WriteFunction((void*)Input, (void*)adr, sizeof(T));
}