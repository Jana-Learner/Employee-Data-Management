#include<afxwin.h>
#include"resource.h"
#include"GetSysInformation.h"
#include"iostream"
using namespace std;

CString GetSysInformation::getDeviceName() {
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];
    CString pcName;
    DWORD size = sizeof(computerName) / sizeof(computerName[0]);
    if (GetComputerNameA(computerName, &size)) {
        pcName = computerName;
        return pcName;
    }
    else {
        return "Failed to Device Name!";
    }
}

CString GetSysInformation::getProcessorName() {
    CString processorName;

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    char cpuBrandString[0x40];
    int cpuInfo[4] = { -1 };
    __cpuid(cpuInfo, 0x80000000);
    unsigned int nExIds = cpuInfo[0];
    memset(cpuBrandString, 0, sizeof(cpuBrandString));

    for (unsigned int i = 0x80000000; i <= nExIds; ++i) {
        __cpuid(cpuInfo, i);
        if (i == 0x80000002)
            memcpy(cpuBrandString, cpuInfo, sizeof(cpuInfo));
        else if (i == 0x80000003)
            memcpy(cpuBrandString + 16, cpuInfo, sizeof(cpuInfo));
        else if (i == 0x80000004)
            memcpy(cpuBrandString + 32, cpuInfo, sizeof(cpuInfo));
    }
    processorName = cpuBrandString;
    return processorName;
}

CString GetSysInformation::getRam() {
    CString ram;
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&statex);
    ram.Format(L"%llu GB", (statex.ullTotalPhys / (1024 * 1024))/1000);
    return ram;
}

CString GetSysInformation::getSystemType() {
    CString sysType;
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    switch (sysInfo.wProcessorArchitecture) {
    case PROCESSOR_ARCHITECTURE_AMD64:
        sysType = "64-bit operating system";
        break;
    case PROCESSOR_ARCHITECTURE_INTEL:
        sysType = "32-bit operating system";
        break;
    default:
        sysType = "Unknown operating system";
        break;
    }
    return sysType;
}

CString GetSysInformation::getOperatingSytem() {
    CString opSys;
    /*OSVERSIONINFO osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    if (GetVersionEx(&osvi)) {
        "Operating System: " << osvi.dwMajorVersion << "." << osvi.dwMinorVersion << std::endl;
        std::cout << "Build Number: " << osvi.dwBuildNumber << std::endl;
        std::cout << "Platform ID: " << osvi.dwPlatformId << std::endl;
        std::cout << "CSD Version: " << osvi.szCSDVersion << std::endl;
    }
    else {
        opSys = "Failed to get OS version";
    }*/
    return opSys;
}