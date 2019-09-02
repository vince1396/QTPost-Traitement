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

        QString f1, lon, lat;
        f1.fromStdString(tab[0]);
        lat.fromStdString(tab[1]);
        lon.fromStdString(tab[2]);

        QString test1 = "1.25";
        QString test2 = "1,25";

        double d1 = test1.toDouble();
        double d2 = test2.toDouble();

        std::cout << "string tab[1] : " << tab[1] << std::endl;
        std::cout << "double tab[1] : " << stod(tab[1]) << std::endl;
        std::cout << "Qstring tab[1] to double : " << lat.toDouble() << std::endl;
        std::cout << "d1 : " << d1 << std::endl;
        std::cout << "d2 : " << d2 << "\n" << std::endl;

//        std::cout << tab[0] << std::endl;
//        std::cout << tab[1] << std::endl;
//        std::cout << tab[2] << "\n" << std::endl;

        point.setF1(f1.toDouble());
        point.setLat(lat.toDouble());
        point.setLong(lon.toDouble());

        //point.displayPoint();

        arrayPoint->insert(point);
    }
}
