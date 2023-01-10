/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_login;
    QRadioButton *radioButton_user;
    QRadioButton *radioButton_admin;
    QRadioButton *radioButton_performer;
    QLineEdit *lineEdit_login;
    QLabel *label_login;
    QLineEdit *lineEdit_password;
    QLabel *label_password;
    QPushButton *pushButton_enter;
    QPushButton *pushButton_toReg;
    QFrame *frame_reg;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_reg;
    QLineEdit *lineEdit_regLogin;
    QLineEdit *lineEdit_regPassword;
    QLineEdit *lineEdit_regNameGroup;
    QComboBox *comboBox_genre;
    QLineEdit *lineEdit_participants;
    QPushButton *pushButton_reg;
    QPushButton *pushButton_back;
    QWidget *tab_search;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_top;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget_top;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_search;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QTableWidget *tableWidget_results;
    QWidget *tab_music;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QTableWidget *tableWidget_myMusic;
    QWidget *tab_playlists;
    QFrame *frame;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_createName_3;
    QLineEdit *lineEdit_changePlaylist;
    QPushButton *pushButton_changePlaylist;
    QPushButton *pushButton_closeFrame;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_10;
    QLabel *label;
    QTableWidget *tableWidget_playlists;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_playlistInfo;
    QTableWidget *tableWidget_TracksFromPlaylist;
    QFrame *frame_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_createName_2;
    QLineEdit *lineEdit_newPlaylist_2;
    QPushButton *pushButton_createPlaylist_2;
    QWidget *tab;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_addAlbum;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QComboBox *comboBox_genres;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *spinBox_count;
    QTableWidget *tableWidget;
    QPushButton *pushButton_sendToCheck;
    QComboBox *comboBox_albums;
    QPushButton *pushButton;
    QTableWidget *tableWidget_album;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_check;
    QPushButton *pushButton_open;
    QTableWidget *tableWidget_check;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_agree;
    QPushButton *pushButton_reject;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1578, 620);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1581, 561));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tab_login = new QWidget();
        tab_login->setObjectName(QString::fromUtf8("tab_login"));
        radioButton_user = new QRadioButton(tab_login);
        radioButton_user->setObjectName(QString::fromUtf8("radioButton_user"));
        radioButton_user->setGeometry(QRect(620, 180, 121, 20));
        radioButton_admin = new QRadioButton(tab_login);
        radioButton_admin->setObjectName(QString::fromUtf8("radioButton_admin"));
        radioButton_admin->setGeometry(QRect(890, 180, 121, 20));
        radioButton_performer = new QRadioButton(tab_login);
        radioButton_performer->setObjectName(QString::fromUtf8("radioButton_performer"));
        radioButton_performer->setGeometry(QRect(760, 180, 111, 20));
        lineEdit_login = new QLineEdit(tab_login);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(710, 220, 241, 22));
        label_login = new QLabel(tab_login);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(650, 220, 51, 16));
        lineEdit_password = new QLineEdit(tab_login);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(710, 250, 241, 22));
        label_password = new QLabel(tab_login);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(650, 250, 51, 16));
        pushButton_enter = new QPushButton(tab_login);
        pushButton_enter->setObjectName(QString::fromUtf8("pushButton_enter"));
        pushButton_enter->setGeometry(QRect(740, 280, 131, 31));
        pushButton_toReg = new QPushButton(tab_login);
        pushButton_toReg->setObjectName(QString::fromUtf8("pushButton_toReg"));
        pushButton_toReg->setGeometry(QRect(740, 320, 131, 31));
        frame_reg = new QFrame(tab_login);
        frame_reg->setObjectName(QString::fromUtf8("frame_reg"));
        frame_reg->setGeometry(QRect(530, 130, 561, 261));
        frame_reg->setAutoFillBackground(true);
        frame_reg->setFrameShape(QFrame::StyledPanel);
        frame_reg->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget = new QWidget(frame_reg);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 20, 481, 239));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_reg = new QLabel(verticalLayoutWidget);
        label_reg->setObjectName(QString::fromUtf8("label_reg"));
        QFont font1;
        font1.setPointSize(11);
        label_reg->setFont(font1);
        label_reg->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_reg);

        lineEdit_regLogin = new QLineEdit(verticalLayoutWidget);
        lineEdit_regLogin->setObjectName(QString::fromUtf8("lineEdit_regLogin"));

        verticalLayout->addWidget(lineEdit_regLogin);

        lineEdit_regPassword = new QLineEdit(verticalLayoutWidget);
        lineEdit_regPassword->setObjectName(QString::fromUtf8("lineEdit_regPassword"));

        verticalLayout->addWidget(lineEdit_regPassword);

        lineEdit_regNameGroup = new QLineEdit(verticalLayoutWidget);
        lineEdit_regNameGroup->setObjectName(QString::fromUtf8("lineEdit_regNameGroup"));

        verticalLayout->addWidget(lineEdit_regNameGroup);

        comboBox_genre = new QComboBox(verticalLayoutWidget);
        comboBox_genre->addItem(QString());
        comboBox_genre->setObjectName(QString::fromUtf8("comboBox_genre"));
        comboBox_genre->setEnabled(true);
        comboBox_genre->setEditable(true);

        verticalLayout->addWidget(comboBox_genre);

        lineEdit_participants = new QLineEdit(verticalLayoutWidget);
        lineEdit_participants->setObjectName(QString::fromUtf8("lineEdit_participants"));

        verticalLayout->addWidget(lineEdit_participants);

        pushButton_reg = new QPushButton(verticalLayoutWidget);
        pushButton_reg->setObjectName(QString::fromUtf8("pushButton_reg"));
        pushButton_reg->setAutoFillBackground(true);

        verticalLayout->addWidget(pushButton_reg);

        pushButton_back = new QPushButton(verticalLayoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));

        verticalLayout->addWidget(pushButton_back);

        tabWidget->addTab(tab_login, QString());
        tab_search = new QWidget();
        tab_search->setObjectName(QString::fromUtf8("tab_search"));
        horizontalLayoutWidget_2 = new QWidget(tab_search);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(50, 20, 1301, 501));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_top = new QLabel(horizontalLayoutWidget_2);
        label_top->setObjectName(QString::fromUtf8("label_top"));
        label_top->setWordWrap(false);

        verticalLayout_6->addWidget(label_top);

        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer);

        tableWidget_top = new QTableWidget(horizontalLayoutWidget_2);
        if (tableWidget_top->columnCount() < 6)
            tableWidget_top->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_top->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_top->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_top->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_top->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_top->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_top->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_top->setObjectName(QString::fromUtf8("tableWidget_top"));
        tableWidget_top->setRowCount(0);
        tableWidget_top->setColumnCount(6);

        verticalLayout_6->addWidget(tableWidget_top);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_search = new QLabel(horizontalLayoutWidget_2);
        label_search->setObjectName(QString::fromUtf8("label_search"));

        horizontalLayout_4->addWidget(label_search);

        lineEdit_search = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));

        horizontalLayout_4->addWidget(lineEdit_search);

        pushButton_search = new QPushButton(horizontalLayoutWidget_2);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));

        horizontalLayout_4->addWidget(pushButton_search);


        verticalLayout_8->addLayout(horizontalLayout_4);

        tableWidget_results = new QTableWidget(horizontalLayoutWidget_2);
        if (tableWidget_results->columnCount() < 6)
            tableWidget_results->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_results->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_results->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_results->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_results->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_results->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_results->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        tableWidget_results->setObjectName(QString::fromUtf8("tableWidget_results"));
        tableWidget_results->setRowCount(0);
        tableWidget_results->setColumnCount(6);

        verticalLayout_8->addWidget(tableWidget_results);


        horizontalLayout_5->addLayout(verticalLayout_8);

        tabWidget->addTab(tab_search, QString());
        tab_music = new QWidget();
        tab_music->setObjectName(QString::fromUtf8("tab_music"));
        verticalLayoutWidget_8 = new QWidget(tab_music);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(240, 40, 1111, 461));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(12);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_4);

        tableWidget_myMusic = new QTableWidget(verticalLayoutWidget_8);
        if (tableWidget_myMusic->columnCount() < 7)
            tableWidget_myMusic->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_myMusic->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_myMusic->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_myMusic->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_myMusic->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_myMusic->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_myMusic->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_myMusic->setHorizontalHeaderItem(6, __qtablewidgetitem18);
        tableWidget_myMusic->setObjectName(QString::fromUtf8("tableWidget_myMusic"));
        tableWidget_myMusic->setSizeIncrement(QSize(0, 0));
        tableWidget_myMusic->setRowCount(0);
        tableWidget_myMusic->setColumnCount(7);
        tableWidget_myMusic->horizontalHeader()->setDefaultSectionSize(147);
        tableWidget_myMusic->horizontalHeader()->setStretchLastSection(true);
        tableWidget_myMusic->verticalHeader()->setDefaultSectionSize(48);
        tableWidget_myMusic->verticalHeader()->setMinimumSectionSize(33);

        verticalLayout_9->addWidget(tableWidget_myMusic);

        tabWidget->addTab(tab_music, QString());
        tab_playlists = new QWidget();
        tab_playlists->setObjectName(QString::fromUtf8("tab_playlists"));
        frame = new QFrame(tab_playlists);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(590, 350, 341, 131));
        frame->setAutoFillBackground(true);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayoutWidget_5 = new QWidget(frame);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 10, 321, 111));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_createName_3 = new QLabel(verticalLayoutWidget_5);
        label_createName_3->setObjectName(QString::fromUtf8("label_createName_3"));
        label_createName_3->setFont(font);
        label_createName_3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_createName_3);

        lineEdit_changePlaylist = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_changePlaylist->setObjectName(QString::fromUtf8("lineEdit_changePlaylist"));
        lineEdit_changePlaylist->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lineEdit_changePlaylist);

        pushButton_changePlaylist = new QPushButton(verticalLayoutWidget_5);
        pushButton_changePlaylist->setObjectName(QString::fromUtf8("pushButton_changePlaylist"));
        pushButton_changePlaylist->setFont(font);

        verticalLayout_5->addWidget(pushButton_changePlaylist);

        pushButton_closeFrame = new QPushButton(verticalLayoutWidget_5);
        pushButton_closeFrame->setObjectName(QString::fromUtf8("pushButton_closeFrame"));
        pushButton_closeFrame->setFont(font);

        verticalLayout_5->addWidget(pushButton_closeFrame);

        horizontalLayoutWidget_3 = new QWidget(tab_playlists);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 30, 1481, 321));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        verticalLayout_10->addWidget(label);

        tableWidget_playlists = new QTableWidget(horizontalLayoutWidget_3);
        if (tableWidget_playlists->columnCount() < 6)
            tableWidget_playlists->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_playlists->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_playlists->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_playlists->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_playlists->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_playlists->setHorizontalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_playlists->setHorizontalHeaderItem(5, __qtablewidgetitem24);
        tableWidget_playlists->setObjectName(QString::fromUtf8("tableWidget_playlists"));
        tableWidget_playlists->setRowCount(0);
        tableWidget_playlists->setColumnCount(6);
        tableWidget_playlists->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_10->addWidget(tableWidget_playlists);


        horizontalLayout_6->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_playlistInfo = new QLabel(horizontalLayoutWidget_3);
        label_playlistInfo->setObjectName(QString::fromUtf8("label_playlistInfo"));
        label_playlistInfo->setFont(font1);

        verticalLayout_11->addWidget(label_playlistInfo);

        tableWidget_TracksFromPlaylist = new QTableWidget(horizontalLayoutWidget_3);
        if (tableWidget_TracksFromPlaylist->columnCount() < 6)
            tableWidget_TracksFromPlaylist->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_TracksFromPlaylist->setHorizontalHeaderItem(0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_TracksFromPlaylist->setHorizontalHeaderItem(1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_TracksFromPlaylist->setHorizontalHeaderItem(2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_TracksFromPlaylist->setHorizontalHeaderItem(3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_TracksFromPlaylist->setHorizontalHeaderItem(4, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_TracksFromPlaylist->setHorizontalHeaderItem(5, __qtablewidgetitem30);
        tableWidget_TracksFromPlaylist->setObjectName(QString::fromUtf8("tableWidget_TracksFromPlaylist"));
        tableWidget_TracksFromPlaylist->setRowCount(0);
        tableWidget_TracksFromPlaylist->setColumnCount(6);
        tableWidget_TracksFromPlaylist->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_11->addWidget(tableWidget_TracksFromPlaylist);


        horizontalLayout_6->addLayout(verticalLayout_11);

        frame_2 = new QFrame(tab_playlists);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(590, 350, 341, 121));
        frame_2->setAutoFillBackground(true);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        verticalLayoutWidget_2 = new QWidget(frame_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 321, 101));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_createName_2 = new QLabel(verticalLayoutWidget_2);
        label_createName_2->setObjectName(QString::fromUtf8("label_createName_2"));
        label_createName_2->setFont(font);
        label_createName_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_createName_2);

        lineEdit_newPlaylist_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_newPlaylist_2->setObjectName(QString::fromUtf8("lineEdit_newPlaylist_2"));
        lineEdit_newPlaylist_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lineEdit_newPlaylist_2);

        pushButton_createPlaylist_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_createPlaylist_2->setObjectName(QString::fromUtf8("pushButton_createPlaylist_2"));
        pushButton_createPlaylist_2->setFont(font);

        verticalLayout_2->addWidget(pushButton_createPlaylist_2);

        tabWidget->addTab(tab_playlists, QString());
        horizontalLayoutWidget_3->raise();
        frame_2->raise();
        frame->raise();
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 421, 501));
        groupBox->setFont(font2);
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_3 = new QWidget(groupBox);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 30, 401, 461));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_addAlbum = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_addAlbum->setObjectName(QString::fromUtf8("lineEdit_addAlbum"));
        lineEdit_addAlbum->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_addAlbum);

        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        dateEdit = new QDateEdit(verticalLayoutWidget_3);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        dateEdit->setMaximumDate(QDate(2022, 12, 31));
        dateEdit->setMinimumDate(QDate(1900, 9, 14));
        dateEdit->setDate(QDate(2022, 1, 1));

        verticalLayout_3->addWidget(dateEdit);

        comboBox_genres = new QComboBox(verticalLayoutWidget_3);
        comboBox_genres->addItem(QString());
        comboBox_genres->setObjectName(QString::fromUtf8("comboBox_genres"));
        comboBox_genres->setEditable(false);

        verticalLayout_3->addWidget(comboBox_genres);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox_count = new QSpinBox(verticalLayoutWidget_3);
        spinBox_count->setObjectName(QString::fromUtf8("spinBox_count"));
        spinBox_count->setAlignment(Qt::AlignCenter);
        spinBox_count->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_count->setMinimum(2);

        horizontalLayout->addWidget(spinBox_count);


        verticalLayout_3->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(verticalLayoutWidget_3);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem32);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setRowCount(2);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableWidget);

        pushButton_sendToCheck = new QPushButton(verticalLayoutWidget_3);
        pushButton_sendToCheck->setObjectName(QString::fromUtf8("pushButton_sendToCheck"));

        verticalLayout_3->addWidget(pushButton_sendToCheck);

        comboBox_albums = new QComboBox(tab);
        comboBox_albums->addItem(QString());
        comboBox_albums->setObjectName(QString::fromUtf8("comboBox_albums"));
        comboBox_albums->setGeometry(QRect(490, 10, 531, 22));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1030, 10, 80, 21));
        tableWidget_album = new QTableWidget(tab);
        if (tableWidget_album->columnCount() < 5)
            tableWidget_album->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_album->setHorizontalHeaderItem(0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_album->setHorizontalHeaderItem(1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_album->setHorizontalHeaderItem(2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_album->setHorizontalHeaderItem(3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_album->setHorizontalHeaderItem(4, __qtablewidgetitem37);
        tableWidget_album->setObjectName(QString::fromUtf8("tableWidget_album"));
        tableWidget_album->setGeometry(QRect(490, 40, 531, 481));
        tableWidget_album->setRowCount(0);
        tableWidget_album->setColumnCount(5);
        tableWidget_album->horizontalHeader()->setStretchLastSection(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 20, 691, 451));
        groupBox_2->setFont(font2);
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_4 = new QWidget(groupBox_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(40, 40, 611, 401));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBox_check = new QComboBox(verticalLayoutWidget_4);
        comboBox_check->addItem(QString());
        comboBox_check->setObjectName(QString::fromUtf8("comboBox_check"));

        horizontalLayout_2->addWidget(comboBox_check);

        pushButton_open = new QPushButton(verticalLayoutWidget_4);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));

        horizontalLayout_2->addWidget(pushButton_open);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tableWidget_check = new QTableWidget(verticalLayoutWidget_4);
        if (tableWidget_check->columnCount() < 5)
            tableWidget_check->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_check->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_check->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_check->setHorizontalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_check->setHorizontalHeaderItem(3, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_check->setHorizontalHeaderItem(4, __qtablewidgetitem42);
        tableWidget_check->setObjectName(QString::fromUtf8("tableWidget_check"));
        tableWidget_check->setRowCount(0);
        tableWidget_check->setColumnCount(5);
        tableWidget_check->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(tableWidget_check);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_agree = new QPushButton(verticalLayoutWidget_4);
        pushButton_agree->setObjectName(QString::fromUtf8("pushButton_agree"));

        horizontalLayout_3->addWidget(pushButton_agree);

        pushButton_reject = new QPushButton(verticalLayoutWidget_4);
        pushButton_reject->setObjectName(QString::fromUtf8("pushButton_reject"));

        horizontalLayout_3->addWidget(pushButton_reject);


        verticalLayout_4->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1578, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);
        comboBox_genre->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        radioButton_user->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        radioButton_admin->setText(QApplication::translate("MainWindow", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        radioButton_performer->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        lineEdit_login->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275*", nullptr));
        label_login->setText(QApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        lineEdit_password->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214*", nullptr));
        label_password->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton_enter->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        pushButton_toReg->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_reg->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        lineEdit_regLogin->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275*", nullptr));
        lineEdit_regPassword->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214*", nullptr));
        lineEdit_regNameGroup->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213*", nullptr));
        comboBox_genre->setItemText(0, QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\266\320\260\320\275\321\200", nullptr));

        comboBox_genre->setCurrentText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\266\320\260\320\275\321\200", nullptr));
        lineEdit_participants->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\203\321\207\320\260\321\201\321\202\320\275\320\270\320\272\320\276\320\262 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        pushButton_reg->setText(QApplication::translate("MainWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        pushButton_back->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_login), QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_top->setText(QApplication::translate("MainWindow", "\320\242\320\276\320\277 \320\274\321\203\320\267\321\213\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_top->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_top->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_top->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_top->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_top->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_top->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_search->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        lineEdit_search->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\321\200\320\265\320\272\320\260 \320\270\320\273\320\270 \320\270\320\274\321\217 \320\270\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\217", nullptr));
        pushButton_search->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_results->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_results->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_results->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_results->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_results->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_results->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_search), QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\234\321\203\320\267\321\213\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_myMusic->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_myMusic->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_myMusic->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_myMusic->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_myMusic->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_myMusic->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\320\222\320\267\320\260\320\270\320\274\320\276\320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_myMusic->horizontalHeaderItem(6);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_music), QApplication::translate("MainWindow", "\320\234\320\276\321\217 \320\274\321\203\320\267\321\213\320\272\320\260", nullptr));
        label_createName_3->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202\320\260", nullptr));
        lineEdit_changePlaylist->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton_changePlaylist->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_closeFrame->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\270 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_playlists->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_playlists->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\277\320\265\321\201\320\265\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_playlists->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_playlists->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_playlists->horizontalHeaderItem(4);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_playlists->horizontalHeaderItem(5);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_playlistInfo->setText(QApplication::translate("MainWindow", "\320\237\320\273\320\265\320\271\320\273\320\270\321\201\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_TracksFromPlaylist->horizontalHeaderItem(0);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_TracksFromPlaylist->horizontalHeaderItem(1);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_TracksFromPlaylist->horizontalHeaderItem(2);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_TracksFromPlaylist->horizontalHeaderItem(3);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 ", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_TracksFromPlaylist->horizontalHeaderItem(4);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_TracksFromPlaylist->horizontalHeaderItem(5);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_createName_2->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202\320\260", nullptr));
        lineEdit_newPlaylist_2->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        pushButton_createPlaylist_2->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_playlists), QApplication::translate("MainWindow", "\320\234\320\276\320\270 \320\277\320\273\320\265\320\271\320\273\320\270\321\201\321\202\321\213", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\260\320\273\321\214\320\261\320\276\320\274 \320\275\320\260 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\321\203", nullptr));
        lineEdit_addAlbum->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\260\320\273\321\214\320\261\320\276\320\274\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\263\320\276\320\264 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \320\260\320\273\321\214\320\261\320\276\320\274", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("MainWindow", "yyyy", nullptr));
        comboBox_genres->setItemText(0, QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\266\320\260\320\275\321\200", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\321\200\320\265\320\272\320\276\320\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\321\200\320\265\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 (\320\262 \320\274\320\270\320\275\321\203\321\202\320\260\321\205)", nullptr));
        pushButton_sendToCheck->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\275\320\260 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\321\203", nullptr));
        comboBox_albums->setItemText(0, QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\270 \320\260\320\273\321\214\320\261\320\276\320\274\321\213", nullptr));

        pushButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_album->horizontalHeaderItem(0);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_album->horizontalHeaderItem(1);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_album->horizontalHeaderItem(2);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_album->horizontalHeaderItem(3);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_album->horizontalHeaderItem(4);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260 \320\270\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\217", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\321\217\320\262\320\272\320\270 \320\275\320\260 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\321\203", nullptr));
        comboBox_check->setItemText(0, QApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274\321\213 \320\277\320\276\320\264 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\321\203", nullptr));

        pushButton_open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_check->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_check->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "\320\230\321\201\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_check->horizontalHeaderItem(2);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "\320\220\320\273\321\214\320\261\320\276\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_check->horizontalHeaderItem(3);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_check->horizontalHeaderItem(4);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200", nullptr));
        pushButton_agree->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_reject->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\320\276\320\275\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260 \320\260\320\264\320\274\320\270\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
