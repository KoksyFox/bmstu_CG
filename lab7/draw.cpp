#include "mycanvas.h"

int MyCanvas::sign(const int num)
{
    return (num > 0) ? 1 : ((num < 0) ? -1 : 0);
}

void MyCanvas::draw_line(const Line &edge, QPainter &painter, const QColor &color)
{
    painter.setPen(color);
//    draw_line_brez(edge.start, edge.end, painter);
    painter.drawLine(edge.start, edge.end);
}

void MyCanvas::draw_all_lines(const QColor &color)
{
    QPainter painter(&scene.main_scene);
    for(auto& line : lines)
        draw_line(line, painter, color);
}

void MyCanvas::draw_point(const QPoint &point, QPainter& painter, const QColor& color)
{
    painter.setPen(color);
    painter.drawPoint(point);
}

void MyCanvas::draw_cutter(const QColor &color)
{
    QPainter painter(&scene.main_scene);
    draw_line({cutter.min_point, {cutter.max_point.rx(), cutter.min_point.ry()}}, painter, color);
    draw_line({{cutter.max_point.rx(), cutter.min_point.ry()}, cutter.max_point}, painter, color);
    draw_line({cutter.max_point, {cutter.min_point.rx(), cutter.max_point.ry()}}, painter, color);
    draw_line({{cutter.min_point.rx(), cutter.max_point.ry()}, cutter.min_point}, painter, color);
}
