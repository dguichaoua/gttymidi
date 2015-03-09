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


#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/separator.h>
#include <string>
#include "ttymidi.h"

using namespace std;

class SerialPort : public Gtk::Window
{
public:
    SerialPort();
    virtual ~SerialPort();
    string get_port();
    void set_port(string sport);

protected:
  //Signal handlers:
  void on_button_clicked();

  //Child widgets:
  Gtk::Box m_Box_Top, m_Box1, m_Box2;
  Gtk::RadioButtonGroup groupe;
  Gtk::RadioButton m_1, m_2, m_3, m_4, m_5, m_6, m_7, m_8, m_9;
  Gtk::Separator m_Separator;
  Gtk::Button m_Button_Close;

};


#endif // SERIALPORT_H
