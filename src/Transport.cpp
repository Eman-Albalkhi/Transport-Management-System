#include "Transport.h"
#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
Transport::Transport()
{
    Transport_Weight=0;
    Maximum_Weight=0;
    this->Transport_ID=-1;
    this->is_for_Shipping=0;
    this->is_KM=0;
    this->Private_or_Governor_or_International=0;
    this->Transport_Speed=0;
}
Transport::Transport(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date_ob,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping):Making_Date(Making_Date_ob)
{
    this->Transport_Weight=Transport_Weight;
    this->Maximum_Weight=Maximum_Weight;
    this->Transport_ID=Transport_ID;
    strcpy(this->Transport_Maker,Transport_Maker.c_str());
    this->Transport_Speed=Transport_Speed;
    this->is_KM=is_KM;
    this->is_for_Shipping=is_for_Shipping;
    this->Private_or_Governor_or_International=Private_or_Governor_or_International;
}
void Transport::set_Transport_ID(long int Transport_ID)
{
    this->Transport_ID=Transport_ID;
}
void Transport::set_Transport_Maker(string Transport_Maker)
{
    strcpy(this->Transport_Maker,Transport_Maker.c_str());
}
void Transport::set_Transport_Making_Date(Date ob)
{
    Making_Date.SetDay(ob.GetDay());
    Making_Date.SetMonth(ob.GetMonth());
    Making_Date.SetYear(ob.GetYear());
}
void Transport::set_is_for_Shipping(bool is_for_Shipping)
{
    this->is_for_Shipping=is_for_Shipping;
}
void Transport::set_Transport_Speed(float Transport_Speed)
{
    this->Transport_Speed=Transport_Speed;
}
void Transport::set_is_KM(bool is_KM)
{
    this->is_KM=is_KM;
}
void Transport::set_Private_or_Governor_or_International(int Private_or_Governor_or_International)
{
    this->Private_or_Governor_or_International=Private_or_Governor_or_International;
}
long int Transport::get_ID()
{
    return Transport_ID;
}
string Transport::get_Name()
{
    return Name;
}
string Transport::get_Transport_Maker()
{
    return Transport_Maker;
}
Date Transport::get_Transport_Making_Date()
{
    return Making_Date;
}
float Transport::get_Transport_Speed()
{
    return Transport_Speed;
}
bool Transport::get_is_KM()
{
    return is_KM;
}
int Transport::get_Private_or_Governor_or_International()
{
    return Private_or_Governor_or_International;
}
bool Transport::get_is_for_Shipping()
{
    return is_for_Shipping;
}
void Transport::print()
{
    cout<<"the transport ID is :"<<Transport_ID<<endl;
    cout<<"the transport maker is :"<<Transport_Maker<<endl;
    Making_Date.print_Date();
    cout<<"the speed of transport is :"<<Transport_Speed<<endl;
    if(is_KM)

        cout<<"the transport is wilderness"<<endl;

    else
        cout<<"the transport is Aerial"<<endl;


    cout<<"the transport name is :"<<Name<<endl;
    cout<<"the transport weight is :"<<Transport_Weight<<endl;
    if(is_for_Shipping)
        cout<<"this is A shipping transport"<<endl;
    else
        cout<<"this is A passengers transport"<<endl;
    if(Private_or_Governor_or_International==0)
        cout<<"this is A private transport"<<endl;
    else if(Private_or_Governor_or_International==1)
        cout<<"this is A governor transport"<<endl;
    else if(Private_or_Governor_or_International==2)
        cout<<"this is A international transport"<<endl;

}
void Transport::input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList)
{
U1:
    cout<<"enter the transport ID :";
    cin>>Transport_ID;
    if(TList.isThere(Transport_ID))
    {
        cout<<"You entered A Transport ID That is Already There Please re-enter"<<endl;
        goto U1;
    }
    cout<<"enter the transport marker :";
    cin>>Transport_Maker;
    cout<<"enter the speed of transport";
    cin>>Transport_Speed;
    cout<<"enter the weight :";
    cin>>Transport_Weight;
    cout<<"if the transport speed is in KM enter 1 or enter 0 if otherwise : ";
    cin>>is_KM;
    cout<<"if the transport ownership is private enter 0 or if it is governor enter 1 or if it is international enter 2";
    cin>>Private_or_Governor_or_International;
    cout<<"Enter the making date "<<endl;
    Making_Date.input_Date();
}
