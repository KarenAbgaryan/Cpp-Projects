#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int countWords(char*);

int main() {
  char userInput[80];

  cout << "Enter a C-String containing 80 or fewer words: ";
  cin.getline(userInput, 80);

  cout << "\nThe number of words in the C-String: " << countWords(userInput) << endl;


  return 0;
}

int countWords(char* userInput){
  int count = 0;

  for(int i = 0; i < strlen(userInput); i++) {
    if (isspace(userInput[i])) {
      if(isalpha(userInput[i + 1])){
        count++;
      }
    }
    
  }

  return count + 1;
}