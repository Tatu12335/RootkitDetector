#ifndef FILE_SCANNER_H
#define FILE_SCANNER_H
#include <windows.h>



void ScanDirectory(const TCHAR* filePath);
void check_file_integrity();
void analyze_file_metadata();
void check_for_malicious_files();
void scan_for_rootkit_files();
void monitor_filesystem_changes();
#endif 
