cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
set(TARGET_NAME libdxfrw)
project(${TARGET_NAME})

add_definitions(-D DXF_EXPORT)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${TARGET_NAME} LANGUAGES CXX)

set(libdxfrw_sources ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(libdxfrw_intern_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/intern)


file(GLOB SOURCES 
	${libdxfrw_sources}/*.cpp
	${libdxfrw_intern_sources}/*.cpp
	)

file(GLOB HEADERS 	
	${libdxfrw_sources}/*.h
	${libdxfrw_intern_sources}/*.h
	)
file(GLOB EXHEADERS 	
	${libdxfrw_sources}/drw_base.h
	${libdxfrw_sources}/drw_classes.h
	${libdxfrw_sources}/drw_config.h
	${libdxfrw_sources}/drw_entities.h
	${libdxfrw_sources}/drw_header.h
	${libdxfrw_sources}/drw_interface.h
	${libdxfrw_sources}/drw_objects.h
	${libdxfrw_sources}/libdwgr.h
	${libdxfrw_sources}/libdxfrw.h
	)
	

add_library(${TARGET_NAME} SHARED ${SOURCES} ${HEADERS})
#add_library(dxfrw STATIC ${libdxfrw_sources} ${libdxfrw_intern_sources})

#install(FILES ${libdxfrw_headers} DESTINATION include)

install(TARGETS ${TARGET_NAME} 
			CONFIGURATIONS Debug
			RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/export/${TARGET_NAME}/dll/Debug
			)
			
install(TARGETS ${TARGET_NAME} 
			CONFIGURATIONS Release
			RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/export/${TARGET_NAME}/dll/Release 
			)
			
#install(TARGETS ${TARGET_NAME} 
#			CONFIGURATIONS Release
#			LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/export/${TARGET_NAME}/lib/Release
#			)

install(FILES ${EXHEADERS} DESTINATION ${PROJECT_BINARY_DIR}/export/${TARGET_NAME}/include)

#message("==================${PROJECT_BINARY_DIR}")
#add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
#	"$<TARGET_FILE_DIR:${TARGET_NAME}>/${TARGET_NAME}.dll" "${PROJECT_BINARY_DIR}/export/${TARGET_NAME}/dll/$<CONFIG>/${TARGET_NAME}.dll" ) 

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
	"$<TARGET_FILE_DIR:${TARGET_NAME}>/${TARGET_NAME}.lib" "${PROJECT_BINARY_DIR}/export/${TARGET_NAME}/lib/$<CONFIG>/${TARGET_NAME}.lib" ) 

#foreach(header ${HEADERS})
#	STRING(REGEX REPLACE ".+/(.+)\\.*" "\\1" FILE_NAME ${header})  
#	add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
#		"${header}" "${PROJECT_BINARY_DIR}/export/include/${TARGET_NAME}/${FILE_NAME}") 

#endforeach()

#if(WIN32)
#  install(TARGETS dxfrw
#          CONFIGURATIONS Debug
#          LIBRARY DESTINATION Debug/lib
#          ARCHIVE DESTINATION Debug/lib)
#  install(TARGETS dxfrw
#          CONFIGURATIONS Release
#          LIBRARY DESTINATION Release/lib
#          ARCHIVE DESTINATION Release/lib)
#else()
#  install(TARGETS dxfrw
#          LIBRARY DESTINATION lib
#          ARCHIVE DESTINATION lib)
#endif()