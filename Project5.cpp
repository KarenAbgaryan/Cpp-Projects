
#include "iostream"
#include "iomanip"
#include "string"
using namespace std;

double findPrice(string[], double[], string, const int);

int main()
{
  const int SIZE = 6;
  string addins[SIZE] = { "Cream", "Cinnamon", "Chocolate", "Amaretto", "Whiskey", "None" };
  double pricing[SIZE] = {0.50, 0.75, 0.75, 2.00, 2.50, 0.00};
  string userchoice;
  double total = 4.00;

  cout << "Welcome to the coffee shop!" << endl;
  cout << "The base price for coffee is $4.00" << endl;
  cout << "Here are the available add-ins:" << "\n\n";

  for (int i = 0; i < SIZE; i++) {
    cout << left << setw(12) << addins[i] << " $" << fixed << setprecision(2) << pricing[i] << endl;
  }

  do {
    double addinPrice;
    cout << "\nEnter your choice or enter 'stop' to quit: " << endl;
    cin >> userchoice;
    addinPrice = findPrice(addins, pricing, userchoice, SIZE);

    if(addinPrice == -1) {
      continue;
    }

    total += addinPrice;
    cout << "Add-in price is: $" << fixed << setprecision(2) << addinPrice << endl;
    cout << "Your price including your add-ins is $" << fixed << setprecision(2) << total << endl;

  } while (userchoice != "stop");

  return 0;
}

double findPrice(string addins[], double pricing[], string userchoice, const int SIZE) {
  for (int i = 0; i < SIZE; i++)
  {
    if (addins[i] == userchoice) {
      return pricing[i];
    }
  }

  if (userchoice != "stop")
    cout << "The " << userchoice << " add-in is not available.\nPlease choose something from the list." << endl;
  
  return -1;
}