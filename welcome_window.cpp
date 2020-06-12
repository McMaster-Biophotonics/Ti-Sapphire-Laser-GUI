#include "header.h"

///Define window constructor
Window::Window()
 //initializers for buttons, etc will go here
{
    build_architechture();

    show_all_children();
    //define architechture function to build background setup
}

///Destructor:
Window::~Window()
{
}

///Function to build the window
void Window::build_architechture()
{
    //Add parent grid to window and format grid
    add(p_grid);
    p_grid.insert_row(0);
    p_grid.insert_row(1);
    p_grid.insert_row(2);
    p_grid.insert_row(3);
    p_grid.insert_column(0);
    p_grid.insert_column(1);
    p_grid.attach(f_1_1,0,0);
    p_grid.attach(f_1_2,0,1);
    p_grid.attach(g_1_1,0,3,3,1);
    f_1_1.set_label("Stage Position");
    f_1_2.set_label("Laser Control");

    //Add level 1 box (holding quit button) and frame
    p_grid.attach(f_1_3,1,1,1,2);
    p_grid.attach(b_1_1,1,0,1,1);
    b_1_1.pack_end(but_2_1_1,false,false,10);
    f_1_3.set_label("Predefined Functions");
    but_2_1_1.set_label("QUIT");

    //Add level 2 frames to bottom grid
    g_1_1.add(f_2_1_1);
    g_1_1.attach_next_to(f_2_1_2,f_2_1_1,Gtk::POS_RIGHT);
    g_1_1.attach_next_to(f_2_1_3,f_2_1_2,Gtk::POS_RIGHT);

    //Label level 2 frames
    f_2_1_1.set_label("X Axis");
    f_2_1_2.set_label("Y Axis");
    f_2_1_3.set_label("Z Axis");

    //Set expansion behaviours for level 1 and 2 frames
    f_1_3.set_hexpand(true);
    f_1_1.set_hexpand(true);
    f_1_2.set_hexpand(true);
    f_2_1_1.set_hexpand(true);
    f_2_1_2.set_hexpand(true);
    f_2_1_3.set_hexpand(true);

    //Add level 2 and level 3 boxes to frame parents
    f_1_1.add(b_2_1_1);
    f_1_2.add(b_2_2_1);
    f_2_1_1.add(b_3_1_1);
    f_2_1_2.add(b_3_2_1);
    f_2_1_3.add(b_3_3_1);

    //Call individual box setup functions
    stage_position_setup();
    laser_control_setup();

    //Call button response fxn to setup signal connects
    button_response();
}

