#ifndef TRANSPORT_FILE_HANDLER_H
#define TRANSPORT_FILE_HANDLER_H
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>
#include <strings.h>
#include <stdlib.h>
#include "Transport.h"
#include "Cars.h"
#include "Shipping_Plane.h"
#include "Passenger_Plane.h"
#include "Trucks.h"
#include "Buses.h"
#include <typeinfo>
using namespace std;
class Int
{
private:
    int a;
public:
    Int()
    {
        a=0;
    }
    Int(int a)
    {
        this->a=a;
    }
    void seta(int a)
    {
        this->a=a;
    }
    int geta()
    {
        return a;
    }

};
class Transport_File_Handler
{
private:
    Int type;
    fstream Transport_File_Operator;
    Transport *temp;
    Cars C;
    Trucks T;
    Shipping_Plane S;
    Passenger_Plane P;
    Buses B;
    string Filename="Transports.bin";
public:
    bool File_Is_OK()
    {
        if(Transport_File_Operator.is_open())
            return true;
        return false;
    }
    void Transport_LinkedList_Adder(LinkedListTemplate<Transport> TList)
    {
        Transport_File_Operator.open("Transports.bin",ios::binary|ios::in);
        while(!Transport_File_Operator.eof())
        {
            Transport_File_Operator.read((char*)&type,sizeof(int));
            if(type.geta()==1)
            {
                Transport_File_Operator.read((char*)&C,sizeof(Cars));
                temp=new Cars(C);
            }

            else if (type.geta()==2)
            {
                Transport_File_Operator.read((char*)&T,sizeof(Trucks));
                temp=new Trucks(T);
            }

            else if (type.geta()==3)
            {
                Transport_File_Operator.read((char*)&B,sizeof(Buses));
                temp=new Buses(B);
            }

            else if (type.geta()==4)
            {
                Transport_File_Operator.read((char*)&S,sizeof(Shipping_Plane));
                temp=new Shipping_Plane(S);
                S.print();
            }

            else if (type.geta()==5)
            {
                Transport_File_Operator.read((char*)&P,sizeof(Passenger_Plane));
                temp=new Passenger_Plane(P);
            }
            //temp->print();
            TList.insertNewNode(temp);
        }
        Transport_File_Operator.close();
    }
    void Transport_LinkedList_Reader(LinkedListTemplate<Transport> TList)
    {
        Transport_File_Operator.open("Transports.bin",ios::binary|ios::out);
        TList.reset_Curr();
        while(TList.get_Curr()!=NULL)
        {
            temp=TList.get_Curr()->getData();
            TList.iterate_Curr();

            switch ( temp->get_Name().at(0))
            {
            case 'P':
                type.seta(1);
                Transport_File_Operator.write((char*)&type,sizeof(Int));
                Transport_File_Operator.write((char*)temp,sizeof(Cars));
                break;
            case 'T':
                type.seta(2);
                Transport_File_Operator.write((char*)&type,sizeof(Int));
                Transport_File_Operator.write((char*)temp,sizeof(Trucks));
                break;
            case 'B':
                type.seta(3);
                Transport_File_Operator.write((char*)&type,sizeof(Int));
                Transport_File_Operator.write((char*)temp,sizeof(Buses));
                break;
            case 'A':
                type.seta(4);
                Transport_File_Operator.write((char*)&type,sizeof(Int));
                Transport_File_Operator.write((char*)temp,sizeof(Passenger_Plane));
                break;
            case 'S':
                type.seta(5);
                Transport_File_Operator.write((char*)&type,sizeof(Int));
                Transport_File_Operator.write((char*)temp,sizeof(Shipping_Plane));
                break;
            }
        }
        Transport_File_Operator.close();
    }


};



#endif // TRANSPORT_FILE_HANDLER_H
