#pragma once
#include "Node.h" 
#include <iostream>

class AndNode : public Node
{
public:
	AndNode(void);
	AndNode(const char* szType);
	virtual ~AndNode(void);

	virtual Node* Clone() const;
	virtual int SendSignal();
	virtual int ProcessSignals();

private:
    static AndNode m_cAndNode;
};

