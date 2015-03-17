TEMPLATE = app
SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

#LIBS
unix:LIBS += -L"/usr/local/lib"
win32:LIBS += -L"C:/sfml-2.2/lib/"

# Include
unix:INCLUDEPATH += "/usr/local/include"
win32:INCLUDEPATH += "C:/sfml-2.2/include/"

#CONFIG(debug, debug|release): LIBS += -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-network-d -lsfml-system-d
CONFIG(debug, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
