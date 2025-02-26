// Robert Šatkevič

#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

class Building {
public:
static unsigned count;
static unsigned nextId;
unsigned id;
unsigned numberOfFloors;
double area;
string address;

Building(unsigned numberOfFloors, double area) {
this->init(numberOfFloors, area, "Unknown");
}

Building(unsigned numberOfFloors, double area, const string& address) {
this->init(numberOfFloors, area, address);
}

~Building() {
Building::decreaseCount();
}

static unsigned getCount() {
return Building::count;
}

unsigned getId() const {
return this->id;
}

unsigned getNumberOfFloors() const {
return this->numberOfFloors;
}

double getArea() const {
return this->area;
}

string getAddress() const {
return this->address;
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

void init(unsigned numberOfFloors, double area,  const string& address) {
this->setId();
this->setNumberOfFloors(numberOfFloors);
this->setAddress(address);
this->setArea(area);
Building::increaseCount();
Building::setNextId();
}

static void increaseCount() {
++Building::count;
}

static void decreaseCount() {
--Building::count;
}

static void setNextId() {
++Building::nextId;
}

void setId() {
this->id = nextId;
}
};
unsigned Building::count = 0;
unsigned Building::nextId = 1;

int main() {
Building* buildings = new Building[5]{
Building(3, 120.5, "123 Main St"),
Building(4, 150.0, "456 Elm St"),
Building(2, 90.0, "789 Oak St"),
Building(5, 200.0, "101 Maple St"),
Building(3, 110.0)
};

assert(Building::getCount() == 5);

assert(buildings[0].getNumberOfFloors() == 3);
assert(buildings[0].getAddress() == "123 Main St");
assert(buildings[0].getArea() == 120.5);
assert(buildings[4].getNumberOfFloors() == 3);
assert(buildings[4].getAddress() == "Unknown");
assert(buildings[4].getArea() == 110.0);

buildings[0].setNumberOfFloors(4);
buildings[0].setAddress("123 Elm St");
buildings[0].setArea(150.0);
assert(buildings[0].getNumberOfFloors() == 4);
assert(buildings[0].getAddress() == "123 Elm St");
assert(buildings[0].getArea() == 150.0);

Building *newBuilding = new Building(4, 150.0, "123 Elm St");

assert(Building::getCount() == 6);

delete newBuilding;

Building *newBuilding2 = new Building(4, 150.0, "123 Elm St");

assert(Building::getCount() == 6);
assert(newBuilding2->getId() == 7);

delete newBuilding2;

assert(Building::getCount() == 5);

delete[] buildings;

assert(Building::getCount() == 0);

return 0;
}