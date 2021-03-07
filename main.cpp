#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include "admin.h"
#include "ticket.h"
#include "customer.h"
#include "admin1.cpp"
#include "customer1.cpp"

using namespace std;


// MENU GLOBAL FUNCTION #################################################################################################################
void MainMenu();
void UserMenu();
void AdminMenu();
void Welcome();

fstream buses,ticket;


// MAIN FUNCTION ############################################################################################################################################
int main()
{
    char root_pass[20]="";
    char ch;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\tEnter Master Password:-> ";
    ch = getch();
    while(ch != 13)// Max 16 characters
    {
        root_pass.push_back(ch);
        ch = getch();
        cout<<"*";

    }
    if(root_pass == "root")
    {
        Welcome();
    }
    else
    {
        cout<<"\n\n\n\n\n\n\n";
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\tAccess Denied...!!!\n\n";
        main();
    }

    return 0;
}

//  ############################################WELCOME SCREEN FUNCTION##########################################################
void Welcome()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ||                  WELCOME TO                ||\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ||                                            ||\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ||            BUS RESERVATION SYSTEM          ||\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ||                                            ||\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ||                    PROJECT                 ||\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t  Created By:-             \t\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t                           \t\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t  ABINAYA U             \t\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t  AKSHAYA L        \t\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";
    MainMenu();
}

// ##############################################MAIN MENU FUNCTION##############################################################
void MainMenu()
{
    int choice;
    while(1)
    {
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t #################::MAIN MENU::##################\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t1. Customer Portal \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t2. Admin Portal \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t3. EXIT \t\t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";
	cin>>choice;
	switch(choice)
	{
		case 1:
            		UserMenu();
            		break;

        	case 2:
            		Ad1.AdminLogin();
            		break;

	        case 3:
                        cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t  Thanks for using our project...!!! \t\t\t\n";
            		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t          Have a nice day...!!!      \t\t\t\n\n";
            		exit(0);

	        default:
        	    	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            		break;

        }

    }

}

// USER MENU FUNCTION #################################################################################################################################
void UserMenu()
{
    int usr_choice;
    while(1)
    {
        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t #################::USER PORTAL::################\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t1. Book Ticket       \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t2. View Bookings     \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t3. Cancel Ticket     \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t4. BACK              \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
	cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";
	cin>>usr_choice;
	switch(usr_choice)
	{
		case 1:
            		Cust1.bookTicket();
            		break;

        	case 2:
            		Cust1.viewBookings();
            		break;

 	        case 3:
            		Cust1.cancelTicket();
                        break;

	        case 4:
                        MainMenu();
            		break;

	        default:
            		cout<<"\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            		UserMenu();
            		break;
     	}

    }
}

// ADMIN MENU FUNCTION####################################################################################################################
void AdminMenu()
{
    int admn_choice;
    while(1)
    {
        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ################::ADMIN PORTAL::################\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t1. Add Bus            \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t2. View Buses         \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t3. View Bookings      \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t4. Cancel Ticket      \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t5. Modify Booking     \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t6. Delete Bus         \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t7. BACK               \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";

        cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin>>admn_choice;

        switch(admn_choice)

        {
		case 1:
            		Ad1.AddBus();
	                break;

	        case 2:
        		Ad1.ViewBus();
            		cout<<"\n\n";
            		break;

       		case 3:
          		Ad1.viewBookings();
      		        break;

       		case 4:
            		Ad1.cancelTickets();
                        break;

	        case 5:
        	    	Ad1.modifyTickets();
            		break;

	        case 6:
        	   	Ad1.deleteBus();
            		break;

	        case 7:
                    	MainMenu();
            		break;

	        default:
        	        cout<<"\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
                        break;

        }

    }
}