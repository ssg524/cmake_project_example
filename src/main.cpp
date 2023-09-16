#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv)
{
    SPDLOG_INFO("Start program");

    // glfw 라이브러리를 초기화
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit()) {
        const char* description = nullptr;
        glfwGetError(&description); // 에러 이유 description에 저장
        SPDLOG_ERROR("failed to initialize glfw: {}", description); // 에러 로그로 출력 spdlog는 fmt 라이브러리로 출력
        return -1;
    }

    // 윈도우 창 생성
    SPDLOG_INFO("Create glfw window");
    // 이전에 CMakeLists에서 정의한 변수들을 사용했다. auto는 자동으로 자료형 정해줌
    // auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    
    if (!window) {
        SPDLOG_ERROR("failed to create glfw window");
        // 생성 실패하면 glfw 라이브러리 종료
        glfwTerminate();
        return -1;
    }

    SPDLOG_INFO("Start main loop");
    // glfwWindowShouldClose는 실행 후 바로 종료되지 않게 하기 위한 함수이다.
    while (!glfwWindowShouldClose(window))
        glfwPollEvents(); // 윈도우와 관련한 이벤트들을 처리함 (클릭, 창 사이즈 조절 등)
        // ㄴ 함수는 1/60초마다 실행됨

    // glfw 라이브러리 종료
    glfwTerminate();
    return 0;
}