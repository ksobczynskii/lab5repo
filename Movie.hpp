#pragma once
#include <iostream>
#include <string>
#include <optional>
#include <variant>
#include <list>
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
    Movie(const std::string title, int year, const std::variant<Director, std::string> &director, std::optional<std::string> desc = std::nullopt) : title(title), year(year), director(director), description(desc) {};
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
};