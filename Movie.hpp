#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <variant>
#include <list>
#include <algorithm>
template <typename RatingType>
class Movie
{
public:
    struct Director
    {
        std::string name;
        unsigned int numberOfOscars;
        Director(std::string name = "", int oscars = 0) : name(name), numberOfOscars(oscars) {};
    };

private:
    std::string title;
    int year;
    std::variant<Director, std::string> director;
    std::optional<std::string> description;
    std::list<RatingType> ratings;

public:
    Movie(const std::string title = "", int year = 0, const std::variant<Director, std::string> &director = "", std::optional<std::string> desc = std::nullopt) : title(title), year(year), director(director), description(desc) {};
    const std::string getTitle() const
    {
        return title;
    }
    int getYear() const
    {
        return year;
    }
    const std::optional<std::string> getDescription() const
    {
        return description;
    }
    const std::variant<Director, std::string> getDirector() const
    {
        return director;
    }
    const std::list<RatingType> getRatings() const
    {
        return ratings;
    }
    float getAverageRating() const
    {
        int i = 0;
        RatingType sum = 0;
        for (auto &rating : ratings)
        {
            i++;
            sum += rating;
        }
        return i > 0 ? sum / i : 0;
    }
    float getTopRating() const
    {
        return *std::max_element(ratings.begin(), ratings.end());
    }
    bool operator<(const Movie &other)
    {
        if (title < other.getTitle())
        {
            return true;
        }
        else if (title == other.getTitle())
        {
            return year > other.getYear();
        }
        else
        {
            return false;
        }
    }
    bool operator==(const Movie &other)
    {
        return year == other.year && title == other.title;
    }
    Movie &operator+(RatingType &&other)
    {
        ratings.push_back(other);
        return *this;
    }
};
template <typename RatingType>
std::ostream &operator<<(std::ostream &os, const Movie<RatingType> &m)
{
    std::string oscars;
    auto dir = m.getDirector();
    os << m.getTitle() << " (" << m.getYear();
    if (std::holds_alternative<typename Movie<RatingType>::Director>(dir))
    {
        auto director = std::get<typename Movie<RatingType>::Director>(dir);
        oscars = "), Director: " + director.name + " (Oscars: ";
        os << oscars << director.numberOfOscars << ")";
    }
    else
    {
        oscars = "), Director: " + std::get<std::string>(dir);
        os << oscars;
    }
    std::string desc = "";

    if (m.getDescription().has_value())
    {
        desc = " Description: " + m.getDescription().value();
    }
    os << ", Avg: " << m.getAverageRating() << ", Top: " << m.getTopRating() << desc;
    return os;
}