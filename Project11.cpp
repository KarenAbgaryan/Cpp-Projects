
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Player {
    string name;
    int number;
    int pointsScored;
};


void getData(Player[], int);
void printData(Player[], int, Player, int);
int calculatePoints(Player[], int);
Player TopScorer(Player[], int);

int main()
{
    const int SIZE = 3;
    Player players[SIZE];
    
    getData(players, SIZE);
    
    Player topScorer = TopScorer(players, SIZE);
    int TotalPoints = calculatePoints(players, SIZE);
    
    printData(players, SIZE, topScorer, TotalPoints);

    return 0;
}


void getData(Player players[], int SIZE){
    for(int i = 0; i < SIZE; i++) {
        cout << "Player #" << i + 1 << endl;
        cout << "--------------------" << endl;
        
        cout << "Player name: ";
        getline(cin, players[i].name);
        
        cout << "Player number: ";
        cin >> players[i].number;
        
        cout << "Points scored: ";
        cin >> players[i].pointsScored;
        cin.ignore();
    }
}

void printData(Player players[], int SIZE, Player topScorer, int TotalPoints){
    cout << endl;
    cout << left << setw(12) << "NAME" << left << setw(12) << "NUMBER" << left << setw(12) << "POINTS SCORED" << endl;
    
    for(int i = 0; i < SIZE; i++) {
        cout << left << setw(12) << players[i].name << left << setw(12) << players[i].number << left << setw(12) << players[i].pointsScored << endl;
    }
    
    cout << "TOTAL POINTS: " << TotalPoints << endl;
    cout << "The player who scored the most points is: " << topScorer.name << endl;
}


int calculatePoints(Player players[], int SIZE){
    int totalPoints = 0;
    
    for(int i = 0; i < SIZE; i++) {
        totalPoints += players[i].pointsScored;
    }
    
    return totalPoints;
}

Player TopScorer(Player players[], int SIZE){
    Player topScorer = players[0];
    
    for(int i = 0; i < SIZE - 1; i++) {
        if(players[i + 1].pointsScored > players[i].pointsScored) {
            topScorer = players[i + 1];
        }
    }
    
    return topScorer;
}
