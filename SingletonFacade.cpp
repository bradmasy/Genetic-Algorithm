#include "SingletonFacade.hpp"
#include <algorithm>

void SingletonFacade::analyzePopulation() {

    // If population is empty return error;
    if (population.empty()) {
        perror("Population is empty");
    }
    updatePopulationFitnessScores();
    Utility::sort(this->population);
}

ostream &operator<<(ostream &os, const SingletonFacade &sg) {
    for (Tour *tour: sg.population) {
        os << *tour << endl << endl;
    }
    return os;
}

void SingletonFacade::updatePopulationFitnessScores() {
    for (auto &i: population) {
        i->updateScore();
    }
}

SingletonFacade &SingletonFacade::getInstance() {
    static SingletonFacade instance;
    return instance;
}

void SingletonFacade::generateParents(vector<Tour *> &parents) {

    vector<Tour *> populationCopy = population;
    for (int i = 0; i < PARENT_POOL_SIZE; i++) {
        std::shuffle(populationCopy.begin(), populationCopy.end(), std::mt19937(std::random_device()()));
        while (std::find(parents.begin(), parents.end(), populationCopy[FIRST_PARENT]) != parents.end()) {
            std::shuffle(populationCopy.begin(), populationCopy.end(), std::mt19937(std::random_device()()));
        }
        parents.push_back(populationCopy[FIRST_PARENT]);
    }
    Utility::sort(parents); // sort after grabbing the parents set for this iteration
}


void SingletonFacade::naturalSelection() {
    int currentIterationCount = 0;
    double weight = 0;

    Tour *elite = population[BEST_TOUR];
    eliteTour = elite;
    originalElite = elite;
    beatFitness = eliteTour->getFitness() / IMPROVEMENT;

    cout << "Performing \"Natural Selection\"..." << endl;
    while ((currentIterationCount < ITERATIONS) && weight < IMPROVEMENT) {
        cout << "Iteration: " << currentIterationCount << endl;

        vector<Tour *> children;
        for (int i = 0; i < static_cast<int>(population.size() - 1); i++) {
            vector<Tour *> parentsOne, parentsTwo;

            generateParents(parentsOne); // generate one batch of parents.
            generateParents(parentsTwo); // generate another batch of parents

            Tour *child = reproduction(*parentsOne[STRONGEST_PARENT], *parentsTwo[STRONGEST_PARENT]);

            children.push_back(child);
        }

        mutation(children);
        Utility::sort(children);
        checkForElite(children[GOLDEN_BOY]);   // check for elite after mutation.
        children.insert(children.begin(), elite); // add the elite to the top of the list.

        weight = *children[ELITE] / *children[RUNNER_UP];

        setNewPopulation(children);
        currentIterationCount++; // function iteration count to break loop.
    }

    iterationCount = currentIterationCount; // set the display iteration count to that iteration count when the loop ended.
}

Tour *SingletonFacade::reproduction(Tour &pTour, Tour &pTour1) {
    Tour *child = new Tour{};
    int size = pTour.size();
    int randomIndex = Utility::randomNumber(0, size - 1);

    vector<City> addedCities; // a vector of cities used for checking, we use City instead of City because of the

    int index = 0;
    for (int i = 0; i < size; i++) {
        City *city;

        if (i >= randomIndex) {
            city = new City{*pTour1.getCity(index)};

            while (std::find(addedCities.begin(), addedCities.end(), *city) != addedCities.end()) {
                delete city; // delete city if found in addedCities, to avoid memory leak.
                index++;
                city = new City{*pTour1.getCity(index)};
            }
            index++;
        } else {
             city = new City{*pTour.getCity(i)};
        }

        /* all dynamic memory created in this function is added to the tour and deleted in the destructor of the tour
            at the end of run time. */

        /*
         * The new pointers are passed to the child tour to give the child a fresh set of pointers for manipulating.
         */

        child->append(*city);
        addedCities.push_back(*city);
    }

    child->updateScore(); // update the score once finished.
    return child;
}

void SingletonFacade::generateTours(vector<City *> &citiesVec, int amountOfTours) {

    for (int i = 0; i < amountOfTours; i++) {
        Tour *tour = new Tour{citiesVec};
        population.push_back(tour);
    }
}

void SingletonFacade::setNewPopulation(vector<Tour *> &children) {
    for (int i = 0; i < static_cast<int>(children.size()); i++) {
        population[i + 1] = children[i];
    }
}

void SingletonFacade::mutateTour(Tour &tour) {
    int index = Utility::randomNumber(0, (tour.size() - 1));

    City temp = *tour.getCity(index);
    *tour.getCities()[index] = *tour.getCities()[index + 1];
    *tour.getCities()[index + 1] = temp;
}

void SingletonFacade::mutation(vector<Tour *> &children) {

    // i is 1 to skip the elite tour in the population.
    for (int i = 1; i < static_cast<int>(children.size()); i++) {

        int mutationProbability = Utility::randomNumber(0, MAX_MUTATION_VALUE);

        if (mutationProbability > MUTATION_RATE) {
            mutateTour(*children[i]);
            children[i]->updateScore();
        }
    }
}

void SingletonFacade::displayStatistics() {
    cout << "\n" <<endl;
    cout << "----------Statistics----------" << endl;
    cout << "\n   -----Original Elite-----   " << endl;
    cout << *originalElite << endl;
    cout << "\nNumber of Iterations: " << iterationCount << endl;
    cout << "Improvement Factor: " << IMPROVEMENT << endl;
    cout << "Tour must be less than [" << (beatFitness) << "] in order to successfully improve." << endl;
    cout << "Achieved Improvement Factor: " << ((achieved) ? "Yes" : "No") << endl;
    cout << ((achieved) ? "Base and Best Distance: " : "Best Non Elite Distance: ") << eliteTour->getFitness() << endl;
    cout << "\n    -----Elite Tour-----    \n" << *eliteTour << endl;
}

void SingletonFacade::checkForElite(Tour *child) {

    if (*child < *eliteTour) {
        eliteTour = child;
        cout << "\ta new elite tour has been discovered with a fitness of: " << (child->getFitness()) << endl;

        if (eliteTour->getFitness() < beatFitness) {
            achieved = true; // mark the status as successful.
        }
    }
}

void SingletonFacade::run() {

    generateTours(pop->getTourPopulation(), POPULATION_SIZE);
    analyzePopulation();
    naturalSelection();
    displayStatistics();
}
