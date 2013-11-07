#include "stdafx.h"
#include "Creator.h"
#include "ConsoleApp.h"

Creator::Creator(FileReader& rReader)
{
	std::string sCircuit;
	if (rReader.ReadFile(sCircuit))
	{
		Initialize(sCircuit);
	}
}


Creator::~Creator(void)
{
}

void Creator::Initialize(std::string sCircuit)
{
	// Split all lines and either create them or link them, they are split by an empty line.
	std::string delimiter = "\n";
	bool Linking = false;
	size_t pos = 0;
	std::string token;
	while ((pos = sCircuit.find(delimiter)) != std::string::npos)
	{
		token = sCircuit.substr(0, pos);
		// Skip comments
		if (token[0] != '#')
		{
			if (token.size() == 0)
			{
				Linking = true;;
			}
			else
			{
				if (!Linking)
					CreateNode(token.c_str());
				else
					LinkNode(token.c_str());
			}
		}
		sCircuit.erase(0, pos + delimiter.length());
	}
}

int Creator::CreateNode(std::string& rsNode)
{
	szNode.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
	ConsoleApp::Write("Creating node: ");
	ConsoleApp::Write(szNode);
	ConsoleApp::Write("\n");
	return 0;
}

int Creator::LinkNode(std::string& rsNode)
{
	ConsoleApp::Write("Linking node: ");
	ConsoleApp::Write(szNode);
	ConsoleApp::Write("\n");
	return 0;
}