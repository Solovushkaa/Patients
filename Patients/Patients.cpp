#include <iostream>
#include "mysql.h"
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <exception>
#include "DataExtraction.h"
#include "My_fun_for_MYSQL.h"

HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

#define BUTTON_ENTER 13
#define BUTTON_ESCAPE 27
#define BUTTON_LEFT 75
#define BUTTON_RIGHT 77
#define BUTTON_UP 72
#define BUTTON_DOWN 80

void DrawLab(int pos);
void DrawArrow(int pos, int posIf);

int main()
{
    MYSQL* mysql = mysql_init(NULL); // получаем дескриптор бд
    MYSQL* mysql_con;
    
    std::string A, B, C; unsigned int D, E;
    std::string table_name;
    std::list<DataExtraction> pull_d;

    SetConsoleTitle(L"Connect to Host");

    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(hstdout, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(hstdout, &CursorInfo);

    bool outputPossible = false;

    //std::cout << "Host: "; std::cin >> A; std::cout << "\n";
    //std::cout << "User: "; std::cin >> B; std::cout << "\n";
    //std::cout << "Password: "; std::cin >> C; std::cout << "\n";
    //std::cout << "Port: "; std::cin >> D; std::cout << "\n";
    //std::cout << "Client flag: "; std::cin >> E; std::cout << "\n";
    A = "localhost", B = "root", C = "1234";
    D = 3306, E = 0;
    mysql = connect_to_DB(A, B, C, "", D, E);

    system("cls");
    std::string db_creation_name;
    db_creation_name = "patients"; //std::cout << "Database create name: "; std::cin >> db_creation_name;
    create_db(mysql, db_creation_name);

    system("cls");
    std::string db_name;
    db_name = "patients"; //std::cout << "Database name: "; std::cin >> db_name;
    mysql_con = connect_to_DB(A, B, C, db_name, D, E);


    int pos = 0;
    const int maxPos = 7;

    DrawLab(pos);
    while (true)
        switch (_getch())
        {
        case BUTTON_ENTER: // enter
        case BUTTON_RIGHT: // right
            if (pos == 0) //добавление таблиц к бд
            {
                SetConsoleTitle(L"Table create");
                system("cls");
                table_name = "patientsdata"; //std::cout << "Table_name: "; std::cin >> table_name;
                add_table_to_db(mysql_con, table_name);
                
            }
            else if (pos == 1)
            {
                SetConsoleTitle(L"Add data from \"txt\" file");
                system("cls");
                std::string file_name;
                file_name = "patients.txt"; //std::cout << "file_name: "; std::cin >> file_name; std::cout << "\n";
                table_name = "patientsdata"; //std::cout << "Table_name: "; std::cin >> table_name;
                pull_data(pull_d, file_name);
                add_data_to_db(mysql_con, pull_d, table_name);
                pull_d.clear();
                system("pause");
            }
            else if (pos == 2)
            {
                SetConsoleTitle(L"Add data from console");
                system("cls");
                std::string obj;
                obj = "Georg Bozhenov 1997-03-05 26 +79547168254"; //std::cout << "Data: "; std::cin >> nm;
                DataExtraction data{obj};
                add_data_to_db(mysql_con, data, table_name);
                system("pause");
            }
            else if (pos == 3)
            {
                SetConsoleTitle(L"Show data from the database");
                system("cls");
                show_pull_data_from_db(mysql_con);
                system("pause");
            }
            else if (pos == 4)
            {
                SetConsoleTitle(L"Disconnect from the Database");
                system("cls");
                disconnect_from_db(mysql_con);
                system("pause");
            }
            else if (pos == 5)
            {
                SetConsoleTitle(L"Delete the table from the Database");
                system("cls");
                std::string table_name;
                table_name = "patientsdata"; //std::cout << "Table name: "; std::cin >> table_name;
                delete_table_from_db(mysql_con, table_name);
                system("pause");
            }
            else if (pos == 6)
            {
                SetConsoleTitle(L"Delete the Database");
                system("cls");
                std::string db_name;
                table_name = "patientsdata"; //std::cout << "Database name: "; std::cin >> db_name;
                delete_db(mysql_con, db_name);
                system("pause");
            }
            else if (pos == 7)
            {
                mysql_close(mysql);
                return 0;
            }
            pos = 0;
            DrawLab(pos);
            break;

        case BUTTON_UP: // up
            if (pos > 0)
                DrawLab(--pos);
            break;

        case BUTTON_DOWN: // down
            if (pos < maxPos)
                DrawLab(++pos);
            break;
        }
}

void DrawLab(int pos)
{
    SetConsoleTitle(L"Menu");
    system("cls");
    std::cout << " Create table";
    DrawArrow(pos, 0);
    std::cout << "\n" << " Add data to database from \"txt\" file";
    DrawArrow(pos, 1);
    std::cout << "\n" << " Add data to database from console";
    DrawArrow(pos, 2);
    std::cout << "\n" << " Pull data from the database";
    DrawArrow(pos, 3);
    std::cout << "\n" << " Disconnect from the database";
    DrawArrow(pos, 4);
    std::cout << "\n" << " Delete the table";
    DrawArrow(pos, 5);
    std::cout << "\n" << " Delete the database";
    DrawArrow(pos, 6);
    std::cout << "\n" << " Exit";
    DrawArrow(pos, 7);
}

void DrawArrow(int pos, int posIf)
{
    if (pos == posIf)
        printf("<-");
}