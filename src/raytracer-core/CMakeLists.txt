add_library(raytracer-core STATIC
    include/raytracer/camera.hpp
    include/raytracer/color.hpp
    include/raytracer/image.hpp
    include/raytracer/image_io.hpp
    include/raytracer/render.hpp
    include/raytracer/sphere.hpp
    include/raytracer/viewport.hpp
    include/raytracer/world.hpp
    src/color.cpp
    src/image_io.cpp
    src/render.cpp
)

set_target_properties(raytracer-core
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories(raytracer-core PUBLIC include)
target_link_libraries(raytracer-core PUBLIC raytracer-geometry)