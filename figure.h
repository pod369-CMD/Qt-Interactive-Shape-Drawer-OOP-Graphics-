#ifndef FIGURE_H
#define FIGURE_H
#include <QBrush>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include  <QColor>
#include <QTextStream>
#include <QDataStream>
class Figure : public QObject, public QGraphicsItem//наследование базовых классов
//сигналы и слоты, объект - граф элемент который можно перемещать,...
{
    Q_OBJECT
    // Свойство стартовой точки, относительно которой отрисовываем фигуру
    Q_PROPERTY(QPointF startPoint
                   READ startPoint WRITE setStartPoint
                       NOTIFY pointChanged)
    // Свойство конечной точки, до куда отрисовываем фигуру
    Q_PROPERTY(QPointF endPoint
                   READ endPoint WRITE setEndPoint
                       NOTIFY pointChanged)
public:
    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();
    //virtual void print();
    QPointF startPoint() const; // Стартовая точка
    QPointF endPoint() const;   // Конечная точка
    void setStartPoint(const QPointF point);    // Установка стартовой точки
    void setEndPoint(const QPointF point);      // Установка конечной точки
    void changeBrush(const QColor& color);
    void setColor(QColor& color){
        m_color = color;
    }
    QColor getColor() {
        return m_color;
    }

signals:
    void pointChanged();    // Сигнал, который испускается, когда изменяется startPoint или endPoint. Это позволяет другим объектам (например, сцене) узнавать об изменении и перерисовывать фигуру.

private:
    QPointF m_startPoint;   // Стартовая точка
    QPointF m_endPoint;     // Конечная точка
    QColor m_color;
    QRectF boundingRect() const;    // виртуальная функция из QGraphicsItem.Область, в которой содержится фигура
public slots:
    void updateRomb();     // Слот обновления области, в которой содержится фигура
};

#endif // FIGURE_H
