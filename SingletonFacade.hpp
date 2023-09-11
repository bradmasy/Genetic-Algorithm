#ifndef LAB1TEMPLATE_SINGLETONFACADE_HPP
#define LAB1TEMPLATE_SINGLETONFACADE_HPP


#include <utility>
#include <vector>
#include <stack>
#include "City.hpp"
#include "Tour.hpp"
#include "Utility.hpp"
#include <iostream>
#include <algorithm>
#include "Population.hpp"

constexpr static int BEST_TOUR = 0; // the best tour, simply put.
constexpr static int ITERATIONS = 1000; // the max amount of iterations our natural selection process will run.
constexpr static int PARENT_POOL_SIZE = 5; // the pool size of the parent, we set small so the likelihood of crossover parents is small to none.
constexpr static int MAX_MUTATION_VALUE = 100; // the max percentage our mutation probability can achieve.
constexpr static int MUTATION_RATE = 10; // the percentage in which our factor needs to exceed.
constexpr static double IMPROVEMENT = 1.50; // 50% better the improvement must be.
constexpr static int POPULATION_SIZE = 32; // this is the amount of tours we will generate.
constexpr static int ELITE = 0; // the best of the best tour.
constexpr static int RUNNER_UP = 1; // the next fittest child, not quite our golden boy, but they will do.
constexpr static int STRONGEST_PARENT = 0; // the fittest parent.
constexpr static int FIRST_PARENT = 0; // the first parent in a set of parents.
constexpr static int GOLDEN_BOY = 0; // the best and brightest child we have created, our golden boy :).

using namespace std;

class SingletonFacade {

private:
    int iterationCount{0};
    bool achieved{false};
    Tour *eliteTour{nullptr};
    Tour *originalElite{nullptr};
    Population *pop = new Population{}; // constructs a fresh population for our algorithm.
    vector<Tour *> population;
    vector<City *> cities;
    vector<Tour *> bestTours;
    double beatFitness{0};

    /**
     * Default Constructor for singleton, privatized to ensure no instances are created outside of the class.
     */
    SingletonFacade() = default;


/**
     * Generates a parent tour by shuffling the indices of a copied population and creating a set of possible parents
     * for our reproduction algorithm. The amount of parents chosen is based on the global PARENT_POOL_SIZE attribute.
     * Once PARENT_POOL_SIZE amount of parents have been selected the vector of tour pointers is sorted by fitness so
     * that the fittest parent will be at our first index.
     *
     * @param parents a reference to an empty vector to be filled with the selected parent tour pointers.
     */
    void generateParents(vector<Tour *> &parents);

/**
     * Compares new golden child tour against the current elite and if the fitness level of a child is less than that
     * of the elite (meaning that it is a better tour in our rankings) that child is now assigned as the new elite
     * tour in the population.
     */
    void checkForElite(Tour *child);

    /**
    * Updates the populations fitness scores and sorts the population.
    */
    void updatePopulationFitnessScores();

    /**
 * Reproduction is our child creation function. Two of our fittest parents cities are crossed over to a new child
 * tour based on a randomely chosen index. From the index we copy the first parents tours over to the child and then
 * add in order from the second parent the remaining tours that are not present in the child. The childs fitness is
 * then assessed and the new child tour pointer is returned.
 *
 * @param pTour a reference to a parent tour.
 * @param pTour1 a reference to a second parent tour.
 * @return a new child tour pointer.
 */
    static Tour *reproduction(Tour &pTour, Tour &pTour1);


    /**
     * Displays the Genetic algorithms statistics after completing its task.
     */
    void displayStatistics();

    /**
   * Generates an amount of tours from the given vector of city pointers and populates the private population
   * vector with them.
   *
   * @param cities a vector of city pointers.
   * @param amountOfTours an integer greater than 0, representing the amount of tours we would like to create.
   */
    void generateTours(vector<City *> &cities, int amountOfTours);

    /**
     * Sorts the population based on its fitness level, initiates a perror if the population is null.
     */
    void analyzePopulation();

    /**
  * A randomly chosen index is chosen and within the tours cities the city at that index is swapped with
  * the city adjacent to it in the vector.
  *
  * @param tour a reference to a tour in which we are performing the mutation on(swap).
  */
    static void mutateTour(Tour &tour);

    /**
     * While avoiding the first index of our population(reserved for the elite tour), we set the new children
     * as the new population to move forward in our genetic algorithm.
     *
     * @param children a reference to a vector of tour pointers that are our children from the reproduction loop.
     */
    void setNewPopulation(vector<Tour *> &children);

    /**
     * Runs a while loop based on an algorithmIterationCount and a weight factor associated with the elite tour.
     * The algorithm runs a nested for loop that generates our children and provides the comparison and sorting
     * functions necessary to determine a new elite tour in our population. If a child tour emerges whose
     * generate weight is less than that of the IMPROVEMENT factor, then our algorithm is complete and the loop
     * breaks returning our new Elite tour. If no tour is fitter than our current Elite, then that elite is
     * returned after the max iteration count has been hit.
     */
    void naturalSelection();

    /**
     * Overloaded ostream operator.
     *
     * @param os a reference to an ostream.
     * @param object a reference to our singleton facade.
     * @return an ostream reference.
     */
    friend ostream &operator<<(ostream &os, const SingletonFacade &object);

    /**
   * For each one of our child tours a random probability is generated, if this probability is greater than
   * the MUTATION_RATE the child enters the mutation phase, once a child has been mutated their fitness level is
   * updated.
   *
   * @param children a reference to a vector of tours that represent our children created previously.
   */
    static void mutation(vector<Tour *> &children);

public:

    ~SingletonFacade() = default;

    /**
     * Runs the genetic algorithm by executing various function calls to naturally select the best tour in the population
     * after a series of iterations and comparisons.
     */
    void run();

    /**
     * Deleted Copy constructor so that the singleton may never be reproduced.
     */
    SingletonFacade(const SingletonFacade &s) = delete;

    /**
     * Deleted = operator so that the singleton may never be reassigned.
     */
    void operator=(SingletonFacade const &) = delete;

    /**
     * Static method to return the instance of our static singleton object.
     *
     * @return a reference to the singleton instance.
     */
    static SingletonFacade &getInstance();
};

#endif //LAB1TEMPLATE_SINGLETONFACADE_HPP
