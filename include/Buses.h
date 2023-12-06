#ifndef BUSES_H
#define BUSES_H
#include "Wilderness.h"
#include "Date.h"

class Buses:public Wilderness
{
private:
    int Num_Of_Seats;
public:
    Buses();
    Buses(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,float Engine_Displacement,float Length,int Num_of_Seats);
    Buses(Buses &ob);
    void set_Num_of_Seats(int Num_of_Seats);
    int  get_Num_Of_seats();
    void print();
    void input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList);
};

#endif // BUSES_H
