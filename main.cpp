// Copyright
// Purpose: Project 2
// Date 10/10/2022
// Author: Colton Sullivan
#include <iostream>
#include <fstream>
#include <vector>
#include "./functions.h"

int main() {
    std::ifstream myfile;
    myfile.open("CrewSchedule.txt");
    if ( !myfile.is_open() ) {
        std::cout << "!!! Could not open the input file(s)" << std::endl;
      return 0;
    }
    int choice;
    showList();
    std::cin >> choice;
    if (choice == -1) {
       std::cout << "Bye!" << std::endl;
    }
    while (choice != -1) {
    while ( choice >  4 || choice < -1 || choice == 0 ) {
       std::cout << "The wrong choice!!!" << std::endl;
       std::cout << "" << std::endl;
       std::cout << "to continue, press enter...";
       showList();
       std::cin >> choice;
    }
    if ( choice == 1 ) {
       showOne();
    }
    if ( choice == 2 ) {
       showTwo();
    }
    if ( choice == 3 ) {
       showThree();
    }
    if ( choice == 4 ) {
       showFour();
    }
       std::cin >> choice;
       if ( choice == -1 ) {
       std::cout << "Bye!" << std::endl;
       }
    }
}
