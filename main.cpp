#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <thread> // For std::this_thread::sleep_for

namespace fs = std::filesystem;

// Function to extract the last numbers before ".pdf" from a filename
float extractFloatValueFromFilename(const std::string& filename) {
    std::regex pattern("(\\d+\\.?\\d*)\\.pdf$"); // Regular expression pattern to match the last numbers before ".pdf"
    std::smatch match;
    if (std::regex_search(filename, match, pattern)) {
        std::string floatStr = match[1]; // Extract the matched numbers as a string
        return std::stof(floatStr); // Convert the string to a float
    }
    return std::numeric_limits<float>::max(); // Return maximum float value if no numbers were found
}

// Custom comparator function to compare filenames based on extracted float values
bool compareFilenamesByFloatValue(const std::string& filename1, const std::string& filename2) {
    float floatValue1 = extractFloatValueFromFilename(filename1);
    float floatValue2 = extractFloatValueFromFilename(filename2);
    return floatValue1 < floatValue2;
}

// Function to list files in a directory and extract float values from their filenames
std::vector<std::string> listFilesAndExtractFloatValues(const std::string& directoryPath) {
    std::vector<std::string> filenames;

    // Check if the provided path exists and is a directory
    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        std::cerr << "Error: Invalid directory path." << std::endl;
        return filenames;
    }

    // Iterate over the files in the directory
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            filenames.push_back(entry.path().filename().string());
        }
    }

    // Sort filenames based on extracted float values
    std::sort(filenames.begin(), filenames.end(), compareFilenamesByFloatValue);

    return filenames;
}

int main(int argc, char *argv[]) {
    // Check if there is exactly one command-line argument (excluding the program name)
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
        return 1; // Return error code
    }

    // Get the directory path from the command-line argument
    std::string dir_path = argv[1];

    // Call the function to list files in the directory and extract float values from their filenames
    std::vector<std::string> filenames = listFilesAndExtractFloatValues(dir_path);

    // Open PDF files in the default PDF viewer with a delay between each file
    for (const auto& filename : filenames) {
        std::string filePath = dir_path + "/" + filename;
        std::string command = "xdg-open \"" + filePath + "\" &"; // Command to open PDF file using xdg-open in background
        std::system(command.c_str()); // Execute the command
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for 1 second
    }

    return 0; // Return success code
}