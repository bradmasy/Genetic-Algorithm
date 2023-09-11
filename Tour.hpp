#ifndef LAB1TEMPLATE_TOUR_HPP
#define LAB1TEMPLATE_TOUR_HPP

#include <vector>
#include <cmath>
#include <cmath>
#include "City.hpp"
#include "random"

class Tour {

private:
    vector<City*> cities;
    double fitness_rating{0};

    /**
     * Calculates distance between cities using the haversine
     * formula
     * a = sin²(Δφ/2) + cos φ1 ⋅ cos φ2 ⋅ sin²(Δλ/2)
     *
     * Where φ represent the latitudes, and λ represent the longitudes.
     * @param x City
     * @param y City
     * @return double distance
     */
    static double haversine(City x, City y);
public:

    /**
    * Default Constructor
    */
    Tour()= default;

    /**
     * Constructor for Tour.
     *
     * @param citiesList a vector of city pointers.
     */
    explicit Tour(vector<City*> &citiesList) {
       for(auto & i : citiesList){
           cities.push_back(new City{*i});
       }
        std::shuffle(cities.begin(), cities.end(), std::mt19937(std::random_device()())); // shuffle the cities.
        this->updateScore();
    }

    /**
     * Copy constructor for tour.
     *
     * @param tour a tour reference.
     */
    Tour(const Tour& tour);

    /**
     * Destructor to delete cities
     */
    ~Tour();

    /**
     * Returns the whole list of cities
     * @return
     */
    [[nodiscard]] vector<City*> getCities() const {return cities;}

    /**
     * Gets the fitness rating of the tour and returns it.
     *
     * @return the tours fitness rating.
     */
    [[nodiscard]] double getFitness() const{
        return this->fitness_rating;
    }
    /**
     * Gets the city at a given index and returns the reference
     * @param index an index in the cities vector.
     * @return a reference to the city at the given index.
     */
    [[nodiscard]] City* getCity(int index)  { return cities[index]; };

    /**
     * Appends a city reference to the cities vector in the tour class.
     *
     * @param city
     */
    void append(City &city) {
        this->cities.push_back(&city);
    }

    /**
     * Appends the city at the given index in the tours vector of cities.
     *
     * @param i the index to append the city at.
     * @param city a pointer to the city we are appending.
     * @return a pointer to a tour.
     */
    Tour* appendAtI(int i, City *city);

    /**
     * Gets the size of the tours cities vector and returns it.
     *
     * @return the size of the tours cities vector.
     */
    int size(){return  static_cast<int>(this->cities.size()); };

    /**
     * Overloaded insertion operator.
     *
     * @param os an ostream reference.
     * @param tour a tour reference.
     * @return an ostream reference containing the tours information.
     */
    friend ostream &operator << (ostream &os,const Tour &tour);

    /**
     * iterates through cities and updates fitness score
     */
    void updateScore();

    /**
     * Overloaded Assignment operator: Reassigns the values in the tour reference to THIS tour.
     *
     * @param m a reference to a tour.
     * @return a reference to THIS tour.
     */
    Tour & operator = (const Tour& m);

    /**
     * Overloaded less than operator: compares the fitness level of THIS tour to that of one passed and
     * returns a boolean representing if THIS tours fitness is less than that of the comparison tours.
     *
     * @param t a reference to a tour.
     * @return a boolean representing if THIS tours fitness is less than that of the comparison tours.
     */
    bool operator < (const Tour & t) const;

    /**
    * Overloaded greater than operator: compares the fitness level of THIS tour to that of one passed and
    * returns a boolean representing if THIS tours fitness is greater than that of the comparison tours.
    *
    * @param t a reference to a tour.
    * @return a boolean representing if THIS tours fitness is less than that of the comparison tours.
    */
    bool operator > (const Tour & t) const;

    /**
     * Overloaded comparison operator: compares if THIS tour is equivalent to the comparison tour passed and
     * returns a boolean based on this fact.
     *
     * @param m a reference to a tour.
     * @return a boolean representing if the tours are equivalent.
     */
    bool operator == (const Tour & m) const;

    /**
     * Overloaded not equals operator: Detects the false of our comparison operator and returns the boolean value.
     * @param m a reference to a tour.
     * @return
     */
    bool operator != (const Tour & m) const;

    /**
     * Overloaded Division operator: Divides THIS tours fitness level by that of the comparison passed and returns
     * the value.
     *
     * @param one a reference to a tour.
     * @return the fitness of THIS tour divided by that of the tour reference.
     */
    double operator/( Tour &one) const;

};
#endif //LAB1TEMPLATE_TOUR_HPP
