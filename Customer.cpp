#include "Customer.h"

CustomerData::CustomerData() {
    customers_data.customerName = "";
    customers_data.customerSurname = "";
    customers_data.customerPhone = "";
    customers_data.seatRow = 0;
    customers_data.seatPlace = 0;
    tickets_data.dateOfBook = "";
    tickets_data.dateOfReturn = "-";
    tickets_data.ticketReturn = false;
}

CustomerData::CustomerData(Customer customers_data_, Ticket tickets_data_) {
    customers_data.customerName = customers_data_.customerName;
    customers_data.customerSurname = customers_data_.customerSurname;
    customers_data.customerPhone = customers_data_.customerPhone;
    customers_data.seatRow = customers_data_.seatRow;
    customers_data.seatPlace = customers_data_.seatPlace;
    tickets_data.dateOfBook = tickets_data_.dateOfBook;
    tickets_data.dateOfReturn = tickets_data_.dateOfReturn;
    tickets_data.ticketReturn = tickets_data_.ticketReturn;
}

CustomerData::~CustomerData() {
}

void CustomerData::printCustomerData() {
    cout << "Name/Surname: " << customers_data.customerName << " "
         << customers_data.customerSurname << endl;
    cout << "Phone number: " << customers_data.customerPhone << endl;
    cout << "Book date: " << tickets_data.dateOfBook << endl;
    cout << "Ticket return: ";
    if (tickets_data.ticketReturn == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    cout << "Return date: " << tickets_data.dateOfReturn << endl;
}

void CustomerData::printTicket() {
    cout << "Name/Surname: " << customers_data.customerName << " "
         << customers_data.customerSurname << endl;
    cout << "Phone number: " << customers_data.customerPhone << endl;
    cout << "Book date: " << tickets_data.dateOfBook << endl;
}

void CustomerData::DataEntry(Customer customers_data_, Ticket tickets_data_) {
    customers_data.movieID = customers_data_.movieID;
    customers_data.customerName = customers_data_.customerName;
    customers_data.customerSurname = customers_data_.customerSurname;
    customers_data.customerPhone = customers_data_.customerPhone;
    customers_data.seatRow = customers_data_.seatRow;
    customers_data.seatPlace = customers_data_.seatPlace;
    tickets_data.dateOfBook = tickets_data_.dateOfBook;
    tickets_data.dateOfReturn = tickets_data_.dateOfReturn;
    tickets_data.ticketReturn = tickets_data_.ticketReturn;
}

void CustomerData::DataReturnEntry(Ticket tickets_data_) {
    tickets_data.ticketReturn = tickets_data_.ticketReturn;
    tickets_data.dateOfReturn = tickets_data_.dateOfReturn;
}

CustomerData& CustomerData::operator=(CustomerData arrCustomer_o) {
    this->customers_data.customerName =
        arrCustomer_o.customers_data.customerName;
    this->customers_data.customerSurname =
        arrCustomer_o.customers_data.customerSurname;
    this->customers_data.customerPhone =
        arrCustomer_o.customers_data.customerPhone;
    this->customers_data.seatRow = arrCustomer_o.customers_data.seatRow;
    this->customers_data.seatPlace = arrCustomer_o.customers_data.seatPlace;
    this->tickets_data.dateOfBook = arrCustomer_o.tickets_data.dateOfBook;
    this->tickets_data.dateOfReturn = arrCustomer_o.tickets_data.dateOfReturn;
    this->tickets_data.ticketReturn = arrCustomer_o.tickets_data.ticketReturn;
    return *this;
}