project(materia)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ./main.cpp

        ./ICharacter.hpp
        ./Character.hpp

        ./AMateria.hpp
        ./Ice.hpp
        ./Cure.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)