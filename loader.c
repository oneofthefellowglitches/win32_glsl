/* glslangValidator -V julia.comp -o shader.spv */
#include <windows.h>

void* LoadShaderSPIRV(const char* filename, size_t* outSize) {
    HANDLE hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, 
                               OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) return NULL;

    DWORD size = GetFileSize(hFile, NULL);
    void* buffer = HeapAlloc(GetProcessHeap(), 0, size);
    
    DWORD bytesRead;
    ReadFile(hFile, buffer, size, &bytesRead, NULL);
    CloseHandle(hFile);

    *outSize = (size_t)size;
    return buffer;
}
