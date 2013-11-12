#include "stdafx.h"
#include "OrNode.h"
#include "ConsoleApp.h"

OrNode OrNode::m_cOrNode("OR");

OrNode::OrNode(const char* szType) : Node(szType)
{
}

OrNode::OrNode(void)
{
}

OrNode::~OrNode(void)
{
}

Node* OrNode::Clone() const
{
	return new OrNode;
}

int OrNode::SendSignal()
{
	if (ProcessSignals())
		return Node::SendSignal();
	return 0;
}

int OrNode::ProcessSignals()
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
	return 1;
}