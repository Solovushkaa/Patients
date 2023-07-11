#include <iostream>
#include "mysql.h"
#include <list>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
#include "DataExtraction.h"

int main()
{
    //std::string in;
    //std::cin >> in;
    std::ifstream fin("input.txt");
    std::list<DataExtraction> a;
    for (std::string s; getline(fin, s);)
    {
        DataExtraction b{ s };
            a.push_back(b);
    }
    for (DataExtraction x : a)
        std::cout << x << "\n";
}

    /*MYSQL* mysql = mysql_init(NULL);
    mysql_real_connect(mysql, "localhost", "root", "1234", "patients", 3306, NULL, 0);
    std::cout << mysql_character_set_name(mysql) << "\n";
    mysql_query(mysql, "insert into patientsdata values (2, \"Gleb\", \"Glebov\", \"1995-05-12\", 28, \"+71234544412\")");
    mysql_query(mysql, "CREATE DATABASE pencil");
    mysql_query(mysql, "DROP DATABASE pencil");*/