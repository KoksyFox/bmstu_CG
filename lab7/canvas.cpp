#include <mycanvas.h>
#include <vector>

MyCanvas::MyCanvas(QWidget *parent) : QWidget (parent)
{
    int scene_height = 631;
    int scene_width = 711;
    scene.main_scene = QImage(scene_width, scene_height, QImage::Format_RGB32);
    scene.main_scene.fill(QColor(Qt::white));

    cutter.min_point = {-1, -1};
    cutter.max_point = {-1, -1};
}

void MyCanvas::update_scene()
{
    scene.main_scene.fill(QColor(Qt::white));
    QPoint unpoint = {-1, -1};
    if ((cutter.max_point != unpoint) && (cutter.min_point != unpoint))
        draw_cutter(color.color_cutter);

    draw_all_lines(color.color_line);
    repaint();
}

// For using repaint()
void MyCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this); // scene.main_scene
    painter.drawImage(0, 0, scene.main_scene);
}

void MyCanvas::clear_scene()
{
    clear_lines();
    clear_cutter();
    update_scene();
}

void MyCanvas::clear_lines()
{
    lines.clear();
    update_scene();
}

void MyCanvas::clear_cutter()
{
    cutter.min_point = {-1, -1};
    cutter.max_point = {-1, -1};
    update_scene();
}

void MyCanvas::add_line(const Line &line)
{
    lines.back() = line;
    update_scene();
}

void MyCanvas::add_new_line(const QPoint &point, const ModeAdd& mode)
{
    QPoint cur_point = point;
    QPoint unpoint = {-1, -1};
    auto& cur_line = lines.back();
    if (lines.empty())
        lines.push_back(Line(point, {-1, -1}));
    else if((cur_line.start != unpoint) && (cur_line.end != unpoint))
        lines.push_back(Line(point, {-1, -1}));
    else if (cur_line.end == unpoint)
    {
        if (mode == HORIZONTAL)
        {
            if (abs(point.x() - cur_line.start.x()) <
                    abs(point.y() - cur_line.start.y()))
                cur_point.setX(cur_line.start.x());
            else
                cur_point.setY(cur_line.start.y());
        }
        cur_line = {cur_line.start, cur_point};
        update_scene();
    }
}

void MyCanvas::update_rectangle_cutter(const QPoint &point)
{
    QPoint unpoint = {-1, -1};
    if ((cutter.max_point == unpoint) && (cutter.min_point != unpoint))
    {
        cutter.max_point = point;
        if (cutter.min_point.rx() > cutter.max_point.rx())
            swap(cutter.min_point.rx(), cutter.max_point.rx());
        if (cutter.min_point.ry() > cutter.max_point.ry())
            swap(cutter.min_point.ry(), cutter.max_point.ry());
        update_scene();
    }
    else
    {
        cutter.min_point = point;
        cutter.max_point = unpoint;
    }
}

bool MyCanvas::region_is_empty()
{
    return lines.empty();
}
