#ifndef MAINW_H
#define MAINW_H

#include <QStringListModel>
#include <QBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QFileDialog>
#include <QMessageBox>

#include "person_keeper.h"

// главное окно
class MainW : public QWidget
{
    Q_OBJECT

public:
    MainW(QWidget *parent = nullptr);
    ~MainW();

    // обработчики событий
    void open_button_OnClick();
    void save_button_OnClick();

private:
    // указатели на графические элементы
    QStringListModel *model_;
    QListView *view_;
    QPushButton *open_button_;
    QPushButton *save_button_;
    QHBoxLayout *horizontal_layout_;
    QVBoxLayout *vertical_layout_;

    // ссылка на хранитель личностей
    PersonKeeper &person_keeper_;
};
#endif // MAINW_H
