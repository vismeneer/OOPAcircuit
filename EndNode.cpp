#include "stdafx.h"
#include "EndNode.h"
#include "ConsoleApp.h"

EndNode EndNode::m_cEndNode("PROBE");

EndNode::EndNode(const char* szType) : Node(szType)
{
}

EndNode::EndNode(void)
{
}

EndNode::~EndNode(void)
{
}

Node* EndNode::Clone() const
{
	return new EndNode;
}

int EndNode::SendSignal()
{
	return ProcessSignals();
}

int EndNode::ProcessSignals()
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
