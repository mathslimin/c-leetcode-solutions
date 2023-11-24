project(hash-table)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
aux_source_directory(. PROBLEMS)

foreach(PROBLEM ${PROBLEMS})
    get_filename_component(PROBLEM_NAME ${PROBLEM} NAME_WE)
    add_executable(${PROJECT_NAME}-${PROBLEM_NAME}.exe ${PROBLEM})
    target_link_libraries(
        ${PROJECT_NAME}-${PROBLEM_NAME}.exe
        ${CMAKE_THREAD_LIBS_INIT}
        m
    )
    install (TARGETS ${PROJECT_NAME}_${PROBLEM_NAME}.exe DESTINATION bin)
endforeach()