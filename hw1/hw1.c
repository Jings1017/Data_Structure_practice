#include <stdio.h>
#include <stdlib.h>

int rfib(int n){     /*遞迴 保留從0到n的值*/ 
    if ((n==0) || (n==1))   
        return n;
    else
        return rfib(n-1) + rfib(n-2);
}

int ifib(int n){     /*疊代 僅保留0,1,n-2,n-1,n的值*/ 
    int f, f1, f2,i;
    if ((n == 0) || (n == 1)) 
        return n;
    else{
   	    int f1=0,f2=1,f=0; 
        for (i=2; i<=n; i++) {
            f  = f1+f2;
	        f1 = f2;
	        f2 = f;
        }
    return f;
    }
}

int main(){         /**分別印出遞迴與疊代的結果**/  
    int n,num,i;
    scanf("%d",&num);  
    for(i=1;i<=num;i++){
    scanf("%d", &n);    
    printf("%d %d\n",rfib(n),ifib(n)); 
    }
    return 0;
} 