
find_package(LATEX COMPONENTS XELATEX REQUIRED)

set(sources
    circle.png
    manual.md
    manual.xml
)

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/umdoc.pdf" "${CMAKE_CURRENT_BINARY_DIR}/umdoc-${PROJECT_VERSION}.pdf"
    COMMAND $<TARGET_FILE:umdoc> "${CMAKE_CURRENT_SOURCE_DIR}/manual.xml" "--packageVersion=${PROJECT_VERSION}" -o "${CMAKE_CURRENT_BINARY_DIR}/umdoc.pdf"
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/umdoc.pdf" "${CMAKE_CURRENT_BINARY_DIR}/umdoc-${PROJECT_VERSION}.pdf"
    DEPENDS $<TARGET_FILE:umdoc> ${sources}
)

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/umdoc.html"
    COMMAND $<TARGET_FILE:umdoc> "${CMAKE_CURRENT_SOURCE_DIR}/manual.xml" "--packageVersion=${PROJECT_VERSION}" -o "${CMAKE_CURRENT_BINARY_DIR}/umdoc.html"
    DEPENDS $<TARGET_FILE:umdoc> ${sources}
)

add_custom_target(manual ALL
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/umdoc.pdf"
            "${CMAKE_CURRENT_BINARY_DIR}/umdoc.html"
    SOURCES ${sources}
)

set_target_properties(manual PROPERTIES
    FOLDER "Doc"
)

source_group("" FILES ${sources})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/umdoc.pdf" DESTINATION .)
