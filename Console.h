#include "Menu.h"

//==============================================================
//CONSOLE STUFF
//==============================================================
string userinput;
int TAimbone;
string akey = "a";
string bkey = "b";
string ckey = "c";
string dkey = "d";
string ekey = "e";
string fkey = "f";
string gkey = "g";
string hkey = "h";
string ikey = "i";
string jkey = "j";
string kkey = "k";
string lkey = "l";
string mkey = "m";
string nkey = "n";
string okey = "o";
string pkey = "p";
string qkey = "q";
string rkey = "r";
string skey = "s";
string tkey = "t";
string ukey = "u";
string vkey = "v";
string wkey = "w";
string xkey = "x";
string ykey = "y";
string zkey = "z";
string Akey = "A";
string Bkey = "B";
string Ckey = "C";
string Dkey = "D";
string Ekey = "E";
string Fkey = "F";
string Gkey = "G";
string Hkey = "H";
string Ikey = "I";
string Jkey = "J";
string Kkey = "K";
string Lkey = "L";
string Mkey = "M";
string Nkey = "N";
string Okey = "O";
string Pkey = "P";
string Qkey = "Q";
string Rkey = "R";
string Skey = "S";
string Tkey = "T";
string Ukey = "U";
string Vkey = "V";
string Wkey = "W";
string Xkey = "X";
string Ykey = "Y";
string Zkey = "Z";
string decimal = ".";
string space = " ";
float CurrentCorrection = 0.0f;

//Usage --> Item25 = (int)ConsoleReturnFunction(Item25);
DWORD * ConsoleReturnFunction(int function)
{
	if (pMenu.Visible)
	{
		switch (function)
		{
			case 0: function = 1; Sleep(100); break;
			case 1: function = 0; Sleep(100); break;
		}
	}
	
	return (DWORD*)function;
}

string Command1 = "Aimbot.Toggle";
string Command2 = "Aimbot.NoSpread.Toggle";
string Command3 = "Aimbot.NoShake.Toggle";
string Command4 = "Aimbot.VisibleOnly.Toggle";
string Command5 = "Aimbot.InfantryOnly.Toggle";
string Command6 = "Aimbot.DrawFOV.Toggle";
string Command7 = "Aimbot.AutoShoot.Toggle";
string Command8 = "Aimbot.LimitAimAngle.Toggle";
string Command9 = "Aimbot.AimAngle.Increase";
string Command10 = "Aimbot.AimAngle.Decrease";
string Command11 = "Aimbot.AimAngle.Display";
string Command12 = "Aimbot.MaxAimDistance.Increase";
string Command13 = "Aimbot.MaxAimDistance.Decrease";
string Command14 = "Aimbot.MaxAimDistance.Display";
string Command15 = "Aimbot.Prediction.Increase";
string Command16 = "Aimbot.Prediction.Decrease";
string Command17 = "Aimbot.Prediction.Display";
string Command18 = "Aimbot.Prediction.Reset";
string Command19 = "Aimbone.Increase";
string Command20 = "Aimbone.Decrease";
string Command21 = "Aimbone.Display";
string Command22 = "Aimbone.Reset";
string Command23 = "Aimbone.Head";
string Command24 = "Aimbone.Neck";
string Command25 = "Aimbone.Chest";
string Command26 = "Aimbone.Stomach";
string Command27 = "Aimbone.Pelvis";
string Command28 = "Aimbone.Legs";
string Command29 = "Aimbone.Feet";