/// Function to setup the 'Stage Position' Box
void Window::stage_position_setup()
{
    //Add grid to box container parent
    b_2_1_1.add(p_grid_3);

    //Populate with rows and columns (5x5 grid)
    for (int j=0;j<5;j++)
    {
        p_grid_3.insert_row(j);
        p_grid_3.insert_column(j);
    }
    //Style options:
    //Create colour and font object for text
    Gdk::RGBA colour = Gdk::RGBA(Glib::ustring("rgb(19,206,13)"));
    Pango::FontDescription f = Pango::FontDescription(Glib::ustring("Sans Bold 13"));

    //Remember, position syntax for 'attach' is: (column,row)
    ///Row 0:
    p_grid_3.attach(lab_4_1_1,0,0);
    p_grid_3.attach(ent_4_1_1,1,0);
    p_grid_3.attach(ent_4_1_2,2,0);
    p_grid_3.attach(ent_4_1_3,3,0);
    p_grid_3.attach(but_4_1_1,4,0);

    //Labels and default text
    lab_4_1_1.set_label("Absolute Position");
    but_4_1_1.add_label("Set Origin");
    static Glib::ustring ent_4_1_1_text = "0";
    Glib::ustring ent_4_1_2_text = "0";
    Glib::ustring ent_4_1_3_text = "0";

    //style options
    ent_4_1_1.override_font(f);
    ent_4_1_2.override_font(f);
    ent_4_1_3.override_font(f);

    ent_4_1_1.get_buffer()->set_text(ent_4_1_1_text);
    ent_4_1_2.get_buffer()->set_text(ent_4_1_2_text);
    ent_4_1_3.get_buffer()->set_text(ent_4_1_3_text);

    ///Row 1:
    p_grid_3.attach(lab_4_1_2,0,1);
    p_grid_3.attach(ent_4_1_4,1,1);
    p_grid_3.attach(ent_4_1_5,2,1);
    p_grid_3.attach(ent_4_1_6,3,1);

    //Labels and default text
    lab_4_1_2.set_label("Relative Position");
    Glib::ustring ent_4_1_4_text = "0";
    Glib::ustring ent_4_1_5_text = "0";
    Glib::ustring ent_4_1_6_text = "0";

    //style options
    ent_4_1_4.override_color(colour,Gtk::STATE_FLAG_NORMAL);
    ent_4_1_5.override_color(colour,Gtk::STATE_FLAG_NORMAL);
    ent_4_1_6.override_color(colour,Gtk::STATE_FLAG_NORMAL);
    ent_4_1_4.override_font(f);
    ent_4_1_5.override_font(f);
    ent_4_1_6.override_font(f);
    ent_4_1_4.get_buffer()->set_text(ent_4_1_4_text);
    ent_4_1_5.get_buffer()->set_text(ent_4_1_5_text);
    ent_4_1_6.get_buffer()->set_text(ent_4_1_6_text);

    ///Row 2
    p_grid_3.attach(but_4_1_2,0,2);
    p_grid_3.attach(ent_4_1_7,1,2);
    p_grid_3.attach(ent_4_1_8,2,2);
    p_grid_3.attach(ent_4_1_9,3,2);

    //Labels and default text
    //initialize as ustring bc of ability to change
    Glib::ustring ent_4_1_7_text = "0";
    Glib::ustring ent_4_1_8_text = "0";
    Glib::ustring ent_4_1_9_text = "0";
    ent_4_1_7.override_font(f);
    ent_4_1_8.override_font(f);
    ent_4_1_9.override_font(f);
    ent_4_1_7.get_buffer()->set_text(ent_4_1_7_text);
    ent_4_1_8.get_buffer()->set_text(ent_4_1_8_text);
    ent_4_1_9.get_buffer()->set_text(ent_4_1_9_text);
    but_4_1_2.set_label("Go to Position");

    ///Row 3
    p_grid_3.attach(lab_4_1_3,0,3);
    p_grid_3.attach(b_4_1_1,1,3);
    p_grid_3.attach(b_4_1_2,2,3);
    p_grid_3.attach(b_4_1_3,4,3,1,2);
    b_4_1_1.pack_start(but_5_1_1,Gtk::PACK_EXPAND_WIDGET);
    b_4_1_1.pack_end(but_5_1_2,Gtk::PACK_EXPAND_WIDGET);
    b_4_1_2.pack_start(but_5_2_1,Gtk::PACK_EXPAND_WIDGET);
    b_4_1_2.pack_start(but_5_2_2,Gtk::PACK_EXPAND_WIDGET);
    b_4_1_3.pack_start(but_5_3_1,Gtk::PACK_EXPAND_WIDGET);

    //Labels & Styling
    lab_4_1_3.set_label("Save Position");
    but_5_1_1.set_label("M1+");
    but_5_1_2.set_label("M2+");
    but_5_2_1.set_label("M3+");
    but_5_2_2.set_label("M4+");
    but_5_3_1.set_label("Joystick Off");

    ///Row 4
    p_grid_3.attach(lab_4_1_4,0,4);
    p_grid_3.attach(b_4_1_4,1,4);
    p_grid_3.attach(b_4_1_5,2,4);
    p_grid_3.attach(but_4_1_3,3,4);
    b_4_1_4.pack_start(but_5_4_1,Gtk::PACK_EXPAND_WIDGET);
    b_4_1_4.pack_end(but_5_4_2,Gtk::PACK_EXPAND_WIDGET);
    b_4_1_5.pack_start(but_5_5_1,Gtk::PACK_EXPAND_WIDGET);
    b_4_1_5.pack_end(but_5_5_2,Gtk::PACK_EXPAND_WIDGET);

    //Labels & Styling
    lab_4_1_4.set_label("Recall Location");
    but_4_1_3.set_label("Relative Origin");
    but_5_4_1.set_label("M1 R");
    but_5_4_2.set_label("M2 R");
    but_5_5_1.set_label("M3 R");
    but_5_5_2.set_label("M4 R");

}

