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

\param a ������ ������ � ���������

\param input ��� �����

2.void show_data_from_cont(std::list<DataExtraction>& a)







