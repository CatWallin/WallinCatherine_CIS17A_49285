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
#include "Spin.h"
#include "GameStats.h"
#include "JobBase.h"

void drawCareer(Player &player, JobBase* *career);
void swapSalaries(Player &player1, Player &player2);
void printFinalResults(Player &player, Player &start, GameStats gameStats);

enum boardTile {GetRaise = 1, LifeTile = 2, TradeSalary = 3, PaySpace = 4, GetMarried = 5, KidSpace = 6, TaxesDue = 7, TaxRefund = 8, GetMoney = 9, NewCareer = 10};

int main(int argc, char** argv) {
    
    srand(time(NULL));
    int numPlayers;
    
    boardTile board[35] = { (boardTile)2, (boardTile)9, (boardTile)3, (boardTile)4, (boardTile)5, (boardTile)2, (boardTile)4, (boardTile)1, (boardTile)6, (boardTile)2, 
                            (boardTile)4, (boardTile)4, (boardTile)3, (boardTile)4, (boardTile)2, (boardTile)1, (boardTile)3, (boardTile)4, (boardTile)2, (boardTile)6, (boardTile)4, 
                            (boardTile)9, (boardTile)3, (boardTile)7, (boardTile)2, (boardTile)10, (boardTile)8, (boardTile)4, (boardTile)1, (boardTile)2, (boardTile)3, (boardTile)4, 
                            (boardTile)1, (boardTile)4, (boardTile)2 };
    
    GameStats gameStats = GameStats();
    
    //regular career objects
    JobBase* career[13];
    career[0] = new Job(); //operator overloading for Job class
    career[1] = new Job("Sales Person", 20000, 50000, 5000);
    career[2] = new Job("Hair Stylist", 30000, 60000, 10000);
    career[3] = new Job("Mechanic", 30000, 60000, 10000);
    career[4] = new Job("Police Officer", 40000, 70000, 15000);
    career[5] = new Job("Entertainer", 50000, 1000000, 20000);
    career[6] = new Job("Athlete", 60000, 1000000, 25000);
    //college career objects
    career[7] = new CollegeJob("Teacher", 40000, 70000, 15000); 
    career[8] = new CollegeJob("Computer Designer", 50000, 80000, 20000);
    career[9] = new CollegeJob("Accountant", 70000, 110000, 30000);
    career[10] = new CollegeJob("Veterinarian", 80000, 120000, 35000);
    career[11] = new CollegeJob("Lawyer", 90000, 1000000, 40000);
    career[12] = new CollegeJob("Doctor", 100000, 1000000, 45000);
    
    
    
    //Game Intro and Player Number Set-Up
    cout << "--------Welcome to the Game of Life!---------" << endl;
    cout << "---------------------------------------------" << endl;
    sleep(1);
    cout << "How many players are there? [2-4]: ";
    cin >> numPlayers;
    //numPlayers = 2;
    while (numPlayers < 2 || numPlayers > 4){
        cout << "This is a 2-4 player game! Please try again: ";
        cin >> numPlayers;
    }
    Player* player = new Player[numPlayers];
    Player* startingPlayerStats = new Player[numPlayers];
    
    cout << endl << "--------------Career Selection---------------" << endl;
    //Set-up Careers and Salaries
    string userInput;
    for (int i = 0; i < numPlayers; i++){
        cout << "---------------------------------------------" << endl;
        cout << "Player " << i+1 << endl;
        sleep(1);
        cout << "Pick career or college: ";
        cin >> userInput;
        //userInput = "career";
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
        }
        else {
            drawCareer(player[i], career);
            int num = rand() % 2 + 1;
            player[i].setSalary(num);
        }
        cout << endl << "Your Career: " << player[i].getCareer()->getPosition() << endl;
        cout << "Your Salary: $" << player[i].getSalary() << endl;
        
        //copying starting player stats 
        startingPlayerStats[i] = Player(player[i]);
        
    }
    
    
    
    //initiate turn sequence 
    do {
        for (int i = 0; i < numPlayers; i++){
            cout << "---------------------------------------------" << endl;
            cout << endl << "Player " << i+1 << endl;
            //spin
            int spinResult;
            spinResult = Spin::initiateSpin();
            cout << "You Spun " << spinResult << endl;
            //got caught speeding!
            if (spinResult == 10){
                for (int p = 0; p < numPlayers; p++){
                    if (player[p].getCareer()->getPosition() == "Police Officer"){
                        cout << "Uh oh..." << endl;
                        cout << "Player " << p+1 << " caught you speeding! You got a ticket! Pay up!" << endl << endl;
                        player[i].caughtSpeeding();
                        player[p].ticketPayment();
                    }
                }
            }
            player[i] += spinResult;
        
        if (player[i].getCurrentBoardPosition() > 35){
            gameStats.setMaxBoardPos(player[i].getCurrentBoardPosition());
            break;                                                                                                                                   
        }
            //spaces
            sleep(1);
            switch(board[player[i].getCurrentBoardPosition()]){
                    case GetRaise:{
                        if(player[i].getSalary() >= player[i].getCareer()->getMaxSalary()){
                            cout << "You were going to get a raise, but you already make the max salary!" << endl;
                            cout << "Your current salary: $";
                        }
                        else{
                            cout << "Congrats! You got a raise!" << endl;
                            cout << "Your new salary: $";
                        }
                        cout << player[i].getRaiseSpace() << endl;
                        break;
                    }
                    case LifeTile:{player[i].lifeTileSpace();break;}
                    case TradeSalary:{
                        cout << "You can trade salaries with any player." << endl;
                        cout << "Here are the salaries of every player: " << endl;
                        for (int q = 0; q < numPlayers; q++){
                            cout << "Player " << q+1 << " " << player[q].getSalary() << endl;
                        }
                        char ynInput;
                        cout << endl << "Would you like to change salaries with another player? (y/n): ";
                        cin >> ynInput;
                        ynInput = tolower(ynInput);
                        while(ynInput != 'y' && ynInput != 'n'){
                            cout << "Invalid Input!!! Please enter 'y' or 'n': ";
                            cin >> ynInput;
                            ynInput = (tolower(ynInput));
                        }
                        if(ynInput == 'y'){
                            int playerSelection;
                            cout << "Which player would you like to trade salaries with? (example: '1'): ";
                            cin >> playerSelection;
                            while (playerSelection > numPlayers || playerSelection < 1 || playerSelection == i+1){
                                cout << "Invalid Selection! Please try again: ";
                                cin >> playerSelection;
                            }
                            swapSalaries(player[i], player[playerSelection-1]);
                            cout << "Player " << i+1 << " Salary: $" << player[i].getSalary() << endl;
                            cout << "Player " << playerSelection << " Salary: $" << player[playerSelection-1].getSalary() << endl;
                        }
                        break;
                    }   
                    //case PaySpace:{player.paySpace();break;}              //need pay space to pay other player //or go to school option
                    case GetMarried:{
                        player[i].setMarried(true);
                        cout << "You got married! Congratulations!" << endl;
                        break;
                    }
                    case KidSpace:{
                        cout << "Congratulations! You just had a baby!" << endl;
                        player[i].operator ++();
                        break;
                    }
                    case TaxesDue:{
                        cout << "Tax Season!" << endl;
                        cout << "Your taxes paid: $" << player[i].getCareer()->getTaxes() << endl;
                        cout << "Your current money: $" << player[i].taxesDueSpace() << endl;                        
                        break;
                    }
                    case TaxRefund:{
                        cout << "Your tax refund has just arrived!!" << endl;
                        cout << "Your total refund: $" << player[i].taxRefundSpace() << endl;
                        cout << "Your current money: $" << player[i].getTotalMoney() << endl;                   
                        break;
                    }
                    case GetMoney:{player[i].getMoneySpace();break;}
                    case NewCareer:{
                        cout << "Midlife Crisis... You went looking for a new job." << endl;
                        drawCareer(player[i], career);
                        int num = rand() % 2 + 1;
                        player[i].setSalary(num);
                        cout << endl << "Your Career: " << player[i].getCareer()->getPosition() << endl;
                        cout << "Your Salary: $" << player[i].getSalary() << endl;
                        break;
                    }            
                }
        }    
         
        //PayDay after each turn
        cout << endl << "*********PAYDAY*********" << endl;
        sleep(1);
        for (int i = 0; i < numPlayers; i++){
            
            cout << "Player " << i+1 << ": ";
            cout << "You now have $: " << player[i].payDay() << endl;
        }
        cout << endl;    
    } while (gameStats.getMaxBoardPosition() < 35);
    
    //pay debt
    for (int i = 0; i < numPlayers; i++){
        if (player[i].getTotalMoney() > player[i].getTotalDebt()){
            player[i].payDebt();    
        }
    }
    
    //printing out results and final stats
    cout << "Starting and Ending" << endl;
    for (int i = 0; i < numPlayers; i++){
        cout << "Player " << i+1 << ":" << endl;
        printFinalResults(player[i], startingPlayerStats[i], gameStats);
        cout << endl;
    }
    
    return 0;
}


