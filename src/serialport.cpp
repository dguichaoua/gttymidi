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


#include "serialport.h"


// Constructor of the main Window (build ui interface).
SerialPort::SerialPort() :

    m_Box_Top(Gtk::ORIENTATION_VERTICAL),
    m_Box1(Gtk::ORIENTATION_VERTICAL, 10),
    m_Box2(Gtk::ORIENTATION_HORIZONTAL, 10),
    m_1("/dev/ttyS0"), m_2("/dev/ttyS1"),m_3("/dev/ttyS2"), m_4("/dev/ttyACM0"),m_5("/dev/ttyACM1"), m_6("/dev/ttyACM2"),m_7("/dev/ttyUSB0"), m_8("/dev/ttyUSB1"),m_9("/dev/ttyUSB2"),
    m_Button_Close("close")
{
    // Set title and border of the window
    set_title("Serial port");
    set_border_width(0);
    set_default_size(300, 100);

   // Put radio buttons 2 and 3 in the same group as 1:
    Gtk::RadioButton::Group group = m_1.get_group();
    m_2.set_group(group);
    m_3.set_group(group);
    m_4.set_group(group);
    m_5.set_group(group);
    m_6.set_group(group);
    m_7.set_group(group);
    m_8.set_group(group);
    m_9.set_group(group);


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
    if (get_serial((char *)"/dev/ttyS0")) m_Box1.pack_start(m_1);
    if (get_serial((char *)"/dev/ttyS1")) m_Box1.pack_start(m_2);
    if (get_serial((char *)"/dev/ttyS2")) m_Box1.pack_start(m_3);
    if (get_serial((char *)"/dev/ttyACM0")) m_Box1.pack_start(m_4);
    if (get_serial((char *)"/dev/ttyACM1")) m_Box1.pack_start(m_5);
    if (get_serial((char *)"/dev/ttyACM2")) m_Box1.pack_start(m_6);
    if (get_serial((char *)"/dev/ttyUSB0")) m_Box1.pack_start(m_7);
    if (get_serial((char *)"/dev/ttyUSB1")) m_Box1.pack_start(m_8);
    if (get_serial((char *)"/dev/ttyUSB2")) m_Box1.pack_start(m_9);

    // Set the button active
    m_1.set_active();

    // Put Close button in Box2:
    m_Box2.pack_start(m_Button_Close);

    // Make the button the default widget
    m_Button_Close.set_can_default();
    m_Button_Close.grab_default();

    // Connect the clicked signal of the button to
    // RadioButtons::on_button_clicked()
    m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this,
                                            &SerialPort::on_button_clicked) );

    // Show all children of the window
    show_all_children();
}

// Destructor of the class
SerialPort::~SerialPort()
{

}

void SerialPort::on_button_clicked()
{
    hide(); //to close the window.
}

string SerialPort::get_port()
{
    if (m_2.get_active()) return "/dev/ttyS1";
    if (m_3.get_active()) return "/dev/ttyS2";
    if (m_4.get_active()) return "/dev/ttyACM0";
    if (m_5.get_active()) return "/dev/ttyACM1";
    if (m_6.get_active()) return "/dev/ttyACM2";
    if (m_7.get_active()) return "/dev/ttyUSB0";
    if (m_8.get_active()) return "/dev/ttyUSB1";
    if (m_9.get_active()) return "/dev/ttyUSB2";
    else return "/dev/ttyS0";
}

void SerialPort::set_port(string sport)
{
    if (sport == "/dev/ttyS0") m_1.set_active();
    if (sport == "/dev/ttyS1") m_2.set_active();
    if (sport == "/dev/ttyS2")m_3.set_active();
    if (sport == "/dev/ttyACM0")m_4.set_active();
    if (sport == "/dev/ttyACM1")m_5.set_active();
    if (sport == "/dev/ttyACM2")m_6.set_active();
    if (sport == "/dev/ttyUSB0")m_7.set_active();
    if (sport == "/dev/ttyUSB1")m_8.set_active();
    if (sport == "/dev/ttyUSB2")m_9.set_active();
}



