
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 6, 2020, 3:43 PM
 * Chapter 13 Problem 7: Test Scores Class
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class TestScores
{
private:
    int testScore1, testScore2, testScore3, averageScore;
public:
    TestScores(int testScore1,int testScore2,int testScore3){
        this->testScore1 = testScore1;
        this->testScore2 = testScore2;
        this->testScore3 = testScore3;
        setAverageScore();
    }
    
    void setTestScore1(int testScore1) { this->testScore1 = testScore1; }
    int getTestScore1() { return testScore1; }
    
    void setTestScore2(int testScore2) { this->testScore2 = testScore2; }
    int getTestScore2() { return testScore2; }
    
    void setTestScore3(int testScore3) { this->testScore3 = testScore3; }
    int getTestScore3() { return testScore3; }
    
    void setAverageScore() { averageScore = ((testScore1 + testScore2 + testScore3) / 3); }
    int getAverageScore() { return averageScore; }
};

int main(int argc, char** argv) {

    int testScore1, testScore2, testScore3;
    
    cout << "Enter the score for test 1: ";
    cin >> testScore1;
    cout << "Enter the score for test 2: ";
    cin >> testScore2;
    cout << "Enter the score for test 3: ";
    cin >> testScore3;
    
    TestScores testScores = TestScores(testScore1, testScore2, testScore3);
    
    cout << "The average of the test scores: " << testScores.getAverageScore() << endl;
    
    return 0;
}

