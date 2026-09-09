// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

#include <iostream>

using namespace std;

int main(){
    const int current_population = 312032486, 
              seconds_in_a_year = 365 * 24 * 60 * 60,
              secondperbirth = 7,
              secondperdeath = 13,
              secondperimmigrant = 45;
    int population = current_population;          
       
    cout << "Current population:" << current_population << endl;
    for (int year = 1; year <= 5; year ++){
        int births = seconds_in_a_year / secondperbirth;
        int deaths = seconds_in_a_year / secondperdeath;
        int immigrants = seconds_in_a_year / secondperimmigrant;
        population = population + births + immigrants - deaths;
        cout << "Population after year " << year << ": " << population << endl; 
    }
}
