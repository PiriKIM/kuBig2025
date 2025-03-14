cmake_minimum_required(VERSION 3.10)
project(carSerial)

# include_directories(${CMAKE_CURRENT_LIST_DIR})
# 헤더 파일이 다른 폴더에 있으면 위치 명시해야함.

# 소스 파일이 많으면 변수로 지정해서 사용.
set(SOURCES
    main.c
    serial.c
    )


add_executable(carSerial ${SOURCES})
# 소스 파일에 명시된 헤더도 알아서 포함되어짐.
