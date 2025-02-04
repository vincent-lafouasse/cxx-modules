project(animals)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp

        ${CMAKE_CURRENT_LIST_DIR}/Animal.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Animal.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Dog.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Dog.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Cat.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Cat.hpp

        ${CMAKE_CURRENT_LIST_DIR}/WrongAnimal.cpp
        ${CMAKE_CURRENT_LIST_DIR}/WrongAnimal.hpp
        ${CMAKE_CURRENT_LIST_DIR}/WrongDog.cpp
        ${CMAKE_CURRENT_LIST_DIR}/WrongDog.hpp
        ${CMAKE_CURRENT_LIST_DIR}/WrongCat.cpp
        ${CMAKE_CURRENT_LIST_DIR}/WrongCat.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)