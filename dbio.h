#ifndef DBIO_H
#define DBIO_H
#include <map>
#include "row.h"
#include "dbmeth.h"

class dbio
{
public:
    dbio();
    void Write(multimap<long int, row> &Row);
    void Read(multimap<long int, row> &Row);

private:

};

#endif // DBIO_H

