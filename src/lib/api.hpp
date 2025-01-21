#ifndef API_HPP
#define API_HPP

#include <string>

// Check if a local kernel ("bzImage") exists in the current working directory.
bool doesLocalKernelExist();

// Check if an ELF binary exists in the current working directory.
bool doesELFBinaryExist(std::string fileName);

#endif // API_HPP