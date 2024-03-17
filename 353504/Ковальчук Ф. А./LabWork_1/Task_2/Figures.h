#ifndef FIGURES_H
#define FIGURES_H
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <math.h>

class IFigure{
    friend class MainWindow;
public:
    virtual void Clear() = 0;
    virtual void UpdateMassCentre() = 0;
    virtual void CalcPerimetr() = 0;
    virtual void CalcSquare() = 0;
    virtual void Draw(QPainter* painter) = 0;
    virtual void MouseEvent(QMouseEvent *mouseEvent) = 0;
    virtual void Translate(float deltaX, float deltaY) = 0;
    virtual void Rotate(float delta) = 0;
    virtual void Scale(bool isNegative) = 0;
protected:
    QPointF m_centre;

    float m_perimetr;
    float m_square;

    float m_scale = 1.0f;
};

class Triangle : public IFigure{
public:
    void Clear() override{
        m_points.clear();
        m_centre = QPoint(0.0f, 0.0f);
        m_perimetr = 0.0f;
        m_square = 0.0f;
        m_scale = 1.0f;
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
    void CalcPerimetr() override{
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
    void CalcSquare() override{
        m_square = 0.0f;

        if(m_points.size() >= 3){
            for(int i = 0; i < m_points.size() - 1; i++){
                m_square += m_points[i].x() * m_points[i + 1].y() - m_points[i].y() * m_points[i+1].x();
            }

            m_square += m_points[0].x() * m_points[m_points.size() - 1].y() - m_points[0].y() * m_points[m_points.size() - 1].x();
            m_square /= 2;
        }
    }
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

    void UpdateMassCentre() override{
        m_centre = QPoint(0.0f, 0.0f);
        for(int i = 0; i < m_points.size(); i++){
            m_centre += m_points[i];
        }
        m_centre /= m_points.size();
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
        CalcPerimetr();
        CalcSquare();
    }
    void MouseEvent(QMouseEvent *mouseEvent) override{
        SetPoint(mouseEvent);
        UpdateMassCentre();

        CalcPerimetr();
        CalcSquare();
    }
    void Rotate(float delta){
        float sinA = std::sin(delta * 3.1415f / 180.0f);
        float cosA = std::cos(delta * 3.1415f / 180.0f);

        for(int i = 0; i < m_points.size(); i++){
            float localX = m_points[i].x() - m_centre.x();
            float localY = m_points[i].y() - m_centre.y();

            m_points[i] = QPointF(m_centre.x() + cosA * localX - sinA * localY,
                                  m_centre.y() +  sinA * localX + cosA * localY);
        }
    }
    void Translate(float deltaX, float deltaY){
        for(int i = 0; i < m_points.size(); i++){
            m_points[i] -= QPointF(deltaX, deltaY);
        }
        m_centre -= QPointF(deltaX, deltaY);
    }

private:
    QVector<QPointF> m_points;
};



#endif // FIGURES_H
