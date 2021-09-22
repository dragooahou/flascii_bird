#pragma once

#define KEYBOARD_SIZE 256

class InputManager {

public:

	enum class Input {

		RELEASED,
		JUST_RELEASED,
		JUST_PRESSED,
		PRESSED,
		COUNT

	};

	InputManager();
	void ListenToUserInput();
	Input getVirtualKeyState(int vk) const;

private:

	short newKeyState[KEYBOARD_SIZE];
	short oldKeyState[KEYBOARD_SIZE];

	Input keyState[KEYBOARD_SIZE];

};