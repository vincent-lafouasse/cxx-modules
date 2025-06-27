project(materias)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ./main.cpp

        ./Character/Character.cpp
        ./Materia/Ice.cpp

        ./PtrVec/PtrVec.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        .
)
