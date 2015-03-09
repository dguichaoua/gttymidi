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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <iostream>
#include <fstream>
#include "ttymidi.h"
#include "baudrate.h"
#include "serialport.h"

using namespace std;


// The class mainwindow inherits from Gtk::Window
class mainwindow : public Gtk::Window
{
	// Constructor and destructor
public:
	mainwindow();
	virtual             ~mainwindow();

protected:
	//Signal handlers (run when the button are clicked)
	void                  on_bridge_on();
	void                  on_bridge_off();
    void                  on_serialport();
    void                  on_baudrate();
    string                NumberToString(int Number);
    void                  add_text(string s);

	//Member widgets:
	Gtk::Box m_Box_Top;
	Gtk::ButtonBox m_ButtonBox;
    Gtk::Separator m_Separator;
    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TextView m_TextView;
	Gtk::Button           bridge_on;
	Gtk::Button           bridge_off;
	Gtk::Button           serialport;
	Gtk::Button           baudrate;

	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;

	int run;
	BaudRate baudrt;
	SerialPort serialpt;
};


#endif // MAINWINDOW_H
