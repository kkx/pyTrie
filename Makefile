# location of the Python header files

PYTHON = /usr/include/python2.6/

# location of the Boost Python include files and library

BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

# compile mesh classes
TARGET = trieClasses

$(TARGET).so: $(TARGET).o
	g++ -shared -Wl,--export-dynamic \
	$(TARGET).o -L$(BOOST_LIB) -lboost_python \
	-L/usr/lib/python2.6/config -lpython2.6 \
	-o $(TARGET).so

$(TARGET).o: $(TARGET).C
	g++ -I$(PYTHON) -I$(BOOST_INC) -c $(TARGET).C

