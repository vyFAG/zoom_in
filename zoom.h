#ifndef ZOOM_H
#define ZOOM_H

#include <QWidget>

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
    
private:
    Ui::Zoom *ui;
    
    int width_cells = 400;
    int height_cells = 400;
    int cell_side = 4;
    
    int window_width = 400;
    int window_height = 400;
    
    QVector<QVector<bool>> cells;
};
#endif // ZOOM_H
