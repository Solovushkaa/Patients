#include <iostream>
#include "mysql.h"
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "DataExtraction.h"
#include "My_fun_for_MYSQL.h"

/**
* Получение информации о курсоре
 */
HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE); 
CONSOLE_CURSOR_INFO CursorInfo;

/**
* Определение макросов для клавиш
 */
#define BUTTON_ENTER 13
#define BUTTON_ESCAPE 27
#define BUTTON_UP 72
#define BUTTON_DOWN 80

void DrawMenu(int pos_f);
void DrawEdit(int pos_s);
void DrawArrow(int pos, int pos_if);

int main()
{
    SetConsoleTitle(L"Connect to Host");

    /**
    * Устранение мерцания курсора
     */
    GetConsoleCursorInfo(hstdout, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(hstdout, &CursorInfo);

    int pos_f = 0, pos_s = 0;///< Параметры выбранной строки в меню/подменю
    const int max_pos_f = 1, max_pos_s = 6;///< Их максимальное значение

    DrawMenu(pos_f);
    while (true)
        switch (_getch()) { 
        case BUTTON_ENTER:
            if (pos_f == 0)/// Подключение к БД
            {
                CursorInfo.bVisible = true;
                SetConsoleCursorInfo(hstdout, &CursorInfo);
                system("cls");/// Очистка консоли
                MYSQL* mysql = mysql_init(NULL); /// Получаем дескриптор БД

                std::string A, B, C; unsigned int D, E;
                std::list<DataExtraction> pull_d;

                std::cout << "Enter the data:\n";
                //std::cout << "Host: "; std::cin >> A; std::cout << "\n";
                //std::cout << "User: "; std::cin >> B; std::cout << "\n";
                //std::cout << "Password: "; std::cin >> C; std::cout << "\n";
                //std::cout << "Port: "; std::cin >> D; std::cout << "\n";
                //std::cout << "Client flag: "; std::cin >> E;
                A = "localhost", B = "root", C = "1234";
                D = 3306, E = 0;
                mysql = connect_to_DB(A, B, C, "", D, E);

                system("cls");
                char ver;
                std::cout << "Create new database? Enter Y(y)/N(n): "; std::cin >> ver;
                if (ver == 'Y' || ver == 'y')
                {
                    system("cls");
                    std::string db_creation_name;///< Имя созданной базы данных
                    db_creation_name = "patients"; //std::cout << "Database create name: "; std::cin >> db_creation_name;
                    create_db(mysql, db_creation_name);
                }

                system("cls");
                std::cout << "Enter the database name:\n";
                std::string db_name;///< Имя базы данных
                db_name = "patients"; //std::cout << "Database name: "; std::cin >> db_name;
                mysql = connect_to_DB(A, B, C, db_name, D, E);
                
                system("cls");
                
                std::cout << "Create new table? Enter Y(y)/N(n): "; std::cin >> ver;
                if (ver == 'Y' || ver == 'y')
                {

                    std::cout << "Enter the creation table name:\n";
                    std::string table_creation_name = "patientsdata";
                    //std::cout << "Table creation name: "; std::cin >> table_creation_name;
                    add_table_to_db(mysql, table_creation_name);
                }
                
                system("cls");
                std::cout << "Enter the table name:\n";
                std::string table_name = "patientsdata";
                //std::cout << "Table name: "; std::cin >> table_name;
                system("cls");

                DrawEdit(pos_s);
                bool flag = false;
                pos_s = 0;
                while (true)
                {
                    if (flag == true)
                    {
                        DrawMenu(pos_f = 0);
                        break;
                    }
                    switch (_getch())
                    {
                    case BUTTON_ENTER: // enter
                        CursorInfo.bVisible = true;
                        SetConsoleCursorInfo(hstdout, &CursorInfo);
                        if (pos_s == 0)/// Ввод данных из файла
                        {
                            SetConsoleTitle(L"Add data from \"txt\" file");
                            system("cls");
                            std::string file_name = "patients.txt";
                            std::cout << "Enter the \"txt\" file:\n";
                            //std::cout << "File: "; std::cin >> file_name; std::cout << "\n";
                            pull_data(pull_d, file_name);
                            add_data_to_db(mysql, pull_d, table_name);
                            pull_d.clear();
                        }
                        else if (pos_s == 1)/// Ввод данных из консоли
                        {
                            SetConsoleTitle(L"Add data from console");
                            system("cls");
                            std::string obj;/// Строка для ввода данных
                            while (true)
                            {
                                std::cout << "Enter the information about patient(name, surname, birthdate, age, phonenumber) (press \"e\" to finish):\n";
                                obj = "e"; //std::cout << "Patient: "; std::cin >> obj;
                                if (obj == "e") break;
                                DataExtraction data{ obj };  
                                add_data_to_db(mysql, data, table_name);
                            }
                        }
                        else if (pos_s == 2)/// Вывод данных на экран
                        {
                            SetConsoleTitle(L"Show data from the database");
                            system("cls");
                            pull_d = pull_data_from_db(mysql);
                            show_data_from_cont(pull_d);
                            flag = true;
                        }
                        else if (pos_s == 3)/// Отключение от БД
                        {
                            SetConsoleTitle(L"Disconnect from the Database");
                            system("cls");
                            mysql_close(mysql);
                            std::cout << "Disconnected\n";
                            flag = true;
                            system("pause");
                        }
                        else if (pos_s == 4)/// Удаление таблицы
                        {
                            SetConsoleTitle(L"Delete the table from the Database");
                            system("cls");
                            std::string table_name;
                            std::cout << "Enter the table name:\n";
                            table_name = "patientsdata"; //std::cout << "Table name: "; std::cin >> table_name;
                            delete_table_from_db(mysql, table_name);
                            std::cout << "Table deleted:\n";
                            flag = true;
                            system("pause");
                        }
                        else if (pos_s == 5)/// Удаление БД
                        {
                            SetConsoleTitle(L"Delete the Database");
                            system("cls");
                            delete_db(mysql, db_name);
                            std::cout << "Database deleted:\n";
                            flag = true;
                            system("pause");
                        }
                        else if (pos_s == 6)/// Вернуться в меню
                        {
                            mysql_close(mysql);
                            flag = true;
                        }
                        pos_s = 0;
                        DrawEdit(pos_s);
                        break;

                    case BUTTON_UP: // up
                        if (pos_s > 0)
                            DrawEdit(--pos_s);
                        break;

                    case BUTTON_DOWN: // down
                        if (pos_s < max_pos_s)
                            DrawEdit(++pos_s);
                        break;
                    }
                }
            }
            else if (pos_f == 1)/// Выход
            {
                system("cls");
                return 0;
            }
        case BUTTON_UP: // up
            if (pos_f > 0)
                DrawMenu(--pos_f);
            break;

        case BUTTON_DOWN: // down
            if (pos_f < max_pos_f)
                DrawMenu(++pos_f);
            break;
        }
}

/**
* Отрисовывает работу меню в командной строке
\param pos_f Параметр, значение которого соответствует строке меню
 */
void DrawMenu(int pos_f)
{
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(hstdout, &CursorInfo);
    SetConsoleTitle(L"Menu");
    system("cls");
    std::cout << " Connect";
    DrawArrow(pos_f, 0);
    std::cout << "\n" << " Exit";
    DrawArrow(pos_f, 1);
}

/**
* Отрисовывает работу подменю главного меню
\param pos_s Параметр, значение которого соответствует строке подменю
 */
void DrawEdit(int pos_s)
{
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(hstdout, &CursorInfo);
    SetConsoleTitle(L"Edit");
    system("cls");
    std::cout << " Add data from \"txt\" file";
    DrawArrow(pos_s, 0);
    std::cout << "\n" << " Add data from console";
    DrawArrow(pos_s, 1);
    std::cout << "\n" << " Show data from the database";
    DrawArrow(pos_s, 2);
    std::cout << "\n" << " Disconnect from the database";
    DrawArrow(pos_s, 3);
    std::cout << "\n" << " Delete the table";
    DrawArrow(pos_s, 4);
    std::cout << "\n" << " Delete the database";
    DrawArrow(pos_s, 5);
    std::cout << "\n" << " Back";
    DrawArrow(pos_s, 6);
}

/**
* Выводит "<-" напротив выбранной строки
\param pos, pos_if Параметры сравнения выбранной строки
*/
void DrawArrow(int pos, int pos_if)
{
    if (pos == pos_if)
        printf("<-");
}