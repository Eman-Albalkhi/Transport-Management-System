#include "Wilderness.h"
#include <iostream>
using namespace std;
Wilderness::Wilderness()
{
    this->Engine_Displacement=-1;
    this->Length=-1;
}
Wilderness::Wilderness(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,float Engine_Displacement,float Length):
    Transport(Transport_Weight,Maximum_Weight,Transport_ID,Transport_Maker,Making_Date,Transport_Speed,is_KM,Private_or_Governor_or_International,is_for_Shipping)
{
    this->Engine_Displacement=Engine_Displacement;
    this->Length=Length;
}
void Wilderness::set_Engine_Displacement(float Engine_Displacement)
{
    this->Engine_Displacement=Engine_Displacement;
}
void  Wilderness::set_Length(float Length)
{
    this->Length=Length;
}
float Wilderness:: get_Engine_Displacement()
{
    return Engine_Displacement;
}
float Wilderness::get_Length()
{
    return Length;
}
void Wilderness::print()
{
    Transport::print();
    cout<<"the engine displacement:"<<Engine_Displacement<<endl;
    cout<<"the length is :"<<Length<<endl;

}
void Wilderness::input(LinkedListTemplate <Transport> TList,LinkedListTemplate<Journey> JList)
{
    Transport::input(TList,JList);
    cout<<"enter the engine displacement :";
    cin>>Engine_Displacement;
    cout<<"enter the length:";
    cin>>Length;
}




