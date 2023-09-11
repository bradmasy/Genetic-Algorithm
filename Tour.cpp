#include "Tour.hpp"

Tour::Tour(const Tour &tour) :fitness_rating(tour.fitness_rating){
    for (int i = 0; i < (int) tour.getCities().size(); ++i) {
        this->cities.push_back(new City{*tour.getCities()[i]});
    }
}

Tour::~Tour(){
    // deleting all the cities.
    for (City* city: cities) { delete city; }
}

Tour* Tour::appendAtI(int i, City *city) {

    cities.insert(cities.begin() + i, city);
    return this;
}

ostream &operator<<(ostream &os, const Tour &tour) {
    for (unsigned int i = 0; i < tour.cities.size(); i++) {
        City* city = tour.cities[i];
        os << "City[" << i << "]: " << (*city) << endl;
    }
    os << "FITNESS RATING: " << tour.fitness_rating << endl;
    os << "---------------";
    return os;
}

void Tour::updateScore() {
    if (cities.size() < 2) {
        return;
    }

    double sum = 0;
    for (unsigned int i = 1; i < cities.size(); i++) {
        sum += haversine(*cities[i - 1], *cities[i]);
    }

    // from the last location to the first again, cycling back to the beginning.
    sum += haversine(*cities[cities.size()-1], *cities[0]);

    this->fitness_rating = sum;
}

double Tour::haversine(City x, City y) {
    double r = 6371e3; // metres
    double φ1 = x.getX() * M_PI/180; // φ, λ in radians
    double φ2 = y.getX() * M_PI/180;
    double Δφ = (x.getX()-y.getX()) * M_PI/180;
    double Δλ = (x.getY()-y.getY()) * M_PI/180;

    double a = sin(Δφ/2) * sin(Δφ/2) +
              cos(φ1) * cos(φ2) *
              sin(Δλ/2) * sin(Δλ/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double result = (r * c)/1000; // in kilometers
   return result;

}

Tour &Tour::operator=(const Tour& m) {
    this->fitness_rating = m.fitness_rating;
    this->cities = m.cities;
    return *this;
}

bool Tour::operator<(const Tour &t) const {
    return this->fitness_rating < t.fitness_rating;
}

bool Tour::operator>(const Tour &t) const {
    if(this->fitness_rating == 0){

        return true;
    }
    return this->fitness_rating > t.fitness_rating;
}

bool Tour::operator==(const Tour &m) const {
    return this->fitness_rating == m.fitness_rating;
}

bool Tour::operator!=(const Tour &m) const {
    return !(*this == m);
}

double Tour::operator/(Tour &one) const {
    return this->fitness_rating/one.fitness_rating;}
