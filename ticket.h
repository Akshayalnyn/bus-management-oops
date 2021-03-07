#ifndef TICKET_H
#define TICKET_H
#include "admin.h"
#include<string.h>
#include<iostream.h>
#include<stdio.h>
using namespace std;
class Ticket
{
private:
    char name[50];
    Admin a;
public:
    void generateTicket(char cname[], Admin ab)
    {
        strcpy(name,cname);
        a = ab;
    }

    void displayTicket()
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout <<"\t\t\t\t\t\t\t\t\t\tName: " << name;
        a.showTicket();

    }

    char* getName()
    {
        return name;
    }
};
#endif