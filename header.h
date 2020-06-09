#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H

//This is just for prototyping, but when the app
//is released, only include necessary headers for
//decreased build time
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
    void label_frame_setup();
};
#endif // GTKMM_EXAMPLE_HELLOWORLD_H
