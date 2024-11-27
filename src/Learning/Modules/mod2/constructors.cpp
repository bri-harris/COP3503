// #include <iostream>
// #include <string>
// using namespace std;

// class Eat {
// public:
//     Eat();

//     Eat(string iName, int iRating = -1);

//     void SetName(string name);

//     void SetRating(int userRating);

//     void Print();

// private:
//     string _name;
//     int _rating;
// };

// Eat::Eat() {
//     _name = "NoName";
//     _rating = -1;
// }

// Eat::Eat(string iName, int iRating) {
//     _name = iName;
//     _rating = iRating;
// }

// void Eat::SetName(string name) {
//     _name = name;
// }

// void Eat::SetRating(int userRating) {
//     _rating = userRating;
// }

// void Eat::Print() {
//     cout << _name << " -- " << _rating << endl;
// }

// int main() {
//     Eat lunch;
//     Eat coffee("Joes");
//     Eat coffee2("Joes2", 5);
//     lunch.Print();
//     coffee.Print();
//     coffee2.Print();

//     Eat places[10];

//     return 0;
// }


// CHALLENGE
// #include <iostream>
// #include <string>
// using namespace std;
//
// class Book {
// public:
//     Book();
//
//     void SetAuthor(string bookAuthor);
//
//     void SetNumWords(int bookNumWords);
//
//     void Print();
//
// private:
//     string author;
//     int numWords;
// };
//
// Book::Book() {
//     author = "Undefined";
//     numWords = 1;
// }
//
//
// void Book::SetAuthor(string bookAuthor) {
//     author = bookAuthor;
// }
//
// void Book::SetNumWords(int bookNumWords) {
//     numWords = bookNumWords;
// }
//
// void Book::Print() {
//     cout << "Author: " << author << ", Number of words: " << numWords << endl;
// }
//
// int main() {
//     string newAuthor;
//     int newNumWords;
//     Book myBook;
//
//     myBook.Print();
//
//     cin >> newAuthor;
//     cin >> newNumWords;
//
//     myBook.SetAuthor(newAuthor);
//     myBook.SetNumWords(newNumWords);
//
//     myBook.Print();
//
//     return 0;
// }
