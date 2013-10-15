CXX           = g++
CXXFLAGS      = -Wall -fPIC
INCPATH       = -I/opt/Qt/5.1.1/gcc/include -I/opt/Qt/5.1.1/gcc/include/QtCore

LINK          = g++
LIBS          = -lQt5Core
LFLAGS        = -L/opt/Qt/5.1.1/gcc/lib

OBJECTS       = Bike.o \
				Emplacement.o \
				Station.o \
				Controller.o \
				main.o

TARGET        = serialize.run

all: $(TARGET)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) "$<" -o "$@"

$(TARGET): $(OBJECTS)
	$(LINK) $(LFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

clean:
	$(RM) *.o $(TARGET)

