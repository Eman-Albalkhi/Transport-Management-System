#include "Passenger_Plane.h"
#include<iostream>
using namespace std;

Passenger_Plane::Passenger_Plane()
{
    strcpy(Name,"APlan");
    Num_Of_Seats=-1;
    Maximum_Luggage_Weight=-1;
}
Passenger_Plane::Passenger_Plane(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,int Num_Of_Engines,float Length,int Num_Of_Seats,float Maximum_Luggage_Weight):
    Aerial(Transport_Weight,Maximum_Weight,Transport_ID,Transport_Maker,Making_Date,Transport_Speed,is_KM,Private_or_Governor_or_International,is_for_Shipping,Num_Of_Engines,Length)
{
    strcpy(Name,"APlan");
    this->Num_Of_Seats=Num_Of_Seats;
    this->Maximum_Luggage_Weight=Maximum_Luggage_Weight;
}
Passenger_Plane::Passenger_Plane(Passenger_Plane &ob)
{
    Transport_ID=ob.Transport_ID;
    strcpy(Transport_Maker,ob.Transport_Maker); strcpy(Name,ob.Name);
    Transport_Speed=ob.Transport_Speed;
    is_KM=ob.is_KM;
    Private_or_Governor_or_International=ob. Private_or_Governor_or_International;
    is_for_Shipping=ob. is_for_Shipping;

    Num_Of_Seats=ob.Num_Of_Seats;
    Maximum_Luggage_Weight=ob.Maximum_Luggage_Weight;
}
void Passenger_Plane::set_Num_of_Seats(int Num_Of_Seats)
{
    this->Num_Of_Seats=Num_Of_Seats;
}
void Passenger_Plane::set_Maximum_Luggage_Weight(int Maximum_Luggage_Weight)
{
    this->Maximum_Luggage_Weight=Maximum_Luggage_Weight;
}
int Passenger_Plane::get_Num_Of_seats()
{
    return Num_Of_Seats;
}
int Passenger_Plane::get_Maximum_Luggage_Weight()
{
    return Maximum_Luggage_Weight;
}
void Passenger_Plane::print()
{
    Aerial::print();
    cout<<"the number of seats are :"<<Num_Of_Seats<<endl;
    cout<<"the maximum luggage weight is :"<<Maximum_Luggage_Weight<<endl;

}
void Passenger_Plane::input(LinkedListTemplate<Transport> TList,LinkedListTemplate <Journey> JList)
{
    Aerial::input(TList,JList);
    cout<<"enter the number of seats :";
    cin>>Num_Of_Seats;
    cout<<"enter the maximum luggage weight :";
    cin>>Maximum_Luggage_Weight;
}
