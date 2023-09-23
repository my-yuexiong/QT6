#ifndef MY_MAINWINDOW_H
#define MY_MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
#include <QDialog>
#include <QFileDialog>

class My_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    My_MainWindow(QWidget *parent = nullptr);
    QTextEdit *textedit;
    void my_openfile();

    ~My_MainWindow();
};
#endif // MY_MAINWINDOW_H
