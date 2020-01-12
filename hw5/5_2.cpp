#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10000
int main(int argc, char *argv[]) {
    int heap[150];
	int i=0,a,b,buffer,num,count;
    char input[max];
    char *temp;
    printf("please input a max heap: ");
    gets(input);
    temp=input;
    while((temp=strtok(temp," \n"))!=NULL){
        heap[++i]=atoi(temp);
        temp=NULL;
    }
    count = i;
	printf("you want to delete: ");
    scanf("%d",&a);
    
	for(i=1;i<=count;i++){
		if(heap[i]==a){
		   heap[i]=heap[count];
		   heap[count]=NULL;
		   num = i;
		}
	}
	
	while(1){
		if(heap[num]<heap[num*2]&&heap[num*2]>heap[num*2+1]){  // left > right
			buffer = heap[num];
			heap[num]=heap[num*2];
			heap[num*2]=buffer;
			num*=2;
			break;
		}
		else if(heap[num]<heap[num*2+1]&&heap[num]<heap[num*2+1]){ // right > left
			buffer = heap[num];
			heap[num]=heap[num*2+1];
			heap[num*2+1]=buffer;
			break;
			
		} 
	}
    
    printf("new heap: ");
    for(i=1;i<count;i++){
        printf("%d ",heap[i]);
    }
	
	return 0;
}
