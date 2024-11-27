
// #include <vector>
// #include <iostream>
// using namespace std;
//
//
// class Coordinate {
// public:
//     void SetXAndY(int coordinateX, int coordinateY) {
//         x = coordinateX;
//         y = coordinateY;
//     }
//
//     void PrintCoordinate() const {
//         cout << x << " - " << y << endl;
//     }
//
//     int GetX() const { return x; }
//     int GetY() const { return y; }
//
// private:
//     int x;
//     int y;
// };
//
// int main() {
//     vector<Coordinate> criticalPoints;
//     Coordinate currCoordinate;
//     int currX;
//     int currY;
//     unsigned int i;
//
//     cin >> currX;
//     cin >> currY;
//     while ((currX >= 0) && (currY >= 0)) {
//         currCoordinate.SetXAndY(currX, currY);
//         criticalPoints.push_back(currCoordinate);
//         cin >> currX;
//         cin >> currY;
//     }
//
//     for (i = 0; i < criticalPoints.size(); ++i) {
//         currCoordinate = criticalPoints.at(i);
//         currCoordinate.PrintCoordinate();
//     }
//
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
//
// class Song {
// public:
//     void SetDurationAndName(int songDuration, string songName) {
//         duration = songDuration;
//         name = songName;
//     }
//
//     void PrintSong() const {
//         cout << duration << " - " << name << endl;
//     }
//
//     int GetDuration() const { return duration; }
//     string GetName() const { return name; }
//
// private:
//     int duration;
//     string name;
// };
//
// int main() {
//     vector<Song> songPlaylist;
//     Song currSong;
//     int currDuration;
//     string currName;
//     unsigned int i;
//
//     cin >> currDuration;
//     while (currDuration >= 0) {
//         cin >> currName;
//         currSong.SetDurationAndName(currDuration, currName);
//         songPlaylist.push_back(currSong);
//
//
//         cin >> currDuration;
//     }
//
//     for (i = 0; i < songPlaylist.size(); ++i) {
//         currSong = songPlaylist.at(i);
//         currSong.PrintSong();
//     }
//
//     return 0;
// }
//
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
//
// class Song {
// public:
//     void SetDurationAndName(int songDuration, string songName) {
//         duration = songDuration;
//         name = songName;
//     }
//
//     void PrintSong() const {
//         cout << duration << " - " << name << endl;
//     }
//
//     int GetDuration() const { return duration; }
//     string GetName() const { return name; }
//
// private:
//     int duration;
//     string name;
// };
//
// class Album {
// public:
//     void SetName(string albumName) { name = albumName; }
//
//     void InputSongs();
//
//     void PrintName() const { cout << name << endl; }
//
//     void PrintSongsLongerThan(int songDuration) const;
//
// private:
//     string name;
//     vector<Song> albumSongs;
// };
//
// void Album::InputSongs() {
//     Song currSong;
//     int currDuration;
//     string currName;
//
//     cin >> currDuration;
//     while (currDuration >= 0) {
//         cin >> currName;
//         currSong.SetDurationAndName(currDuration, currName);
//         albumSongs.push_back(currSong);
//         cin >> currDuration;
//     }
// }
//
// void Album::PrintSongsLongerThan(int songDuration) const {
//     unsigned int i;
//     Song currSong;
//
//     cout << "Songs longer than " << songDuration << " seconds:" << endl;
//
//     for (i = 0; i < albumSongs.size(); ++i) {
//         currSong = albumSongs.at(i);
//         if (currSong.GetDuration() > songDuration) {
//             currSong.PrintSong();
//         }
//     }
// }
//
// int main() {
//     Album musicAlbum;
//     string albumName;
//
//     getline(cin, albumName);
//     musicAlbum.SetName(albumName);
//     musicAlbum.InputSongs();
//     musicAlbum.PrintName();
//     musicAlbum.PrintSongsLongerThan(210);
//
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
//
// class Member {
// public:
//     void SetDetails(string newName, int newAge);
//
//     void Print() const;
//
// private:
//     string name;
//     int age;
// };
//
// void Member::SetDetails(string newName, int newAge) {
//     name = newName;
//     age = newAge;
// }
//
// void Member::Print() const {
//     cout << "Member: " << name << ", Age: " << age << endl;
// }
//
// int main() {
//     vector<Member> memberList;
//     Member currMember;
//     string currName;
//     int currAge;
//     int memberCount;
//     unsigned int i;
//
//     cin >> memberCount;
//     for (i = 0; i < memberCount; ++i) {
//         cin >> currName;
//         cin >> currAge;
//
//         currMember.SetDetails(currName, currAge);
//         memberList.push_back(currMember);
//     }
//
//     for (i = 0; i < memberList.size(); ++i) {
//         currMember = memberList.at(i);
//         currMember.Print();
//     }
//
//     return 0;
// }


