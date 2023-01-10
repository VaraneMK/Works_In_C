/********************************************************************************
** Form generated from reading UI file 'dialogforreview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFORREVIEW_H
#define UI_DIALOGFORREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogForReview
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_reviewsInfo;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_estimation;
    QLineEdit *lineEdit_review;
    QPushButton *pushButton_add;
    QPushButton *pushButton_close;

    void setupUi(QDialog *DialogForReview)
    {
        if (DialogForReview->objectName().isEmpty())
            DialogForReview->setObjectName(QString::fromUtf8("DialogForReview"));
        DialogForReview->resize(306, 381);
        QFont font;
        font.setPointSize(12);
        DialogForReview->setFont(font);
        verticalLayoutWidget = new QWidget(DialogForReview);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 301, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_reviewsInfo = new QLabel(verticalLayoutWidget);
        label_reviewsInfo->setObjectName(QString::fromUtf8("label_reviewsInfo"));
        label_reviewsInfo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_reviewsInfo);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        spinBox_estimation = new QSpinBox(verticalLayoutWidget);
        spinBox_estimation->setObjectName(QString::fromUtf8("spinBox_estimation"));
        spinBox_estimation->setAlignment(Qt::AlignCenter);
        spinBox_estimation->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_estimation->setMaximum(10);

        verticalLayout_2->addWidget(spinBox_estimation);


        verticalLayout->addLayout(verticalLayout_2);

        lineEdit_review = new QLineEdit(verticalLayoutWidget);
        lineEdit_review->setObjectName(QString::fromUtf8("lineEdit_review"));

        verticalLayout->addWidget(lineEdit_review);

        pushButton_add = new QPushButton(verticalLayoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);

        pushButton_close = new QPushButton(verticalLayoutWidget);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));

        verticalLayout->addWidget(pushButton_close);


        retranslateUi(DialogForReview);

        QMetaObject::connectSlotsByName(DialogForReview);
    } // setupUi

    void retranslateUi(QDialog *DialogForReview)
    {
        DialogForReview->setWindowTitle(QApplication::translate("DialogForReview", "Dialog", nullptr));
        label_reviewsInfo->setText(QApplication::translate("DialogForReview", "\320\236\321\202\320\267\321\213\320\262", nullptr));
        label_2->setText(QApplication::translate("DialogForReview", "\320\222\320\260\321\210\320\260 \320\276\321\206\320\265\320\275\320\272\320\260(0-10)", nullptr));
        lineEdit_review->setPlaceholderText(QApplication::translate("DialogForReview", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\267\321\213\320\262", nullptr));
        pushButton_add->setText(QApplication::translate("DialogForReview", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_close->setText(QApplication::translate("DialogForReview", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogForReview: public Ui_DialogForReview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFORREVIEW_H
