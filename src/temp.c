#include<stdio.h>
int main(){
	int a = 10;
    int b;
    scanf("%d", &b);
    if(a < b){
    	printf("b is large");
    }
    else{
    	printf("a is large");
    }
    printf("End of program");
    return 0;
}