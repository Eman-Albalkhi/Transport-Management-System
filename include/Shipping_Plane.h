#ifndef SHIPPING_PLANE_H
#define SHIPPING_PLANE_H
#include "Aerial.h"

class Shipping_Plane:public Aerial
{
public :
    Shipping_Plane();
    Shipping_Plane(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping);
    Shipping_Plane(Shipping_Plane &ob);
    void  set_Empty_Weight(float Empty_Weight);
    void  set_Maximum_Weight(float Maximum_Weight);
    float get_Empty_Weight();
    float get_Maximum_Weight();
    void print();
    void input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList);

};

#endif // SHIPPING_PLANE_H
