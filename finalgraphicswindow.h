// This file was supplied by Prof. Marshall Long for ENAS 130.

#ifndef FINALGRAPHICSWINDOW_H
#define FINALGRAPHICSWINDOW_H

#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>

namespace Ui
{
    class GraphicsWindow;
}

class GraphicsWindow : public QDialog
{
public:
    explicit GraphicsWindow(QWidget *parent = 0);
    ~GraphicsWindow();
    void setupPixmap(int width, int height);

protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Q_OBJECT
    Ui::GraphicsWindow *ui;
    QPixmap pixmap;
};

#endif // FINALGRAPHICSWINDOW_H
