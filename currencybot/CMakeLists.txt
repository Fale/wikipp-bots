cmake_minimum_required ( VERSION 2.6 )
project ( currencybot )

set( BUILD_SHARED_LIBS ON )

SET( Boost_USE_STATIC_LIBS OFF )
SET( Boost_USE_MULTITHREAD ON )
FIND_PACKAGE( Boost 1.36 COMPONENTS date_time regex system )

set( CMAKE_THREAD_LIBS_INIT )
add_definitions( -Wall -O3 )

link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

find_path( wikipp_include_dir
NAMES wiki++
PATHS /usr/local/include
/usr/include
)

include_directories ( ${wikipp_include_dir} )
if ( !build_global )
  find_library( wikipp_extended_currency
    NAMES libwikipp_extended_currency.so
    PATHS /usr/local/lib
          /usr/lib
  )
  find_library( wikipp_libs_prgdata
  NAMES libwikipp_libs_prgdata.so
  PATHS /usr/local/lib
  /usr/lib
  )
  find_library( wikipp_wiki_login
  NAMES libwikipp_wiki_login.so
  PATHS /usr/local/lib
  /usr/lib
  )
  find_library( wikipp_wiki_write
  NAMES libwikipp_wiki_write.so
  PATHS /usr/local/lib
  /usr/lib
  )
endif()

add_executable ( currencybot main.cpp )

install( TARGETS currencybot
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static )

target_link_libraries ( currencybot wikipp_extended_currency wikipp_libs_prgdata wikipp_wiki_login wikipp_wiki_write )