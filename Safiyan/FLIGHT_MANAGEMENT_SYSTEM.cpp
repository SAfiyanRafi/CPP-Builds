#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Forward declarations
class Flight;
class Passenger;

// Class to represent a booking
class Booking {
private:
    string bookingID;
    Flight* flight;
    Passenger* passenger;
    string seatNumber;
    string bookingStatus;

public:
    Booking(const string& bookingID, Flight* flight, Passenger* passenger, const string& seatNumber)
        : bookingID(bookingID), flight(flight), passenger(passenger), seatNumber(seatNumber), bookingStatus("Confirmed") {}

    const string& getBookingID() const {
        return bookingID;
    }

    Flight* getFlight() const {
        return flight;
    }

    Passenger* getPassenger() const {
        return passenger;
    }

    const string& getSeatNumber() const {
        return seatNumber;
    }

    const string& getBookingStatus() const {
        return bookingStatus;
    }

    void setBookingStatus(const string& status) {
        bookingStatus = status;
    }
};

// Class to represent a passenger
class Passenger {
private:
    string passengerID;
    string name;
    string email;
    string phone;

public:
    Passenger(const string& passengerID, const string& name, const string& email, const string& phone)
        : passengerID(passengerID), name(name), email(email), phone(phone) {}

    const string& getPassengerID() const {
        return passengerID;
    }

    const string& getName() const {
        return name;
    }

    const string& getEmail() const {
        return email;
    }

    const string& getPhone() const {
        return phone;
    }
};

// Class to represent a flight
class Flight {
private:
    string flightID;
    string flightNumber;
    string origin;
    string destination;
    time_t departureTime;
    time_t arrivalTime;
    int totalSeats;
    int availableSeats;

public:
    Flight(const string& flightID, const string& flightNumber, const string& origin, const string& destination, time_t departureTime, time_t arrivalTime, int totalSeats)
        : flightID(flightID), flightNumber(flightNumber), origin(origin), destination(destination), departureTime(departureTime), arrivalTime(arrivalTime), totalSeats(totalSeats), availableSeats(totalSeats) {}

    const string& getFlightID() const {
        return flightID;
    }

    const string& getFlightNumber() const {
        return flightNumber;
    }

    const string& getOrigin() const {
        return origin;
    }

    const string& getDestination() const {
        return destination;
    }

    time_t getDepartureTime() const {
        return departureTime;
    }

    time_t getArrivalTime() const {
        return arrivalTime;
    }

    int getTotalSeats() const {
        return totalSeats;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    bool bookSeat() {
        if (availableSeats > 0) {
            --availableSeats;
            return true;
        } else {
            return false;
        }
    }
};

// Class to represent the flight booking system
class FlightBookingSystem {
private:
    vector<Flight> flights;
    vector<Passenger> passengers;
    vector<Booking> bookings;
    int nextBookingID;

public:
    FlightBookingSystem() : nextBookingID(1) {}

    void addFlight(const Flight& flight) {
        flights.push_back(flight);
    }

    void addPassenger(const Passenger& passenger) {
        passengers.push_back(passenger);
    }

    bool bookFlight(const string& flightID, const string& passengerID, const string& seatNumber) {
        Flight* flight = findFlight(flightID);
        Passenger* passenger = findPassenger(passengerID);
        if (flight && passenger && flight->bookSeat()) {
            bookings.push_back(Booking(to_string(nextBookingID++), flight, passenger, seatNumber));
            return true;
        } else {
            return false;
        }
    }

    Flight* findFlight(const string& flightID) {
        for (Flight& flight : flights) {
            if (flight.getFlightID() == flightID) {
                return &flight;
            }
        }
        return nullptr;
    }

    Passenger* findPassenger(const string& passengerID) {
        for (Passenger& passenger : passengers) {
            if (passenger.getPassengerID() == passengerID) {
                return &passenger;
            }
        }
        return nullptr;
    }

    void displayBookings() const {
        cout << "Bookings:" << endl;
        for (const Booking& booking : bookings) {
            cout << "Booking ID: " << booking.getBookingID() << ", Flight: " << booking.getFlight()->getFlightNumber() << ", Passenger: " << booking.getPassenger()->getName() << ", Seat: " << booking.getSeatNumber() << ", Status: " << booking.getBookingStatus() << endl;
        }
    }
};

int main() {
    // Create a flight
    Flight flight("F1", "BA123", "LHR", "JFK", time(nullptr) + 3600, time(nullptr) + 14400, 100);

    // Create a passenger
    Passenger passenger("P1", "John Doe", "john@example.com", "1234567890");

    // Create a flight booking system
    FlightBookingSystem fbs;
    fbs.addFlight(flight);
    fbs.addPassenger(passenger);

    // Book the flight for the passenger
    if (fbs.bookFlight("F1", "P1", "A1")) {
        cout << "Flight booked successfully!" << endl;
    } else {
        cout << "Failed to book flight." << endl;
    }

    // Display bookings
    fbs.displayBookings();

    return 0;
}
