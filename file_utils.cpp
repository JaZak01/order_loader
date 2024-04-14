#include "file_utils.h"

float extractFloatValueFromFilename(const std::string& filename) {
    std::regex pattern("(\\d+\\.?\\d*)\\.pdf$");
    std::smatch match;
    if (std::regex_search(filename, match, pattern)) {
        std::string floatStr = match[1];
        return std::stof(floatStr);
    }
    return std::numeric_limits<float>::max();
}

bool compareFilenamesByFloatValue(const std::string& filename1, const std::string& filename2) {
    float floatValue1 = extractFloatValueFromFilename(filename1);
    float floatValue2 = extractFloatValueFromFilename(filename2);
    return floatValue1 > floatValue2;
}

std::vector<std::string> listFilesAndExtractFloatValues(const std::string& directoryPath) {
    std::vector<std::string> filenames;
    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        std::cerr << "Error: Invalid directory path." << std::endl;
        return filenames;
    }
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            filenames.push_back(entry.path().filename().string());
        }
    }
    std::sort(filenames.begin(), filenames.end(), compareFilenamesByFloatValue);
    return filenames;
}