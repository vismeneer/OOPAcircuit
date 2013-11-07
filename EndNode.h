#pragma once
#include "node.h"
class EndNode :
	public Node
{
public:
	EndNode(const char* szIdentifier);
	virtual ~EndNode(void);

	int SendSignal();
	void GetIdentifier(std::string& rsIdentifier);
};

