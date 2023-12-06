#include "Aerial.h"
#include "Transport.h"
#include<iostream>
using namespace std;
Aerial::Aerial()
{
    Num_Of_Engines=-1;
    Length=-1;
}
Aerial::Aerial(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,int Num_Of_Engines,float Length):
    Transport(Transport_Weight,Maximum_Weight,Transport_ID,Transport_Maker,Making_Date,Transport_Speed,is_KM,Private_or_Governor_or_International,is_for_Shipping)
{
    this->Num_Of_Engines=Num_Of_Engines;
    this->Length=Length;
}
void Aerial::set_Num_of_Engines(int Num_Of_Engines)
{
    this->Num_Of_Engines=Num_Of_Engines;
}
void Aerial::set_Length(float Length)
{
    this->Length=Length;
}
int Aerial::get_Num_Of_Engines()
{
    return Num_Of_Engines;
}
float Aerial::get_Length()
{
    return Length;
}
void Aerial::print()
{
    Transport::print();
    cout<<"the number of engines are :"<<Num_Of_Engines<<endl;
    cout<<"the length is : "<<Length<<endl;
}
void Aerial::input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList)
{
    Transport::input(TList,JList);
    cout<<"enter the num of engines :";
    cin>>Num_Of_Engines;
    cout<<"enter the length:";
    cin>>Length;

}

