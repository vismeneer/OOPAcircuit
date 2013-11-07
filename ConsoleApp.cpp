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
		Write("\n");
		Write("Press 'Y' to run again or something else to quit...\n");
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			//system("cls");
			Write("\n");
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
	FileReader* pReader = new FileReader(szFileName);
	Creator* pCreator = new Creator();

	if (pCreator->Create(pReader))
	{
		delete pReader;
		RunCircuit(pCreator->m_vNodes, pCreator->m_vProbes);

		delete pCreator;
	}
	else
	{
		delete pReader;
		delete pCreator;
	}
}

void ConsoleApp::RunCircuit(std::vector<Node*>& rvNodes, std::vector<Node*>& rvProbes)
{
	bool bFailed = false;
	for(std::vector<Node*>::iterator it = rvNodes.begin(); it != rvNodes.end(); ++it) 
	{
		Node* pNode = *it;
		if (!pNode->SendSignal())
			bFailed = true;
	}
	if (bFailed)
		return;

	Write("\n");
	for(std::vector<Node*>::iterator it = rvProbes.begin(); it != rvProbes.end(); ++it)
	{
		Node* pNode = *it;
		std::string sMessage;
		pNode->GetIdentifier(sMessage);
		if (pNode->m_bSignal)
			sMessage.append(": 1\n");
		else
			sMessage.append(": 0\n");
		Write(sMessage.c_str());
	}
	Write("\n");
}

void ConsoleApp::Write(const char* szText)
{
	cout << szText;
}