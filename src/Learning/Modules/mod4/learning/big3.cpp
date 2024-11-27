// #include <iostream>
// using namespace std;
//
// class LItem {
//     string _name;
//     string _description;
//     int _quantity;
//     float _price;
//
// public:
//     LItem();
//
//     LItem(const LItem &otherObj); //copy constructor
//     LItem &operator=(const LItem &otherObj); //copy asignment operator
// };
//
// LItem::LItem() {
//     _name, _description = "N/A";
//     _quantity, _price = 0;
// }
//
// LItem::LItem(const LItem &otherObj) {
//     //Copy EVERYTHING from 'other' into 'this'
//     _name = otherObj._name;
//     _description = otherObj._description;
//     _quantity = otherObj._quantity;
// }
//
// LItem &LItem::operator=(const LItem &otherObj) {
//     //copy ∀thing from the 'other' obj into 'this'
//     _price = otherObj._price;
//     _name = otherObj._name;
//     _description = otherObj._description;
//     _quantity = otherObj._quantity;
//     _price = otherObj._price;
//
//     return *this; //always the last line / return
// }
//
//
// int main() {
//     //default constructor called to create objs
//     LItem a, b;
//     LItem c = a;
//     c = b;
//     return 0;
// }
