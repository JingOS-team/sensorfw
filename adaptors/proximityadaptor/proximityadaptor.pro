TARGET       = proximityadaptor

HEADERS += proximityadaptor.h \
           proximityadaptorplugin.h

SOURCES += proximityadaptor.cpp \
           proximityadaptorplugin.cpp

include( ../adaptor-config.pri )

mce {
    DEFINES += SENSORFW_MCE_WATCHER
}
