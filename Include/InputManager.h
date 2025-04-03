#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <unordered_map>
#include <GLFW/glfw3.h>  // GLFW for key handling
#include <string>

class InputManager {

public:
	static void initialize(GLFWwindow* window);
	static void update();
	static void mapActionToKey(const std::string& action, int key);
	static bool actionPressed(const std::string& action);

private:
	static std::unordered_map<int, bool> _keyStates;
	static std::unordered_map<int, bool> _previousKeyStates;
	static std::unordered_map<std::string, int> _actionKeyMap; //Maps actions to keys
	static GLFWwindow* _window;  // Pointer to the GLFW window

};

#endif //INPUTMANAGER_H