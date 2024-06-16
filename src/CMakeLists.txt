add_executable(raytracer
    main.cpp
)

set_target_properties(raytracer
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_subdirectory(geometry)
add_subdirectory(raytracer-core)

target_link_libraries(raytracer PRIVATE raytracer-core)