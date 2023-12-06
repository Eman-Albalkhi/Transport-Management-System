#include "Shipping_Plane.h"
#include<iostream>
using namespace std;

Shipping_Plane::Shipping_Plane()
{
    strcpy(Name,"SPlan");
}

Shipping_Plane::Shipping_Plane(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping):
    Aerial(Transport_Weight,Maximum_Weight,Transport_ID,Transport_Maker,Making_Date,Transport_Speed,is_KM,Private_or_Governor_or_International,is_for_Shipping,Num_Of_Engines,Length)
{
    strcpy(Name,"SPlan");
}
Shipping_Plane::Shipping_Plane(Shipping_Plane &ob)
{
    Transport_ID=ob.Transport_ID;
    strcpy(Transport_Maker,ob.Transport_Maker); strcpy(Name,ob.Name);
    Transport_Speed=ob.Transport_Speed;
    is_KM=ob.is_KM;
    Private_or_Governor_or_International=ob. Private_or_Governor_or_International;
    is_for_Shipping=ob. is_for_Shipping;

    Transport_Weight=ob.Transport_Weight;
    Maximum_Weight=ob.Maximum_Weight;
    Making_Date.SetDay(ob.get_Transport_Making_Date().GetDay());
    Making_Date.SetMonth(ob.get_Transport_Making_Date().GetMonth());
    Making_Date.SetYear(ob.get_Transport_Making_Date().GetYear());
}
void Shipping_Plane::set_Empty_Weight(float Transport_Weight)
{
    this->Transport_Weight=Transport_Weight;
}
void Shipping_Plane::set_Maximum_Weight(float Maximum)
{
    this->Maximum_Weight=Maximum_Weight;
}
float Shipping_Plane::get_Empty_Weight()
{
    return Transport_Weight;
}
float Shipping_Plane::get_Maximum_Weight()
{
    return Maximum_Weight;
}
void Shipping_Plane::print()
{
    Aerial::print();
    cout<<"the empty weight is :"<<Transport_Weight<<endl;
    cout<<"the maximum weight is :"<<Maximum_Weight<<endl;
}
void Shipping_Plane::input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList)
{
    Aerial::input(TList,JList);
    cout<<"enter the empty weight:";
    cin>>Transport_Weight;
    cout<<"enter the maximum weight:";
    cin>>Maximum_Weight;
}
