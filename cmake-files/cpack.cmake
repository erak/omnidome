### CPack Convenience Macro

MACRO(setup_cpack)
  #if ((${MAJOR_VERSION} EQUAL 0 AND (${MINOR_VERSION} EQUAL 0) AND (${PATCH_VERSION} EQUAL 0))
  #  MESSAGE(WARNING "Version number is not valid (you are not on a version branch). CPack will not be executed.")
  #  return()
  #endif (${MAJOR_VERSION} EQUAL 0 AND (${MINOR_VERSION} EQUAL 0) AND (${PATCH_VERSION} EQUAL 0))

  set(CPACK_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
  set(CPACK_PACKAGE_VENDOR "cr8tr")
  set(CPACK_PACKAGE_VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
  set(CPACK_PACKAGE_VERSION_MAJOR "${MAJOR_VERSION}")
  set(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
  set(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
  SET(CPACK_GENERATOR "DEB")
ENDMACRO(setup_cpack major_version minor_version patch_version)

