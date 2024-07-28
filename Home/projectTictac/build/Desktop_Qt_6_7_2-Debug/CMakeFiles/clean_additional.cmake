# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/projectTictac_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/projectTictac_autogen.dir/ParseCache.txt"
  "projectTictac_autogen"
  )
endif()
