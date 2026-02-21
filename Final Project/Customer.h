#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
// #include <iomanip>
#include "CreditCard.h"

using namespace std;

class Customer {
  public:
    Customer(string fName = "Unknown", string lName = "Unknown", CreditCard creditCard = CreditCard(), string gasType = "Unknown", int numGalons = -1)
        : fName(fName), lName(lName), creditCard(creditCard), gasType(gasType), numGalons(numGalons) {};

    void Print() const {
      cout << lName << endl;
      creditCard.Print();
      cout << "Number of galons: " << numGalons << endl;
      if (gasType == "regular" || gasType == "Regular") {
        cout << "Total cost: $" << (numGalons * 4.00) << endl;
      } else {
        cout << "Total cost: $" << (numGalons * 5.00) << endl;
      }
    }

  private:
    string fName;
    string lName;
    CreditCard creditCard;
    string gasType;
    int numGalons;

};

#endif