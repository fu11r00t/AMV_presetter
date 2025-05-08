QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/gui/widgets/videomeasurementwidget.cpp \
    src/main.cpp \
    src/gui/mainwindow.cpp

RESOURCES += \
    resources/styles.qrc

HEADERS += \
#    include/gui/widgets/*.h \
#    include/gui/dialogs/*.h \
    include/gui/mainwindow.h \
    include/gui/widgets/videomeasurementwidget.h
#    include/data/*.h \
#    include/core/*.h

#FORMS += \
#    mainwindow.ui

TRANSLATIONS += \
    AMV_presetter_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations
RC_ICONS = resources/icons/amv_logo.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
INCLUDEPATH += "C:/opencv/build/include"
LIBS += -L"C:/opencv/build/x64/vc16/lib" \
        -lopencv_world4110
