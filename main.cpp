#include <iostream>
#include "Trucks.h"
#include "Buses.h"
#include "Passenger_Plane.h"
#include "Cars.h"
#include"Shipping_Plane.h"
#include "LinkedListTemplate.h"
#include "Transport_File_Handler.h"
#include "Journey_File_Handler.h"
#include "Functions.h"
using namespace std;


int main()
{
    LinkedListTemplate<Journey> JList;
    LinkedListTemplate<Transport> TList;
    Journey_File_Handler JFile;
    Transport_File_Handler TFile;
    Transport *Tptr;
    Journey *Jptr;
    Journey j;
    string From,To;
    int Choice;
    int ID;
    Date A,B;
    cout <<"Hello And Welcome :"<<endl;
    while(1)
    {
        print_menu();
        scanf("%d",&Choice);
        fflush(stdin);
        switch(Choice)
        {
        case 1:
            Tptr=new Cars();
            Tptr->input(TList,JList);
            TList.insertNewNode(Tptr);
            break;
        case 2:
            Tptr=new Trucks();
            Tptr->input(TList,JList);
            TList.insertNewNode(Tptr);
            break;
        case 3:
            Tptr=new Buses();
            Tptr->input(TList,JList);
            TList.insertNewNode(Tptr);
            break;
        case 4:
            Tptr=new Passenger_Plane();
            Tptr->input(TList,JList);
            TList.insertNewNode(Tptr);
            break;
        case 5:
            Tptr=new Shipping_Plane();
            Tptr->input(TList,JList);
            TList.insertNewNode(Tptr);
            break;
        case 6:
            Jptr=new Journey();
            Jptr->input(TList,JList);
            JList.insertNewNode(Jptr);
            break;
        case 7:
            cout<<"Enter the transport ID : ";
            cin>>ID;
            print_journey(ID,JList);
            break;
        case 8:
            cout<<"Enter the name of the first city :";
            cin>>From;
            cout<<"Enter the name of the second city :";
            cin>>To;
            cout<<"Enter the transport ID : ";
            cin>>ID;
            print_journeys_between_places(To,From,ID,JList);
            break;
        case 9:
            cout<<"Enter the first Date :";
            A.input_Date();
            cout<<"Enter the second Date :";
            B.input_Date();
            cout<<"Enter the transport ID : ";
            cin>>ID;
            print_between_dates(A,B,ID,JList);
            break;
        case 10:
            JFile.Journey_LinkedList_Reader(JList);
            TFile.Transport_LinkedList_Reader(TList);
            break;
        case 11:
            JFile.Journey_LinkedList_Adder(JList);
            TFile.Transport_LinkedList_Adder(TList);
            break;
        case 12:
            TList.print();
            cout<<"=============================================="<<endl;
            JList.print();
            return 0;
        }

    }
}
