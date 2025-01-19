#include <iostream>
#include <filesystem>
#include "lib/api.hpp"

int main() {
    std::cout << "--== splitOS installer image builder ==--\n";

    bool localKernel = false;

    // TODO: implement file type checking so bzImage can't be just a normal text file
    if (doesLocalKernelExist()) {
        localKernel = true;
        std::cout << "Local kernel binary found. Using.";
    } else {
        std::cerr << "A kernel binary in the current working directory was not found.\n";
        return 1; // TODO: Instead, download a kernel or specify a different path
    }

    std::cout << "Creating ISO root...\n";

    std::filesystem::path isoRootPath = "/tmp/splitos-iib-isoroot";

    if (std::filesystem::exists(isoRootPath)) {
        std::cout << "DEBUG: Path exists";
        if (std::filesystem::is_directory(isoRootPath)) std::filesystem::remove_all(isoRootPath);
        else std::filesystem::remove(isoRootPath);
    } else std::cout << "DEBUG: Path does not exist";

    std::filesystem::create_directory(isoRootPath);
}