# Patients
������� �������� ������ � �������� � ������� �� MYSQL.

������� ��������� ����������, ������� � �������� ���������� � ���������, ������������ � ������� ���� ������, �����
��� ID ��������, ���, �������, ���� ��������, ������� � ���������� ������. ����� ���� ����������� ��������� ������ � ��������. ������ �����, ���������� ���������������� ��������� � ��������� ������ � ���� ����. 

��� ������� ���������� ������������ �������� � ������� ���� � ����� ������� ��������� �������:
connect - ����������� � ���� ������
exit - ����� �� ����������

��� ������ ������� �������� ������������ ������������ ������� ���� ������ � �������.
����� ������������ �������� � �������, � ������� ��� �������� �������������� � ����� ������. ������������ ����� ������� ��������� �������:

Add data from "txt" file - ��������� �������� ������ �� ���������� �����

Add data from console - ��������� �������� ������ �� �������

Show data from the database - ������� �� ����� ������

Disconnect from the database - ��������� ������������ �� ���� ������

Delete the table - ������� �������

Delete the database - ������� ���� ������

Back - ��������� ��������� � ����

��� ����������� ������������ ������ ��������� ������: ����, ��� ������������, ������, ���� � ���������� ����. 
����� �� ������������� ������� ������ ��� ���� ������ � ��� �������.

��� ������ ���� ������������ ��������� �������:

DrawMenu, DrawEdit, DrawArrow - �������, �������������� ����

��� �������� ������ � �������� ������������ ����� DataExtraction. ���� ����� �������� ��������� ������, ��������� � ������������
� ����������� �������� ������ � ������ �������. ����� ����� �������� ����������� �� ��������� � ������, ������������
������ �������. 

� ������ ������������� ���������� ������ ���� ����� ���������� ���������� ����������� ������ DataExtractionException.

��� ������ � ����� ������ � ��������� ���� �������� ��������� �������:

1.void pull_data(std::list<DataExtraction>& a, const std::string& input)

������� ��������� ������ �� ����� � ��������� � �������

\param a - ������ ������ � ���������

\param input - ��� �����

2.void show_data_from_cont(std::list<DataExtraction>& a)

������� ������� ������ � ��������� � �������

\param a - ������ ������ � ���������

3.void create_db(MYSQL* mysql, const std::string& db)

������� ���������� ����� ���� ������

\param mysql - ���������� ��

\param db - ��� ��

4.void delete_db(MYSQL* mysql, const std::string& db)

������� ������� ���� ������

\param mysql - ���������� ��

\param db - ��� ��

MYSQL* connect_to_DB(const std::string& host1, const std::string& user1,
    const std::string& passwd1, const std::string& db1, const unsigned int port1, const unsigned long clientflag1)

������� ������������ ����������� � ���� ������

\param host1 - ����

\param user1 - ��� ������������

\param passwd1 - ������

\param db1 - ��� ��

\param port1 - ����

\param clientflag1 - ���������� ����

