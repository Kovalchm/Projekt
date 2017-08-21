#ifndef DBMETH_H
#define DBMETH_H
#include "row.h"
#include <map>
#include <string>
#include "czas.h"

class dbmeth // baza danych
{
public:
    dbmeth();
    void SetRow();
    void DelRow(long int index);
    void EditRow(long int index, int field);
    void ShowDB();
    void ShowDay(czas cz);
    void ShowNearest(multimap<long, row> &Row);
    void Nakladki();
    void Transfer();
    multimap<long int,row> Row;

private:
    string mes = "| Data\t     | Czas  | Trwalosc.\t | Nazwa Wydarzenia\t\t\t\t | Miejsce\t";
    row GetRow(long index);
    void Add(row r);
    void PastTransfer(multimap<long, row>::iterator ite);
    void FormatShowRow(multimap<long int,row>::iterator ite);
    multimap<long int,row>::iterator ite;
};

#endif // DBMETH_H

