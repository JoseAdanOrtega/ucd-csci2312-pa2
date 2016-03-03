////
//// Created by Jose on 2/16/2016.
////
//

#include <algorithm>
#include <sstream>

#include "Cluster.h"

namespace Clustering {
    LNode::LNode(const Point &p, LNodePtr n) : point(p) {
        next = n;
    }

    // ******************************************************************

    Cluster::Cluster() {
        __size = 0;

        __points = nullptr;
    }

    // ******************************************************************

    Cluster::Cluster(const Cluster &pass) {
        __size = pass.getSize();

        __cpy(pass.__points);
    }

    // ******************************************************************

    Cluster &Cluster::operator=(const Cluster &pass) {
        if (this != &pass) {

            __size = pass.__size;

            __del();

            __cpy(pass.__points);
        }
        return *this;
    }

    // ******************************************************************

    Cluster::~Cluster() {
        __del();
    }

    // ******************************************************************

    int Cluster::getSize() const {
        return __size;
    }

    // ******************************************************************

    void Cluster::__del() {
        LNodePtr temp = __points;

        LNodePtr next;

        for (int i = 0; i < __size; ++i) {
            if (__points != nullptr) {
                next = temp->next;

                delete temp;

                temp = next;
            }
        }
        __points = nullptr;
    }

    // ******************************************************************

    void Cluster::__cpy(LNodePtr temp) {
        if (temp != nullptr){
            LNodePtr null = nullptr;

            LNode *head = new LNode(temp -> point, null);

            LNodePtr currentptr = temp -> next;

            __points = head;

            LNodePtr current = __points;

            while (currentptr != nullptr) {
                current -> next = new LNode(currentptr-> point, null);

                current = current -> next;

                currentptr = currentptr-> next;
            }
        }
    }

    // ******************************************************************

    void Cluster::add(const Point &pass) {

        if (__points == nullptr) {
            LNode *Temp = new LNode(pass, nullptr);

            __points = Temp;

            ++__size;

            return;
        }

        if (__points->next == nullptr) {
            LNode *Temp = new LNode(pass, nullptr);

            if (Temp -> point < __points -> point) {
                Temp -> next = __points;

                __points = Temp;

                ++__size;

                return;
            }

            else {
                __points -> next = Temp;

                ++__size;

                return;
            }
        }

        LNode *Temp = new LNode(pass, nullptr);

        LNodePtr current = __points -> next;

        LNodePtr prev = __points;

        if (Temp -> point < __points->point) {
            __points = Temp;

            Temp -> next = prev;

            ++__size;

            return;
        }

        if (Temp -> point < current -> point) {
            prev -> next = Temp;

            Temp -> next = current;

            ++__size;

            return;
        }

        while (current -> next != nullptr) {
            if (Temp -> point < current -> point) {
                prev = Temp;

                Temp -> next = prev;

                ++__size;

                return;
            }
            current = current -> next;

            prev = prev -> next;
        }
        current -> next = Temp;

        ++__size;
    }

    // ******************************************************************

    const Point &Cluster::remove(const Point &pass) {
        LNodePtr temp = __points;

        if (temp -> point == pass) {

            temp = __points;

            if (__size > 0) {
                __points = __points -> next;

                --__size;
            }

            delete temp;
        }

        else{
            int i = 0;

            LNodePtr prev = temp;

            temp = temp -> next;

            for (; i < __size; ++i) {
                if (temp -> point == pass) {
                    if (temp -> next == nullptr) {
                        prev -> next = nullptr;

                        delete temp;

                        __size--;
                    }
                    else {
                        prev -> next = temp -> next;
                    }
                }
                temp = temp -> next;

                prev = prev -> next;
            }
        }
        return pass;
    }

    // ******************************************************************

    bool Cluster::contains(const Point &P1) {

        LNodePtr temp;

        if (P1 == __points -> point) {
            return true;
        }

        if (__points -> next == nullptr) {
            return false;
        }

        temp = __points -> next;

        for (int i = 1; i < __size; ++i) {
            if (temp -> point == P1) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // ******************************************************************

    const Point &Cluster::operator[](unsigned int index) const {
        LNodePtr temp = __points;

        if (index == 0) {
            return __points->point;
        }

        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }

        return temp->point;
    }

    // ******************************************************************

    bool operator==(const Cluster &C1, const Cluster &C2) {
        if (C1.__size != C2.__size) {
            return false;
        }

        for (int i = 0; i < C1.__size; ++i) {
            if (C1[i] != C2[i]) {
                return false;
            }
        }
        return true;
    }

    // ******************************************************************

    bool operator!=(const Cluster &C1, const Cluster &C2) {
        return !(C1 == C2);
    }

    // ******************************************************************

    Cluster &Cluster::operator+=(const Point &P1) {
        this->add(P1);

        return *this;
    }

    // ******************************************************************

    Cluster &Cluster::operator-=(const Point &P1) {
        this->remove(P1);
        return *this;
    }

    // ******************************************************************

    // Members: Compound assignment (Cluster argument)
    Cluster &Cluster::operator+=(const Cluster &C2) { // union

        for (int i = 0; i < C2.getSize(); ++i) {
            if (!(this->contains(C2[i]))) {
                this->add(C2[i]);
            }
        }
        return *this;
    }

    // ******************************************************************

    Cluster &Cluster::operator-=(const Cluster &C2) { // (asymmetric) difference
        for (int i = 0; i < C2.getSize(); ++i) {
            if (this->contains(C2[i])) {
                this->remove(C2[i]);
            }
        }

        return *this;
    }

    // ******************************************************************

    // Friends: Arithmetic (Cluster and Point)
    const Cluster operator+(const Cluster &left, const Point &right) {
        Cluster *C2 = new Cluster(left);
        if (!(C2->contains(right))) {
            C2->add(right);
        }

        else {
            return left;
        }
        return *C2;
    }

    // ******************************************************************

    const Cluster operator-(const Cluster &left, const Point &right) {
        Cluster *C2 = new Cluster(left);
        if (C2->contains(right)) {
            C2->remove(right);
        } else {
            return left;
        }
        return *C2;
    }

    // ******************************************************************

    // Friends: Arithmetic (two Clusters)
    const Cluster operator+(const Cluster &left, const Cluster &right) {
        Cluster *C3 = new Cluster(left);
        Cluster *C4 = new Cluster(right);

        for (int i = 0; i < C4->getSize(); ++i) {
            if (!(C3->contains(right[i]))) {
                C3->add(right[i]);
            }
        }
        delete C4;
        return *C3;
    }

    // ******************************************************************

    const Cluster operator-(const Cluster &left, const Cluster &rigth) {
        Cluster *C3 = new Cluster(left);
        Cluster *C4 = new Cluster(rigth);

        for (int i = 0; i < C3->getSize(); ++i) {
            if (C3->contains(rigth[i])) {
                C3->remove(rigth[i]);
            }
        }
        delete C4;
        return *C3;
    }

    // ******************************************************************

    std::ostream &operator<<(std::ostream &output, const Cluster &Clust) {
        LNodePtr temp = Clust.__points;
        for (int i = 0; i < Clust.__size; ++i) {
            output << temp->point << std::endl;
            temp = temp->next;
        }
        return output;
    }

    // ******************************************************************

    std::istream &operator>>(std::istream &in, Cluster &cluster) {
        while (!in.eof()) {
            Point p(1);

            std::string str;
            std::getline(in, str);

            if (str.length() > 0) {
                std::stringstream ss(str);

                ss >> p;

                cluster.add(p);
            }
        }

        return in;
    }
}