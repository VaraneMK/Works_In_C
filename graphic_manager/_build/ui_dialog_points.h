/********************************************************************************
** Form generated from reading UI file 'dialog_points.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_POINTS_H
#define UI_DIALOG_POINTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_points
{
public:
    QSpinBox *spinBox;
    QTableWidget *tableWidget;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *Dialog_points)
    {
        if (Dialog_points->objectName().isEmpty())
            Dialog_points->setObjectName(QString::fromUtf8("Dialog_points"));
        Dialog_points->resize(500, 421);
        spinBox = new QSpinBox(Dialog_points);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(380, 40, 46, 22));
        spinBox->setMinimum(2);
        spinBox->setMaximum(20);
        spinBox->setValue(3);
        tableWidget = new QTableWidget(Dialog_points);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 30, 231, 281));
        tableWidget->setRowCount(3);
        tableWidget->setColumnCount(2);
        pushButton_OK = new QPushButton(Dialog_points);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(300, 380, 75, 23));
        pushButton_Cancel = new QPushButton(Dialog_points);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(390, 380, 75, 23));

        retranslateUi(Dialog_points);

        QMetaObject::connectSlotsByName(Dialog_points);
    } // setupUi

    void retranslateUi(QDialog *Dialog_points)
    {
        Dialog_points->setWindowTitle(QCoreApplication::translate("Dialog_points", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Dialog_points", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Dialog_points", "Y", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Dialog_points", "OK", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("Dialog_points", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_points: public Ui_Dialog_points {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_POINTS_H
