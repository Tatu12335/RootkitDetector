#define WIN32_LEAN_AND_MEAN  
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <winternl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*int main()
{
	HANDLE hProcessSnap;
	PROCESSENTRY32 pe32;

	BOOL EnumProcesses(DWORD *lpidProcesses, DWORD cb,LPDWORD lbcbNeeded);
	BOOL EnumProcessModules(HANDLE hProcess, HMODULE * lphModule, DWORD cb, LPDWORD lpcbNeeded);

	

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if(hProcessSnap == INVALID_HANDLE_VALUE)
	{
		printf("CreateToolhelp32Snapshot (of processes) failed");
		return(1);
	}

	pe32.dwSize = sizeof(PROCESSENTRY32);
	if(!Process32First(hProcessSnap, &pe32))
	{
		printf("Process32First failed");
		CloseHandle(hProcessSnap);
		return(1);
	}

	for(int i = 0; i < 1024; i++)
	{
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe32.th32ProcessID);
		if(hProcess)
		{
			HMODULE hMod;
			DWORD cbNeeded;
			if(EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
			{
				TCHAR szProcessName[MAX_PATH];
				GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName)/sizeof(TCHAR));
				if(strcmp(szProcessName, "notepad.exe") == 0)
				{
					printf("Notepad process found with PID: %u\n", pe32.th32ProcessID);
				}
			}
			CloseHandle(hProcess);
		}
	}

	do {
		printf("Processname %ls Process ID: %u\n",pe32.szExeFile ,pe32.th32ProcessID);
	} while (Process32Next(hProcessSnap, &pe32));
		
	printf("Done.\n");
		
	CloseHandle(hProcessSnap);
}*/
