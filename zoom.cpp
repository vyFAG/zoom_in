#include "zoom.h"
#include "ui_zoom.h"
#include <QPainter>
#include <random>

Zoom::Zoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Zoom)
{
    ui->setupUi(this);
    
    std::random_device randoming;
    std::mt19937 rand_engine(randoming());
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

void Zoom::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    
    QPainter paint_object(this);
    
    std::random_device randoming;
    std::mt19937 rand_engine(randoming());
    std::uniform_int_distribution<> binary(0, 1);
    std::uniform_int_distribution<> color(0, 255);
    
    for (int w = 0; w < this->width() / cell_side; w++) {
        for (int h = 0; h < this->height() / cell_side; h++) {
            //QColor cell_color(color(rand_engine), color(rand_engine), color(rand_engine));
            
            paint_object.setBrush(QBrush(Qt::black));
            paint_object.setPen(QPen(Qt::black, 1, Qt::SolidLine));
            
            if (cells[w][h] == 1) {
                paint_object.drawRect(w * cell_side, h * cell_side, cell_side, cell_side);
            }
        }
    }
}
