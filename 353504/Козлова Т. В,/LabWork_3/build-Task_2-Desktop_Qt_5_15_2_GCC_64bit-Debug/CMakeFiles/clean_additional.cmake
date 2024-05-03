# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Ackermann_autogen"
  "CMakeFiles/Ackermann_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Ackermann_autogen.dir/ParseCache.txt"
  )
endif()