///Function to setup 'Laser Control' box
void Window::laser_control_setup()
{
    b_2_2_1.add(p_grid_3_2);
    //Populate parent grid (8 rows by 5 columns)
    for(int j=0;j<8;j++)
    {
        if(j<5)
        {
            p_grid_3_2.insert_row(j);
            p_grid_3_2.insert_column(j);
        }
        else
        {
            p_grid_3_2.insert_row(j);
        }
    }
    ///Spin button settings (to be customized as necessary)
    int default_min = 1;
    int default_max = 100;
    int default_val = 1;
    int default_increment = 1;
    int default_pg_increment = 10;
    ///End of spin button settings

    ///Row 0
    //Remember, syntax for attaching widgets to grid is (column,row)
    p_grid_3_2.attach(lab_4_2_1,3,0);
    p_grid_3_2.attach(lab_4_2_2,4,0);
    p_grid_3_2.attach(lab_4_pad_1,2,0); //padding label

    //Labels & Styling
    lab_4_pad_1.set_hexpand(true);
    lab_4_2_1.set_label("Energy [nJ]");
    lab_4_2_2.set_label("Fluence [mJ/cm2]");


    ///Row 1
    p_grid_3_2.attach(but_4_2_1,0,1);
    p_grid_3_2.attach(ent_4_2_1,3,1);
    p_grid_3_2.attach(ent_4_2_2,4,1);

    //Labels & Styling
    but_4_2_1.set_label("Trigger Off");

    ///Row 2
    p_grid_3_2.attach(spb_4_2_1,0,2);
    p_grid_3_2.attach(lab_4_2_3,3,2);
    p_grid_3_2.attach(spb_4_2_2,4,2);

    //Labels & Styling
    //UNC for 'mu' is :U+03BC (written as \u03BC in C++)
    lab_4_2_3.set_label("Spot Size [\u03BCm]");
    //spb_4_2_1
    spb_4_2_1.set_range(default_min,default_max);
    spb_4_2_1.set_value(default_val);
    spb_4_2_1.set_increments(default_increment,default_pg_increment);
    spb_4_2_1.set_wrap(true);
    //spb_4_2_2
    spb_4_2_2.set_range(default_min,default_max);
    spb_4_2_2.set_value(default_val);
    spb_4_2_2.set_increments(default_increment,default_pg_increment);
    spb_4_2_2.set_wrap(true);


    ///Row 3
    p_grid_3_2.attach(but_4_2_2,0,3);
    p_grid_3_2.attach(lab_4_2_4,3,3);
    p_grid_3_2.attach(spb_4_2_3,4,3);

    //Labels & Styling
    but_4_2_2.set_label("Snap");
    lab_4_2_4.set_label("Po [mW]");
    //spb_4_2_3
    spb_4_2_3.set_range(default_min,default_max);
    spb_4_2_3.set_value(default_val);
    spb_4_2_3.set_increments(default_increment,default_pg_increment);
    spb_4_2_3.set_wrap(true);

    ///Row 4
    p_grid_3_2.attach(but_4_2_3,0,4);
    p_grid_3_2.attach(lab_4_2_5,3,4);
    p_grid_3_2.attach(spb_4_2_4,4,4);

    //Labels & Styling
    but_4_2_3.set_label("Laser On");
    lab_4_2_5.set_label("Signal [V]");
    //spb_4_2_4
    spb_4_2_4.set_range(default_min,default_max);
    spb_4_2_4.set_value(default_val);
    spb_4_2_4.set_increments(default_increment,default_pg_increment);
    spb_4_2_4.set_wrap(true);

    ///Row 5
    p_grid_3_2.attach(but_4_2_4,0,5);
    p_grid_3_2.attach(lab_4_2_6,3,5);
    p_grid_3_2.attach(spb_4_2_5,4,5);

    //Labels & Styling
    but_4_2_4.set_label("Laser Off");
    lab_4_2_6.set_label("Current Signal [V]");
    //spb_4_2_5
    spb_4_2_5.set_range(default_min,default_max);
    spb_4_2_5.set_value(default_val);
    spb_4_2_5.set_increments(default_increment,default_pg_increment);
    spb_4_2_5.set_wrap(true);

    ///Row 6
    p_grid_3_2.attach(but_4_2_5,0,6);
    p_grid_3_2.attach(but_4_2_7,3,6,2,1);

    //Labels & Styling
    but_4_2_5.set_label("Slow Rep Rate");
    but_4_2_7.set_label("Use OD Calibration");

    ///Row 7
    p_grid_3_2.attach(lab_4_2_7,0,7);
    p_grid_3_2.attach(spb_4_2_6,1,7);

    //Labels & Styling
    lab_4_2_7.set_label("Pulse-pulse delay [ms]");
    //spb_4_2_6
    spb_4_2_6.set_range(default_min,default_max);
    spb_4_2_6.set_value(default_val);
    spb_4_2_6.set_increments(default_increment,default_pg_increment);
    spb_4_2_6.set_wrap(true);




}

///Function to define button signal reponses
void Window::button_response()
{
    but_2_1_1.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_qbutton_clicked));
    but_4_1_1.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_setOrigion_button_clicked));
    but_4_1_2.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_goTo_button_clicked));

}

/**
This set of functions define individual button clicks and their actions
**/

///This function contains the response for the quit button
void Window::on_qbutton_clicked()
{
    hide();
}

