#include "header.h"

int main(int argc, char *argv[])
{
    //Create Application instance
    auto app = Gtk::Application::create(argc, argv, "com.github.Laser-Micromachining");

    //create window object
    Window window;

    //Begin event loop process
    return app->run(window);
}
