#ifndef AERIAL_H
#define AERIAL_H
#include "Transport.h"

class Aerial:public Transport
{
protected:
    int Num_Of_Engines;
    float Length;
public:
    Aerial();
    Aerial(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,int Num_Of_Engines,float Length);
    void set_Num_of_Engines(int Num_Of_Engines);
    void set_Length(float Length);
    int get_Num_Of_Engines();
    float get_Length();
    virtual void print();
    virtual void input(LinkedListTemplate<Transport>,LinkedListTemplate<Journey>);
};

#endif // AERIAL_H
