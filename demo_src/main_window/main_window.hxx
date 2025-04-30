#ifndef MAIN_WINDOW_HXX
#define MAIN_WINDOW_HXX

#include "QWidget"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGridLayout"
#include "QLabel"
#include "QLineEdit"
#include "QComboBox"
#include "QTextEdit"
#include "QCheckBox"
#include "QSpacerItem"
#include "QPushButton"
#include "QSizePolicy"
#include "null_log.hxx"

class MainWindow : public QWidget {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);

        ~MainWindow() = default;

    private:
    QLineEdit * tagEdit;
    QLineEdit * titleEdit;
    QLineEdit * subTitleEdit;
    QLineEdit * contentEdit;
    QComboBox * logLevelEdit;
    QTextEdit * logViewer;
    QCheckBox * useColor;
    QPushButton * generateLogBtn;
};


#endif //MAIN_WINDOW_HXX
