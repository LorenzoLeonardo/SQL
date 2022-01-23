#include "CSQL.h"

CSQL::CSQL() :
	m_nRow(0), m_nCol(0)
{

}
CSQL::~CSQL()
{

}
bool CSQL::ConnectDatabase()
{
	return true;
}
void CSQL::DisconnectDatabase()
{

}