#pragma once

#include "FileReader.h"
#include <vector>
#include "Node.h"

class Creator
{
public:
	Creator(void);
	virtual ~Creator(void);
	int Create(FileReader* pReader);


	std::vector<Node*> m_vNodes;
	std::vector<Node*> m_vProbes;

private:
	int Initialize(std::string sCircuit);
	int CreateNode(std::string& rsCircuit);
	int LinkNode(std::string& rsCircuit);
	void SplitTrim(std::string sCircuit, std::vector<std::string>& rsaValues);
	Node* FindNode(const char* szIdentifier);
};

