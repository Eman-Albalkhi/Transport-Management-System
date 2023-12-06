#include "Functions.h"
using namespace std;
bool Date_cmp(Date A,Date B)
{
    if(A.GetYear()>=B.GetYear())
        return 1;
    if(A.GetYear()==B.GetYear())
        if(A.GetMonth()>=B.GetMonth())
            return 1;
    if(A.GetYear()==B.GetYear()&&A.GetMonth()==B.GetMonth())
        if(A.GetDay()>=B.GetDay())
            return 1;
    return 0;
}
void print_journeys_between_places(string To,string From,int ID,LinkedListTemplate<Journey> JList)
{
    JList.reset_Curr();
    while((JList.get_Curr()!=NULL))
    {
        if((JList.get_Curr()->getData()->get_From()==From)&&(JList.get_Curr()->getData()->get_To()==To)&&(JList.get_Curr()->getData()->get_Transportation_ID()==ID))
            JList.get_Curr()->getData()->print();
        JList.iterate_Curr();
    }
}
int print_between_dates(Date Start,Date End,int ID,LinkedListTemplate<Journey> JList)
{
    Date A,B;
    int sum=0;
    while(JList.get_Curr()!=NULL)
    {
        A=JList.get_Curr()->getData()->get_Journey_Date();
        B=JList.get_Curr()->getData()->get_Journey_Date();
        if(Date_cmp(A,Start)&&!Date_cmp(B,End)&&JList.get_Curr()->getData()->get_Transportation_ID()==ID)
            sum+=JList.get_Curr()->getData()->get_Booking_Record().get_Num_Of_Passengers();
        JList.iterate_Curr();
    }
    return sum;
}
void print_journey(int ID,LinkedListTemplate<Journey>   JList)
{
    JList.reset_Curr();
    while(JList.get_Curr()!=NULL)
    {
        if(JList.get_Curr()->getData()->get_Transportation_ID()==ID)
            JList.get_Curr()->getData()->print();
        JList.iterate_Curr();
    }
}
void print_menu()
{
        cout<<" Please Choose from the Ones Below :"<<endl
        <<    "(1) To Add A Car (2) To Add A Truck (3) To Add A Bus (4) To Add A Shipping Plane (5) To Add A Passenger Plane"<<endl
        <<    "(6) To Add A Journey (7) To Print Journeys Related to A Transport (8) To Print Journeys Between Two Cities"<<endl
        <<    "(9) To Print All Journeys Between 2 Dates (10) To Store LinkedLists On File (11) To Load Them From Files"<<endl
        <<    "(12) To Exit."<<endl;
}
