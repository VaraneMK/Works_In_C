/********************************************************************************
** Form generated from reading UI file 'actionwithsession.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONWITHSESSION_H
#define UI_ACTIONWITHSESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionWithSession
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_info;
    QComboBox *comboBox_movie;
    QComboBox *comboBox_hall;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QPushButton *pushButton_add;
    QPushButton *pushButton_close;
    QWidget *tab_2;
    QTableWidget *tableWidget_sessions;

    void setupUi(QDialog *ActionWithSession)
    {
        if (ActionWithSession->objectName().isEmpty())
            ActionWithSession->setObjectName(QString::fromUtf8("ActionWithSession"));
        ActionWithSession->resize(435, 446);
        QFont font;
        font.setPointSize(12);
        ActionWithSession->setFont(font);
        tabWidget = new QTabWidget(ActionWithSession);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 411, 441));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 361, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_info = new QLabel(verticalLayoutWidget);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        QFont font1;
        font1.setPointSize(14);
        label_info->setFont(font1);
        label_info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_info);

        comboBox_movie = new QComboBox(verticalLayoutWidget);
        comboBox_movie->addItem(QString());
        comboBox_movie->setObjectName(QString::fromUtf8("comboBox_movie"));

        verticalLayout->addWidget(comboBox_movie);

        comboBox_hall = new QComboBox(verticalLayoutWidget);
        comboBox_hall->addItem(QString());
        comboBox_hall->setObjectName(QString::fromUtf8("comboBox_hall"));

        verticalLayout->addWidget(comboBox_hall);

        dateEdit = new QDateEdit(verticalLayoutWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateEdit->setCalendarPopup(true);

        verticalLayout->addWidget(dateEdit);

        timeEdit = new QTimeEdit(verticalLayoutWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setEnabled(true);
        timeEdit->setAlignment(Qt::AlignCenter);
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        timeEdit->setCalendarPopup(false);

        verticalLayout->addWidget(timeEdit);

        pushButton_add = new QPushButton(verticalLayoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);

        pushButton_close = new QPushButton(verticalLayoutWidget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        verticalLayout->addWidget(pushButton_close);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableWidget_sessions = new QTableWidget(tab_2);
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
        tableWidget_sessions->setGeometry(QRect(0, 0, 411, 411));
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
        tabWidget->addTab(tab_2, QString());

        retranslateUi(ActionWithSession);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ActionWithSession);
    } // setupUi

    void retranslateUi(QDialog *ActionWithSession)
    {
        ActionWithSession->setWindowTitle(QApplication::translate("ActionWithSession", "Dialog", nullptr));
        label_info->setText(QApplication::translate("ActionWithSession", "\320\241\320\265\320\260\320\275\321\201", nullptr));
        comboBox_movie->setItemText(0, QApplication::translate("ActionWithSession", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\270\320\273\321\214\320\274\320\260", nullptr));

        comboBox_hall->setItemText(0, QApplication::translate("ActionWithSession", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\267\320\260\320\273", nullptr));

        timeEdit->setDisplayFormat(QApplication::translate("ActionWithSession", "hh:mm", nullptr));
        pushButton_add->setText(QApplication::translate("ActionWithSession", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_close->setText(QApplication::translate("ActionWithSession", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ActionWithSession", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\265\320\260\320\275\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_sessions->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ActionWithSession", "\320\227\320\260\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_sessions->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ActionWithSession", "\320\244\320\270\320\273\321\214\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_sessions->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ActionWithSession", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_sessions->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ActionWithSession", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_sessions->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ActionWithSession", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ActionWithSession", "\320\222\321\201\320\265 \321\201\320\265\320\260\320\275\321\201\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActionWithSession: public Ui_ActionWithSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONWITHSESSION_H
