#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cout<<"Enter country numbers: "<<endl;
	cin>>n;
	int *gdp;
	gdp=(int *)malloc(sizeof(int)*n);
	for (int i=0;i<n;i++){
		cin>>gdp[i];
	}
	for (int i=0;i<n;i++){
		cout<<gdp[i]<<endl;
	}	
}
