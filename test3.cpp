#include <string>
#include <vector>
#include <memory>
#include <iostream>
class moviettr
{
    struct MovieNode
    {
        int hr;
        int min;
        std::string name;
        std::unique_ptr<MovieNode> next;
        MovieNode(int hr = 0, int min = 0, std::string name = "", std::unique_ptr<MovieNode> next = nullptr) : hr(hr), min(min), name(name), next(std::move(next)) {};
    };
    std::unique_ptr<MovieNode> head = nullptr;

public:
    class iterator
    {
        MovieNode *ptr;

    public:
        iterator(MovieNode *ptr) : ptr(ptr) {};

        std::string operator*() { return ptr->name; }
        iterator &operator++()
        {
            ptr = ptr->next.get();
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        bool operator==(const iterator &other) { return ptr == other.ptr; }
        bool operator!=(const iterator &other) { return !(*this == other); }
    };

    iterator begin() { return iterator(head.get()); };
    iterator fin() { return iterator(nullptr); };
    moviettr() = default;
    void init(int hr = 0, int min = 0, std::string name = "")
    {
        head = std::make_unique<MovieNode>(hr, min, name);
    }
    void prepend(int hr = 0, int min = 0, std::string name = "")
    {
        head = std::make_unique<MovieNode>(hr, min, name, std::move(head));
    }
    void print_schedule()
    {
        std::cout << "Today we play: " << std::endl;
        for (moviettr::iterator it = begin(); it != fin(); it++)
        {
            std::cout << *it << std::endl;
        }
    }
};

int main()
{
    moviettr today;
    today.init(2, 49, "Interstellar");
    today.prepend(1, 39, "Reservoir Dogs");
    today.prepend(2, 34, "Pulp Fiction");
    today.print_schedule();
    // for (moviettr::iterator it = today.begin(); it != today.fin(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    auto tommorow = moviettr();
    tommorow.init(2, 45, "Django");
    tommorow.prepend(2, 40, "Once upon a time in Hollywood");
    std::cout << "... and tommorow we play: " << std::endl;
    for (auto it = tommorow.begin(); it != tommorow.fin(); it++)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}