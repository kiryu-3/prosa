#include <stdio.h>

int main(void) {

    float fkazu,skazu,kekka;
    int i,j,enzansi;

    printf("何回ループするかを選択してください\n");
    scanf("%d",&j);
    if(j<=0){
	printf("ERROR!\n");
	return 0;
    }

    for(i=0; i<j; i++){
    	printf("最初の数字を入力してENTERボタンを押してください\n");
    	scanf("%f",&fkazu);
    	printf("次の数字を入力してENTERボタンを押してください\n");
    	scanf("%f",&skazu);
    	printf("四則演算を選択してください\n＋:0 ー:1 ×:2 ÷:3\n");
    	scanf("%d",&enzansi);
	
    	if(enzansi == 0){;
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
        	printf("ERROR!\n");
    	}
    }
    return 0;
}	