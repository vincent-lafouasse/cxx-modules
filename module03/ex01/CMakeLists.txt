project(scav_trap)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ClapTrap.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ClapTrap.hpp
        ${CMAKE_CURRENT_LIST_DIR}/ScavTrap.cpp
        ${CMAKE_CURRENT_LIST_DIR}/ScavTrap.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)