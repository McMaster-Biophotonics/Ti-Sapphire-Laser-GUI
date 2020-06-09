#include "header.h"

//Define window constructor
Window::Window():button1("Home Command"),button2("Button 2"),q_button("Press to Quit")
{
    //Set title of grid
    set_title("Gtk::Grid");

    //Set border width
    set_border_width(12);

    //Add parent frame to window
    add(p_grid);

    //Define signal response for buttons
    button1.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked1));
    button2.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked2));
    q_button.signal_clicked().connect(sigc::mem_fun(*this,&Window::on_button_clicked_quit));

    //Add boxes to parent grid
    p_grid.add(box1);
    p_grid.add(box2);
    p_grid.attach_next_to(box3,box1,Gtk::POS_BOTTOM,2,1);


    //Add buttons to boxes
    box1.pack_start(button1);
    box2.pack_start(button2);
    box3.pack_start(q_button);

    show_all_children();

}


//Destructor
Window::~Window()
{
}

void Window::on_button_clicked1()
{
    std::cout << "Clicked 1!" << std::endl;
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
