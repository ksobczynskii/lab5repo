#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <variant>
#include <list>
#include <map>
#include <algorithm>
#include <numeric>
#include "Movie.hpp"

class MovieCollection
{
private:
    std::map<char, std::vector<Movie<double>>> moviesByLetter;

public:
    MovieCollection() = default;
    std::map<char, std::vector<Movie<double>>> &getMoviesByLetter();
    std::vector<Movie<double>> getAllMovies() const;
    void addMovie(const Movie<double> &movie);
    void sortMovies();
    void removeMoviesOlderThan(char letter, int year);
    float getAverageTopRating();
    std::vector<Movie<double>> getMoviesByDirector(const std::string &director);
    std::optional<Movie<double>> findMovieWithAverageAbove(double threshold);
};
std::ostream &operator<<(std::ostream &os, const MovieCollection &mc);
