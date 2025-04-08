import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import CustomComponents 1.0

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: "Матрица из квадратиков"

    ColumnLayout {
        anchors.fill: parent
        spacing: 10
        anchors.margins: 10

        // Панель для задания параметров матрицы
        RowLayout {
            spacing: 10

            Label { text: "n (колонки):" }
            TextField {
                id: columnInput
                text: "8"
                width: 60
                inputMethodHints: Qt.ImhDigitsOnly
            }

            Label { text: "m (строки):" }
            TextField {
                id: rowInput
                text: "6"
                width: 60
                inputMethodHints: Qt.ImhDigitsOnly
            }

            Button {
                text: "Обновить матрицу"
                onClicked: {
                    mItem.gridColumns = parseInt(columnInput.text)
                    mItem.gridRows = parseInt(rowInput.text)
                }
            }
        }

        // Наш кастомный элемент, который отрисовывает матрицу в C++
        MatrixItem {
            id: mItem
            Layout.fillWidth: true
            Layout.fillHeight: true
            // Элемент сам центрирует матрицу внутри себя через расчёт в paint()
        }
    }
}
