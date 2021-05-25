#include "widget.h"
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
   : QWidget(parent)
{
   this->setAutoFillBackground(true);
   resize(600,400);

}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event)
{

   QPoint points[4] = {QPoint(10, 80), QPoint(20,10),
                       QPoint(80,30), QPoint(90,70)};
   QPoint targetPoint = QPoint(10, 40);
   int nCross = 0;

   QPainter *pPainter = new QPainter(this);
   pPainter->drawPolygon(points, 4, Qt::OddEvenFill);
   pPainter->drawLine(targetPoint.x(), targetPoint.y(),
                      targetPoint.x()+ 100,targetPoint.y());
   for (int i = 0; i < 4; i++) {
      QPoint p1 = points[i];
      QPoint p2 = points[(i+1)%4];
      if( p1.y() == p2.y() )
         continue;
      if( targetPoint.y() < qMin(p1.y(), p2.y()) )
         continue;
      if( targetPoint.y() >= qMax(p1.y(), p2.y()) )
         continue;
      double x = (double)(targetPoint.y() - p1.y()) * (double)(p2.x() - p1.x()) /
                 (double)(p2.y() - p1.y() ) + p1.x();
      if ( x > targetPoint.x() )
         nCross++;
   }
   if ( nCross % 2 == 1)
      qDebug() << "point in polygon!";
   else
      qDebug() << "point not in polygon!";
   delete pPainter;
}

