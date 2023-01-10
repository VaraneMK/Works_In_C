/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
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
    QFrame *frame_login;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_viewReg;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_user;
    QRadioButton *radioButton_admin;
    QLineEdit *lineEdit_login;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_echoChange;
    QPushButton *pushButton_enter;
    QFrame *frame_reg;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_reg;
    QLineEdit *lineEdit_regLogin;
    QLineEdit *lineEdit_regPassword;
    QLineEdit *lineEdit_regBD;
    QLineEdit *lineEdit_regEmail;
    QLineEdit *lineEdit_regPhoneNumber;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_reg;
    QPushButton *pushButton_closeRegFrame;
    QWidget *tab_search;
    QFrame *frame_movieInfo;
    QLabel *label_hall;
    QFrame *frame;
    QLabel *label_row4;
    QLabel *label_row2;
    QLabel *label_row3;
    QLabel *label_row7;
    QLabel *label_row5;
    QLabel *label_row1;
    QLabel *label_screen;
    QLabel *label_row6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_busy;
    QLabel *label_onBasket;
    QLabel *label_yourPlace;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_placeInfo;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_numberRow;
    QSpinBox *spinBox_numberRow;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_numberPlace;
    QSpinBox *spinBox_numberPlace;
    QPushButton *pushButton_addToBasket;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_genre;
    QLineEdit *lineEdit_genre;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_duration_2;
    QLineEdit *lineEdit_ageLimit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_duration;
    QLineEdit *lineEdit_duration;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_duration_3;
    QLineEdit *lineEdit_rating;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_acteurs;
    QTextEdit *textEdit_acteurs;
    QLabel *label;
    QTextEdit *textEdit_reviews;
    QPushButton *pushButton_closeMovieInfo;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QCalendarWidget *calendarWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_sessionInfo;
    QTableWidget *tableWidget_sessions;
    QWidget *tab_basket;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_money;
    QTableWidget *tableWidget_basket;
    QWidget *tab_tickets;
    QTableWidget *tableWidget_tickets;
    QLabel *label_history;
    QTableWidget *tableWidget_history;
    QLabel *label_history_2;
    QWidget *tab_admin;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButton_ActionWithGenre;
    QPushButton *pushButton_ActionWithMovie;
    QPushButton *pushButton_ActionWithSession;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1390, 615);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1391, 561));
        tab_login = new QWidget();
        tab_login->setObjectName(QString::fromUtf8("tab_login"));
        frame_login = new QFrame(tab_login);
        frame_login->setObjectName(QString::fromUtf8("frame_login"));
        frame_login->setGeometry(QRect(480, 100, 331, 261));
        frame_login->setAutoFillBackground(true);
        frame_login->setFrameShape(QFrame::StyledPanel);
        frame_login->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget_2 = new QWidget(frame_login);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 311, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(26);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_viewReg = new QPushButton(verticalLayoutWidget_2);
        pushButton_viewReg->setObjectName(QString::fromUtf8("pushButton_viewReg"));

        verticalLayout_2->addWidget(pushButton_viewReg);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_user = new QRadioButton(verticalLayoutWidget_2);
        radioButton_user->setObjectName(QString::fromUtf8("radioButton_user"));

        horizontalLayout->addWidget(radioButton_user);

        radioButton_admin = new QRadioButton(verticalLayoutWidget_2);
        radioButton_admin->setObjectName(QString::fromUtf8("radioButton_admin"));

        horizontalLayout->addWidget(radioButton_admin);


        verticalLayout_2->addLayout(horizontalLayout);

        lineEdit_login = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        verticalLayout_2->addWidget(lineEdit_login);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_password = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout_3->addWidget(lineEdit_password);

        pushButton_echoChange = new QPushButton(verticalLayoutWidget_2);
        pushButton_echoChange->setObjectName(QString::fromUtf8("pushButton_echoChange"));
        pushButton_echoChange->setMaximumSize(QSize(21, 21));

        horizontalLayout_3->addWidget(pushButton_echoChange);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pushButton_enter = new QPushButton(verticalLayoutWidget_2);
        pushButton_enter->setObjectName(QString::fromUtf8("pushButton_enter"));

        verticalLayout_2->addWidget(pushButton_enter);

        frame_reg = new QFrame(tab_login);
        frame_reg->setObjectName(QString::fromUtf8("frame_reg"));
        frame_reg->setGeometry(QRect(480, 50, 331, 381));
        frame_reg->setAutoFillBackground(true);
        frame_reg->setFrameShape(QFrame::StyledPanel);
        frame_reg->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget = new QWidget(frame_reg);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 311, 368));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(26);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_reg = new QLabel(verticalLayoutWidget);
        label_reg->setObjectName(QString::fromUtf8("label_reg"));
        QFont font;
        font.setPointSize(15);
        label_reg->setFont(font);
        label_reg->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_reg);

        lineEdit_regLogin = new QLineEdit(verticalLayoutWidget);
        lineEdit_regLogin->setObjectName(QString::fromUtf8("lineEdit_regLogin"));

        verticalLayout->addWidget(lineEdit_regLogin);

        lineEdit_regPassword = new QLineEdit(verticalLayoutWidget);
        lineEdit_regPassword->setObjectName(QString::fromUtf8("lineEdit_regPassword"));

        verticalLayout->addWidget(lineEdit_regPassword);

        lineEdit_regBD = new QLineEdit(verticalLayoutWidget);
        lineEdit_regBD->setObjectName(QString::fromUtf8("lineEdit_regBD"));

        verticalLayout->addWidget(lineEdit_regBD);

        lineEdit_regEmail = new QLineEdit(verticalLayoutWidget);
        lineEdit_regEmail->setObjectName(QString::fromUtf8("lineEdit_regEmail"));
        lineEdit_regEmail->setFrame(true);
        lineEdit_regEmail->setDragEnabled(true);
        lineEdit_regEmail->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_regEmail->setClearButtonEnabled(false);

        verticalLayout->addWidget(lineEdit_regEmail);

        lineEdit_regPhoneNumber = new QLineEdit(verticalLayoutWidget);
        lineEdit_regPhoneNumber->setObjectName(QString::fromUtf8("lineEdit_regPhoneNumber"));

        verticalLayout->addWidget(lineEdit_regPhoneNumber);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_reg = new QPushButton(verticalLayoutWidget);
        pushButton_reg->setObjectName(QString::fromUtf8("pushButton_reg"));

        horizontalLayout_2->addWidget(pushButton_reg);

        pushButton_closeRegFrame = new QPushButton(verticalLayoutWidget);
        pushButton_closeRegFrame->setObjectName(QString::fromUtf8("pushButton_closeRegFrame"));

        horizontalLayout_2->addWidget(pushButton_closeRegFrame);


        verticalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_login, QString());
        tab_search = new QWidget();
        tab_search->setObjectName(QString::fromUtf8("tab_search"));
        frame_movieInfo = new QFrame(tab_search);
        frame_movieInfo->setObjectName(QString::fromUtf8("frame_movieInfo"));
        frame_movieInfo->setGeometry(QRect(10, 10, 1351, 481));
        QFont font1;
        font1.setPointSize(12);
        frame_movieInfo->setFont(font1);
        frame_movieInfo->setAutoFillBackground(true);
        frame_movieInfo->setFrameShape(QFrame::StyledPanel);
        frame_movieInfo->setFrameShadow(QFrame::Sunken);
        label_hall = new QLabel(frame_movieInfo);
        label_hall->setObjectName(QString::fromUtf8("label_hall"));
        label_hall->setGeometry(QRect(470, 20, 51, 21));
        frame = new QFrame(frame_movieInfo);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(470, 40, 501, 371));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        label_row4 = new QLabel(frame);
        label_row4->setObjectName(QString::fromUtf8("label_row4"));
        label_row4->setGeometry(QRect(20, 190, 35, 20));
        label_row2 = new QLabel(frame);
        label_row2->setObjectName(QString::fromUtf8("label_row2"));
        label_row2->setGeometry(QRect(20, 110, 35, 20));
        label_row3 = new QLabel(frame);
        label_row3->setObjectName(QString::fromUtf8("label_row3"));
        label_row3->setGeometry(QRect(20, 150, 35, 20));
        label_row7 = new QLabel(frame);
        label_row7->setObjectName(QString::fromUtf8("label_row7"));
        label_row7->setGeometry(QRect(20, 310, 35, 20));
        label_row5 = new QLabel(frame);
        label_row5->setObjectName(QString::fromUtf8("label_row5"));
        label_row5->setGeometry(QRect(20, 230, 35, 20));
        label_row1 = new QLabel(frame);
        label_row1->setObjectName(QString::fromUtf8("label_row1"));
        label_row1->setGeometry(QRect(20, 70, 35, 20));
        label_screen = new QLabel(frame);
        label_screen->setObjectName(QString::fromUtf8("label_screen"));
        label_screen->setGeometry(QRect(50, 20, 420, 16));
        QFont font2;
        font2.setPointSize(10);
        label_screen->setFont(font2);
        label_screen->setFrameShape(QFrame::Box);
        label_screen->setAlignment(Qt::AlignCenter);
        label_row6 = new QLabel(frame);
        label_row6->setObjectName(QString::fromUtf8("label_row6"));
        label_row6->setGeometry(QRect(20, 270, 35, 20));
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 350, 281, 20));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_busy = new QLabel(horizontalLayoutWidget);
        label_busy->setObjectName(QString::fromUtf8("label_busy"));
        QFont font3;
        font3.setPointSize(9);
        label_busy->setFont(font3);
        label_busy->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        horizontalLayout_12->addWidget(label_busy);

        label_onBasket = new QLabel(horizontalLayoutWidget);
        label_onBasket->setObjectName(QString::fromUtf8("label_onBasket"));
        label_onBasket->setFont(font3);
        label_onBasket->setStyleSheet(QString::fromUtf8("color: rgb(181, 181, 181);"));

        horizontalLayout_12->addWidget(label_onBasket);

        label_yourPlace = new QLabel(horizontalLayoutWidget);
        label_yourPlace->setObjectName(QString::fromUtf8("label_yourPlace"));
        label_yourPlace->setFont(font3);
        label_yourPlace->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        horizontalLayout_12->addWidget(label_yourPlace);

        verticalLayoutWidget_4 = new QWidget(frame_movieInfo);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(1160, 40, 190, 151));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_placeInfo = new QLabel(verticalLayoutWidget_4);
        label_placeInfo->setObjectName(QString::fromUtf8("label_placeInfo"));

        verticalLayout_6->addWidget(label_placeInfo);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_numberRow = new QLabel(verticalLayoutWidget_4);
        label_numberRow->setObjectName(QString::fromUtf8("label_numberRow"));

        horizontalLayout_6->addWidget(label_numberRow);

        spinBox_numberRow = new QSpinBox(verticalLayoutWidget_4);
        spinBox_numberRow->setObjectName(QString::fromUtf8("spinBox_numberRow"));
        spinBox_numberRow->setEnabled(true);
        spinBox_numberRow->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_numberRow->setFrame(true);
        spinBox_numberRow->setAlignment(Qt::AlignCenter);
        spinBox_numberRow->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_numberRow->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinBox_numberRow->setKeyboardTracking(true);
        spinBox_numberRow->setProperty("showGroupSeparator", QVariant(false));

        horizontalLayout_6->addWidget(spinBox_numberRow);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_numberPlace = new QLabel(verticalLayoutWidget_4);
        label_numberPlace->setObjectName(QString::fromUtf8("label_numberPlace"));

        horizontalLayout_7->addWidget(label_numberPlace);

        spinBox_numberPlace = new QSpinBox(verticalLayoutWidget_4);
        spinBox_numberPlace->setObjectName(QString::fromUtf8("spinBox_numberPlace"));
        spinBox_numberPlace->setEnabled(true);
        spinBox_numberPlace->setInputMethodHints(Qt::ImhDigitsOnly);
        spinBox_numberPlace->setFrame(true);
        spinBox_numberPlace->setAlignment(Qt::AlignCenter);
        spinBox_numberPlace->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_numberPlace->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinBox_numberPlace->setKeyboardTracking(true);
        spinBox_numberPlace->setProperty("showGroupSeparator", QVariant(false));

        horizontalLayout_7->addWidget(spinBox_numberPlace);


        verticalLayout_6->addLayout(horizontalLayout_7);

        pushButton_addToBasket = new QPushButton(verticalLayoutWidget_4);
        pushButton_addToBasket->setObjectName(QString::fromUtf8("pushButton_addToBasket"));

        verticalLayout_6->addWidget(pushButton_addToBasket);

        verticalLayoutWidget_5 = new QWidget(frame_movieInfo);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 0, 391, 481));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_name = new QLabel(verticalLayoutWidget_5);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout_8->addWidget(label_name);

        lineEdit_name = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout_8->addWidget(lineEdit_name);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_genre = new QLabel(verticalLayoutWidget_5);
        label_genre->setObjectName(QString::fromUtf8("label_genre"));

        horizontalLayout_9->addWidget(label_genre);

        lineEdit_genre = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_genre->setObjectName(QString::fromUtf8("lineEdit_genre"));

        horizontalLayout_9->addWidget(lineEdit_genre);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_duration_2 = new QLabel(verticalLayoutWidget_5);
        label_duration_2->setObjectName(QString::fromUtf8("label_duration_2"));

        horizontalLayout_10->addWidget(label_duration_2);

        lineEdit_ageLimit = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_ageLimit->setObjectName(QString::fromUtf8("lineEdit_ageLimit"));
        lineEdit_ageLimit->setContextMenuPolicy(Qt::DefaultContextMenu);

        horizontalLayout_10->addWidget(lineEdit_ageLimit);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_duration = new QLabel(verticalLayoutWidget_5);
        label_duration->setObjectName(QString::fromUtf8("label_duration"));

        horizontalLayout_11->addWidget(label_duration);

        lineEdit_duration = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_duration->setObjectName(QString::fromUtf8("lineEdit_duration"));

        horizontalLayout_11->addWidget(lineEdit_duration);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_duration_3 = new QLabel(verticalLayoutWidget_5);
        label_duration_3->setObjectName(QString::fromUtf8("label_duration_3"));

        horizontalLayout_13->addWidget(label_duration_3);

        lineEdit_rating = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_rating->setObjectName(QString::fromUtf8("lineEdit_rating"));

        horizontalLayout_13->addWidget(lineEdit_rating);


        verticalLayout_7->addLayout(horizontalLayout_13);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_acteurs = new QLabel(verticalLayoutWidget_5);
        label_acteurs->setObjectName(QString::fromUtf8("label_acteurs"));

        verticalLayout_8->addWidget(label_acteurs);

        textEdit_acteurs = new QTextEdit(verticalLayoutWidget_5);
        textEdit_acteurs->setObjectName(QString::fromUtf8("textEdit_acteurs"));

        verticalLayout_8->addWidget(textEdit_acteurs);

        label = new QLabel(verticalLayoutWidget_5);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_8->addWidget(label);

        textEdit_reviews = new QTextEdit(verticalLayoutWidget_5);
        textEdit_reviews->setObjectName(QString::fromUtf8("textEdit_reviews"));

        verticalLayout_8->addWidget(textEdit_reviews);


        verticalLayout_7->addLayout(verticalLayout_8);

        pushButton_closeMovieInfo = new QPushButton(frame_movieInfo);
        pushButton_closeMovieInfo->setObjectName(QString::fromUtf8("pushButton_closeMovieInfo"));
        pushButton_closeMovieInfo->setGeometry(QRect(1280, 0, 71, 21));
        pushButton_closeMovieInfo->setFont(font3);
        horizontalLayoutWidget_2 = new QWidget(tab_search);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 50, 1231, 391));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_search = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));
        lineEdit_search->setCursorMoveStyle(Qt::LogicalMoveStyle);

        verticalLayout_4->addWidget(lineEdit_search);

        pushButton_search = new QPushButton(horizontalLayoutWidget_2);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));

        verticalLayout_4->addWidget(pushButton_search);

        calendarWidget = new QCalendarWidget(horizontalLayoutWidget_2);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGridVisible(false);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        verticalLayout_4->addWidget(calendarWidget);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_sessionInfo = new QLabel(horizontalLayoutWidget_2);
        label_sessionInfo->setObjectName(QString::fromUtf8("label_sessionInfo"));
        QFont font4;
        font4.setPointSize(16);
        label_sessionInfo->setFont(font4);
        label_sessionInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_sessionInfo);

        tableWidget_sessions = new QTableWidget(horizontalLayoutWidget_2);
        if (tableWidget_sessions->columnCount() < 5)
            tableWidget_sessions->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_sessions->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_sessions->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_sessions->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_sessions->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_sessions->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_sessions->setObjectName(QString::fromUtf8("tableWidget_sessions"));
        tableWidget_sessions->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget_sessions->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget_sessions->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableWidget_sessions->setTextElideMode(Qt::ElideLeft);
        tableWidget_sessions->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget_sessions->setGridStyle(Qt::SolidLine);
        tableWidget_sessions->setSortingEnabled(false);
        tableWidget_sessions->setWordWrap(false);
        tableWidget_sessions->setCornerButtonEnabled(true);
        tableWidget_sessions->setRowCount(0);
        tableWidget_sessions->setColumnCount(5);
        tableWidget_sessions->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_sessions->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget_sessions->horizontalHeader()->setMinimumSectionSize(34);
        tableWidget_sessions->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_sessions->horizontalHeader()->setStretchLastSection(true);
        tableWidget_sessions->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_sessions->verticalHeader()->setStretchLastSection(false);

        verticalLayout_5->addWidget(tableWidget_sessions);


        horizontalLayout_5->addLayout(verticalLayout_5);

        tabWidget->addTab(tab_search, QString());
        horizontalLayoutWidget_2->raise();
        frame_movieInfo->raise();
        tab_basket = new QWidget();
        tab_basket->setObjectName(QString::fromUtf8("tab_basket"));
        verticalLayoutWidget_3 = new QWidget(tab_basket);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(150, 30, 1041, 451));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 0, 5, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_money = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_money->setObjectName(QString::fromUtf8("lineEdit_money"));

        horizontalLayout_4->addWidget(lineEdit_money);


        verticalLayout_3->addLayout(horizontalLayout_4);

        tableWidget_basket = new QTableWidget(verticalLayoutWidget_3);
        if (tableWidget_basket->columnCount() < 8)
            tableWidget_basket->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_basket->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_basket->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_basket->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_basket->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_basket->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_basket->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_basket->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_basket->setHorizontalHeaderItem(7, __qtablewidgetitem12);
        tableWidget_basket->setObjectName(QString::fromUtf8("tableWidget_basket"));
        tableWidget_basket->setColumnCount(8);
        tableWidget_basket->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableWidget_basket);

        tabWidget->addTab(tab_basket, QString());
        tab_tickets = new QWidget();
        tab_tickets->setObjectName(QString::fromUtf8("tab_tickets"));
        tableWidget_tickets = new QTableWidget(tab_tickets);
        if (tableWidget_tickets->columnCount() < 6)
            tableWidget_tickets->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_tickets->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_tickets->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_tickets->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_tickets->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_tickets->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_tickets->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        tableWidget_tickets->setObjectName(QString::fromUtf8("tableWidget_tickets"));
        tableWidget_tickets->setGeometry(QRect(10, 50, 611, 391));
        tableWidget_tickets->horizontalHeader()->setStretchLastSection(true);
        label_history = new QLabel(tab_tickets);
        label_history->setObjectName(QString::fromUtf8("label_history"));
        label_history->setGeometry(QRect(10, 10, 251, 31));
        QFont font5;
        font5.setPointSize(14);
        label_history->setFont(font5);
        tableWidget_history = new QTableWidget(tab_tickets);
        if (tableWidget_history->columnCount() < 2)
            tableWidget_history->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_history->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        tableWidget_history->setObjectName(QString::fromUtf8("tableWidget_history"));
        tableWidget_history->setGeometry(QRect(770, 50, 311, 391));
        tableWidget_history->horizontalHeader()->setStretchLastSection(true);
        label_history_2 = new QLabel(tab_tickets);
        label_history_2->setObjectName(QString::fromUtf8("label_history_2"));
        label_history_2->setGeometry(QRect(770, 10, 251, 31));
        label_history_2->setFont(font5);
        tabWidget->addTab(tab_tickets, QString());
        tab_admin = new QWidget();
        tab_admin->setObjectName(QString::fromUtf8("tab_admin"));
        groupBox = new QGroupBox(tab_admin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(500, 80, 261, 321));
        QFont font6;
        font6.setPointSize(11);
        groupBox->setFont(font6);
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_6 = new QWidget(groupBox);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(20, 30, 221, 281));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButton_ActionWithGenre = new QPushButton(verticalLayoutWidget_6);
        pushButton_ActionWithGenre->setObjectName(QString::fromUtf8("pushButton_ActionWithGenre"));

        verticalLayout_9->addWidget(pushButton_ActionWithGenre);

        pushButton_ActionWithMovie = new QPushButton(verticalLayoutWidget_6);
        pushButton_ActionWithMovie->setObjectName(QString::fromUtf8("pushButton_ActionWithMovie"));

        verticalLayout_9->addWidget(pushButton_ActionWithMovie);

        pushButton_ActionWithSession = new QPushButton(verticalLayoutWidget_6);
        pushButton_ActionWithSession->setObjectName(QString::fromUtf8("pushButton_ActionWithSession"));

        verticalLayout_9->addWidget(pushButton_ActionWithSession);

        tabWidget->addTab(tab_admin, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1390, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_viewReg->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        radioButton_user->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        radioButton_admin->setText(QApplication::translate("MainWindow", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        lineEdit_login->setText(QApplication::translate("MainWindow", "varanemk", nullptr));
        lineEdit_login->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210 \320\273\320\276\320\263\320\270\320\275", nullptr));
        lineEdit_password->setText(QApplication::translate("MainWindow", "katalka2002", nullptr));
        lineEdit_password->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton_echoChange->setText(QApplication::translate("MainWindow", ".", nullptr));
        pushButton_enter->setText(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
        label_reg->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        lineEdit_regLogin->setText(QString());
        lineEdit_regLogin->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275*", nullptr));
        lineEdit_regPassword->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214*", nullptr));
        lineEdit_regBD->setText(QString());
        lineEdit_regBD->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217*", nullptr));
        lineEdit_regEmail->setText(QString());
        lineEdit_regEmail->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 email", nullptr));
        lineEdit_regPhoneNumber->setText(QString());
        lineEdit_regPhoneNumber->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        pushButton_reg->setText(QApplication::translate("MainWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        pushButton_closeRegFrame->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_login), QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_hall->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\273", nullptr));
        label_row4->setText(QApplication::translate("MainWindow", "4 \321\200\321\217\320\264", nullptr));
        label_row2->setText(QApplication::translate("MainWindow", "2 \321\200\321\217\320\264", nullptr));
        label_row3->setText(QApplication::translate("MainWindow", "3 \321\200\321\217\320\264", nullptr));
        label_row7->setText(QApplication::translate("MainWindow", "7 \321\200\321\217\320\264", nullptr));
        label_row5->setText(QApplication::translate("MainWindow", "5 \321\200\321\217\320\264", nullptr));
        label_row1->setText(QApplication::translate("MainWindow", "1 \321\200\321\217\320\264", nullptr));
        label_screen->setText(QApplication::translate("MainWindow", "\320\255\320\272\321\200\320\260\320\275", nullptr));
        label_row6->setText(QApplication::translate("MainWindow", "6 \321\200\321\217\320\264", nullptr));
        label_busy->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\275\321\217\321\202\320\276", nullptr));
        label_onBasket->setText(QApplication::translate("MainWindow", "\320\222 \320\272\320\276\321\200\320\267\320\270\320\275\320\265", nullptr));
        label_yourPlace->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\270 \320\274\320\265\321\201\321\202\320\260", nullptr));
        label_placeInfo->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\265 \320\274\320\265\321\201\321\202\320\276", nullptr));
        label_numberRow->setText(QApplication::translate("MainWindow", "\342\204\226 \320\240\321\217\320\264\320\260", nullptr));
        label_numberPlace->setText(QApplication::translate("MainWindow", "\342\204\226 \320\234\320\265\321\201\321\202\320\260", nullptr));
        pushButton_addToBasket->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\272\320\276\321\200\320\267\320\270\320\275\321\203", nullptr));
        label_name->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_genre->setText(QApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200:", nullptr));
        label_duration_2->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202\320\275\320\276\320\265 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_duration->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_duration_3->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263:", nullptr));
        label_acteurs->setText(QApplication::translate("MainWindow", "\320\222 \321\200\320\276\320\273\321\217\321\205:", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\267\321\213\320\262\321\213", nullptr));
        pushButton_closeMovieInfo->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        lineEdit_search->setPlaceholderText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        pushButton_search->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        label_sessionInfo->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\263\320\276\320\264\320\275\321\217 \320\262 \320\272\320\270\320\275\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_sessions->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_sessions->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_sessions->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_sessions->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_sessions->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_search), QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210 \320\261\320\260\320\273\320\260\320\275\321\201", nullptr));
        lineEdit_money->setText(QApplication::translate("MainWindow", "*\320\262\320\265\321\201\321\214 \320\275\320\265\321\204\321\202\321\217\320\275\320\276\320\271 \320\267\320\260\320\277\320\260\321\201 \320\240\320\244*", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_basket->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_basket->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_basket->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_basket->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_basket->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\342\204\226 \321\200\321\217\320\264\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_basket->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\342\204\226 \320\274\320\265\321\201\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_basket->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\320\232\321\203\320\277\320\270\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_basket->horizontalHeaderItem(7);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_basket), QApplication::translate("MainWindow", "\320\232\320\276\321\200\320\267\320\270\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_tickets->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_tickets->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_tickets->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_tickets->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_tickets->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\342\204\226 \321\200\321\217\320\264\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_tickets->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\342\204\226 \320\274\320\265\321\201\321\202\320\260", nullptr));
        label_history->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\277\320\276\320\272\321\203\320\277\320\276\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_history->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_history->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\267\321\213\320\262", nullptr));
        label_history_2->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\276\320\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_tickets), QApplication::translate("MainWindow", "\320\221\320\270\320\273\320\265\321\202\321\213", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\270 \320\277\321\200\320\260\320\262\320\260", nullptr));
        pushButton_ActionWithGenre->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\266\320\260\320\275\321\200", nullptr));
        pushButton_ActionWithMovie->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\320\274", nullptr));
        pushButton_ActionWithSession->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\265\320\260\320\275\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_admin), QApplication::translate("MainWindow", "\320\220\320\264\320\274\320\270\320\275\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
