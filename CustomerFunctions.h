#pragma once
#include "Customer.h"

// Prototypes of functions
void DataEntry(CustomerData* (&arrCustomer), int& tsize);
void DataCustomerReading(CustomerData* (&arrCustomer), int& tsize, string fileName);
void showBookedTickets(CustomerData* arrCustomer, int tsize);
void showReturnedTickets(CustomerData* arrCustomer, int tsize);
void Copy(CustomerData* arrCustomer_n, CustomerData* arrCustomer_o, int tsize);
void bookTicket(MovieData* (&arrMovie), CustomerData* (&arrCustomer), int& tsize, Seat& seat);
void returnTicket(CustomerData* (&arrCustomer), int& tsize, Seat& seat);
void deleteCustomer(CustomerData* (&arrCustomer), int& tsize, Seat& seat);
void DataCustomerSave(CustomerData* arrCustomer, int tsize, string fileName);
