#include "matrixitem.h"
#include <QPainter>

MatrixItem::MatrixItem(QQuickItem *parent)
    : QQuickPaintedItem(parent),
      m_gridColumns(8),
      m_gridRows(6),
      m_squareSize(40),
      m_spacing(10)
{
}

void MatrixItem::setGridColumns(int columns) {
    if (m_gridColumns != columns) {
        m_gridColumns = columns;
        update(); // Обновляем отрисовку
        emit gridColumnsChanged();
    }
}

void MatrixItem::setGridRows(int rows) {
    if (m_gridRows != rows) {
        m_gridRows = rows;
        update();
        emit gridRowsChanged();
    }
}

void MatrixItem::setSquareSize(int size) {
    if (m_squareSize != size) {
        m_squareSize = size;
        update();
        emit squareSizeChanged();
    }
}

void MatrixItem::setSpacing(int spacing) {
    if (m_spacing != spacing) {
        m_spacing = spacing;
        update();
        emit spacingChanged();
    }
}

void MatrixItem::paint(QPainter *painter) {
    // Вычисляем общий размер матрицы
    int totalWidth = m_gridColumns * m_squareSize + (m_gridColumns - 1) * m_spacing;
    int totalHeight = m_gridRows * m_squareSize + (m_gridRows - 1) * m_spacing;

    // Вычисляем отступы для центрирования матрицы в элементе
    int startX = (width() - totalWidth) / 2;
    int startY = (height() - totalHeight) / 2;

    painter->setRenderHint(QPainter::Antialiasing, false);

    // Проходим по строкам и столбцам и рисуем квадраты
    for (int row = 0; row < m_gridRows; ++row) {
        for (int col = 0; col < m_gridColumns; ++col) {
            int index = row * m_gridColumns + col;
            // Нумеруем квадраты начиная с 1: четные (2,4,...) будем красить в серый,
            // нечетные — в чёрный.
            QColor color = ((index + 1) % 2 == 0) ? QColor("gray") : QColor("black");
            painter->setBrush(color);
            painter->setPen(Qt::NoPen);

            int x = startX + col * (m_squareSize + m_spacing);
            int y = startY + row * (m_squareSize + m_spacing);
            painter->drawRect(x, y, m_squareSize, m_squareSize);
        }
    }
}
