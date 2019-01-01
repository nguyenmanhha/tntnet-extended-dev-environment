# this makefile auto-scans the folders below mentioned folders and compiles on changes. see "dev" file

all:webserver

wsrun: all
	webserver

CT = app/controllers/
MT = app/models/
VT = app/views/

V_SOURCES := $(shell find $(VT) -name 'v_*.ecpp')
C_SOURCES := $(shell find $(CT) -name 'c_*.ecpp')
C_SOURCES2 := $(shell find $(CT) -name 'c_*.cpp')
M_SOURCES := $(shell find $(MT) -name 'm_*.cpp')

VS = $(V_SOURCES:%.ecpp=%.o)
CS = $(C_SOURCES:%.ecpp=%.o) $(C_SOURCES2:%.cpp=%.o)
MS = $(M_SOURCES:%.cpp=%.o)

# example to add more object-files, remove first line to use it
LS = ""
# LS = lib/model_sqldb_adapter.o lib/model_mongodb_adapter.o

COMPS = webserver.o $(LS) $(VS) $(CS) $(MS)

webserver: $(COMPS)
	${CXX} -o $@ $^  ${LDFLAGS}

.SUFFIXES: .ecpp .gif .jpg .css .js .cpp
ECPPC=/usr/bin/ecppc
CXXFLAGS+=-I/usr/include -Ilib/ -Iapp/models -fPIC -O2 -g -std=c++11 -std=gnu++11
LDFLAGS+= -L/usr/local/lib -ltntnet  -L/usr/lib -ltntdb -lcxxtools

.ecpp.cpp:
	${ECPPC} ${ECPPFLAGS} ${ECPPFLAGS_CPP} -o $@ $<

.gif.cpp:
	${ECPPC} ${ECPPFLAGS} -m image/gif ${ECPPFLAGS_GIF} -b -o $@ $<
.jpg.cpp:
	${ECPPC} ${ECPPFLAGS} -m image/jpg ${ECPPFLAGS_JPG} -b -o $@ $<
.png.cpp:
	${ECPPC} ${ECPPFLAGS} -m image/png ${ECPPFLAGS_PNG} -b -o $@ $<
.ico.cpp:
	${ECPPC} ${ECPPFLAGS} -m image/x-icon ${ECPPFLAGS_ICO} -b -o $@ $<
.css.cpp:
	${ECPPC} ${ECPPFLAGS} -m text/css ${ECPPFLAGS_CSS} -b -o $@ $<
.js.cpp:
	${ECPPC} ${ECPPFLAGS} -m application/javascript ${ECPPFLAGS_JS} -b -o $@ $<
