project(horde)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Zombie.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Zombie.hpp
        ${CMAKE_CURRENT_LIST_DIR}/zombieHorde.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)