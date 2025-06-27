project(materias)

add_executable(${PROJECT_NAME}
        main.cpp

        Character/Character.cpp
        Character/ICharacter.cpp

        Materia/AMateria.cpp
        Materia/IMateriaSource.cpp
        Materia/Ice.cpp
        Materia/Cure.cpp

        PtrVec/PtrVec.cpp
        Materia/MateriaSource.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
        .
)
