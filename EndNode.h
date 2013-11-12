#pragma once
#include "node.h"
class EndNode :
	public Node
{
public:
	EndNode(void);
	EndNode(const char* szType);
	virtual ~EndNode(void);

	virtual Node* Clone() const;
	virtual int SendSignal();
	virtual int ProcessSignals();

private:
    static EndNode m_cEndNode;
};

