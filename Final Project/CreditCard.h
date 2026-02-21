#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <string>
#include <iostream>


using namespace std;

class CreditCard {
  public:
    CreditCard(string cardName = "Unknown", int cardExpYear = -1, int cardExpMonth = -1, string cardNumber = "Unknown")
        : cardName(cardName), cardExpYear(cardExpYear), cardExpMonth(cardExpMonth), cardNumber(cardNumber) {};

    void Print() const {
      cout << "Credit card name: " << cardName << endl;
    }

  private:
    string cardName;
    int cardExpYear;
    int cardExpMonth;
    string cardNumber;
    
};



#endif