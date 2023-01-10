/********************************************************************************
** Form generated from reading UI file 'actionwithgenre.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONWITHGENRE_H
#define UI_ACTIONWITHGENRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionWithGenre
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_description;
    QPushButton *pushButton_add;
    QPushButton *pushButton_close;
    QWidget *tab_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ActionWithGenre)
    {
        if (ActionWithGenre->objectName().isEmpty())
            ActionWithGenre->setObjectName(QString::fromUtf8("ActionWithGenre"));
        ActionWithGenre->resize(321, 271);
        QFont font;
        font.setPointSize(12);
        ActionWithGenre->setFont(font);
        tabWidget = new QTabWidget(ActionWithGenre);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 321, 271));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 291, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(verticalLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout->addWidget(lineEdit_name);

        lineEdit_description = new QLineEdit(verticalLayoutWidget);
        lineEdit_description->setObjectName(QString::fromUtf8("lineEdit_description"));

        verticalLayout->addWidget(lineEdit_description);

        pushButton_add = new QPushButton(verticalLayoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);

        pushButton_close = new QPushButton(verticalLayoutWidget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        verticalLayout->addWidget(pushButton_close);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 321, 241));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(ActionWithGenre);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ActionWithGenre);
    } // setupUi

    void retranslateUi(QDialog *ActionWithGenre)
    {
        ActionWithGenre->setWindowTitle(QApplication::translate("ActionWithGenre", "Dialog", nullptr));
        label->setText(QApplication::translate("ActionWithGenre", "\320\226\320\260\320\275\321\200", nullptr));
        lineEdit_name->setPlaceholderText(QApplication::translate("ActionWithGenre", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\266\320\260\320\275\321\200\320\260*", nullptr));
        lineEdit_description->setPlaceholderText(QApplication::translate("ActionWithGenre", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\266\320\260\320\275\321\200\320\260", nullptr));
        pushButton_add->setText(QApplication::translate("ActionWithGenre", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_close->setText(QApplication::translate("ActionWithGenre", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ActionWithGenre", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\266\320\260\320\275\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ActionWithGenre", "\320\226\320\260\320\275\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ActionWithGenre", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\266\320\260\320\275\321\200\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ActionWithGenre", "\320\222\321\201\320\265 \320\266\320\260\320\275\321\200\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActionWithGenre: public Ui_ActionWithGenre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONWITHGENRE_H
