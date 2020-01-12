#include <stdio.h> 
struct Edge{ 
    int src, dest, weight; 
}; 
struct Graph{ 
    int V, E; 
    Edge* edge; 
}; 
struct subset{ 
    int parent,rank; 
}; 
struct Graph* createGraph(int V, int E){ 
    Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
}  
int find(struct subset a[], int i){ 
    if (a[i].parent != i) a[i].parent = find(a,a[i].parent); 
    return a[i].parent; 
} 
void Union(struct subset a[], int x, int y){ 
    int xroot = find(a, x) , yroot = find(a, y); 
    if (a[xroot].rank < a[yroot].rank) 
        a[xroot].parent = yroot; 
    else if (a[xroot].rank > a[yroot].rank) 
        a[yroot].parent = xroot; 
    else{ 
        a[yroot].parent = xroot; 
        a[xroot].rank++; 
    } 
}  
void sollin(struct Graph* graph){ 
    int V = graph->V, E = graph->E; 
    int *min = new int[V];
    int numTrees = V , MSTweight = 0;
    struct subset *subsets = new subset[V]; 
	Edge *edge = graph->edge; 
    for (int v = 0; v < V; ++v){ 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
        min[v] = -1; 
    }  
    while (numTrees > 1){ 
        for(int v = 0; v < V; ++v) min[v] = -1; 
        for (int i=0; i<E; i++) { 
            int s1 = find(subsets, edge[i].src); 
            int s2 = find(subsets, edge[i].dest); 
            if (s1 != s2){ 
                if (edge[min[s1]].weight > edge[i].weight ||min[s1] == -1 )  min[s1] = i; 
                if (edge[min[s2]].weight > edge[i].weight ||min[s2] == -1 )  min[s2] = i; 
            } 
            else continue; 
        } 
        for (int i=0; i<V; i++){ 
            if (min[i] != -1){ 
                int s1 = find(subsets, edge[min[i]].src); 
                int s2 = find(subsets, edge[min[i]].dest); 
                if (s1 == s2) continue; 
                printf("%d %d %d\n",edge[min[i]].src,edge[min[i]].dest,edge[min[i]].weight); 
                Union(subsets, s1, s2); 
                numTrees--; 
            } 
        } 
    } 
    return; 
}
int main(){ 
    int n , i ,max=0, v1[100],v2[100],val[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d %d %d",&v1[i],&v2[i],&val[i]); 
		if(v2[i]>max) max = v2[i];
	} 
    int V = max+1 ,E = n;
    struct Graph* graph = createGraph(V, E); 
    for(i=0;i<n;i++){
    	graph->edge[i].src = v1[i];
    	graph->edge[i].dest = v2[i];
    	graph->edge[i].weight = val[i];
   	}
    printf("\n\nresult: \n\n");
    sollin(graph); 
    return 0; 
}
