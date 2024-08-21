#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    // Initialiser GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Créer une fenêtre GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "GLAD Example", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialiser GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Définir la fonction de rappel pour le redimensionnement de la fenêtre
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Boucle de rendu
    while (!glfwWindowShouldClose(window)) {
        // Gérer les événements
        glfwPollEvents();

        // Rendu
        glClear(GL_COLOR_BUFFER_BIT);

        // Échanger les tampons
        glfwSwapBuffers(window);
    }

    // Terminer GLFW
    glfwTerminate();
    return 0;
}