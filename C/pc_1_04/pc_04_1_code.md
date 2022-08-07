``` C
#include <stdio.h>

int main(void) {

    float fkazu,skazu,kekka;
    int enzansi;

    printf("最初の数字を入力してENTERボタンを押してください\n");
    scanf("%f",&fkazu);
    printf("次の数字を入力してENTERボタンを押してください\n");
    scanf("%f",&skazu);
    printf("四則演算を選択してください\n＋:0 ー:1 ×:2 ÷:3\n");
    scanf("%d",&enzansi);

    switch(enzansi){
    case 0:
        kekka = fkazu + skazu;
        printf("%f + %f = %f\n", fkazu,skazu,kekka);
        break;
    case 1:
        kekka = fkazu - skazu ;
        printf("%f - %f = %f\n", fkazu,skazu,kekka);
        break;
    case 2:
        kekka = fkazu * skazu ;
        printf("%f * %f = %f\n", fkazu,skazu,kekka);
        break;
    case 3:
        kekka = fkazu / skazu ;
        printf("%f / %f = %f\n", fkazu,skazu,kekka);
        break;
    default:
        printf("ERROR!");
        break;
    }
    return 0;
}
```