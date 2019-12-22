include prorab.mk

this_name := tests

this_cxxflags += -std=c++11
this_cxxflags += -Wall
this_cxxflags += -DDEBUG
this_cxxflags += -fstrict-aliasing
this_cxxflags += -O3
this_cxxflags += -fPIC

this_srcs += main.cpp

ifeq ($(os),macosx)
    this_cxxflags += -stdlib=libc++ # this is needed to be able to use c++11 std lib
    this_ldlibs += -lc++
endif


this_ldlibs += -lstdc++

this_no_install := true

$(eval $(prorab-build-app))

include $(d)../test_target.mk

