#include "dbio.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <map>


using namespace std;// zapis do pliku
dbio::dbio()
{
}

void dbio::Write(multimap<long, row> &Row){
    ofstream fs("db.bin");
    if(fs.is_open()){
        for(multimap<long int,row>::iterator  i = Row.begin(); i != Row.end(); ++i){
            fs << i->second;
        }
        fs.close();
    }
    cout<<"Writing success\n";
}

void dbio::Read(multimap<long, row> &Row){
    ifstream in("db.bin",ios_base::in);
    if(in.is_open()){
        for(multimap<long int,row>::iterator  i = Row.begin(); i != Row.end(); ++i){
            in >> i->second;
        }
        in.close();
        cout<<"Reading success\n";
    }
    else{
        cout<<"Couldn't open file\n";
    }
}

