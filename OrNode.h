#pragma once
#include "node.h"
class OrNode :
	public Node
{
public:
	OrNode(void);
	OrNode(const char* szType);
	virtual ~OrNode(void);

	virtual Node* Clone() const;
	virtual int SendSignal();
	virtual int ProcessSignals();

private:
    static OrNode m_cOrNode;
};

