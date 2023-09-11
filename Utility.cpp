#include "Utility.hpp"
#include "Tour.hpp"

int Utility::randomNumber(int lower, int upper)
{
    double randomDouble;

    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double>distribution(lower,upper);
    randomDouble = distribution(generator);

    return (int)randomDouble;
}

void Utility::sort(vector<Tour *> &populations) {
    // We are going to do a bubble sort
    for (int i = 0; i < static_cast<int>(populations.size()); i++) {
        for (int j = 0;j < static_cast<int>(populations.size() - 1); j++) {
            if (*populations[j] > *populations[j + 1]) {
                Tour * temp = populations[j + 1];
                populations[j + 1] = populations[j];
                populations[j] = temp;
            }
        }
    }
}

