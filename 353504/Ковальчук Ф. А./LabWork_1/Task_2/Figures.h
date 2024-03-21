#ifndef FIGURES_H
#define FIGURES_H
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <math.h>
#include <QDebug>

class IFigure{
    friend class MainWindow;

public:
    virtual void Clear(){
        m_points.clear();
        m_centre = QPoint(0.0f, 0.0f);
        m_perimetr = 0.0f;
        m_square = 0.0f;
        m_scale = 1.0f;
    }
    virtual void UpdateMassCentre(){
        m_centre = QPoint(0.0f, 0.0f);
        for(int i = 0; i < m_points.size(); i++){
            m_centre += m_points[i];
        }
        m_centre /= m_points.size();
    }
    virtual void CalcPerimetr(){
        m_perimetr = 0;
        for(int i = 0; i < m_points.size() - 1; i++){
            float dX = m_points[i].x() - m_points[i+1].x();
            float dY = m_points[i].y() - m_points[i+1].y();
            m_perimetr += sqrt(dX * dX + dY * dY);
        }

        //connect last and first
        float dX = m_points[0].x() - m_points[m_points.size() - 1].x();
        float dY = m_points[0].y() - m_points[m_points.size() - 1].y();
        m_perimetr += sqrt(dX * dX + dY * dY);
    }
    virtual void CalcSquare(){
        m_square = 0.0f;

        if(m_points.size() >= 3){
            for(int i = 0; i < m_points.size() - 1; i++){
                m_square += m_points[i].x() * m_points[i + 1].y() - m_points[i].y() * m_points[i+1].x();
            }

            m_square += m_points[0].x() * m_points[m_points.size() - 1].y() - m_points[0].y() * m_points[m_points.size() - 1].x();
            m_square /= 2;
        }
    }

    virtual void Translate(float deltaX, float deltaY){
        for(int i = 0; i < m_points.size(); i++){
            m_points[i] -= QPointF(deltaX, deltaY);
        }
        m_centre -= QPointF(deltaX, deltaY);
    }
    virtual void Rotate(float delta){
        float sinA = std::sin(delta * 3.1415f / 180.0f);
        float cosA = std::cos(delta * 3.1415f / 180.0f);

        for(int i = 0; i < m_points.size(); i++){
            float localX = m_points[i].x() - m_centre.x();
            float localY = m_points[i].y() - m_centre.y();

            m_points[i] = QPointF(m_centre.x() + cosA * localX - sinA * localY,
                                  m_centre.y() +  sinA * localX + cosA * localY);
        }
    }
    virtual void Scale(bool isNegative){
        float scale = m_scale;
        if(isNegative && m_scale > 0.0f){
            m_scale -= 0.01f;
        }
        else if(!isNegative){
            m_scale += 0.01f;
        }

        for(int i = 0; i < m_points.size(); i++){
            m_points[i] = m_centre + ((m_points[i] - m_centre) / scale * m_scale);
        }
        CalcPerimetr();
        CalcSquare();
    }


    virtual void Draw(QPainter* painter) = 0;
    virtual void MouseEvent(QMouseEvent *mouseEvent) = 0;
protected:
    QPointF m_centre;
    QVector<QPointF> m_points;

    float m_perimetr;
    float m_square;

    float m_scale = 1.0f;
};

class Triangle : public IFigure{
public:
    void Draw(QPainter* painter) override{
        if(m_points.size() == 0) return;
        QPolygonF polygonF;
        QPointF pointF;

        for(int i = 0; i < m_points.size(); i++){
            pointF = QPointF(m_points[i]);
            polygonF << pointF;
        }

        CalcPerimetr();
        CalcSquare();

        if(m_points.size() == 1) painter->drawPoint(pointF);
        else painter->drawPolygon(polygonF);
    }

    void MouseEvent(QMouseEvent *mouseEvent) override{
        SetPoint(mouseEvent);
        UpdateMassCentre();

        CalcPerimetr();
        CalcSquare();
    }

    void SetPoint(QMouseEvent* mouseEvent){
        if(m_points.size() >= 3) m_points.clear();

        m_points.push_back(mouseEvent->pos());
        if(m_points.size() == 3){
            m_centre = (m_points[0] + m_points[1] + m_points[2]) / 3;
            CalcPerimetr();
            CalcSquare();
        }
    }


};

