#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "InputManager.h"




InputManager::InputManager() {
	memset(newKeyState, 0, 256 * sizeof(short));
	memset(oldKeyState, 0, 256 * sizeof(short));
	memset(keyState, 0, 256 * sizeof(Input));
};

void InputManager::ListenToUserInput() {

	for (int i = 0; i < 256; i++) {
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

 InputManager::Input InputManager::getVirtualKeyState(int vk)
{
	return keyState[vk];
}

