#include "polygon.h"

#include <utility>

/**
 * @brief Construct a new Polygon object
 * 
 * @param polygon 
 * @param value 
 * @param value1 
*/
Polygon::Polygon(std::string polygon, int value, int value1) {
    this->polygon = std::move(polygon);
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
 * sopra implementata.
 * 
 * @attention I tipi di poligoni permessi sono:
 * 1) SQUARE;
 * 2) RECTANGLE;
 * 3) RHOMBUS;
 * 4) PARALLELOGRAM;
 * 5) tutti i poligoni il cui nome inglese termina in "GON";
 * Tutti gli altri poligoni (se ve ne sono) sono ancora non supportati e verranno aggiunti in seguito.
 * 
 * @warning Questa funzione lancia un'eccezione std::invalid_argument quando il numero di lati specificato è negativo o nullo.
 * 
 * @param polygon Il poligono di cui calcolare l'area
 * @return double L'area del poligono specificato
 */
double Polygon::polygonArea(const Polygon& polygon, int numLati) {
    if(numLati <= 0) {
        throw std::invalid_argument("The number of edges of a polygon cannot be less than or equal to zero.");
    }
    if(polygon.polygon == "SQUARE" || polygon.polygon == "RECTANGLE" || polygon.polygon == "PARALLELOGRAM") {
        return polygon.value*polygon.value1;
    } else {
        if(polygon.polygon == "RHOMBUS") {
            return (double)(polygon.value*polygon.value1)/2.0; //Input values correspond to the two diagonals
        } else {
            if(polygon.polygon == "TRIANGLE") {
                return triangleArea(polygon.value, polygon.value1);
            } else {
                if(polygon.polygon.find("GON", polygon.polygon.length() - 3)) {
                    return numLati*triangleArea(polygon.value, polygon.value1);
                } else {
                    throw std::invalid_argument("Not supported yet.");
                }
            }
        }
    }
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
 * @warning Questa funzione lancia un'eccezione std::overflow_error quando il numero da rappresentare è troppo grande per poter essere memorizzato.
 * @warning Questa funzione lancia un'eccezione std::invalid_argument quando il raggio fornito come parametro formale è un numero negativo.
 * @exception std::overflow_error Eccezione lanciata quando il numero da rappresentare è troppo grande per poter essere memorizzato
 * @exception std::invalild_argument Eccezione lanciata quando il raggio fornito come parametro formale è un numero negativo
 * @param radius Il raggio della sfera
 * @return double Il volume della sfera calcolato
 */
double Polygon::sphereVolume(int radius) {
    if(radius < 0) {
        throw std::invalid_argument("The given radius is invalid. Try giving a positive or null radius.");
    }
    return (4.0/3.0)*M_PI*radius*radius*radius;
}
