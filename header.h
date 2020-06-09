#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H
#include <gtkmm-3.0/gtkmm.h>
/*
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/radiobutton.h>
#include <gtkmm-3.0/gtkmm/separator.h>
*/

#include <iostream>


//Class to create window
class Window: public Gtk::Window
{
public:
    Window();
    virtual ~Window();
    //void create_button();
protected:
    //Gtk::Frame m_frame;
    Gtk::Grid p_grid;
    Gtk::Box box1; //top left
    Gtk::Box box2; //top right
    Gtk::Box box3; //bottom row

    Gtk::Button button1;
    Gtk::Button button2;
    Gtk::Button q_button;

    void on_button_clicked1();
    void on_button_clicked2();
    void on_button_clicked_quit();
};

/*class Buttons : public Gtk::Button //inherit from Gtk::Button
{
public:
    Buttons(); //constructor
    virtual ~Buttons(); //destructor
    //Note: 'virtual' specified that the destructor can
    //be overwridden in any derived classes
protected:
    //Signal handlers:
    void on_button_clicked();

    //Member widgets:
    Gtk::Button m_button; //creates a button member widget
};*/
#endif // GTKMM_EXAMPLE_HELLOWORLD_H
