#ifndef ROW_H
#define ROW_H
#include <string>
#include <iostream>

using namespace std;
class row // Organizacja strukt bazy danych
{
public:
    string name;
    string place;
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int duration;

    friend ostream& operator<<(ostream &o, const row& r){
        o << r.name;
        o << r.place;
        o << r.year;
        o << r.month;
        o << r.day;
        o << r.hour;
        o << r.minutes;
        o << r.duration;
        return o;
    }

    friend istream& operator>>(istream &o, row& r){
        o >> r.name;
        o >> r.place;
        o >> r.year;
        o >> r.month;
        o >> r.day;
        o >> r.hour;
        o >> r.minutes;
        o >> r.duration;
        return o;
    }

};

#endif // ROW_H

