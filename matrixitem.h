#ifndef MATRIXITEM_H
#define MATRIXITEM_H

#include <QQuickPaintedItem>
#include <QColor>

class MatrixItem : public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(int gridColumns READ gridColumns WRITE setGridColumns NOTIFY gridColumnsChanged)
    Q_PROPERTY(int gridRows READ gridRows WRITE setGridRows NOTIFY gridRowsChanged)
    Q_PROPERTY(int squareSize READ squareSize WRITE setSquareSize NOTIFY squareSizeChanged)
    Q_PROPERTY(int spacing READ spacing WRITE setSpacing NOTIFY spacingChanged)
public:
    explicit MatrixItem(QQuickItem *parent = nullptr);

    int gridColumns() const { return m_gridColumns; }
    void setGridColumns(int columns);

    int gridRows() const { return m_gridRows; }
    void setGridRows(int rows);

    int squareSize() const { return m_squareSize; }
    void setSquareSize(int size);

    int spacing() const { return m_spacing; }
    void setSpacing(int spacing);

    // Отрисовка матрицы происходит здесь
    void paint(QPainter *painter) override;

signals:
    void gridColumnsChanged();
    void gridRowsChanged();
    void squareSizeChanged();
    void spacingChanged();

private:
    int m_gridColumns;
    int m_gridRows;
    int m_squareSize;
    int m_spacing;
};

#endif // MATRIXITEM_H
