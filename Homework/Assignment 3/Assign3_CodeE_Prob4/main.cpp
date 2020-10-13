#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MachineData
{
    string drinkName;
    int cost;
    int number;
};

MachineData drink[5] = {
    { "Cola", 75, 20 },
    { "Root Beer", 75, 20 },
    { "Lemon-Lime", 75, 20 },
    { "Grape Soda", 80, 20 },
    { "Cream Soda", 80, 20 }
};

bool validateMoneyInput(int);
string promptUserSelectSoda();

int main(){
    string sodaSelection;
    int insertedMoney;
	int totalMoneyInputed;
	int totalMoneyMade = 0;
	
	for (int i = 0; i < 5; i++){
	    cout << left << setw(11) << drink[i].drinkName << setw(4) << drink[i].cost << drink[i].number << endl;
	}
	cout << "Quit" << endl;
	sodaSelection = promptUserSelectSoda();
	
	
	while (sodaSelection != "Quit"){
	    int change;
	    
	    cin >> insertedMoney;
	    
	   // while (validateMoneyInput(insertedMoney) == false){
	   //     cin >> insertedMoney;
	   // }
	    
	    for (int i = 0; i < 5; i++){
	        if (sodaSelection == drink[i].drinkName){
	            change = insertedMoney - drink[i].cost;
	            drink[i].number--;
	            totalMoneyInputed += insertedMoney;
	            totalMoneyMade += drink[i].cost;
	            break;
	        }
	    }
	    cout << change << endl;
	    for (int i = 0; i < 5; i++){
	    cout << left << setw(11) << drink[i].drinkName << setw(4) << drink[i].cost << drink[i].number << endl;
	    }
	    cout << "Quit" << endl;
	    cin.ignore();
        sodaSelection = promptUserSelectSoda();
	}
	cout << totalMoneyMade << endl;
	return 0;
}

bool validateMoneyInput(int amount){
    if (amount < 0 || amount > 1){
        return 0;
    }
    else {
        return 1;
    }
}

string promptUserSelectSoda(){
    string soda;
    getline(cin, soda);
    return soda;
}