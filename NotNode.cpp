#include "stdafx.h"
#include "NotNode.h"
#include "ConsoleApp.h"

NotNode::NotNode(const char* szIdentifier) : Node(szIdentifier)
{
}


NotNode::~NotNode(void)
{
}

int NotNode::SendSignal()
{
	if (m_vInputs.size() < 1 || m_vInputs.size() > 1)
	{
		std::string sMessage = m_sIdentifier;
		sMessage.append("/NOT: heeft niet maar een input.\n");
		ConsoleApp::Write(sMessage.c_str());
		return 0;
	}
	else
	{
		m_bSignal = !m_vInputs[0];
	}
	
	Node::SendSignal();
	return 1;
}

void NotNode::GetIdentifier(std::string& rsIdentifier)
{
	rsIdentifier = m_sIdentifier;
}