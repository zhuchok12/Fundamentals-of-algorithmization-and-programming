#include "graph.h"

Graph::Graph(int *a, long long size)
{
    set(a,size);
}

Graph::Graph()
{

}

void Graph::draw(QPainter *p)
{
    qDebug()<<"draw1";
    if(not_to_draw)return;
    qDebug()<<"draw2";
    long double pos=1;
    qDebug()<<array_size;
    for(int i=0;i<array_size;i++,pos+=1)
    {

        p->drawLine(pos,1,pos,scale*(array[i]-min_element));
    }
}

void Graph::set(int *a, long long size)
{
    array=a;
    array_size=size;
    not_to_draw=false;

    if(array_size>max_weight)
    {
        not_to_draw=true;
        qDebug()<<"Too many elements in array [ "<<array_size<<" > "<<max_weight;
        return;
    }

    max_element=a[0];
    min_element=a[0];
    for(int i=0;i<size;i++)
    {
        max_element=std::max(max_element,(long long)a[i]);
        min_element=std::min(max_element,(long long)a[i]);
    }

    scale=((long double)max_element-(long double)min_element)/(long double)max_height;
    qDebug()<<"MIN:"<<min_element<<" MAX:"<<max_element;
    qDebug()<<"SCALE: "<<std::to_string(scale);
}
