//following Microsoft documentation and examples
//https://docs.microsoft.com/en-us/windows/win32/toolhelp/taking-a-snapshot-and-viewing-processes

#include<iostream>
#include<string>
#include<Windows.h>
#include <tlhelp32.h>

HANDLE process = NULL; 

bool getprocess(char* processname)
{
	HANDLE processSnap;
	PROCESSENTRY32 proc32;
	DWORD procid;

	proc32.dwSize = sizeof(PROCESSENTRY32);
	processSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (processSnap == INVALID_HANDLE_VALUE)
	{
		std::cout << "INVALID_HANDLE_VALUE" << std::endl;
		return false;
	}

	while (Process32Next(processSnap, &proc32))
	{
		if (!strcmp(processname, proc32.szExeFile)) //dont forget to go to project properties > advanced > character set > multi-byte
		{
			process = OpenProcess(PROCESS_ALL_ACCESS, false, proc32.th32ProcessID);
			procid = proc32.th32ProcessID;

			if (process == NULL)
			{
				std::cout << "failed to get the process" << std::endl;
			}
			CloseHandle(processSnap);
			return true;
		}
	}
	CloseHandle(processSnap);
	std::cout << "process not found" << std::endl;
	return false;
}


int main()
{
	DWORD MemoryaAdress = 0x00F0A3F8; // memory address to change
	int NewMemoryValue = 100; // value you want to overwrite
	getprocess((char*)"something.exe"); //processname goes here
	
	WriteProcessMemory(process,(PVOID)MemoryaAdress,&NewMemoryValue,sizeof(int),0);
}