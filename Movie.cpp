#include "Movie.h"
MovieData::MovieData() {
movies_data.movieName = "";
movies_data.movieGenre = "";
movies_data.movieAge = 0;
movies_data.dateMovie = "";
movies_data.movieActors = "";
movies_data.ticketPrice = 0;
}
MovieData::MovieData(Movie movies_data_) {
movies_data.movieName = movies_data_.movieName;
movies_data.movieGenre = movies_data_.movieGenre;
movies_data.movieAge = movies_data_.movieAge;
movies_data.dateMovie = movies_data_.dateMovie;
movies_data.movieActors = movies_data_.movieActors;
movies_data.ticketPrice = movies_data_.ticketPrice;
}
MovieData::~MovieData() {
}
void MovieData::printData() {
cout << "Name: " << movies_data.movieName << endl;
cout << "Genre: " << movies_data.movieGenre << endl;
cout << "Age restriction: " << movies_data.movieAge << "+" << endl;
cout << "Show date: " << movies_data.dateMovie << endl;
cout << "Actors: " << movies_data.movieActors << endl;
cout << "Ticket price: " << movies_data.ticketPrice << " UAH" << endl;
}
void MovieData::printActors() {
cout << " " << movies_data.movieActors << endl;
}
void MovieData::DataEntry(Movie movies_data_) {
movies_data.movieName = movies_data_.movieName;
movies_data.movieGenre = movies_data_.movieGenre;
movies_data.movieAge = movies_data_.movieAge;
movies_data.dateMovie = movies_data_.dateMovie;
movies_data.movieActors = movies_data_.movieActors;
movies_data.ticketPrice = movies_data_.ticketPrice;
}
MovieData& MovieData::operator=(MovieData arrMovie_o) {
this->movies_data.movieName = arrMovie_o.movies_data.movieName;
this->movies_data.movieGenre = arrMovie_o.movies_data.movieGenre;
this->movies_data.movieAge = arrMovie_o.movies_data.movieAge;
this->movies_data.dateMovie = arrMovie_o.movies_data.dateMovie;
this->movies_data.movieActors = arrMovie_o.movies_data.movieActors;
this->movies_data.ticketPrice = arrMovie_o.movies_data.ticketPrice;
return *this;
}
