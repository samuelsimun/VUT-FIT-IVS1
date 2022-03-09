
if(NOT "/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest/googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt" IS_NEWER_THAN "/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest-master"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest-master'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/google/googletest.git" "googletest-master"
    WORKING_DIRECTORY "/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/google/googletest.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout main --
  WORKING_DIRECTORY "/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest-master"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'main'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest-master"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest-master'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest/googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt"
    "/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/samuel/Desktop/IVS - odovzdanie/ivs_project_1_2022/assignment/build/googletest/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt'")
endif()

