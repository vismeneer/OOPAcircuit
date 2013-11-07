#pragma once

#include <iostream>

class FileReader
{
public:
	FileReader(const char* szFileName);
	virtual ~FileReader(void);
	
	int ReadFile(std::string& rsText);

private:
	std::string m_sFileName;
};

