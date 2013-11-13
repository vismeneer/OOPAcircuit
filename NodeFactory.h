#pragma once
#include <map>
#include <string>
#include "Node.h"

class Node;

class NodeFactory
{
public:
	NodeFactory(void);
	~NodeFactory(void);

	static  Node* create( const char* );


private:
	typedef std::map<std::string, Node*> CDecoratorMap;
	static CDecoratorMap m_cDecoratorMap;

	static void assign( const char*, Node* );
	friend class Node;
};

