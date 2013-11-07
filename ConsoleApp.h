#pragma once

#include <vector>
#include "Node.h"

class ConsoleApp
{

public:
	ConsoleApp(void);
	~ConsoleApp(void);

	static void Write(const char* szText);

private:
	void CreateCircuit(const char* szFileName);
	void RunCircuit(std::vector<Node*>& rvNodes, std::vector<Node*>& rvProbes);
};

