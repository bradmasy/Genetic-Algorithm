#include "Population.hpp"

vector<City*> Population::initializePopulation() {
    vector<City*> master;
    City* Vancouver = new City{49.2827, 123.1207, "Vancouver"};
    City* Toronto = new City{43.6532, 79.3832, "Toronto"};
    City* Calgary = new City{51.0447, 114.0719, "Calgary"};
    City* Halifax = new City{44.6476, 63.5728, "Halifax"};
    City* Saskatoon = new City{52.1579, 106.6702, "Saskatoon"};
    City* Yellowknife = new City{62.4540, 114.3718, "Yellowknife"};
    City* Montreal = new City{45.5019, 73.5674, "Montreal"};
    City* Iqaluit = new City{63.7467, 68.5170, "Iqaluit"};
    City* Winnipeg = new City{49.8954, 97.1385, "Winnipeg"};
    City* Whitehorse = new City{60.7197, 135.0523, "Whitehorse"};
    City* LosAngelos = new City{34.0522, 118.2437, "Los Angelos"};
    City* Nashville = new City{36.1627, 86.7816, "Nashville"};
    City* NewYork = new City{40.7128, 74.0060, "New York"};
    City* Atlanta = new City{33.7488,84.3877,"Atlanta"};
    City* Boston = new City{42.3601,71.0589,"Boston"};
    City* Madison = new City{43.0722,89.4008,"Madison"};
    City* Helena = new City{46.5891,112.0391, "Helena"};
    City* Louisiana = new City{30.9843,91.9623,"Louisiana"};
    City* Charlotte = new City{35.2271,80.8431,"Charlotte"};
    City* Kingston = new City{44.2312,76.4860,"Kingston"};
    City* Fredericton = new City{45.9636,66.6431,"Fredericton"};
    City* JacksonHole = new City{43.4799,110.7624,"Jackson Hole"};
    City* Austin = new City{30.2672,97.7431,"Austin"};
    City* Dallas = new City{32.7767,96.7970,"Dallas"};
    City* Philadelphia = new City{39.9526,75.1652,"Philadelphia"};
    City* Pittsburgh = new City{40.4406,79.9959,"Pittsburgh"};
    City* Chicago = new City{41.8781,87.6298,"Chicago"};
    City* Baltimore = new City{39.2904,76.6122,"Baltimore"};
    City* Seattle = new City{47.6062,122.3321,"Seattle"};
    City* NewOrleans = new City{29.9511,90.0715,"New Orleans"};
    City* SanFrancisco = new City{37.7749,122.4194,"San Francisco"};
    City* Charleston = new City{32.7765,79.9311,"Charleston"};

    master.insert(master.end(), {Vancouver, Toronto, Calgary, Halifax,
                                 Saskatoon, Yellowknife, Montreal, Iqaluit, Winnipeg, Whitehorse,
                                 LosAngelos, Nashville, NewYork,Atlanta,Boston,Madison,Helena,Louisiana,Charleston,Charlotte,
                                 Kingston,Fredericton,JacksonHole,Austin,Dallas,Philadelphia,Pittsburgh,Chicago,Baltimore,Seattle,
                                 NewOrleans,SanFrancisco});
    return master;
}

Population::Population() {
        masterCities = initializePopulation(); // initialize the population
}

vector<City *>& Population::getTourPopulation() {
    return this->masterCities;
}

Population::~Population() {
    for(City* city: masterCities){
        delete city; // destroying the cities.
    }
}
