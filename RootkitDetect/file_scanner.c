#define WIN32_LEAN_AND_MEAN 
#include "file_scanner.h"
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <winternl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strsafe.h>
#include <fileapi.h>
#include <tchar.h>
#include <locale.h>
#include <fcntl.h>
#include <io.h>

void ScanDirectory(const TCHAR* filePath);
void scan_filesystem();
void check_file_integrity();
void detect_hidden_files();
void analyze_file_metadata();
void check_for_malicious_files();
void scan_for_rootkit_files();
void monitor_filesystem_changes();

int main()
{
	setlocale(LC_ALL, "");

	_setmode(_fileno(stdout), _O_U16TEXT);

	ScanDirectory(L"C:\\");
	scan_filesystem();
	check_file_integrity();
	detect_hidden_files();
	analyze_file_metadata();
	check_for_malicious_files();
	scan_for_rootkit_files();
	monitor_filesystem_changes();
	return 0;
}

void scan_filesystem()
{
	// Implement filesystem scanning logic here
	// This could involve enumerating files and directories, checking for hidden files, etc.
	
	

	
	
}
void ScanDirectory(const TCHAR* filePath)
{
	// Implement file path validation logic here
	// This could involve checking for invalid characters, ensuring the path is within allowed directories, etc.

	
	wchar_t searchPath[MAX_PATH];
	swprintf(searchPath, MAX_PATH, L"%s\\*", filePath);

	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFileW(searchPath, &findFileData);

	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if(wcscmp(findFileData.cFileName, L".") == 0 || strcmp(findFileData.cFileName, L"..") == 0)
			{
				continue; // Skip current and parent directory entries
			}
			
			wprintf(L"Found file: %s\n", findFileData.cFileName);
			
			if(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				wchar_t subDir[MAX_PATH];
				swprintf(subDir, MAX_PATH, L"%s\\%s", filePath, findFileData.cFileName);
				ScanDirectory(subDir);
			}
			else
			{
				// Implement file analysis logic here
				// This could involve checking file attributes, analyzing file content, etc.
			}
		} while (FindNextFileW(hFind, &findFileData) != 0 );
		
		FindClose(hFind);
	}
	else
	{
		
		wprintf(L"Failed to open directory: %s. ERROR : %lu\n", filePath,GetLastError());
	}

}
void check_file_integrity()
{
	// Implement file integrity checking logic here
	// This could involve calculating and comparing file hashes, checking for modified files, etc.
}
void detect_hidden_files()
{
	// Implement hidden file detection logic here
	// This could involve checking file attributes, looking for files with suspicious names, etc.
}
void analyze_file_metadata()
{
	// Implement file metadata analysis logic here
	// This could involve checking file creation and modification times, owner information, etc.
}
void check_for_malicious_files()
{
	// Implement malicious file detection logic here
	// This could involve checking file signatures, looking for known malware patterns, etc.
}
void scan_for_rootkit_files()
{
	// Implement rootkit file scanning logic here
	// This could involve looking for files commonly associated with rootkits, checking for hidden files, etc.
}
void monitor_filesystem_changes()
{
	// Implement filesystem change monitoring logic here
	// This could involve using Windows APIs to watch for changes in the filesystem, such as new files being created or existing files being modified.
}
