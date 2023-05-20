QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

#handle the design and edit roles
CONFIG += no_designer

QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcity.cpp \
    addmap.cpp \
    addmap_error.cpp \
    addmap_successfully.cpp \
    algorithms.cpp \
    bfs.cpp \
    choosemap.cpp \
    dashboard.cpp \
    defaultcities_path.cpp \
    dfs.cpp \
    displaymapdata.cpp \
    enumerators.cpp \
    error_pathfinder.cpp \
    exitloader.cpp \
    files.cpp \
    fivecities_path.cpp \
    fourcities_path.cpp \
    graph.cpp \
    homepage.cpp \
    main.cpp \
    mini_wasalni_gui.cpp \
    pathfinder_main.cpp \
    sevencities_path.cpp \
    sixcities_path.cpp \
    threecities_path.cpp \
    traverse.cpp \
    twocities_path.cpp \
    update_menu.cpp \
    welcome.cpp

HEADERS += \
    addcity.h \
    addmap.h \
    addmap_error.h \
    addmap_successfully.h \
    algorithms.h \
    bfs.h \
    choosemap.h \
    dashboard.h \
    defaultcities_path.h \
    dfs.h \
    displaymapdata.h \
    error_pathfinder.h \
    exitloader.h \
    files.h \
    fivecities_path.h \
    fourcities_path.h \
    gVariables.h \
    graph.h \
    homepage.h \
    mini_wasalni_gui.h \
    pathfinder_main.h \
    sevencities_path.h \
    sixcities_path.h \
    threecities_path.h \
    traverse.h \
    twocities_path.h \
    update_menu.h \
    welcome.h

FORMS += \
    addcity.ui \
    addmap.ui \
    addmap_error.ui \
    addmap_successfully.ui \
    bfs.ui \
    choosemap.ui \
    dashboard.ui \
    defaultcities_path.ui \
    dfs.ui \
    displaymapdata.ui \
    error_pathfinder.ui \
    exitloader.ui \
    fivecities_path.ui \
    fourcities_path.ui \
    homepage.ui \
    mini_wasalni_gui.ui \
    pathfinder_main.ui \
    sevencities_path.ui \
    sixcities_path.ui \
    threecities_path.ui \
    traverse.ui \
    twocities_path.ui \
    update_menu.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
