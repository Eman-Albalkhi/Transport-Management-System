#ifndef DATE_H
#define DATE_H


class Date
{
private:
    int Day,Month,Year;
public:
    Date();
    Date(int,int,int);
    Date(Date &ob);
    void SetDay(int);
    void SetMonth(int);
    void SetYear(int);
    int GetDay();
    int GetMonth();
    int GetYear();
    void input_Date();
    void print_Date();

};

#endif // DATE_H
