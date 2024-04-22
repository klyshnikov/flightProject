#ifndef CPP_VARIABELS_H
#define CPP_VARIABELS_H

#include "map"
#include "string"

namespace calculation {
    using noise_1hour_in_sector = std::vector<double>;
    using noise_24hour_in_sector = std::vector<double>*;

    const std::pair<double, double> sheremetyegoCords = {55.973233, 37.409741};

    const double max_distance_to_count = 0;

    const int shape_of_nearest_sectors = 6;

    const int max_noise = 100;
    const int bar_chart_size = 10;

    const std::map<std::string, double> planes_power = {};

    const std::vector<std::string> groupPlanesBigNoise = {"B77W", "A333", "B772", "B789", "B788", "IL76"};
    const std::vector<std::string> groupPlanesSmallNoise = {"CRJ2", "SU95", "E195"};
}

#endif