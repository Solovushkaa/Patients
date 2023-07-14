#include "My_fun_for_MYSQL.h"

void pull_data(std::list<DataExtraction>& a, const std::string& input) 
{
    std::ifstream fin(input);
    for (std::string s; getline(fin, s);)
    {
        try {
            DataExtraction b{s};
            a.push_back(b);
        }
        catch (DataExtractionException) {}
    }
    fin.close();
}

void show_data_from_cont(std::list<DataExtraction>& a) 
{
    for (DataExtraction x : a)
        std::cout << x << "\n";
}

void create_db(MYSQL* mysql, const std::string& db)
{
    mysql_query(mysql, ("CREATE DATABASE " + db + ';').c_str());
}

void delete_db(MYSQL* mysql, const std::string& db)
{
    mysql_query(mysql, ("DROP DATABASE " + db + ';').c_str());
}

MYSQL* connect_to_DB(const std::string& host1, const std::string& user1,
    const std::string& passwd1, const std::string& db1, const unsigned int port1, const unsigned long clientflag1)
{
    MYSQL* mysql = mysql_init(NULL);
    mysql_real_connect(mysql, host1.c_str(), user1.c_str(), passwd1.c_str(), db1.c_str(), port1, NULL, clientflag1);
    return mysql;
}

void add_table_to_db(MYSQL* mysql_con, const std::string& name_table)
{
    mysql_query(mysql_con, ("create table " + name_table + "(id int NOT NULL AUTO_INCREMENT, name varchar(20), surname varchar(20), birthdate date, age int(3), phonenumber varchar(12), primary key(id));").c_str());
}

void delete_table_from_db(MYSQL* mysql_con, const std::string& name_table)
{
    mysql_query(mysql_con, ("drop table " + name_table + ';').c_str());
}

void add_data_to_db(MYSQL* mysql, std::list<DataExtraction>& pull_d, const std::string& table_name)
{
    for (const DataExtraction& row : pull_d)
    {
        mysql_query(mysql, ("insert into " + table_name + " (name, surname, birthdate, age, phonenumber) values " +
            "(\"" + row.get_nm() + "\", " + "\"" + row.get_surnm() + "\", " + "\"" + row.get_birth() + "\", " + row.get_age() + ", " + "\"" + row.get_phonenum() + "\");").c_str());
    }
    
}

void add_data_to_db(MYSQL* mysql, DataExtraction pull_d, const std::string& table_name)
{
    mysql_query(mysql, ("insert into " + table_name + " (name, surname, birthdate, age, phonenumber) values " + 
        "(\"" + pull_d.get_nm() + "\", " + "\"" + pull_d.get_surnm() + "\", " + "\"" + pull_d.get_birth() + "\", " + pull_d.get_age() + ", " + "\"" + pull_d.get_phonenum() + "\");").c_str());
}