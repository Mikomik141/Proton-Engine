#ifndef PROTON_ENGINE_GAME_H
#define PROTON_ENGINE_GAME_H

#include <GLFW/glfw3.h>

class Game {
public:
    Game();
    ~Game();
    bool initialize();
    void run();
    void cleanup();

private:
    GLFWwindow* window;
    void processInput();
    void update();
    void render();
    void renderImGui();

};

#endif // PROTON_ENGINE_GAME_H