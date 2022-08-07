#include <stdio.h>

int main(void) {
    float fkazu,skazu,kekka;

    printf("最初の数字を入力してENTERボタンを押してください\n");
    scanf("%f",&fkazu);
    printf("次の数字を入力してENTERボタンを押してください\n");
    scanf("%f",&skazu);

    kekka = fkazu + skazu ;
    printf("%f + %f = %f\n", fkazu,skazu,kekka);
    kekka = fkazu - skazu ;
    printf("%f - %f = %f\n", fkazu,skazu,kekka);
    kekka = fkazu * skazu ;
    printf("%f * %f = %f\n", fkazu,skazu,kekka);
    kekka = fkazu / skazu ;
    printf("%f / %f = %f\n", fkazu,skazu,kekka);

    return 0;
}