#include "stdafx.h"
#include "ConsoleApp.h"
#include <string>
#include <iostream>
#include <fstream>

#include "FileReader.h"
#include "Creator.h"

using namespace std;


ConsoleApp::ConsoleApp(void)
{
	while(true)
	{
		// Get filename
		cout << "Enter filename: ";
		string sFileName;
		getline(cin, sFileName);
		
		// Run the actual logic from the app
		CreateCircuit(sFileName.c_str());
		
		// Attempt a retry or quit
		Write("\n\n");
		Write("Press 'Y' to run again or something else to quit...\n");
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			system("cls");
		}
		else
			break;
		cin.get();
	}
}


ConsoleApp::~ConsoleApp(void)
{
}

void ConsoleApp::CreateCircuit(const char* szFileName)
{
	FileReader CReader(szFileName);
	Creator CCreator(CReader);
}

void ConsoleApp::Write(const char* szText)
{
	cout << szText;
}