#include "MovieCollection.hpp"

void MovieCollection::addMovie(const Movie<double> &movie)
{
    char c = movie.getTitle().at(0);
    moviesByLetter[c].push_back(movie);
}
std::vector<Movie<double>> MovieCollection::getAllMovies() const
{
    std::vector<Movie<double>> vec;
    for (auto &[key, value] : moviesByLetter)
    {
        // std::cout << "\nDebug\n " << std::endl;
        for (auto &m : value)
        {
            vec.push_back(m);
        }
    }
    return vec;
}
std::map<char, std::vector<Movie<double>>> &MovieCollection::getMoviesByLetter()
{
    return moviesByLetter;
}
void MovieCollection::sortMovies()
{
    for (auto &[key, val] : moviesByLetter)
    {
        std::sort(val.begin(), val.end());
    }
}
void MovieCollection::removeMoviesOlderThan(char letter, int year)
{

    moviesByLetter[letter].erase(std::remove_if(moviesByLetter[letter].begin(), moviesByLetter[letter].end(), [year](Movie<double> m)
                                                { return m.getYear() < year; }),
                                 moviesByLetter[letter].end());
};
float MovieCollection::getAverageTopRating()
{

    std::vector<Movie<double>> vec = getAllMovies();
    if (vec.empty())
    {
        return 0;
    }
    float sum = std::accumulate(vec.begin(), vec.end(), 0.0, [](float a, const Movie<double> &mv)
                                { return a + mv.getTopRating(); });
    return sum / vec.size();
}

std::vector<Movie<double>> MovieCollection::getMoviesByDirector(const std::string &director)
{
    std::vector<Movie<double>> allMovies = getAllMovies();
    std::vector<Movie<double>> result;
    std::copy_if(allMovies.begin(), allMovies.end(), std::back_inserter(result),
                 [&](const Movie<double> &m)
                 {
                     if (std::holds_alternative<std::string>(m.getDirector()))
                     {
                         return director == std::get<std::string>(m.getDirector());
                     }
                     else
                     {
                         return director == std::get<Movie<double>::Director>(m.getDirector()).name;
                     }
                 });
    return result;
}
std::optional<Movie<double>> MovieCollection::findMovieWithAverageAbove(double threshold)
{
    std::optional<Movie<double>> movie;
    std::vector<Movie<double>> vec = getAllMovies();
    movie = *std::find_if(vec.begin(), vec.end(), [threshold](const Movie<double> &mv)
                          { return mv.getAverageRating() > threshold; });
    if (movie.has_value())
    {
        return movie;
    }
    return std::nullopt;
}
std::ostream &operator<<(std::ostream &os, const MovieCollection &mc)
{

    std::vector<Movie<double>> movies = mc.getAllMovies();
    if (movies.empty())
    {
        return os;
    }
    char c = movies.at(0).getTitle().at(0);
    os << "=== " << c << " ===" << std::endl;
    for (auto m : movies)
    {
        if (m.getTitle().at(0) != c)
        {
            c = m.getTitle().at(0);
            os << "=== " << c << " ===" << std::endl;
        }
        os << m << std::endl;
    }
    return os;
}
