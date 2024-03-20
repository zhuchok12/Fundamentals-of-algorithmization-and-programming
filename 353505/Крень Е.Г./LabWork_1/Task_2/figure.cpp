#include "figure.h"

#define PI 3.1415926535

figures::circle::circle(QVector2D coordinate, int radius, float valueSectors)
{
    area = PI*radius*radius;
    perimeter = 2 * PI * radius;
    centerCoordinates = coordinate;
    float angle = 360/valueSectors;

    for (int i = 0; i <= valueSectors; i++)
    {
        float currentAngle = angle * i;
        float x = radius * cos(qDegreesToRadians(currentAngle));
        float y = radius * sin(qDegreesToRadians(currentAngle));

        coordinates.push_back(QVector2D(x + coordinate.x(), y + coordinate.y()));
    }
}

figures::square::square(QVector2D coordinate, int length)
    :circle(coordinate, length/sqrt(2), 4)
{
    area = length*length;
    perimeter = 4 * length;
    rotation(45);

}

figures::triangle::triangle(QVector2D coordinate, int length)
    :circle(coordinate, length, 3)
{
    area = length*length*sqrt(3)/4;
    perimeter = 3 * length;
    rotation(90);
}

figures::hexagon::hexagon(QVector2D coordinate, int length)
    :circle(coordinate, length, 6)
{
    area = 6*length*length*sqrt(3)/4;
    perimeter = 6 * length;
    rotation(90);
}

figures::elipse::elipse(QVector2D coordinate, int bigAxis, int smallAxis){

    area = PI*bigAxis*smallAxis;
    perimeter = PI*sqrt(bigAxis*bigAxis/2 + smallAxis*smallAxis/2);
    centerCoordinates = coordinate;
    for (int i = 0; i <= 100; i++)
    {
        float currentAngle = 3.6 * i;
        float x = bigAxis * cos(qDegreesToRadians(currentAngle));
        float y = smallAxis * sin(qDegreesToRadians(currentAngle));

            coordinates.push_back(QVector2D(x + coordinate.x(), y + coordinate.y()));

    }
}

figures::rhomb::rhomb(QVector2D coordinate, int width, int length)
{
    area = length*width/2;
    perimeter = (length+width)*2;
    centerCoordinates = coordinate;

    coordinates.push_back(QVector2D(coordinate.x(), width/2 + coordinate.y()));
    coordinates.push_back(QVector2D(length/2 + coordinate.x(), coordinate.y()));
    coordinates.push_back(QVector2D(coordinate.x(), coordinate.y() - width/2));
    coordinates.push_back(QVector2D(coordinate.x() - length/2 ,coordinate.y()));
    coordinates.push_back(QVector2D(coordinate.x(), width/2 + coordinate.y()));
}

figures::star::star(QVector2D coordinate, int bigR, int smallR)
{
    float a = smallR/(sqrt(0.5+sqrt(5)/10));
    float h = sin(qDegreesToRadians(54))*smallR;
    float tr = (bigR-h)*a/2;
    area = 5*(tr + a*h/2);
    centerCoordinates = coordinate;
    for (int i = 0; i <= 5; i++)
    {
        float currentAngle = 72 * i;
        float x = bigR * sin(qDegreesToRadians(currentAngle));
        float y = bigR * cos(qDegreesToRadians(currentAngle));
        coordinates.push_back(QVector2D(x + coordinate.x(), coordinate.y() - y));

        currentAngle += 36;
        x = smallR * sin(qDegreesToRadians(currentAngle));
        y = smallR * cos(qDegreesToRadians(currentAngle));

        coordinates.push_back(QVector2D(x + coordinate.x(), coordinate.y() - y));
    }

    perimeter = 10*sqrt(pow(coordinates[0].x()-coordinates[1].x(), 2)+pow(coordinates[0].y()-coordinates[1].y(), 2));

}

figures::trapezoid::trapezoid(QVector2D coordinate, float length1, float length2, float height)
{
    area = height*(length1+length2)/2;
    perimeter = 2*sqrt(height*height+(length2-length1)*(length2-length1)/4)+length1+length2;
    centerCoordinates = coordinate;
    coordinates.push_back(QVector2D(coordinate.x() + length2/2, coordinate.y() + height/2));
    coordinates.push_back(QVector2D(coordinate.x() - length2/2, coordinate.y() + height/2));
    coordinates.push_back(QVector2D(coordinate.x() - length1/2, coordinate.y() - height/2));
    coordinates.push_back(QVector2D(coordinate.x() + length1/2, coordinate.y() - height/2));
    coordinates.push_back(QVector2D(coordinate.x() + length2/2, coordinate.y() + height/2));
}


figures::rectangle::rectangle(QVector2D coordinate, int length, int width)
{
    area = length*width;
    perimeter = (length+width)*2;
    centerCoordinates = coordinate;
    coordinates.push_back(QVector2D(coordinate.x() + length/2, coordinate.y() + width/2));
    coordinates.push_back(QVector2D(coordinate.x() - length/2, coordinate.y() + width/2));
    coordinates.push_back(QVector2D(coordinate.x() - length/2, coordinate.y() - width/2));
    coordinates.push_back(QVector2D(coordinate.x() + length/2, coordinate.y() - width/2));
    coordinates.push_back(QVector2D(coordinate.x() + length/2, coordinate.y() + width/2));
}

