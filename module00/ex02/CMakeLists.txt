project(accounting)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/tests.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Account.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Account.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)