//
// Created by prota on 15.10.2020.
//

#include "Octagon.h"

Octagon::Octagon(Cord center, double radius):Figure(center,radius){};

double Octagon::Area(){
    return 8 * 0.5 * sin((double) 45 / 180 * PI) * Radius * Radius;
}

void Octagon::print(){
    for (int i = 0; i < 5; ++i){
        Cord radVector(Radius * sin((double) (i * 45) / 180 * PI), Radius * cos((double) (i * 45) / 180 * PI));
        std::cout << Center + radVector << ", ";
    }
}