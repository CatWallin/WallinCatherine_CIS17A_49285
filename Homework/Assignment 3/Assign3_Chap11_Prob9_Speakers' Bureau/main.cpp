

/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 10, 2020, 1:16 PM
 * Chapter 11 Problem 9 -- Speakers' Bureau
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct SpeakerData 
{
    string name;
    float phoneNum;
    string topic;
    float fee;
};

int menuSelect();
void enterSpeakerInfo(SpeakerData &);
void changeSpeakerInfo(SpeakerData &);
void displaySpeakerInfo(SpeakerData speaker);

int main(int argc, char** argv) {

    SpeakerData speaker[10];
    int selection;
    
    selection = menuSelect();
    
    while (selection != 4){
    
    
        if (selection == 1){
            int speakerSelection;
            cout << "Select a speaker (1-10): ";
            cin >> speakerSelection;
            speakerSelection--;
            enterSpeakerInfo(speaker[speakerSelection]);
        }
        else if (selection == 2){
            int speakerSelection;
            cout << "Select a speaker (1-10): ";
            cin >> speakerSelection;
            speakerSelection--;
            changeSpeakerInfo(speaker[speakerSelection]);
        }
        else {
            for (int i = 10; i < 10; i++){
                displaySpeakerInfo(speaker[i]);
            }
        }
        selection = menuSelect();
    }
    
    return 0;
}

int menuSelect(){
int menuSelection;
    
    cout << "Speakers' Bureau Data Menu" << endl;
    cout << "1. Enter Speaker Info" << endl;
    cout << "2. Change Speaker Info" << endl;
    cout << "3. Display Speaker Info" << endl;
    cout << "4. Quit" << endl;
    cout << "Selection: " << endl;
    cin >> menuSelection; 
    
    while (menuSelection < 1 || menuSelection > 4){
        cout << "Invalid Choice, please select again: ";
        cin >> menuSelection;
    }
    return menuSelection;
}

void enterSpeakerInfo(SpeakerData &a){
    cout << "Enter Speaker Name: ";
    cin >> a.name;
    cout << "Enter Speaker's Phone Number: ";
    cin >> a.phoneNum;
    cout << "Enter Speaker's Topic: ";
    cin >> a.topic;
    cout << "Enter Speaker's Fee: ";
    cin >> a.fee;
}

void changeSpeakerInfo(SpeakerData &a){
    int choice;
    cout << "What information would you like to change?" << endl;
    cout << "1. Speaker Name" << endl << "2. Speaker Number" << endl << "3. Speaker Topic" << endl << "4. Speaker Fee" << endl << "5. Quit" << endl;
    cin >> choice;
    while (choice > 5 || choice < 1){
        cout << "Invalid. Please try again: ";
        cin >> choice;
    }
    cout << "Please enter change: ";
    if (choice == 1){
        cin >> a.name;
    }
    else if (choice == 2){
        cin >> a.phoneNum;
    }
    else if (choice == 3){
        cin >> a.topic;
    }
    else if (choice == 4){
        cin >> a.fee;
    }
    else return;
}

void displaySpeakerInfo(SpeakerData a){
    cout << "Speaker: " << a.name;
    cout << "Phone Number: " << a.phoneNum;
    cout << "Topic: " << a.topic;
    cout << "Fee: " << a.fee;
}