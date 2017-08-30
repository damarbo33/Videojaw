#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_64-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/cmdutils.o \
	${OBJECTDIR}/ffplay.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-fpermissive
CXXFLAGS=-fpermissive

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../ExternalLibs/SDL2-2.0.5/x86_64-w64-mingw32/lib -L../../ExternalLibs/ffmpeg/lib -lmingw32 -lSDL2main -lSDL2 -lavutil -lavformat -lavcodec -lswscale -lswresample

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/videojaw.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/videojaw.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/videojaw ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/cmdutils.o: cmdutils.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../ExternalLibs/ffmpeg/include -I../../ExternalLibs/SDL2-2.0.5/x86_64-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cmdutils.o cmdutils.c

${OBJECTDIR}/ffplay.o: ffplay.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../ExternalLibs/ffmpeg/include -I../../ExternalLibs/SDL2-2.0.5/x86_64-w64-mingw32/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ffplay.o ffplay.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
