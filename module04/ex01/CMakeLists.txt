project(big_brain)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Brain.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Brain.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Animal.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Animal.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Dog.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Dog.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Cat.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Cat.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)