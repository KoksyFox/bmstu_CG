#include <unistd.h>
#include <iostream>
#include <QPainter>
#include <QWidget>
#include <algorithm>
#include <ctime>
#include <stack>
#include "mycanvas.h"
#include <chrono>
#define X_min 0
#define X_max 710
#define Y_min 0
#define Y_max 731

using namespace chrono;


//void MyCanvas::activate_pixel(const QPoint& point, QPainter& painter)
//{
//    QColor cur_color = scene.main_scene.pixelColor(point);
//    if (cur_color == color.color_bg)
//    {
//        painter.setPen(color.color_main);
//        painter.drawPoint(point);
//    }
//    else if (cur_color == color.color_main)
//    {
//        painter.setPen(color.color_bg);
//        painter.drawPoint(point);
//    }

//}

