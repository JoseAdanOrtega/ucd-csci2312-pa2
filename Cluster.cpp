//
// Created by Jose on 2/16/2016.
//

#include <iostream>
#include <fstream>
#include "cluster.h"

using namespace std;

namespace Clustering {
    LNode::LNode(const Point &p, LNodePtr n): point(p){
        next = n;
    }

    Cluster::Cluster(){

    }

    // The big three: cpy ctor, overloaded operator=, dtor
    Cluster::Cluster(const Cluster &){

    }

    Cluster &Cluster::operator=(const Cluster &) {

    }

    Cluster::~Cluster(){

    }

    // Getters/setters
    // TODO add to the requirements
    int Cluster::getSize() const{

    }

    // Set functions: They allow calling c1.add(c2.remove(p));
    // TODO add asc order to the requirements
    void Cluster::add(const Point &){

    }

    const Point &Cluster::remove(const Point &pass){

    }

    bool Cluster::contains(const Point &){

    }

    // Overloaded operators

    // Members: Subscript

    // notice: const
    const Point &Cluster::operator[](unsigned int index) const{

    }

    // Members: Compound assignment (Point argument)
    Cluster &Cluster::operator+=(const Point &){

    }

    Cluster &Cluster::operator-=(const Point &){

    }

    // Members: Compound assignment (Cluster argument)

    // union
    Cluster &Cluster::operator+=(const Cluster &){

    }

    // (asymmetric) difference
    Cluster &Cluster::operator-=(const Cluster &){

    }

    // Friends: IO
    std::ostream &operator<<(std::ostream &output, const Cluster &Clust){

    }

    std::istream &operator>>(std::istream &input, Cluster &Clust){

    }

    // Friends: Comparison
    bool operator==(const Cluster &, const Cluster &){

    }

    bool operator!=(const Cluster &, const Cluster &){

    }

    // Friends: Arithmetic (Cluster and Point)
    const Cluster operator+(const Cluster &, const Point &){

    }

    const Cluster operator-(const Cluster &, const Point &){

    }

    // Friends: Arithmetic (two Clusters)

    // union
    const Cluster operator+(const Cluster &, const Cluster &){

    }

    // (asymmetric) difference
    const Cluster operator-(const Cluster &, const Cluster &){

    }
}