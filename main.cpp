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

    // Create a button
    GtkWidget *button = gtk_button_new_with_label("Open PDF Files");
    g_signal_connect(button, "clicked", G_CALLBACK(openFiles), reinterpret_cast<gpointer>(argv[1]));

    // Add the button to the window
    gtk_container_add(GTK_CONTAINER(window), button);

    // Show all widgets
    gtk_widget_show_all(window);

    // Main GTK loop
    gtk_main();

    return 0;
}