class Circle : public IFigure{
public:
    void MouseEvent(QMouseEvent *mouseEvent) override{
        SetPoint(mouseEvent);
    }
    void Draw(QPainter* painter) override{
        if(m_isInitCenter){
            QPen pen;
            pen.setColor(QColor("red"));
            pen.setWidth(5);
            painter->setPen(pen);
            painter->drawPoint(m_centre);
            //painter->drawPoint(m_points[0]);
        }
        if(m_points.size() == 0) return;

        //painter->drawEllipse(m_centre, m_points[0].x(), m_points[0].y());
        QPen pen;
        pen.setColor(QColor("black"));
        pen.setWidth(1);
        painter->setPen(pen);
        painter->drawPoint(m_points[0]);
        painter->drawEllipse(m_centre, m_radius, m_radius);
        pen.setColor(QColor("red"));
        pen.setWidth(5);
        painter->setPen(pen);
        painter->drawPoint(m_points[0]);
        //QPolygonF polygonF;
        //QPointF pointF;

        //for(int i = 0; i < m_points.size(); i++){
        //    pointF = QPointF(m_points[i]);
        //    polygonF << pointF;
        //}

        //CalcPerimetr();
        //CalcSquare();

        //if(m_points.size() == 1) painter->drawPoint(pointF);
        //else painter->drawPolygon(polygonF);
    }

    void CalcPerimetr() override{
        m_perimetr = 2.0f * 3.1415f * m_radius;
    }
    void CalcSquare() override{
        m_square = 3.1415f * m_radius * m_radius;
    }
    void SetPoint(QMouseEvent* mouseEvent){
        if(!m_isInitCenter){
            m_centre = mouseEvent->pos();
            m_isInitCenter = true;
        }
        else{
            if(m_points.size() == 0){
                m_points.push_back(mouseEvent->pos());
                float dX = m_centre.x() - m_points[0].x();
                float dY = m_centre.y() - m_points[0].y();
                m_radius = std::sqrt(dX * dX + dY * dY);
                //qInfo() << m_radius;
                CalcPerimetr();
                CalcSquare();

            }

                /*float xp;
                float xn;
                float yp;
                float yn;

                if(m_points[0].x() >= m_centre.x()){
                    xp = m_centre.x();
                    xn = xp + m_radius;
                }
                else{
                    xn = m_centre.x();
                    xp = xn - m_radius;
                }

                if(m_points[0].y() >= m_centre.y()){
                    yp = m_centre.y();i
                    yn = yp + m_radius;
                }
                else{
                    yn = m_centre.y();
                    yp = yn - m_radius;
                }

                m_centre = QPointF((xp + xn) / 2.0f, (yp + yn) / 2.0f);

            }*/
            else{
                m_points.clear();
                m_centre = mouseEvent->pos();
            }
        }
    }

    void Scale(bool isNegative) override{
        float scale = m_scale;
        if(isNegative && m_scale > 0.0f){
            m_scale -= 0.01f;
        }
        else if(!isNegative){
            m_scale += 0.01f;
        }

        for(int i = 0; i < m_points.size(); i++){
            m_points[i] = m_centre + ((m_points[i] - m_centre) / scale * m_scale);
        }

        float dX = m_centre.x() - m_points[0].x();
        float dY = m_centre.y() - m_points[0].y();
        m_radius = std::sqrt(dX * dX + dY * dY);

        CalcPerimetr();
        CalcSquare();
    }
private:

    float m_radius = 0.0f;
    bool m_isInitCenter = false;
};

