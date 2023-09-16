# ExternalProject 기능을 사용
include(ExternalProject)

set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)

# Add 함수 내 프로젝트를 dep-spdlog 라는 이름으로 가져옴.
ExternalProject_Add(
    dep-spdlog
    GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
    GIT_TAG "v1.x"
    GIT_SHALLOW 1
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR} # 프로젝트 빌드 후 인스톨 어디에 할지 지정.
    TEST_COMMAND ""
)

set(DEP_LIST ${DEP_LIST} dep-spdlog)
set(DEP_LIBS ${DEP_LIBS} spdlog)