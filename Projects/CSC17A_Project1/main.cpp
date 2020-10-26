
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
#include <time.h>
#include <iomanip>
#include <fstream>
#include <unistd.h>

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

void calculateSalary(struct PlayerData *);
void goToCollege(struct PlayerData *);
void drawCareer(struct JobData *, struct PlayerData *);
int spin();
void writeJobData(fstream &, struct PlayerData);

void lifeTileSpace(PlayerData *);
void getMoneySpace(PlayerData *);
void payDay(PlayerData *);
void paySpace(PlayerData *);
void getMarriedSpace(PlayerData *);
void kidSpace(PlayerData *);
void tradeSalarySpace(PlayerData *);
void newCareer(PlayerData *);
void taxesDueSpace(PlayerData *);
void taxRefundSpace(PlayerData *);
void getRaiseSpace(PlayerData *);

enum boardTile {GetRaise = 1, LifeTile = 2, TradeSalary = 3, PaySpace = 4, GetMarried = 5, 
KidSpace = 6, TaxesDue = 7, TaxRefund = 8, GetMoney = 9, NewCareer = 10};

int main(int argc, char** argv) {
    
    srand(time(NULL));
    int maxBoardPos = 0;
    double highestMoney = 0;
    int winner = 0;
    char userInput[50];
    
    JobData jobDataList[13] = {
        {"PlaceHolder", 0, 0, 0, false},
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
        
    boardTile board[30];
    
    fstream inputFile;
    string inputFileName = "board.txt";
    fstream outputFile;
    
    inputFile.open(inputFileName, ios::in | ios::binary);
    for (int i = 0; i < 35; i++){
        int tileNum;
        inputFile >> tileNum;
        board[i] = (boardTile)tileNum;
    }
    
    cout << "Welcome to the Game of Life!" << endl;
    sleep(1);
    int numPlayers;
    cout << "How many players are there? [2-4]: ";
    cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 4){
        cout << "This is a 2-4 player game! Please try again: ";
        cin >> numPlayers;
    }
    PlayerData* player = new PlayerData[numPlayers];
    
    //set up careers and salaries
    for (int i = 0; i < numPlayers; i++){
        sleep(1);
        player[i].married = false;
        cout << "Player " << i+1 << endl;
        string input;
        cout << "Pick career or college: ";
        cin >> input;
        for (int i = 0; i < input.length(); i++){
            ((char)tolower(input[i]));
        }
        if (input == "college"){
            goToCollege(&player[i]);
            drawCareer(jobDataList, &player[i]);
        }
        else if (input == "career"){
            player[i].degree = false;
            drawCareer(jobDataList, &player[i]);
        }
        else{
            cout << "Invalid Input! Please choose career or college: ";
            cin >> input;
        }
        calculateSalary(&player[i]);
        sleep(1);
        cout << "Your Salary as a(n) " << player[i].career.position << " is $" << setprecision(2) << fixed << player[i].salary << endl;
    }
       
    do {
        for (int i = 0; i < numPlayers; i++){
            PlayerData *currentPlayer = &player[i];
            sleep(1);
            cout << endl << "Player " << i+1 << endl;
            sleep(1);
            int spinResult;
            spinResult = spin();
            if (spinResult == 10){
                for (int p = 0; p < numPlayers; p++){
                    if (player[p].career.position == "Police Officer"){
                        player[p].totalMoney += 10000;
                        currentPlayer->totalMoney = currentPlayer->totalMoney - 10000;
                        cout << "You got caught speeding! Pay your ticket!" << endl;
                    }
                }
            }
            currentPlayer->currentBoardPosition += spinResult;
            if (currentPlayer->currentBoardPosition > 35){
                maxBoardPos = currentPlayer->currentBoardPosition;
                break;
            }
            switch(board[currentPlayer->currentBoardPosition]){
                case GetRaise:{getRaiseSpace(currentPlayer);break;}
                case LifeTile:{lifeTileSpace(currentPlayer);break;}
                case TradeSalary:{tradeSalarySpace(currentPlayer);break;}
                case PaySpace:{paySpace(currentPlayer);break;}
                case GetMarried:{getMarriedSpace(currentPlayer);break;}
                case KidSpace:{kidSpace(currentPlayer);break;}
                case TaxesDue:{taxesDueSpace(currentPlayer);break;}
                case TaxRefund:{taxRefundSpace(currentPlayer);break;}
                case GetMoney:{getMoneySpace(currentPlayer);break;}
                case NewCareer:{newCareer(currentPlayer);drawCareer(jobDataList, currentPlayer);calculateSalary(currentPlayer);break;}
                }
        }
        cout << endl << "*PAYDAY*" << endl << endl;
        sleep(1);
        for (int i = 0; i < numPlayers; i++){
            cout << "Player " << i+1 << endl;
            payDay(&player[i]);
        }
        cout << endl;
        
    } while (maxBoardPos < 35);
    
    cout << "Time to retire!" << endl;
    for (int i = 0; i < numPlayers; i++){
        player[i].totalMoney = player[i].totalMoney - player[i].totalDebt;
        player[i].totalMoney += player[i].lifeTileCount * 5000;
        if (player[i].totalMoney > highestMoney){
            highestMoney = player[i].totalMoney;
            winner = i;
        }
    }
    cout << "The winner of the game is player " << winner+1 << "!!" << endl;
    cout << "Please input a filename to write the game stats to: ";
    cin >> userInput;
    cout << "Congrats! Thanks for playing." << endl;
    for (int i = 0; i < 50; i++){
            ((char)tolower(userInput[i]));
        }
    string outputFileName;
    outputFileName = userInput;
    
    outputFile.open(outputFileName, ios::out | ios::binary);
    outputFile << "The Game of Life: Game Stats" << endl;
    outputFile << "Winner: Player " << winner+1 << endl; 
    for (int i = 0; i < numPlayers; i++){
        outputFile << endl << endl << "Player " << i+1 << endl;
        writeJobData(outputFile, player[i]);
    }
    
    outputFile.close();
    
    delete[] player;
    
    return 0;
}

