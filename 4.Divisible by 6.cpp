#include<bits/stdc++.h>
using namespace std;
void diviby6(long a){
	if (a%6==0){
		cout<<"Yes "<<a<<" is divisible by 6."<<endl;
	}
	else{
		cout<<"No "<<a<<" is not divisible by 6."<<endl;
	}
}
int main(){
	long n;
	cin>>n;
	diviby6(n);
}