void swapSalaries(Player &player1,Player &player2){
    double temp = player1.getSalary();
    player1.changeSalary(player2.getSalary());
    player2.changeSalary(temp);
}

void drawCareer(Player &player, JobBase* *career){
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
    cout << "1) " << setprecision(2) << fixed << career[result1]->getPosition() << endl << "Min Salary: " << career[result1]->getMinSalary() << endl;
    cout << "Max Salary: " << career[result1]->getMaxSalary() << endl << "Taxes: " << career[result1]->getTaxes() << endl;
    career[result1]->printRequirement();
    cout << endl;
    sleep(1);
    cout << "2) " << setprecision(2) << fixed << career[result2]->getPosition() << endl << "Min Salary: " << career[result2]->getMinSalary() << endl;  
    cout << "Max Salary: " << career[result2]->getMaxSalary() << endl << "Taxes: " << career[result2]->getTaxes() << endl;
    career[result2]->printRequirement();
    cout << endl;
    int careerSelection;
    cin >> careerSelection;
    //careerSelection = 1;
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

void printFinalResults(Player &player, Player &start, GameStats gameStats){
    if (player.getDegree()){
        cout << "You studied hard and made it through school, earning your degree." << endl;
    }
    else {
        cout << "You joined the workforce immediately with determination!" << endl;
    }
    if (gameStats.compare<string>(start.getCareer()->getPosition(), player.getCareer()->getPosition())){
        cout << "You were dedicated to your career as a " << player.getCareer()->getPosition() << " your entire life." << endl;
    }
    else {
        cout << "You jumped around a few careers." << endl;
        cout << "You started your adult life as a " << start.getCareer()->getPosition() << ". " << endl;
        cout << "You retired as a " << player.getCareer()->getPosition() << "." << endl;
    }
    if (gameStats.compare<double>(start.getSalary(), player.getSalary())){
        cout << "You earned the same salary throughout your career: $" << player.getSalary() << endl;
    }
    else {
        cout << "Your income changed a little throughout the years!" << endl;
        cout << "You started your working life off making $" << start.getSalary();
        cout << ". You retired making $" << player.getSalary() << "." << endl;
    }
    if (player.getMarried()){
        cout << "You had a beautiful marriage!" << endl;
    }
    if (player.getChildren() == 1){
        cout << "You had a wonderful child!" << endl;
    }
    else if (player.getChildren() > 1){
        cout << "You had " << player.getChildren() << " wonderful children!" << endl;
    }
    cout << "You collected " << player.getLifeTileCount() << " total LIFE tile(s)." << endl;
    if (start.getTotalDebt() > 0 && player.getTotalDebt() == 0){
        cout << "You paid off $" << start.getTotalDebt() << " worth of debt." << endl;
        cout << "You now live your life debt free!" << endl;
    }
    if (player.getTotalDebt() > 0){
        cout << "Unfortunately, you still have some debt... " << endl;
        cout << "$" << player.getTotalDebt() << " of total debt." << endl;
    }
    cout << "You retired with $" << player.getTotalMoney() << " worth of savings!" << endl;
    
}
