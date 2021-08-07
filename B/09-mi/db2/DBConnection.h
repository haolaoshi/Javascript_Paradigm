#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <cassert>
#include <string>
#include "Countable.h"
#include "Database.h"

using std::string;

class DBConnection : public Database , public Countable {
    DBConnection(const DBConnection&) ;
    DBConnection& operator=(const DBConnection&);
protected:
    DBConnection(const string& dbstr) throw (DatabaseError)
        :Database(dbstr){ open();}
    ~DBConnection(){close();}
public:
    static DBConnection*
    create(const string&  dbstr) throw(DatabseError){
        DBConnection* conn = new DBConnection(dbstr);
        conn->attach();
        assert(conn->refCount() == 1);
        return conn;
    }
};

#endif
