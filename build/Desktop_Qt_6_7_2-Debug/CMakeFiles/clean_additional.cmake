# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/resourceViewer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/resourceViewer_autogen.dir/ParseCache.txt"
  "resourceViewer_autogen"
  )
endif()
