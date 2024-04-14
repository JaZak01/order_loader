#include <iostream>
#include <string>
#include "gtk_gui.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Open PDF Files");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    if (argc == 1) {
        // No arguments provided, create an entry widget to input the folder path
        GtkWidget *entry = gtk_entry_new();
        gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Enter path to folder with PDF files");

        // Create a button to trigger the action
        GtkWidget *button = gtk_button_new_with_label("Open PDF Files");
        g_signal_connect(button, "clicked", G_CALLBACK(openFilesI), entry);

        // Create a box to hold the entry and button
        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
        gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

        // Add the box to the window
        gtk_container_add(GTK_CONTAINER(window), box);
    } else {
        // Create a button
        GtkWidget *button = gtk_button_new_with_label("Open PDF Files");
        g_signal_connect(button, "clicked", G_CALLBACK(openFiles), reinterpret_cast<gpointer>(argv[1]));

        // Add the button to the window
        gtk_container_add(GTK_CONTAINER(window), button);
    }

    // Show all widgets
    gtk_widget_show_all(window);

    // Main GTK loop
    gtk_main();

    return 0;
}