// #include <iostream>
// #include <vector>
// using namespace std;
//
// class City {
// public:
//     bool ReadDetails();
//
//     void Print() const;
//
// private:
//     int population;
//     string name;
// };
//
// bool City::ReadDetails() {
//     int newPopulation;
//
//     cin >> newPopulation;
//     if (newPopulation == -1) {
//         return false;
//     } else {
//         population = newPopulation;
//         cin >> name;
//         return true;
//     }
// }
//
// void City::Print() const {
//     cout << "City population: " << population << ", Name: " << name << endl;
// }
//
// int main() {
//     vector<City> cityList;
//     City currCity;
//     bool result;
//     unsigned int i;
//
//     result = currCity.ReadDetails();
//     while (result) {
//         cityList.push_back(currCity);
//         result = currCity.ReadDetails();
//     }
//
//     for (i = 0; i < cityList.size(); ++i) {
//         currCity = cityList.at(i);
//         currCity.Print();
//     }
//
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
//
// class Student {
// public:
//     void SetDetails(string newName, int newAge);
//
//     int GetAge() const;
//
// private:
//     string name;
//     int age;
// };
//
// void Student::SetDetails(string newName, int newAge) {
//     name = newName;
//     age = newAge;
// }
//
// int Student::GetAge() const {
//     return age;
// }
//
// class Appointments {
// public:
//     void InputStudents();
//
//     int FindLowestStudentAge();
//
// private:
//     vector<Student> studentList;
// };
//
// void Appointments::InputStudents() {
//     Student currStudent;
//     string currName;
//     int currAge;
//     int studentCount;
//     unsigned int i;
//
//     cin >> studentCount;
//     for (i = 0; i < studentCount; ++i) {
//         cin >> currName;
//         cin >> currAge;
//
//         currStudent.SetDetails(currName, currAge);
//         studentList.push_back(currStudent);
//     }
// }
//
// int Appointments::FindLowestStudentAge() {
//     int lowestAge = studentList.at(0).GetAge();
//     for (int i = 0; i < studentList.size(); ++i) {
//         if (studentList.at(i).GetAge() < lowestAge) lowestAge = studentList.at(i).GetAge();
//     }
//     return lowestAge;
// }
//
//
// int main() {
//     Appointments appointments;
//
//     appointments.InputStudents();
//     cout << "Lowest student age: " << appointments.FindLowestStudentAge() << endl;
//
//     return 0;
// }
//
// #include <iostream>
// using namespace std;
//
// int main() {
//     int userNum;
//     int uNum2;
//     cout << "Enter integer:" << endl;
//     cin >> userNum;
//
//     cout << "You entered: " << userNum << endl;
//     int uSquared = userNum * userNum;
//     cout << userNum << " squared is " << uSquared << endl;
//     cout << "And " << userNum << " cubed is " << uSquared * userNum << "!!" << endl;
//     cout << "Enter another integer:" << endl;
//     cin >> uNum2;
//     cout << userNum << " + " << uNum2 << " is " << userNum + uNum2 << endl;
//     cout << userNum << " * " << uNum2 << " is " << userNum * uNum2 << endl;
//
//     return 0;
// }




