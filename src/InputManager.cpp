#include <InputManager.h>
//#include <unordered_map>
#include <iostream>

void InputManager::initialize(GLFWwindow* window) {
    if (!window) {
        std::cerr << "Error: GLFW window is not initialized!" << std::endl;
        return;
    }
    // Assign the window pointer
    this->window = window;
    
    keyStates.clear();
    previousKeyStates.clear();
}

// Update keyStates based on input
void InputManager::update() {
    if (window == nullptr) {
        std::cerr << "Error: Invalid GLFW window pointer!" << std::endl;
        return;
    }   
    
    previousKeyStates = keyStates;

    for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; ++key) {
        int state = glfwGetKey(window, key);

        // Update the key state
        if (state == GLFW_PRESS) {
            keyStates[key] = true;  // Key is pressed
        }
        else {
            keyStates[key] = false;  // Key is not pressed
        }
    }
    
}

bool InputManager::keyPressed(int key) {
    return keyStates[key];
}