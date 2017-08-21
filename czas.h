#ifndef CZAS_H
#define CZAS_H


class czas// ustalenie daty/czasu
{
public:
    int year;
    int month;
    int day;
    int hour;
    int min;
    int secfrom70;

    czas();
    long int GetUnixTime(czas &A);
    long int DateToUnix();
    void SetVars();

private:
    int GetCurrentTime();
};

#endif // CZAS_H

