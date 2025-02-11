#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

class House {
private:
    unsigned rooms;
    string address;
    double area;
public:
    House(unsigned rooms, const string& address, double area) {
        this->setRooms(rooms);
        this->setAddress(address);
        this->setArea(area);
    }

    House(unsigned rooms, double area) {
        this->setRooms(rooms);
        this->setAddress("Unknown");
        this->setArea(area);
    }

    ~House() {
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

    unsigned getRooms() {
        return rooms;
    }

    string getAddress() {
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

int main() {
    
    return 0;
}