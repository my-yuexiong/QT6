#ifndef MY_OPENFILE_H
#define MY_OPENFILE_H

#include <QObject>
#include <QDialog>
#include <QFileDialog>

class My_openfile : public QObject
{
    Q_OBJECT
public:
    explicit My_openfile(QObject *parent = nullptr);

    void my_openfile();

signals:

};

#endif // MY_OPENFILE_H
