#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

/**
This is just for prototyping, but when the app
is released, only include necessary headers for
decreased build time
**/

#include <gtkmm-3.0/gtkmm.h>
/*
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/radiobutton.h>
#include <gtkmm-3.0/gtkmm/separator.h>
*/
#include <iostream>

/**
I follow a certain naming convention when creating
container widgets to contruct this GUI. Then naming
convention is outline below:

gtkType_level_parentInstanceNumber_instanceNumber

I will define these below:
 - gtkType: A child of the Gtk::Window class (i.e. Box, Frame etc.)
 - level: the heirarchal level corresponding to parents and
 children (i.e. 0 is the highest level, then 1, 2 etc.)
 - parentInstanceNumber: Since there can be multiple containers of
 the same type (such as 3 frames in a parent Box for example), I wanted
 to label these to keep track
 - instanceNumber: The instance of the child within the parent. I wanted
 to keep track of child containers of the same type within one
 parent (i.e. the third Box within a Grid parent)
 **/


//Class to create window
class Window: public Gtk::Window
{
public:
    Window(); //Constructor
    virtual ~Window(); //Destructor

protected:
    //Parent box member (Level 0)
    Gtk::Box p_box;

    //Level 1 Children Frames
    Gtk::Frame f_1_1;
    Gtk::Frame f_1_2;
    Gtk::Frame f_1_3;

    //Level 1 Child Grid and label
    Gtk::Label lab_1_1;
    Gtk::Grid g_1_1;

    //Level 2 Boxes
    Gtk::Box b_2_1_1;
    Gtk::Box b_2_2_1;
    Gtk:Box b_2_3_1;

    //Level 3 Frames (to be placed inside g_1_1)
    Gtk::Frame f_3_1_1;
    Gtk::Frame f_3_1_2;
    Gtk::Frame f_3_1_3;

    //Level 4 boxes (to be placed in level 3 frames)
    Gtk::Box b_4_1_1;
    Gtk::Box b_4_2_1;
    Gtk::Box b_4_3_1;

    //Old code:
    /*
    //Structural elements
    Gtk::Box p_box; //parent box for all
    Gtk::Grid p_grid;
    Gtk::Grid box_text_grid; //grid to organize label and textField
    Gtk::Box box_tl; //top left
    Gtk::Box box_tr; //top right
    Gtk::Box box_bl; //bottom row
    Gtk::Box box_text; //to hold textView
    Gtk::Box box_rgrid_top; //box to hold frame label
    Gtk::Box box_rgrid_bot; //box to hold text field
    Gtk::Frame m_frame; //to hold TextView label
    Gtk::Label m_label;

    //To hold text editor portion
    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TextView m_TextView;
    Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1, m_refTextBuffer2;


    Gtk::Button button1;
    Gtk::Button button2;
    Gtk::Button q_button;

    //Signal Handlers
    void on_button_clicked_erase_field();
    void on_button_clicked2();
    void on_button_clicked_quit();

    //Text editor member functions
    void on_button_fill_field();
    void init_architect();
    void left_grid_setup();
    void right_grid_setup();
    void label_frame_setup();
    void button_setup();
    */
};
#endif // GTKMM_EXAMPLE_HELLOWORLD_H
