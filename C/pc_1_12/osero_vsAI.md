```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

void mode(void);
void reset(void);
void display(void);
int put(int, int,int);
int change(int);
void play(int);
void AIplay(int);
int check(int,int);
void finish(void);

int color[8][8],whichAI,AIturn;

int main() {
	int badpoint,nowcolor;
	system("cls");
	/*盤をリセット*/
	reset();
	/*描写*/
	display();
    	mode();
	badpoint=0;
	nowcolor=2;

	while (1){
		if (nowcolor == 2) {
			printf("黒のターンです\n");
			if(AIturn==1){
				printf("AIのターンです\n5秒ほどお待ちください\n");
				sleep(5);
			}
		}
		else if (nowcolor == 1) {
			printf("白のターンです\n");
			if(AIturn==1){
				printf("AIのターンです\n5秒ほどお待ちください\n");
				sleep(5);
			}
		}
		/*始める*/
		if(whichAI==1){
			if(badpoint!=0){
				printf("置ける場所はありません");
				sleep(3);
			}else{
				play(nowcolor);
			}		
		}else if(whichAI==2){
			if(AIturn==0){
				if(badpoint!=0){
					printf("置ける場所はありません");
					sleep(3);
                }else{
			        play(nowcolor);
		        }
				AIturn=1;
			}else if(AIturn==1){
				if(badpoint!=0){
                	printf("置ける場所はありません");
					sleep(3);
				}else{
					AIplay(nowcolor);
				}
				AIturn=0;   	
            }
		}
		/*描写*/
        	system("cls");
		display();
		/*交替*/
		nowcolor=change(nowcolor);
		/*続行判断*/
		badpoint=check(badpoint,nowcolor);
		if(badpoint==2){
			break;
		}
	}
	finish();
}
	
void mode(){
    int mode;

	printf("ゲームモードを選択してください\n");
	printf("1:人間VS人間  2:人間VS単純AI\n");

	while(1){
		scanf("%d",&mode);
		if(mode!=1&&mode!=2){
			printf("もう一度入力してください\n");
		}else{
			break;
		}
	}
	switch(mode){
	case 1:
        whichAI=1;
		break;
	case 2:
		whichAI=2;
		while(1){
			printf("1:先手  2:後手\n");
			scanf("%d",&AIturn);
			AIturn-=1;
			if(AIturn!=0&&AIturn!=1){
				printf("もう一度入力してください\n");
			}else{
				break;
			}
		}
	}			
}
		
void reset() {
	int i,j;
	/*すべてを空に*/
	for (i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
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
	printf(" 0 1 2 3 4 5 6 7 \n");
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

int change(int nowcolor2) {
	if (nowcolor2 == 2) {
		nowcolor2 = 1;
	}
	else if (nowcolor2 == 1) {
		nowcolor2 = 2;
	}
	return nowcolor2;
}
void play(int nowcolor2) {
	int i,j,flag;
	/*入力*/
	while (1){
		printf("縦＝");
		scanf("%d",&i);
		
		printf("横＝");
		scanf("%d",&j);


		if (i<0||i>7||j<0||j>7) {
			printf("盤外です\n");
			continue;
		}else if(color[i][j] == 1 || color[i][j] == 2){
			printf("すでにコマが置かれています\n");
			continue;
		}else{
            flag=put(i, j,nowcolor2);
			if (flag == 0) {
				break;
			}else if (flag == 1) {
				printf("選択した場所には置けません\n");
			}
        }
    }
}

int put(int x, int y,int nowcolor3) {
    int i,j,n,k;
    int flag=1;
	/*置けるかチェックしつつひっくり返す*/
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {

			/*置いたところは無視*/
			if (i == 0 && j == 0) {
				continue;
			}
			/*隣が自色は無視*/
			if (color[i+x][j+y]==nowcolor3) {
				continue;
			}

			/*各方向に1マスずつ確認*/
			for (k = 1; k < 8; k++) {

				/*盤内だけでチェック*/
				if (x + i * k >= 0 && x + i * k < 8 && y + j * k >= 0 && y + j * k < 8) {
					
					/*空白があった場合はそれ以上試行する必要なし*/
					if (color[x + i * k][y + j * k] == 0) {
						break;
					}
					/*自色を見つけたらそこまでのコマをひっくり返す*/
					else if (color[x + i * k][y + j * k] == nowcolor3) {
						/*コマを置き自色に変える*/
						color[x][y] = nowcolor3;
						for (n = 1; n <= k; n++) {
							color[x + i * n][y + j * n] = nowcolor3;
						}
						flag=0;
						break;
					}

				}
					
			}
		}
	}
	return flag;
}

void AIplay(int nowcolor2){
	int i,j,m=0,n,k,x,y,z,a[20][2];
	for(x=0;x<8;x++){
		for(y=0;y<8;y++){
			if (color[x][y] == 1 || color[x][y] == 2) {
				continue;
			}

			for (i = -1; i <= 1; i++) {
				for (j = -1; j <= 1; j++) {

				/*置いたところは無視*/
					if (i == 0 && j == 0) {
						continue;
					}
				/*隣が自色は無視*/
					if (color[i+x][j+y]==nowcolor2) {
						continue;
					}
				/*各方向に1マスずつ確認*/
					for (k = 1; k < 8; k++) {

					/*盤内だけでチェック*/
						if (x + i * k >= 0 && x + i * k < 8 && y + j * k >= 0 && y + j * k < 8) {
										
							/*空白があった場合はそれ以上試行する必要なし*/
							if (color[x + i * k][y + j * k] == 0) {
								break;
							}
							/*自色を見つけたらそこまでのコマをひっくり返す*/
							else if (color[x + i * k][y + j * k] == nowcolor2) {
									a[m][0]=x;
									a[m][1]=y;
									m+=1;
							}
						}
					}
				}
			}
		}
	}
	srand(time(NULL));
	z=rand()%m;	
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {

		/*置いたところは無視*/
			if (i == 0 && j == 0) {
				continue;
			}
			/*隣が自色は無視*/
			if (color[i+a[z][0]][j+a[z][1]]==nowcolor2) {
				continue;
			}
			/*各方向に1マスずつ確認*/
			for (k = 1; k < 8; k++) {

			/*盤内だけでチェック*/
				if (a[z][0] + i * k >= 0 && a[z][0] + i * k < 8 && a[z][1] + j * k >= 0 && a[z][1] + j * k < 8) {
										
					/*空白があった場合はそれ以上試行する必要なし*/
					if (color[a[z][0] + i * k][a[z][1] + j * k] == 0) {
							break;
					}
					/*自色を見つけたらそこまでのコマをひっくり返す*/
					else if (color[a[z][0] + i * k][a[z][1] + j * k] == nowcolor2) {
						color[a[z][0]][a[z][1]] = nowcolor2;
						for (n = 1; n <= k; n++) {
							color[a[z][0] + i * n][a[z][1] + j * n] = nowcolor2;
						}
						break;
					}
				}
			}	
		}	
	}
}

int check(int badpoint,int nowcolor2){
	int k,x,y,flag=1;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					flag = 1;
					if (color[x][y] == 1 || color[x][y] == 2) {
						continue;
					}

					/*置いたところは無視*/
					if (i == 0 && j == 0) {
						continue;
					}
					/*隣が自色は無視*/
					if (color[i+x][j+y]==nowcolor2) {
						continue;
					}
				/*各方向に1マスずつ確認*/
					for (k = 1; k < 8; k++) {

						/*盤内だけでチェック*/
						if (x + i * k >= 0 && x + i * k <= 8 && y + j * k >= 0 && y + j * k <= 8) {
									
							/*空白があった場合はそれ以上試行する必要なし*/
							if (color[x + i * k][y + j * k] == 0) {
								break;
							}
							/*自色を見つけたらそこまでのコマをひっくり返す*/
							else if (color[x + i * k][y + j * k] == nowcolor2) {
								flag=0;
								goto end;
							}
						}
					}
				}
			}
		}	
	}
	end:
	if(flag == 1) {
		badpoint+=1;
	}else if(flag==0){
		badpoint=0;
	}
	flag==1;
	return badpoint;
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