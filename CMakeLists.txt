cmake_minimum_required(VERSION 3.13)

# set은 변수 생성
set(PROJECT_NAME cmake_project_example)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)

include(Dependency.cmake)

# 우리 프로젝트에 include / lib 관련 옵션 추가
# 컴파일할때 ${DEP_INCLUDE_DIR} / ${DEP_LIB_DIR} 디렉토리를 포함시킴
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS}) # 포함시킬 라이브러리 지정

# Dependency들이 먼저 build 될 수 있게 관계 설정
add_dependencies(${PROJECT_NAME} ${DEP_LIST})