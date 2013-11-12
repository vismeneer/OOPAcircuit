#pragma once
#include "node.h"
class NotNode :
	public Node
{
public:
	NotNode(void);
	NotNode(const char* szType);
	virtual ~NotNode(void);

	virtual Node* Clone() const;
	virtual int SendSignal();
	virtual int ProcessSignals();

private:
    static NotNode m_cNotNode;
};

