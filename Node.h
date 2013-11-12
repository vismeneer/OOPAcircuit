#pragma once
#include <string>
#include <vector>


class Node
{
public:
	Node(void);
	Node(const char*);
	virtual ~Node(void);

	virtual Node* Clone() const = 0;
	virtual int SendSignal() = 0;
	//virtual int ProcessSignals();

	bool m_bSignal;
	std::string m_sIdentifier;
	std::vector<bool> m_vInputs;
	std::vector<Node*> m_vNextNodes;
};

