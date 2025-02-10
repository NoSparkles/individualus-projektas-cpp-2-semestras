#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class House {
private:
    unsigned rooms;
    string address;
    double area;
public:
    House(unsigned rooms = 1, const string& address = "", double area = 0) {
        this->setRooms(rooms);
        this->setAddress(address);
        this->setArea(area);
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
};

int main() {

    
    return 0;
}