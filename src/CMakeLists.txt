
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME}
	Qt5::Widgets
	Qt5::Qml
	Qt5::Quick
	Qt5::QuickControls2
	Threads::Threads
	${Boost_LIBRARIES}
	)


target_include_directories(${PROJECT_NAME} PRIVATE
	)

add_custom_target(run
	${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
	DEPENDS ${PROJECT_NAME}
	USES_TERMINAL)

add_custom_target(gdb
	gdb --directory=${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	DEPENDS ${PROJECT_NAME}
	USES_TERMINAL
	)

add_custom_target(cgdb
	cgdb -- --directory=${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
	DEPENDS ${PROJECT_NAME}
	USES_TERMINAL
	)

add_custom_target(gdbgui
	nemiver -- --directory=${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
	DEPENDS ${PROJECT_NAME}
	USES_TERMINAL
	)

file(GLOB_RECURSE QML_FILES
	FOLLOW_SYMLINKS
	LIST_DIRECTORIES false
	*.qml)

add_subdirectory(qml)

