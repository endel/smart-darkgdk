#pragma once

#define KEY_1 2
#define KEY_2 3
#define KEY_3 4
#define KEY_4 5
#define KEY_5 6
#define KEY_6 7
#define KEY_7 8
#define KEY_8 9
#define KEY_9 10
#define KEY_0 11

#define KEY_PAD_7 71
#define KEY_PAD_8 72
#define KEY_PAD_9 73
#define KEY_PAD_4 75
#define KEY_PAD_5 76
#define KEY_PAD_6 77
#define KEY_PAD_1 79
#define KEY_PAD_2 80
#define KEY_PAD_3 81
#define KEY_PAD_0 82

#define KEY_Q 16
#define KEY_W 17
#define KEY_E 18
#define KEY_R 19
#define KEY_T 20
#define KEY_Y 21
#define KEY_U 22
#define KEY_I 23
#define KEY_O 24
#define KEY_P 25
#define KEY_A 30
#define KEY_S 31
#define KEY_D 32
#define KEY_G 33
#define KEY_H 34
#define KEY_J 35
#define KEY_K 36
#define KEY_L 37
#define KEY_Z 44
#define KEY_X 45
#define KEY_C 46
#define KEY_V 47
#define KEY_B 48
#define KEY_N 49
#define KEY_M 50

#define KEY_BACKSPACE 14
#define KEY_TAB 15
#define KEY_CTRL_L 29
#define KEY_CTRL_R 157
#define KEY_DELETE 211
#define KEY_SHIFT_L 42
#define KEY_SHIFT_R 54
#define KEY_ALT_L 56
#define KEY_ALT_R 184
#define KEY_SPACE 57
#define KEY_UP 200
#define KEY_DOWN 208
#define KEY_RIGHT 205
#define KEY_LEFT 203
#define KEY_RETURN 28

#define KEY_F1 59
#define KEY_F2 60
#define KEY_F3 61
#define KEY_F4 62
#define KEY_F5 63
#define KEY_F6 64
#define KEY_F7 65
#define KEY_F8 66
#define KEY_F9 67
#define KEY_F10 68
#define KEY_F11 87

class Key
{
public:
	Key(void);
	~Key(void);
	static bool up();
	static bool down();
	static bool left();
	static bool right();
	static bool ctrl();
	static bool shift();
	static bool enter();
	static bool escape();
	static bool space();
	static int scanCode();
	static bool check(int scanCode);
	static char* entry();
	static char* getClipboard();
	static int getRegistry();
};
