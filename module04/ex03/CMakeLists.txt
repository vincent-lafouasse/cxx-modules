project(materias)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ./main.cpp

        ./Character/ICharacter.hpp
        ./Character/Character.hpp

        ./Materia/AMateria.hpp
        ./Materia/Ice.hpp
        ./Materia/Cure.hpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)