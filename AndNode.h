#pragma once
#include "Node.h" 
#include <iostream>

class AndNode : public Node
{
public:
	AndNode(const char* szIdentifier);
	virtual ~AndNode(void);

	int SendSignal();
	void GetIdentifier(std::string& rsIdentifier);
};

