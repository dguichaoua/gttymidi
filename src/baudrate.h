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


#ifndef BAUDRATE_H
#define BAUDRATE_H

#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/separator.h>
#include <gtkmm/dialog.h>
#include <gtkmm/stock.h>

class BaudRate : public Gtk::Window
{
public:
    BaudRate();
    virtual ~BaudRate();
    int get_baud();
    void set_baud(int baud);

protected:
  //Signal handlers:
  void on_button_clicked();

  //Child widgets:
  Gtk::Box m_Box_Top, m_Box1, m_Box2;
  Gtk::RadioButtonGroup groupe;
  Gtk::RadioButton m_115, m_57, m_38, m_19, m_9, m_4, m_2, m_1 ;
  Gtk::Separator m_Separator;
  Gtk::Button m_Button_Ok;
  Gtk::Button m_Button_Cancel;
};


#endif // BAUDRATE_H
