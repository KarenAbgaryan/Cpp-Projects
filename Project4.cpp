
#include "iostream"
#include "iomanip"
using namespace std;

void getInput(double[], const int);
void calculateSum(double[], const int);
void calculateProduct(double[], const int);


int main() {
  const int SIZE = 5;
  double numArray[SIZE];

  getInput(numArray, SIZE);
  calculateSum(numArray, SIZE);
  calculateProduct(numArray, SIZE);

  return 0;
}

void getInput(double numArray[], const int SIZE) {
  cout << "Enter the 5 numbers:" << endl;

  for (int i = 0; i < SIZE; i++) {
    cout << "Number " << i + 1 << ": ";
    cin >> numArray[i];
  }
  
}

void calculateSum(double numArray[], const int SIZE) {
  double Sum = 0;

  for (int i = 0; i < SIZE; i++) {
    Sum += numArray[i];
  }

  cout << "\nThe Sum of the numbers is: " << fixed << setprecision(2) << Sum << endl;
}

void calculateProduct(double numArray[], const int SIZE) {
  double Product = 1;

  for (int i = 0; i < SIZE; i++)
  {
    Product *= numArray[i];
  }

  cout << "The Product of the numbers is: " << fixed << setprecision(2) << Product << endl;
}