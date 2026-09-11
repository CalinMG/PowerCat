#include <windows.h>
#include <powrprof.h>
#include <iostream>
#include <vector>

int main() {
    GUID* activeSchemeGuid = nullptr;
    DWORD status = PowerGetActiveScheme(NULL, &activeSchemeGuid);

    if (status != ERROR_SUCCESS || activeSchemeGuid == nullptr) {
        std::cerr << "Failed to retrieve active power scheme. Error code: " << status << std::endl;
        return 1;
    }

    // Determine required buffer size for the friendly display name
    DWORD bufferSize = 0;
    PowerReadFriendlyName(NULL, activeSchemeGuid, NULL, NULL, NULL, &bufferSize);

    if (bufferSize > 0) {
        std::vector<UCHAR> buffer(bufferSize);
        if (PowerReadFriendlyName(NULL, activeSchemeGuid, NULL, NULL, buffer.data(), &bufferSize) == ERROR_SUCCESS) {
            std::wcout << L"Current Active Power Plan: " 
                       << reinterpret_cast<wchar_t*>(buffer.data()) 
                       << std::endl;
        }
    }

    // Clean up memory allocated by the Power Management API
    LocalFree(activeSchemeGuid);
    return 0;
}