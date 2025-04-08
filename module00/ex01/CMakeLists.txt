project(phone_book)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Command.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Command.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Contact.hpp
        ${CMAKE_CURRENT_LIST_DIR}/Contact.cpp
        ${CMAKE_CURRENT_LIST_DIR}/PhoneBook.hpp
        ${CMAKE_CURRENT_LIST_DIR}/PhoneBook.cpp
        ${CMAKE_CURRENT_LIST_DIR}/FormattedInput.cpp
        ${CMAKE_CURRENT_LIST_DIR}/FormattedInput.h
)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
