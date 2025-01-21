#include <iostream>
#include <filesystem>
#include <vector>
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
        std::cout << "Local kernel binary found. Using.\n";
    } else {
        std::cerr << "A kernel binary in the current working directory was not found.\n";
        return 1;
    }

    // Create the work directory
    std::cout << "Creating work directory...\n";
    std::filesystem::path workDirPath = "/tmp/splitos-iib-workdir";

    if (std::filesystem::exists(workDirPath)) {
        if (std::filesystem::is_directory(workDirPath)) std::filesystem::remove_all(workDirPath);
        else std::filesystem::remove(workDirPath);
    }

    std::filesystem::create_directory(workDirPath);

    std::cout << "Creating filesystem hierarchy...\n";

    // Define all FHS directories the ISO needs
    const std::vector<std::filesystem::path> directories = {
        "bin", "boot", "dev", "etc", "usr",
        "lib", "lib64", "media", "mnt", "run",
        "sbin", "tmp", "proc", "sys", "dev"
    };

    // Create the directories
    for (int i = 0; i < directories.size(); i++) {
        const std::filesystem::path directory = workDirPath / directories[i];
        std::filesystem::create_directory(directory);
    }
}