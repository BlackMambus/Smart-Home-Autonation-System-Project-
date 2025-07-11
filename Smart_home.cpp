#include <iostream>
#include <string>
using namespace std;

// Base class for all smart devices
class SmartDevice {
protected:
    string name;
    bool isOn;

public:
    SmartDevice(string deviceName) : name(deviceName), isOn(false) {}

    virtual void turnOn() {
        isOn = true;
        cout << name << " is now ON.\n";
    }

    virtual void turnOff() {
        isOn = false;
        cout << name << " is now OFF.\n";
    }

    virtual void status() const {
        cout << name << " is " << (isOn ? "ON" : "OFF") << ".\n";
    }
};

// Light class
class Light : public SmartDevice {
public:
    Light(string name) : SmartDevice(name) {}
};

// Fan class
class Fan : public SmartDevice {
public:
    Fan(string name) : SmartDevice(name) {}
};

// Thermostat class
class Thermostat : public SmartDevice {
private:
    int temperature;

public:
    Thermostat(string name, int temp = 22) : SmartDevice(name), temperature(temp) {}

    void setTemperature(int temp) {
        temperature = temp;
        cout << name << " temperature set to " << temperature << "°C.\n";
    }

    void status() const override {
        SmartDevice::status();
        if (isOn) {
            cout << name << " temperature is " << temperature << "°C.\n";
        }
    }
};

// Main control system
int main() {
    Light livingRoomLight("Living Room Light");
    Fan ceilingFan("Ceiling Fan");
    Thermostat homeThermostat("Home Thermostat");

    int choice;
    do {
        cout << "\n--- Smart Home Menu ---\n";
        cout << "1. Turn ON Light\n";
        cout << "2. Turn OFF Light\n";
        cout << "3. Turn ON Fan\n";
        cout << "4. Turn OFF Fan\n";
        cout << "5. Turn ON Thermostat\n";
        cout << "6. Turn OFF Thermostat\n";
        cout << "7. Set Thermostat Temperature\n";
        cout << "8. Show Device Status\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: livingRoomLight.turnOn(); break;
            case 2: livingRoomLight.turnOff(); break;
            case 3: ceilingFan.turnOn(); break;
            case 4: ceilingFan.turnOff(); break;
            case 5: homeThermostat.turnOn(); break;
            case 6: homeThermostat.turnOff(); break;
            case 7: {
                int temp;
                cout << "Enter temperature: ";
                cin >> temp;
                homeThermostat.setTemperature(temp);
                break;
            }
            case 8:
                livingRoomLight.status();
                ceilingFan.status();
                homeThermostat.status();
                break;
            case 0: cout << "Exiting Smart Home System.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

