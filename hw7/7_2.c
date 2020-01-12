#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define size 100
#define max(x, y) ( x>y? x: y ) 
#define min(x, y) ( x<y? x: y )
struct node{
	int id;
	int cost;
};
void set1(int n, int ee[], int m[][size]){
	memset(ee, 0, sizeof(int)*n);
	int i, j;
	for(i=1; i<n; i++)
		for(j=0; j<i; j++)
			if(m[j][i]!=0)
				ee[i] = max(ee[i], ee[j]+m[j][i]);
}
void set2(int n, int le[], int m[][size]){
	int i, j;
	for(i=0; i<n-1; i++)
		le[i] = INT_MAX;
	for(i=n-2; i>=0; i--)	
		for(j=i; j<n; j++)	
			if(m[i][j]!=0)
				le[i] = min(le[i], le[j]-m[i][j]);
}
int set3(int n, int e[], int l[], int ee[], int le[], int m[][size]){
	int i, j, k=0;
	/*set e[]*/
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(m[i][j]!=0)
				e[k++] = ee[i];
	k=0;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(m[j][i]!=0)
				l[k++] = le[i]-m[j][i];
	return k;
}
int main(int argc, char *argv[]){
	int i=0, j=0, N,k,max=0,v1[size],v2[size],val[size], m[size][size];
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%d %d %d %d",&k,&v1[i],&v2[i],&val[i]);
	for(i=0;i<N;i++){
		m[v1[i]][v2[i]]=val[i];
		if(v2[i]>max) max=v2[i];
	}
	int n = max+1 , num = n*(n+1)/2 , ee[n], le[n], e[num], l[num];
	set1(n, ee, m);
	le[n-1] = ee[n-1], le[0] = 0;
	set2(n, le, m);
	num = set3( n, e, l, ee, le, m);
	printf("\nact.   e   l   slack   critical   \n");
	for(i=0;i<N;i++){
		printf("%d   %3d%4d%5d       ",i+1,e[i],l[i],l[i]-e[i]);
		if(e[i]==l[i]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
