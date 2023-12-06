#include "Journey.h"
#include<iostream>
#include<string>
#include "Booking_record.h"
class Booking_record;
using namespace std;
Journey::Journey()
{
    Journey_ID=-1;
    Transportation_ID=-1;
    is_Transportation_Type_For_People=0;
    Journey_Carry_On_Weight=-1;
    Journey_Full_On_Weight=-1;
    Warning=0;
}
void Journey::set_Journey_Full_On_Weight(LinkedListTemplate<Transport> TList)
{
    TList.reset_Curr();
    if(TList.isEmpty())
    {
        cout<<"No Transportation is Available Now"<<endl;
        return;
    }
    while(!TList.isEmpty() &&Transportation_ID< TList.get_Curr()->getData()->get_ID())
    {
        TList.iterate_Curr();
    }
    if((!TList.isEmpty())&&(Transportation_ID == TList.get_Curr()->getData()->get_ID()))
    {
        Journey_Full_On_Weight=Journey_Carry_On_Weight+TList.get_Curr()->getData()->get_Transport_Weight();
        return;
    }
}
Journey::Journey(int Journey_ID,int Transportation_ID,Date JDate,string From,string To,Booking_record Journey_Booking_Record_ob,double Journey_Carry_On_Weight,LinkedListTemplate<Transport> TList):Journey_Date(JDate),Journey_Booking_Record(Journey_Booking_Record_ob)
{
    this->Journey_ID=Journey_ID;
    this->Transportation_ID=Transportation_ID;
    strcpy(this->From,From.c_str());

    strcpy(this->To,To.c_str());
    this->Journey_Carry_On_Weight=Journey_Carry_On_Weight;
    set_Journey_Full_On_Weight(TList);
}
void Journey::input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList)
{
    char temp;
D1:
    cout<<"If you want to cancel enter x"<<endl;
    cin>>temp;
    if(temp=='x')
        return;
    cout<<"Journey_ID is :  ";
    cin>>Journey_ID;
    if(JList.isThere(Journey_ID)||Journey_ID<0)
    {
        cout<<"The Journey_ID is already there/or it's negative"<<endl;
        goto D1;
    }
D2:
    if(temp=='x')
        return;
    cout<<"Transportation_ID is :  ";
    cin>>Transportation_ID;
    if(!TList.isThere(Transportation_ID)||Transportation_ID<0)
    {
        cout<<"The Transportation_ID is not related to any vehicle"<<endl;
        goto D2;
    }
    cout<<"Journey Date is : ";
    Journey_Date.input_Date();
    Transport *tempo=TList.Searcher(Transportation_ID)->getData();
    is_Transportation_Type_For_People=tempo->get_is_for_Shipping();
    if(!is_Transportation_Type_For_People)
        Journey_Carry_On_Weight=Journey_Booking_Record.Booking_record_input(tempo->get_Num_Of_seats());
    else if(is_Transportation_Type_For_People)
    {
        cout<<"the carry on weight :  ";
        cin>>Journey_Carry_On_Weight;
    }
    Journey_Full_On_Weight=Journey_Carry_On_Weight+tempo->get_Transport_Weight();
    if(Journey_Full_On_Weight>tempo->get_Maximum_Weight())
        Warning=1;
    cout<<"The Journey is from :";
    cin>>From;
    cout<<"The Journey is To   :";
    cin>>To;

}

void Journey::Warning_Alarm()
{
    if(Warning)
        cout<<"WARNING :The Full On Weight exceeds The Maximum Weight"<<endl;
}
void Journey::set_Journey_ID(int Journey_ID)
{
    this->Journey_ID=Journey_ID;
}
void Journey::set_Transportation_ID(int Transportation_ID)
{
    this->Transportation_ID=Transportation_ID;
}
void Journey::set_is_Transportation_Type_For_People(LinkedListTemplate<Transport> TList)
{

    if(TList.isEmpty())
    {
        cout<<"No Transportation is Available Now"<<endl;
        return;
    }

    while(TList.get_Curr()!=NULL&&get_Transportation_ID()< TList.get_Curr()->getData()->get_ID())
    {
        TList.iterate_Curr();
    }
    if(TList.get_Curr()!=NULL&&get_Transportation_ID()== TList.get_Curr()->getData()->get_ID()&&TList.get_Curr()->getData()->get_is_for_Shipping()==0)
    {
        is_Transportation_Type_For_People=1;
        return;
    }
    is_Transportation_Type_For_People=0;
    return;
}
void Journey::set_Journey_Date(Date Journey_Date)
{
    this->Journey_Date.SetDay(Journey_Date.GetDay());
    this->Journey_Date.SetMonth(Journey_Date.GetMonth());
    this->Journey_Date.SetYear(Journey_Date.GetYear());
}
void Journey::set_From(string From)
{
    strcpy( this->From,From.c_str());
}
void Journey::set_To(string To)
{
     strcpy( this->To,To.c_str());
}
void Journey::set_Journey_Booking_Record(Booking_record Journey_Booking_Record)
{
    this->Journey_Booking_Record=Journey_Booking_Record;
}
void Journey::set_Journey_Carry_On_Weight(double Journey_Carry_On_Weight)
{
    if(!is_Transportation_Type_For_People)
    {
        this->Journey_Carry_On_Weight=Journey_Carry_On_Weight;
        return;
    }

    cout<<"The Transportation is for passengers so it cannot have a Carry on Weight directly From user..instead it will get it from the Booking record"<<endl;
    Journey_Carry_On_Weight=Journey_Booking_Record.get_Full_Weight();
}
void Journey::set_Warning(LinkedListTemplate<Transport> TList)
{
    TList.reset_Curr();
    while((TList.get_Curr()!=NULL)&&(Transportation_ID< TList.get_Curr()->getData()->get_ID()))
    {
        TList.iterate_Curr();
    }
    if((TList.get_Curr()!=NULL&&Transportation_ID== TList.get_Curr()->getData()->get_ID())&&TList.get_Curr()->getData()->get_Maximum_Weight()<Journey_Full_On_Weight)
        Warning=1;
}
int Journey::get_ID()
{
    return Journey_ID;
}
int Journey::get_Transportation_ID()
{
    return Transportation_ID;
}
bool Journey::get_is_Transportation_Type_For_People()
{
    return is_Transportation_Type_For_People;
}
Date Journey::get_Journey_Date()
{
    return Journey_Date;
}
Booking_record Journey::get_Booking_Record()
{
    return Journey_Booking_Record;
}
double Journey::get_Journey_Carry_On_Weight()
{
    return Journey_Carry_On_Weight;
}
double Journey::get_Journey_Full_On_Weight()
{
    return Journey_Full_On_Weight;
}
bool Journey::get_Warning()
{
    return Warning;
}
void Journey::print()
{
    cout<<"the journey ID is:"<<Journey_ID<<endl;
    cout<<"the transportation ID is:"<<Transportation_ID<<endl;
    cout<<"the details of transportation are :"<<endl;
    if(is_Transportation_Type_For_People)
        cout<<"This is A passengers Transport"<<endl;
    else
        cout<<"This is A shipping Transport"<<endl;
    Journey_Date.print_Date();
    cout<<"the journey is from : "<<From<<endl;
    cout<<"the journey is to :"<<To<<endl;
    Journey_Booking_Record.print_Booking_record();
    cout<<"the carry on weight :"<<Journey_Carry_On_Weight<<endl;
    cout<<"the full on weight :"<<Journey_Full_On_Weight<<endl;
    Warning_Alarm();

}
