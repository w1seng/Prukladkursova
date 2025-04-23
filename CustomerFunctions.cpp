#include "CustomerFunctions.h"
//description of functions
void DataEntry(CustomerData* (&arrCustomer), int& tsize) {
    Customer customers;
    Ticket tickets;
    cout << "Enter size of customers array:";
    cin >> tsize;
    arrCustomer = new CustomerData[tsize];
    for (int i = 0; i < tsize; i++) {
        char e;
        cin.get(e);
        cout << "Enter customer name: ";
        getline(cin, customers.customerName, '\n');
        cout << "Enter customer surname: ";
        getline(cin, customers.customerSurname, '\n');
        cout << "Enter customer phone: ";
        cin >> customers.customerPhone;
        cin.ignore(1, '\n');
        cout << "Enter seat row (1-9): ";
        cin >> customers.seatRow;
        cin.ignore(1, '\n');
        cout << "Enter seat place (1-8): ";
        cin >> customers.seatPlace;
        cin.ignore(1, '\n');
        cout << "Enter todays date: ";
        getline(cin, tickets.dateOfBook, '\n');
        //add new data to elemnt of array
        arrCustomer[i].DataEntry(customers, tickets);
        cout << "___________________________\n";
    }
}

void DataCustomerReading(CustomerData* (&arrCustomer), int& tsize, string fileName) {
    ifstream fin(fileName);
    if (fin) {
        Customer customers;
        Ticket tickets;
        fin >> tsize;
        arrCustomer = new CustomerData[tsize]; // create memory for array of data
        //reading data
        for (int i = 0; i < tsize; i++) {
            fin >> customers.customerName;
            fin >> customers.customerSurname;
            fin >> customers.customerPhone;
            fin >> customers.seatRow;
            fin >> customers.seatPlace;
            fin >> tickets.dateOfBook;
            fin >> tickets.ticketReturn;
            fin >> tickets.dateOfReturn;
            //add new data in element of array
            arrCustomer[i].DataEntry(customers, tickets);
        }
    } else {
        cout << "Problem with file Customer opening!" << endl;
    }
    fin.close();
}

void showBookedTickets(CustomerData* arrCustomer, int tsize) {
    for (int i = 0; i < tsize; i++) {
        cout << "Customer #" << i + 1 << endl;
        arrCustomer[i].printCustomerData();
        cout << "_______________________\n";
    }
}

void showReturnedTickets(CustomerData* arrCustomer, int tsize) {
    for (int i = 0; i < tsize; i++) {
        if (arrCustomer[i].GetTicketsData().ticketReturn == 1) {
            cout << "Customer #" << i + 1 << endl;
            arrCustomer[i].printCustomerData();
            cout << "_______________________\n";
        }
    }
}

void Copy(CustomerData* arrCustomer_n, CustomerData* arrCustomer_o, int tsize) {
    for (int i = 0; i < tsize; i++) {
        arrCustomer_n[i] = arrCustomer_o[i];
    }
}

void bookTicket(MovieData* (&arrMovie), CustomerData* (&arrCustomer), int& tsize, Seat& seat) {
    Movie movies;
    Customer customers;
    Ticket tickets;
    int movieID = 0, row = 0, place = 0;
    string session;
    cout << "Ticket Booking:" << endl;
    cout << "Enter movie ID: ";
    cin >> movieID;
    cout << "Enter seat ROW (1-9): ";
    cin >> row;
    cout << "Enter seat PLACE (1-8): ";
    cin >> place;
    if (!seat.seatStat[row - 1][place - 1]) {
        CustomerData* temp = new CustomerData[tsize];
        int size = tsize, new_size = ++tsize;
        int choice;
        Copy(temp, arrCustomer, size);
        arrCustomer = new CustomerData[new_size];
        Copy(arrCustomer, temp, size);
    SESSION:
        cout << "Choose session:\n1) Morning - 10:30;\n2) Afternoon - 15:00;\n3)Evening - 18:30;\n4) Night - 21:00." << endl;
        cout << ">> ";
        cin >> choice;
        if (choice == 1) {
            session = "10:30";
        } else if (choice == 2) {
            session = "15:00";
        } else if (choice == 3) {
            session = "18:30";
        } else if (choice == 4) {
            session = "21:00";
        } else {
            cout << "Choice is wrong!" << endl;
            goto SESSION;
        }
        cout << "Enter your name: ";
        cin >> customers.customerName;
        cout << "Enter your surname: ";
        cin >> customers.customerSurname;

        cout << "Enter your phone number: ";
        cin >> customers.customerPhone;
        customers.seatRow = row;
        customers.seatPlace = place;
        cout << "Enter todays date(format dd.mm.yyyy): ";
        cin >> tickets.dateOfBook;
        tickets.ticketReturn = false;
        tickets.dateOfReturn = "-";
        seat.seatStat[row - 1][place - 1] = true;
        //add new data to elemnt of array
        arrCustomer[size].DataEntry(customers, tickets);
        Sleep(1000);
        system("cls");
        cout << "\t\t______________________________________________________" << endl
             << "\t\t|                                                    |" << endl
             << "\t\t| Dear Customer " << customers.customerName << " " << customers.customerSurname << ", " << endl
             << "\t\t| Your tickets have been booked                     |" << endl
             << "\t\t|                                                    |" << endl
             << "\t\t| The details:                                       |" << endl
             << "\t\t| Movie name: " << arrMovie[--movieID].GetMovieData().movieName << " " << endl
             << "\t\t| Book date: " << tickets.dateOfBook << "           |" << endl
             << "\t\t| Show date: " << arrMovie[--movieID].GetMovieData().dateMovie << " |" << endl
             << "\t\t| Show starts: " << session << "                    |" << endl
             << "\t\t| Seat row: " << customers.seatRow << "             |" << endl
             << "\t\t| Seat place: " << customers.seatPlace << "         |" << endl
             << "\t\t|                                                    |" << endl
             << "\t\t| Total price: ";
        if (customers.seatRow < 4) {
            cout << arrMovie[movieID].GetMovieData().ticketPrice;
        }
        if (customers.seatRow > 3 && customers.seatRow < 7) {
            cout << arrMovie[movieID].GetMovieData().ticketPrice * 2;
        }
        if (customers.seatRow > 6) {
            cout << arrMovie[movieID].GetMovieData().ticketPrice * 3;
        }
        cout << " UAH |" << endl
             << "\t\t|____________________________________________________|\n"
             << endl;
        delete[] temp;
    } else {
        cout << "Seat is already booked!!!" << endl;
    }
}

