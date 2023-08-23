# node-keylistener
A global windows keylistener for nodejs created using C++.
## Usage
#### Importing keyListener
```js   
const { keyListener } = require('./keylistener')
```
#### Creating a keyListener
The `keyListener` function takes a callback function as an argument and returns a Node.js `ChildProcess`.   
The process can be killed using `<processname>.kill()`. Refer to `/test/test.js` for an example.
## Response data
Here is an example of the data passed in the callback function   
```
{ key: 'S', state: 'DOWN' }
```
## Supported keys
```
BACKSPACE, TAB, CLEAR, ENTER, PAUSE, CAPS_LOCK, ESCAPE, SPACEBAR, PAGE_UP, PAGE_DOWN, END, HOME, LEFT_ARROW, UP_ARROW, RIGHT_ARROW, DOWN_ARROW, SELECT, PRINT, EXECUTE, PRINT_SCREEN, INSERT, DELETE, HELP, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, NUMPAD_0, NUMPAD_1, NUMPAD_2, NUMPAD_3, NUMPAD_4, NUMPAD_5, NUMPAD_6, NUMPAD_7, NUMPAD_8, NUMPAD_9, MULTIPLY, ADD, SEPARATOR, SUBTRACT, DECIMAL, DIVIDE, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24, NUM_LOCK, SCROLL_LOCK, LEFT_SHIFT, RIGHT_SHIFT, LEFT_CONTROL, RIGHT_CONTROL, LEFT_ALT, RIGHT_ALT, VOLUME_MUTE, VOLUME_DOWN, VOLUME_UP, NEXT_TRACK, PREVIOUS_TRACK, STOP_MEDIA, PLAY_PAUSE
```
