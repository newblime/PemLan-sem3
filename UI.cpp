#include <bits/stdc++.h>
#include <stdlib.h>
#include <Windows.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

void delay(){
	int delay;
	delay=1;
	while(delay<100000000) {
		delay++;
	}
}

void loadscr(){
	vector<char>load = {'U','A','S','P','E','M','L', 'A', 'N'};
	for(int i = 0; i < load.size(); i++) {
		cout << "\t " << load[i];
		delay();
	}
	sleep(2);
}

//fungsi gotoxy bisa digunain untuk atur posisi output
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loadscreen(){
    system("cls");
    system("color 70");
    gotoxy(20,10);
    loadscr();
}

//fungsi loading bisa digunain untuk loadscreen dari fungsi satu ke fungsi lainnya
void loading(){
    system("color 70");
	system("cls");
	gotoxy(32, 10);

	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;

	cout << "\n\t\t\t\t\t    L O A D I N G...";
	cout << "\n\n\n\t\t\t\t\t";

	for(int i = 0; i < 25; i++)
		cout << (char)bar1;

	cout << "\r";
	cout << "\t\t\t\t\t";

	for(int i = 0; i < 25; i++){
		cout << (char)bar2;
		Sleep(100);
	}

	//cout << "\n\n\t\t\t\t\t" << (char)1 << "!";
	//system("pause");
}

//ini fungsi main hanya buat testing
int main(){
    loadscreen();
    loading();

	return 0;
}
