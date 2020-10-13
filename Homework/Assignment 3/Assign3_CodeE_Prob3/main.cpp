/* 
 * File:   
 * Author: Catherine Wallin
 * Created on 10/6/2020 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
struct Budget
{
    float housing,
          utilities,
          householdExpenses,
          transportation,
          food,
          medical,
          insurance,
          entertainment,
          clothing,
          misc;
};

//Function Prototypes
void budgetInput(Budget &);
void overUnder(Budget, Budget);
void display(float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    
    Budget Month = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 
                    150.00, 75.00, 50.00};
    Budget Spent;
    float totalBudget;
    float totalSpent;
    float difference;

    budgetInput(Spent);
    
    overUnder(Month, Spent);
    
    totalBudget = (Month.housing + Month.utilities + Month.householdExpenses 
    + Month.transportation + Month.food + Month.medical + Month.insurance
    + Month.entertainment + Month.clothing + Month.misc);
    
    totalSpent = (Spent.housing + Spent.utilities + Spent.householdExpenses 
    + Spent.transportation + Spent.food + Spent.medical + Spent.insurance
    + Spent.entertainment + Spent.clothing + Spent.misc);
    
    if (totalBudget > totalSpent){
        difference = totalBudget - totalSpent;
        cout << setprecision(2) << fixed << "You were $" << difference;
        cout << " under budget";
    }
    else {
        difference = totalSpent - totalBudget;
        cout << setprecision(2) << fixed << "You were $" << difference;
        cout << " over budget";
    }
    

    //Exit stage right!
    return 0;
}

void budgetInput(Budget &a){
    cout << "Enter housing cost for the month:$" << endl;
    cin >> a.housing;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> a.utilities;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> a.householdExpenses;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> a.transportation;
    cout << "Enter food cost for the month:$" << endl;
    cin >> a.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> a.medical;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> a.insurance;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> a.entertainment;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> a.clothing;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> a.misc;
}

void overUnder(Budget a, Budget b){
    cout << "Housing ";
    display(a.housing, b.housing);
    
    cout << "Utilities ";
    display(a.utilities, b.utilities);
    
    cout << "Household Expenses ";
    display(a.householdExpenses, b.householdExpenses);
    
    cout << "Transportation ";
    display(a.transportation, b.transportation);
    
    cout << "Food ";
    display(a.food, b.food);
    
    cout << "Medical ";
    display(a.medical, b.medical);
    
    cout << "Insurance ";
    display(a.insurance, b.insurance);
    
    cout << "Entertainment ";
    display(a.entertainment, b.entertainment);
    
    cout << "Clothing ";
    display(a.clothing, b.clothing);
    
    cout << "Miscellaneous ";
    display(a.misc, b.misc);
    
}

void display(float a, float b){
    if (a == b){
        cout << "Even" << endl;
    }
    else if (b > a){
        cout << "Over" << endl;
    }
    else {
        cout << "Under" << endl;
    }
}