#include <unistd.h>
#include <iostream>
#include <QPainter>
#include <QWidget>
#include <algorithm>
#include <ctime>
#include <stack>
#include "mycanvas.h"
#include <chrono>
#include <math.h>

#define EPS sqrt(2)
#define NUM_BITS 4
#define X_min 0
#define X_max 710
#define Y_min 0
#define Y_max 731

double MyCanvas::len_line(const QPointF P1, const QPointF P2)
{
    return sqrt((P1.x() - P2.x()) * (P1.x() - P2.x()) + (P1.y() - P2.y()) * (P1.y() - P2.y()));
}

void MyCanvas::calc_bits(int *arr, const QPointF point)
{
    double x = point.x();
    double y = point.y();

    arr[3] = (x < cutter.min_point.x()) ? 1 : 0;
    arr[2] = (x > cutter.max_point.x()) ? 1 : 0;
    arr[1] = (y < cutter.min_point.y()) ? 1 : 0;
    arr[0] = (y > cutter.max_point.y()) ? 1 : 0;
}

int MyCanvas::sum_bits(int *arr)
{
    int sum = 0;

    for (int i = 0; i < NUM_BITS; i++)
        sum += arr[i];

    return sum;
}

int MyCanvas::logic_mult(int *arr_fst, int *arr_sec)
{
    int mult = 0;
    for (int i = 0; i < NUM_BITS; i++)
        mult += arr_fst[i] * arr_sec[i];

    return mult;
}

void MyCanvas::cut_region(float eps)
{
    QPainter painter(&scene.main_scene);
    painter.setPen(color.color_cut);

    cut_region_middle_point(eps, painter);
}

void MyCanvas::cut_region_middle_point(float eps, QPainter &painter)
{
    QPointF P1, P2;
    QPointF R, tmp, P_middle;
    int T1[NUM_BITS], T2[NUM_BITS];
    int S1, S2;
    int i;

    // Просмотр всех отрезков
    for (int k = 0; k < lines.size(); k++)
    {
        // Концы отрезка
        P1 = lines[k].start;
        P2 = lines[k].end;

        // Шаг отсечения
        i = 1;

        while (true)
        {
            // Вычисление битовых кодов концевых точек
            calc_bits(T1, P1);
            calc_bits(T2, P2);

            // Вычисление сумм кодов
            S1 = sum_bits(T1);
            S2 = sum_bits(T2);

            // Проверка полной видимости отрезка
            if ((S1 == 0) && (S2 == 0))
            {
                // Закрашивание отрезка целиком
                painter.drawLine(P1.x(), P1.y(), P2.x(), P2.y());
                break;
            }

            // Проверка полной невидимости отрезка(отрезок лежит по одну из сторон окна )
            if (logic_mult(T1, T2))
                break;

            // i > 2 - конец поиска (уточнения)
            if (i > 2)
            {
                // Закрашивание отрезка целиком
                painter.drawLine(P1.x(), P1.y(), P2.x(), P2.y());
                break;
            }

            // Запоминается первая концевая точка
            R = P1;
            // P2 - наиболее удалённая от P1
            if (S2 == 0)
            {
                P1 = P2;
                P2 = R;
                i++;
            }
            else
            {
                // Пока расстояние отрезка больше EPS
                while (len_line(P1, P2) > eps)
                {
                    // Вычисление координат средней точки
                    P_middle.setX((P1.x() + P2.x()) / 2);
                    P_middle.setY((P1.y() + P2.y()) / 2);

                    // Запоминаем первую точку, рассматриваем отрезок [P1; P_middle]
                    tmp = P1;
                    P1 = P_middle;

                    calc_bits(T1, P1);

                    // Если отрезок [P_middle; P2] - невидимый
                    if (logic_mult(T1, T2))
                    {
                        P1 = tmp;
                        P2 = P_middle;
                    }
                }

                // Меняем точки местами, чтобы рассмотреть оба интервала
                P1 = P2;
                P2 = R;
                i++;
            }
        }
    }
    repaint();
}

