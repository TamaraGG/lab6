#include "collection.h"
#include <QHBoxLayout>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *window = new QWidget();

    Collection col;
    QLabel *label = new QLabel("0");
    QSlider *slider = new QSlider;
    QSpinBox *spinbox = new QSpinBox;
    QScrollBar *scrollbar = new QScrollBar;

    col.AddWidget(label);
    col.AddWidget(slider);
    col.AddWidget(spinbox);
    col.AddWidget(scrollbar);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);
    layout->addWidget(slider);
    layout->addWidget(spinbox);
    layout->addWidget(scrollbar);

    // изменение цвета окна
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(198, 236, 217, 127));
    window->setAutoFillBackground(true);
    window->setPalette(pal);
    
    // задание шрифта
    QFont font("Times", 20, QFont::Bold);
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);

    window->setLayout(layout);
    window->show();

    return a.exec();
}
