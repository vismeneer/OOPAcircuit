#include "stdafx.h"
#include "StartNode.h"


StartNode::StartNode(const char* szIdentifier, bool bSignal) : Node(szIdentifier)
{
	m_bSignal = bSignal;
}


StartNode::~StartNode(void)
{
}

int StartNode::SendSignal()
{
	Node::SendSignal();
	return 1;
}

void StartNode::GetIdentifier(std::string& rsIdentifier)
{
	rsIdentifier = m_sIdentifier;
}