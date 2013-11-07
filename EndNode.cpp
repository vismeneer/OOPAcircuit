#include "stdafx.h"
#include "EndNode.h"
#include "ConsoleApp.h"

EndNode::EndNode(const char* szIdentifier) : Node(szIdentifier)
{
}


EndNode::~EndNode(void)
{
}

int EndNode::SendSignal()
{
	if (m_vInputs.size() < 1 || m_vInputs.size() > 1)
	{
		std::string sMessage = m_sIdentifier;
		sMessage.append("/PROBE: heeft niet maar een input.\n");
		ConsoleApp::Write(sMessage.c_str());
		return 0;
	}
	else
		m_bSignal = m_vInputs[0];
	return 1;
}

void EndNode::GetIdentifier(std::string& rsIdentifier)
{
	rsIdentifier = m_sIdentifier;
}
