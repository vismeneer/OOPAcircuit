#include "stdafx.h"
#include "FileReader.h"
#include <fstream>
#include <string>

#include "ConsoleApp.h"

FileReader::FileReader(const char* szFileName)
{
	if (szFileName == NULL)
		ConsoleApp::Write("Filename is a nullpointer.");
	else
		this->m_sFileName.append(szFileName);
}


FileReader::~FileReader(void)
{
}

int FileReader::ReadFile(std::string& rsText)
{
	using namespace std;

	string sLine;
	ifstream myfile (m_sFileName);
	if (myfile.is_open())
	{
		while ( getline (myfile,sLine) )
		{
			rsText.append(sLine + "\n");
		}
		myfile.close();
		return 1;
	}
	else 
	{
		ConsoleApp::Write("Unable to open file.");
		return 0;
	}
}