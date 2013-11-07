#pragma once
#include <iostream>
#include <vector>

class Node
{
public:
	Node(const char* szIdentifier);
	virtual ~Node(void);

	virtual int SendSignal();
	virtual void GetIdentifier(std::string& rsIdentifier) = 0;


	bool m_bSignal;
	std::vector<bool> m_vInputs;
	std::vector<Node*> m_vNextNodes;

protected:
	std::string m_sIdentifier;
};

