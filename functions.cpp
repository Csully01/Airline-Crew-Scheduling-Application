// Copyright
// Purpose Functions for the project
// Author Colton Sullivan
#include<iostream>
#include<fstream>
#include <string>
#include<vector>
#include <algorithm>
#include "functions.h"

void showList() {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Airline Crew Scheduling Application" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << " 1 List assigned flights of a crew" << std::endl;
    std::cout << " 2 List crews for a flight" << std::endl;
    std::cout << " 3 List names of the crews" << std::endl;
    std::cout << " 4 [Your Option]" << std::endl;
    std::cout << "-1 Exit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << ">> Enter your choice:" << std::endl;
}
// give the user the 1 selection
void showOne() {
    // vectors to store everything from the files
    std::vector<std::string> names;
    std::vector<std::string> schedules;
    std::vector<std::string> flightsd;
    std::vector<std::string> flightsl;
    std::ifstream fin("CrewSchedule.txt");
    std::ifstream fin2("Flights.txt");
    std::string name, schedule, flightdep, flightlnd;
    while ( fin >> name >> schedule ) {
        names.push_back(name);
        schedules.push_back(schedule);
    }
    while ( fin2 >> flightdep >> flightlnd ) {
       flightsd.push_back(flightdep);
       flightsl.push_back(flightlnd);
    }
    // 1000000001
    // if number at i[1] = 1 then go to vector for flights
    // and print the number that is at 1
    // else move on to the next
    std::cout << ">> Enter the name of the crew :" << std::endl;
    int count = 0;
    bool found = false;
    bool feasible = true;
    std::string previousFlight;
    while ( found == false ) {
       std::string usrname;
       std::cin >> usrname;
       for (int i = 0; i < usrname.size(); i++) {
          usrname[i] = toupper(usrname[i]);
       }
    // to get the assigned flights you have to get name at i and schedule at i,
    // then print from the flight vector 2
    if ( find(names.begin(), names.end(), usrname) != names.end() ) {
       found = true;
       std::cout << "---- Assigned Flights ----" << std::endl;
       int j;
       for ( int i = 0; i < names.size(); i++ ) {
          if ( names.at(i) == usrname ) {
             j = i;
          }
       }
         for ( int i = 0; i < 11; i++ ) {
             if ( schedules.at(j).at(i) == '1' ) {
                count++;
                 if ( i != 0 && previousFlight != flightsd.at(i) ) {
                     feasible = false;
                 }
                 std::cout << flightsd.at(i) << "-";
                 std::cout << flightsl.at(i) << std::endl;
                 previousFlight = flightsl.at(i);
             }
         }
         if ( count == 1 ) {
            feasible = true;
         }
         if ( feasible == false ) {
             std::cout << "The flight sequence is not feasible!!" << std::endl;
         } else {
             std::cout << "The flight sequence is feasible" << std::endl;
         }
    } else {
       std::cout << "!!! No record for " << usrname << std::endl;
       std::cout << ">> Enter the name of the crew :" << std::endl;
    }
    }
    std::cout << "\n" << "to continue, press enter...";
    showList();
}

void showTwo() {
    // vectors to store everything
    std::vector<std::string> names;
    std::vector<std::string> schedules;
    std::vector<std::string> flightsd;
    std::vector<std::string> flightsl;

    std::ifstream fin("CrewSchedule.txt");
    std::ifstream fin2("Flights.txt");
    std::string name, schedule, flightdep, flightlnd;

    while ( fin >> name >> schedule ) {
        names.push_back(name);
        schedules.push_back(schedule);
    }
    while ( fin2 >> flightdep >> flightlnd ) {
       flightsd.push_back(flightdep);
       flightsl.push_back(flightlnd);
    }

    std::cout << "Here is the flight points: SFO, LAX,";
    std::cout << "ORD, DEN, SEA" << std::endl;
    bool found = false;
    while ( found == false ) {
    std::string from;
    std::string to;
    int crewNum = 0;

    std::cout << ">> FROM :" << std::endl;
    std::cin >> from;
    for ( int i = 0; i < from.size(); i++ ) {
       from[i] = toupper(from[i]);
    }
    std::cout <<">> TO :" << std::endl;
    std::cin >> to;
    for ( int i = 0; i < to.size(); i++ ) {
       to[i] = toupper(to[i]);
    }
    // find if the to and from are in the vectors for
    // both then look to see which crew has that as a 1
    // for loop to go throught the departures and every
    // occurence of that city check that index in landing vector
    // and see if it matches the to city, if it does then save
    // that index to use to check the schedules
    int index;
    for ( int i = 0; i < flightsd.size(); i++ ) {
       if ( flightsd.at(i) == from ) {
          if ( flightsl.at(i) == to ) {
             found = true;
             index = i;
          }
       }
    }
    if ( found == true ) {
       std::cout << "---- Crew List ----" << std::endl;
       for ( int i = 0; i < schedules.size(); i++ ) {
          if ( schedules.at(i).at(index) == '1' ) {
             std::cout << names.at(i) << std::endl;
             crewNum += 1;
          }
       }
       std::cout << crewNum << " crew(s) work(s) on the flight ";
       std::cout << from << "-" << to << std::endl;
       std::cout << "" << std::endl;

     } else {
       std::cout << "No flight was found!!Please enter again..." << std::endl;
       std::cout << "Here is the flight points: SFO, LAX";
       std::cout << ", ORD, DEN, SEA" << std::endl;
     }
    }
    std::cout << "to continue, press enter...";
    showList();
}
void showThree() {
    std::cout << "--- Names of The Crews ---" << std::endl;
    std::ifstream fin("CrewSchedule.txt");
    std::string name, schedule;

    while ( fin >> name >> schedule ) {
       std::cout << name  << std::endl;
    }
    std::cout << "\nto continue, press enter...";
    showList();
}
void showFour() {
    std::cout << "--- Schedules of The Crews ---" << std::endl;
    std::ifstream fin("CrewSchedule.txt");
    std::string name, schedule;
   
    while(fin >> name >> schedule){
       std::cout << schedule  << std::endl;
    }
    std::cout << "to continue, press enter...";
    showList();
}
