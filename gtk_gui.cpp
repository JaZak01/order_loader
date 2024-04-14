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


