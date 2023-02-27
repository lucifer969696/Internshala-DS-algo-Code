#include<bits/stdc++.h>
using namespace std;
int mintemp(int a, int b, int c){
	if(a<b){
		if (a<c){
			return a;
		}
		else{
			return c;
		}
	}
	else{
		if (b<c){
			return b;
		}
		else{
			return c;
		}
	}
}
int main(){
	int temp1,temp2,temp3;
	cout<<"Enter temperature: "<<endl;
	cin>>temp1>>temp2>>temp3;
	cout<<"Minimum temparature: "<<mintemp(temp1,temp2,temp3);
}
