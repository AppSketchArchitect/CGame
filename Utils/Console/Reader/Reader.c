//
// Created by direx on 29/01/2025.
//

#include "Reader.h"

#include <stdbool.h>
#include <stdio.h>
#include <windows.h>

bool bQuitInput = false;
char lastInput = ' ';

DWORD WINAPI ThreadReader(LPVOID) {
    while (bQuitInput == false) {
        if (GetKeyState(VkKeyScan('b')) & 0x8000) {
            lastInput = 'b';
        }
        if(GetKeyState(VkKeyScan('z')) & 0x8000) {
            lastInput = 'z';
        }
        if(GetKeyState(VkKeyScan('q')) & 0x8000) {
            lastInput = 'q';
        }
        if(GetKeyState(VkKeyScan('s')) & 0x8000) {
            lastInput = 's';
        }
        if(GetKeyState(VkKeyScan('d')) & 0x8000) {
            lastInput = 'd';
        }
    }
    return 0;
}

void InitializeKeyReader() {
    CreateThread(NULL, 0, ThreadReader, NULL, 0, NULL);
}

void StopKeyReader() {
    bQuitInput = true;
}

char GetInput() {
    const char input = lastInput;
    lastInput = ' ';
    return input;
}

