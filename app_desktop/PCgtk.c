#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

static void enter_callback (GtkWidget *widget, GtkWidget *entry)
{
	const gchar *entry_text;
	entry_text = gtk_entry_get_text (GTK_ENTRY(entry));
	printf("Entry contents : %s\n", entry_text);
}

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vbox, *hbox;
    GtkWidget *entry;
    GtkWidget *button;
    GtkWidget *check;
    gint tmp_pos;

    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 200, 100);
    gtk_window_set_title (GTK_WINDOW (window), "GTK Entry");
    g_signal_connect (window, "destroy",G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect_swapped (window, "delete-event",G_CALLBACK (gtk_widget_destroy), window);

   
    
    gtk_widget_show (window);

    gtk_main();

    return 0;
}
