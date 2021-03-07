#include "admin.h"
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void Admin::AdminLogin()
{
    char AdmnUname[25], AdmnPass[25];
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t #################::ADMIN LOGIN::################\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter AdminID:-> ";
    cin>>AdmnUname;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Password:-> ";
    cin>>AdmnPass;

    if(AdmnUname == "admin" && AdmnPass == "pass")
    {
        AdminMenu();
    }
    else
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t\tUsername or Password is wrong...!!! ";
        AdminLogin();
    }

}

void Admin::AddBus()
{
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ###################::ADD BUS::##################\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
    cin >> busID;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Time:-> ";
    cin.getline(Time,50);
    cout<<"\n\t\t\t\t\t\t\t\t\t\tDestination:-> ";
    cin.getline(DeptSt,200);
    cout<<"\n\t\t\t\t\t\t\t\t\t\tFare:-> ";
    cin >> fare;

    buses.open("Buses.dat",ios::out|ios::app|ios::binary);
    buses.write((char*)this, sizeof(*this));
    buses.close();

    cout<<"\n\t\t\t\t\t\t\t\t\t\tBus Added Successfully...!!!:-> \n";
}

void Admin::ViewBus()
{
    buses.open("Buses.dat",ios::in|ios::app|ios::binary);
    if(!buses)
        cout<<"\n\t\t\t\tFile Not Found...!!!";
    else
    {
        cout<<"\n\n";
        cout<<"\t                                                     ::BUS DETAILS::                                             \n\n";
        cout<<"\t===================================================================================================================\n";
        cout<<"\t"<<"   Bus No." << setw(22) << "Destination" << setw(16) << "Arrival" << setw(20) << "Seats" << setw(16) << "Fare" << "\n";
        cout<<"\t===================================================================================================================\n";

        buses.read((char*)this, sizeof(*this));

        while(!buses.eof())
        {
            cout << "\n\t    " << busID << setw(20) << DeptSt << setw(16) << Time << setw(22) << max_seats - booked << setw(18) << fare << "\n";
            buses.read((char*)this, sizeof(*this));

        }
        buses.close();
    }
}

void Admin::showBus()
{

    cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t\t\t\tBus No:-> " << busID;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tDestination:-> " << DeptSt;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tTime:-> " << Time;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tSeats Remaining:-> " << max_seats - booked;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tFare:-> " << fare;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";

    cout <<"\n\n";
}

void Admin::cancelTickets()
{
    char cname[50];
    int chk = 0;
    Ticket t;

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

//MODIFY TICKET FUNCTION ###########################################################################################
void Admin::modifyTickets()
{
    char cname[50],name[50];
    int chk = 0;
    Ticket t;

    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Name:-> ";
    cin.getline(cname,50);

    ticket.open("tickets.dat", ios::in | ios::out | ios::app | ios::binary);
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
                ticket.seekg(0,ios::cur);
                cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter New Details \n";
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Customer Name :-> ";
                cin.getline(name,50);
                ticket.seekp(ticket.tellg() - sizeof(t));
                ticket.write((char*)&t, sizeof(t));
                cout << "\n\t\t\t\t\t\t\t\t\t\tName Updated Successfully...!!";
                chk = 1;
            }
        }
        if(chk = 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tRecord Not Found...!!";
        }

    }

    ticket.close();

}


void Admin::deleteBus()
{
    int bid;
    int chk = 0;
    Ticket t;

    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Bus No:-> ";
    cin>>bid;

    buses.open("Buses.dat", ios::in | ios::out | ios::app | ios::binary);
    ticket.open("temp.dat", ios::out | ios::app | ios::binary);

    if(buses.fail())
    {
        cout << "\n\\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
    }

    else
    {
        buses.seekg(0,ios::beg);
        while(buses.read((char*)&Ad1, sizeof(Admin)))
        {
            if(Ad1.getBusId() != bid)
            {
                ticket.write((char*)&Ad1, sizeof(Admin));

            }
            else
            {
                chk = 1;
            }
        }
        if(chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Not Found...!!";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Deleted...!!";
        }

    }

    buses.close();
    ticket.close();
    remove("Buses.dat");
    rename("temp.dat","Buses.dat");
}

void Admin::viewBookings()
{
    Ticket t;
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
        ticket.read((char*)&t, sizeof(t));
        while(!ticket.eof())
        {
            t.displayTicket();
            ticket.read((char*)&t, sizeof(t));
        }

    }

    ticket.close();
}

void Admin::showTicket()
{
    //cout<<"\n\t\t\t\tTicket No:-> " << ticketNo;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tBus No:-> " << busID;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tDestination:-> " << DeptSt;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tTime:-> " << Time;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tFare:-> " << fare;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";

    cout <<"\n\n";
}