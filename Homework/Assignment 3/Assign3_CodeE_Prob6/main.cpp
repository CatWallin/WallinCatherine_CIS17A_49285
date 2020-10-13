#include <iostream>
#include <iomanip>

using namespace std;

struct MovieData
{
    string title,
           director;
    int    releaseDate,
           runningTime;
};

void displayMovie(MovieData);

int main(){
    
    int expectedInput;
    int heck;
	
	cout << "This program reviews structures" << endl;
	cout << "Input how many movies, the Title of the Movie, Director, Year Released, ";
	cout << "and the Running Time in (minutes)."<< endl;
	cout << endl;
	cin >> expectedInput;
	
	MovieData Movie[expectedInput];
	
	for (int movieIndex = 0; movieIndex < expectedInput; movieIndex++){
	   cin.ignore();
	   getline(cin, Movie[movieIndex].title);
	   getline(cin, Movie[movieIndex].director);
	   cin >> Movie[movieIndex].releaseDate;
	   cin >> Movie[movieIndex].runningTime;
	}
	
	for (int i = 0; i < expectedInput; i++){
	    displayMovie(Movie[i]);
	    if (i < (expectedInput-1)){
	        cout << endl;
	    }
	}
	
	return 0;
}

void displayMovie(MovieData a){
    cout << "Title:     " << a.title << endl;
    cout << "Director:  " << a.director << endl;
    cout << "Year:      " << a.releaseDate << endl;
    cout << "Length:    " << a.runningTime << endl;
}