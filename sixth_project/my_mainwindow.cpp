#include "my_mainwindow.h"


My_MainWindow::My_MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //设置窗口大小和名称
    this->setFixedSize(500,500);
    this->setWindowTitle("路飞编辑器");

    //允许窗口绘制
    this->setAutoFillBackground(true);

    //创建一个图片控件，并直接设置图片的大小,以下两种方式都可以
    //以下两种方式都可以，但使用第一种可以使图片大小刚好和窗口大小一样、
    //使用第二种可能会使图片大小不变，使整个窗口中不止一张图片
    QPixmap pix1 = QPixmap(":/image/lufy").scaled(this->size());
    //pix1.load(":/image/lufy");

    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pix1));
    this->setPalette(palette);


    //创建一个菜单栏，名字叫menubar，这里有两种创建菜单栏的方式，推荐使用第二种
    //QMenuBar *menubar = new QMenuBar(this);
    QMenuBar *menubar = menuBar();

    //将创建的菜单栏添加到窗口中来
    this->setMenuBar(menubar);

    //创建三个菜单
    QMenu *menu1 = new QMenu("文件");
    QMenu *menu2 = new QMenu("编辑");
    QMenu *menu3 = new QMenu("帮助");

    //将创建的三个菜单添加到菜单栏中来
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);

    //创建四个菜单项
    QAction *action1 = new QAction("打开文件");
    QAction *action2 = new QAction("另存为");
    QAction *action3 = new QAction("关闭文件");
    QAction *action4_1 = new QAction("关闭");

    //将创建的菜单项添加到菜单1中来
    menu1->addAction(action1);
    menu1->addAction(action2);
    menu1->addAction(action3);
    menu1->addAction(action4_1);

    //又创建了三个菜单项
    QAction *action4 = new QAction("复制");
    QAction *action5 = new QAction("粘贴");
    QAction *action6 = new QAction("剪切");

    //将创建的三个菜单项添加到菜单2中来
    menu2->addAction(action4);
    menu2->addAction(action5);
    menu2->addAction(action6);

    //又创建了三个菜单项
    QAction *action7 = new QAction("电话咨询");
    QAction *action8 = new QAction("帮助文档");
    QAction *action9 = new QAction("微信咨询");

    //将创建的三个菜单项添加到菜单3中来
    menu3->addAction(action7);
    menu3->addAction(action8);
    menu3->addAction(action9);

    //构造信号与槽，信号是菜单1中点击关闭，槽是关闭窗口
    connect(action4_1,&QAction::triggered,this,&QMainWindow::close);

    //创建一个工具栏
    QToolBar *toolbar = new QToolBar(this);

    //将工具栏添加到窗口中来
    this->addToolBar(toolbar);

    //创建三个工具
    QAction *action10 = new QAction("锤子");
    QAction *action11 = new QAction("剪刀");
    QAction *action12 = new QAction("钳子");

    //将创建的三个工具添加到工具栏中来
    toolbar->addAction(action10);
    toolbar->addAction(action11);
    toolbar->addAction(action12);

    //设置工具栏位置
    toolbar->setAllowedAreas(Qt::LeftToolBarArea);

    //设置工具栏是否能移动
    //toolbar->setMovable(false);

    //创建一个状态栏，这里有两种方式，还是推荐使用第二种
    //QStatusBar *status = new QStatusBar(this);
    QStatusBar *status = statusBar();

    //将创建好的状态栏添加到窗口中来
    this->setStatusBar(status);

    //创建两个标签
    QLabel *label1 = new QLabel("重庆大学明月科创班",this);
    QLabel *label2 = new QLabel("作者：越雄",this);

    //显示临时信息，第二个参数是显示时间，单位是毫秒
    //status->showMessage("作者：越雄",4000);

    //显示正式信息
    status->addWidget(label1);
    //显示永久信息
    status->addPermanentWidget(label2);


    //创建一个铆接部件
    QDockWidget *dockwidget = new QDockWidget("小窗口",this);

    //将核心部件文本编辑器设置成透明的，是背景图片显示出来
    this->addDockWidget(Qt::TopDockWidgetArea,dockwidget);

    //创建一个核心部件，这里以一个文本编辑器为例
    QTextEdit *textedit = new QTextEdit(this);

    //将创建的核心部件（文本编辑器）添加到窗口中来
    this->setCentralWidget(textedit);

    textedit->setStyleSheet("background: transparent;");

    //给菜单项增加图片信息
    //创建一个图片控件
    QPixmap pix;

    //选择图片
    pix.load(":/image/file_flag");

    //给菜单项设置图片,也可以给菜单设置图片，下面是菜单1设置的图片
    action1->setIcon(QIcon(pix));

    //定义一个模态对话框，模态对话框会阻塞主窗口的运行，即模态对话框未关闭，主对话框不会运行
    //创建一个对话框对象，因为这个模态对话框会阻塞程序运行，所以将这个对话框对象创建在栈上就可以了
    //QDialog dialog;

    //设置对话框名称
    //dialog.setWindowTitle("小对话框");

    //运行对话框
    //dialog.exec();

    //定义一个非模态对话框，非模态对话框不会阻塞程序运行
    //创建一个对话框对象，因为非模态对话框不会阻塞程序运行，所以要创建在堆上
    //QDialog *dialog = new QDialog;

    //设置对话框名称
    //dialog->setWindowTitle("小对话框");

    //设置对话框自动释放内存
    //dialog->setAttribute(Qt::WA_DeleteOnClose);

    //设置对话框的大小
    //dialog->resize(250,250);

    //运行对话框
    //dialog->show();

    connect(action1,&QAction::triggered,this,&My_MainWindow::my_openfile);


}

void My_MainWindow::my_openfile()
{
    QString filepath = QFileDialog::getOpenFileName(this,tr("打开文件"),"./",tr("Text(*.txt)"));
    if(!filepath.isEmpty())
    {
        textedit->append(filepath);
    }
}

My_MainWindow::~My_MainWindow()
{

}
