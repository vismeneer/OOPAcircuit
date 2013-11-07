#pragma once
class ConsoleApp
{

public:
	ConsoleApp(void);
	~ConsoleApp(void);

	static void Write(const char* szText);

private:
	void CreateCircuit(const char* szFileName);
};

