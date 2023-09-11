#ifndef LAB1TEMPLATE_CITY_HPP
#define LAB1TEMPLATE_CITY_HPP

#include <stdexcept>

#define MIN_VALUE 1
#define MAX_VALUE 1000
#define DEFAULT_NAME "NULL CITY"
#include <iostream>
#include <vector>

using namespace std;

class City {

private:
    string name;
    double x;
    double y;

    /**
     * Checks to see if the number passed in is
     * in the range of acceptable coordinates.
     *
     * @param num a double representing a coordinate.
     * @return a bool representing if the number is in range.
     */
    static bool inRange(double num) { return num >= MIN_VALUE && num < MAX_VALUE;}
public:

    /**
     * City Constructor.
     *
     * @param x coordinates a double that represents the longitude coordinates of a city.
     * @param y coordinates a double that represents the latitude coordinates of a city.
     * @param name a string representing the name of the city.
     * @throws invalid_argument if x or y is outside of the range 1 - 999
     */
    explicit City(double x = MIN_VALUE, double y = MIN_VALUE, const string name = DEFAULT_NAME): name(name), x(x), y(y) {
        if (!inRange(x) || !inRange(y)) {
            throw invalid_argument("X and Y must have valued between 0 - 1000.");
        }
    };

    /**
     * City copy constructor.
     *
     * @param city a reference to a city.
     */
    City(const City& city) {
        this->name = city.name;
        this->x = city.x;
        this->y = city.y;
    }

    ~City()= default;
    /**
     * Overloaded ostream operator.
     *
     * @param os a reference to an ostream.
     * @param city a reference to a city.
     * @return an ostream containing the cities information.
     */
    friend ostream & operator<<(ostream &os, const City &city) {
        os << city.name << " " << city.x << " " << city.y;
        return os;
    };

    /**
     * Gets the x value coordinates of the city.
     * @return the x value coordinates of the city.
     */
    [[nodiscard]] double getX() const { return this->x; };

    /**
     * Gets the y value coordinates of the city.
     *
     * @return the y value coordinates of the city
     */
    [[nodiscard]] double getY() const { return this->y; };

    /**
     * Gets the name of the city.
     *
     * @return the name of the city.
     */
    string getName(){return this->name; };

    /**
     * Sets the x coordinates for the city.
     *
     * @param x
     */
    void setX(int const xVal) {this->x = xVal;};
    /**
     *
     * @param y
     */
    void setY(int const yVal) {this->y = yVal;};

    /**
     * Overloaded assignment operator. Reassigns the passed city to the current city object.
     *
     * @param city a city object.
     * @return a reference to a city.
     */
    City &operator=(City city);

    /**
     * Swaps the values of the first city with the second cities data and the values of the second cities data with
     * the first cities.
     *
     * @param cityOne a reference to a city.
     * @param cityTwo a reference to a second city.
     */
    void swapCity(City &cityOne, City &cityTwo);

    /**
     * Overloaded comparison operator. Returns true if the cities contain the same name, x and y coordinates.
     * @param city a reference to a city.
     * @param cityTwo a reference to a second city.
     * @return a boolean value based on if the cities contain the same data.
     */
    friend bool operator==(const City &city, const City &cityTwo);
};

#endif //LAB1TEMPLATE_CITY_HPP
