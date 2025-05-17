#include <iostream>
#include <string>

enum class RadarType { RADAR1, RADAR2, RADAR3 };
enum class StrengthType { LOW, MEDIUM, HIGH };
enum class AgilityType { SLOW, NORMAL, FAST };

class Vehicle {
    std::string name;
    RadarType radar;
    StrengthType strength;
    AgilityType agility;
public:
    Vehicle(std::string n, RadarType r, StrengthType s, AgilityType a)
        : name(n), radar(r), strength(s), agility(a) {}

    void print() {
        std::cout << "Vehicle: " << name
                  << "\nRadar: " << static_cast<int>(radar)
                  << "\nStrength: " << static_cast<int>(strength)
                  << "\nAgility: " << static_cast<int>(agility) << "\n";
    }
};

class VehicleBuilder {
    std::string name = "Default";
    RadarType radar = RadarType::RADAR1;
    StrengthType strength = StrengthType::LOW;
    AgilityType agility = AgilityType::SLOW;
public:
    VehicleBuilder& setName(const std::string& n) { name = n; return *this; }
    VehicleBuilder& setRadar(RadarType r) { radar = r; return *this; }
    VehicleBuilder& setStrength(StrengthType s) { strength = s; return *this; }
    VehicleBuilder& setAgility(AgilityType a) { agility = a; return *this; }

    Vehicle build() { return Vehicle(name, radar, strength, agility); }
};

int main() {
    Vehicle scout1 = VehicleBuilder()
        .setName("Scout1")
        .setRadar(RadarType::RADAR2)
        .setStrength(StrengthType::LOW)
        .setAgility(AgilityType::FAST)
        .build();

    Vehicle tank1 = VehicleBuilder()
        .setName("Tank1")
        .setRadar(RadarType::RADAR3)
        .setStrength(StrengthType::HIGH)
        .setAgility(AgilityType::SLOW)
        .build();

    scout1.print();
    std::cout << "\n";
    tank1.print();
    return 0;
}

