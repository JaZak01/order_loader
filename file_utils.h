#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string>
#include <vector>
#include <filesystem>
#include <regex>
#include <algorithm>
#include <iostream>

namespace fs = std::filesystem;

float extractFloatValueFromFilename(const std::string& filename);
bool compareFilenamesByFloatValue(const std::string& filename1, const std::string& filename2);
std::vector<std::string> listFilesAndExtractFloatValues(const std::string& directoryPath);

#endif // FILE_UTILS_H