///This function contains the response for the 'Set origin' button
void Window::on_setOrigion_button_clicked()
{
    //Will actually need to send command later, just changes text entry for now
    ent_4_1_1.get_buffer()->set_text("0");
    ent_4_1_2.get_buffer()->set_text("0");
    ent_4_1_3.get_buffer()->set_text("0");
    ent_4_1_4.get_buffer()->set_text("0");
    ent_4_1_5.get_buffer()->set_text("0");
    ent_4_1_6.get_buffer()->set_text("0");
}

/**
This function will set the text values of the first row
of text entries to the third row to demonstrate the use
of the 'Go to Position' button
**/

void Window::on_goTo_button_clicked()
{
    std::cout << "Go to button clicked" << std::endl;
}


//Old code:
/*
//Define window constructor
Window::Window():button1("Erase Field"),
                 button2("Fill Text Field"),
                 q_button("Quit"),
                 m_label("Enter Text below:\t\t\t\t")
{
    init_architect();
    left_grid_setup();
    right_grid_setup();
    label_frame_setup();
    button_setup();

    show_all_children();
}


//Destructor
Window::~Window()
{
    //Nothing to define here
}
*/
/**
These are the setup functions, used for things like connecting button
signals to slot functions, and setting up general architechture. I chose
to construct the window this way because it is reproducible for other
windows and more user-friendly for people who want to adapt this code
later.
**/

//Old code:
/*
//This function will setup the container widgets necessary for construction of GUI
void Window::init_architect()
{
    //Set title of grid
    set_title("Gtkmm Application");

    //Add parent box widget
    add(p_box);

    //Set default size of app & border width
    set_default_size(500, 200);
    set_border_width(5);

    //Add left grid and text field container box to parent box
    p_box.pack_start(p_grid);
    p_box.pack_start(box_text);
}

void Window::left_grid_setup()
{
    //Set left grid behaviour
    p_grid.set_valign(Gtk::ALIGN_CENTER);
    p_grid.set_halign(Gtk::ALIGN_CENTER);



    //Add boxes to left parent grid
    p_grid.add(box_tr);
    p_grid.attach_next_to(box_tl,box_tr,Gtk::POS_BOTTOM,1,1);
    p_grid.attach_next_to(box_bl,box_tl,Gtk::POS_BOTTOM,1,1);


    //Set left grid spacing parameters
    p_grid.set_row_spacing(20);
    p_grid.set_row_baseline_position(1,Gtk::BASELINE_POSITION_CENTER);

    //Add buttons to boxes
    box_tl.pack_start(button1);
    box_tr.pack_start(button2);
    box_bl.pack_start(q_button);
}

void Window::right_grid_setup()
{
    //Add text field structural layout

    //Add treeview inside scrolled window
    m_ScrolledWindow.add(m_TextView);
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    m_ScrolledWindow.set_size_request(50,150);

    //Add right grid and layout textfield and label & define grid behaviour
    box_text.add(box_text_grid);
    box_text_grid.add(m_ScrolledWindow);
    box_text_grid.attach_next_to(m_frame,m_ScrolledWindow,Gtk::POS_TOP);
    box_text_grid.set_valign(Gtk::ALIGN_CENTER);
    box_text_grid.set_halign(Gtk::ALIGN_CENTER);
    box_text_grid.set_hexpand(true);
}

void Window::label_frame_setup()
{
    //Add label to frame holder
    m_frame.add(m_label);
    m_frame.set_size_request(100,10);
}

void Window::button_setup()
{
    //Define signal response for buttons
    button1.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked_erase_field));
    button2.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_fill_field));
    q_button.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked_quit));

    //Setup size requests for buttons
    button1.set_size_request(20,10);
    button2.set_size_request(20,10);
    q_button.set_size_request(20,10);

}

*/
/**
These are slot functions that are linked to button signals.
That basically just means that when a button is 'clicked' for
example, the specified function will be called.
**/

//Old code:
/*
//This function clears the text field, even after entering text
void Window::on_button_clicked_erase_field()
{
    m_refTextBuffer2 = Gtk::TextBuffer::create();
    m_refTextBuffer2->set_text("");
    m_TextView.set_buffer(m_refTextBuffer2);

}

//This function closes the window - same as pressing the 'X' button
void Window::on_button_clicked_quit()
{
    hide();
}

//This function fills the field with a template for information (for testing)
void Window::on_button_fill_field()
{
    m_refTextBuffer1 = Gtk::TextBuffer::create();
    m_refTextBuffer1->set_text("Name:\nDOB:");
    m_TextView.set_buffer(m_refTextBuffer1);
}
*/


