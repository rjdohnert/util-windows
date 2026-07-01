#include <windows.h>
#include <iostream>
#include <iomanip>

int main() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    // Retrieve system memory status
    if (GlobalMemoryStatusEx(&memInfo)) {
        // Conversion factor from bytes to Gigabytes
        const double BYTES_TO_GB = 1024.0 * 1024.0 * 1024.0;

        // Physical Memory calculations
        double totalPhysGB = memInfo.ullTotalPhys / BYTES_TO_GB;
        double availPhysGB = memInfo.ullAvailPhys / BYTES_TO_GB;
        double usedPhysGB = totalPhysGB - availPhysGB;

        // Virtual Memory calculations (System Commit Limit / Page File)
        double totalVirtGB = memInfo.ullTotalPageFile / BYTES_TO_GB;
        double availVirtGB = memInfo.ullAvailPageFile / BYTES_TO_GB;
        double usedVirtGB = totalVirtGB - availVirtGB;

        // Configure decimal output formatting
        std::cout << std::fixed << std::setprecision(2);

        // Display Physical Memory Status
        std::cout << "Physical Memory (RAM):\n";
        std::cout << "  Total Physical Memory:  " << totalPhysGB << " GB\n";
        std::cout << "  Used Physical Memory:   " << usedPhysGB << " GB (" << memInfo.dwMemoryLoad << "% in use)\n";
        std::cout << "  Available Physical:     " << availPhysGB << " GB\n\n";

        // Display Virtual Memory Status (RAM + Page File)
        std::cout << "Virtual Memory (Commit Charge):\n";
        std::cout << "  Total Virtual Memory:   " << totalVirtGB << " GB\n";
        std::cout << "  Used Virtual Memory:    " << usedVirtGB << " GB\n";
        std::cout << "  Available Virtual:      " << availVirtGB << " GB\n";
    } else {
        std::cerr << "Error: Unable to retrieve memory status. Error code: " << GetLastError() << "\n";
        return 1;
    }

    return 0;
}