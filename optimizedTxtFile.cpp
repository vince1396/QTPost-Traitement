#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "optimizedTxtFile.h"
#include "ArrayPoint.h"
#include "ostream"
#include "iomanip"
#include "QString"

/*
 * This file contains methods that can be used on the second step of the
 * Post-Processing process, on a .txt file.
 */


/*
 * Methods that stores each line of the file in a vector
 */
void getOptimizedData(std::ifstream &fileFlow, std::vector<std::string> &vector)
{
    std::string line;

    while(getline(fileFlow, line))
    {
        vector.push_back(line);
    }
}

/*
 * We transform each line of a vector in a Point object and store them in another vector
 */
void createPointFromOD(std::vector<std::string> * vector, ArrayPoint *arrayPoint)
{
    for(const auto & i : *vector)
    {
        Point point;
        point.setHour(stoi(i.substr(1, 2)));
        point.setMinute(stoi(i.substr(4, 2)));
        point.setSecond(stoi(i.substr(7, 2)));

        std::string tab[3];
        std::string string = i.substr(i.find_first_of('\t'));
        string = string.substr(string.find_first_not_of('\t'));

        for(int j = 0; j < 3; j++)
        {
            if(j == 2)
                tab[j] = string;

            if(j < 2)
            {
                tab[j] = string.substr(0, string.find_first_of('\t'));
                string = string.substr(string.find_first_of('\t'));
                string = string.substr(string.find_first_not_of('\t'));
            }
        }

        point.setF1(QString().fromStdString(tab[0]).toDouble());
        point.setLat(QString().fromStdString(tab[1]).toDouble());
        point.setLong(QString().fromStdString(tab[2]).toDouble());

        arrayPoint->insert(point);
    }
}
