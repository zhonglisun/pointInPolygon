#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

class Widget : public QWidget
{
   Q_OBJECT

public:
   Widget(QWidget *parent = nullptr);
   ~Widget();

public:
   void paintEvent(QPaintEvent *event) override;
};
#endif // WIDGET_H
