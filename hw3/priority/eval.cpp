#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
	string prefix;
	int i,n;
	cout<<"input prefix: ";
	getline(cin,prefix,'\n');
	stack<float> Stack;
	n=prefix.size()-1;
	for(i=n;i>=0;i--){ 
	    if(prefix[i]==' ')
		    continue;
		else if(isdigit(prefix[i])){
			if(isdigit(prefix[i-1])!=1)
			   Stack.push(prefix[i]-'0'); 
			else{
			   Stack.push((prefix[i-1]-'0')*10+(prefix[i]-'0'));
			   prefix[i-1]=' ';
			}
		}
		else if (prefix[i]=='+'||'-'||'*'||'/'){ 
			float o1=Stack.top(); 
			Stack.pop(); 
			float o2=Stack.top(); 
			Stack.pop(); 
			switch(prefix[i]){
			case '+': 
				Stack.push(o1 + o2); break; 
			case '-': 
				Stack.push(o1 - o2); break; 
			case '*': 
				Stack.push(o1 * o2); break; 
			case '/': 
				Stack.push(o1 / o2); break; 
			} 
		} 
	} 
	cout<<Stack.top()<<endl;
	return 0; 
} 
