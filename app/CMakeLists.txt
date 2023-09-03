cmake_minimum_required(VERSION 3.0..3.24)
project(pencil2d)
add_executable(${PROJECT_NAME})

find_package(Qt5 COMPONENTS Core Widgets Gui Xml Multimedia Svg Network)

target_sources(${PROJECT_NAME} PRIVATE
    aboutdialog.cpp
    aboutdialog.h
    main.cpp
    pencil2d.cpp
    pencil2d.h)

target_sources(${PROJECT_NAME} PRIVATE
    ui/aboutdialog.ui
    ui/bucketoptionswidget.ui
    ui/cameraoptionswidget.ui
    ui/camerapropertiesdialog.ui
    ui/colorinspector.ui
    ui/colorpalette.ui
    ui/doubleprogressdialog.ui
    ui/errordialog.ui
    ui/exportimageoptions.ui
    ui/exportmovieoptions.ui
    ui/filespage.ui
    ui/generalpage.ui
    ui/importexportdialog.ui
    ui/importimageseqoptions.ui
    ui/importimageseqpreview.ui
    ui/importlayersdialog.ui
    ui/importpositiondialog.ui
    ui/layeropacitydialog.ui
    ui/mainwindow2.ui
    ui/onionskin.ui
    ui/pegbaralignmentdialog.ui
    ui/preferencesdialog.ui
    ui/presetdialog.ui
    ui/repositionframesdialog.ui
    ui/shortcutspage.ui
    ui/timelinepage.ui
    ui/toolboxwidget.ui
    ui/tooloptions.ui
    ui/toolspage.ui)

target_link_libraries(${PROJECT_NAME} PRIVATE
Qt5::Core
Qt5::Widgets
Qt5::Gui
Qt5::Xml
Qt5::Multimedia
Qt5::Svg
Qt5::Network)