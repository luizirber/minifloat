# added CMakeLists.txt file for biicode support.

if(BIICODE)
  ADD_BII_TARGETS()

  IF(APPLE)
    TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11 -stdlib=libc++")
  ELSEIF (WIN32 OR UNIX)
    TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11")
  ENDIF(APPLE)

  return()
endif()
