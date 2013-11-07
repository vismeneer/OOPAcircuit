#pragma once
#include "node.h"
class NotNode :
	public Node
{
public:
	NotNode(const char* szIdentifier);
	virtual ~NotNode(void);

	int SendSignal();
	void GetIdentifier(std::string& rsIdentifier);
};

