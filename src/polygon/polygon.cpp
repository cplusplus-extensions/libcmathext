#include "polygon.h"

/**
 * @brief Construct a new Polygon object
 * 
 * @param polygon 
 * @param value 
 * @param value1 
*/
Polygon::Polygon(std::string polygon, int value, int value1) {
    this->polygon = polygon;
    this->value = value;
    this->value1 = value1;
}

/**
 * @brief Questa funzione permette di calcolare l'area di un triangolo.
 * 
 * @param base 
 * @param height 
 * @return double
 */
double Polygon::triangleArea(int base, int height) {
    return (double)(base*height)/2.0;
}

/**
 * @brief Questa funzione permette di calcolare l'area di alcuni tipi di poligoni, basandosi sulla struttura Polygon
 * sopra implementata. ATTENZIONE: i tipi di poligoni permessi sono:
 * 1) SQUARE;
 * 2) RECTANGLE;
 * 3) RHOMBUS;
 * 4) PARALLELOGRAM;
 * 5) tutti i poligoni il cui nome inglese termina in "GON";
 * Tutti gli altri poligoni (se ve ne sono) sono ancora non supportati e verranno aggiunti in seguito.
 * 
 * @param polygon 
 * @return double
 */
double Polygon::polygonArea(Polygon polygon, int numLati) {
    if(polygon.polygon.compare("SQUARE") == 0 || polygon.polygon.compare("RECTANGLE") == 0 || polygon.polygon.compare("PARALLELOGRAM") == 0) {
        return polygon.value*polygon.value1;
    } else {
        if(polygon.polygon.compare("RHOMBUS") == 0) {
            return (double)(polygon.value*polygon.value1)/2.0; //Input values correspond to the two diagonals
        } else {
            if(polygon.polygon.compare("TRIANGLE") == 0) {
                return triangleArea(polygon.value, polygon.value1);
            } else {
                if(polygon.polygon.find("GON", polygon.polygon.length() - 3)) {
                    return numLati*triangleArea(polygon.value, polygon.value1);
                } else {
                    std::cerr << "Not supported yet." << "\n";
                }
            }
        }
    }

    return -1;
}

/**
 * @brief Questa funzione permette di calcolare l'area di un cerchio.
 * 
 * @param radius 
 * @return double 
 */
double Polygon::circleArea(int radius) {
    return M_PI*radius*radius;
}

/**
 * @brief Questa funzione permette di calcolare il volume di una sfera.
 * 
 * @param radius 
 * @return double 
 */
double Polygon::sphereVolume(int radius) {
    return (4.0/3.0)*M_PI*radius*radius*radius;
}
