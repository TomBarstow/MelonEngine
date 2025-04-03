#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <unordered_map>
#include <GLFW/glfw3.h>  // GLFW for key handling
#include <string>

class InputManager {

public:
	void initialize(GLFWwindow* window);
	void update();
	void mapActionToKey(const std::string& action, int key);
	bool actionPressed(const std::string& action);

private:
	std::unordered_map<int, bool> keyStates;
	std::unordered_map<int, bool> previousKeyStates;
	std::unordered_map<std::string, int> actionKeyMap; //Maps actions to keys
	GLFWwindow* window;  // Pointer to the GLFW window

};

#endif //INPUTMANAGER_H