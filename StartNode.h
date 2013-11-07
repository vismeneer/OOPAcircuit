#pragma once
#include "node.h"
#include <iostream>

class StartNode :
	public Node
{
public:
	StartNode(const char* szIdentifier, bool bSignal);
	virtual ~StartNode(void);

	int SendSignal();
	void GetIdentifier(std::string& rsIdentifier);
};

