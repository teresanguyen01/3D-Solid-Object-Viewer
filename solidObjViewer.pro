QT       += core gui widgets

TARGET   = solidObjViewer

TEMPLATE = app

CONFIG   += console

HEADERS  += finalgraphics.h finalgraphicswindow.h \
    structPoly_classSolid.h classVertex.h

SOURCES  += solidObjViewer.cpp finalgraphics.cpp finalgraphicswindow.cpp \
    classVertex.cpp \
    finalproj_part2_Nguyen_Teresa.cpp

FORMS    += finalgraphicswindow.ui
