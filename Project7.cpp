
#include "iostream"
#include "iomanip"
using namespace std;

double calcTotalBooks(double *, int);
double calcAverageBooks(double *, int);

int main()
{
  int numOfStudents;
  double averageBooks;
  double totalBooks;

  cout << "How many students were surveyed? ";
  cin >> numOfStudents;

  double *booksReadPtr = new double[numOfStudents];

  cout << "Enter the number of books read by each student: " << endl;

  for (int i = 0; i < numOfStudents; i++)
  {
    do
    {
      cout << "Student " << i + 1 << ": ";
      cin >> *(booksReadPtr + i);
      if (*(booksReadPtr + i) <= 0)
      {
        cout << "The number of scores must be greater than zero." << endl;
      }

    } while (*(booksReadPtr + i) <= 0);
  }

  averageBooks = calcAverageBooks(booksReadPtr, numOfStudents);
  totalBooks = calcTotalBooks(booksReadPtr, numOfStudents);

  cout << "\nThe total number of books read by the students are: " << totalBooks << "." << endl;
  cout << "\nThe average number of books read by the students are: " << averageBooks << ".";

  delete[] booksReadPtr;
  return 0;
}

double calcTotalBooks(double *bookReadPtr, int num)
{
  double total = 0;
  for (int i = 0; i < num; i++)
  {
    total += *(bookReadPtr + i);
  }

  return total;
}

double calcAverageBooks(double *bookReadPtr, int num)
{
  return calcTotalBooks(bookReadPtr, num) / num;
}


