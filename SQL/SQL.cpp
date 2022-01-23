// SQL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CPostgreSQL.h"

int main()
{
    CPostgreSQL sql;

    
    if (!sql.ConnectDatabase("host=localhost port=5432 dbname=TestDB user=postgres password=1234"))
    {
        printf("%s", sql.GetLastErrorStatement());
        return 0;
    }

    std::string statement = "select * from Test_Table";

    std::vector<std::vector<std::string>> vData;
    vData = sql.GetDataFromDatabase(statement);
    if (vData.empty())
    {
        printf("%s", sql.GetLastErrorStatement());
        return 0;
    }

    for (int i = 0; i < vData.size(); i++)
    {
        for (int j = 0; j < vData[i].size(); j++)
        {
            printf("%s\t", vData[i][j].c_str());
        }
        printf("\r\n");
    }

    sql.DisconnectDatabase();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
