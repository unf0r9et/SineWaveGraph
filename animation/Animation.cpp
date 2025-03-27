#include <iostream>
#include <windows.h> 
#include <math.h>

#define WIDTH 120
#define HEIGHT 30
#define PI 3.141592
#define TIME 50

void ClearScreen(char(&screen)[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (j == WIDTH / 2 && i != HEIGHT / 2) {
				screen[i][j] = '|';
			}
			else if (i == HEIGHT / 2) {
				screen[i][j] = '-';
			}
			else screen[i][j] = ' ';
			screen[HEIGHT / 2][WIDTH / 2] = '+';
		}
	}
}
void FunctionSin(char(&screen)[HEIGHT][WIDTH], int coefficient) {
	system("cls");
	ClearScreen(screen);
	int x{ 0 };
	int y{ 0 };
	double k = (4 * PI) / WIDTH;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			x = j;
			y = sin(j * k - coefficient) * HEIGHT / 2;
			if (y < 0) {
				y = abs(y) + (HEIGHT / 2 - 1);
				screen[y][x] = '@';
			}
			else {
				y = (-1 * y) + (HEIGHT / 2 - 1);
				screen[y][x] = '@';
			}
		}
	}
}
void ShowScreen(char(&screen)[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			std::cout << screen[i][j];
		}
		std::cout << std::endl;
	}
}
void CursorOff() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем handle консоли
	CONSOLE_CURSOR_INFO cursorInfo;                    // Структура для управления курсором
	GetConsoleCursorInfo(hConsole, &cursorInfo);       // Получаем текущие настройки курсора
	cursorInfo.bVisible = FALSE;                       // Устанавливаем видимость курсора в FALSE
	SetConsoleCursorInfo(hConsole, &cursorInfo);       // Применяем изменения
}

int main() {
	char screen[HEIGHT][WIDTH];
	CursorOff();
	while (1) {
		for (int coefficient = 0; coefficient <= 2 * PI; coefficient++) {
			FunctionSin(screen, coefficient);
			ShowScreen(screen);
			Sleep(TIME);
		}
	}
	return 0;
}