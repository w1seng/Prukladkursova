#pragma once
#include "Movie.h"
//prototypes of functions
void DataEntry(MovieData* (&arrMovie), int& tsize);
void DataMovieReading(MovieData* (&arrMovie), int& tsize, string fileName);
void showMovies(MovieData* arrMovie, int tsize);
void Copy(MovieData* arrMovie_n, MovieData* arrMovie_o, int tsize);
void addMovie(MovieData* (&arrMovie), int& tsize);
void deleteMovie(MovieData* (&arrMovie), int& tsize);
void findMovieByGenre(MovieData* arrMovie, int tsize);
void findMovieByDate(MovieData* arrMovie, int tsize);
void findActorsByMovie(MovieData* arrMovie, int tsize);
void DataSave(MovieData* arrMovie, int tsize, string fileName);