void writeJobData(fstream &outputFile,PlayerData player){
        outputFile << setprecision(2) << fixed << "Career: " << player.career.position << endl;
        outputFile << "Ending Salary: $" << player.salary << endl;
        outputFile << "Married: ";
        if (player.married = true){
            outputFile << "Yes" << endl;
        }
        else {
            outputFile << "No" << endl;
        }
        outputFile << "Children: " << player.children << endl;
        outputFile << "Degree: ";
        if (player.degree = true){
            outputFile << "Yes" << endl;
        }
        else {
            outputFile << "No" << endl;
        }
        outputFile << "Total LIFE tiles: " << player.lifeTileCount << endl;
        outputFile << "Total Debt: $" << player.totalDebt << endl;
        outputFile << "Total Money: $" << player.totalMoney << endl;
}

int spin(){
    int result = rand() % 10 + 1;
    cout << "You Spun " << result << endl;
    return result;
}

void calculateSalary(PlayerData* player){
    int num = rand() % 2 + 1;
    if (num == 1){
        player->salary = player->career.minSalary;
    }
    else if (num == 2){
        player->salary = player->career.minSalary + 10000;
    }
    else {
        player->salary = player->career.maxSalary * .75;
    }
}

void goToCollege(PlayerData* player){
    cout << "Congratulations you have earned your degree!" << endl;
    sleep(1);
    cout << "You now have $40,000 of debt." << endl;
    sleep(1);
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
    cout << "You will be given 2 random careers to choose from: " << endl;
    int result1 = rand() % num + 1;
    int result2 = rand() % num + 1;
    while (result1 == result2){
        result2 = rand() % num + 1;
    }
    sleep(1);
    cout << "1) " << setprecision(2) << fixed << jobDataList[result1].position << endl << "Min Salary: " << jobDataList[result1].minSalary << endl;
    cout << "Max Salary: " << jobDataList[result1].maxSalary << endl << "Taxes: " << jobDataList[result1].taxes << endl;
    sleep(1);
    cout << "2) " << setprecision(2) << fixed << jobDataList[result2].position << endl << "Min Salary: " << jobDataList[result2].minSalary << endl; //segmentation fault 
    cout << "Max Salary: " << jobDataList[result2].maxSalary << endl << "Taxes: " << jobDataList[result2].taxes << endl;
    int careerSelection;
    cin >> careerSelection;
    while (careerSelection < 1 || careerSelection > 2){
        cout << "Invalid Selection. Please enter 1 or 2: ";
        cin >> careerSelection;
    }
    if (careerSelection == 1){
        player->career = jobDataList[result1];
    }
    else {
        player->career = jobDataList[result2];
    }
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
void payDay(PlayerData *player){
    player->totalMoney += player->salary;
    cout << "You now have $" << player->totalMoney << endl;
}
void paySpace(PlayerData *player){
    //pay and money goes to specific career 
}
void getMarriedSpace(PlayerData *player){
    cout << "Congratulations! You got married!" << endl;
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
    cout << "Midlife Crisis!" << endl;
    sleep(1);
    cout << "Prepare to choose new career." << endl;
}
void taxesDueSpace(PlayerData *player){
    cout << "Taxes Due!" << endl;
    player->totalMoney -= player->career.taxes;
    sleep(1);
    cout << "You have paid $" << player->career.taxes << "in taxes." << endl;
}
void taxRefundSpace(PlayerData *player){
    cout << "Your tax refund came in the mail!" << endl;
    player->totalMoney += (player->career.taxes * .25);
    sleep(1);
    cout << "You got a refund of $" << player->career.taxes * .25 << endl;
}
void getRaiseSpace(PlayerData *player){
    if ((player->career.maxSalary-10000) > player->salary){
        cout << "Congrats! You've been given a raise!" << endl;
        player->salary += 10000;
        cout << "Your new salary is $" << player->salary << endl;
    }
    else if (player->career.maxSalary == player->salary){
        cout << "You were going to get a raise but you have the max salary!" << endl;
    }
    else {
        cout << "Congrats! You've been given a raise!" << endl;
        player->salary = player->career.maxSalary;
    }
}