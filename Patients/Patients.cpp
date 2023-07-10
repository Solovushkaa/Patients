#include <iostream>
#include "mysql.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	system("cls");

	MYSQL* mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;

	int i = 0;

	// Получаем дескриптор соединения
	mysql = mysql_init(NULL);
	if (mysql == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");
		//exit(1); //Если используется оконное приложение
	}
	// Подключаемся к серверу
	if (!mysql_real_connect(mysql, "localhost", "root", "1234", "patients", 3306, NULL, 0))
	{
		// Если нет возможности установить соединение с сервером
		// базы данных выводим сообщение об ошибке
		fprintf(stderr, "Error: can'tconnecttodatabase %s\n", mysql_error(mysql));
	}
	else
	{
		// Если соединение успешно установлено выводим фразу - "Success!"
		fprintf(stdout, "Success!\n");
	}

	//mysql_set_character_set(mysql, "utf8mb4");
	////Смотрим изменилась ли кодировка на нужную, по умалчанию идёт latin1
	//cout << "connectioncharacterset: " << mysql_character_set_name(mysql) << endl;

	mysql_query(mysql, "SELECT 1, text FROM patientsdata"); //Делаем запрос к таблице по имени МНУ =)

	if (res = mysql_store_result(mysql)) {
		while (row = mysql_fetch_row(res)) {
			for (i = 0; i < mysql_num_fields(res); i++) {
				std::cout << row[i] << "\n"; //Выводим все что есть в базе через цикл
			}
		}
	}
	else fprintf(stderr, "%s\n", mysql_error(mysql));

	// Закрываем соединение с сервером базы данных
	mysql_close(mysql);

	system("Pause");

	return 0;
}


    /*MYSQL* mysql = mysql_init(NULL);
    mysql_real_connect(mysql, "localhost", "root", "1234", "patients", 3306, NULL, 0);
    std::cout << mysql_character_set_name(mysql) << "\n";
    mysql_query(mysql, "insert into patientsdata values (2, \"KUK\", \"OLD\", \"1995-05-12\", 28, \"+71234544412\")");
    mysql_query(mysql, "CREATE DATABASE pencil");
    mysql_query(mysql, "DROP DATABASE pencil");*/
//леша пидорас