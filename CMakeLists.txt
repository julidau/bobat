project("bobat")

set(SOURCE
	"source/camera.cpp"
	"source/polygon.cpp"
	"main.cpp"
)

include_directories("include/")

add_executable(bobat ${SOURCE})

target_link_libraries(bobat SDL2)
