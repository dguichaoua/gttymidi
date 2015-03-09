/*
    This file is part of ttymidi.

    ttymidi is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ttymidi is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ttymidi.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include "mainwindow.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Initialize gtkmm
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    // Create the window
    mainwindow w;
    // Start main loop
    //Shows the window and returns when it is closed.
    return app->run(w);
}

