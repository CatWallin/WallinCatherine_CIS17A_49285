/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 24, 2020, 4:58 PM
 * Project 2: The Game of Life 
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <unistd.h>

using namespace std;

#include "CollegeJob.h"
#include "Player.h"

void drawCareer(class Player, class Job *);

int main(int argc, char** argv) {
    
    srand(time(NULL));
    int numPlayers;
    
    //regular career objects
    Job career[13];
    career[0] = Job("PlaceHolder", 0, 0, 0);
    career[1] = Job("Sales Person", 20000, 50000, 5000);
    career[2] = Job("Hair Stylist", 30000, 60000, 10000);
    career[3] = Job("Mechanic", 30000, 60000, 10000);
    career[4] = Job("Police Officer", 40000, 70000, 15000);
    career[5] = Job("Entertainer", 50000, 1000000, 20000);
    career[6] = Job("Athlete", 60000, 1000000, 25000);
    career[7] = CollegeJob("Teacher", 40000, 70000, 15000); 
    career[8] = CollegeJob("Computer Designer", 50000, 80000, 20000);
    career[9] = CollegeJob("Accountant", 70000, 110000, 30000);
    career[10] = CollegeJob("Veterinarian", 80000, 120000, 35000);
    career[11] = CollegeJob("Lawyer", 90000, 1000000, 40000);
    career[12] = CollegeJob("Doctor", 100000, 1000000, 45000);
    
    
    
    //Game Intro and Player Number Set-Up
    cout << "Welcome to the Game of Life!" << endl;
    cout << "How many players are there? [2-4]: ";
    cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 4){
        cout << "This is a 2-4 player game! Please try again: ";
        cin >> numPlayers;
    }
    Player* player = new Player[numPlayers];
    
    //Set-up Careers and Salaries
    string userInput;
    for (int i = 0; i < numPlayers; i++){
        cout << "Player " << i+1 << endl;
        cout << "Pick career or college: ";
        cin >> userInput;
        for (int i = 0; i < userInput.length(); i++){
            ((char)tolower(userInput[i]));
        }
        while(userInput != "college" && userInput != "career"){
            cout << "Invalid Choice!!! Please enter career or college: ";
            cin >> userInput;
            for (int i = 0; i < userInput.length(); i++){
                ((char)tolower(userInput[i]));
            }
        }
        if (userInput == "college"){
            cout << "Congratulations! You have earned your degree!" << endl;
            cout << "You now have $40,000 of debt." << endl;
            player[i].setTotalDebt(40000.00);
            cout << "Your total debt is now: $" << player[i].getTotalDebt() << endl;
            player[i].setDegree(true);
            drawCareer(player[i], career);
            int num = rand() % 2 + 1;
            player[i].setSalary(num);
            cout << num << " " << "career: " << player[i].getCareer().getPosition() << endl;
        }
        else {
            drawCareer(player[i], career);
            int num = rand() % 2 + 1;
            player[i].setSalary(num);
            cout << num;
        }
        cout << "Your Salary: $" << player[i].getSalary() << endl;
    }
    return 0;
}


void drawCareer(Player player, Job* career){
    int num;
    if (player.getDegree() == true){
        num = 12;
    }
    else {
        num = 6;
    }
    cout << "You will be given 2 random careers to choose from: " << endl;
    int result1 = rand() % num + 1;
    int result2 = rand() % num + 1;
    while (result1 == result2){
        result2 = rand() % num + 1;
    }
    sleep(1);
    cout << "1) " << setprecision(2) << fixed << career[result1].getPosition() << endl << "Min Salary: " << career[result1].getMinSalary() << endl;
    cout << "Max Salary: " << career[result1].getMaxSalary() << endl << "Taxes: " << career[result1].getTaxes() << endl;
    sleep(1);
    cout << "2) " << setprecision(2) << fixed << career[result2].getPosition() << endl << "Min Salary: " << career[result2].getMinSalary() << endl;  
    cout << "Max Salary: " << career[result2].getMaxSalary() << endl << "Taxes: " << career[result2].getTaxes() << endl;
    int careerSelection;
    cin >> careerSelection;
    while (careerSelection < 1 || careerSelection > 2){
        cout << "Invalid Selection. Please enter 1 or 2: ";
        cin >> careerSelection;
    }
    if (careerSelection == 1){
        player.setCareer(career[result1]);
    }
    else {
        player.setCareer(career[result2]);
    }
    
}

