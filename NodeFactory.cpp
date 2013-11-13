#include "stdafx.h"
#include "NodeFactory.h"
#include "AndNode.h"
NodeFactory::CDecoratorMap NodeFactory::m_cDecoratorMap;

NodeFactory::NodeFactory(void)
{
}


NodeFactory::~NodeFactory(void)
{
}

void NodeFactory::assign( const char* szType, Node* pStrategy )
{
    m_cDecoratorMap[std::string(szType)] = pStrategy;
}

Node* NodeFactory::create( const char* szType )
{
    CDecoratorMap::const_iterator cFind = m_cDecoratorMap.find( szType );

    if ( cFind == m_cDecoratorMap.end() )
        return NULL;
    else
        return cFind->second->Clone();
}