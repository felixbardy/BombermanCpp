#Example:
#set(BINARY my_binary)
#set(SOURCES my_binary_source.cpp)

#add_executable(${BINARY} ${SOURCES})

#target_link_libraries(
#    ${BINARY}
#    ${SDL2_LIBRARIES}
#    ${SDL2_IMAGE_LIBRARIES}
#    ${SDL2_TTF_LIBRARIES}
#    ${CMAKE_PROJECT_NAME}_lib
#)