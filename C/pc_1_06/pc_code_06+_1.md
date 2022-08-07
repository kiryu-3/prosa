``` C
#include <stdio.h>

int main(void) {

    float fkazu,skazu,kekka,finish;
    int enzansi;

    while(1){
    //while(i<j){
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

		printf("計算を終了しますか？（はい:0を入力）\n");
		scanf("%d",&finish);
		
		if(finish==0){
			break;
		}else{
			;
		}
    }
    return 0;
}	
```