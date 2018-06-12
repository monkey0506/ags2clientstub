# Makefile for AGSteam
#
# define some paths...
PATH_SRC=.
PATH_BUILD=$(PATH_SRC)/build
SRCS=ags2client/IAGS2Client.cpp ags2client/IClientAchievements.cpp ags2client/IClientLeaderboards.cpp \
	ags2client/IClientStats.cpp ags2client/main.cpp AchievementsStub.cpp AGS2Client.cpp AGS2ClientStub.cpp \
	LeaderboardsStub.cpp StatsStub.cpp
# .o object files for ags2client end up in a separate directory, but this is fine
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
CXXFLAGS=-g -Wall -std=c++11 -O2 -fPIC

# define some functions to help build other needed paths

# get path to the ignored "build" folder's platform subdirectory (e.g., ./build/osx)
# requires 1 arg, platform to build (e.g., osx)
define platform_build_path
$(PATH_BUILD)/$1
endef

# get path to platform-specific object folder (e.g., ./build/osx/obj)
# requires 1 arg, specifies platform (e.g., osx)
define platform_obj_path
$(call platform_build_path,$1)/obj
endef

# get object file path names (e.g., ./build/osx/obj/ags2client/IAGS2Client.o) for all object files
# requires 1 arg, specifies platform (e.g., osx)
define obj_file_paths
$(patsubst %,$(call platform_obj_path,$1)/%,$(OBJS))
endef

# template to build a specific platform
# requires 1 arg, platform to build (e.g., osx)
# requires additional variables to be predefined if expected as non-empty:
# 	* [PLATFORM]_CXX_FLAGS: additional C++ flags for making object files (e.g., -DMAC_VERSION)
# 	* [PLATFORM]_LIB_FLAGS: linker flags for platform (e.g., "-dynamiclib" should probably be specified here for OS X)
define build_platform

# make uppercase version of platform argument for constructing variables
$(eval VPLAT=$(shell echo $1 | tr '[a-z]' '[A-Z]'))

# construct platform-specific and variant-specific paths
$(eval PATH_$(VPLAT)_BUILD=$(call platform_build_path,$1))
$(eval PATH_$(VPLAT)_OBJ=$(call platform_obj_path,$1))
$(eval $(VPLAT)_OBJ_FILE_PATHS=$(call obj_file_paths,$1))

# rule for building for platform
$1-build: $($(VPLAT)_OBJ_FILE_PATHS)
	g++ $($(VPLAT)_LIB_FLAGS) $($(VPLAT)_OBJ_FILE_PATHS)

# rule for making platform object files
$(PATH_$(VPLAT)_OBJ)/%.o: $(PATH_SRC)/%.cpp
	mkdir -p $(PATH_$(VPLAT)_OBJ)/ags2client
	g++ $(CXXFLAGS) -DAGS2CLIENT_UNIFIED_CLIENT_NAME $($(VPLAT)_CXX_FLAGS) -c $$< -o $$@

# undefine VPLAT, it shouldn't be reused (other platform paths defined above may be reused)
undefine VPLAT

endef


# default rule: do nothing
none:

# clean all platforms
clean: clean-osx clean-linux


# OS X
OSX_CXX_FLAGS=-DMAC_VERSION
OSX_LIB_FLAGS=-dynamiclib -o $(PATH_OSX_BUILD)/libags2clientstub.dylib

osx: osx-build
$(eval $(call build_platform,osx))

clean-osx:
	rm -rf $(PATH_OSX_OBJ) $(PATH_OSX_BUILD)/libags2clientstub.dylib


# Linux (64-bit)
LINUX64_CXX_FLAGS=-DLINUX_VERSION
LINUX64_LIB_FLAGS=-shared -o $(PATH_LINUX64_BUILD)/libags2clientstub.so

linux64: linux64-build
$(eval $(call build_platform,linux64))

clean-linux64:
	rm -rf $(PATH_LINUX64_OBJ) $(PATH_LINUX64_BUILD)/libags2clientstub.so

# Linux (32-bit)
LINUX32_CXX_FLAGS=$(LINUX64_CXX_FLAGS) -m32
LINUX32_LIB_FLAGS=-shared -o $(PATH_LINUX32_BUILD)/libags2clientstub.so -m32

linux32: linux32-build
$(eval $(call build_platform,linux32))

clean-linux32:
	rm -rf $(PATH_LINUX32_OBJ) $(PATH_LINUX32_BUILD)/libags2clientstub.so

# Linux (all)
linux: linux64 linux32

clean-linux: clean-linux64 clean-linux32
