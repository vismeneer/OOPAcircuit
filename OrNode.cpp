#include "stdafx.h"
#include "OrNode.h"
#include "ConsoleApp.h"

OrNode::OrNode(const char* szIdentifier) : Node(szIdentifier)
{
}


OrNode::~OrNode(void)
{
}

int OrNode::SendSignal()
{
	if (m_vInputs.size() < 2)
	{
		std::string sMessage = m_sIdentifier;
		sMessage.append("/OR: heeft minder dan twee inputs.\n");
		ConsoleApp::Write(sMessage.c_str());
		return 0;
	}
	else
	{
		m_bSignal = false;
		for(std::vector<bool>::iterator it = m_vInputs.begin(); it != m_vInputs.end(); ++it) 
		{
			if (*it)
				m_bSignal = true;
		}
	}
	
	Node::SendSignal();
	return 1;
}

void OrNode::GetIdentifier(std::string& rsIdentifier)
{
	rsIdentifier = m_sIdentifier;
}