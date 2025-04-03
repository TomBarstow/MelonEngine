#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <unordered_map>
#include <GLFW/glfw3.h>  // GLFW for key handling

class InputManager {

public:
	void initialize(GLFWwindow* window);
	void update();
	bool keyPressed(int key);

private:
	std::unordered_map<int, bool> keyStates;
	std::unordered_map<int, bool> previousKeyStates;
	GLFWwindow* window;  // Pointer to the GLFW window

};

#endif //INPUTMANAGER_H