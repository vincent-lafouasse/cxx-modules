project(violence)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/HumanA.cpp
        ${CMAKE_CURRENT_LIST_DIR}/HumanB.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
