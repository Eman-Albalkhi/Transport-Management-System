#ifndef PASSENGER_PLANE_H
#define PASSENGER_PLANE_H
#include "Aerial.h"

class Passenger_Plane:public Aerial
{
private:
    int Num_Of_Seats;
    int Maximum_Luggage_Weight;
public:
    Passenger_Plane();
    Passenger_Plane(float Transport_Weight,float Maximum_Weight,long int Transport_ID,string Transport_Maker,Date Making_Date,float Transport_Speed,bool is_KM,int Private_or_Governor_or_International,bool is_for_Shipping,int Num_Of_Engines,float Length,int Num_Of_Seats,float Maximum_Luggage_Weight);
    Passenger_Plane(Passenger_Plane &ob);
    void    set_Num_of_Seats(int Num_Of_Seats);
    void    set_Maximum_Luggage_Weight(int Maximum_Luggage_Weight);
    int     get_Num_Of_seats();
    int     get_Maximum_Luggage_Weight();
    void print();
    void input(LinkedListTemplate<Transport> TList,LinkedListTemplate<Journey> JList);
};

#endif // PASSENGER_PLANE_H
