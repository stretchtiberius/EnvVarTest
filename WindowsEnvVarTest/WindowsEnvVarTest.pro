TEMPLATE   = app
CONFIG	  += qt warn_on no_keywords console embed_manifest_exe
QT        +=
QT        -= gui
TARGET     = WindowsEnvVarTest
SOURCES	   = main.cpp
HEADERS	   =
LIBS      +=

# Treat warnings as errors
win32:QMAKE_CXXFLAGS += /WX
unix:QMAKE_CXXFLAGS += -Werror

unix {
	OBJECTS_DIR = linux
	DESTDIR = linux
	MOC_DIR = linux
	RCC_DIR = linux
}
CONFIG(debug, debug|release){
	# Debug build options
}
else{
	# Release build options
}