#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>
#include <windows.h>

void* mem_alloc(size_t size) { return HeapAlloc(GetProcessHeap(), 0, size); }
void  mem_free(void* ptr)    { HeapFree(GetProcessHeap(), 0, ptr); }

void WinMainCRTStartup() {
    VkInstanceCreateInfo instInfo = { VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
    VkInstance instance;
    vkCreateInstance(&instInfo, NULL, &instance);

    VkPhysicalDevice gpu;
    uint32_t gpuCount = 1;
    vkEnumeratePhysicalDevices(instance, &gpuCount, &gpu);
    // vkAllocateMemory flag VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT

  float time = 0.0f;
    while(1) {
        time += 0.01f;
        // vkCmdDispatch(cmdBuf, width/16, height/16, 1);
        // bufora -> Swapchain
        // ...
        
        if (GetAsyncKeyState(VK_ESCAPE)) break;
    }

    ExitProcess(0);
}
