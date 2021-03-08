#ifndef ZOOM_H
#define ZOOM_H

#include <QWidget>
#include <QGraphicsSceneWheelEvent>
#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class Zoom; }
QT_END_NAMESPACE

class Zoom : public QWidget
{
    Q_OBJECT
    
public:
    Zoom(QWidget *parent = nullptr);
    ~Zoom();
    
protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent (QMouseEvent *event);
    
private:
    Ui::Zoom *ui;
    
    int window_width = 400;
    int window_height = 400;
    int cell_side = 4;
    
    int width_cells = window_width / cell_side;
    int height_cells = window_height / cell_side;
    
    int absolute_size = 1;
    
    int cursor_pos_x = 0;
    int cursor_pos_y = 0;
    
    int last_cursor_pos_x = 0;
    int last_cursor_pos_y = 0;
    
    QVector<QVector<bool>> cells;
    
    std::random_device randoming;
    std::mt19937 rand_engine;
};
#endif // ZOOM_H
