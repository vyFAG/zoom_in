#include "zoom.h"
#include "ui_zoom.h"
#include <QPainter>
#include <QWheelEvent>
#include <QDebug>
#include <random>

Zoom::Zoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Zoom)
{
    ui->setupUi(this);
    
    this->setFixedSize(window_width, window_height);
    
    rand_engine = std::mt19937(randoming());
    
    std::uniform_int_distribution<> binary(0, 1);
    
    cells.resize(width_cells);
    for (int w = 0; w < width_cells; w++) {
        for (int h = 0; h < height_cells; h++) {
            cells[w].resize(height_cells);
            cells[w][h] = binary(rand_engine);
        }
    }
}

Zoom::~Zoom()
{
    delete ui;
}

void Zoom::mousePressEvent (QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        cursor_pos_x = QCursor::pos().x() - this->geometry().x();
        cursor_pos_y = QCursor::pos().y() - this->geometry().y();
        
        cell_side *= 2;
        absolute_size *= 2;
    }
    
    if(event->button() == Qt::RightButton && cell_side > 4) {
        cursor_pos_x = QCursor::pos().x() - this->geometry().x();
        cursor_pos_y = QCursor::pos().y() - this->geometry().y();
        
        cell_side /= 2;
        absolute_size /= 2;
    }
    
    repaint();
    
    /*std::uniform_int_distribution<> test(0, 24);
    if(event->button() == Qt::LeftButton) {
        cursor_pos_x = QCursor::pos().x() - this->geometry().x();
        cursor_pos_y = QCursor::pos().y() - this->geometry().y();
        
        int begin_cell_x = ceil(cursor_pos_x / cell_side);
        int begin_cell_y = ceil(cursor_pos_y / cell_side);
        
        
        if (begin_cell_x < width_cells / 4) {
            begin_pos_x = 0;
            final_pos_x = width_cells / 2;
        }
        
        if (begin_cell_x > width_cells / 4 * 3) { // add
            begin_pos_x = 0;
        }
        
        if (begin_cell_y > height_cells / 4) {
            begin_pos_x = 0;
        }
        
        cell_side *= 2;
        qDebug() << cursor_pos_x << " " << cursor_pos_y;
    }*/
}

void Zoom::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    
    QPainter paint_object(this);
    
    std::uniform_int_distribution<> binary(0, 1);
    
    paint_object.setBrush(QBrush(Qt::black));
    paint_object.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    
    for (int w = 0; w < width_cells; w++) {
        for (int h = 0; h < height_cells; h++) {
            //QColor cell_color(color(rand_engine), color(rand_engine), color(rand_engine));
            
            if (cells[w][h] == 1) {
                paint_object.drawRect(this->width() / absolute_size - cursor_pos_x + w * cell_side,
                                      this->height() / absolute_size - cursor_pos_y + h * cell_side, cell_side, cell_side);
            }
        }
    }
}
