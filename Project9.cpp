#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int countVowels(char *);
int countConsonants(char *);
int countLetters(char *);
void getString(char*);
void printMenu();

int main()
{
  char userInput[80];
  char selection;

  getString(userInput);


  do
  {
    printMenu();

    cin >> selection;
    cin.ignore();

    if (selection == 'A') {
      cout << "The string has " << countVowels(userInput) << " vowels.\n\n";
      continue;
    }
    else if (selection == 'B') {
      cout << "The string has " << countConsonants(userInput) << " consonants.\n\n";
      continue;
    }
    else if (selection == 'C') {
      cout << "The string has " << countLetters(userInput) << " letters.\n\n";
      continue;
    }
    else if (selection == 'D') {
      getString(userInput);
      continue;
    } else {
      continue;
    }
    
    
    
  } while (selection != 'E');
  

  return 0;
}


int countVowels(char* userInput) {
  int count = 0;

  for (int i = 0; i < strlen(userInput); i++)
  {
    if (isalpha(userInput[i]))
    {
      if (toupper(userInput[i]) == 'A' || toupper(userInput[i]) == 'E' || toupper(userInput[i]) == 'I' || toupper(userInput[i]) == 'O' || userInput[i + 1] == 'U')
      {
        count++;
      }
    }
  }

  return count;
};

int countConsonants(char* userInput) {
  return countLetters(userInput) - countVowels(userInput);
};

int countLetters(char* userInput) {
  int count = 0;

  for (int i = 0; i < strlen(userInput); i++)
  {
    if (isalpha(userInput[i]))
    {
      count++;
    }
  }

  return count;
};

void getString(char* userInput) {
  cout << "Enter a string: ";
  cin.getline(userInput, 80);
};


void printMenu() {
  cout << "\tA) Count the vowels in the string" << endl;
  cout << "\tB) Count the consonants in the string" << endl;
  cout << "\tC) Count both vowels and consonants" << endl;
  cout << "\tD) Enter another string" << endl;
  cout << "\tE) Exit this program" << endl;
  cout << "\tEnter A, B, C, D or E." << endl;
};


