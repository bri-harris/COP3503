//
// Created by Harris, Brianna on 9/5/24.
//
//
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
//
// class Review {
// public:
//     void SetRateCmnt(int revRating, string revComment) {
//         rating = revRating;
//         comment = revComment;
//     }
//
//     int GetRating() const { return rating; }
//     string GetComment() const { return comment; }
//
// private:
//     int rating = -1;
//     string comment = "NoComment";
// };
//
// class Reviews {
// public:
//     void InputReviews();
//
//     void OutCmntsForRate(int currRating) const;
//
//     int GetAvgRate() const;
//
// private:
//     vector<Review> reviewList;
// };
//
// //Get rating comment pairs, add ∀to list. -rating ends
// void Reviews::InputReviews() {
//     Review currReview;
//     int currRating;
//     string currComment;
//
//     cin >> currRating;
//     while (currRating >= 0) {
//         getline(cin, currComment);
//         currReview.SetRateCmnt(currRating, currComment);
//         reviewList.push_back(currReview);
//         cin >> currRating;
//     }
// }
//
// //print ∀ cmts for reviews w/ given rating
// void Reviews::OutCmntsForRate(int currRating) const {
//     for (unsigned int i = 0; i < reviewList.size(); ++i) {
//         Review currReview = reviewList.at(i);
//         if (currRating == currReview.GetRating()) {
//             cout << currReview.GetComment() << endl;
//         }
//     }
// }
//
// int Reviews::GetAvgRate() const {
//     int ratingsSum = 0;
//
//     for (unsigned int i = 0; i < reviewList.size(); ++i) {
//         ratingsSum += reviewList.at(i).GetRating();
//     }
//     return (ratingsSum / reviewList.size());
// }
//
// class Restaurant {
// public:
//     void SetName(string rName) {
//         name = rName;
//     }
//
//     void ReadReviews();
//
//     void PrintComtsByRate() const;
//
// private:
//     string name;
//     Reviews reviews;
// };
//
// void Restaurant::ReadReviews() {
//     cout << "type ratings & comments. =1 to q." << endl;
//     reviews.InputReviews();
// }
//
// void Restaurant::PrintComtsByRate() const {
//     cout << "cmts ∀ rate: " << endl;
//     for (int i = 1; i <= 5; ++i) {
//         cout << i << ":" << endl;
//         reviews.OutCmntsForRate(i);
//     }
// }
//
// int main() {
//     Restaurant ourPlace;
//     string currName;
//
//     cout << "Type restaurant name: " << endl;
//     getline(cin, currName);
//     ourPlace.SetName(currName);
//     cout << endl;
//
//     ourPlace.ReadReviews();
//     cout << endl;
//
//     ourPlace.PrintComtsByRate();
//
//     return 0;
// }
