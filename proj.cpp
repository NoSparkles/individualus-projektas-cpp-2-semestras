#include <iostream>
#include <iomanip>
#include <assert.h>
#include <vector>

using namespace std;

class House {
private:
    static unsigned count;
    static unsigned nextId;
    unsigned id;
    unsigned rooms;
    string address;
    double area;

    static void setCount(unsigned count) {
        House::count = count;
    }

    static void setNextId(unsigned nextId) {
        House::nextId = nextId;
    }

    void setId(unsigned id) {
        this->id = id;
    }
public:
    House(unsigned rooms, const string& address, double area) {
        this->setId(nextId);
        House::setCount(House::count + 1);
        House::setNextId(House::nextId + 1);
        this->setRooms(rooms);
        this->setAddress(address);
        this->setArea(area);
    }

    House(unsigned rooms, double area) {
        this->setId(nextId);
        House::setCount(House::count + 1);
        House::setNextId(House::nextId + 1);
        this->setRooms(rooms);
        this->setAddress("Unknown");
        this->setArea(area);
    }

    ~House() {
        House::setCount(House::count - 1);
    }

    static unsigned getCount() {
        return House::count;
    }

    unsigned getId() const {
        return this->id;
    }

    void setRooms(unsigned rooms) {
        if (rooms < 1) {
            return;
        }
        this->rooms = rooms;
    }

    void setAddress(const string& address) {
        if (address.length() == 0 || address.length() > 50) {
            return;
        }
        this->address = address;
    }

    void setArea(double area) {
        if (area <= 0) {
            return;
        }
        this->area = area;
    }

    unsigned getRooms() const {
        return rooms;
    }

    string getAddress() const {
        return address;
    }

    double getArea() const {
        return area;
    }

    string to_string() const {
        stringstream ss;
        ss << "Rooms: " << rooms << ", Address: " << address << ", Area: " << fixed << setprecision(2) << area;
        return ss.str();
    }
};
unsigned House::count = 0;
unsigned House::nextId = 1;

int main() {
    // Create an array of House objects
    House* houses = new House[5]{
        House(3, "123 Main St", 120.5),
        House(4, "456 Elm St", 150.0),
        House(2, "789 Oak St", 90.0),
        House(5, "101 Maple St", 200.0),
        House(3, 110.0)
    };

    // Test the count of houses
    assert(House::getCount() == 5);

    // Test the methods of House class
    assert(houses[0].getRooms() == 3);
    assert(houses[0].getAddress() == "123 Main St");
    assert(houses[0].getArea() == 120.5);
    assert(houses[4].getRooms() == 3);
    assert(houses[4].getAddress() == "Unknown");
    assert(houses[4].getArea() == 110.0);

    // Test the to_string method
    assert(houses[0].to_string() == "Rooms: 3, Address: 123 Main St, Area: 120.50");

    // Test setters
    houses[0].setRooms(4);
    houses[0].setAddress("123 Elm St");
    houses[0].setArea(150.0);
    assert(houses[0].getRooms() == 4);
    assert(houses[0].getAddress() == "123 Elm St");
    assert(houses[0].getArea() == 150.0);

    // Create a new House object
    House *newHouse = new House(4, "123 Elm St", 150.0);

    // Test the count of houses
    assert(House::getCount() == 6);

    // Delete the new house object
    delete newHouse;

    //create a new house object
    House *newHouse2 = new House(4, "123 Elm St", 150.0);

    // Test the count of houses
    assert(House::getCount() == 6);
    assert(newHouse2->getId() == 7);
    
    delete newHouse2;

    // Test the count of houses after deleting the new house object
    assert(House::getCount() == 5);
    
    // Clean up dynamically allocated memory
    delete[] houses;

    // Test the count of houses after deleting the array of houses
    assert(House::getCount() == 0);
    
    return 0;
}