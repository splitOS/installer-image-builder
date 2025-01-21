#include <iostream>
#include <filesystem>
#include <unistd.h>
#include "lib/api.hpp"

int main() {
    // Abort program if user isn't root/UID 0
    if (getuid() != 0) {
        std::cerr << "Please run this program as root.\n";
        return 2;
    }

    // Splash text
    std::cout << "--== splitOS installer image builder ==--\n";
    
    // If there is a local kernel found.
    bool localKernel = false;

    // Check to see if a kernel binary bzImage is found in the current working dir 
    if (doesLocalKernelExist()) {
        localKernel = true;
        std::cout << "Local kernel binary found. Using.";
    } else {
        std::cerr << "A kernel binary in the current working directory was not found.\n";
        return 1;
    }

    // Create the ISO root filesystem
    std::cout << "Creating ISO root filesystem...\n";
    std::filesystem::path isoRootPath = "/tmp/splitos-iib-isoroot";

    if (std::filesystem::exists(isoRootPath)) {
        std::cout << "DEBUG: Path exists";
        if (std::filesystem::is_directory(isoRootPath)) std::filesystem::remove_all(isoRootPath);
        else std::filesystem::remove(isoRootPath);
    } else std::cout << "DEBUG: Path does not exist";

    std::filesystem::create_directory(isoRootPath);
}