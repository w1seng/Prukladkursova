#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Movie {
    string movieName, movieGenre, dateMovie, movieActors;
    int movieAge, ticketPrice;
};

class MovieData {
protected:
    Movie movies_data;

public:
    MovieData(); // constructor without argument
    MovieData(Movie movies_data_); // constructor with argument
    ~MovieData(); // destructor
    void printData(); // print movie data
    void printActors(); // print actors cast
    void DataEntry(Movie movies_data_); // overloaded function for data entering

    // getter movie data from class
    Movie GetMovieData() { return movies_data; } // added missing semicolon

    // overloading of operator "="
    MovieData& operator = (MovieData d_o);
};
