project(module03)

add_custom_target(ClapTrap make -C ${CMAKE_CURRENT_SOURCE_DIR}/ex00)
add_custom_target(ScavTrap make -C ${CMAKE_CURRENT_SOURCE_DIR}/ex01)