cmake_minimum_required(VERSION 3.9)

if (WIN32)
	list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/3dparty/hunter-packages-gate")
	#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/3dparty/polly")
	#include("mingw-c11")
	include("cmake/HunterGate")

	HunterGate(
		URL "https://github.com/ruslo/hunter/archive/v0.20.13.tar.gz"
		SHA1 "d92042d6e22522516183b86da10e56fb1af73f7a"
	)
endif ()

project(loft)

if (WIN32)
	hunter_add_package(Boost COMPONENTS system filesystem thread log test)
	hunter_add_package(Qt COMPONENTS qtdeclarative qttools qtquickcontrols)
endif ()

enable_testing()

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_MAINTENANCE 0)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_COMMON "-Wextra -Wunused -Weffc++ -Wall --pedantic -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG ${CMAKE_CXX_FLAGS_COMMON}")
set(CMAKE_CXX_FLAGS_DEBUG "-g ${CMAKE_CXX_FLAGS_COMMON}")

find_package(Qt5Widgets)
find_package(Qt5Qml)
find_package(Qt5Quick)
find_package(Qt5QuickControls2)
find_package(Qt5LinguistTools)
find_package(Threads)
find_package(Boost REQUIRED COMPONENTS
	system REQUIRED
	filesystem REQUIRED
	log REQUIRED
	)

if (NOT WIN32)
	add_definitions(-DBOOST_LOG_DYN_LINK=1)
endif ()

add_subdirectory(src)

