TARGET       = hybrisorientationadaptor

HEADERS += hybrisorientationadaptor.h \
           hybrisorientationadaptorplugin.h

SOURCES += hybrisorientationadaptor.cpp \
           hybrisorientationadaptorplugin.cpp

LIBS+= -L../../core -lhybrissensorfw-qt5

include( ../adaptor-config.pri )
config_hybris {
    PKGCONFIG += android-headers
}
