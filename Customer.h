#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Movie.h"
#include "Seat.h"
using namespace std;

struct Customer {
    string customerName, customerSurname, customerPhone;
    int movieID, seatRow, seatPlace;
};

struct Ticket {
    string dateOfBook, dateOfReturn;
    bool ticketReturn;
};

class CustomerData : public MovieData, public Seat {
private:
    Customer customers_data;
    Ticket tickets_data;

public:
    CustomerData(); // constructor without argument
    CustomerData(Customer customers_data_, Ticket tickets_data_); // constructor with argument
    ~CustomerData();

    void printCustomerData(); // print customers data
    void printTicket(); // print booked ticket
    void DataEntry(Customer customers_data_, Ticket tickets_data_); // overloaded function for data entering (here customer and ticket datas)
    void DataReturnEntry(Ticket tickets_data_); // entry data about returned ticket

    // getter for customer and tickets datas
    Customer GetCustomerData() { return customers_data; }
    Ticket GetTicketsData() { return tickets_data; }

    // overloading of operator "="
    CustomerData& operator = (CustomerData arrCustomer_o);
};
