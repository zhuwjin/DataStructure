include_directories(include)

add_library(li_list base/LiList.cpp)
add_library(cd_list base/CDLinklist.cpp)
add_library(c_list base/CLinklist.cpp)
add_library(d_list base/DLinklist.cpp)

add_executable(e_1 exercises/e_1.cpp)
target_link_libraries(e_1 li_list)

add_executable(e_2 exercises/e_2.cpp)
target_link_libraries(e_2 li_list)

add_executable(e_4 exercises/e_4.cpp)
target_link_libraries(e_4 li_list)

add_executable(e_5 exercises/e_5.cpp)
target_link_libraries(e_5 li_list)

add_executable(e_6 exercises/e_6.cpp)
target_link_libraries(e_6 li_list)

add_executable(e_8 exercises/e_8.cpp)
target_link_libraries(e_8 li_list)

add_executable(e_9 exercises/e_9.cpp)
target_link_libraries(e_9 li_list)

add_executable(e_10 exercises/e_10.cpp)
target_link_libraries(e_10 li_list)

add_executable(e_12 exercises/e_12.cpp)
target_link_libraries(e_12 li_list)

add_executable(e_13 exercises/e_13.cpp)
target_link_libraries(e_13 li_list)

add_executable(e_14 exercises/e_14.cpp)
target_link_libraries(e_14 li_list)

add_executable(e_15 exercises/e_15.cpp)
target_link_libraries(e_15 li_list)

add_executable(e_16 exercises/e_16.cpp)
target_link_libraries(e_16 li_list)

add_executable(e_17 exercises/e_17.cpp)
target_link_libraries(e_17 cd_list)

add_executable(e_18 exercises/e_18.cpp)
target_link_libraries(e_18 c_list)

add_executable(e_19 exercises/e_19.cpp)
target_link_libraries(e_19 c_list)

add_executable(e_20 exercises/e_20.cpp)

add_executable(e_21 exercises/e_21.cpp)
target_link_libraries(e_21 li_list)

add_executable(e_22 exercises/e_22.cpp)
target_link_libraries(e_22 li_list)

add_executable(e_23 exercises/e_23.cpp)

add_executable(e_24 exercises/e_24.cpp)
target_link_libraries(e_24 li_list)

add_executable(e_25 exercises/e_25.cpp)
target_link_libraries(e_25 li_list)