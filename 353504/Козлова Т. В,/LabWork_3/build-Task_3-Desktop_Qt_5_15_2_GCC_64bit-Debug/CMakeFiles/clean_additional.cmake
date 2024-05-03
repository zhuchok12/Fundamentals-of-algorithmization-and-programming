# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Reverse_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Reverse_autogen.dir/ParseCache.txt"
  "Reverse_autogen"
  )
endif()
