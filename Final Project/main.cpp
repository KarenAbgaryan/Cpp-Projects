#include <iostream>
#include <string>
#include "Customer.h"
#include "CreditCard.h"
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  string firstName;
  string lastName;
  string cardName;
  int cardExpYear;
  int cardExpMonth;
  string cardNumber;
  string typeOfGas;
  int numGalons;
  bool isNotDigit;
  string printReceipt;

  cout << "Enter your first name: " << endl;
  cin >> firstName;

  cout << "Enter your last name: " << endl;
  cin >> lastName;

  cout << "Enter your credit card name (Visa, Mastercard, etc.): " << endl;
  cin >> cardName;

  cout << "Enter your credit card expioration year: " << endl;
  cin >> cardExpYear;

  while (cardExpYear < 2023) {
    cout << "Invalid year try again (must be 2023 or later): " << endl;
    cin >> cardExpYear;
  }

  cout << "Enter your credit card expioration month: " << endl;
  cin >> cardExpMonth;

  while (!(cardExpMonth > 0 && cardExpMonth < 13))
  {
    cout << "Invalid month try again (1 to 12): " << endl;
    cin >> cardExpMonth;
  }

  cout << "Enter your credit card number: " << endl;
  cin >> cardNumber;

  isNotDigit = true;
  while (isNotDigit) {
    isNotDigit = false;
    for (int i = 0; i < cardNumber.size(); i++) {
      if (!(isdigit(cardNumber[i]))) {
        isNotDigit = true;
        break;
      }
    }

    if (isNotDigit == true) {
      cout << "Invalid credit cared number (type numbers between 0-9): " << endl;
      cin >> cardNumber;
    }
  }

  cout << "Select your prefered type of gas (regular or premium): " << endl;
  cin >> typeOfGas;

  while (!(typeOfGas == "Regular" || typeOfGas == "regular" || typeOfGas == "premium" || typeOfGas == "Premium"))
  {
    cout << "Invalid entery. Select your prefered type of gas (regular or premium): " << endl;
    cin >> typeOfGas;
  }

  cout << "Type number of galons: " << endl;
  cin >> numGalons;

  cout << setw(25) << setfill('-') << "" << endl;

  CreditCard creditCard = CreditCard(cardName, cardExpYear, cardExpMonth, cardNumber);
  Customer customer = Customer(firstName, lastName, creditCard, typeOfGas, numGalons);

  cout << "Do you want to print a receipt?: " << endl;
  cin >> printReceipt;

  if (printReceipt == "yes" || printReceipt == "Yes")
  {
    cout << setw(25) << setfill('-') << "" << endl;
    customer.Print();
  } else {
    cout << "Thank you, See you again" << endl;
  }

  return 0;
}
