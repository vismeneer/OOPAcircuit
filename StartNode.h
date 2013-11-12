#pragma once
#include "node.h"
#include <iostream>

class StartNode :
	public Node
{
public:
	StartNode(void);
	StartNode(const char* szType);
	virtual ~StartNode(void);

	virtual Node* Clone() const;
	virtual int SendSignal();
	virtual int ProcessSignals();

private:
    static StartNode m_cStartNode;
};

