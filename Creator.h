#pragma once

#include "FileReader.h"
#include <list>

class Creator
{
public:
	Creator(FileReader& rReader);
	~Creator(void);

private:
	void Initialize(std::string sCircuit);
	int CreateNode(std::string& rsCircuit);
	int LinkNode(std::string& rsCircuit);

	std::list<int> Inputs;
	std::list<int> Outputs;
	std::list<int> Nodes;
};

