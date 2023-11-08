
include_directories("${PROJECT_BINARY_DIR}")
file(GLOB_RECURSE native_srcs RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach(srcfile IN LISTS native_srcs)
    # Get file name without directory
    get_filename_component(target_name ${srcfile} NAME_WE)
    add_executable(${target_name} ${srcfile})
    # 安装动态库和可执行程序
    install(TARGETS ${target_name}
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
    )
endforeach()
