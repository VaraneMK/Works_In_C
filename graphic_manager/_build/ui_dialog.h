/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_st;
    QComboBox *comboBox;
    QPushButton *pushbutton_color;
    QSlider *horizontalSlider;
    QLabel *label_w;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(229, 232);
        QFont font;
        font.setPointSize(8);
        Dialog->setFont(font);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-150, 190, 341, 32));
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_st = new QLabel(Dialog);
        label_st->setObjectName(QString::fromUtf8("label_st"));
        label_st->setGeometry(QRect(20, 90, 41, 21));
        comboBox = new QComboBox(Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 90, 131, 22));
        comboBox->setFont(font);
        pushbutton_color = new QPushButton(Dialog);
        pushbutton_color->setObjectName(QString::fromUtf8("pushbutton_color"));
        pushbutton_color->setGeometry(QRect(20, 60, 171, 21));
        horizontalSlider = new QSlider(Dialog);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 140, 171, 16));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(25);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_w = new QLabel(Dialog);
        label_w->setObjectName(QString::fromUtf8("label_w"));
        label_w->setGeometry(QRect(100, 150, 41, 21));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 150, 16, 21));
        QFont font1;
        font1.setPointSize(11);
        label->setFont(font1);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 150, 16, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 120, 121, 16));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 10, 161, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Narrow"));
        font2.setPointSize(14);
        label_4->setFont(font2);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_st->setText(QCoreApplication::translate("Dialog", "\320\241\321\202\320\270\320\273\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Dialog", "\320\221\320\265\320\267 \320\273\320\270\320\275\320\270\320\270", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Dialog", "\320\241\320\277\320\273\320\276\321\210\320\275\320\260\321\217", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Dialog", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Dialog", "\320\250\321\202\321\200\320\270\321\205", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Dialog", "\320\250\321\202\321\200\320\270\321\205-\320\277\321\203\320\275\320\272\321\202\320\270\321\200", nullptr));

        pushbutton_color->setText(QCoreApplication::translate("Dialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label_w->setText(QString());
        label->setText(QCoreApplication::translate("Dialog", "1", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "25", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\272\320\260\321\200\320\260\320\275\320\264\320\260\321\210\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\320\232\320\220\320\240\320\220\320\235\320\224\320\220\320\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
