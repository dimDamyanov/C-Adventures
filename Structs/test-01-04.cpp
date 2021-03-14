#include <iostream>
#include <limits>

struct Ticket {
    char name[20];
    char address[50];
    char egn[11];
    char station_dep[25];
    char station_arr[25];
    char time_dep[6];
    char time_arr[6];
    char travel_class;
    float discount;
    float travel_price;
    float ticket_price;
};

void inputTicket(Ticket &ticket) {
    std::cout << "Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(ticket.name, 20);
    std::cout << "Address: ";
    std::cin.getline(ticket.address, 50);
    std::cout << "EGN: ";
    std::cin >> ticket.egn;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Departure station: ";
    std::cin.getline(ticket.station_dep, 25);
    std::cout << "Arrival station: ";
    std::cin.getline(ticket.station_arr, 25);
    std::cout << "Time Departure: ";
    std::cin.getline(ticket.time_dep, 8);
    std::cout << "Time Arrival: ";
    std::cin.getline(ticket.time_arr, 8);
    std::cout << "Travel class: ";
    std::cin >> ticket.travel_class;
    std::cout << "Discount (BGN): ";
    std::cin >> ticket.discount;
    std::cout << "Travel price (BGN): ";
    std::cin >> ticket.travel_price;
    std::cout << "Ticket price (BGN): ";
    std::cin >> ticket.ticket_price;
    return; 
}

void printTicket(Ticket &ticket) {
    std::cout.width(15);    std::cout << std::left << ticket.name;
    std::cout.width(20);    std::cout << std::left << ticket.address;
    std::cout.width(20);    std::cout << std::left << ticket.station_dep;
    std::cout.width(20);    std::cout << std::left << ticket.station_arr;
    std::cout.width(8);    std::cout << std::left << ticket.time_dep;
    std::cout.width(8);    std::cout << std::left << ticket.time_arr;
    std::cout.width(3);    std::cout << std::left << ticket.travel_class;
    std::cout.width(4);    std::cout << std::left << ticket.discount;
    std::cout.width(4);    std::cout << std::left << ticket.ticket_price;
    std::cout.width(4);    std::cout << std::left << ticket.travel_price;

    std::cout << std::endl;
    return;
}

void printTicketDataHeader() {
    std::cout.width(15);    std::cout << std::left << "Name";
    std::cout.width(20);    std::cout << std::left << "Address";
    std::cout.width(20);    std::cout << std::left << "Departure st.";
    std::cout.width(20);    std::cout << std::left << "Arrival st.";
    std::cout.width(8);    std::cout << std::left << "Time D.";
    std::cout.width(8);    std::cout << std::left << "Time A.";
    std::cout.width(3);    std::cout << std::left << "C";
    std::cout.width(4);    std::cout << std::left << "Di";
    std::cout.width(4);    std::cout << std::left << "TiP";
    std::cout.width(4);    std::cout << std::left << "TrP";
    std::cout << std::endl;
    return;
}

int main() {
    int n;
    std::cout << "n= ";
    std::cin >> n;
    Ticket tickets[n];
    for (int i = 0; i < n; i++) {
        std::cout << '(' << i + 1 << '/' << n << ')' << std::endl;
        inputTicket(tickets[i]);
    }
    printTicketDataHeader();
    for (int i = 0; i < n; i++)
        printTicket(tickets[i]);
    
    float sClassEarn = 0;
    for (int i = 0; i < n; i++) {
        if (tickets[i].travel_class == 's')
            sClassEarn += (tickets[i].ticket_price - tickets[i].discount);
    }
    std::cout << "Sleeping class earnings: " << sClassEarn  << " BGN" << std::endl;
    int discountTicketsCount = 0;
    for (int i = 0; i < n; i++) {
        if (tickets[i].discount != 0)
            discountTicketsCount++;
    }
    std::cout << "Discount count: " << discountTicketsCount << std::endl;
    float maximalDiscount = tickets[0].discount;
    for (int i = 0; i < n; i++) {
        if (tickets[i].discount > maximalDiscount)
            maximalDiscount = tickets[i].discount;
    }
    std::cout << "Maximal discount: " << maximalDiscount << std::endl;
    return 0;
}
