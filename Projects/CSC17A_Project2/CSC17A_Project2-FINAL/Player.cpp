
#include <iostream>
using namespace std;
#include "Player.h"

Player::Player(){
    salary = 0;
    married = false;
    degree = false;
    children = 0;
    totalMoney = 1000;
    totalDebt = 0;
    currentBoardPosition = 0;
    lifeTileCount = 0;
}

Player::Player(const Player &player){
    career = player.career;
    salary = player.salary;
    married = player.married;
    degree = player.degree;
    children = player.children;
    totalMoney = player.totalMoney;
    totalDebt = player.totalDebt;
    currentBoardPosition = player.currentBoardPosition;
    lifeTileCount = player.lifeTileCount;
}

void Player::setCareer(JobBase* job){
    career = job;    
}
 
void Player::setSalary(int randomNum){
    if (randomNum == 1){
        salary = career->getMinSalary();
    }
    else if (randomNum == 2){
        salary = career->getMinSalary() + 10000;
    }
    else {
        salary = career->getMaxSalary() * .75;
    }
    if (salary > career->getMaxSalary() || salary < career->getMinSalary()){
        throw InvalidSalary();
    }
}

void Player::setMarried(bool x){
    married = x;
}

void Player::setDegree(bool x){
    degree = x;
}

void Player::setTotalMoney(float tm){
    totalMoney = tm;
}

void Player::setTotalDebt(float td){
    totalDebt = td; 
}

void Player::setCurrentBoardPosition(int cbp){
    currentBoardPosition = cbp;
}

void Player::setLifeTileCount(int ltc){
    lifeTileCount = ltc;
}
    
    
//space functions
int Player::lifeTileSpace(){
    lifeTileCount++;
    return lifeTileCount;
}

float Player::getMoneySpace(int num){
    float amount;
    if (num == 1){
        amount = 500;
    }
    else if (num == 2){
        amount = 1000;
    }
    else {
        amount = 5000;
    }
    totalMoney += amount;
    return amount;
}

float Player::payDay(){
    totalMoney += salary;
    return totalMoney;
}

void Player::payPlayer(int num){
    totalMoney -= num;
}

void Player::paidByPlayer(int num){
    totalMoney += num;
}

//kidSpace: overloaded operator
int Player::operator++(){
    ++children;
    return children;
}

float Player::taxesDueSpace(){
    totalMoney -= career->getTaxes();
    return totalMoney;
}

float Player::taxRefundSpace(){
    totalMoney += (career->getTaxes() * .25);
    return (career->getTaxes() * .25);
}

float Player::getRaiseSpace(){
    if ((career->getMaxSalary()-10000) > salary){
        salary += 10000;
        return salary;  
    }
    else{
        salary = career->getMaxSalary();
        return salary;
    } 
}
    
void Player::changeSalary(float newSalary){
    salary = newSalary;
} 

//function if caught speeding!
void Player::caughtSpeeding(){
    totalMoney -= 2000;
}

//function if another player was speeding and the current player is a police officer 
void Player::ticketPayment(){
    totalMoney +=2000;
}

//overloaded operator for player's board position
void Player::operator+=(int spinResult){
    currentBoardPosition += spinResult;
}

void Player::payDebt(){
    totalMoney = totalMoney - totalDebt;
    totalDebt = 0.0;
}