# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/pingpong_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/pingpong_autogen.dir/ParseCache.txt"
  "pingpong_autogen"
  )
endif()
