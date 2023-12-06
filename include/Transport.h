#ifndef TRANSPORT_H
#define TRANSPORT_H
#include "Date.h"
#include <string.h>
#include<iostream>
#include<LinkedListTemplate.h>
#include "Journey.h"
using namespace std;
class Journey;
class Transport
{
protected:
    long int Transport_ID;
    char Transport_Maker[99];
    Date   Making_Date;
    float Transport_Speed;
    bool is_KM;
    int Private_or_Governor_or_International;
    bool is_for_Shipping;
    char Name[6];
    float Transport_Weight,Maximum_Weight;
public:
    Transport();
    Transport(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping);

    void     set_Transport_ID(long int Transport_ID);
    void     set_Transport_Maker(string Transport_Maker);
    void     set_Transport_Making_Date(Date Making_Date);
    void     set_Transport_Speed(float Transport_Speed);
    void     set_is_KM(bool is_KM);
    void     set_Private_or_Governor_or_International(int Private_or_Governor_or_International);
    void     set_is_for_Shipping(bool is_for_Shipping);
    long int get_ID();
    string   get_Transport_Maker();
    string   get_Name();
    Date     get_Transport_Making_Date();
    float    get_Transport_Speed();
    bool     get_is_KM();
    int      get_Private_or_Governor_or_International();
    bool     get_is_for_Shipping();
    float    get_Transport_Weight(){return Transport_Weight;}
    virtual void  print();
    virtual void  input(LinkedListTemplate<Transport>,LinkedListTemplate<Journey>);
    virtual int   get_Num_Of_seats(){}
    float         get_Maximum_Weight(){return Maximum_Weight;}
};

#endif // TRANSPORT_H
