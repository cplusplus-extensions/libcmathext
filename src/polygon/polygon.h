#ifndef POLYGON_H
#define POLYGON_H
#ifdef __GNUC__
#if __GNUC__ < 13
#define _USE_MATH_DEFINES
#endif
#endif

#include <iostream>
#include <cmath>

/**
 * @brief La seguente classe rappresenta la base per l'implementazione delle funzioni riguardanti il calcolo delle aree
 * dei poligoni sottostanti. ATTENZIONE: questa classe DEVE essere implementata in questo modo, altrimenti le funzioni di cui
 * si è appena parlato devono essere reimplementate.
 * 
 */
class Polygon {
    private:
        std::string polygon; //Name of the polygon
        int value, value1; //Parameters to be taken when calculating the area of the polygon
    
    public:
        explicit Polygon(std::string polygon, int value, int value1);
        double triangleArea(int base, int height);
        double polygonArea(const Polygon& polygon, int numLati);
        double circleArea(int radius);
        double sphereVolume(int radius);
};

#endif
