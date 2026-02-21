#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct StoreBudget {
  double rent;
  double utilities;
  double supplies;
  double tax;
  double insurance;
  double miscellaneous;
};

void getActualExpenses(StoreBudget&);
double overOrUnderBudget(StoreBudget&, StoreBudget&);
void showResults(StoreBudget&, StoreBudget&);


int main() {
  StoreBudget monthlyBudget = {2000.00, 175.00, 7500.00, 800.00, 350.00, 400.00};
  StoreBudget monthlyExpenses;

  getActualExpenses(monthlyExpenses);

  showResults(monthlyBudget, monthlyExpenses);

  return 0;
}

void getActualExpenses(StoreBudget &expenses){
  cout << "Enter the amount spent for rent: $";
  cin >> expenses.rent;
  cout << "Enter the amount spent for utilities: $";
  cin >> expenses.utilities;
  cout << "Enter the amount spent for supplies: $";
  cin >> expenses.supplies;
  cout << "Enter the amount spent for tax: $";
  cin >> expenses.tax;
  cout << "Enter the amount spent for insurance: $";
  cin >> expenses.insurance;
  cout << "Enter the amount spent for miscellaneous: $";
  cin >> expenses.miscellaneous;
  cout << endl;
}


double overOrUnderBudget(StoreBudget &budget, StoreBudget &expenses) {
  return (
    budget.rent - expenses.rent +
    budget.supplies - expenses.supplies +
    budget.utilities - expenses.utilities +
    budget.insurance - expenses.insurance +
    budget.tax - expenses.tax +
    budget.miscellaneous - expenses.miscellaneous
  );
}

void showResults(StoreBudget &budget, StoreBudget &expenses) {
  double total = overOrUnderBudget(budget, expenses);
  cout << fixed << setprecision(2);
  cout << left << setw(20) << "Type of Expense" << left << setw(12) << "Budgeted" << left << setw(12) << "Spent" << left << setw(12) << "Over(-)/Under" << endl;
  cout << "---------------------------------------------------------------" << endl;
  cout << left << setw(18) << "Rent" << right << setw(10) << budget.rent << right << setw(10) << expenses.rent << right << setw(18) << budget.rent - expenses.rent << endl;
  cout << left << setw(18) << "Utilities" << right << setw(10) << budget.utilities << right << setw(10) << expenses.utilities << right << setw(18) << budget.utilities - expenses.utilities << endl;
  cout << left << setw(18) << "Supplies" << right << setw(10) << budget.supplies << right << setw(10) << expenses.supplies << right << setw(18) << budget.supplies - expenses.supplies << endl;
  cout << left << setw(18) << "Tax" << right << setw(10) << budget.tax << right << setw(10) << expenses.tax << right << setw(18) << budget.tax - expenses.tax << endl;
  cout << left << setw(18) << "Insurance" << right << setw(10) << budget.insurance << right << setw(10) << expenses.insurance << right << setw(18) << budget.insurance - expenses.insurance << endl;
  cout << left << setw(18) << "Miscellanous" << right << setw(10) << budget.miscellaneous << right << setw(10) << expenses.miscellaneous << right << setw(18) << budget.miscellaneous - expenses.miscellaneous << endl;
  if(total >= 0) {
    cout << "For the month you are under the budget by: $" << total << endl;
  } else {
    cout << "For the month you are over the budget by: $" << abs(total) << endl;
  }
};
