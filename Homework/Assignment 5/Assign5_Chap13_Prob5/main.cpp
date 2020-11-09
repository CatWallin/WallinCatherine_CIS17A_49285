/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 4, 2020, 10:33 AM
 * Chapter 13 Problem 5: RetailItem Class
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class RetailItem
{
private:
    string description;
    int unitsOnHand;
    double price;
public:
    RetailItem(string description, int unitsOnHand, double price){
        this->description = description;
        this->unitsOnHand = unitsOnHand;
        this->price = price;
    }
    
    void setDescription(string description) { this->description = description; }
    string getDescription() { return description; }
    
    void setUnitsOnHand(int unitsOnHand) { this->unitsOnHand = unitsOnHand; }
    int getUnitsOnHand() { return unitsOnHand; }
    
    void setPrice(double price) { this->price = price; }
    double getPrice() { return price; }
    
};

int main(int argc, char** argv) {

    RetailItem item1 = RetailItem("Jacket", 12, 59.95);
    RetailItem item2 = RetailItem("Designer Jeans", 40, 34.95);
    RetailItem item3 = RetailItem("Shirt", 20, 24.95);
    
    cout << "Item #1: " << item1.getDescription() << endl;
    cout << "Units on Hand: " << item1.getUnitsOnHand() << endl;
    cout << "Price: $" << setprecision(2) << fixed << item1.getPrice() << endl << endl;
    
    cout << "Item #2: " << item2.getDescription() << endl;
    cout << "Units on Hand: " << item2.getUnitsOnHand() << endl;
    cout << "Price: $" << setprecision(2) << fixed << item2.getPrice() << endl << endl;
    
    cout << "Item #3: " << item3.getDescription() << endl;
    cout << "Units on Hand: " << item3.getUnitsOnHand() << endl;
    cout << "Price: $" << setprecision(2) << fixed << item3.getPrice() << endl << endl;
    
    return 0;
}

