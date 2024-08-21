#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Gui/imgui.h>
#include <Gui/imgui_impl_glfw.h>
#include <Gui/imgui_impl_opengl3.h>
#include <iostream>
#include <Game/Game.h>

Game::Game() : window(nullptr) {}

Game::~Game() {
    cleanup();
}

bool Game::initialize() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Create a GLFW window
    window = glfwCreateWindow(800, 600, "Game Loop Example", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    // Set the framebuffer size callback
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    return true;
}

void Game::run() {
    while (!glfwWindowShouldClose(window)) {
        processInput();
        update();
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Game::cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    if (window) {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}

void Game::processInput() {
    // Handle input
}

void Game::update() {
    // Update game state
}

void Game::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    renderImGui();
    // Render game
}

void Game::renderImGui() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // ImGui rendering code here
    ImGui::Begin("Hello, world!");
    ImGui::Text("This is some useful text.");
    if (ImGui::Button("Click Me")) {
        // Button was clicked
        std::cout << "Button clicked!" << std::endl;
    }
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
