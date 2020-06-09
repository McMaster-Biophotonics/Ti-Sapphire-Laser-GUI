#include "header.h"

//Define window constructor
Window::Window():button1("Erase Field"),
                 button2("Fill Text Field"),
                 q_button("Quit"),
                 m_label("Enter Text below:\t\t\t\t")
{
    //Set title of grid
    set_title("Gtkmm Application");
    add(p_box);

    //Set border width
    set_default_size(500, 200);
    set_border_width(5);

    //Add parent grid to parent box
    p_box.pack_start(p_grid);
    p_box.pack_start(box_text);
   // p_box.pack_start(m_frame,Gtk::PACK_EXPAND_WIDGET);

    //Add label to frame holder
    m_frame.add(m_label);
    m_frame.set_size_request(100,10);


    //Define signal response for buttons
    button1.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked_erase_field));
    button2.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_fill_field));
    q_button.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked_quit));

    //Set button sizes and how they respond inside the left grid
    p_grid.set_valign(Gtk::ALIGN_CENTER);
    p_grid.set_halign(Gtk::ALIGN_CENTER);
    button1.set_size_request(20,10);
    button2.set_size_request(20,10);
    q_button.set_size_request(20,10);


    //Add boxes to left parent grid
    p_grid.add(box_tr);
    p_grid.attach_next_to(box_tl,box_tr,Gtk::POS_BOTTOM,1,1);
    p_grid.attach_next_to(box_bl,box_tl,Gtk::POS_BOTTOM,1,1);


    //Set left grid spacing parameters
    p_grid.set_row_spacing(20);
    p_grid.set_row_baseline_position(1,Gtk::BASELINE_POSITION_CENTER);



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

void Window::on_button_clicked_erase_field()
{
    m_refTextBuffer2 = Gtk::TextBuffer::create();
    m_refTextBuffer2->set_text("");
    m_TextView.set_buffer(m_refTextBuffer2);

}

void Window::on_button_clicked2()
{
    std::cout << "Clicked 2!" << std::endl;
}

void Window::on_button_clicked_quit()
{
    std::cout << "The Program will now quit" << std::endl;
    hide();
}

void Window::fill_buffer()
{
    m_refTextBuffer1 = Gtk::TextBuffer::create();
    m_refTextBuffer1->set_text("Name:\nDOB:");
}

void Window::on_button_fill_field()
{
    fill_buffer();
    m_TextView.set_buffer(m_refTextBuffer1);
}


/*//Define Window member fxns
void Window::create_button(void)
{
    Buttons f_button; //create object
}*/

/*
//Define constructor with button
Buttons::Buttons():m_button("Click to Enter")
{
    //Set border width of window
    set_border_width(10);

    //Instruct button object to call the on_button_clicked
    //fxn below when it receives the clicked signal
    m_button.signal_clicked().connect(sigc::mem_fun(*this,&Buttons::on_button_clicked));

    //Pack button into a window
    add(m_button);

    //Display created widget
    m_button.show();

}

//Define destructor
Buttons::~Buttons()
{
}

//define on_button_clicked action fxn
void Buttons::on_button_clicked(void)
{
    std::cout << "Button Clicked! (Placeholder action for now)" << std::endl;
}

*/
