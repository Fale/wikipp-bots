cmake_minimum_required ( VERSION 2.6 )
project ( indexbot )

set(BUILD_SHARED_LIBS ON)

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE( Boost 1.36 COMPONENTS date_time regex system)

set( CMAKE_THREAD_LIBS_INIT )
add_definitions( -Wall -O3 )

link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

# Include dir
find_path( Wikipp_INCLUDE_DIR
  NAMES wiki++
  PATHS /usr/local/include
        /usr/include
)

# Finally the library itself
find_library( Wikipp_LIBRARY
  NAMES libwikipp_extended_currency.so
  PATHS /usr/local/lib
        /usr/lib
)

link_directories ( ${Wikipp_LIBRARY} )
include_directories( ${Wikipp_INCLUDE_DIR} )

add_executable ( indexbot main.cpp )

install( TARGETS indexbot
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static )

target_link_libraries ( indexbot libwikipp_extended_index.so libwikipp_libs_dati.so libwikipp_libs_prgdata.so libwikipp_wiki_login.so libwikipp_wiki_write.so )