#include "DataExtraction.h"

DataExtraction::DataExtraction(const std::string& s)
{
    if (s != "")
    {
        std::istringstream input(s);
        input >> nm >> surnm >> birth >> age >> phonenum;
    }
}

std::ostream& operator << (std::ostream& out, const DataExtraction& a)
{
	out << a.get_nm() << ' ' << a.get_surnm() << ' ' << a.get_birth() << ' ' << a.get_age() << ' ' << a.get_phonenum();
	return out;
}