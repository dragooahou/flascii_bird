#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "InputManager.h"



/*
Sets mememory to register inputs
*/
InputManager::InputManager() {
	memset(newKeyState, 0, 256 * sizeof(short));
	memset(oldKeyState, 0, 256 * sizeof(short));
	memset(keyState, 0, 256 * sizeof(Input));
};

/*
Register each key state on the keyboard and stores it according to it's previous state :
PRESSED -> the key is pressed since (at least) the previous frame
JUST_PRESSED -> the key just got pressed on this specific frame
JUST_REALEASED -> the key just released on this specific frame
RELEASED -> the key is released since (at least) the previous frame
*/
void InputManager::ListenToUserInput() {

	for (int i = 0; i < KEYBOARD_SIZE; i++) {
		newKeyState[i] = GetAsyncKeyState(i);

		//if the key is held down
		if ((newKeyState[i] & 0x8000) && (oldKeyState[i] & 0x8000)) {
			keyState[i] = Input::PRESSED;
		}
		//if the key was just pressed
		else if ((newKeyState[i] & 0x8000) && !(oldKeyState[i] & 0x8000)) {
			keyState[i] = Input::JUST_PRESSED;
		}
		//if the key was just released
		else if (!(newKeyState[i] & 0x8000) && (oldKeyState[i] & 0x8000)) {
			keyState[i] = Input::JUST_RELEASED;
		}
		//if the key is released
		else if (!(newKeyState[i] & 0x8000) && !(oldKeyState[i] & 0x8000)) {
			keyState[i] = Input::RELEASED;
		}

		oldKeyState[i] = newKeyState[i];

	}
}

/*
Retrieves the state of a specific key (VK_)
*/
 InputManager::Input InputManager::getVirtualKeyState(int vk) const {
	return keyState[vk];
}

 /*
 Retrieves signleton instance of InputManager
 */
InputManager &InputManager::GetInstance() {
    static InputManager inputManager;
    return inputManager;
}

