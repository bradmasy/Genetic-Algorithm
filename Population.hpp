#ifndef LAB1TEMPLATE_POPULATION_HPP
#define LAB1TEMPLATE_POPULATION_HPP

#include "City.hpp"
#include <algorithm>
#include <utility>
#include <random>

constexpr static int CITIES_IN_TOUR = 32;
class Population {

private:
     vector<City *> masterCities;

public:
    /**
     * Creates an initial population to run our algorithm on.
     *
     * @return a vector of city pointers.
     */
    static vector<City*> initializePopulation();

    /**
     * Population constructor.
     */
    Population();

    /**
     * Population Destructor.
     */
    ~Population();

    /**
     * Gets the master population vector.
     *
     * @return a vector of city pointers.
     */
    vector<City*>& getTourPopulation();
};

#endif //LAB1TEMPLATE_POPULATION_HPP
