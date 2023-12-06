#include "Cars.h"
#include<iostream>
using namespace std;
Cars::Cars()
{
    strcpy(Name,"PCars");
    Num_Of_Doors=-1;
}
Cars::Cars(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,float Engine_Displacement,float Length,int Num_Of_Doors):
    Wilderness(Transport_Weight,Maximum_Weight,Transport_ID,Transport_Maker,Making_Date,Transport_Speed,is_KM,Private_or_Governor_or_International,is_for_Shipping,Engine_Displacement,Length)
{
    strcpy(Name,"PCars");
    this->Num_Of_Doors=Num_Of_Doors;
}
Cars::Cars(Cars &ob)
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

    Num_Of_Doors=ob.Num_Of_Doors;
}
void Cars::set_Num_Of_Doors(int Num_Of_Doors)
{
    this->Num_Of_Doors=Num_Of_Doors;
}
int Cars::get_Num_Of_seats()
{
    return Num_Of_Doors;
}
void Cars::print()
{
    Wilderness::print();
    cout<<"the number of doors are :"<<Num_Of_Doors<<endl;

}
void Cars::input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList)
{
    Wilderness::input(TList,JList);
    cout<<"enter the number of doors :";
    cin>>Num_Of_Doors;
}
