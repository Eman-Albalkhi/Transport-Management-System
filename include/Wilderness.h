#ifndef WILDERNESS_H
#define WILDERNESS_H
#include "Transport.h"

class Wilderness:public Transport
{
protected:
    float Engine_Displacement;
    float Length;
public:
    Wilderness();
    Wilderness(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,float Engine_Displacement,float Length);
    void  set_Engine_Displacement(float Engine_Displacement);
    void  set_Length(float Length);
    float get_Engine_Displacement();
    float get_Length();
    virtual void print();
    virtual void input(LinkedListTemplate<Transport>,LinkedListTemplate<Journey>);
};

#endif // WILDERNESS_H
