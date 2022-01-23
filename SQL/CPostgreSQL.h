#pragma once
#include <string>
#include <vector>
#include "CSQL.h"
#include "libpq-fe.h"


#pragma comment(lib, "libpq.lib")

class CPostgreSQL :
    public CSQL
{
private:
    PGconn* m_pConnection;
    std::string m_sLastErrorStatement;
public:
    CPostgreSQL();
    ~CPostgreSQL();

    const char* GetLastErrorStatement();
    bool ConnectDatabase(std::string);
    void DisconnectDatabase();
    std::vector<std::vector<std::string>> GetDataFromDatabase(std::string);
};

