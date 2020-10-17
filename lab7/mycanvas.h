#ifndef MYCANVAS_H
#define MYCANVAS_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;

enum ModeAdd
{
    SIMPLY,
    HORIZONTAL,
};

struct RectangleCutter
{
    QPoint min_point = {-1, -1};
    QPoint max_point = {-1, -1};
};

struct Line
{
    QPoint start = {-1, -1};
    QPoint end = {-1, -1};

    Line(const QPoint& new_start, const QPoint& new_end)
    {
        start = new_start;
        end = new_end;
    }
    Line(const QPoint& new_start)
    {
        start = new_start;
    }
};

struct CanvasColor
{
    QColor color_line = QColor(Qt::black);
    QColor color_cut = QColor(Qt::white);
    QColor color_cutter = QColor(Qt::black);
};

struct CanvasScene
{
    QImage main_scene;
};

class MyCanvas : public QWidget
{
    Q_OBJECT

private:
    CanvasColor color;
    vector<Line> lines;
    CanvasScene scene;
    RectangleCutter cutter;

private:
    void update_scene();

    int sign(const int num);
    void draw_line(const Line& edge, QPainter& painter, const QColor& color);
    void draw_all_lines(const QColor& color);
    void draw_point(const QPoint& point, QPainter& painter, const QColor& color);
    void draw_cutter(const QColor& color);

    void cut_lines_middle_point(QPainter& painter);
public:
    explicit MyCanvas(QWidget *parent = nullptr);

    void set_line_color(const QColor& new_color);
    void set_cut_color(const QColor& new_color);
    void set_cutter_color(const QColor& new_color);

    QColor get_line_color() const;
    QColor get_cut_color() const;
    QColor get_cutter_color() const;

    void add_line(const Line& line);
    void add_new_line(const QPoint& point, const ModeAdd& mode);
    void update_rectangle_cutter(const QPoint &point);

    void clear_scene();
    void clear_cutter();
    void clear_lines();

    void cut_region(float eps);
    void cut_region_middle_point(float eps, QPainter& painter);

    void calc_bits(int *arr, const QPointF point);
    int sum_bits(int *arr);
    int logic_mult(int *arr_fst, int *arr_sec);
    double len_line(const QPointF P1, const QPointF P2);

    bool region_is_empty();

protected:
    void paintEvent(QPaintEvent* event);
};

#endif // MYCANVAS_H
