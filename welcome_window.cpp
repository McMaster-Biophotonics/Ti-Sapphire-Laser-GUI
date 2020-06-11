#include "header.h"

//Define window constructor
Window::Window() //initializers for buttons, etc will go here
{
    build_architechture();

    show_all_children();
    //define architechture function to build background setup
}

//Destructor:
Window::~Window()
{
}

//Function to build the window
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
    f_1_1.set_label("Frame 1_1");
    f_1_2.set_label("Frame 1_2");

    //Add level 1 box (holding quit button) and frame
    p_grid.attach(f_1_3,1,1,1,2);
    p_grid.attach(b_1_1,1,0,1,1);
    f_1_3.set_label("Frame f_1_3");
    b_1_1.add(but_2_1_1);
    but_2_1_1.set_label("QUIT");



    //Add level 2 frames to bottom grid
    g_1_1.add(f_2_1_1);
    g_1_1.attach_next_to(f_2_1_2,f_2_1_1,Gtk::POS_RIGHT);
    g_1_1.attach_next_to(f_2_1_3,f_2_1_2,Gtk::POS_RIGHT);

    //Label level 2 frames
    f_2_1_1.set_label("Frame 2_1_1");
    f_2_1_2.set_label("Frame 2_1_2");
    f_2_1_3.set_label("Frame 2_1_3");

    //Set expansion behaviours for level 1 and 2 frames
    f_1_3.set_hexpand(true);
    f_1_1.set_hexpand(true);
    f_1_2.set_hexpand(true);
    f_2_1_1.set_hexpand(true);
    f_2_1_2.set_hexpand(true);
    f_2_1_3.set_hexpand(true);

    //Call button response fxn to setup signal connects
    button_response();
}

//Function to define button signal reponses
void Window::button_response()
{
    but_2_1_1.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_qbutton_clicked));

}

/**
This set of functions define individual button clicks and their actions
**/

//This function contains the response for the quit button
void Window::on_qbutton_clicked()
{
    hide();
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


