#include "City.hpp"

City &City::operator=(City city) {
    swapCity(*this,city);
    return *this;
}

void City::swapCity(City &cityOne, City &cityTwo) {
    std::swap( cityOne.name,cityTwo.name);
    std::swap( cityOne.x,cityTwo.x);
    std::swap(   cityOne.y ,cityTwo.y );

}

bool operator==(const City &city, const City &cityTwo) {
    bool sameCity = false;
    if(city.name == cityTwo.name && city.x == cityTwo.x && city.y == cityTwo.y ){
        sameCity = true;
    }
    return sameCity;
}
