#include "DataExtraction.h"

DataExtraction::DataExtraction(const std::string& s)
{
    std::string mass[6];
    if (s != "")
    {
        int j = 0, k = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (isspace(s[i])) {
                mass[k] = s.substr(j, i - j);
                ++k;
                j = i + 1;
            }
            if (i == s.size() - 1) {
                mass[k] = s.substr(j, i - j + 1);
                ++k;
            }
        }
        if (k == 5) {
            ID = stoi(mass[0]);
            nm = mass[1];
            surnm = mass[2];
            birth = mass[3];
            age = stoi(mass[4]);
            phonenum = mass[5];
        }
    }
}

