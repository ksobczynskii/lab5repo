#include <iostream>
#include <string>

class Country
{
    struct Capital // struktura/klasa zagniezdzona :)
    {
        std::string name;
        unsigned int population;
        Capital(std::string name = " ", unsigned int pop = 0) : name(name), population(pop) {};
    };

public:
    Capital c;
    unsigned int population;
    std::string name;

    Country(std::string name, std::string capital_name = " ", unsigned int population = 0, unsigned int cap_pop = 0) : population(population), name(name), c(capital_name, cap_pop) {};
    void print()
    {
        std::cout << "Country is " << name << " with a population of " << population << " people and capital in  " << c.name << " with a population of " << c.population << std::endl;
    }

    bool operator()(int x)
    {
        return population > x;
    }
};

int main()
{
    Country Poland("Poland", "Warschau", 38000000, 2000000);
    Poland.print();
    std::cout << "Czy polska ma wiecej niz 40.000.000? : " << Poland(40000000) << std::endl;
}