void returnTicket(CustomerData* (&arrCustomer), int& tsize, Seat& seat) {
    Customer customers;
    Ticket tickets;
    string tPhone, tDate;
    int row = 0, place = 0;
    cout << "Enter your phone number: ";
    cin >> tPhone;
    cout << "Enter todays date (format dd.mm.yyyy): ";
    cin >> tDate;
    cout << "Enter your ROW (1-9): ";
    cin >> row;
    cout << "Enter your place (1-8): ";
    cin >> place;
    for (int i = 0; i < tsize; i++) {
        if (arrCustomer[i].GetCustomerData().customerPhone == tPhone &&
            arrCustomer[i].GetCustomerData().seatRow == row &&
            arrCustomer[i].GetCustomerData().seatPlace == place) {
            seat.seatStat[row - 1][place - 1] = false;
            tickets.ticketReturn = true;
            tickets.dateOfReturn = tDate;
            arrCustomer[i].DataReturnEntry(tickets);
        }
    }
}

void deleteCustomer(CustomerData* (&arrCustomer), int& tsize, Seat& seat) {
    int _tsize;
    CustomerData* temp = new CustomerData[tsize];
    cout << "Enter the ID of customer (from 1 to " << tsize << "): ";
    cin >> _tsize;
    _tsize--;
    int trow = arrCustomer[_tsize].GetCustomerData().seatRow,
        tplace = arrCustomer[_tsize].GetCustomerData().seatPlace;
    if (_tsize >= 0 && _tsize < tsize) {
        seat.seatStat[--trow][--tplace] = false;
        Copy(temp, arrCustomer, tsize);
        int q = 0;
        tsize--;
        //create new memory
        arrCustomer = new CustomerData[tsize];
        for (int i = 0; i <= tsize; i++) {
            if (i != _tsize) {
                arrCustomer[q] = temp[i];
                q++;
            }
        }
        cout << "Customer is deleted!" << endl;
    } else {
        cout << "ID is wrong!" << endl;
    }
    delete[] temp;
}

void DataCustomerSave(CustomerData* arrCustomer, int tsize, string fileName) {
    ofstream fout(fileName);
    if (fout) {
        fout << tsize << endl;
        for (int i = 0; i < tsize; i++) {
            fout << arrCustomer[i].GetCustomerData().customerName << endl
                 << arrCustomer[i].GetCustomerData().customerSurname << endl
                 << arrCustomer[i].GetCustomerData().customerPhone << endl
                 << arrCustomer[i].GetCustomerData().seatRow << endl
                 << arrCustomer[i].GetCustomerData().seatPlace << endl
                 << arrCustomer[i].GetTicketsData().dateOfBook << endl;
            fout << arrCustomer[i].GetTicketsData().ticketReturn << endl
                 << arrCustomer[i].GetTicketsData().dateOfReturn << endl;
            if (i < tsize - 1) {
                fout << endl;
            }
        }
    } else {
        cout << "Problem with file opening!";
    }
    cout << "Data about customers is saved: " << endl;
    fout.close();
}
