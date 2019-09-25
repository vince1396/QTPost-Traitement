#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "general.h"
#include "Point.h"
#include "optimizedTxtFile.h"
#include "ArrayPoint.h"
#include "optimizedTxtFile.h"
#include "controller.h"
#include "QString"
#include "QFileDialog"

const double lambdasValues[6] = {3.75, 3.33, 1.67, 1.43, 1.30, 1.12}; // Meters

void postTraitement(std::string filePath, int idFrequence, std::string dirPath)
{
    float time;
    clock_t t1, t2;

    t1 = clock();

    // Open file
    std::ifstream fileFlow(filePath, std::ios::in);

    // If file opening went well
    if(fileFlow)
    {
        // =============================================================================================================
        std::vector<std::string> optimizedData;                            // Will contains each line of the optimized txt file
        std::vector<ArrayPoint> lambdasContainer;                         // Will store ArrayPoint after making lambdas
        std::vector<Point> arrayMedian;

        getOptimizedData(fileFlow, optimizedData);                         // We store the lines in the container
        ArrayPoint arrayPoint(static_cast<int>(optimizedData.size()));     // Creation of the ArrayPoint containing all the points from the file
        createPointFromOD(&optimizedData, &arrayPoint);                    // Creation of the Points and inserting on the array
        //arrayPoint.displayArray();
        arrayPoint.makeAccumulatedDistance();                                  // Accumulated distance calculation for each point
        lambdasCreation(&arrayPoint, &lambdasContainer, lambdasValues[idFrequence]); // Making lambdas groups, depending on the frequency
        makeMediane(&lambdasContainer, &arrayMedian);
        // =============================================================================================================
        std::string const path(dirPath + "/result");
        std::ofstream writting(path, std::ios::out | std::ios::trunc);

        if(writting)
        {
            std::cout << "Starting writting..." << std::endl;

            writting << "Time \t   "
                     << "RSSI \t"
                     << "Long \t "
                     << "Lat \n\n";

            for(auto & i : arrayMediane)
            {
                writting
                << "\""
                << i.getHour()
                << ":"
                << i.getMinute()
                << ":"
                << i.getSecond()
                << "\""
                << "; "
                <<  std::setprecision(7)
                << i.getRssi()
                << "; "
                <<  std::setprecision(9)
                << i.getLong()
                << "; "
                <<  std::setprecision(9)
                << i.getLat()
                << "\n";
            }
            writting.close();
        }
        else
        {
            std::cerr << "Error writting" << std::endl;
        }

        fileFlow.close();
        // =============================================================================================================
    }
    else // If an error occured during file opening
    {
        // Display error message
        //View::errorOpenFile(filePath);
    }

    t2 = clock();
    time = (float) (t2-t1) / CLOCKS_PER_SEC;

    std::cout << "\n\nExec : " << time << "s" << std::endl;
}
