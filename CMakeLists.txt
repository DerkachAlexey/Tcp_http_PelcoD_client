cmake_minimum_required (VERSION 3.12)

project( PZT_tcp_client)

set( SRC main.cpp
	 PelcoD.hpp
	 PelcoD.cpp
	 TcpClient.hpp
	 TcpClient.cpp)

link_directories($ENV{Boost_LIBRARIES})
add_executable( ${CMAKE_PROJECT_NAME} ${SRC})


  
include_directories( $ENV{Boost_INCLUDE_DIRS} )
   
target_link_libraries( PZT_tcp_client  )

