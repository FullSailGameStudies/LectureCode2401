﻿// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Superhero.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string path = "C:\\temp\\2401\\";
    std::string fileName = "2401.csv";
    std::string fullPath = path + fileName;
    char delimiter = '?';

    //writing the csv data
    {
        std::ofstream outFile(fullPath);//where is it going to write the file?
        outFile << "Batman rules!" << delimiter << 5 << delimiter << 13.7 << delimiter << true;
    }

    //read the csv data
    std::ifstream inFile(fullPath);
    std::string line;
    std::getline(inFile, line);
    std::cout << line << "\n";
    inFile.close();

    //parse the csv data into individual pieces
    std::stringstream lineStream(line);

    std::string data;
    std::getline(lineStream, data, delimiter);//reads "Batman rules!"
    std::string catchPhrase = data;

    std::getline(lineStream, data, delimiter); //reads "5"
    int age = std::stoi(data);//let's hope it's an int


    std::getline(lineStream, data, delimiter); //reads "13.7"
    double bankBalance = std::stod(data);

    std::getline(lineStream, data, delimiter); //reads "1"
    bool amIGoingToPass = std::stoi(data);



    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::vector<Superhero> JLA;
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';

    std::string heroString;
    std::stringstream heroStream(multi);
    while (std::getline(heroStream, heroString, collectionSeparator))
    {
        //std::cout << heroString << "\n";
        std::stringstream detailsStream(heroString);
        std::string name, secret, ageString;
        int age;
        std::getline(detailsStream, name, objectSeparator);
        std::getline(detailsStream, secret, objectSeparator);
        std::getline(detailsStream, ageString, objectSeparator);
        age = std::stoi(ageString);

        Superhero hero(name, secret, age);
        JLA.push_back(hero);
    }

    std::cout << "\n\nThe Justice League\n";
    for (auto& hero : JLA)
    {
        std::cout << "Hello citizen! I am " << hero.Name() << "! (aka " << hero.Secret() << ") ";
        std::cout << "And I am " << hero.Age() << " years old.\n";
    }
}