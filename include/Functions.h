#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Trucks.h"
#include "Buses.h"
#include "Passenger_Plane.h"
#include "Cars.h"
#include"Shipping_Plane.h"
#include "LinkedListTemplate.h"
#include "Transport_File_Handler.h"
#include "Journey_File_Handler.h"
bool Date_cmp(Date A,Date B);
void print_journeys_between_places(string To,string From,int ID,LinkedListTemplate<Journey> JList);
int print_between_dates(Date Start,Date End,int ID,LinkedListTemplate<Journey> JList);
void print_journey(int ID,LinkedListTemplate<Journey>   JList);
void print_menu();
#endif // FUNCTIONS_H
