# Usage:
#
# ```cmake
# add_app(bruh src...)
# ```
#
# `<app_name>` should be the the directory name

#cmake_minimum_required(VERSION 3.28)
#project(flight_sw)

function(add_app name)
  message("Adding application: \"${name}\"")

  add_executable(${name}
        ${CMAKE_CURRENT_SOURCE_DIR}/${name}/${ARGN}
    )

  target_include_directories(${name} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/${name}
    )

  target_link_libraries(${name} etl freertos_kernel)

  if(NOT "${TARGET}" STREQUAL "Native")
    target_link_libraries(${name} stm_hal)
  endif()

endfunction()

add_app(src

main.cpp
src/constants.hpp

src/task-fsm.cpp
src/task-fsm.hpp

src/task-command.cpp
src/task-command.hpp

src/task-telem.cpp
src/task-telem.hpp

src/driver-bms.cpp

src/driver-uart.cpp

src/driver-bus.cpp
)
