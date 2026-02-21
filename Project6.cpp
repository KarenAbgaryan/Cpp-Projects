
#include "iostream"
#include "iomanip"
using namespace std;

double calcAverageScore(double*, int);
void bubbleSort(double*, int);

int main()
{
  int numOfScores;
  double averageScore;

  cout << "How many test scores will you enter? ";
  cin >> numOfScores;

  double* testScoresPtr = new double[numOfScores];

  for (int i = 0; i < numOfScores; i++) {
    do {
      cout << "Enter test score " << i + 1 << ": ";
      cin >> *(testScoresPtr + i);
      if (*(testScoresPtr + i) < 0) {
        cout << "Negative scores are not allowed." << endl;
      }
      
    } while (*(testScoresPtr + i) < 0);
  }

  averageScore = calcAverageScore(testScoresPtr, numOfScores);
  bubbleSort(testScoresPtr, numOfScores);

  cout << "The test scores in ascending order, and their average, are:\n\n";
  cout << " Score\n -----\n\n"; 

  for (int i = 0; i < numOfScores; i++) {
    cout << " " << fixed << setprecision(2) << *(testScoresPtr + i) << endl;
  }
  
  cout << "\nAverage score:  " << fixed << setprecision(2) << averageScore;

  delete[] testScoresPtr;
  return 0;
}


void bubbleSort(double* testScoresPtr, int num) {
    for (int i = 0; i < num - 1; i++) {
      for (int j = 0; j < num - 1; j++) {
        if (*(testScoresPtr + j) > *(testScoresPtr + j + 1)) {
          double temp = *(testScoresPtr + j);
          *(testScoresPtr + j) = *(testScoresPtr + j + 1);
          *(testScoresPtr + j + 1) = temp;
        }
      }
    }
    
}


double calcAverageScore(double* testsScorePtr, int num) {
  double sum = 0;
  for (int i = 0; i < num; i++) {
    sum += *(testsScorePtr + i);
  }
  
  return sum / num;
}
