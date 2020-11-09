
/* 
 * File:   main.cpp
 * Author: Catherine
 * Created on November 3, 2020, 12:35 PM
 * Chapter 13 Problem 4: Patient Charges
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Patient
{
private:
    string firstName, middleName, lastName, address, city, state,
           zipCode, phoneNum, emergencyName, emergencyNum;
public:
    Patient(string firstName, string middleName, string lastName, string address, string city, string state, string zipCode, string phoneNum, string emergencyName, string emergencyNum){
        this->firstName = firstName;
        this->middleName = middleName;
        this->lastName = lastName;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zipCode = zipCode;
        this->phoneNum = phoneNum;
        this->emergencyName = emergencyName;
        this->emergencyNum = emergencyNum;
    }
    
    // first name
    void setFirstName(string firstName) { this->firstName = firstName; }
    string getFirstName() { return firstName; }
    
    // middle name 
    void setMiddleName(string middleName) { this->firstName = firstName; }
    string getMiddleName() { return middleName; }
    
    // last name
    void setLastName(string lastName) { this->lastName = lastName; }
    string getLastName() { return lastName; }
    
    // address
    void setAddress(string address) { this->address = address; }
    string getAdress() { return address; }
    
    // city
    void setCity(string city) { this->city = city; }
    string getCity() { return city; }
    
    // state
    void setState(string state) { this->state = state; }
    string getState() { return state; }
    
    // zip code
    void setZipCode(string zipCode) { this->zipCode = zipCode; }
    string getZipCode() { return zipCode; }
    
    // phone number
    void setPhoneNum(string phoneNum) { this->phoneNum = phoneNum; }
    string getPhoneNum() { return phoneNum; }
    
    // emergency name
    void setEmergencyName(string emergencyName) { this->emergencyName = emergencyName; }
    string getEmergencyName() { return emergencyName; }
    
    // emergency number 
    void setEmergencyNum(string emergencyNum) { this->emergencyNum = emergencyNum; }
    string getEmergencyNum() { return emergencyNum; }
     
};

class Procedure
{
private:
    string name, date, practitioner;
    float charges;
public:
    Procedure(string name, string date, string practitioner, float charges){
        this->name = name;
        this->date = date;
        this->practitioner = practitioner;
        this->charges = charges;
    }
    
    // name
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    
    // date
    void setDate(string date) { this->date = date; }
    string getDate() { return date; }
    
    // practitioner
    void setPractitioner(string practitioner) { this->practitioner = practitioner; }
    string getPractitioner() { return practitioner; }
    
    // charges
    void setCharges(float charges) { this->charges = charges; }
    float getCharges() { return charges; }
};

int main(int argc, char** argv) {

    Patient patient = Patient("Hammy", "Wallin", "Scott", "1785 Pitter Lane", "Hecksville", "CA", 
            "92530", "(951)867-5309", "Doge Wallin", "(951)123-4567");
    
    Procedure procedure1 = Procedure("Physical Exam", "11/8/2020", "Dr. Irvine", 250.00);
    Procedure procedure2 = Procedure("X-ray", "11/8/2020", "Dr. Jamison", 500.00);
    Procedure procedure3 = Procedure("Blood Test", "11/8/2020", "Dr. Smith", 200.00);
    
    cout << "Patient Information: " << endl;
    cout << "Name: " << patient.getFirstName() << " " << patient.getMiddleName() << " " << patient.getLastName() << endl;
    cout << "Address: " << patient.getAdress() << " " << patient.getCity() << " " << patient.getState() << " " << patient.getZipCode() << endl;
    cout << "Phone Number: " << patient.getPhoneNum() << endl;
    cout << "Emergency Contact: " << patient.getEmergencyName() << endl;
    cout << "Emergency Contact Number: " << patient.getEmergencyNum() << endl << endl;
    
    cout << "Procedure #1: " << procedure1.getName() << endl;
    cout << "Date: " << procedure1.getDate() << endl;
    cout << "Practitioner: " << procedure1.getPractitioner() << endl;
    cout << "Charges: $" << setprecision(2) << fixed << procedure1.getCharges() << endl << endl; 
    
    cout << "Procedure #2: " << procedure2.getName() << endl;
    cout << "Date: " << procedure2.getDate() << endl;
    cout << "Practitioner: " << procedure2.getPractitioner() << endl;
    cout << "Charges: $" << setprecision(2) << fixed << procedure2.getCharges() << endl << endl; 
    
    cout << "Procedure #3: " << procedure3.getName() << endl;
    cout << "Date: " << procedure3.getDate() << endl;
    cout << "Practitioner: " << procedure3.getPractitioner() << endl;
    cout << "Charges: $" << setprecision(2) << fixed << procedure3.getCharges() << endl << endl;
    
    cout << "Total charges for all procedures: $" << (procedure1.getCharges() + procedure2.getCharges() + procedure3.getCharges());
    
    return 0;
}

