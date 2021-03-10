#include <iostream>
#include <limits>

struct Flight {
    int flightNumber;
    int capacity;
    int occupiedSeats;
    int freeSeats;
    char destination[26];
    char destinationType;
};

void inputFlight(Flight &flight) {
    std::cout << "Flight number: ";
    std::cin >> flight.flightNumber;
    std::cout << "Capacity: ";
    std::cin >> flight.capacity;
    std::cout << "Occupied seats: ";
    std::cin >> flight.occupiedSeats;
    flight.freeSeats = flight.capacity - flight.occupiedSeats;
    std::cout << "Destination: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(flight.destination, 26);
    std::cout << "Destination type: ";
    std::cin >> flight.destinationType;
    return;
}

void printFlight(Flight &flight) {
    std::cout.width(5); std::cout << std::left << flight.flightNumber;
    std::cout.width(5); std::cout << std::left << flight.capacity;
    std::cout.width(5); std::cout << std::left << flight.occupiedSeats;
    std::cout.width(5); std::cout << std::left << flight.freeSeats;
    std::cout.width(15); std::cout << std::left << flight.destination;
    std::cout.width(5); std::cout << std::left << flight.destinationType << std::endl;
    return;
}

void printDataHeader() {
    std::cout.width(5); std::cout << std::left << "F#";
    std::cout.width(5); std::cout << std::left << "Cap";
    std::cout.width(5); std::cout << std::left << "OS";
    std::cout.width(5); std::cout << std::left << "FS";
    std::cout.width(15); std::cout << std::left << "Dest";
    std::cout.width(5); std::cout << std::left << "DestT" << std::endl;
    return;
}

int main() {
    int n;
    std::cout << "n= ";
    std::cin >> n;
    Flight flights[n];
    for (int i = 0; i < n; i++) {
        std::cout << '(' << i + 1 << '/' << n << ')' << std::endl;
        inputFlight(flights[i]);
    }
    printDataHeader();
    for (int i = 0; i < n; i++) {
        printFlight(flights[i]);
    }
    int maxFreeSeats;
    std::cout << "Maximal free seats: ";
    std::cin >> maxFreeSeats;
    printDataHeader();
    for (int i = 0; i < n; i++) {
        if (flights[i].freeSeats < maxFreeSeats)
            printFlight(flights[i]);
    }
    char destinationType;
    std::cout << "Zone type: ";
    std::cin >> destinationType;
    printDataHeader();
    for (int i = 0; i < n; i++) {
        if (flights[i].destinationType == destinationType)
            printFlight(flights[i]);
    }
    return 0;
}