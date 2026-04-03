#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN  
#endif


#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <winternl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_scanner.h"
#include "file_scanner.h"
#include "network_scanner.h"
#include <locale.h>
#include <fcntl.h>
#include <io.h>
#include <WinSock2.h>


int main()
{
	
	setlocale(LC_ALL, "");

	_setmode(_fileno(stdout), _O_U16TEXT);

	LPWSADATA wsaData;

 
	ScanDirectory(L"C:\\");// See file_scanner.c for filesystem scanning implementation
	// See process_scanner.c for process scanning implementation
	scan_processes();

	WSAStartup(MAKEWORD(2, 2), &wsaData);// Initialize Winsock for network scanning
	scan_network_connections(); // See network_scanner.c for network scanning implementation

	return 0;
}