#include "customer.h"
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include "admin.h"
using namespace std;
void Customer::bookTicket()
{
    char from[200],name[50];
    int chk=0;
    Ticket t;
    Admin ad;

    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ###############::TICKET BOOKING::###############\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
    cin.getline(from,200);

    buses.open("Buses.dat", ios::in | ios::out | ios::app | ios::binary);
    if(buses.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
    }

    else
    {
        while(buses.read((char*)&ad, sizeof(ad)))
        {
            if(strcmpi(ad.getDeptSt(),from) == 0)
	    {
                cout<<"\n\n\n\n";
                cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
                cout<<"\t\t\t\t\t\t\t\t\t\t ###############::AVAILABLE BUSES::##############\n";
                cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";
                ad.showBus();
                chk = 1;
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Customer Name :-> ";
                cin.getline(name,50);
                ad.book();
                //ad.setTicketNo();
                t.generateTicket(name,ad);
                ticket.open("tickets.dat", ios::out | ios::app | ios::binary);
                ticket.write((char*)&t, sizeof(t));
                ticket.close();

                buses.seekp(buses.tellg()-sizeof(ad), ios::beg);
                buses.write((char*)&ad, sizeof(ad));

                cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Booked Successfully...!!";
                //cout << "\n\t\t\t\t\t\t\t\t\t\tYour Alloted TicketNo is [" << ad.getTicketNo() << "]";
                //cout << "\n\t\t\t\t\t\t\t\t\t\tPlease Remember Your TicketNo Carefully...!!";
            }
        }

        if(chk == 0)
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Buses Found...!!";
    }

    buses.close();
}

// USER LOGIN FUNCTION ########################################################################################################################
void Customer::viewBookings()
{
    char cname[50];
    int chk = 0;
    Ticket t;

    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Name:-> ";
    cin.getline(cname,50);
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ################::YOUR BOOKINGS::###############\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    ticket.open("tickets.dat", ios::in | ios::app | ios::binary);
    if(ticket.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
    }

    else
    {
        while(ticket.read((char*)&t, sizeof(t)))
        {
            if(strcmpi(t.getName(),cname) == 0)
            {
                t.displayTicket();
                chk = 1;
            }
        }
        if(chk = 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!";
        }

    }

    ticket.close();
}

void Customer::cancelTicket()
{
    char cname[50];
    int chk = 0;
    Ticket t;
    Admin ad;

    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Name:-> ";
    cin.getline(cname,50);

    ticket.open("tickets.dat", ios::in | ios::out | ios::app | ios::binary);
    buses.open("temp.dat", ios::out | ios::app | ios::binary);

    if(ticket.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
    }

    else
    {
        ticket.seekg(0,ios::beg);
        while(ticket.read((char*)&t, sizeof(t)))
        {
            if(strcmpi(t.getName(),cname) != 0)
            {
                buses.write((char*)&t, sizeof(t));

            }
            else
            {
                chk = 1;
            }
        }
        if(chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Not Found...!!";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Cancelled...!!";
        }

    }

    ticket.close();
    buses.close();
    remove("tickets.dat");
    rename("temp.dat","tickets.dat");
}