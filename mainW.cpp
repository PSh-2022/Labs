#include "mainW.h"

MainW::MainW(QWidget *parent): QWidget(parent), person_keeper_(PersonKeeper::instance()) // получаем ссылку на экземпляр класса PersonKeeper
{
    model_ = new QStringListModel(); // создаем модель списка строк

    // настройка интерфейса
    setWindowTitle("Lab 1"); //название окна

    view_ = new QListView(); // создаем вид списка
    view_->setModel(model_); // задаем вид списка, используя модель списка строк

    open_button_ = new QPushButton("Open"); // создаем кнопку открытия файла
    save_button_ = new QPushButton("Save As"); // создаем кнопку сохранения файла

    horizontal_layout_ = new QHBoxLayout(); // горизонтальная развертка
    horizontal_layout_->addWidget(open_button_); // добавляем кнопки. кнопки занимают одну строку, имеют равную ширину
    horizontal_layout_->addWidget(save_button_); // сохраняем кнопки

    vertical_layout_ = new QVBoxLayout(this); //вертикальная развертка
    vertical_layout_->addWidget(view_); // в верхней части развертки - список имен
    vertical_layout_->addLayout(horizontal_layout_); // в нижней части развертки - кнопки

    // привязываем обработчик события к событию "нажатие на кнопку"
    connect(open_button_, &QPushButton::clicked, this, &MainW::open_button_OnClick);
    connect(save_button_, &QPushButton::clicked, this, &MainW::save_button_OnClick);
}

MainW::~MainW()
{
    // удаляем динамически созданные элементы интерфейса
    delete save_button_;
    delete open_button_;
    delete view_;
    delete horizontal_layout_;
    delete vertical_layout_;

    delete model_;
}

void MainW::open_button_OnClick()
{
    QString path = QFileDialog::getOpenFileName(this, "Open", "../", "*.txt"); // открытие диалога открытия файла

    if (path != "")
    {
        try
        {
            person_keeper_.Clear(); // отчищаем стек с ФИО
            person_keeper_.readPersons(path); // считываем ФИО из файла в хранилище

            model_->setStringList(person_keeper_.toQStringList()); // выводим ФИО из хранилища в модель списка строк
        }
        //ловим ошибки
        catch (EStackException &e)
        {
            QMessageBox::about(this, "Error: open_button_OnClick: empty PersonKeeper", e.what());
        }
        catch (const char *str)
        {
            QMessageBox::about(this, "Error: open_button_OnClick: empty PersonKeeper", str);
        }
    }

    // если диалог закрыли, ничего не делаем
}

void MainW::save_button_OnClick()
{
    QString path = QFileDialog::getSaveFileName(this, "Save As", "../", "*.txt"); // открываем диалог сохранения файла

    if (path != "")
    {
        try
        {
            person_keeper_.writePersons(path); // записываем имена из храналища личностей в выбранный файл
        }
        //ловим ошибки
        catch (EStackException &e)
        {
            QMessageBox::about(this, "Error: open_button_OnClick: empty PersonKeeper", e.what());
        }
        catch (const char *str)
        {
            QMessageBox::about(this, "Error: open_button_OnClick: empty PersonKeeper", str);
        }
    }

    // если диалог закрыли, ничего не делаем
}
