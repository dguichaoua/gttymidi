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


#include "mainwindow.h"


int baud = 38400;
string serport = (char *)"/dev/ttyS0";
string homepath = getenv("HOME");
string iconpath = "/usr/local/share/gttymidi.png";

// Constructor of the main Window (build ui interface).
mainwindow::mainwindow()   :
    m_Box_Top(Gtk::ORIENTATION_VERTICAL),
    bridge_on("Bridge On"), bridge_off("Bridge Off"), serialport("Serial port"), baudrate("Baud rate")
{
    // Initialize the main window
    set_title("Gtk serial to Alsa midi bridge");
    ifstream my_icon(iconpath.c_str());
    if (my_icon.good())
    {
        set_icon_from_file(iconpath.c_str());
    }
    else
    {
        ifstream my_icon("gttymidi.png");
        if (my_icon.good())
    {
        set_icon_from_file("gttymidi.png");
    }
    }
    set_border_width(5);
    set_default_size(400, 300);


    // Add outer box to the window (because the window
    // can only contain a single widget)
    add(m_Box_Top);

    // Set the inner boxes' borders
    //m_Box_Top.set_border_width(10);

    m_TextView.set_editable(false);;
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    m_Box_Top.pack_start(m_ScrolledWindow);
    m_ScrolledWindow.add(m_TextView);

    m_Box_Top.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

    // Create the first button
    bridge_on.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_bridge_on));
    m_ButtonBox.pack_start(bridge_on, Gtk::PACK_SHRINK);
    bridge_on.set_sensitive(true);


    // Create the second button
    bridge_off.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_bridge_off));
    m_ButtonBox.pack_start(bridge_off, Gtk::PACK_SHRINK);
    bridge_off.set_sensitive(false);

    // Create the third button
    serialport.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_serialport));
    m_ButtonBox.pack_start(serialport, Gtk::PACK_SHRINK);
    serialport.set_sensitive(true);

    // Create the 4th button
    baudrate.signal_clicked().connect(sigc::mem_fun(*this,&mainwindow::on_baudrate));
    m_ButtonBox.pack_start(baudrate, Gtk::PACK_SHRINK);
    baudrate.set_sensitive(true);

    // Display the main grid in the main window
    show_all();

    m_refTextBuffer = Gtk::TextBuffer::create();

    run = false;

    string s;

    ifstream fichconf((homepath+"/.gttymidi.conf").c_str());
    if ( !fichconf )
    {
        s = "File .gttymidi.conf not found\n";
        m_refTextBuffer->insert_at_cursor(s);
    }
    else
    {
        fichconf >> baud;
        fichconf >> serport;
        fichconf.close();
    }

    baudrt.set_baud(baud);
    serialpt.set_port(serport);

    s="Serial Port : "+serport+"\n";
    m_refTextBuffer->insert_at_cursor(s);

    s="Baud rate : "+NumberToString(baud)+"\n";
    m_refTextBuffer->insert_at_cursor(s);
    m_TextView.set_buffer(m_refTextBuffer);
}


// Destructor of the class
mainwindow::~mainwindow()
{
    if(run)
    {
        ttymidi_off();
        bridge_on.set_sensitive(true);
        bridge_off.set_sensitive(false);
        serialport.set_sensitive(true);
        baudrate.set_sensitive(true);
        run = false;
    }
    ofstream fichconf((homepath+"/.gttymidi.conf").c_str());
    if ( !fichconf )
    {
        cerr << "File .gttymidi.conf error\n";
    }
    else
    {
        fichconf << baud << endl;
        fichconf << serport.c_str() << endl;
        fichconf.close();
    }
}


// Call when the first button is clicked
void mainwindow::on_bridge_on()
{
    baud = baudrt.get_baud();
    serport = serialpt.get_port();
    arg_set((char *)serport.c_str(), baud, (char *)"Serial to Midi bridge");
    if(ttymidi_on())
    {
        run = true;
        bridge_on.set_sensitive(false);
        bridge_off.set_sensitive(true);
        serialport.set_sensitive(false);
        baudrate.set_sensitive(false);
        add_text("Bridge "+serport+" to midi port at "+NumberToString(baud)+" baud\n");
    }
}


// Call when the second button is clicked
void mainwindow::on_bridge_off()
{
    if(run)
    {
        ttymidi_off();
        bridge_on.set_sensitive(true);
        bridge_off.set_sensitive(false);
        serialport.set_sensitive(true);
        baudrate.set_sensitive(true);
        run = false;
        add_text("Bridge off\n");
    }

}

// Call when the third button is clicked
void mainwindow::on_serialport()
{
    serialpt.set_modal(true);
    serialpt.show();
}

// Call when the 4th button is clicked
void mainwindow::on_baudrate()
{
    // Start main loop
    baudrt.set_modal(true);
    baudrt.show();
}

string mainwindow::NumberToString(int Number)
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

void mainwindow::add_text(string s)
{
    m_refTextBuffer->insert_at_cursor(s);
}
