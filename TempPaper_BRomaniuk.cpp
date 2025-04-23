#include "MovieFunctions.h"
#include "CustomerFunctions.h"
#include "Seat.h"
#include "Additional.h"
using namespace std;

int _choiceMenu;

void Menu() {
    system("cls");
    cout << "Choose the function you need:\n\n";
    cout << " 1 - Add new movie.\n" //+
         << " 2 - Show all movies.\n" //+
         << " 3 - Delete movie.\n" //+
         << " 4 - Find movies by genre.\n" //+
         << " 5 - Get actors by movie.\n" //+
         << " 6 - Get info about movie by date.\n" //+
         << " 7 - Status of seat in the cinema.\n" //+
         << " 8 - Book ticket.\n" //+
         << " 9 - Return ticket.\n" //+
         << " 10 - Info about booked tickets.\n" //+
         << " 11 - Info about returned tickets.\n" //+
         << " 12 - Delete customer.\n" //+
         << " 13 - Rules of conduct.\n" //+
         << " 14 - List of food and drinks.\n" //+
         << " 15 - Exit.\n"
         << "Enter number and press ENTER:\n"
         << ">> ";
    cin >> _choiceMenu;
}

int main() {
    system("COLOR F0");
    ifstream welcomePage("Welcomepage.txt");
    string templine;
    while (getline(welcomePage, templine)) {
        cout << "\t\t" << templine << endl;
        Sleep(25);
    }
    welcomePage.close();
    int q;
    cout << "\n\t\t\t\t\tEnter 1 to continue, 0 to exit\n\t\t\t\t\t\t";
    cin >> q;
    if (q == 1) {
        system("cls");
        Login loginScreen;
        loginScreen.login();
        Menu();
        Seat stats;
        int _size = 0; // count of movies data
        MovieData* arrMovie = new MovieData[_size]; // array of movies data
        int _sizeC = 0; // count of customers data
        CustomerData* arrCustomer = new CustomerData[_sizeC]; // array of customer data
        DataCustomerReading(arrCustomer, _sizeC, "Customers.txt");
        DataMovieReading(arrMovie, _size, "Movies.txt");
        stats.readSeat();
        while (_choiceMenu != 15) {
            switch (_choiceMenu) {
                case 1: // Add new movie
                    system("cls");
                    if (_size != 0) {
                        addMovie(arrMovie, _size);
                        DataSave(arrMovie, _size, "Movies.txt");
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 2: // Show all movies
                    system("cls");
                    if (_size != 0) {
                        showMovies(arrMovie, _size);
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 3: // Delete movie
                    system("cls");
                    if (_size != 0) {
                        deleteMovie(arrMovie, _size);
                        DataSave(arrMovie, _size, "Movies.txt");
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 4: // Find movie by genre
                    system("cls");
                    if (_size != 0) {
                        findMovieByGenre(arrMovie, _size);
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 5: // show actors of movie
                    system("cls");
                    if (_size != 0) {
                        findActorsByMovie(arrMovie, _size);
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 6: // find movie by date
                    system("cls");
                    if (_size != 0) {
                        findMovieByDate(arrMovie, _size);
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 7: // check seat status
                    system("cls");
                    stats.seatStatus();
                    system("pause");
                    Menu();
                    break;
                case 8: // book ticket
                    system("cls");
                    if (_sizeC != 0) {
                        bookTicket(arrMovie, arrCustomer, _sizeC, stats);
                        stats.saveSeat();
                        DataCustomerSave(arrCustomer, _sizeC, "Customers.txt");
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 9: // return ticket
                    system("cls");
                    if (_sizeC != 0) {
                        returnTicket(arrCustomer, _sizeC, stats);
                        stats.saveSeat();
                        DataCustomerSave(arrCustomer, _sizeC, "Customers.txt");
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 10: // show booked tickets
                    system("cls");
                    if (_sizeC != 0) {
                        showBookedTickets(arrCustomer, _sizeC);
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 11: // show returned tickets
                    system("cls");
                    if (_sizeC != 0) {
                        showReturnedTickets(arrCustomer, _sizeC);
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 12: // delete customer
                    system("cls");
                    if (_sizeC != 0) {
                        deleteCustomer(arrCustomer, _sizeC, stats);
                        stats.saveSeat();
                        DataCustomerSave(arrCustomer, _sizeC, "Customers.txt");
                    } else {
                        cout << "File is empty!" << endl;
                    }
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                case 13: // show rules of conduct
                    system("cls");
                    showRulesOfConduct();
                    Menu();
                    break;
                case 14: // show list of food and drinks
                    system("cls");
                    showListOfFoodAndDrinks();
                    Menu();
                    break;
                case 15:
                    system("cls");
                    exit(1);
                    break;
                default:
                    cout << "Choice is wrong!" << endl;
                    system("cls");
                    Menu();
                    break;
            }
        }
        delete[] arrMovie;
        delete[] arrCustomer;
        system("cls");
        cout << "\n\tWork is done! Thanks for using!\n" << endl;
    }
    if (q == 0) {
        exit(1);
    }
}
