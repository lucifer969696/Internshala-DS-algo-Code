//Create 2 functions namely first() and second() apart from main(). Read 3 test scores of a cricketer in main() and call first() that calculates the average score. From first() call function second() that prints the smallest score.
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
void second(){
	if(a<b||a<c){
		cout<<a;
	}
	else if(b<a||b<c){
		cout<<b<<endl;
	}
	else{
		cout<<c<<endl;
	}
}
void first(){
	float x;
	x=(a+b+c)/3;
	cout<<x<<endl;
	second();
}
int main(){
	cin>>a>>b>>c;
	first();
}
