
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 5, 2020, 10:55 AM
 * Chapter 13 Problem 6: Inventory Class
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Inventory
{
private:
    int itemNumber, quantity;
    double cost, totalCost;
public:
    Inventory(){
        itemNumber = 0;
        quantity = 0;
        cost = 0;
        totalCost = 0;
    }
    
    Inventory(int itemNumber, int quantity, double cost){
        this->itemNumber = itemNumber;
        this->quantity = quantity;
        this->cost = cost;
        setTotalCost(this->cost, this->quantity);
    }
    
    void setItemNumber(int itemNumber) { this->itemNumber = itemNumber; }
    int getItemNumber() { return itemNumber; }
    
    void setQuantity(int quantity) { this->quantity = quantity; }
    int getQuantity() { return quantity; }
    
    void setCost(double cost) { this->cost = cost; }
    double getCost() { return cost; }
    
    void setTotalCost(double cost, int quantity) { totalCost = (quantity * cost); }
    double getTotalCost() { return totalCost; }
};

int main(int argc, char** argv) {

    int itemNumber, quantity;
    double cost;
    
    cout << "Input the item number: ";
    cin >> itemNumber;
    while(itemNumber < 0){
        cout << "Invalid Input, try again: ";
        cin >> itemNumber;
    }
    cout << "Input the quantity: ";
    cin >> quantity;
    while(quantity < 0){
        cout << "Invalid Input, try again: ";
        cin >> quantity;
    }
    cout << "Input the cost: $";
    cin >> cost;
    while(cost < 0){
        cout << "Invalid Input, try again: ";
        cin >> cost;
    }       
    Inventory item1 = Inventory(itemNumber, quantity, cost);
    
    cout << "\nItem 1: " << endl;
    cout << "Item Number: " << item1.getItemNumber() << endl;
    cout << "Quantity: " << item1.getQuantity() << endl;
    cout << "Cost: $" << setprecision(2) << fixed << item1.getCost() << endl;
    cout << "Total Cost: $" << item1.getTotalCost() << endl;
    
    return 0;
}

