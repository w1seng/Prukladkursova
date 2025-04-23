#include "MovieFunctions.h"
#include <iostream>
//description of functions
void DataEntry(MovieData* (&arrMovie), int& tsize) {
    Movie movies;
    cout << "Enter size of array: ";
    cin >> tsize;
    arrMovie = new MovieData[tsize];
    for (int i = 0; i < tsize; i++) {
        char e; cin.get(e);
        cout << "Enter movie name: ";
        getline(cin, movies.movieName, '\n');
        cout << "Enter movie genre: ";
        getline(cin, movies.movieGenre, '\n');
        cout << "Enter age restriction : ";
        cin >> movies.movieAge;
        cin.ignore(1, '\n');
        cout << "Enter show date: ";
        getline(cin, movies.dateMovie, '\n');
        cout << "Enter actors: ";
        getline(cin, movies.movieActors, '\n');
        cout << "Enter ticket price: ";
        cin >> movies.ticketPrice;
        cin.ignore(1, '\n');
        //add new data to elemnt of array
        arrMovie[i].DataEntry(movies);
        cout << "_______________________\nPress ENTER 1 TIME\n";
    }
}

void DataMovieReading(MovieData* (&arrMovie), int& tsize, string fileName) {
    ifstream fin(fileName);
    if (fin) {
        Movie movies;
        fin >> tsize;
        arrMovie = new MovieData[tsize]; // create memory for array of data
        //reading data
        for (int i = 0; i < tsize; i++) {
            getline(fin, movies.movieName);
            getline(fin, movies.movieName);
            getline(fin, movies.movieGenre);
            fin >> movies.movieAge;
            fin.ignore(1, '\n');
            getline(fin, movies.dateMovie);
            getline(fin, movies.movieActors);
            fin >> movies.ticketPrice;
            fin.ignore(1, '\n');
            //add new data in element of array
            arrMovie[i].DataEntry(movies);
        }
    } else {
        cout << "Problem with file opening!" << endl;
    }
    fin.close();
}

void showMovies(MovieData* arrMovie, int tsize) {
    for (int i = 0; i < tsize; i++) {
        cout << "Movie #" << i + 1 << endl;
        arrMovie[i].printData();
        cout << "_______________________________________\n";
    }
}

void Copy(MovieData* arrMovie_n, MovieData* arrMovie_o, int tsize) {
    for (int i = 0; i < tsize; i++) {
        arrMovie_n[i] = arrMovie_o[i];
    }
}

void addMovie(MovieData* (&arrMovie), int& tsize) {
    Movie movies;
    MovieData* temp = new MovieData[tsize];
    int size = tsize, new_size = ++tsize;
    Copy(temp, arrMovie, size);
    arrMovie = new MovieData[new_size];
    Copy(arrMovie, temp, size);
    char e; cin.get(e);
    cout << "Enter movie name: ";
    getline(cin, movies.movieName, '\n');
    cout << "Enter movie genre: ";
    getline(cin, movies.movieGenre, '\n');
    cout << "Enter age restriction: ";
    cin >> movies.movieAge;
    cin.ignore(1, '\n');
    cout << "Enter show date (format dd.mm.yyyy): ";
    getline(cin, movies.dateMovie, '\n');
    cout << "Enter actors: ";
    getline(cin, movies.movieActors, '\n');
    cout << "Enter ticket price: ";
    cin >> movies.ticketPrice;
    cin.ignore(1, '\n');
    //add new data to elemnt of array
    arrMovie[size].DataEntry(movies);
    cout << "Movie is added!" << endl;
    delete[] temp;
}

void deleteMovie(MovieData* (&arrMovie), int& tsize) {
    int _tsize;
    MovieData* temp = new MovieData[tsize];
    cout << "Enter the ID of movie (from 1 to " << tsize << "): ";
    cin >> _tsize;
    _tsize--;
    if (_tsize >= 0 && _tsize < tsize) {
        Copy(temp, arrMovie, tsize);
        int q = 0;
        tsize--;
        //create new memory
        arrMovie = new MovieData[tsize];
        for (int i = 0; i <= tsize; i++) {
            if (i != _tsize) {
                arrMovie[q] = temp[i];
                q++;
            }
        }
        cout << "Movie is deleted!" << endl;
    } else {
        cout << "ID is wrong!" << endl;
    }
    delete[] temp;
}

void findMovieByGenre(MovieData* arrMovie, int tsize) {
    string genre;
    cout << "Enter genre: ";
    cin >> genre;
    system("cls");
    cout << "Movies with " << genre << endl;
    for (int i = 0; i < tsize; i++) {
        if (arrMovie[i].GetMovieData().movieGenre == genre) {
            cout << "Movie #" << i + 1 << endl;
            arrMovie[i].printData();
            cout << "_______________________\n";
        }
    }
}

void findMovieByDate(MovieData* arrMovie, int tsize) {
    string date;
    cout << "Enter date (format dd.mm.yyyy): ";
    cin >> date;
    system("cls");
    cout << "Movies shows on " << date << endl;
    for (int i = 0; i < tsize; i++) {
        if (arrMovie[i].GetMovieData().dateMovie == date) {
            cout << "Movie #" << i + 1 << endl;
            arrMovie[i].printData();
            cout << "_______________________\n";
        }
    }
}

void findActorsByMovie(MovieData* arrMovie, int tsize) {
    string mname; char e;
    cin.get(e);
    cout << "Enter movie name: ";
    getline(cin, mname, '\n');
    system("cls");
    cout << "Actors cast of " << mname << endl;
    for (int i = 0; i < tsize; i++) {
        if (arrMovie[i].GetMovieData().movieName == mname) {
            cout << endl;
            arrMovie[i].printActors();
            cout << "_________________________________________\n";
        }
    }
}

void DataSave(MovieData* arrMovie, int tsize, string fileName) {
    ofstream fout(fileName);
    if (fout) {
        fout << tsize << endl;
        for (int i = 0; i < tsize; i++) {
            fout << arrMovie[i].GetMovieData().movieName << endl
                 << arrMovie[i].GetMovieData().movieGenre << endl
                 << arrMovie[i].GetMovieData().movieAge << endl
                 << arrMovie[i].GetMovieData().dateMovie << endl
                 << arrMovie[i].GetMovieData().movieActors << endl
                 << arrMovie[i].GetMovieData().ticketPrice << endl;
            if (i < tsize - 1) {
                fout << endl;
            }
        }
    } else {
        cout << "Problem with file opening!";
    }
    cout << "Data about movies is saved: " << endl;
    fout.close();
}