void process_command()
{
	if(userinput == Command1) 
	{
		Item25 = (int)ConsoleReturnFunction(Item25);
		userinput = "";
	}
	else if(userinput == Command2) 
	{
		Item12 = (int)ConsoleReturnFunction(Item12);
		userinput = "";
	}
	else if(userinput == Command3) 
	{
		Item43 = (int)ConsoleReturnFunction(Item43);
		userinput = "";
	}
	else if(userinput == Command4) 
	{
		Item40 = (int)ConsoleReturnFunction(Item40);
		userinput = "";
	}
	else if(userinput == Command5) 
	{
		Item41 = (int)ConsoleReturnFunction(Item41);
		userinput = "";
	}
	else if(userinput == Command6) 
	{
		Item38 = (int)ConsoleReturnFunction(Item38);
		userinput = "";
	}
	else if(userinput == Command7) 
	{
		Item36 = (int)ConsoleReturnFunction(Item36);
		userinput = "";
	}
	else if(userinput == Command8) 
	{
		Item39 = (int)ConsoleReturnFunction(Item39);
		userinput = "";
	}
	else if(userinput == Command9) 
	{
		MaxAimAngle = MaxAimAngle + 10.0;
		userinput = "";
	}
	else if(userinput == Command10) 
	{
		MaxAimAngle = MaxAimAngle - 10.0;
		userinput = "";
	}
	else if(userinput == Command11) 
	{
		string aimangle = NumberToString(MaxAimAngle);
		userinput = aimangle;
	}
	else if(userinput == Command12) 
	{
		MaxAimDistance = MaxAimDistance + 50.0;
		userinput = "";
	}
	else if(userinput == Command13) 
	{
		MaxAimDistance = MaxAimDistance - 50.0;
		userinput = "";
	}
	else if(userinput == Command14) 
	{
		string aimdist = NumberToString(MaxAimDistance);
		userinput = aimdist;
	}
	else if(userinput == Command15) 
	{
		AimPrediction = AimPrediction - 5.0f;
		userinput = "";
	}
	else if(userinput == Command16) 
	{
		AimPrediction = AimPrediction + 5.0f;
		userinput = "";
	}
	else if(userinput == Command17) 
	{
		string correction = NumberToString(AimPrediction);
		userinput = correction;
	}
	else if(userinput == Command18) 
	{
		AimPrediction = 0.0f;
		userinput = "Aimbot Prediction Reset";
	}
	else if(userinput == Command19)
	{
		if(Aimbone < 60) Aimbone = Aimbone + 1;
		userinput = "";
	}
	else if(userinput == Command20)
	{
		if(Aimbone > 1) Aimbone = Aimbone - 1;
		userinput = "";
	}
	else if(userinput == Command21)
	{
		string aimbonenum = NumberToString(Aimbone);
		userinput = aimbonenum;
	}
	else if(userinput == Command22)
	{
		Aimbone = 56;
		userinput = "Aimbone Reset";
	}
	else if(userinput == Command23)
	{
		Aimbone = 56;
		userinput = "Aimbone Set to Head";
	}
	else if(userinput == Command24)
	{
		Aimbone = 49;
		userinput = "Aimbone Set to Neck";
	}
	else if(userinput == Command25)
	{
		Aimbone = 13;
		userinput = "Aimbone Set to Chest";
	}
	else if(userinput == Command26)
	{
		Aimbone = 11;
		userinput = "Aimbone Set to Stomach";
	}
	else if(userinput == Command27)
	{
		Aimbone = 6;
		userinput = "Aimbone Set to Pelvis";
	}
	else if(userinput == Command28)
	{
		Aimbone = 7;
		userinput = "Aimbone Set to Legs";
	}
	else if(userinput == Command29)
	{
		Aimbone = 9;
		userinput = "Aimbone Set to Feet";
	}
	else if(userinput == "help")
	{
		userinput = "Use Up/Down Arrows to Browse Commands";
	}
	else
	{
		userinput = "Unknown Command - Press ESC to Clear";
	}
}

