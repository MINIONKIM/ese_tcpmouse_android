#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

static GtkWidget *xpm_label_box( gchar *xpm_filename, gchar *label_text )
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *image;

    /* Create box for image and label */
    box = gtk_hbox_new (FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (box), 2);

    /* Now on to the image stuff */
    image = gtk_image_new_from_file (xpm_filename);

    /* Create a label for the button */
    label = gtk_label_new (label_text);

    /* Pack the image and label into the box */
    gtk_box_pack_start (GTK_BOX (box), image, FALSE, FALSE, 3);
    gtk_box_pack_start (GTK_BOX (box), label, FALSE, FALSE, 3);

    gtk_widget_show (image);
    gtk_widget_show (label);

    return box;
}
static void enter_callback (GtkWidget *widget, GtkWidget *entry)
{
	const gchar *entry_text;
	entry_text = gtk_entry_get_text (GTK_ENTRY(entry));
	printf("Entry contents : %s\n", entry_text);
}

static void button_callback(GtkWidget *widget, gpointer data)
{
	g_print("Hello again - %s was pressed\n", (char *) data);
}

int main (int argc, char *argv[])
{
    /* this variable will store a pointer to the window object. */
    GtkWidget *window;
    GtkWidget *vbox;
    /* this will store a text entry */
    GtkWidget *entry;
    GtkWidget *entry2;   
    /* this will store push buttons */
    GtkWidget *button;
    /* this will store a horizontal box*/
    GtkWidget *hbox;

    GtkWidget *timeLabel;
    gint tmp_pos;

//////////////////////////////////////////////////////////////////////

    /* this is called in all GTK applications. Arguments 
	are parsed from the command line and are returned
 	to the application. */
    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //gtk_widget_set_size_request (GTK_WIDGET (window), 400, 400);
    gtk_window_set_title (GTK_WINDOW (window), "PC GTK Entry");
    gtk_container_set_border_width(GTK_CONTAINER (window), 5);

    /* When the window is given the "delete_event" signal (usually by
	the "close" opthion), we ask it to call the delete_event() function. 
	*/
    g_signal_connect_swapped (window, "delete-event",
				G_CALLBACK (gtk_widget_destroy), window);
    /* Here we connect the "destory" event to a signal handler.
 	This event occurs when we call gtk_widget_destroy() on the window, 
	or if we return FALSE in the "delete_event" callback. */
    g_signal_connect (window, "destroy",G_CALLBACK (gtk_main_quit), NULL);


    // hbox
    hbox = gtk_hbox_new (TRUE, 20);
    gtk_container_add (GTK_CONTAINER (window), hbox);
    gtk_widget_show (hbox);

    //vbox
    vbox = gtk_vbox_new (TRUE, 20);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show (vbox);

    //entry ..	
    entry = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 100);
    g_signal_connect (entry, "activate",G_CALLBACK (enter_callback), entry);
    gtk_entry_set_text (GTK_ENTRY (entry), "Put your IP address");

    tmp_pos = GTK_ENTRY (entry)->text_length;
    gtk_editable_select_region (GTK_EDITABLE (entry),0, 
				GTK_ENTRY (entry)->text_length);
    gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, TRUE, 0);
    gtk_widget_show (entry);

   //entry2 ..	
    entry2 = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry2), 100);
    g_signal_connect (entry2, "activate",G_CALLBACK (enter_callback), entry2);
    gtk_entry_set_text (GTK_ENTRY (entry2), "Put your Port number");

    tmp_pos = GTK_ENTRY (entry2)->text_length;
    gtk_editable_select_region (GTK_EDITABLE (entry2),0, 
				GTK_ENTRY (entry2)->text_length);
    gtk_box_pack_start (GTK_BOX (vbox), entry2, TRUE, TRUE, 0);
    gtk_widget_show (entry2);

    // timeLabel
    timeLabel = gtk_label_new("IP address : ");
    gtk_widget_set_size_request(timeLabel, 50, 50);
    gtk_container_add(GTK_CONTAINER(vbox), timeLabel);
    
    //button ...
    button = gtk_button_new_with_label("Connect");
    gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC (button_callback), NULL);

    //gtk_signal_connect_object (GTK_OBJECT (button), "clicked", 
	//	GTK_SIGNAL_FUNC (gtk_widget_destory), 
	//	GTK_OBJECT (window));
    
    gtk_container_add (GTK_CONTAINER (window), button);
    //gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    gtk_widget_show(button);


    gtk_widget_show (window);

    gtk_main();

    return 0;
}
