//
// Created by Jose on 2/16/2016.
//
#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.h"

using namespace std;

namespace Clustering {
         unsigned int Point::__idGen = 0; // id generator

        //default constructor
        Point::Point(int pass){
                __id =  __idGen;        //Gives an ID to the class

                __idGen++;              //Increments ID so it can be different everytime

                __dim = pass;           //Assigns the current dimention

                __values = new double[__dim];   //Creates a dynamic array with the passed in number

                for(int i = 0; i < __dim; i++)   //Gives every value in the array a value of 0.0
                        __values[i] = 0.0;

        }

        //constructor
        Point::Point(int pass, double * thing){
                __id =  __idGen;        //Gives an ID to the class

                __idGen++;              //Increments ID so it can be different everytime

                __dim = pass;           //Assigns the current dimention

                __values = new double[__dim];   //Creates an array with the passed in number

                for(int i = 0; i < __dim; i++)   //Gives every value in the array a values of the passed in array
                        __values[i] = thing[i];

        }

        //copy constructor
        Point::Point(const Point &pass){
                __dim = pass.__dim;               //gives the same ID of the point being passed in

                __values = new double[__dim];     //Creates an array with the passed in number

                __id = pass.__id;                 //ID is copied

                for(int i = 0; i < __dim; i++)  //Gives every value in the array a value of 0.0
                         __values[i] = pass.__values[i];

        }

        //overloaded operator=
        Point &Point::operator=(const Point &point){
                if(this != &point){
                        __dim = point.__dim;            //sets the dimention to the dimention passed in

                        __id = point.__id;              //sets the dimention to the dimention passed in

                        delete [] __values;             //Deletes all values in array

                        __values = new double [__dim];  //Creates an array with the passed in number

                        for(int i = 0; i < __dim; i++)
                                __values[i] = point.__values[i];
                }

                return *this;
        }

        //destructor
        Point::~Point(){
                delete []__values;      //deletes values[]
        }

        // Accessors & mutators
        int Point::getId() const{
                return __id;
        }

        int Point::getDims() const{
                return __dim;
        }

        void Point::setValue(int i, double pass){
                __values[i] = pass;
        }

        double Point::getValue(int i) const{
                return __values[i];
        }

        // Functions
        double Point::distanceTo(const Point &pass) const{
                double total = 0;               //Will hold on to the current value of the things being multiplied

                if(__dim != pass.__dim) {
                        return false;
                }

                for(int i = 0; i < __dim; i++)
                        total = total + (pow(pass.getValue(i) - getValue(i), 2));

                return (sqrt(total));

        }

        // Overloaded operators

        // Members

        // p *= 6; p.operator*=(6);
        Point &Point::operator*=(double pass){
                for(int i = 0; i < __dim; i++)
                        __values[i] *= pass;

                return *this;
        }

        Point &Point::operator/=(double pass){
                for(int i = 0; i < __dim; i++)
                        __values[i] /= pass;

                return *this;
        }

        // prevent (p1 * 2) = p2;
        const Point Point::operator*(double pass) const{
                Point temp(__dim);

                for(int i = 0; i < __dim; i++)
                        temp.__values[i] = __values[i] * pass;

                return temp;
        }

        // p3 = p2 / 2;
        const Point Point::operator/(double pass) const{
                Point temp(__dim);

                for(int i = 0; i < __dim; i++)
                        temp.__values[i] = __values[i] / pass;

                return temp;
        }

        double &Point::operator[](int index){
                return this -> __values[index];
        }

        // Friends

        Point &operator+=(Point &left, const Point &right){
                for(int i = 0; i < left.__dim; i++)
                        left.__values[i] = left.__values[i] + right.__values[i];

                return left;
        }

        Point &operator-=(Point &left, const Point &right){
                for(int i = 0; i < left.__dim; i++)
                        left.__values[i] = left.__values[i] - right.__values[i];

                return left;
        }

        const Point operator+(const Point &left, const Point &right){
                Point temp(left.__dim);

                for(int i = 0; i < left.__dim; i++)
                        temp.__values[i] = left.__values[i] + right.__values[i];

                return temp;
        }

        const Point operator-(const Point &left, const Point &right){
                Point temp(left.__dim);

                for(int i = 0; i < left.__dim; i++)
                        temp.__values[i] = left.__values[i] - right.__values[i];

                return temp;
        }

        bool operator==(const Point &left, const Point &right){
                bool temp = true;

                if(left.__dim != right.__dim || left.__id != right.__id)
                        temp = false;

                for(int i = 0; i < left.getDims(); i++){
                        if(left.__values[i] != right.__values[i])
                                temp = false;
                }

                return temp;
        }


        bool operator!=(const Point &left, const Point &right){
                bool temp = false;

                if(left.__dim != right.__dim || left.__id != right.__id)
                        temp = true;

                for(int i = 0; i < left.getDims(); i++){
                        if(left.__values[i] != right.__values[i])
                                temp = true;
                }

                return temp;
        }

        bool operator<(const Point &left, const Point &right){
                bool temp = true;

                if(left.__dim > right.__dim)
                        temp = false;

                for(int i = 0; i < left.getDims(); i++){
                        if(left.__values[i] > right.__values[i])
                                temp = false;
                }

                return temp;
        }

        bool operator>(const Point &left, const Point &right){
                bool temp = true;

                if(left.__dim < right.__dim)
                        temp = false;

                for(int i = 0; i < left.getDims(); i++){
                        if(left.__values[i] < right.__values[i])
                                temp = false;
                }

                return temp;
        }

        bool operator<=(const Point &left, const Point &right){
                bool temp = true;

                if(left > right)
                        temp = false;

                return temp;
        }

        bool operator>=(const Point &left, const Point &right){
                bool temp = true;

                if(left < right)
                        temp = false;

                return temp;
        }


        ostream &operator<<(ostream &output, const Point &pass){
                for(int i = 0; i < pass.getDims(); i++){
                        output << pass.getValue(i);

                        if(i != pass.getDims() -1)
                                output << ", ";
                }

                return output;
        }

        istream &operator>>(istream &input, Point &pass){
                int i = 0;
                string s1,s2;

                while(!input.eof()){
                        getline(input, s1);

                        stringstream ss1(s1);

                        while(!ss1.eof()){
                                getline(ss1,s2, ',');

                                stringstream ss2(s2);

                                ss2 >> pass.__values[i];

                                ++i;
                        }

                }

                return input;
        }
    }
