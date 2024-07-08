#include <iostream>
#include <windows.h>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<short, string> code_to_key = {
    {0x08, "BACKSPACE"},
    {0x09, "TAB"},
    {0x0c, "CLEAR"},
    {0x0d, "ENTER"},
    {0x13, "PAUSE"},
    {0x14, "CAPS_LOCK"},
    {0x1B, "ESCAPE"},
    {0x20, "SPACEBAR"},
    {0x21, "PAGE_UP"},
    {0x22, "PAGE_DOWN"},
    {0x23, "END"},
    {0x24, "HOME"},
    {0x25, "LEFT_ARROW"},
    {0x26, "UP_ARROW"},
    {0x27, "RIGHT_ARROW"},
    {0x28, "DOWN_ARROW"},
    {0x29, "SELECT"},
    {0x2A, "PRINT"},
    {0x2B, "EXECUTE"},
    {0x2C, "PRINT_SCREEN"},
    {0x2D, "INSERT"},
    {0x2E, "DELETE"},
    {0x2F, "HELP"},
    {0x30, "0"},
    {0x31, "1"},
    {0x32, "2"},
    {0x33, "3"},
    {0x34, "4"},
    {0x35, "5"},
    {0x36, "6"},
    {0x37, "7"},
    {0x38, "8"},
    {0x39, "9"},
    {0x41, "A"},
    {0x42, "B"},
    {0x43, "C"},
    {0x44, "D"},
    {0x45, "E"},
    {0x46, "F"},
    {0x47, "G"},
    {0x48, "H"},
    {0x49, "I"},
    {0x4A, "J"},
    {0x4B, "K"},
    {0x4C, "L"},
    {0x4D, "M"},
    {0x4E, "N"},
    {0x4F, "O"},
    {0x50, "P"},
    {0x51, "Q"},
    {0x52, "R"},
    {0x53, "S"},
    {0x54, "T"},
    {0x55, "U"},
    {0x56, "V"},
    {0x57, "W"},
    {0x58, "X"},
    {0x59, "Y"},
    {0x5A, "Z"},
    {0x60, "NUMPAD_0"},
    {0x61, "NUMPAD_1"},
    {0x62, "NUMPAD_2"},
    {0x63, "NUMPAD_3"},
    {0x64, "NUMPAD_4"},
    {0x65, "NUMPAD_5"},
    {0x66, "NUMPAD_6"},
    {0x67, "NUMPAD_7"},
    {0x68, "NUMPAD_8"},
    {0x69, "NUMPAD_9"},
    {0x6A, "MULTIPLY"},
    {0x6B, "ADD"},
    {0x6C, "SEPARATOR"},
    {0x6D, "SUBTRACT"},
    {0x6E, "DECIMAL"},
    {0x6F, "DIVIDE"},
	{0x70, "F1"},
	{0x71, "F2"},
	{0x72, "F3"},
	{0x73, "F4"},
	{0x74, "F5"},
	{0x75, "F6"},
	{0x76, "F7"},
	{0x77, "F8"},
	{0x78, "F9"},
    {0x79, "F10"},
    {0x7A, "F11"},
    {0x7B, "F12"},
    {0x7C, "F13"},
    {0x7D, "F14"},
    {0x7E, "F15"},
    {0x7F, "F16"},
    {0x80, "F17"},
    {0x81, "F18"},
    {0x82, "F19"},
    {0x83, "F20"},
    {0x84, "F21"},
    {0x85, "F22"},
    {0x86, "F23"},
    {0x87, "F24"},
    {0x90, "NUM_LOCK"},
    {0x91, "SCROLL_LOCK"},
    {0xA0, "LEFT_SHIFT"},
    {0xA1, "RIGHT_SHIFT"},
    {0xA2, "LEFT_CONTROL"},
    {0xA3, "RIGHT_CONTROL"},
    {0xA4, "LEFT_ALT"},
    {0xA5, "RIGHT_ALT"},
    {0xAD, "VOLUME_MUTE"},
    {0xAE, "VOLUME_DOWN"},
    {0xAF, "VOLUME_UP"},
    {0xB0, "NEXT_TRACK"},
    {0xB1, "PREVIOUS_TRACK"},
    {0xB2, "STOP_MEDIA"},
    {0xB3, "PLAY_PAUSE"}
};

int main() {

    set<short> down_keys;

    while (true) {
        for (auto i: code_to_key) {
            SHORT key_state = GetAsyncKeyState(i.first);
            if (key_state < 0) {
                if (down_keys.find(i.first) == down_keys.end()) {
                    cout << i.second << " DOWN" << endl;
                }
                down_keys.insert(i.first);
            }
            if (down_keys.find(i.first) != down_keys.end() && key_state == 0) {
                cout << i.second << " UP" << endl;
                down_keys.erase(i.first);
            }
        }
    }
}
