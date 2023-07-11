#pragma once
#include <iostream>
#include <string>
#include <sstream>


class DataExtraction
{
	int age;
	std::string nm, surnm, birth, phonenum;
public:
	DataExtraction(const std::string& s);
	DataExtraction();
	std::string get_nm() const { return nm; }
	std::string get_surnm() const { return surnm; }
	std::string get_birth() const { return birth; }
	int get_age() const { return age; }
	std::string get_phonenum() const { return phonenum; }
};

std::ostream& operator << (std::ostream& out, const DataExtraction& a);