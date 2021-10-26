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

    InputManager(InputManager &other) = delete;
    void operator=(const InputManager &) = delete;

	void ListenToUserInput();
	Input getVirtualKeyState(int vk) const;

    static InputManager& GetInstance();


private:

    InputManager();

    short newKeyState[KEYBOARD_SIZE];
    short oldKeyState[KEYBOARD_SIZE];

    Input keyState[KEYBOARD_SIZE];

};