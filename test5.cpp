#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <optional>
#include <variant>
int main()
{
    std::pair<int, float> p = std::make_pair(1, 4.0);
    std::cout << "First: " << p.first << " Second: " << p.second << std::endl;
    char s = 's';
    std::string str = "kibidi";
    std::pair<char, std::string> t(std::move(s), std::move(str));
    std::cout << "First: " << t.first << " Second: " << t.second << std::endl;
    std::cout << str << std::endl;
    std::tuple<std::string, int, int> tup;
    std::get<0>(tup) = "Barcelona - Inter";
    std::get<1>(tup) = 6;
    std::get<2>(tup) = 7;
    std::cout << "Game " << std::get<0>(tup) << " " << std::get<1>(tup) << " : " << std::get<2>(tup) << std::endl;
    auto wrrum = std::make_tuple("Arsenal - PSG", 2, 1);
    std::cout << "Game " << std::get<0>(wrrum) << " " << std::get<1>(wrrum) << " : " << std::get<2>(wrrum) << std::endl;
    std::optional<int> i;
    i = 5;
    if (i.has_value())
    {
        std::cout << "value of i is: " << i.value() << std::endl;
    }
    else
    {
        std::cout << "No value" << std::endl;
    }

    i = std::nullopt;
    std::cout << *i << std::endl;
    // std::cout << i << std::endl; // tak nie mozna zas
    if (i.has_value())
    {
        std::cout << "value of i is: " << i.value() << std::endl;
    }
    else
    {
        std::cout << "No value" << std::endl;
    }
    std::variant<int, float, bool, std::string> v;
    v = 3;
    std::cout << std::get<int>(v) << std::endl;
    v = 2.0f;
    v = true;
    v = "kocham poznan";
    std::cout << std::get<std::string>(v) << std::endl;
    std::cout << std::holds_alternative<int>(v) << std::endl;
    // std::cout << std::get<int>(v) << std::endl; // juz nie mozna zawolac tego coska
    std::cout << v.index() << std::endl;
}