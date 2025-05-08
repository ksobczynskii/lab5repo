#include <iostream>
#include <vector>
#include <string>
// to jest testowa klasa do code snippetow z wykladu
class vector3d
{
    float _x, _y, _z;

public:
    explicit vector3d(int x = 0, int y = 0, int z = 0) : _x(x), _y(y), _z(z) {};

    vector3d &operator+=(const vector3d &other)
    {
        _x += other._x;
        _y += other._y;
        _z += other._z;
        return *this;
    }
    float x() const
    {
        return _x;
    }
    float y() const
    {
        return _y;
    }
    float z() const
    {
        return _z;
    }
    vector3d operator+() { return *this; };
    vector3d operator-()
    {
        return vector3d(_x * -1, _y * -1, _z * -1);
    }
    vector3d &operator++()
    {
        _x++;
        _y++;
        _z++;
        return *this;
    };
    vector3d operator++(int)
    {
        vector3d tmp = *this;
        _x++;
        _y++;
        _z++;
        return tmp;
    };
    vector3d &operator--()
    {
        _x--;
        _y--;
        _z--;
        return *this;
    };
    vector3d operator--(int)
    {
        vector3d tmp = *this;
        _x--;
        _y--;
        _z--;
        return tmp;
    };

    vector3d operator+(const vector3d &other) const
    {
        vector3d result = *this;
        result += other;
        return result;
    }
    vector3d operator*(const vector3d &other) const
    {
        vector3d res = *this;
        res._x = res._x * other._x;
        res._y = res._y * other._y;
        res._z = res._z * other._z;
        return res;
    }
    vector3d &operator*=(const vector3d &other)
    {
        _x = _x * other._x;
        _y = _y * other._y;
        _z = _z * other._z;
        return *this;
    }
    operator std::string() // w operatorach konwersji nie dajemy typu zwracanego, bo operator ma zawsze ten sam typ co to na co konwertuje
    {
        return "vector3d(" + std::to_string(_x) + ", " + std::to_string(_y) + ", " + std::to_string(_z) + ")";
    }
    void print()
    {
        std::cout << "Vector: x=" << _x << " y=" << _y << " z=" << _z << std::endl;
    }
};
std::ostream &operator<<(std::ostream &os, const vector3d &v)
{
    os << "vector3d(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
    return os;
}
void foo(float a, float b, float c)
{
    std::cout << "foo(" << a << ", " << b << ", " << c << ")" << std::endl;
}
void goo(vector3d v)
{
    std::cout << "goo(" << v.x() << ", " << v.y() << ", " << v.z() << ")" << std::endl;
}
int main()
{
    vector3d vec(1, 3, 4);
    vec.print();
    vec += vector3d(1, 10, 4);
    vec.print();
    vector3d vec2(0, 2, 4);
    vec = vec + vec2;
    vec.print();
    vec = vec * vec;
    vec.print();
    vec *= vector3d(4, 2, 1);
    vec.print();
    std::cout << vec << std::endl;
    std::cout << -vector3d(1, 2, 3) << std::endl;
    vec++;
    vec.print();
    vec--;
    vec.print();
    foo(2.0, 3.0, 4.0);
    // goo(2.0); // niejawna konwersja z float do vector3d po dodaniu slowa kluczowego explicit juz nie zadziala
    goo(vector3d(2.0));                                          // dziala
    goo(static_cast<vector3d>(23));                              // dziala
    std::string s = static_cast<std::string>(vector3d(6, 9, 6)); // dziala
    std::cout << s << std::endl;
    std::string str = "skibidi";
    std::vector<std::string> vect;
    vect.push_back(std::move(str));
    if (str.empty())
    {
        std::cout << "String was moved and is now empty" << std::endl;
    }
    else
    {
        std::cout << "String is: " << str << std::endl;
    }
}