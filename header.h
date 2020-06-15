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
    ///build_architechture members
    //Parent box member (Level 0)
    Gtk::Grid p_grid;

    //Level 1 Child Grids and box holding quit command
    Gtk::Box b_1_1;
    Gtk::Grid g_1_1,g_1_2;

    //Level 1 Children Frames (to be placed inside parent grid)
    Gtk::Frame f_1_1,f_1_2,f_1_3;

    //Level 2 Boxes
    Gtk::Box b_2_1_1,b_2_2_1;

    //Level 2 Frames (to be placed inside g_1_1 child grid)
    Gtk::Frame f_2_1_1,f_2_1_2,f_2_1_3;

    //Level 2 button holding quit command
    Gtk::Button but_2_1_1;

    //Level 3 boxes (to be placed in level 2 frames)
    Gtk::Box b_3_1_1,b_3_2_1,b_3_3_1;

    ///stage_position_setup members
    //Level 3 grid (for 'Stage Position' Container)
    Gtk::Grid p_grid_3;

    //Row 0
    Gtk::Label lab_4_1_1,lab_4_pad_1;
    Gtk::Entry ent_4_1_1,ent_4_1_2,ent_4_1_3;
    Gtk::Button but_4_1_1;

    //Row 1
    Gtk::Label lab_4_1_2;
    Gtk::Entry ent_4_1_4,ent_4_1_5,ent_4_1_6;

    //Row 2
    Gtk::Button but_4_1_2;
    Gtk::Entry ent_4_1_7,ent_4_1_8,ent_4_1_9;

    //Row 3
    Gtk::Label lab_4_1_3;
    Gtk::Box b_4_1_1,b_4_1_2,b_4_1_3;
    Gtk::Button but_5_1_1,but_5_1_2,but_5_2_1,but_5_2_2,but_5_3_1;

    //Row 4
    Gtk::Label lab_4_1_4;
    Gtk::Box b_4_1_4,b_4_1_5;
    Gtk::Button but_5_4_1,but_5_4_2,but_5_5_1,but_5_5_2,but_4_1_3;

    ///laser_control setup members
    Gtk::Grid p_grid_3_2;
    Gtk::Label lab_4_2_1,lab_4_2_2,lab_4_2_3,lab_4_2_4,lab_4_2_5,lab_4_2_6,lab_4_2_7;
    Gtk::Entry ent_4_2_1,ent_4_2_2;
    Gtk::Button but_4_2_1,but_4_2_2,but_4_2_3,but_4_2_4,but_4_2_5,but_4_2_6,but_4_2_7;
    Gtk::SpinButton spb_4_2_1,spb_4_2_2,spb_4_2_3,spb_4_2_4,spb_4_2_5,spb_4_2_6;

    ///x_axis_setup members
    Gtk::Grid p_grid_4_1;
    Gtk::Label lab_5_6_1,lab_5_6_2,lab_5_6_3,lab_5_6_4,lab_5_6_5,lab_5_6_6;
    Gtk::Label lab_5_pad_1,lab_5_pad_2;
    Gtk::SpinButton spb_5_6_1,spb_5_6_2;
    Gtk::Button but_5_6_1,but_5_6_2,but_5_6_3,but_5_6_4,but_5_6_5,but_5_6_6;

    ///y_axis_setup members
    Gtk::Grid p_grid_4_2;
    Gtk::Label lab_5_7_1,lab_5_7_2,lab_5_7_3,lab_5_7_4,lab_5_7_5,lab_5_7_6;
    Gtk::Label lab_5_pad_3,lab_5_pad_4;
    Gtk::SpinButton spb_5_7_1,spb_5_7_2;
    Gtk::Button but_5_7_1,but_5_7_2,but_5_7_3,but_5_7_4,but_5_7_5,but_5_7_6;

    ///z_axis_setup members
    Gtk::Grid p_grid_4_3;
    Gtk::Label lab_5_8_1,lab_5_8_2,lab_5_8_3,lab_5_8_4,lab_5_8_5,lab_5_8_6;
    Gtk::Label lab_5_pad_5,lab_5_pad_6,lab_5_pad_7;
    Gtk::Button but_5_8_1,but_5_8_2,but_5_8_3,but_5_8_4,but_5_8_5;
    Gtk::SpinButton spb_5_8_1,spb_5_8_2;



    ///Member functions
    void build_architechture();
    void stage_position_setup();
    void laser_control_setup();
    void x_axis_setup();
    void y_axis_setup();
    void z_axis_setup();
    void button_response();
    void on_qbutton_clicked();
    void on_setOrigion_button_clicked();
    void on_goTo_button_clicked();

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
