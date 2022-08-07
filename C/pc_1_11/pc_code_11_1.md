``` C
#include<stdio.h>
#include<stdlib.h>

void reset(void);
void display(void);
void play(int);
int change(int);
void finish(void);

int color[8][8];

int main() {
	int badpoint,nowcolor;

	system("cls"); /*初手*/
	reset(); /*盤をリセット*/
	display(); /*描写*/
    badpoint=0; /*最初はどこも置ける*/
	nowcolor=2; /*最初は黒*/

   	while (1){
		if (nowcolor == 2) {
			printf("黒のターンです\n");
		}
		else if (nowcolor == 1) {
			printf("白のターンです\n");
		}
		
		play(nowcolor);
		system("cls");
		display();		
		nowcolor=change(nowcolor); /*交替*/
		/*続行判断*/
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (color[i][j] == 0) {
					badpoint=0;
					break;
				}
				else if (color[i][j] != 0) {
					badpoint = 1;
				}
			}
		}
		if(badpoint==1){
			printf("ゲーム終了");
			break;
		}
	}
	finish();		
}

void reset() {
	/*すべてを空に*/
	for (int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			color[i][j] = 0;
		}
	}
	/*初期設定*/
	color[3][3] = 1;
	color[3][4] = 2;
	color[4][3] = 2;
	color[4][4] = 1;
}

void display() {
	int i,j;
	/*描写*/
	printf("  0 1 2 3 4 5 6 7\n");
	for (i = 0; i < 8; i++) {
		printf("%d", i);
		for (j = 0; j < 8; j++) {
			if (color[i][j] == 0) {
				printf("・");
			}
			else if (color[i][j] == 1) {
				printf("● ");
			}
			else if (color[i][j] == 2) {
				printf("○ ");
			}
			else {
				printf("+ ");
			}
		}
		printf("\n");
	}
}

void play(int nowcolor2) {
	int i,j;
	/*入力*/
	while(1){
		printf("縦＝");
		scanf("%d",&i);
		printf("横＝");
		scanf("%d",&j);

		if (i < 0 || i>7 || j < 0 || j>7) {
			printf("盤外です\n");
			continue;
		}

		if (color[i][j] == 1 || color[i][j] == 2) {
			printf("すでにコマが置かれています\n");
			continue;
		}
        color[i][j] = nowcolor2;
	break;
	}
}

int change(int nowcolor2) {
	if (nowcolor2 == 2) {
		nowcolor2 = 1;
	}
	else if (nowcolor2 == 1) {
		nowcolor2 = 2;
	}
        return nowcolor2;
}

void finish() {
	int blackcount = 0;
	int whitecount = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (color[i][j] == 1) {
				whitecount = whitecount + 1;
			}
			else if (color[i][j] == 2) {
				blackcount = blackcount + 1;
			}
		}
	}

	printf("黒:%d 白:%d\n", blackcount, whitecount);

	if (blackcount > whitecount) {
		printf("黒の勝ち\n");
	}
	else if (blackcount < whitecount) {
		printf("白の勝ち\n");
	}
	else if (blackcount == whitecount) {
		printf("引き分け\n");
	}
}



```