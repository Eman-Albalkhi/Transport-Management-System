#include "Booking_record.h"
#include <iostream>
using namespace std;
Booking_record::Booking_record()
{
    num_of_passengers=num_of_seats=Full_Weight= 0;
}
Booking_record::Booking_record(int num_of_seats)
{
    num_of_passengers=0;
    this->num_of_seats=num_of_seats;
    is_taken=new bool[num_of_seats];
    weight_of_luggage=new int [num_of_seats];
}
Booking_record::Booking_record(Booking_record &ob)
{
    this->num_of_passengers=ob.num_of_passengers;
    this->num_of_seats=ob.num_of_seats;
    this->is_taken=new bool [num_of_seats];
    this->weight_of_luggage=new int [num_of_seats];
    for(int i=0; i<num_of_seats; i++)
    {
        this->is_taken[i]=ob.is_taken[i];
        this->weight_of_luggage[i]=ob.weight_of_luggage[i];
    }
}
int Booking_record::Booking_record_input(int num_of_seats)
{
    int sum=0;
    this->num_of_seats=num_of_seats;
    is_taken = new bool[num_of_seats];
    weight_of_luggage=new int[num_of_seats];
    for(int i=0; i<num_of_seats; i++)
    {
        cout<<"is seat number "<<i<<"Taken ??"<<endl<<"enter 1 if yes,0 if not";
        cin>>is_taken[i];
        if(is_taken[i]==1)
        {
            cout<<"How much weight does this passenger carry ?"<<endl;
            cin>>weight_of_luggage[i];
            sum+=weight_of_luggage[i];
            num_of_passengers++;
        }
    }
    Full_Weight=sum;
    return Full_Weight;
}
int Booking_record::get_Full_Weight()
{
    return Full_Weight;
}
int Booking_record::get_Num_Of_Passengers()
{
    return num_of_passengers;
}
void Booking_record::print_Booking_record()
{
    cout<<"the number of seats :"<<num_of_seats<<endl;
    cout<<"the details of seats are :"<<endl;
    for(int i=0; i<num_of_seats; i++)
    {
        if(is_taken[i])
        {
            cout<<"the luggage weight of seat num :"<<i<<"is :"<<weight_of_luggage[i]<<endl;
        }
    }
    cout<<"the full weight is:"<<Full_Weight<<endl;

}

