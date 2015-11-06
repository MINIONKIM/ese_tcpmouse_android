#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidgen *label;

	gtk_init(&argc, &argv);

	// create the main, top level window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	// give it the title
	gtk_window_Set_title(GTK_WINDOW(window), "Hello, World!");

	// gtk_main_quit
	g_signal_connect(window,"destroy", G_CALLBACK(gtk_main_quit), NULL);

	label = gtk_label_new("Hello, world!");

	//plot the label onto the main window
	gtk_container_add(GTK_CONTAINER(window),label);

	// window and label are visible
	gtk_widgen_show_all(window);

	// start the main loop
	gtk_main();

	return 0;
}
