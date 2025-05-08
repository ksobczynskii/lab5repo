#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <array>
#include <list>
#include <algorithm>
#include <map>
#include <set>

class Point
{
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {};
    void print() { std::cout << "x: " << x << " y: " << y << std::endl; }
};

bool krotkie(std::string s)
{
    return s.size() <= 5;
}

std::string make_prisoner(int id)
{
    return "Prisoner " + std::to_string(id);
}
int main()
{
    std::array<std::string, 5> teams;
    teams.at(0) = "Knicks";
    teams.at(1) = "Bulls";
    teams.at(2) = "Celtics";
    teams.at(3) = "Lakers";
    teams.at(4) = "Warriors";
    std::cout << "Teams: " << std::endl;
    for (auto it = teams.begin(); it != teams.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::vector<std::string> vecTeams(teams.begin(), teams.end());
    std::cout << "Teams from vector: " << std::endl;
    for (auto it = vecTeams.begin(); it != vecTeams.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    vecTeams.insert(vecTeams.begin() + 2, "Timberwolves");
    std::cout << "Teams from vector after insert: " << std::endl;
    for (auto it = vecTeams.begin(); it != vecTeams.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    vecTeams.erase(vecTeams.begin() + 2, vecTeams.end() - 1);
    std::cout << "Teams from vector after erase: " << std::endl;
    for (auto it = vecTeams.begin(); it != vecTeams.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "\n\n " << std::endl;
    std::list<Point> pts;
    pts.emplace_back(Point(1, 2));
    pts.emplace_back(Point(3, 4));
    pts.emplace_back(Point(5, 6));
    std::cout << "Points: " << std::endl;
    for (auto it = pts.begin(); it != pts.end(); it++)
    {
        it->print();
    }
    std::cout << "\n\n " << std::endl;
    std::map<std::string, int> mapMovies;
    mapMovies.insert(std::make_pair("Ratatouille", 2007));
    mapMovies.insert(std::make_pair("Star Wars: Return of the Jedi", 1983));
    mapMovies.insert(std::make_pair("Blade Runner", 1982));
    mapMovies.insert(std::make_pair("Insomnia", 2002));
    for (auto it = mapMovies.begin(); it != mapMovies.end(); it++)
    {
        std::cout << "Movie: " << it->first << " Year: " << it->second << std::endl;
    }
    std::cout << "\n\n " << std::endl;
    for (const auto &[key, value] : mapMovies)
    {
        std::cout << "Movie: " << key << " Year: " << value << std::endl;
    }

    auto it = mapMovies.find("Insomnia"); // zwraca 'pointer-iterator' na Key Insomnia
    if (it != mapMovies.end())
    {
        std::cout << "Found movie: " << it->first << " Year: " << it->second << std::endl;
    }
    else
    {
        std::cout << "Movie not found" << std::endl;
    }
    mapMovies["Gladiator"] = 2000;
    std::cout << "Movie: " << mapMovies["Gladiator"] << std::endl; // zwraca value pod key gladiator -2000
    std::set<std::string> setMovies;
    setMovies.insert("Ratatouille");
    setMovies.insert("Star Wars: Return of the Jedi");
    setMovies.insert("Blade Runner");
    setMovies.insert("Insomnia");
    setMovies.insert("Gladiator");
    setMovies.insert("Gladiator"); // nie doda drugi raz gladiatora
    std::cout << "Movies: " << std::endl;
    for (auto it = setMovies.begin(); it != setMovies.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "\n\n " << std::endl;

    std::vector<std::string> names;
    names.emplace_back("Belzebub");
    names.emplace_back("Koziolek");
    names.emplace_back("Eustachy");
    names.emplace_back("Lebron");
    std::cout << "Najwieksze leksykalnie imie to: " << *std::max_element(names.begin(), names.end()) << std::endl;
    auto s = std::find(names.begin(), names.end(), "Lebron");
    if (s != names.end())
    {
        std::cout << "Found Lebron" << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    auto s2 = std::find_if(names.begin(), names.end(), krotkie);
    if (s2 != names.end())
    {
        std::cout << "Found short name: " << *s2 << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    names.emplace_back("Kaz");
    auto s3 = std::find_if(names.begin(), names.end(), krotkie);
    if (s3 != names.end())
    {
        std::cout << "Found short name: " << *s3 << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    std::cout << "\n\n " << std::endl;
    std::vector<std::string> moreNames(names.size());
    std::copy(names.begin(), names.end(), moreNames.begin());
    std::cout << "More names: " << std::endl;
    for (auto it = moreNames.begin(); it != moreNames.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "\n\n " << std::endl;
    std::vector<int> ids = {67, 89, 43, 12, 45, 23, 56, 78, 90};
    std::vector<std::string> prisoners(ids.size());
    std::transform(ids.begin(), ids.end(), prisoners.begin(), make_prisoner);
    std::cout << "Prisoners: " << std::endl;
    for (auto it = prisoners.begin(); it != prisoners.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}