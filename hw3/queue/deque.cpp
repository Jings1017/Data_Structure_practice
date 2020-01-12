#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 50
void pushf(int num,int n,int a[]){
	int i;
	if(n==0)
		a[0]=num;
	else{
	    for(i=n;i>0;i--)
		    a[i]=a[i-1];
		a[0]=num;
	}
}
void popf(int n,int a[]){
	int i;
	for(i=0;i<n;i++){
	   	a[i]=a[i+1];
	}
}
int main(){
	int deque[max_size],i=0,n=0,num;
	char mode[max_size];
	begin:scanf("%s",mode);
	
	if(strcmp(mode,"push_front")==0){
		scanf("%d",&num);
		pushf(num,n,deque);
	    n++;
	    goto begin;
    }
	else if(strcmp(mode,"push_back")==0){
		scanf("%d",&num);
		deque[n]=num;
	    n++;
	    goto begin;
	}
	else if(strcmp(mode,"pop_front")==0){
	    popf(n,deque);
		n--;
	    goto begin;
	}
	else if(strcmp(mode,"pop_back")==0){
		deque[n-1]=0;
	    n--;
	    goto begin;
	}
	else if(strcmp(mode,"show")==0){
        for(i=0;i<n;i++){
          printf("%d ",deque[i]);
		}
	    printf("\n");
	}
}