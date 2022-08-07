#include <stdio.h>

float fkazu,skazu;

int input(void);
char enzansi(int);
float calc(int);

int main(void) {
	int enzansi1;
	char enzansi2;
	float kekka;

    for(int i=0; i<3; i++){
        enzansi1=input();
        enzansi2 = enzansi(enzansi1);
        kekka = calc(enzansi1);

        printf("%f %c %f = %f\n" , fkazu,enzansi2,skazu,kekka);

        return 0;
    }
}

int input(void){
	int x;

    printf("最初の数字を入力してENTERボタンを押してください\n");
    scanf("%f",&fkazu);
    printf("次の数字を入力してENTERボタンを押してください\n");
    scanf("%f",&skazu);
    printf("四則演算を選択してください\n＋:0 ー:1 ×:2 ÷:3\n");
    scanf("%d",&x);

	return x;
   }

char enzansi(int check){
	char y;

    if(check == 0){
        y = '+';
    }else if(check == 1){
        y = '-';
    }else if(check == 2){
       	y = '*';
    }else if(check == 3){
        y= '/';
    }else{
        printf("ERROR!");
		return 1;	 /* 強制終了 */
    }
	return y;
}

float calc(int check){
	float z;

    if(check == 0){
        z = fkazu + skazu;
    }else if(check == 1){
        z = fkazu - skazu ;
    }else if(check == 2){
       	z = fkazu * skazu ;
    }else if(check == 3){
        z = fkazu / skazu ;
    }else{
        ;		/* エラー処理はすでに住んでいるので空処理 */
    }
    return z;
}	