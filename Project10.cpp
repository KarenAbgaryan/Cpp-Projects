#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MovieData {
  string title;
  string director;
  int yearReleased;
  int runningTime;
  double productionCost;
  double firstYearRevenues;
};


void printMovieData(MovieData); 

int main() {
  MovieData movie1 = {
      "Rocky 1",
      "John G. Avildsen",
      1976,
      120,
      1000000,  // ~$1 million estimated production cost
      117000000 // ~$117 million in revenue over 5 years
  };

  MovieData movie2 = {
      "John Wick 4",
      "Chad Stahelski",
      2023,
      169,
      100000000, // ~$100 million production cost
      432000000  // ~$432 million revenue over 5 years
  };


  printMovieData(movie1);
  printMovieData(movie2);

  return 0;
}

void printMovieData(MovieData movie) {
  cout << "Movie Title: " << movie.title << endl;
  cout << "Director: " << movie.director << endl;
  cout << "Year Released: " << movie.yearReleased << endl;
  cout << "Running Time: " << movie.runningTime << " minutes" << endl;

  cout << fixed << setprecision(2);
  cout << "Production Cost: $" << movie.productionCost << endl;
  cout << "First-Year Revenues: $" << movie.firstYearRevenues << endl;
  cout << "First-Year Profits: $" << movie.firstYearRevenues - movie.productionCost << endl;

  cout << "-------------------------------------------" << endl;
}

