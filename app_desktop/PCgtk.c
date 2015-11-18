#include <Stdlib.h>
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
	GtkWidget *button;
	GtkWidget *window;
	GtkWidget *box1;

	gtk_init(&argc, &argv);  // initialize

	//create the main, top level window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	//give it the title
	gtk_window_set_title(GTK_WINDOW(window), "PC-Android Connection");

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit),NULL);


	gtk_container_set_border_width (GTK_CONTAINER(window), 10);
	gtk_widget_realize(window);

	//create a new button
	button = gtk_button_new();
	//
	gtk_widget_set_size_request(button, 50,50);
	
	label = gtk_lael_new("Hi!");

	// plot the label onto the main window
	gtk_container_add(GTK_CONTAINER(window), label);

	//window and label, are visible
	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
