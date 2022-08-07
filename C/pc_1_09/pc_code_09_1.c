#include <stdio.h>

void input(void);
void calc(void);

float fkazu,skazu,kekka;
int enzansi;

int main(void) {

    for(int i=0; i<3; i++){
        input();
        calc(); 
    }
    return 0;
}

void input(void){
    printf("最初の数字を入力してENTERボタンを押してください\n");
    scanf("%f",&fkazu);
    printf("次の数字を入力してENTERボタンを押してください\n");
    scanf("%f",&skazu);
    printf("四則演算を選択してください\n＋:0 ー:1 ×:2 ÷:3\n");
    scanf("%d",&enzansi);
}

void calc(void){
    if(enzansi == 0){
        kekka = fkazu + skazu;
        printf("%f + %f = %f\n", fkazu,skazu,kekka);
    }else if(enzansi == 1){
        kekka = fkazu - skazu ;
        printf("%f - %f = %f\n", fkazu,skazu,kekka);
    }else if(enzansi == 2){
       	kekka = fkazu * skazu ;
        printf("%f * %f = %f\n", fkazu,skazu,kekka);
    }else if(enzansi == 3){
        kekka = fkazu / skazu ;
        printf("%f / %f = %f\n", fkazu,skazu,kekka);
    }else{
        printf("ERROR!");
    }
}