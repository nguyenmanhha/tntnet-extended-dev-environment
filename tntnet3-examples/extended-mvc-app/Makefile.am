ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = subdir-objects

# auto-scan for sources and static resources
SRC_PATH := src/
PUBLIC_ASSETS_PATH := $(SRC_PATH)public/

# these seprate scans allow for more flexibility
APP_ECPP_SRC_MODELS := $(shell find $(SRC_PATH)app/models/ -iname '*.ecpp')
APP_ECPP_SRC_VIEWS := $(shell find $(SRC_PATH)app/views/ -iname '*.ecpp')
APP_ECPP_SRC_CONTROLLERS := $(shell find $(SRC_PATH)app/controllers/ -iname '*.ecpp')

APP_ECPP_SRC_ACTIONS := $(shell find $(SRC_PATH)app/actions/ -iname '*.ecpp')
APP_ECPP_SRC_JSONS := $(shell find $(SRC_PATH)app/jsons/ -iname '*.ecpp')
APP_ECPP_SRC_HTMLS := $(shell find $(SRC_PATH)app/htmls/ -iname '*.ecpp')

# APP_SRC := $(shell find $(SRC_PATH) -iname '*.cpp')
# APP_HEADRS := $(shell find $(SRC_PATH) -iname '*.h')

# APP_PUBLIC_ASSETS_JS := $(shell find $(PUBLIC_ASSETS_PATH) -iname '*.js')
# APP_PUBLIC_ASSETS_CSS := $(shell find $(PUBLIC_ASSETS_PATH) -iname '*.css')
# APP_PUBLIC_ASSETS_IMG := $(shell find $(PUBLIC_ASSETS_PATH) -iname '*.png' -o -iname '*.jpg' -o -iname '*.jpeg' -o -iname '*ico')
# APP_PUBLIC_ASSETS := $(APP_PUBLIC_ASSETS_JS) $(APP_PUBLIC_ASSETS_CSS) $(APP_PUBLIC_ASSETS_IMG)

models := \
	$(APP_ECPP_SRC_MODELS)

views := \
	$(APP_ECPP_SRC_VIEWS)

controllers := \
	$(APP_ECPP_SRC_CONTROLLERS)

actions := \
	$(APP_ECPP_SRC_ACTIONS)

bin_PROGRAMS = MyApp

noinst_HEADERS = \
	src/actionreply.h \
	src/action.ecpp \
	src/configuration.h \
	src/noty.h \
	src/session.ecpp \
	$(models)

ecppSources = \
	src/actionmain.ecpp \
	$(APP_ECPP_SRC_JSONS) \
	$(APP_ECPP_SRC_HTMLS) \
	src/webmain.ecpp \
	$(views) \
	$(controllers) \
	$(actions)

notySources =  $(shell find $(PUBLIC_ASSETS_PATH)js/noty/ -iname '*.js')

staticSources := \
	$(notySources) \
	$(PUBLIC_ASSETS_PATH)js/jquery-2.1.4.min.js \
	$(PUBLIC_ASSETS_PATH)js/tntnet.js \
	$(PUBLIC_ASSETS_PATH)mypage.js \
	$(PUBLIC_ASSETS_PATH)MyApp.css

ecppTargets := $(ecppSources:%.ecpp=%.cpp)

nodist_MyApp_SOURCES = \
	src/public.cpp

refresh-sources:
	$(shell echo "MyApp_SOURCES:= src/main.cpp src/configuration.cpp $(ecppTargets)" > sources.lst)

wsrun: all

MyApp_LDADD = -lcxxtools -ltntnet

nobase_dist_noinst_DATA = $(staticSources)

CLEANFILES := $(ecppTargets)  $(ecppSources:.ecpp=.deps) src/public.cpp

EXTRA_DIST = $(staticSources)

#
# Rules for tntnet applications
#
ECPPFLAGS=-I$(srcdir)/src

SUFFIXES=.ecpp .cpp

# public
src/public.cpp: $(staticSources)
	$(AM_V_GEN)$(ECPPC) -bb -z -n public -p -o src/public.cpp $(ECPPFLAGS) $(staticSources)

.ecpp.cpp:
	$(AM_V_GEN)$(ECPPC) -n `echo $<|$(SED) 's|^$(srcdir)/||; s|\.ecpp$$||'` $(ECPPFLAGS) -o $@ $<

.ecpp.deps:
	$(AM_V_GEN)$(ECPPC) -M $(ECPPFLAGS) $< | $(SED) '1s|\(.*\).cpp:|\1.cpp $@:|' > $@


-include $(ecppSources:.ecpp=.deps)
include  sources.lst
