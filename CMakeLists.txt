#
# Nicholas Yue nicholas_yue@users.sourceforge.net
#
# Note:
# (1) OBE
# (2) Default installation directory is /usr/local, override with -DCMAKE_INSTALL_PREFIX="" during cmake
#     invocation
# (3) Do the usual "make clean all" to build the library
# (4) To install either "make install" or "make install DESTDIR=<your directory>"

cmake_minimum_required( VERSION 3.11 FATAL_ERROR )
set( CMAKE_LEGACY_CYGWIN_WIN32 0 )
cmake_policy( SET CMP0048 NEW )

project( LOG4CPP )

find_package( Threads )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_EXTENSIONS OFF )

if (WIN32)
  add_definitions ( -D_CRT_SECURE_NO_WARNINGS )
endif (WIN32)

if ( CMAKE_BUILD_TYPE MATCHES "Debug" )
  set ( LOG4CPP_LIBRARY_NAME "log4cppD" )
else ( CMAKE_BUILD_TYPE MATCHES "Debug" )
  set ( LOG4CPP_LIBRARY_NAME "log4cpp" )
endif ( CMAKE_BUILD_TYPE MATCHES "Debug" )

add_library ( ${LOG4CPP_LIBRARY_NAME}
  src/Appender.cpp
  src/AppenderSkeleton.cpp
  src/AppendersFactory.cpp
  src/BufferingAppender.cpp
  src/FactoryParams.cpp
  src/LayoutsFactory.cpp
  src/LevelEvaluator.cpp
  src/Localtime.cpp
  src/PassThroughLayout.cpp
  src/TriggeringEventEvaluatorFactory.cpp
  src/LayoutAppender.cpp
  src/FileAppender.cpp
  src/DailyRollingFileAppender.cpp
  src/RollingFileAppender.cpp
  src/FixedContextCategory.cpp
  src/IdsaAppender.cpp
  src/OstreamAppender.cpp
  src/StringQueueAppender.cpp
  src/SyslogAppender.cpp
  src/RemoteSyslogAppender.cpp
  src/SimpleLayout.cpp
  src/BasicLayout.cpp
  src/PatternLayout.cpp
  src/Category.cpp
  src/CategoryStream.cpp
  src/HierarchyMaintainer.cpp
  src/Configurator.cpp
  src/BasicConfigurator.cpp
  src/SimpleConfigurator.cpp
  src/PropertyConfigurator.cpp
  src/PropertyConfiguratorImpl.cpp
  src/LoggingEvent.cpp
  src/Priority.cpp
  src/NDC.cpp
  src/Filter.cpp
  src/TimeStamp.cpp
  src/StringUtil.cpp
  src/Properties.cpp
  src/Win32DebugAppender.cpp
  src/NTEventLogAppender.cpp
  src/DllMain.cpp
  src/DummyThreads.cpp
  src/MSThreads.cpp
  src/OmniThreads.cpp
  src/PThreads.cpp
  src/AbortAppender.cpp
)

target_include_directories( ${LOG4CPP_LIBRARY_NAME} PUBLIC include )


target_link_libraries( ${LOG4CPP_LIBRARY_NAME} Threads::Threads )

if (WIN32)
  target_link_libraries (${LOG4CPP_LIBRARY_NAME} kernel32 user32 ws2_32 advapi32 )
  set_target_properties(${LOG4CPP_LIBRARY_NAME} PROPERTIES LINK_FLAGS /NODEFAULTLIB:msvcrt )
endif (WIN32)

install (
  DIRECTORY include/log4cpp
  DESTINATION include
  PATTERN "config.h" EXCLUDE
  PATTERN ".svn" EXCLUDE
  PATTERN "*.am" EXCLUDE
  PATTERN "*.in" EXCLUDE
  )

install (
  TARGETS ${LOG4CPP_LIBRARY_NAME}
  LIBRARY
  )
