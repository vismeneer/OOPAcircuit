#include "stdafx.h"
#include "AndNode.h"
#include "ConsoleApp.h"

AndNode::AndNode(const char* szIdentifier) : Node(szIdentifier)
{
}


AndNode::~AndNode(void)
{
}

int AndNode::SendSignal()
{
	if (m_vInputs.size() < 2)
	{
		std::string sMessage = m_sIdentifier;
		sMessage.append("/AND: heeft minder dan twee inputs.\n");
		ConsoleApp::Write(sMessage.c_str());
		return 0;
	}
	else
	{
		m_bSignal = true;
		for(std::vector<bool>::iterator it = m_vInputs.begin(); it != m_vInputs.end(); ++it) 
		{
			if (!*it)
				m_bSignal = false;
		}
	}
	
	Node::SendSignal();
	return 1;
}

void AndNode::GetIdentifier(std::string& rsIdentifier)
{
	rsIdentifier = m_sIdentifier;
}