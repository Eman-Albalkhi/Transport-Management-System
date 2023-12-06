#include "Buses.h"
#include "Date.h"
#include<iostream>
using namespace std;
Buses::Buses()
{
    strcpy(Name,"Buses");
    Num_Of_Seats=-1;
}

Buses::Buses(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,float Engine_Displacement,float Length,int Num_of_Seats):
    Wilderness(Transport_Weight,Maximum_Weight,Transport_ID,Transport_Maker,Making_Date,Transport_Speed,is_KM,Private_or_Governor_or_International,is_for_Shipping,Engine_Displacement,Length)
{
    strcpy(Name,"Buses");
    this->Num_Of_Seats=Num_Of_Seats;
}
Buses::Buses(Buses &ob)
{
    Making_Date.SetDay(ob.Making_Date.GetDay());
    Making_Date.SetMonth(ob.Making_Date.GetMonth());
    Making_Date.SetYear(ob.Making_Date.GetYear());
    Transport_ID=ob.Transport_ID;
    strcpy(Transport_Maker,ob.Transport_Maker); strcpy(Name,ob.Name);
    Transport_Speed=ob.Transport_Speed;
    is_KM=ob.is_KM;
    Private_or_Governor_or_International=ob. Private_or_Governor_or_International;
    is_for_Shipping=ob. is_for_Shipping;

    Num_Of_Seats=ob.Num_Of_Seats;
}
void Buses::set_Num_of_Seats(int Num_Of_Seats)
{
    this->Num_Of_Seats=Num_Of_Seats;
}
int Buses::get_Num_Of_seats()
{
    return Num_Of_Seats;
}
void Buses::print()
{
    Wilderness::print();
    cout<<"the number of seats are:"<<Num_Of_Seats<<endl;
}

void Buses::input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList)
{
    Wilderness::input(TList,JList);
    strcpy(Name,"Buses");
    cout<<"enter the number of seats:";
    cin>>Num_Of_Seats;
}
