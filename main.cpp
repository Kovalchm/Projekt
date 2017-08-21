#include <iostream>
#include "row.h"
#include "dbio.h"
#include "dbmeth.h"
#include <stdlib.h>
#include <string>
#include "czas.h"

using namespace std;

int main()
{
    czas cz;
    string tms="Czas biezacy:";

    string mes=" 1: Dodac zapis\n 2: Przeniesc wydazenie z przeszlej daty\n 3: Obejrzec wydazenie na wybrano date \n 4: Usunac zapis\n 5: Zapisz jako\n 6: Redagowanie zapisu\n 8: Zobaczyc wszystie zapisy\n 7: Wyjscie\n Abrakadabra: pusty ekran\n";
    cout<<mes;
    dbmeth db;
    dbio dio;
    long int ind,field;
    char choice;

    dio.Read(db.Row);
    db.ShowNearest(db.Row);
    db.Nakladki();

    for(int i=0;true;i++){
        cout<<"Prosze wybrac opcje"<<endl;
        cin>>choice;
     switch(choice){
            case '1':
                db.SetRow();
                break;
            case '2':
                db.Transfer();
                break;
            case '3':
                cz.SetVars();
                db.ShowDay(cz);
                break;
            case '4':
                ind=cz.DateToUnix();
                db.DelRow(ind);
                break;
            case '5':
                dio.Write(db.Row);
                break;
            case '6':
                ind=cz.DateToUnix();
                cout<<"1: Rok 2: Miesiac 3: Dzien 4: Godzine  5: Minute 6: Trwalosc  7: Nazwa wydarzenia 8: Miejsce"<<endl;
                cin>>field;
                db.EditRow(ind,field);
                break;
            case '7':
                exit(0);
                break;
            case '8':
                db.ShowDB();
                break;
            default:
                if (system("clear")) system( "cls" );
                cout<<mes;
                db.Nakladki();
                break;
        }
    }
}
