/********************************************************************************
** Form generated from reading UI file 'finalgraphicswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALGRAPHICSWINDOW_H
#define UI_FINALGRAPHICSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_GraphicsWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *drawArea;

    void setupUi(QDialog *GraphicsWindow)
    {
        if (GraphicsWindow->objectName().isEmpty())
            GraphicsWindow->setObjectName("GraphicsWindow");
        GraphicsWindow->resize(800, 600);
        horizontalLayout = new QHBoxLayout(GraphicsWindow);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        drawArea = new QLabel(GraphicsWindow);
        drawArea->setObjectName("drawArea");
        drawArea->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(drawArea->sizePolicy().hasHeightForWidth());
        drawArea->setSizePolicy(sizePolicy);
        drawArea->setScaledContents(true);

        horizontalLayout->addWidget(drawArea);


        retranslateUi(GraphicsWindow);

        QMetaObject::connectSlotsByName(GraphicsWindow);
    } // setupUi

    void retranslateUi(QDialog *GraphicsWindow)
    {
        GraphicsWindow->setWindowTitle(QCoreApplication::translate("GraphicsWindow", "GraphicsWindow", nullptr));
        drawArea->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GraphicsWindow: public Ui_GraphicsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALGRAPHICSWINDOW_H
