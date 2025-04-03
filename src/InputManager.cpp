#include <InputManager.h>
//#include <unordered_map>
//#include <iostream>
#include <console.h>

void InputManager::initialize(GLFWwindow* window) {
    if (!window) {
        Console("Error: GLFW window is not initialized!");
        return;
    }
    // Assign the window pointer
    this->window = window;
    
    // Clear hashtables
    keyStates.clear();
    previousKeyStates.clear();

    //Map actions to keys
    mapActionToKey("Forward", GLFW_KEY_W);
    mapActionToKey("Backward", GLFW_KEY_S);
    mapActionToKey("Left", GLFW_KEY_A);
    mapActionToKey("Right", GLFW_KEY_D);
}

// Update keyStates based on input
void InputManager::update() {
    if (window == nullptr) {
        Console("Error: Invalid GLFW window pointer!");
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

void InputManager::mapActionToKey(const std::string& action, int key) {
    actionKeyMap[action] = key;
}

bool InputManager::actionPressed(const std::string& action) {
    int key = actionKeyMap[action];
    return keyStates[key];
}