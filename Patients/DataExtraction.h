#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

class DataExtraction
{
	std::string nm, surnm, birth, age, phonenum;
public:
	DataExtraction(const std::string& s);
	DataExtraction();
	std::string get_nm() const { return nm; }
	std::string get_surnm() const { return surnm; }
	std::string get_birth() const { return birth; }
	std::string get_age() const { return age; }
	std::string get_phonenum() const { return phonenum; }
};

std::ostream& operator << (std::ostream& out, const DataExtraction& a);

class DataExtractionException{};