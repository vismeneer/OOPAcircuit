#include "stdafx.h"
#include "Node.h"


Node::Node(const char* szIdentifier) 
{
	if (szIdentifier!= NULL) 
		m_sIdentifier.append(szIdentifier);
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