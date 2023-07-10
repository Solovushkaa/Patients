#include <iostream>
#include "mysql.h"
#include <vector>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
#include "DataExtraction.h"



using namespace std;

int main()
{
    string in;
    cin >> in;
    ifstream fin(in);
    vector<DataExtraction> row;
    istringstream input();
    for (long long x; input >> x;) row.push_back(x);
    if (!row.empty())
        .push_back(row);
    fin.close();
}

    /*MYSQL* mysql = mysql_init(NULL);
    mysql_real_connect(mysql, "localhost", "root", "1234", "patients", 3306, NULL, 0);
    std::cout << mysql_character_set_name(mysql) << "\n";
    mysql_query(mysql, "insert into patientsdata values (2, \"KUK\", \"OLD\", \"1995-05-12\", 28, \"+71234544412\")");
    mysql_query(mysql, "CREATE DATABASE pencil");
    mysql_query(mysql, "DROP DATABASE pencil");*/