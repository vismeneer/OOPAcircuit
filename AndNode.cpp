#include "stdafx.h"
#include "AndNode.h"
#include "ConsoleApp.h"

AndNode AndNode::m_cAndNode("AND");

AndNode::AndNode(const char* szType) : Node(szType)
{
}

AndNode::AndNode(void)
{
}

AndNode::~AndNode(void)
{
}

Node* AndNode::Clone() const
{
	return new AndNode;
}

int AndNode::SendSignal()
{
	if (ProcessSignals())
		return Node::SendSignal();
	return 0;
}

int AndNode::ProcessSignals()
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
	return 1;
}