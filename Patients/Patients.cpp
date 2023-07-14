#include <iostream>
#include "mysql.h"
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include "DataExtraction.h"
#include "My_fun_for_MYSQL.h"

//int main()
//{
//    std::string input;
//    input = "PatientsTXT.txt"; /*std::cin >> in;*/
//    std::list<DataExtraction> pull_d;
//
//    //вытаскиваем данные из файла
//    pull_data(pull_d, input);
//    show_data_from_cont(pull_d);
//
//    //получаем дескриптор бд
//    MYSQL* mysql = mysql_init(NULL);
//
//    //создание бд
//    std::string db_creation_name;
//    std::cin >> db_creation_name;
//    create_db(mysql, db_creation_name);
//
//    //удаление бд
//    std::string db_delete_name;
//    std::cin >> db_delete_name;
//    delete_db(mysql, db_delete_name);
//
//    //подключение к бд
//    std::string host, user, passwd, db, unix_socket;
//    unsigned int port;
//    unsigned long clientflag;
//    std::cin >> host >> user >> passwd >> db >> port >> unix_socket >> clientflag;//(mysql, "localhost", "root", "1234", "patients", 3306, NULL, 0)
//    MYSQL* mysql_con = connect_to_DB(host, user, passwd, db, port, unix_socket, clientflag);
//    std::cout << mysql_character_set_name(mysql) << "\n";
//
//    //добавление таблиц к бд
//    std::string table_name;
//    std::cin >> table_name;
//    add_table_to_db(mysql_con, table_name);
//
//    //добавление данных в таблицу бд
//    std::string table_name;
//    std::cin >> table_name;
//    add_data_to_db(mysql_con, pull_d, table_name);
//
//    //
//    MYSQL_RES* a = mysql_use_result(mysql_con);
//    
//}

int main()
{
	std::string input;
	input = "patients.txt";
	std::list<DataExtraction> pull_d;
	

	
	//вытаскиваем данные из файла
	pull_data(pull_d, input);
	show_data_from_cont(pull_d);

	MYSQL* mysql = mysql_init(NULL);
	
	//подключение к бд
	std::string A, B, C, D;
    MYSQL* mysql_con = connect_to_DB("localhost", "root", "1234", "", 3306, 0);
    
	
	//создание бд
	std::string db_creation_name = "test";
	create_db(mysql_con, db_creation_name);

	mysql_con = connect_to_DB("localhost", "root", "1234", "test", 3306, 0);

	mysql_set_character_set(mysql_con, "utf8mb4");
	std::cout << mysql_character_set_name(mysql_con) << "\n";

	//добавление таблиц к бд
    std::string table_name = "tst";
	add_table_to_db(mysql_con, "tst");

	//добавление данных в таблицу бд
	add_data_to_db(mysql_con, pull_d, "tst");

	std::cout << mysql_use_result(mysql_con);
}