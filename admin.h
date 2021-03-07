#ifndef ADMIN_H
#define ADMIN_H
#include<string.h>
class Admin
{
private:
    int busID, max_seats,fare,booked,ticketNo;
    char DeptSt[200],Time[50];

public:
    void AdminLogin();
    void AddBus();
    void ViewBus();
    void showBus();
    void cancelTickets();
    void modifyTickets();
    void deleteBus();
    void viewBookings();
    void showTicket();

    Admin()
    {
        busID = 0;
        max_seats = 50;
        booked = 0;
        fare = 0;
        ticketNo = 0;
        strcpy(Time, "9:10AM");
        strcpy(DeptSt, "");
    }

    int getBusId()
    {
        return busID;
    }

    char* getDeptSt()
    {
        return DeptSt;
    }

    void book()
    {
        booked++;
    }

    char* getArrTime()
    {
        return Time;
    }

    int getBooked()
    {
        return booked;
    }

    int getMax()
    {
        return max_seats;
    }

    int getFare()
    {
        return fare;
    }

    int getTicketNo()
    {
        return ticketNo;
    }

    void setTicketNo()
    {
        ticketNo++;
    }

} Ad1;
#endif