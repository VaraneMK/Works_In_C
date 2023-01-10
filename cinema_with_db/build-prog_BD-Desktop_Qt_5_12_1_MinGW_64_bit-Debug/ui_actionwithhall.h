/********************************************************************************
** Form generated from reading UI file 'actionwithhall.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONWITHHALL_H
#define UI_ACTIONWITHHALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionWithHall
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *ActionWithHall)
    {
        if (ActionWithHall->objectName().isEmpty())
            ActionWithHall->setObjectName(QString::fromUtf8("ActionWithHall"));
        ActionWithHall->resize(301, 204);
        verticalLayoutWidget = new QWidget(ActionWithHall);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 281, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(ActionWithHall);

        QMetaObject::connectSlotsByName(ActionWithHall);
    } // setupUi

    void retranslateUi(QDialog *ActionWithHall)
    {
        ActionWithHall->setWindowTitle(QApplication::translate("ActionWithHall", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ActionWithHall", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActionWithHall: public Ui_ActionWithHall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONWITHHALL_H
