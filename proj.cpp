#include <iostream>
#include <iomanip>
#include <assert.h>
#include <vector>

using namespace std;

class Building {
private:
    static unsigned count;
    static unsigned nextId;
    unsigned id;
    unsigned numberOfFloors;
    string address;
    double area;

    static void setCount(unsigned count) {
        Building::count = count;
    }

    static void setNextId(unsigned nextId) {
        Building::nextId = nextId;
    }

    void setId(unsigned id) {
        this->id = id;
    }
public:
    Building(unsigned numberOfFloors, const string& address, double area) {
        this->setId(Building::nextId);
        Building::setCount(Building::count + 1);
        Building::setNextId(Building::nextId + 1);
        this->setNumberOfFloors(numberOfFloors);
        this->setAddress(address);
        this->setArea(area);
    }

    Building(unsigned numberOfFloors, double area) {
        this->setId(Building::nextId);
        Building::setCount(Building::count + 1);
        Building::setNextId(Building::nextId + 1);
        this->setNumberOfFloors(numberOfFloors);
        this->setAddress("Unknown");
        this->setArea(area);
    }

    ~Building() {
        Building::setCount(Building::count - 1);
    }

    static unsigned getCount() {
        return Building::count;
    }

    unsigned getId() const {
        return this->id;
    }

    void setNumberOfFloors(unsigned numberOfFloors) {
        if (numberOfFloors < 1) {
            throw invalid_argument("Number of floors must be greater than 0");
        }
        this->numberOfFloors = numberOfFloors;
    }

    void setAddress(const string& address) {
        if (address.length() == 0 || address.length() > 50) {
            throw invalid_argument("Address must be between 1 and 50 characters");
        }
        this->address = address;
    }

    void setArea(double area) {
        if (area < 0) {
            throw invalid_argument("Area must be greater than 0");
        }
        this->area = area;
    }

    unsigned getNumberOfFloors() const {
        return this->numberOfFloors;
    }

    string getAddress() const {
        return this->address;
    }

    double getArea() const {
        return this->area;
    }

    string to_string() const {
        stringstream ss;
        ss << "Number of Floors: " << this->numberOfFloors << ", Address: " << this->address << ", Area: " << fixed << setprecision(2) << this->area;
        return ss.str();
    }
};
unsigned Building::count = 0;
unsigned Building::nextId = 1;

int main() {
    Building* buildings = new Building[5]{
        Building(3, "123 Main St", 120.5),
        Building(4, "456 Elm St", 150.0),
        Building(2, "789 Oak St", 90.0),
        Building(5, "101 Maple St", 200.0),
        Building(3, 110.0)
    };

    assert(Building::getCount() == 5);

    assert(buildings[0].getNumberOfFloors() == 3);
    assert(buildings[0].getAddress() == "123 Main St");
    assert(buildings[0].getArea() == 120.5);
    assert(buildings[4].getNumberOfFloors() == 3);
    assert(buildings[4].getAddress() == "Unknown");
    assert(buildings[4].getArea() == 110.0);

    assert(buildings[0].to_string() == "Number of Floors: 3, Address: 123 Main St, Area: 120.50");

    buildings[0].setNumberOfFloors(4);
    buildings[0].setAddress("123 Elm St");
    buildings[0].setArea(150.0);
    assert(buildings[0].getNumberOfFloors() == 4);
    assert(buildings[0].getAddress() == "123 Elm St");
    assert(buildings[0].getArea() == 150.0);

    Building *newBuilding = new Building(4, "123 Elm St", 150.0);

    assert(Building::getCount() == 6);

    delete newBuilding;

    Building *newBuilding2 = new Building(4, "123 Elm St", 150.0);

    assert(Building::getCount() == 6);
    assert(newBuilding2->getId() == 7);
    
    delete newBuilding2;

    assert(Building::getCount() == 5);
    
    delete[] buildings;

    assert(Building::getCount() == 0);
    
    return 0;
}