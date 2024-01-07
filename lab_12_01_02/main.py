import sys

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QMainWindow, QWidget, QVBoxLayout, QLabel, QApplication, \
    QPushButton, QMessageBox, QLineEdit, QSpinBox, QCheckBox

from src.lib_array import filter_array, shift_array


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Обработка массива")
        self.setMinimumWidth(400)
        self.move(600, 250)

        self.central_widget = QWidget()

        self.layout = QVBoxLayout(self.central_widget)
        self.layout.setContentsMargins(30, 30, 30, 30)
        self.layout.setSpacing(20)
        self.layout.setAlignment(Qt.AlignTop)

        # Input array
        array_widget = QWidget()
        array_layout = QVBoxLayout(array_widget)
        array_layout.setContentsMargins(0, 0, 0, 0)
        self.array_line_edit = QLineEdit()
        self.array_line_edit.setText('3 7 5 9 3 16 45 46 25')
        array_label = QLabel('### Массив')
        array_label.setTextFormat(Qt.TextFormat.MarkdownText)
        array_layout.addWidget(array_label)
        array_layout.addWidget(self.array_line_edit)
        self.layout.addWidget(array_widget)

        # Shift
        shift_widget = QWidget()
        shift_layout = QVBoxLayout(shift_widget)
        shift_layout.setContentsMargins(0, 0, 0, 0)
        shift_button = QPushButton('Сдвинуть')
        shift_button.clicked.connect(self.shift_clicked)
        self.shift_spin_box = QSpinBox()
        self.shift_spin_box.setValue(3)
        shift_label = QLabel('### Сдвиг')
        shift_label.setTextFormat(Qt.TextFormat.MarkdownText)
        shift_layout.addWidget(shift_label)
        shift_layout.addWidget(QLabel('Количество'))
        shift_layout.addWidget(self.shift_spin_box)
        shift_layout.addWidget(shift_button)
        self.layout.addWidget(shift_widget)

        # Filter
        filter_widget = QWidget()
        filter_layout = QVBoxLayout(filter_widget)
        filter_layout.setContentsMargins(0, 0, 0, 0)
        filter_button = QPushButton('Отфильтровать')
        filter_button.clicked.connect(self.filter_clicked)
        self.filter_check_box = QCheckBox('Выделить память с запасом')
        self.filter_check_box.setChecked(True)
        filter_label = QLabel('### Фильтрование')
        filter_label.setTextFormat(Qt.TextFormat.MarkdownText)
        filter_layout.addWidget(filter_label)
        filter_layout.addWidget(self.filter_check_box)
        filter_layout.addWidget(filter_button)
        self.layout.addWidget(filter_widget)

        self.setCentralWidget(self.central_widget)

    def filter_clicked(self):
        try:
            arr = list(map(int, self.array_line_edit.text().strip().split()))
            arr = filter_array(arr, reserve_memory=self.filter_check_box.isChecked())
            self.array_line_edit.setText(' '.join(map(str, arr)))
        except:
            self.show_error('Некорректный массив')

    def shift_clicked(self):
        try:
            arr = list(map(int, self.array_line_edit.text().strip().split()))
            arr = shift_array(arr, self.shift_spin_box.value())
            self.array_line_edit.setText(' '.join(map(str, arr)))
        except:
            self.show_error('Некорректный массив')

    def show_error(self, text):
        QMessageBox.warning(self, 'Внимание!', text, QMessageBox.Ok)


app = QApplication(sys.argv)

window = MainWindow()
window.show()

app.exec()
