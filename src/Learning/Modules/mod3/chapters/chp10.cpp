// #include <iostream>
// using namespace std;

// class Sleep {
// public:
//     Sleep(int hrs = 0, int mins = 0);

//     void Print();

//     int GetHours();

// private:
//     int _hrs;
//     int _mins;
// };

// Sleep::Sleep(int hrs, int mins) {
//     _hrs = hrs;
//     _mins = mins;
// }

// void Sleep::Print() {
//     cout << _hrs << "hrs " << _mins << "mins slept." << endl;
// }

// int Sleep::GetHours() {
//     return _hrs;
// }

// int main() {
//     Sleep *record;
//     record = new Sleep(8, 10);
//     record->Print();
//     cout << "Hrs: " << (*record).GetHours() << endl;
//     delete record;
//     return 0;
// }
//
//
//
// #include <iostream>
// using namespace std;
//
// class Cylinder {
// public:
//    Cylinder(int radiusValue, int heightValue);
//
//    void Print();
//
// private:
//    int radius;
//    int height;
// };
//
// Cylinder::Cylinder(int radiusValue, int heightValue) {
//    radius = radiusValue;
//    height = heightValue;
// }
//
// void Cylinder::Print() {
//    cout << "Cylinder's radius: " << radius << endl;
//    cout << "Cylinder's height: " << height << endl;
// }
//
// int main() {
//    Cylinder *pCylinder = nullptr;
//    int radiusVal;
//    int heightVal;
//
//    cin >> radiusVal;
//    cin >> heightVal;
//
//    pCylinder = new Cylinder(radiusVal, heightVal);
//
//    pCylinder->Print();
//
//    delete pCylinder;
//
//    return 0;
// }
//
//
//
// #include <iostream>
// #include <iomanip>
// using namespace std;
//
// class Duck {
// public:
//     Duck(double ageValue, double weightValue);
//
//     void IncreaseAgeAndWeight();
//
//     void Print();
//
// private:
//     double age;
//     double weight;
// };
//
// Duck::Duck(double ageValue, double weightValue) {
//     age = ageValue;
//     weight = weightValue;
// }
//
// void Duck::IncreaseAgeAndWeight() {
//     age = age * 10.0;
//     weight = weight * 10.0;
//     cout << "Duck's age and weight are increased." << endl;
// }
//
// void Duck::Print() {
//     cout << "Duck's age: " << fixed << setprecision(1) << age << endl;
//     cout << "Duck's weight: " << fixed << setprecision(1) << weight << endl;
// }
//
// int main() {
//     /* Additional variable declarations go here */
//
//     double ageVal;
//     double weightVal;
//
//     cin >> ageVal;
//     cin >> weightVal;
//
//     Duck *duck1 = new Duck(ageVal, weightVal);
//     duck1->IncreaseAgeAndWeight();
//
//     duck1->Print();
//
//     delete duck1;
//
//     return 0;
// }
//
//
//
// //
// #include <iostream>
// using namespace std;
//
// class Sheep {
// public:
//     Sheep();
//
//     void Read();
//
//     void Print();
//
// private:
//     int age;
//     int weight;
// };
//
// Sheep::Sheep() {
//     age = 0;
//     weight = 0;
// }
//
// void Sheep::Read() {
//     cin >> age;
//     cin >> weight;
// }
//
// void Sheep::Print() {
//     cout << "Sheep's age: " << age << endl;
//     cout << "Sheep's weight: " << weight << endl;
// }
//
// int main() {
//     Sheep *sheepPtr = nullptr;
//
//     sheepPtr = new Sheep;
//     (*sheepPtr).Read();
//     sheepPtr->Print();
//     delete sheepPtr;
//     return 0;
// }
