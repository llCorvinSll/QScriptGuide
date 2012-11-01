QT += core gui script
CONFIG += uitools
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 contains(QT_CONFIG, scripttools): QT += scripttools