class Rhomb : public IFigure{
    void MouseEvent(QMouseEvent *mouseEvent) override{
        SetPoint(mouseEvent);
    }
    void Draw(QPainter* painter) override{
        if(m_points.size() != 4) return;
        painter->drawLine(m_points[0], m_points[1]);
        painter->drawLine(m_points[1], m_points[2]);
        painter->drawLine(m_points[2], m_points[3]);
        painter->drawLine(m_points[0], m_points[3]);
    }
    void CalcPerimetr() override{
        float dX = m_points[0].x() - m_points[1].x();
        float dY = m_points[0].y() - m_points[1].y();
        m_perimetr = 4 * std::sqrt(dX * dX + dY * dY);
    }
    void CalcSquare() override{
        float a = std::max(abs(m_points[0].x() - m_centre.x()), abs(m_points[0].y() - m_centre.y()));
        m_square = 2 * a * a;
    }
    void SetPoint(QMouseEvent* mouseEvent){
        if(!m_isInitCenter){
            m_centre = mouseEvent->pos();
            m_isInitCenter = true;
        }
        else{
            if(m_points.size() != 4){
                float a = abs(mouseEvent->pos().x() - m_centre.x());
                float b = abs(mouseEvent->pos().y() - m_centre.y());
                m_points.push_back(m_centre + QPointF(a, 0));

                m_points.push_back(m_centre + QPointF(0, b));
                m_points.push_back(m_centre + QPointF(-a, 0));
                m_points.push_back(m_centre + QPointF(0, -b));
                //m_points.push_back(mouseEvent->pos());

                CalcPerimetr();
                CalcSquare();
            }
            else{
                m_points.clear();
                m_centre = mouseEvent->pos();
            }
        }
    }
private:

    bool m_isInitCenter = false;
};

class Rect : public IFigure{
    void MouseEvent(QMouseEvent *mouseEvent) override{
        SetPoint(mouseEvent);
    }
    void Draw(QPainter* painter) override{
        if(m_points.size() != 4) return;
        painter->drawLine(m_points[0], m_points[1]);
        painter->drawLine(m_points[1], m_points[2]);
        painter->drawLine(m_points[2], m_points[3]);
        painter->drawLine(m_points[0], m_points[3]);
    }
    void CalcPerimetr() override{
        m_perimetr = m_a * 2 + m_b * 2;
    }
    void CalcSquare() override{
        m_square = m_a * m_b;
    }
    void SetPoint(QMouseEvent* mouseEvent){
        if(!m_isInitCenter){
            m_centre = mouseEvent->pos();
            m_isInitCenter = true;
        }
        else{
            if(m_points.size() != 4){
                float a = abs(mouseEvent->pos().x() - m_centre.x());
                float b = abs(mouseEvent->pos().y() - m_centre.y());
                m_a = a * 2;
                m_b = b * 2;
                m_points.push_back(m_centre + QPointF(-a, -b));

                m_points.push_back(m_centre + QPointF(-a, b));
                m_points.push_back(m_centre + QPointF(a, b));
                m_points.push_back(m_centre + QPointF(a, -b));
                //m_points.push_back(mouseEvent->pos());

                CalcPerimetr();
                CalcSquare();
            }
            else{
                m_points.clear();
                m_centre = mouseEvent->pos();
            }
        }
    }
private:
    float m_a;
    float m_b;

    bool m_isInitCenter = false;
};

class Scuare : public IFigure{
    void MouseEvent(QMouseEvent *mouseEvent) override{
        SetPoint(mouseEvent);
    }
    void Draw(QPainter* painter) override{
        if(m_points.size() != 4) return;
        painter->drawLine(m_points[0], m_points[1]);
        painter->drawLine(m_points[1], m_points[2]);
        painter->drawLine(m_points[2], m_points[3]);
        painter->drawLine(m_points[0], m_points[3]);
    }
    void CalcPerimetr() override{
        m_perimetr = m_a * 2 + m_a * 2;
    }
    void CalcSquare() override{
        m_square = m_a * m_a;
    }
    void SetPoint(QMouseEvent* mouseEvent){
        if(!m_isInitCenter){
            m_centre = mouseEvent->pos();
            m_isInitCenter = true;
        }
        else{
            if(m_points.size() != 4){
                m_a = std::max(abs(mouseEvent->pos().x() - m_centre.x()), abs(mouseEvent->pos().y() - m_centre.y()));

                m_points.push_back(m_centre + QPointF(-m_a, -m_a));
                m_points.push_back(m_centre + QPointF(-m_a, m_a));
                m_points.push_back(m_centre + QPointF(m_a, m_a));
                m_points.push_back(m_centre + QPointF(m_a, -m_a));

                CalcPerimetr();
                CalcSquare();
            }
            else{
                m_points.clear();
                m_centre = mouseEvent->pos();
            }
        }
    }
private:
    float m_a;

    bool m_isInitCenter = false;
};


#endif // FIGURES_H
