#include "ifigure.h"

#include <QDebug>

IFigure::IFigure()
{

}

void IFigure::globalToLocal(){
    for(auto &i:coordinates){
        i.setX(i.x() - centerCoordinates.x());
        i.setY(i.y() - centerCoordinates.y());
    }
}

void IFigure::localToGlobal(){
    for(auto &i:coordinates){
        i.setX(i.x() + centerCoordinates.x());
        i.setY(i.y() + centerCoordinates.y());
    }
}

void IFigure::rotation(double roll){
    globalToLocal();
    for(int i = 0; i<coordinates.size(); ++i){
        auto x = coordinates[i].x();
        coordinates[i].setX(x * cos(qDegreesToRadians(roll)) + coordinates[i].y() * sin(qDegreesToRadians(roll)));
        coordinates[i].setY(-1*x * sin(qDegreesToRadians(roll)) + coordinates[i].y() * cos(qDegreesToRadians(roll)));
    }
    localToGlobal();
}

void IFigure::scaleUp(double k){
    if(k!=0){
        globalToLocal();
        for (int i = 0; i < coordinates.size(); ++i) {
            coordinates[i].setX(coordinates[i].x()*k);
            coordinates[i].setY(coordinates[i].y()*k);
        }
        localToGlobal();
        perimeter *= k;
        area *= k*k;
    }
}

void IFigure::scaleDown(double k){
    if(perimeter>=8&&k!=0){
        globalToLocal();
        for (int i = 0; i < coordinates.size(); ++i) {
            coordinates[i].setX(coordinates[i].x()/k);
            coordinates[i].setY(coordinates[i].y()/k);
        }
        localToGlobal();
        perimeter /= k;
        area /= k*k;
    }
}

void IFigure::transform(double x, double y){
    for (int i = 0; i < coordinates.size(); ++i) {
        coordinates[i].setX(x + coordinates[i].x());
        coordinates[i].setY(y + coordinates[i].y());
    }
    centerCoordinates.setX(centerCoordinates.x()+x);
    centerCoordinates.setY(centerCoordinates.y()+y);
}
