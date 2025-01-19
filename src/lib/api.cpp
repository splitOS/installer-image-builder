#include "api.hpp"
#include <filesystem>

bool doesLocalKernelExist() {
    std::filesystem::path kernelPath = std::filesystem::current_path() / "bzImage";
    if (std::filesystem::exists(kernelPath) && std::filesystem::is_regular_file(kernelPath))
        return true; else return false;
}