/********************************************************************************
** Form generated from reading UI file 'dialog_brush.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_BRUSH_H
#define UI_DIALOG_BRUSH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_brush
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton_ok;
    QPushButton *pushbutton_cancel;
    QLabel *label_2;

    void setupUi(QDialog *Dialog_brush)
    {
        if (Dialog_brush->objectName().isEmpty())
            Dialog_brush->setObjectName(QString::fromUtf8("Dialog_brush"));
        Dialog_brush->resize(211, 196);
        pushButton = new QPushButton(Dialog_brush);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 70, 171, 21));
        label = new QLabel(Dialog_brush);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 100, 51, 21));
        comboBox = new QComboBox(Dialog_brush);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 100, 131, 22));
        pushButton_ok = new QPushButton(Dialog_brush);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(60, 150, 61, 21));
        pushbutton_cancel = new QPushButton(Dialog_brush);
        pushbutton_cancel->setObjectName(QString::fromUtf8("pushbutton_cancel"));
        pushbutton_cancel->setGeometry(QRect(130, 150, 61, 21));
        label_2 = new QLabel(Dialog_brush);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 10, 151, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Narrow"));
        font.setPointSize(14);
        label_2->setFont(font);

        retranslateUi(Dialog_brush);

        QMetaObject::connectSlotsByName(Dialog_brush);
    } // setupUi

    void retranslateUi(QDialog *Dialog_brush)
    {
        Dialog_brush->setWindowTitle(QCoreApplication::translate("Dialog_brush", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog_brush", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label->setText(QCoreApplication::translate("Dialog_brush", "\320\241\321\202\320\270\320\273\321\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Dialog_brush", "\320\221\320\265\320\267 \320\267\320\260\320\273\320\270\320\262\320\272\320\270", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Dialog_brush", "\320\236\320\261\321\213\321\207\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Dialog_brush", "\320\237\320\273\320\276\321\202\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 1", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Dialog_brush", "\320\237\320\273\320\276\321\202\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 2", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Dialog_brush", "\320\237\320\273\320\276\321\202\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 3", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Dialog_brush", "\320\237\320\273\320\276\321\202\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 4", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Dialog_brush", "\320\237\320\273\320\276\321\202\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 5", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("Dialog_brush", "\320\237\320\273\320\276\321\202\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 6", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("Dialog_brush", "\320\237\320\273\320\276\321\202\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 7", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("Dialog_brush", "\320\223\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("Dialog_brush", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("Dialog_brush", "\320\232\320\273\320\265\321\202\320\276\321\207\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("Dialog_brush", "\320\224\320\270\320\260\320\263\320\276\320\273\321\214\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 1", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("Dialog_brush", "\320\224\320\270\320\260\320\263\320\276\320\273\321\214\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 2", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("Dialog_brush", "\320\224\320\270\320\260\320\263\320\276\320\273\321\214\320\275\320\260\321\217 \320\267\320\260\320\273\320\270\320\262\320\272\320\260 3", nullptr));

        pushButton_ok->setText(QCoreApplication::translate("Dialog_brush", "OK", nullptr));
        pushbutton_cancel->setText(QCoreApplication::translate("Dialog_brush", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_brush", "\320\227\320\220\320\233\320\230\320\222\320\232\320\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_brush: public Ui_Dialog_brush {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_BRUSH_H
