
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 10, 2020, 10:50 PM
 * Purpose: Project 1: The Game of Life
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct JobData
{
    string position;
    double minSalary;
    double maxSalary;
    float taxes;
    bool requiresDegee;
};

struct PlayerData
{
    JobData career;
    double salary;
    bool married;
    bool degree;
    int children;
    double totalMoney;
    double totalDebt;
    int currentBoardPosition;
};

void calculateSalary();
void payDay(double *);
void goToCollege(struct PlayerData *);
void drawCareer(struct JobData *, struct PlayerData *);
int spin();


int main(int argc, char** argv) {
    
    JobData jobDataList[12] = {
        {"SalesPerson", 20000, 50000, 5000, false},
        {"Hair Stylist", 30000, 60000, 10000, false},
        {"Mechanic", 30000, 60000, 10000, false},
        {"Police Officer", 40000, 70000, 15000, false},
        {"Entertainer", 50000, 1000000, 20000, false},
        {"Athlete", 60000, 1000000, 25000, false},
        {"Teacher", 40000, 70000, 15000, true},
        {"Computer Designer", 50000, 80000, 20000, true},
        {"Accountant", 70000, 110000, 30000, true},
        {"Veterinarian", 80000, 120000, 35000, true},
        {"Lawyer", 90000, 1000000, 40000, true},
        {"Doctor", 100000, 1000000, 45000, true}};
    
    PlayerData player[4];
    
    string input;
    cout << "Pick career or college: ";
    cin >> input;
    for (int i = 0; i < input.length(); i++){
        ((char)tolower(input[i]));
    }
    if (input == "college"){
        goToCollege(player);
        drawCareer(jobDataList, player);
    }
    else if (input == "career"){
        drawCareer(jobDataList, player);
    }
    else{
        cout << "Invalid Input! Please choose career or college: ";
        cin >> input;
    }
    
    
    
    
    
    
    
    
    return 0;
}

int spin(){
    int result = (rand() % 10) + 1;
    cout << "You Spun " << result << endl;
    return result;
}

void calculateSalary(){
    
}

void goToCollege(PlayerData* player){
    cout << "Congratulations you have earned your degree!" << endl;
    cout << "You now have $40,000 of debt." << endl;
    player->totalDebt = player->totalDebt + 40000.00;
    cout << "Your total debt is now: $" << player->totalDebt << endl;
    player->degree = true;
}

void drawCareer(JobData* jobDataList, PlayerData* player){
    int num;
    if (player->degree == true){
        num = 12;
    }
    else {
        num = 6;
    }
    cout << num;
    cout << "You will be given 2 random careers to choose from: " << endl;
    int result1 = (rand() % num);
    int result2 = (rand() % num);
    while (result1 == result2){
        result2 = (rand() % num);
    }
    cout << "1) " << jobDataList[result1].position << endl << "Min Salary: " << jobDataList[result1].minSalary << endl;
    cout << "Max Salary: " << jobDataList[result1].maxSalary << endl << "Taxes: " << jobDataList[result1].taxes << endl;
    cout << "2) " << jobDataList[result2].position << endl << "Min Salary: " << jobDataList[result2].minSalary << endl;
    cout << "Max Salary: " << jobDataList[result2].maxSalary << endl << "Taxes: " << jobDataList[result2].taxes << endl;
}