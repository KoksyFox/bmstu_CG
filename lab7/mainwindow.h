#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPoint>
#include <mycanvas.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void change_button_color(QPushButton *butt, QColor color);
    void add_new_point(const QPoint& point, const ModeAdd& mode);
    void close_region();
    void change_horizontal_point(QPoint& point);
    void update_cutter(const QPoint& point);

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_add_point_clicked();
    void on_button_clear_1_clicked();
    void on_button_clear_2_clicked();
    void on_button_choose_line_color_clicked();
    void on_button_choose_cutter_color_clicked();
    void on_button_choose_cut_color_clicked();
    void on_button_cut_region_clicked();
    void on_button_clear_cutter_clicked();
    void on_button_clear_lines_clicked();

private:
    Ui::MainWindow *ui;
    MyCanvas *view_scene;
    bool mouse_is_active;

protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
