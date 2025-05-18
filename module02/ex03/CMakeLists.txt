project(bsp)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Fixed.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Fixed.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Point.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Point.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
