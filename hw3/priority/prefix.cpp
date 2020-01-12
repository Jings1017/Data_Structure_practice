#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100

int priority(char);
int in2pre(char*);

int main(void) { 
    char infix[max]; 
    printf("input the infix: "); 
    scanf("%[^\n]s", &infix); 
    in2pre(infix); 
    return 0; 
} 

int priority(char op) { 
    int value; 
    switch(op) { 
        case'!':case'~': 
        	value = 15;  break;
        case '*': case '/': case'%':
            value = 13;  break;
        case '+': case '-': 
            value = 12;  break; 
		case '&':
			value = 8;   break;
		case '^':
			value = 7;   break;
		case ',':
			value = 1;   break;
        default: 
            value = 0;   break; 
    } 
    return value; 
}
int in2pre(char* infix) { 
    int i = strlen(infix)-1,top=0,j=0,k;
    char stack[max] ="",prefix[max]=""; 
    while(1){
        switch(infix[i]) {  //從最後面開始 
            case ')': 
                if(top < (sizeof(stack) / sizeof(char))) { 
                    stack[++top] = infix[i];   //放進stack 
                } 
                break;
            case '(':
                while(stack[top] != ')'){ 
					prefix[j++] = stack[top--]; //j往前一格 top退一格
                }
                top--; //不印出 ( 
                break;
            case '+': case '-': case '*': case '/': case '%': 
			case '!': case '~': case '&': case '^': case ',':
                while(priority(stack[top]) > priority(infix[i])) {  
					prefix[j++] = stack[top--];	
                } 
                if(top++ < (sizeof(stack) / sizeof(char))) { 
                    stack[top] = infix[i]; 
                } 
                break;  
            case ' ':
                break;
            default:
				prefix[j++] = infix[i];
                break; 
        }
		if(i == 0){
			while(top > 0) { 
				prefix[j++] = stack[top--];
			}
			prefix[j] = '\0';
			strrev(prefix);
			printf("prefix: ");
			for(k=0;k<j;k++){
			    printf("%c ", prefix[k]);
			}
			return 0;
		}
        i--;
    } 
} 
