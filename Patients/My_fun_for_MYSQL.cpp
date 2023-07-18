#include "My_fun_for_MYSQL.h"

/**
* Чтение данных из файла
\param a Список данных о пациентах
\param input Имя файла
 */
void pull_data(std::list<DataExtraction>& a, const std::string& input)
{
    std::ifstream fin(input);
    for (std::string s; getline(fin, s);)
    {
        try {
            DataExtraction b{ s };
            a.push_back(b);
        }
        catch (DataExtractionException) {}
    }
    fin.close();
}

/**
* Вывод данных о пациенте в консоль
\param a Список данных о пациентах
 */
void show_data_from_cont(std::list<DataExtraction>& a)
{
    for (DataExtraction x : a)
        std::cout << x << "\n";
}

 /**
 * Создание базы данных
 \param mysql Дескриптор БД
 \param db Имя БД
  */
void create_db(MYSQL* mysql, const std::string& db)
{
    mysql_query(mysql, ("CREATE DATABASE " + db + ';').c_str());
}

 /**
 * Удаление базы данных
 \param mysql Дескриптор БД
 \param db Имя БД
  */
void delete_db(MYSQL* mysql, const std::string& db)
{
    mysql_query(mysql, ("DROP DATABASE " + db + ';').c_str());
}

/**
 * Подключение к базе данных
 \param host1 Хост
 \param user1 Имя пользователя
 \param passwd1 Пароль
 \param db1 Имя БД
 \param port1 Порт
 \param clientflag1 
  */
MYSQL* connect_to_DB(const std::string& host1, const std::string& user1,
    const std::string& passwd1, const std::string& db1, const unsigned int port1, const unsigned long clientflag1)
{
    MYSQL* mysql = mysql_init(NULL);
    mysql_real_connect(mysql, host1.c_str(), user1.c_str(), passwd1.c_str(), db1.c_str(), port1, NULL, clientflag1);
    return mysql;
}

/**
 * Добавление таблицы в базу данных
 \param mysql Дескриптор БД
 \param table_name Имя таблицы
  */
void add_table_to_db(MYSQL* mysql, const std::string& table_name)
{
    mysql_query(mysql, ("create table " + table_name + "(id int NOT NULL AUTO_INCREMENT, name varchar(20), surname varchar(20), birthdate date, age int(3), phonenumber varchar(12), primary key(id));").c_str());
}

/**
 * Удаление таблицы из базы данных
 \param mysql Дескриптор БД
 \param table_name Имя таблицы
  */
void delete_table_from_db(MYSQL* mysql, const std::string& table_name)
{
    mysql_query(mysql, ("drop table " + table_name + ';').c_str());
}

/**
 * Добавление данных о пациенте в базу данных(2 и более пациентов)
 \param mysql Дескриптор БД
 \param pull_d Добавляемые данные о пациентах
 \param table_name Имя таблицы
  */
void add_data_to_db(MYSQL* mysql, std::list<DataExtraction>& pull_d, const std::string& table_name)
{
    for (const DataExtraction& row : pull_d)
    {
        mysql_query(mysql, ("insert into " + table_name + " (name, surname, birthdate, age, phonenumber) values " +
            "(\"" + row.get_nm() + "\", " + "\"" + row.get_surnm() + "\", " + "\"" + row.get_birth() + "\", " + row.get_age() + ", " + "\"" + row.get_phonenum() + "\");").c_str());
    }

}

/**
 * Добавление данных о пациенте в базу данных(1 пациент)
 \param mysql Дескриптор БД
 \param pull_d Добавляемые данные о пациенте
 \param table_name Имя таблицы
  */
void add_data_to_db(MYSQL* mysql, DataExtraction pull_d, const std::string& table_name)
{
    mysql_query(mysql, ("insert into " + table_name + " (name, surname, birthdate, age, phonenumber) values " +
        "(\"" + pull_d.get_nm() + "\", " + "\"" + pull_d.get_surnm() + "\", " + "\"" + pull_d.get_birth() + "\", " + pull_d.get_age() + ", " + "\"" + pull_d.get_phonenum() + "\");").c_str());
}

/**
 * Извлечение информации из базы данных
 \param mysql Дескриптор БД
 \return Контейнер данных о пациентах
  */
std::list<DataExtraction>& pull_data_from_db(MYSQL* mysql)
{
    std::list<DataExtraction> a;
    MYSQL_RES* res = mysql_store_result(mysql);
    MYSQL_ROW row; 
    if (mysql_num_rows(res) > 0)
    { 
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            DataExtraction b{row};
            a.push_back(b);
        }
    }
    mysql_free_result(res);
    return a;
}