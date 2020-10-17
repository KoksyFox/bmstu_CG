#include "mycanvas.h"

void MyCanvas::set_line_color(const QColor& new_color)
{
    color.color_line = new_color;
    update_scene();
}

void MyCanvas::set_cut_color(const QColor& new_color)
{
    color.color_cut = new_color;
    update_scene();
}

void MyCanvas::set_cutter_color(const QColor &new_color)
{
    color.color_cutter = new_color;
    update_scene();
}

QColor MyCanvas::get_line_color() const
{
    return color.color_line;
}

QColor MyCanvas::get_cut_color() const
{
    return color.color_cut;
}

QColor MyCanvas::get_cutter_color() const
{
    return color.color_cutter;
}
