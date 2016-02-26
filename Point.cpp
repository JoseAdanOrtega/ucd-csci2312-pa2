//
// Created by Jose on 2/16/2016.
//
#include <iostream>
#include <fstream>
#include "Point.h"

using namespace std;



namespace Clustering {
         unsigned int Point::__idGen = 0; // id generator

        //default constructor
        Point::Point(int pass){
        __id =  __idGen;        //Gives an ID to the class

        __idGen++;              //Increments ID so it can be different everytime

        __dim = pass;           //Assigns the current dimention

        __values = new double[__dim];   //Give Values the value of dim in a new double
        }

        //constructor
        Point::Point(int pass, double * thing){

        }

        //copy constructor
        Point::Point(const Point &point){

        }

        //overloaded operator=
        Point &Point::operator=(const Point &point){

        }

        //destructor
        Point::~Point(){

        }

        // Accessors & mutators
        int Point::getId() const{

        }

        int Point::getDims() const{

        }

        void Point::setValue(int, double){

        }
        double Point::getValue(int) const{

        }

        // Functions
        double Point::distanceTo(const Point &) const{

        }

        // Overloaded operators

        // Members

        // p *= 6; p.operator*=(6);
        Point &Point::operator*=(double){

        }

        Point &Point::operator/=(double){

        }

        // prevent (p1 * 2) = p2;
        const Point Point::operator*(double) const{

        }

        // p3 = p2 / 2;
        const Point Point::operator/(double) const{

        }

        double &Point::operator[](int index){

        }

        // Friends

        Point &operator+=(Point &left, const Point &right){

        }

        Point &operator-=(Point &left, const Point &right){

        }

        const Point operator+(const Point &left, const Point &right){

        }

        const Point operator-(const Point &left, const Point &right){

        }

        bool operator==(const Point &left, const Point &right){

        }


        bool operator!=(const Point &left, const Point &right){

        }

        bool operator<(const Point &left, const Point &right){

        }

        bool operator>(const Point &left, const Point &right){

        }

        bool operator<=(const Point &left, const Point &right){

        }

        bool operator>=(const Point &left, const Point &right){

        }


        std::ostream &operator<<(std::ostream &, const Point &){

        }

        std::istream &operator>>(std::istream &, Point &){

        }
    }
