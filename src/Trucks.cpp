#include "Trucks.h"
#include<iostream>
using namespace std;

Trucks::Trucks()
{
    strcpy(Name,"Truck");
    Goods_Height=-1;
}

Trucks::Trucks(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,float Engine_Displacement,float Length,float Goods_Height):
    Wilderness(Transport_Weight,Maximum_Weight,Transport_ID,Transport_Maker,Making_Date,Transport_Speed,is_KM,Private_or_Governor_or_International,is_for_Shipping,Engine_Displacement,Length)
{
    strcpy(Name,"Truck");
    this->Goods_Height=Goods_Height;
}
Trucks::Trucks(Trucks &ob)
{
    Making_Date.SetDay(ob.Making_Date.GetDay());
    Making_Date.SetMonth(ob.Making_Date.GetMonth());
    Making_Date.SetYear(ob.Making_Date.GetYear());
    Transport_ID=ob.Transport_ID;
    strcpy(this->Transport_Maker,ob.Transport_Maker);
    strcpy(this->Name,ob.Name);
    Transport_Speed=ob.Transport_Speed;
    is_KM=ob.is_KM;
    Private_or_Governor_or_International=ob. Private_or_Governor_or_International;
    is_for_Shipping=ob. is_for_Shipping;
    Empty_Weight=ob.Empty_Weight;
    Maximum_Weight=ob.Maximum_Weight;
    Goods_Height=ob.Goods_Height;
}
void Trucks::set_Empty_Weight(float Emoty_Weight)
{
    this->Empty_Weight=Empty_Weight;
}
void Trucks::set_Maximum_Weight(float Maximum_Weight)
{
    this->Maximum_Weight=Maximum_Weight;
}
void Trucks::set_Goods_Height(float Goods_Height)
{
    this->Goods_Height=Goods_Height;
}
float Trucks::get_Empty_Weight()
{
    return Empty_Weight;
}
float Trucks::get_Maximum_Weight()
{
    return Maximum_Weight;
}
float Trucks::get_Goods_Height()
{
    return Goods_Height;
}
void Trucks::print()
{
    Wilderness::print();
    cout<<"the empty weight :"<<Empty_Weight;
    cout<<"the maximum weight :"<<Maximum_Weight;
    cout<<"the goods height :"<<Goods_Height;
}
void Trucks::input(LinkedListTemplate <Transport> TList,LinkedListTemplate<Journey> JList)
{
    Wilderness::input(TList,JList);
    cout<<"enter the empty weight :";
    cin>>Empty_Weight;
    cout<<"enter the maximum weight :";
    cin>>Maximum_Weight;
    cout<<"enter the goods height";
    cin>>Goods_Height;
}
