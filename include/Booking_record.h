#ifndef BOOKING_RECORD_H
#define BOOKING_RECORD_H


class Booking_record
{
private:
    int num_of_seats,num_of_passengers;
    bool *is_taken;
    int *weight_of_luggage;
    int Full_Weight;
public:
    Booking_record();
    Booking_record(int);
    Booking_record(Booking_record &ob);
    int Booking_record_input(int);
    int get_Full_Weight();
    int get_Num_Of_Passengers();
    void print_Booking_record();
};
#endif
