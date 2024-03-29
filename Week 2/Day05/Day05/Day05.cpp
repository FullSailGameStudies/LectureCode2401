﻿// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

int LinearSearch(std::vector<int> nums, int searchTerm)
{
    int foundIndex = -1;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (searchTerm == nums.at(i))
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}


int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE 1:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 }; //worst-case: 7 items. O(N) where N = size
    int searchNumber = 6;
    int index = LinearSearch(numbers, searchNumber);
    std::cout << searchNumber << " was" << ((index == -1) ? " NOT " : " ") << "found.\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a Dictionary:
        1) using the insert method.
        3) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE 2:

            Create a map that stores names (string) and grades. Call the variable grades.
            Add students and grades to your map.

    */

    std::map<std::string, float> menu;//type of the keys is string (name), type of the values is float (price)

    //keys are UNIQUE in the map
    //values are NOT unique
    std::string key = "Cheez Burger";
    float value = 1.99F;
    menu[key] = value;
    menu["Cheezy Fries"] = 0.99F;
    menu["Dino Nuggies"] = 4.99F;
    menu["Dino Nuggies"] = 7.99F;//overwrite any existing value for the key

    auto result = menu.insert(std::make_pair("Cheezy Pizza", 6.99F));
    if (result.second)
    {
        std::cout << "Cheezy Pizza was added to the menu.\n";
    }
    else
        std::cout << "Cheezy Pizza was already on the menu.\n";


    srand(time(NULL));
    std::vector<std::string> names{ "Alexander", "Candace", "Shaley", "Michael", "Miguel", "Osiris",
"John", "Payton", "Donell", "Luke", "Joshua", "Dominick", "Patrick", "Asah", "Derick",
"Angel", "Dante", "Jshaun", "Jaxx", "Muhanad", "Harold", "Natalie", "Michael J", "Liam",
"Nathan", "Shane", "Matthew J", "Duc", "Jeremy", "Sterling", "Seth", "Maxwell", "Emily",
"Huy", "Derrick W", "Bryan", "Akheem", "Dylan", "Eric", "Khalid", "Lindsey", "Sabrina",
"Timothy", "William" };
    std::map<std::string, double> grades;
    for (auto& name : names)
    {
        grades[name] = rand() % 10001 / 100.0;
    }


    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    std::cout << "\nWelcome to Cheezy World\n";
    for (auto menuIter = menu.begin(); menuIter != menu.end(); menuIter++)
    {
        //menuIter->first is the KEY
        //menuIter->second is the VALUE associated with the KEY
        std::cout << std::setw(20) << std::left << menuIter->first << std::setw(7) << std::right << menuIter->second;
        std::cout << "\n";
    }

    std::cout << "\nWelcome to Cheezy World\n";
    for (auto& [itemName, itemPrice] : menu)
    {
        std::cout << std::setw(20) << std::left << itemName << std::setw(7) << std::right << itemPrice;
        std::cout << "\n";
    }


    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE 4:

            Loop over your grades map and print each student name and grade.

    */
    std::cout << "\n\nGrades for PG2 2401\n";
    for (auto& [studentName, studentGrade] : grades)
    {
        std::cout << std::setw(15) << std::left << studentName;
        std::cout << std::setw(7) << std::right << studentGrade << "\n";
    }



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }


    std::string itemToFind = "Cheezy Fries";
    auto isFoundIterator = menu.find(itemToFind);
    if (isFoundIterator == menu.end()) //NOT FOUND
    {
        std::cout << itemToFind << " was not found.\n";
    }
    else
    {
        std::cout << itemToFind << " used to cost " << isFoundIterator->second << "\n";
        isFoundIterator->second *= 1.05;//adds a 5% increase to the price
        std::cout << itemToFind << " now costs " << menu[itemToFind] << ". Thanks PUTIN!\n";
    }

    float newPrice = menu["Cheezy Dogs"];//what will this do?? will this throw an exception??
    std::cout << "Cheezy Dogs costs " << newPrice << "\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe




    /*
        CHALLENGE 5:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */
    /*
        CHALLENGE 6:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
    std::string student = "Harold";
    auto foundStudent = grades.find(student);
    if (foundStudent != grades.end())
    {
        std::cout << student << "'s grade was " << foundStudent->second << ". WOW!\n";
        foundStudent->second = std::min(100.0, foundStudent->second + 5);
        std::cout << student << "'s grade is now " << grades[student] << ".\n";
        if (foundStudent->second > 59.5) std::cout << "GOOD JOB!\n";
        else std::cout << "Better luck next time. :(  \n";
    }
    else
        std::cout << student << " is not in PG2 this month.\n";



    if (grades.erase(student) > 0)
        std::cout << student << " was dropped from PG2.\n";
    else
        std::cout << student << " is not in PG2 this month.\n";

    grades.erase(foundStudent);

}