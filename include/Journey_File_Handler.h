#ifndef JOURNEY_FILE_HANDLER_H
#define JOURNEY_FILE_HANDLER_H
#include "Journey.h"
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Journey_File_Handler
{
private:
    fstream Journey_File_Operator;
    Journey temp;
    string Filename="Journeys.bin";
public:
    bool File_Is_OK()
    {
        if(Journey_File_Operator.is_open())
            return true;
        return false;
    }
    void Journey_LinkedList_Adder(LinkedListTemplate<Journey> JList)
    {
        Journey_File_Operator.open("Journeys.bin",ios::binary|ios::in);
        while(!Journey_File_Operator.eof())
        {
            Journey_File_Operator.read((char*)&temp,sizeof(Journey));
            JList.insertNewNode(&temp);
        }
        Journey_File_Operator.close();
    }
    void Journey_LinkedList_Reader(LinkedListTemplate<Journey> JList)
    {
        Journey_File_Operator.open("Journeys.bin",ios::binary|ios::out);
        JList.reset_Curr();
        while(JList.get_Curr()!=NULL)
        {
            Journey E(*JList.get_Curr()->getData());
            JList.iterate_Curr();
            Journey_File_Operator.write((char*)&E,sizeof(Journey));
        }
        Journey_File_Operator.close();
    }

};

#endif // JOURNEY_FILE_HANDLER_H
