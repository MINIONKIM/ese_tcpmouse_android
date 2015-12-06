#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

const gchar *state_text;
const gchar *data_text;

/* this will store push buttons */
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *button3;

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

static void enter1_callback (GtkWidget *widget, GtkWidget *entry)
{
	state_text = gtk_entry_get_text (GTK_ENTRY(entry));
	printf("Entry contents : %s\n", state_text);
	
	return;
}

static void enter2_callback (GtkWidget *widget, GtkWidget *entry)
{
	data_text = gtk_entry_get_text (GTK_ENTRY(entry));
	printf("Entry contents : %s\n", data_text);

	return;
}

static void on_button1_clicked(GtkButton* button, gpointer data)
{
    /* cast the data back to a char*  */
    char* txt = (char*)data;

    /*button activate*/
    gtk_widget_set_sensitive(button1, FALSE);
    gtk_widget_set_sensitive(button2, TRUE);

    printf("open_button_clicked - '%s'\n", txt);
    fflush(stdout);
}

static void on_button2_clicked(GtkButton* button, gpointer data)
{
    /* cast the data back to a char*  */
    char* txt = (char*)data;

    /*button activate*/	
    gtk_widget_set_sensitive(button1, TRUE);
    gtk_widget_set_sensitive(button2, FALSE);

    printf("close_button_clicked - '%s'\n", txt);
    fflush(stdout);
}

/* "quit" button "clicked" callback function. */
static void on_quit_clicked(GtkButton* button, gpointer data)
{
    /* make sure we realy quit. */
    gtk_main_quit();
}

int main (int argc, char *argv[])
{
    /* this variable will store a pointer to the window object. */
    GtkWidget *window;
    GtkWidget *vbox;
    /* this will store a text entry */
    GtkWidget *entry;
    GtkWidget *entry2;   
  
    /* this will store a horizontal box*/
    GtkWidget *hbox;

    GtkWidget *label;
    GtkWidget *frame;
	
    GtkWidget *timeLabel;
    gint tmp_pos;

// ----------------------------------------------------------------------------

    /* this is called in all GTK applications. Arguments 
	are parsed from the command line and are returned
 	to the application. */
    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "PC GTK Entry");
    gtk_widget_set_size_request(GTK_WIDGET (window), 200, 350);
    gtk_container_set_border_width(GTK_CONTAINER (window), 5);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    /* When the window is given the "delete_event" signal (usually by
	the "close" opthion), we ask it to call the delete_event() function. 
	*/
    g_signal_connect_swapped (window, "delete-event",
				G_CALLBACK (gtk_widget_destroy), window);
    /* Here we connect the "destory" event to a signal handler.
 	This event occurs when we call gtk_widget_destroy() on the window, 
	or if we return FALSE in the "delete_event" callback. */
    g_signal_connect (window, "destroy",G_CALLBACK (gtk_main_quit), NULL);

// ----------------------------------------------------------------------------
    //vbox
    vbox = gtk_vbox_new (FALSE, 5);
  
   // hbox
    hbox = gtk_hbox_new (FALSE, 5);
  
    gtk_container_add (GTK_CONTAINER (window), hbox);
    gtk_box_pack_start (GTK_BOX (hbox), vbox, FALSE, FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (window), 5);

   // frame
    frame = gtk_frame_new("NULL");
    gtk_frame_set_label (GTK_FRAME(frame), "STATE");
    gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_ETCHED_OUT);


 
    //entry ..	
    entry = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry), 100);
    gtk_widget_set_size_request(entry, 170, 50);
    g_signal_connect (entry, "activate",G_CALLBACK (enter1_callback), entry);
    gtk_entry_set_text (GTK_ENTRY (entry), "Disconnect");

    tmp_pos = GTK_ENTRY (entry)->text_length;
    gtk_editable_select_region (GTK_EDITABLE (entry),0, 
				GTK_ENTRY (entry)->text_length);
    gtk_container_add (GTK_CONTAINER (frame), entry);
    gtk_box_pack_start (GTK_BOX (vbox), frame, FALSE, FALSE, 0);

    gtk_widget_show (entry);


      // frame
    frame = gtk_frame_new("NULL");
    gtk_frame_set_label (GTK_FRAME(frame), "DATA");
    gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.0);
    gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_ETCHED_OUT);


    //entry2 ..	
    entry2 = gtk_entry_new ();
    gtk_entry_set_max_length (GTK_ENTRY (entry2), 100);
     gtk_widget_set_size_request(entry2, 170, 50);
    g_signal_connect (entry2, "activate",G_CALLBACK (enter2_callback), entry2);
    gtk_entry_set_text (GTK_ENTRY (entry2), "What data");

    tmp_pos = GTK_ENTRY (entry2)->text_length;
    gtk_editable_select_region (GTK_EDITABLE (entry2),0, 
				GTK_ENTRY (entry2)->text_length);
    gtk_container_add (GTK_CONTAINER (frame), entry2);
    gtk_box_pack_start (GTK_BOX (vbox), frame, FALSE, FALSE, 0);
    gtk_widget_show (entry2);

   
    //button ...
    button1 = gtk_button_new_with_label("Open");
   

    //gtk_signal_connect_object (GTK_OBJECT (button), "clicked", 
	//	GTK_SIGNAL_FUNC (gtk_widget_destory), 
	//	GTK_OBJECT (window));
    
    //gtk_container_add (GTK_CONTAINER (window), button1);
    gtk_widget_set_size_request(button1, 50, 50);
    gtk_box_pack_start (GTK_BOX (vbox), button1, FALSE, TRUE, 1);
    

    gtk_signal_connect (GTK_OBJECT (button1), "clicked", 
		GTK_SIGNAL_FUNC (on_button1_clicked), NULL);

    gtk_widget_show(button1);


   // button2
   button2 = gtk_button_new_with_label("Close");
   gtk_widget_set_size_request(button2, 50, 50);  
   gtk_box_pack_start (GTK_BOX (vbox), button2, FALSE, TRUE, 1);
   gtk_signal_connect (GTK_OBJECT (button2), "clicked", 
			GTK_SIGNAL_FUNC (on_button2_clicked), NULL);

	// test
   gtk_widget_set_sensitive(button2, FALSE);

    gtk_widget_show(button2);

   // button3
   button3 = gtk_button_new_with_label("Quit");  
   gtk_widget_set_size_request(button3, 50, 50);
   gtk_box_pack_start (GTK_BOX (vbox), button3, FALSE, TRUE, 1);
   gtk_signal_connect (GTK_OBJECT (button3), "clicked", 
			GTK_SIGNAL_FUNC (on_quit_clicked), NULL);

    gtk_widget_show(button3);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
