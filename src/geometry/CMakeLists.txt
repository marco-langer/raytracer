add_library(raytracer-geometry STATIC
    include/geometry/collision.hpp
    include/geometry/random.hpp
    include/geometry/ray.hpp
    include/geometry/sphere.hpp
    include/geometry/vec3.hpp
    src/collision.cpp
    src/vec3.cpp
    src/random.cpp
    src/ray.cpp
)

set_target_properties(raytracer-geometry
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_include_directories(raytracer-geometry PUBLIC include)
