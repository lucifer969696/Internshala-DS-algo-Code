#include<bits/stdc++.h>
using namespace std;
float simple_interest(float pa, float roi, int time){
	float sp;
	sp=(pa*roi*time)/100;
	return sp;
}
int main(){
	float pa,roi;
	int time;
	cout<<"Enter Principal Amount, Rate of Interest, Time respectively: "<<endl;
	cin>>pa>>roi>>time;
	cout<<"Simple Interest is: "<<simple_interest(pa,roi,time)<<endl;
}

