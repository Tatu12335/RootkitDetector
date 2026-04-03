#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#pragma comment(lib, "iphlpapi.lib") // Link against the Iphlpapi library for network functions
#pragma comment(lib, "ws2_32.lib") // Link against the Winsock library for network functions
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <winternl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iphlpapi.h>
#include <strsafe.h>
#include "network_scanner.h"
#include <WinSock2.h>

void scan_network_connections();
void check_network_integrity();
void analyze_network_behavior();
void check_for_malicious_network_activity();
void monitor_network_changes();

void scan_network_connections()
{
	DWORD dwSize = 0;
	PVOID BUFFER = NULL;
	

	DWORD dEnxtended = GetExtendedTcpTable(NULL,
		&dwSize,
		FALSE,
		AF_INET,
		TCP_TABLE_OWNER_PID_ALL,
		0);

	if (dEnxtended == ERROR_INSUFFICIENT_BUFFER) 
	{
		// Allocate the necessary buffer size for the TCP table
		BUFFER = malloc(dwSize);

		if(BUFFER == NULL)
		{
			wprintf(L"Memory allocation failed. Error: %lu\n", GetLastError());
			return;
		} 
		
		dEnxtended = GetExtendedTcpTable(BUFFER,
			&dwSize,
			TRUE,
			AF_INET,
			TCP_TABLE_OWNER_PID_ALL,
			0);
		
		if (dEnxtended != NO_ERROR)
			wprintf(L"GetExtendedTcpTable failed. Error: %lu\n", GetLastError());
		
		for(int i = 0; i < ((MIB_TCPTABLE_OWNER_PID*)BUFFER)->dwNumEntries; i++)
		{
			// Moves the pointer to the current row in the TCP table and prints the connection information
			MIB_TCPROW_OWNER_PID row = ((MIB_TCPTABLE_OWNER_PID*)BUFFER)->table[i];
			wprintf(L"Local Addr: %u.%u.%u.%u:%u | Remote Addr: %u.%u.%u.%u:%u | State: %u | PID: %u\n",
				row.dwLocalAddr & 0xFF, (row.dwLocalAddr >> 8) & 0xFF, (row.dwLocalAddr >> 16) & 0xFF, (row.dwLocalAddr >> 24) & 0xFF, ntohs((USHORT)row.dwLocalPort),
				row.dwRemoteAddr & 0xFF, (row.dwRemoteAddr >> 8) & 0xFF, (row.dwRemoteAddr >> 16) & 0xFF, (row.dwRemoteAddr >> 24) & 0xFF, ntohs((USHORT)row.dwRemotePort),
				row.dwState,
				row.dwOwningPid);
		}
		free(BUFFER);
		
	
	}
	closesocket(0); 
	
}
void check_network_integrity()
{
	
}
void analyze_network_behavior()
{

}
void check_for_malicious_network_activity()
{
	
}
void monitor_network_changes()
{

}