void CaptureInput()
{
	if(pMenu.Visible == 1)
	{
		if(GetAsyncKeyState(VK_ESCAPE) & 1) userinput = "";
		if(GetAsyncKeyState(VK_SPACE) & 1) userinput.append(space);

		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x41) & 1) userinput.append(Akey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x42) & 1) userinput.append(Bkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x43) & 1) userinput.append(Ckey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x44) & 1) userinput.append(Dkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x45) & 1) userinput.append(Ekey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x46) & 1) userinput.append(Fkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x47) & 1) userinput.append(Gkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x48) & 1) userinput.append(Hkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x49) & 1) userinput.append(Ikey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x4A) & 1) userinput.append(Jkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x4B) & 1) userinput.append(Kkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x4C) & 1) userinput.append(Lkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x4D) & 1) userinput.append(Mkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x4E) & 1) userinput.append(Nkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x4F) & 1) userinput.append(Okey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x50) & 1) userinput.append(Pkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x51) & 1) userinput.append(Qkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x52) & 1) userinput.append(Rkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x53) & 1) userinput.append(Skey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x54) & 1) userinput.append(Tkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x55) & 1) userinput.append(Ukey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x56) & 1) userinput.append(Vkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x57) & 1) userinput.append(Wkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x58) & 1) userinput.append(Xkey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x59) & 1) userinput.append(Ykey);}
		if(GetAsyncKeyState(VK_SHIFT) & 0x8000)	{if(GetAsyncKeyState(0x5A) & 1) userinput.append(Zkey);}

		if(GetAsyncKeyState(0x41) & 1) userinput.append(akey);
		if(GetAsyncKeyState(0x42) & 1) userinput.append(bkey);
		if(GetAsyncKeyState(0x43) & 1) userinput.append(ckey);
		if(GetAsyncKeyState(0x44) & 1) userinput.append(dkey);
		if(GetAsyncKeyState(0x45) & 1) userinput.append(ekey);
		if(GetAsyncKeyState(0x46) & 1) userinput.append(fkey);
		if(GetAsyncKeyState(0x47) & 1) userinput.append(gkey);
		if(GetAsyncKeyState(0x48) & 1) userinput.append(hkey);
		if(GetAsyncKeyState(0x49) & 1) userinput.append(ikey);
		if(GetAsyncKeyState(0x4A) & 1) userinput.append(jkey);
		if(GetAsyncKeyState(0x4B) & 1) userinput.append(kkey);
		if(GetAsyncKeyState(0x4C) & 1) userinput.append(lkey);
		if(GetAsyncKeyState(0x4D) & 1) userinput.append(mkey);
		if(GetAsyncKeyState(0x4E) & 1) userinput.append(nkey);
		if(GetAsyncKeyState(0x4F) & 1) userinput.append(okey);
		if(GetAsyncKeyState(0x50) & 1) userinput.append(pkey);
		if(GetAsyncKeyState(0x51) & 1) userinput.append(qkey);
		if(GetAsyncKeyState(0x52) & 1) userinput.append(rkey);
		if(GetAsyncKeyState(0x53) & 1) userinput.append(skey);
		if(GetAsyncKeyState(0x54) & 1) userinput.append(tkey);
		if(GetAsyncKeyState(0x55) & 1) userinput.append(ukey);
		if(GetAsyncKeyState(0x56) & 1) userinput.append(vkey);
		if(GetAsyncKeyState(0x57) & 1) userinput.append(wkey);
		if(GetAsyncKeyState(0x58) & 1) userinput.append(xkey);
		if(GetAsyncKeyState(0x59) & 1) userinput.append(ykey);
		if(GetAsyncKeyState(0x5A) & 1) userinput.append(zkey);

		if(GetAsyncKeyState(VK_OEM_PERIOD) & 1) userinput.append(decimal);
		if(GetAsyncKeyState(VK_BACK) & 1) userinput = userinput.substr(0, userinput.length()-1);
		if(GetAsyncKeyState(VK_RETURN) & 1) process_command();

		if(GetAsyncKeyState(VK_UP) & 1)
		{
			if(userinput == Command29) userinput = Command28;
			if(userinput == Command28) userinput = Command27;
			if(userinput == Command27) userinput = Command26;
			if(userinput == Command26) userinput = Command25;
			if(userinput == Command25) userinput = Command24;
			if(userinput == Command24) userinput = Command23;
			if(userinput == Command23) userinput = Command22;
			if(userinput == Command22) userinput = Command21;
			if(userinput == Command21) userinput = Command20;
			if(userinput == Command20) userinput = Command19;
			if(userinput == Command19) userinput = Command18;
			if(userinput == Command18) userinput = Command17;
			if(userinput == Command17) userinput = Command16;
			if(userinput == Command16) userinput = Command15;
			if(userinput == Command15) userinput = Command14;
			if(userinput == Command14) userinput = Command13;
			if(userinput == Command13) userinput = Command12;
			if(userinput == Command12) userinput = Command11;
			if(userinput == Command11) userinput = Command10;
			if(userinput == Command10) userinput = Command9;
			if(userinput == Command9) userinput = Command8;
			if(userinput == Command8) userinput = Command7;
			if(userinput == Command7) userinput = Command6;
			if(userinput == Command6) userinput = Command5;
			if(userinput == Command5) userinput = Command4;
			if(userinput == Command4) userinput = Command3;
			if(userinput == Command3) userinput = Command2;
			if(userinput == Command2) userinput = Command1;
			if(userinput == Command1) userinput = Command29;	
			else userinput = Command29;
		}

		if(GetAsyncKeyState(VK_DOWN) & 1)
		{
			if(userinput == Command1) userinput = Command2;
			if(userinput == Command2) userinput = Command3;
			if(userinput == Command3) userinput = Command4;
			if(userinput == Command4) userinput = Command5;
			if(userinput == Command5) userinput = Command6;
			if(userinput == Command6) userinput = Command7;
			if(userinput == Command7) userinput = Command8;
			if(userinput == Command8) userinput = Command9;
			if(userinput == Command9) userinput = Command10;
			if(userinput == Command10) userinput = Command11;
			if(userinput == Command11) userinput = Command12;
			if(userinput == Command12) userinput = Command13;
			if(userinput == Command13) userinput = Command14;
			if(userinput == Command14) userinput = Command15;
			if(userinput == Command15) userinput = Command16;
			if(userinput == Command16) userinput = Command17;
			if(userinput == Command17) userinput = Command18;
			if(userinput == Command18) userinput = Command19;
			if(userinput == Command19) userinput = Command20;
			if(userinput == Command20) userinput = Command21;
			if(userinput == Command21) userinput = Command22;
			if(userinput == Command22) userinput = Command23;
			if(userinput == Command23) userinput = Command24;
			if(userinput == Command24) userinput = Command25;
			if(userinput == Command25) userinput = Command26;
			if(userinput == Command26) userinput = Command27;
			if(userinput == Command27) userinput = Command28;
			if(userinput == Command28) userinput = Command29;
			if(userinput == Command29) userinput = Command1;
			else userinput = Command1;
		}
	}
}