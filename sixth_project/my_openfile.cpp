#include "my_openfile.h"

My_openfile::My_openfile(QObject *parent)
    : QObject{parent}
{

}

void My_openfile::my_openfile()
{
    QString filepath = QFileDialog::getOpenFileName(,tr("打开文件"),"./",tr("image(*.png *.jpg)"));
}
