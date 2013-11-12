#include "stdafx.h"
#include "Creator.h"
#include "ConsoleApp.h"
#include "Node.h"
#include <algorithm>
#include "NodeFactory.h"

Creator::Creator()
{
}


Creator::~Creator(void)
{
	for (Node* pNode : m_vNodes)
		delete pNode;
}

int Creator::Create(FileReader* pReader)
{
	std::string sCircuit;
	if (pReader->ReadFile(sCircuit))
	{
		return Initialize(sCircuit);
	}
	else
		return 0;
}


int Creator::Initialize(std::string sCircuit)
{
	// Split all lines and either create them or link them.
	// The create part and link part are split by an empty line.
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
			// Swap from creating to linking after empty line
			if (token.size() == 0)
			{
				Linking = true;
				// De probes worden eerst apart gezet alvorens hier als laatste toegevoegd te worden aan de nodes list.
				for(std::vector<Node*>::iterator it = m_vProbes.begin(); it != m_vProbes.end(); ++it) 
				{
					Node* pNode = *it;
					m_vNodes.push_back(pNode);
				}
			}
			else
			{
				if (!Linking)
				{
					if (!CreateNode(token))
					{
						ConsoleApp::Write("Fout tijdens het parsen van het bestand.\n");
						return 0;
					}
				}
				else
				{
					if (!LinkNode(token))
					{
						ConsoleApp::Write("Fout tijdens het parsen van het bestand.\n");
						return 0;
					}
				}
			}
		}
		sCircuit.erase(0, pos + delimiter.length());
	}
	return 1;
}

int Creator::CreateNode(std::string& rsNode)
{
	std::vector<std::string> vElements;
	SplitTrim(rsNode, vElements);
	// Vector should consist of 2 elements at this point.
	if (vElements.size() == 2)
	{
		// catch input_low/high by cutting off _low/_high for the factory
		Node* pNode = NodeFactory::create(vElements[1].substr(0,5).c_str());
		if (!pNode)
			return 0;
	
		// Set nodes variables
		pNode->m_sIdentifier = vElements[0].c_str();
		if (vElements[0].compare("INPUT_HIGH") == 0)
			pNode->m_bSignal = true;
		if (vElements[0].compare("INPUT_LOW") == 0)
			pNode->m_bSignal = false;

		return 1;
	}
	return 0;
}

int Creator::LinkNode(std::string& rsNode)
{
	std::vector<std::string> vElements;

	SplitTrim(rsNode, vElements);
	
	// Vector should at least have 2 elements
	if (vElements.size() >= 2)
	{
		Node* pNode = FindNode(vElements[0].c_str());
		Node* pTargetNode;

		unsigned int i;
		for (i = 1; i < vElements.size(); i++)
		{
			pTargetNode = FindNode(vElements[i].c_str());
			if (pNode != NULL && pTargetNode != NULL)
				pNode->m_vNextNodes.push_back(pTargetNode);
		}

		return 1;
	}

	return 0;
}

void Creator::SplitTrim(std::string sNode, std::vector<std::string>& rsaValues)
{
	std::string delimiter = ":";
	size_t pos = 0;

	// Insert value before ":"
	pos = sNode.find(delimiter);
	rsaValues.push_back(sNode.substr(0, pos));
	sNode.erase(0, pos + delimiter.length());

	// Remove tabs from the rest of the string
	sNode.erase(std::remove(sNode.begin(), sNode.end(), '\t'), sNode.end());
	sNode.erase(std::remove(sNode.begin(), sNode.end(), ' '), sNode.end());
	// Insert either type, or linking nodes
	// Needs to be split if linking nodes
	delimiter = ",";
	pos = sNode.find(delimiter);
	while ((pos = sNode.find(delimiter)) != std::string::npos)
	{
		rsaValues.push_back(sNode.substr(0, pos));
		sNode.erase(0, pos + delimiter.length());
	}
	// Push the last element in the vector
	// Push it till size - 1 since we dont want the ";"
	rsaValues.push_back(sNode.substr(0, sNode.size() - 1));
	sNode.erase(0, pos + delimiter.length());
}

Node* Creator::FindNode(const char* szIdentifier)
{
	for (Node* pNode : m_vNodes)
	{
		std::string sIdentifier = pNode->m_sIdentifier;
		if (sIdentifier.compare(szIdentifier) == 0)
			return pNode;
	}
	return NULL;
}