#include "header.h"

//Define window constructor
Window::Window():button1("Erase Field"),
                 button2("Fill Text Field"),
                 q_button("Quit"),
                 m_label("Enter Text below:\t\t\t\t")
{
    init_architect();
    left_grid_setup();
    label_frame_setup();

    //Define signal response for buttons
    button1.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked_erase_field));
    button2.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_fill_field));
    q_button.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked_quit));

    //Setup size requests for buttons
    button1.set_size_request(20,10);
    button2.set_size_request(20,10);
    q_button.set_size_request(20,10);


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

    //Add buttons to boxes
    box_tl.pack_start(button1);
    box_tr.pack_start(button2);
    box_bl.pack_start(q_button);

    show_all_children();

}


//Destructor
Window::~Window()
{
}

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
    Window::p_grid.set_valign(Gtk::ALIGN_CENTER);
    Window::p_grid.set_halign(Gtk::ALIGN_CENTER);



    //Add boxes to left parent grid
    Window::p_grid.add(box_tr);
    Window::p_grid.attach_next_to(box_tl,box_tr,Gtk::POS_BOTTOM,1,1);
    Window::p_grid.attach_next_to(box_bl,box_tl,Gtk::POS_BOTTOM,1,1);


    //Set left grid spacing parameters
    Window::p_grid.set_row_spacing(20);
    Window::p_grid.set_row_baseline_position(1,Gtk::BASELINE_POSITION_CENTER);
}

void Window::label_frame_setup()
{
    //Add label to frame holder
    m_frame.add(m_label);
    m_frame.set_size_request(100,10);
}


void Window::on_button_clicked_erase_field()
{
    m_refTextBuffer2 = Gtk::TextBuffer::create();
    m_refTextBuffer2->set_text("");
    m_TextView.set_buffer(m_refTextBuffer2);

}

void Window::on_button_clicked_quit()
{
    //std::cout << "The Program will now quit" << std::endl;
    hide();
}

void Window::on_button_fill_field()
{
    m_refTextBuffer1 = Gtk::TextBuffer::create();
    m_refTextBuffer1->set_text("Name:\nDOB:");
    m_TextView.set_buffer(m_refTextBuffer1);
}


