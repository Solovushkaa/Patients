#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "mysql.h"
#include "DataExtraction.h"
void pull_data(std::list<DataExtraction>& a, const std::string& input);
void show_data_from_cont(std::list<DataExtraction>& a);

void create_db(MYSQL* mysql, const std::string& db);
void delete_db(MYSQL* mysql, const std::string& db);
MYSQL* connect_to_DB(const std::string& host1, const std::string& user1,
    const std::string& passwd1, const std::string& db1, const unsigned int port1, const unsigned long clientflag1);

void add_table_to_db(MYSQL* mysql_con, const std::string& name_table);
void delete_table_from_db(MYSQL* mysql_con, const std::string& name_table);

void add_data_to_db(MYSQL* mysql, std::list<DataExtraction>& pull_d, const std::string& table_name);
void add_data_to_db(MYSQL* mysql, DataExtraction pull_d, const std::string& table_name);

