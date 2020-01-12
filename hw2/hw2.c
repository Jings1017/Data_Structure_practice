#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int n,m,x,y,i,j,k,ibug,jbug,count,num=0,matrix[42][22];
    int imove[8]= {-1,0,1,1,1,0,-1,-1};
    int jmove[8]= {1,1,1,0,-1,-1,-1,0}; 
    srand(time(NULL));
    printf("Please input n: ");
    scanf("%d",&n);
    printf("Please input m: ");
    scanf("%d",&m); 
	printf("Please input ibug: ");
    scanf("%d",&ibug); 
	printf("Please input jbug: ");
    scanf("%d",&jbug);
    for(i=0;i<42;i++)
        for(j=0;j<22;j++)
            matrix[i][j]=-1;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            matrix[i+1][j+1] = 0;
    while(count<50000){
        do{
            x=ibug;
            y=jbug;
            k=rand()%8;
            x=x+imove[k]; 
            y=y+jmove[k];
        }while(matrix[x][y] == -1);
        ibug = x;   
        jbug = y;
        matrix[ibug][jbug]+=1; 

        for(i=0; i<n; i++){
            for(j=0; j<m; j++)
                if(!matrix[i+1][j+1]){
                    num++;
                    break;
                }
            if(num>0)
                break;
        }
        if(num==0)
            break;
        num=0; 
        count++;
    }
    printf("\n Total moves %d \n", count);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++)
            printf("%4d", matrix[i+1][j+1]);
        printf("\n");
    }
    return 0;
}