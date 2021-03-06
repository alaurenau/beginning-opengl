CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(APP_NAME ogro_invasion)

PROJECT(${APP_NAME})

IF(WIN32)
    ADD_DEFINITIONS(-D_WIN32)
ENDIF(WIN32)

SET(SOURCE_FILES
	src/main.cpp
	src/example.cpp
	src/targa.cpp
	src/camera.cpp
	src/collider.cpp
	src/enemy.cpp
	src/entity.cpp
	src/explosion.cpp
	src/freetypefont.cpp
	src/frustum.cpp
	src/gameworld.cpp
	src/landscape.cpp
	src/md2model.cpp
	src/ogro.cpp
	src/player.cpp
	src/rocket.cpp
	src/spherecollider.cpp
	src/terrain.cpp
	src/terraincollider.cpp
	src/tree.cpp
	src/window/glfwwindowwrapper.cpp
)

IF(WIN32)
	ADD_EXECUTABLE(${APP_NAME} WIN32 ${SOURCE_FILES})
ELSE(WIN32)
	ADD_EXECUTABLE(${APP_NAME} ${SOURCE_FILES})
ENDIF(WIN32)

IF(WIN32)
	SET(LIBRARIES OPENGL32 GLU32 freetype)
ELSE(WIN32)
	SET(LIBRARIES GL GLU freetype)
ENDIF(WIN32)

TARGET_LINK_LIBRARIES(${APP_NAME} glee glfw-window glfw ${LIBRARIES})

ADD_CUSTOM_TARGET(
		${APP_NAME}-data ALL
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/data
		${CMAKE_CURRENT_BINARY_DIR}/data)

add_dependencies(${APP_NAME} ${APP_NAME}-data)
