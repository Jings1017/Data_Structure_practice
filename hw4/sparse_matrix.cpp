#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX 1024

typedef struct{ 
   int row;
   int col;
   int value;
}node;

typedef struct{ 
   int SMrow;
   int SMcol;
   int SMvalue;
   node data[MAX];
}matrix;


int main(){
	int i,j,k,l,sum=0,count=0;
    matrix *a,*b,*c,*d;
    
	a=(matrix *)malloc(sizeof(matrix));
    b=(matrix *)malloc(sizeof(matrix));
    c=(matrix *)malloc(sizeof(matrix)); 
    d=(matrix *)malloc(sizeof(matrix)); 
    
	printf("Please input the rows, columns and nonzero terms in a.\n");
    scanf("%d %d %d",&a->SMrow,&a->SMcol,&a->SMvalue);
	printf("Now, please input the row, column and value .\n");
    for(i=0 ; i < a->SMvalue ; i++)
        scanf("%d %d %d",&a->data[i].row,&a->data[i].col,&a->data[i].value);
    
	printf("Please input the rows, columns and nonzero terms in b.\n");
    scanf("%d %d %d",&b->SMrow,&b->SMcol,&b->SMvalue);
	printf("Now, please input the row, column and value .\n");
    for(i=0;i<b->SMvalue;i++)
        scanf("%d %d %d",&b->data[i].row,&b->data[i].col,&b->data[i].value);
	
	c->SMrow   = b->SMcol;
    c->SMcol   = b->SMrow;
    c->SMvalue = b->SMvalue;
	
	for(i=0;i<b->SMvalue;i++){  //transpose
        c->data[i].row   = b->data[i].col;
        c->data[i].col   = b->data[i].row;
        c->data[i].value = b->data[i].value;
	}
	
    printf("b transpose:\n");
    printf("numRows = %d, numCols = %d\n",c->SMrow ,c->SMcol);
    printf("The matrix by row, column and value: \n");
	for(i=0;i<c->SMvalue;i++)
        printf("%d %d %d\n",c->data[i].row,c->data[i].col,c->data[i].value);
    
    //mult
    d->SMrow   = a->SMrow;
    d->SMcol   = c->SMcol;
	for(i=0 ; i < a-> SMrow ; i++){
        for(j=0 ; j < c-> SMcol ; j++){
            for(k=0 ; k < a->SMvalue ; k++){
                for(l=0 ; l < c->SMvalue ; l++){
                    if(i == a->data[k].row && j == c->data[l].col && a->data[k].col == c->data[l].row)
                        sum += a->data[k].value * c->data[l].value;
                }
            }
            if(sum!=0){
                d->data[count].row=i;
                d->data[count].col=j;
                d->data[count].value=sum;
                count++;
				sum=0;
            }
        }
    }
    d->SMvalue = count;
    printf("a*b transpose:\n");
    printf("numRows = %d, numCols = %d \n",d->SMrow , d->SMcol);
    printf("The matrix by row, column and value: \n");
    for(i=0;i<d->SMvalue;i++)
        printf("%d %d %d\n",d->data[i].row,d->data[i].col,d->data[i].value);
}
