/************************************************************************************************
    Name:		CoachLDEW
    Date:		10.24.2024
    Purpose:	This program allows the user to the font size.  The Width and Height in Pixels.
                Normal font size is 8 x 16
*************************************************************************************************/
#include <iostream>			//This library contains standard input and output processes
#include <Windows.h>		//This library contains the function to control the cursor position

using namespace std;


void ChangeFontSize(int fontW, int fontH)
{
    //Otput Handle to the console
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //Contains extended information for a console font.
    CONSOLE_FONT_INFOEX CfontInfo;
    //cbSize - The size of this structure, in bytes. This member must be set to sizeof(CONSOLE_FONT_INFOEX) 
    //before calling GetCurrentConsoleFontEx or it will fail.
    CfontInfo.cbSize = sizeof(CfontInfo);
    //The index of the font in the system's console font table.
    CfontInfo.nFont = 0;

    //This is where we modify the font size
    
    //A COORD structure that contains the width and height of each character in the font, in logical units. 
    //The X member contains the width, while the Y member contains the height.
    CfontInfo.dwFontSize.X = fontW; // Width of each character in pixels
    CfontInfo.dwFontSize.Y = fontH; // Height of each character in pixels
    //The font pitch and family. For information about the possible values for this member, see the description 
    //of the tmPitchAndFamily member of the TEXTMETRIC structure.
    CfontInfo.FontFamily = FF_DONTCARE;
    //The font weight. The weight can range from 100 to 1000, in multiples of 100. For example, the normal 
    //weight is 400, while 700 is bold.
    CfontInfo.FontWeight = FW_NORMAL;

    //Retrieves extended information about the current console font.
    SetCurrentConsoleFontEx(hOut, FALSE, &CfontInfo);
}

int main() 
{
    int fontW = 12;         //Font Width
    int fontH = 24;         //Font Height

    //Function to change Font Size
    ChangeFontSize(fontW, fontH);

    cout << "Font Width = " << fontW << endl;
    cout << "Font Height = " << fontH << endl;

    return 0;
}