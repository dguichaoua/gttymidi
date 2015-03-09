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


#include "baudrate.h"


// Constructor of the main Window (build ui interface).
BaudRate::BaudRate() :
    m_Box_Top(Gtk::ORIENTATION_VERTICAL,0),
    m_Box1(Gtk::ORIENTATION_VERTICAL, 10),
    m_Box2(Gtk::ORIENTATION_HORIZONTAL, 100),
    m_115("115200"), m_57("57600"),m_38("38400"), m_19("19200"),m_9("9600"), m_4("4800"),m_2("2400"), m_1("1200"),
    m_Button_Ok("Ok"),m_Button_Cancel("Close")
{
    // Set title and border of the window
    set_title("Baud Rate");
    set_border_width(0);
    set_default_size(300, 100);

    // Put radio buttons 2 and 3 in the same group as 1:
    Gtk::RadioButton::Group group = m_115.get_group();
    m_57.set_group(group);
    m_38.set_group(group);
    m_19.set_group(group);
    m_9.set_group(group);
    m_4.set_group(group);
    m_2.set_group(group);
    m_1.set_group(group);


    // Add outer box to the window (because the window
    // can only contain a single widget)
    add(m_Box_Top);

    //Put the inner boxes and the separator in the outer box:
    m_Box_Top.pack_start(m_Box1);
    m_Box_Top.pack_start(m_Separator);
    m_Box_Top.pack_start(m_Box2);

    // Set the inner boxes' borders
    m_Box2.set_border_width(10);
    m_Box1.set_border_width(10);

    // Put the radio buttons in Box1:
    m_Box1.pack_start(m_115);
    m_Box1.pack_start(m_57);
    m_Box1.pack_start(m_38);
    m_Box1.pack_start(m_19);
    m_Box1.pack_start(m_9);
    m_Box1.pack_start(m_4);
    m_Box1.pack_start(m_2);
    m_Box1.pack_start(m_1);

    // Set the button active
    m_115.set_active();

    // Put Close button in Box2:
    //m_Box2.pack_start(m_Button_Ok);
    m_Box2.pack_start(m_Button_Cancel);

    // Make the button the default widget
    m_Button_Cancel.set_can_default();
    m_Button_Cancel.grab_default();

    // Connect the clicked signal of the button to
    // RadioButtons::on_button_clicked()
    m_Button_Cancel.signal_clicked().connect(sigc::mem_fun(*this,
                                            &BaudRate::on_button_clicked) );

    // Show all children of the window
    show_all_children();

}

// Destructor of the class
BaudRate::~BaudRate()
{

}

void BaudRate::on_button_clicked()
{
    hide(); //to close the window.
}

int BaudRate::get_baud()
{
    if (m_115.get_active()) return 115200;
    if (m_57.get_active()) return 57600;
    if (m_38.get_active()) return 38400;
    if (m_19.get_active()) return 19200;
    if (m_9.get_active()) return 9600;
    if (m_4.get_active()) return 4800;
    if (m_2.get_active()) return 2400;
    else return 1200;
}

void BaudRate::set_baud(int baud)
{
    switch (baud)
    {
        case 1200   :
            m_1.set_active();
            break;
        case 2400   :
            m_2.set_active();
            break;
        case 4800   :
            m_4.set_active();
            break;
        case 9600   :
            m_9.set_active();
            break;
        case 19200  :
            m_19.set_active();
            break;
        case 38400  :
            m_38.set_active();
            break;
        case 57600  :
            m_57.set_active();
           break;
        case 115200 :
            m_115.set_active();
            break;
        default:
            exit(1);
    }
}

