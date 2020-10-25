
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
#include <fstream>

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
    int lifeTileCount;
};

void calculateSalary();
void payDay(double *);
void goToCollege(struct PlayerData *);
void drawCareer(struct JobData *, struct PlayerData *);
int spin();

void lifeTileSpace(PlayerData *);
void getMoneySpace(PlayerData *);
void payDaySpace(PlayerData *);
void paySpace(PlayerData *);
void getMarriedSpace(PlayerData *);
void kidSpace(PlayerData *);
void tradeSalarySpace(PlayerData *);
void newCareer(PlayerData *);
void taxesDueSpace(PlayerData *);
void taxRefundSpace(PlayerData *);
void getRaiseSpace(PlayerData *);
void retire(PlayerData *);

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
        
    int board[30];
    
    fstream inputFile;
    string fileName = "board.txt";
    fstream outputFile;
    string outputFileName = "gameStats.txt";
    
    inputFile.open(fileName, ios::in | ios::binary);
    for (int i = 0; i < 35; i++){
        inputFile >> board[i];
    }
    
    for (int i = 0; i < 35; i++){
        cout << board[i] << endl;
    }
    
    int numPlayers;
    cout << "How many players are there? [2-4]: ";
    cin >> numPlayers;
    PlayerData* player = new PlayerData;
    
    
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
    
    //TURN = LOOP THROUGH PLAYERS - ROLL - add roll to currentplace variable
    //take that place in the array 
    player->currentBoardPosition += spin();
    switch(board[curentBoardPosition]){
        case "1":{getRaiseSpace(player);break;}
        case "2":{lifeTileSpace(player);break;}
        case "3":{payDaySpace(player);break;}
        case "4":{paySpace(player);break;}
        case "5":{getMarriedSpace(player);break;}
        case "6":{kidSpace(player);break;}
        case "7":{taxesDueSpace(player);break;}
        case "8":{taxRefundSpace(player);break;}
        case "9":{getMoneySpace(player);break;}
        case "10":{newCareer(player);break;}
        case "11":{tradeSalarySpace(player);break;}
    }
    
    
    outputFile.open(outputFileName, ios::out | ios::binary);
    
    //delete player array
    
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
    int careerSelection;
    cin >> careerSelection;
}

void lifeTileSpace(PlayerData *player){
    cout << "You have earned a LIFE tile!" << endl;
    player->lifeTileCount++;
    cout << "You now have " << player->lifeTileCount << " LIFE tiles!" << endl;
}
void getMoneySpace(PlayerData *player){
    cout << "You have earned some extra cash!" << endl;
    player->totalMoney += 5000;
    cout << "You now have $" << player->totalMoney << "." << endl;
}
void payDaySpace(PlayerData *player){
    cout << "PAY DAY!" << endl;
    player->totalMoney += player->salary;
}
void paySpace(PlayerData *player){
    //pay and money goes to specific career 
}
void getMarriedSpace(PlayerData *player){
    cout << "Congratulations! You are married!" << endl;
    player->married = true;
}
void kidSpace(PlayerData *player){
    cout << "Congratulations! You've just had a baby!" << endl;
    player->children++;
}
void tradeSalarySpace(PlayerData *player){
    //display salaries of all players and ask if they'd like to trade
}
void newCareer(PlayerData *player){
    //go through choose career function
}
void taxesDueSpace(PlayerData *player){
    cout << "Taxes Due!" << endl;
    player->totalMoney -= player->career.taxes;
}
void taxRefundSpace(PlayerData *player){
    cout << "Your tax refund came in the mail!" << endl;
    player->totalMoney += 5000;
}
void getRaiseSpace(PlayerData *player){
    if ((player->career.maxSalary-10000) > player->salary){
        cout << "Congrats! You've been given a raise!" << endl;
        player->salary += 10000;
        cout << "Your new salary is $" << player->salary << endl;
    }
}
void retire(PlayerData *player){
    
}