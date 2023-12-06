#ifndef JOURNEY_H
#define JOURNEY_H
#include "Date.h"
#include "Booking_record.h"
#include <iostream>
#include <strings.h>
#include "Booking_record.h"
#include "Transport.h"
class Transport;
using namespace std;
class Journey
{
private:
    string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
    int Journey_ID;
    int Transportation_ID;
    bool is_Transportation_Type_For_People;
    Date Journey_Date;
    char From[99],To[99];
    Booking_record Journey_Booking_Record;
    double Journey_Carry_On_Weight;
    double Journey_Full_On_Weight;
    bool Warning;
public:
    Journey();
    Journey(int,int,Date,string,string,Booking_record,double,LinkedListTemplate<Transport> A);
    void input(LinkedListTemplate<Transport>);
    void Warning_Alarm();
    void set_Journey_ID(int Journey_ID);
    void set_Transportation_ID(int Transportation_ID);
    void set_is_Transportation_Type_For_People(LinkedListTemplate<Transport>);
    void set_Journey_Date(Date Journey_Date);
    void set_From(string From);
    void set_To(string To);
    void set_Journey_Booking_Record(Booking_record);
    void set_Journey_Carry_On_Weight(double Journey_Carry_On_Weight);
    void set_Journey_Full_On_Weight(LinkedListTemplate<Transport>);
    void set_Warning(LinkedListTemplate<Transport>);
    int get_ID();
    int get_Transportation_ID();
    bool get_is_Transportation_Type_For_People();
    Date get_Journey_Date();
    string get_From(){string a=convertToString(From,sizeof(From));return a; }
    string get_To(){string a=convertToString(To,sizeof(To));return a; }
Booking_record get_Booking_Record();
    double get_Journey_Carry_On_Weight();
    double get_Journey_Full_On_Weight();
    bool get_Warning();
    void input(LinkedListTemplate<Transport>,LinkedListTemplate<Journey>);
    void print();
};

#endif // JOURNEY_H
