#ifndef IFIGURE_H
#define IFIGURE_H

#include <QVector2D>
#include <QVector>

class IFigure
{
public:
    IFigure();
    void setCoordinates(QVector<QVector2D> c){coordinates = c;}
    void setCenterCoordinates(QVector2D c){centerCoordinates = c;}
    float getArea(){return area;}
    float getPerimeter(){return perimeter;}
    void rotation(double roll);
    void scaleUp(double k);
    void scaleDown(double k);
    void transform(double x, double y);
    QVector2D getCenterCoordinates(){return centerCoordinates;}
    const QVector<QVector2D>& getCoordinates(){return coordinates;}
    void localToGlobal();
    void globalToLocal();
protected:
    float area;
    float perimeter;
    QVector2D centerCoordinates;
    QVector<QVector2D> coordinates;
};

#endif // IFIGURE_H
