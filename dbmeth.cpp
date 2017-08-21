#include "dbmeth.h"
#include <cstdio>
#include "czas.h"

using namespace std;


dbmeth::dbmeth()
{
}

void dbmeth::Add(row r){
    long int index;
    czas cz;
    cz.year=r.year;
    cz.month=r.month;
    cz.day=r.day;
    cz.hour=r.hour;
    cz.min=r.minutes;
    index= cz.GetUnixTime(cz);
    Row.insert(pair<long int,row>(index,r));
}

row dbmeth::GetRow(long int index){
    row r;
    if(Row.count(index)){
        ite= Row.find(index);
        r=ite->second;
        return r;
    }
    else{
        cout<<"No rows having this index\n";
    }
}

void dbmeth::DelRow(long index){
    if(Row.count(index)){
        ite= Row.find(index);
        Row.erase(ite);
        cout<<"Usunieto ";
    }
    else{
        cout<<"No rows have this index\n";
    }
}

void dbmeth::SetRow(){
    row r;
    cout<<"Prosze wpisac rok, miejsciac, dzien, godziny, minuty ta trwalosc wydarzenia"<<endl;
    cin>>r.year>>r.month>>r.day>>r.hour>>r.minutes>>r.duration;
    cout<<"Prosze wpisac nazwe wydarzenia"<<endl;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,r.name);
    cout<<"Prosze wpisac nazwe wydarzenia"<<endl;
    getline(cin,r.place);
    Add(r);
}

void dbmeth::EditRow(long index, int field){
    row r;
    int value;
    string svalue;
    cout<<"Prosze wpisac wartosc"<<endl;
    r=GetRow(index);
    switch(field){
    case 1:
        cin>>value;
        r.year=value;
        break;
    case 2:
        cin>>value;
        r.month=value;
        break;
    case 3:
        cin>>value;
        r.day=value;
        break;
    case 4:
        cin>>value;
        r.hour=value;
        break;
    case 5:
        cin>>value;
        r.minutes=value;
        break;
    case 6:
        cin>>value;
        r.duration=value;
        break;
    case 7:
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,svalue);
        r.name=svalue;
        break;
    case 8:
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,svalue);
        r.place=svalue;
        break;
    default:
        cout<<"Error of field number\n";
        break;
    }
    DelRow(index);
    Add(r);
}

void dbmeth::ShowDB(){
    cout<<mes<<endl;
    for(ite=Row.begin();ite != Row.end();ite++){
        FormatShowRow(ite);
    }
}

void dbmeth::FormatShowRow(multimap<long int,row>::iterator ite){
    row r;
    r=ite->second;
    cout<<"| "<<r.year<<".";
    if(r.month<10){
        cout<<"0";
    }
    cout<<r.month<<".";
    if(r.day<10){
        cout<<"0";
    }
    cout<<r.day<<" | ";
    if(r.hour<10){
        cout<<"0";
    }
    cout<<r.hour<<":";
    if(r.minutes<10){
        cout<<"0";
    }
    cout<<r.minutes<<" | ";
    if(r.duration>10000){
        cout<<r.duration<<" | ";
    } else{
        cout<<r.duration<<"\t | ";
    }
    cout<<r.name<<"\t | ";
    cout<<r.place<<" "<<endl;
}

void dbmeth::ShowDay(czas cz){
    bool b=false;
    cout<<mes<<endl;
    for(ite=Row.begin();ite!=Row.end();ite++){
        if(ite->second.year==cz.year && ite->second.month==cz.month && ite->second.day==cz.day){
            FormatShowRow(ite);
            b=true;
        }
    }
    if(!b) cout<<"Rows not found";
}

void dbmeth::ShowNearest(multimap<long int,row> &Row){
    if(Row.size()!=0){
        czas cz;
        row r;
        bool b =false;
            for(ite=Row.begin();!b;ite++){
                if(ite->first<cz.secfrom70){ continue;}
                else{
                    r=ite->second;
                    b=true;
                }
        }
        cout<<"Najblizsze wydarzenie: "<<r.name<<r.day<<" dnia "<<r.month<<" miesiaca o"<<r.hour<<" godzinie "<<r.minutes<<" minut"<<endl;
    }else{
        cout<<"Zadnyczh najblizszyh wydarzen"<<endl;
    }
}

void dbmeth::Nakladki(){
    long int mdur;
    multimap<long int,row>::iterator it;
    for(ite=Row.begin();ite!=Row.end();ite++){
        mdur=ite->first+(ite->second.duration*60);
        for(it=Row.begin();it!=Row.end();it++){
            if(it==ite){
                continue;
            }
            if(it->first<mdur && it->first>ite->first) {
                cout<<"Wydarzenie przekrywa "<<ite->second.name<<" ta "<<it->second.name<<endl;
            }
        }
    }
}

void dbmeth::PastTransfer(multimap<long int,row>::iterator ite){
    czas cz;
    row r;
    cz.hour=0;
    cz.min=0;
    long int now;
    int var=0;
    now=cz.secfrom70;
        if(ite->first<now){
            cout<<"Przeniesc wydarzenie? Nacisnij 1, zeby przeniesc wydarzenie, albo ono bedzie usuniete."<<endl;
            FormatShowRow(ite);
            cin>>var;
            switch (var) {
            case 1:
                r=ite->second;
                cout<<"Prosze wpisac nowej daty: rok, miesiac, dzien, czas, trwalosc \n";
                cin>>r.year>>r.month>>r.day>>r.hour>>r.minutes>>r.duration;
                Add(r);
                DelRow(ite->first);
                break;
            default:
                DelRow(ite->first);
                break;
            }
        }
}

void dbmeth::Transfer(){
    for(ite=Row.begin();ite!=Row.end();ite++){
        PastTransfer(ite);
    }
}

