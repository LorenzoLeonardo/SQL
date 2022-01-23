#include "CPostgreSQL.h"

CPostgreSQL::CPostgreSQL():m_pConnection(NULL)
{

}
CPostgreSQL::~CPostgreSQL()
{

}

bool CPostgreSQL::ConnectDatabase(std::string sStatement)
{
    m_pConnection = PQconnectdb(sStatement.c_str());

    if (PQstatus(m_pConnection) != CONNECTION_OK) {
        m_sLastErrorStatement = PQerrorMessage(m_pConnection);
        return false;
    }
    return true;
}
void CPostgreSQL::DisconnectDatabase()
{
    if(m_pConnection!=NULL)
        PQfinish(m_pConnection);
}
const char* CPostgreSQL::GetLastErrorStatement()
{
    return m_sLastErrorStatement.c_str();
}

std::vector<std::vector<std::string>> CPostgreSQL::GetDataFromDatabase(std::string sStatement)
{
    PGresult* pResult = NULL;
    int nFields = 0;
    std::vector<std::vector<std::string>> vData;
    std::vector<std::string> vRow;

    vData.clear();

    pResult = PQexec(m_pConnection, sStatement.c_str());

    ExecStatusType exStatus = PQresultStatus(pResult);

    if (exStatus != PGRES_TUPLES_OK)
    {
        m_sLastErrorStatement = PQerrorMessage(m_pConnection);
        return vData;
    }

    nFields = PQnfields(pResult);
   
    for (int i = 0; i < nFields; i++)
        vRow.push_back(PQfname(pResult, i));
    vData.push_back(vRow);

    for (int i = 0; i < PQntuples(pResult); i++)
    {
        vRow.clear();
        for (int j = 0; j < nFields; j++)
        {
            vRow.push_back(PQgetvalue(pResult, i, j));
        }
        vData.push_back(vRow);
    }

    PQclear(pResult);
    return vData;
}