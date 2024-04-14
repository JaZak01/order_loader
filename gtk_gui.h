#ifndef GTK_GUI_H
#define GTK_GUI_H

#include <gtk/gtk.h>
#include <string>
#include <vector>
#include <thread>
#include "file_utils.h"

void openFiles(GtkWidget *widget, gpointer data);
void openFilesI(GtkWidget *widget, gpointer data);
void callback_function(GtkWidget *widget, gpointer user_data);

#endif // GTK_GUI_H
