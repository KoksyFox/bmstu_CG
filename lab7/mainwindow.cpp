#include <QColorDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <cstdio>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view_scene = new MyCanvas(ui->widget);
    view_scene->setMinimumSize(711, 631);

    change_button_color(ui->button_choose_line_color, QColor(Qt::black));
    change_button_color(ui->button_choose_cut_color, QColor(Qt::red));
    change_button_color(ui->button_choose_cutter_color, QColor(Qt::green));

    view_scene->set_line_color(QColor(Qt::black));
    view_scene->set_cut_color(QColor(Qt::red));
    view_scene->set_cutter_color(QColor(Qt::green));

    mouse_is_active = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_button_color(QPushButton *butt, QColor color)
{
    QPalette buf = butt->palette();
    buf.setColor(QPalette::Button, color);
    butt->setPalette(buf);
}

void MainWindow::add_new_point(const QPoint& point, const ModeAdd& mode)
{
    view_scene->add_new_line(point, mode);
    view_scene->repaint();
}

void MainWindow::update_cutter(const QPoint& point)
{
    view_scene->update_rectangle_cutter(point);
    view_scene->repaint();
}

void MainWindow::on_button_choose_line_color_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет");
    if (color.isValid())
    {
        change_button_color(ui->button_choose_line_color, color);
        view_scene->set_line_color(color);
    }
}

void MainWindow::on_button_choose_cutter_color_clicked()
{
    QColor color = QColorDialog::getColor(Qt::green, this, "Выберите цвет");
    if (color.isValid())
    {
        change_button_color(ui->button_choose_cutter_color, color);
        view_scene->set_cutter_color(color);
    }
}

void MainWindow::on_button_choose_cut_color_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет");
    if (color.isValid())
    {
        change_button_color(ui->button_choose_cut_color, color);
        view_scene->set_cut_color(color);
    }
}

void MainWindow::on_button_cut_region_clicked()
{
    float eps = ui->eps->text().toFloat();

    view_scene->cut_region(eps);
}

void MainWindow::on_button_clear_1_clicked()
{
    view_scene->clear_scene();
}

void MainWindow::on_button_clear_2_clicked()
{
    view_scene->clear_scene();
}

void MainWindow::on_button_clear_cutter_clicked()
{
    view_scene->clear_cutter();
}

void MainWindow::on_button_clear_lines_clicked()
{
    view_scene->clear_lines();
}

void MainWindow::on_button_add_point_clicked()
{
    bool err1 = true, err2 = true;

    int x = ui->num_x->text().toInt(&err1);
    int y = ui->num_y->text().toInt(&err2);

    if (err1 && err2)
    {
        if (ui->rad_type_line->isChecked())
            add_new_point({x, y}, SIMPLY);
        else if (ui->rad_type_cutter->isChecked())
            update_cutter({x, y});
    }
    else
        QMessageBox::warning(this, "Ошибка ввода",
                             "Координаты точки задаются целыми числами!");
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Shift)
        mouse_is_active = true;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Shift)
        mouse_is_active = false;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint point = view_scene->mapFromGlobal(QCursor::pos());
    if (point.x() < 711 && point.x() > 0 && point.y() > 0 && point.y() < 631)
    {
        if (event->button() == Qt::LeftButton)
        {
            if (ui->rad_type_line->isChecked())
            {
                if (mouse_is_active)
                    add_new_point(point, HORIZONTAL);
                else
                    add_new_point(point, SIMPLY);
            }
            else if (ui->rad_type_cutter->isChecked())
                update_cutter(point);

        }
    }
}
