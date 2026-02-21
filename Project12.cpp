#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

bool openfile(ifstream&, string);

int main() {
  ifstream infile;
  string line;
  string findInText;
  string fileName;
  int sum = 0;

  cout << "Enter the file name you would like to open: ";
  cin >> fileName;
  cout << "Enter string to search for: ";
  cin >> findInText;

  while(!openfile(infile, fileName)) {
    cout << "There are no files found with this file name. Please try again: ";
    cin >> fileName;
  }


  cout << "\nYour file was opened successfully." << endl;
  cout << "Reading the file contents.\n" << endl;


  while(infile) {
    int pos = 0;
    getline(infile, line);

    if (line.find(findInText) != string::npos) {
      cout << line << endl;
      while((pos = line.find(findInText, pos)) != string::npos) {
        sum++;
        pos += findInText.length();
      }
    }
    
  }

  cout << "\n\"" << findInText << "\" was found " << sum << " times." << endl;

  return 0;
}


bool openfile(ifstream& file, string fileName) {
  file.open(fileName);
  if(file.fail()) 
    return false;

  return true;
}









