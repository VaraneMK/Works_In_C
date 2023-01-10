/********************************************************************************
** Form generated from reading UI file 'actionwithmovie.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONWITHMOVIE_H
#define UI_ACTIONWITHMOVIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionWithMovie
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_info;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_genre;
    QLabel *label_ageLimit;
    QSpinBox *spinBox_ageLimit;
    QLabel *label_duration;
    QSpinBox *spinBox_duration;
    QLineEdit *lineEdit_cast;
    QPushButton *pushButton_add;
    QPushButton *pushButton_close;
    QWidget *tab_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ActionWithMovie)
    {
        if (ActionWithMovie->objectName().isEmpty())
            ActionWithMovie->setObjectName(QString::fromUtf8("ActionWithMovie"));
        ActionWithMovie->resize(422, 449);
        QFont font;
        font.setPointSize(12);
        ActionWithMovie->setFont(font);
        tabWidget = new QTabWidget(ActionWithMovie);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 401, 441));
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
        label_info->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_info);

        lineEdit_name = new QLineEdit(verticalLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout->addWidget(lineEdit_name);

        comboBox_genre = new QComboBox(verticalLayoutWidget);
        comboBox_genre->addItem(QString());
        comboBox_genre->setObjectName(QString::fromUtf8("comboBox_genre"));

        verticalLayout->addWidget(comboBox_genre);

        label_ageLimit = new QLabel(verticalLayoutWidget);
        label_ageLimit->setObjectName(QString::fromUtf8("label_ageLimit"));
        label_ageLimit->setMaximumSize(QSize(16777215, 16));
        label_ageLimit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_ageLimit);

        spinBox_ageLimit = new QSpinBox(verticalLayoutWidget);
        spinBox_ageLimit->setObjectName(QString::fromUtf8("spinBox_ageLimit"));
        spinBox_ageLimit->setAlignment(Qt::AlignCenter);
        spinBox_ageLimit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ageLimit->setMaximum(18);

        verticalLayout->addWidget(spinBox_ageLimit);

        label_duration = new QLabel(verticalLayoutWidget);
        label_duration->setObjectName(QString::fromUtf8("label_duration"));
        label_duration->setMaximumSize(QSize(16777215, 16));
        label_duration->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_duration);

        spinBox_duration = new QSpinBox(verticalLayoutWidget);
        spinBox_duration->setObjectName(QString::fromUtf8("spinBox_duration"));
        spinBox_duration->setAlignment(Qt::AlignCenter);
        spinBox_duration->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_duration->setMaximum(500);

        verticalLayout->addWidget(spinBox_duration);

        lineEdit_cast = new QLineEdit(verticalLayoutWidget);
        lineEdit_cast->setObjectName(QString::fromUtf8("lineEdit_cast"));

        verticalLayout->addWidget(lineEdit_cast);

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
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 401, 411));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(ActionWithMovie);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ActionWithMovie);
    } // setupUi

    void retranslateUi(QDialog *ActionWithMovie)
    {
        ActionWithMovie->setWindowTitle(QApplication::translate("ActionWithMovie", "Dialog", nullptr));
        label_info->setText(QApplication::translate("ActionWithMovie", "\320\244\320\270\320\273\321\214\320\274", nullptr));
        lineEdit_name->setPlaceholderText(QApplication::translate("ActionWithMovie", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\270\320\273\321\214\320\274\320\260", nullptr));
        comboBox_genre->setItemText(0, QApplication::translate("ActionWithMovie", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\266\320\260\320\275\321\200", nullptr));

        label_ageLimit->setText(QApplication::translate("ActionWithMovie", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202\320\275\320\276\320\265 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_duration->setText(QApplication::translate("ActionWithMovie", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        lineEdit_cast->setPlaceholderText(QApplication::translate("ActionWithMovie", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\260\320\272\321\202\320\265\321\200\321\201\320\272\320\270\320\271 \321\201\320\276\321\201\321\202\320\260\320\262", nullptr));
        pushButton_add->setText(QApplication::translate("ActionWithMovie", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_close->setText(QApplication::translate("ActionWithMovie", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ActionWithMovie", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ActionWithMovie", "\320\244\320\270\320\273\321\214\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ActionWithMovie", "\320\226\320\260\320\275\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ActionWithMovie", "\320\222\320\276\320\267\321\200.\320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ActionWithMovie", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ActionWithMovie", "\320\222\321\201\320\265 \321\204\320\270\320\273\321\214\320\274\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActionWithMovie: public Ui_ActionWithMovie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONWITHMOVIE_H
