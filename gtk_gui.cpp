#include "gtk_gui.h"

// Callback function for handling button click events
 void openFiles(GtkWidget *widget, gpointer data) {
    const char* directoryPath = reinterpret_cast<const char*>(data);
    std::vector<std::string> filenames = listFilesAndExtractFloatValues(directoryPath);
    for (const auto& filename : filenames) {
        std::string filePath = directoryPath + std::string("/") + filename;
        std::string command = "xdg-open \"" + filePath + "\" &";
        std::system(command.c_str());
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void openFilesI(GtkWidget *widget, gpointer data) {
     const char* directoryPath = nullptr;
     if (data != nullptr) {
         // Path provided via entry widget
         directoryPath = gtk_entry_get_text(GTK_ENTRY(data));
     } else {
         // Path provided via command-line argument
         directoryPath = reinterpret_cast<const char*>(data);
     }

     if (directoryPath != nullptr) {
         // Call the function to list files in the directory and extract float values from their filenames
         std::vector<std::string> filenames = listFilesAndExtractFloatValues(directoryPath);
         if (!filenames.empty()) {
             // Open PDF files in the default PDF viewer with a delay between each file
             for (const auto& filename : filenames) {
                 std::string filePath = std::string(directoryPath) + "/" + filename;
                 std::string command = "xdg-open \"" + filePath + "\" &";
                 std::system(command.c_str());
                 std::this_thread::sleep_for(std::chrono::seconds(1));
             }
         } else {
             std::cerr << "Error: No PDF files found in the directory." << std::endl;
         }
     } else {
         std::cerr << "Error: Invalid directory path." << std::endl;
     }
 }

