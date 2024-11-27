// class Vehicle {
//     float _gallonsOfFuel;
//     int _numPassengers;
//     int _cargoBoxes;
//
// public:
//     void Refuel(float gallons) {
//         _gallonsOfFuel = gallons;
//     }
//
//     void AddPassenger() {
//         _numPassengers++;
//     }
//
//     void LoadCargo() {
//         _cargoBoxes++;
//     }
// };
//
// class Car : public Vehicle {
//     float _bounceHeight;
//
// public:
//     void Bounce() {
//     }
// };
//
// class Airplane : public Vehicle {
//     bool _isLandingGearOut;
//
// public:
//     void DeployLandingGear() {
//     }
// };
//
// int main() {
//     Vehicle someVehicle;
//
//     someVehicle.AddPassenger();
//     someVehicle.LoadCargo();
//     someVehicle.Refuel(2.6f);
//
//
//     return 0;
// }
