#include "stdafx.h"
#include "NotNode.h"
#include "ConsoleApp.h"

NotNode NotNode::m_cNotNode("NOT");

NotNode::NotNode(const char* szType) : Node(szType)
{
}

NotNode::NotNode(void)
{
}

NotNode::~NotNode(void)
{
}

Node* NotNode::Clone() const
{
	return new NotNode;
}

int NotNode::SendSignal()
{
	if (ProcessSignals())
		return Node::SendSignal();
	return 0;
}

int NotNode::ProcessSignals()
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
	return 1;
}