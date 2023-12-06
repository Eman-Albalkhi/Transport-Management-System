#ifndef TRUCKS_H
#define TRUCKS_H
#include "Wilderness.h"

class Trucks:public Wilderness
{
private:
    float Empty_Weight;
    float Maximum_Weight;
    float Goods_Height;
public:
    Trucks();
    Trucks(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,float Engine_Displacement,float Length,float Goods_Height);
    Trucks(Trucks &ob);
    void  set_Empty_Weight(float Empty_Weight);
    void  set_Goods_Height(float Goods_Height);
    void  set_Maximum_Weight(float Empty_Weight);
    float get_Empty_Weight();
    float get_Maximum_Weight();
    float get_Goods_Height();
    void print();
    void input(LinkedListTemplate<Transport>,LinkedListTemplate<Journey>);

};

#endif // TRUCKS_H
