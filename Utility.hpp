#ifndef LAB1TEMPLATE_UTILITY_HPP
#define LAB1TEMPLATE_UTILITY_HPP
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class Tour; // forward declaration
class Utility {
public:

    /**
     * Generates a random number between the lower and the upper bound passed and returns it.
     *
     * @param lower an integer greater or equal to 0.
     * @param upper an integer greater than the lower passed.
     * @return a random integer between the lower and upper values passed.
     */
    static int randomNumber(int lower, int upper);

    /**
     * Performs a bubble sort on a given vector of tour pointers based on the fitness level of the tour.
     * the sort order is the fittest tour is at the first index and the longest tour is at the final index.
     *
     * @param populations a vector of tour pointers.
     */
    static void sort(vector<Tour*>& populations);
};


#endif //LAB1TEMPLATE_UTILITY_HPP
