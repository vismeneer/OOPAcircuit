#include "stdafx.h"
#include "Node.h"
#include "NodeFactory.h"


Node::Node(const char* szType)
{
	NodeFactory::assign(szType, this);
}

Node::Node(void) 
{
}
Node::~Node(void) 
{
}

int Node::SendSignal() 
{
	for(std::vector<Node*>::iterator it = m_vNextNodes.begin(); it != m_vNextNodes.end(); ++it) 
	{
		Node* pNode = *it;
		pNode->m_vInputs.push_back(m_bSignal);
	}
	return 1;
}