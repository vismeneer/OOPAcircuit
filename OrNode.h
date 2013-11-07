#pragma once
#include "node.h"
class OrNode :
	public Node
{
public:
	OrNode(const char* szIdentifier);
	virtual ~OrNode(void);

	int SendSignal();
	void GetIdentifier(std::string& rsIdentifier);
};

