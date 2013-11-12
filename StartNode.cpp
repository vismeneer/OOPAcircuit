#include "stdafx.h"
#include "StartNode.h"

StartNode StartNode::m_cStartNode("INPUT");

StartNode::StartNode(const char* szType) : Node(szType)
{
}

StartNode::StartNode(void)
{
}

StartNode::~StartNode(void)
{
}

Node* StartNode::Clone() const
{
	return new StartNode;
}

int StartNode::SendSignal()
{
	return Node::SendSignal();
}

int StartNode::ProcessSignals()
{
	return 0;
}