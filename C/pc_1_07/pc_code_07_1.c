#include <stdio.h>

int main(void) {

    float fkazu,skazu,kekka;
    int enzansi;
    char a[4] = {'+','-','*','/'};
  
    for(int i=0; i<3; i++){
    	printf("最初の数字を入力してENTERボタンを押してください\n");
    	scanf("%f",&fkazu);
    	printf("次の数字を入力してENTERボタンを押してください\n");
    	scanf("%f",&skazu);
    	printf("四則演算を選択してください\n＋:0 ー:1 ×:2 ÷:3\n");
    	scanf("%d",&enzansi);
	
    	if(enzansi == 0){
        	kekka = fkazu + skazu;
        	printf("%f %c %f = %f\n", fkazu,a[enzansi],skazu,kekka);
    	}else if(enzansi == 1){
        	kekka = fkazu - skazu ;
        	printf("%f %c %f = %f\n", fkazu,a[enzansi],skazu,kekka);
    	}else if(enzansi == 2){
       		kekka = fkazu * skazu ;
        	printf("%f %c %f = %f\n", fkazu,a[enzansi],skazu,kekka);
    	}else if(enzansi == 3){
        	kekka = fkazu / skazu ;
        	printf("%f %c %f = %f\n", fkazu,a[enzansi],skazu,kekka);
    	}else{
        	printf("ERROR!");
    	}
    }
    return 0;
}