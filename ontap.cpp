#include <iostream> 
using namespace std; 
void part (int K[10], int LB, int UB, int j) {
	int i = LB + 1;
	j = UB;
	while(i <= j){
		while(K[i] < K[LB]) i++;
		while(K[j] > K[LB]) j--;
		if(i < j){
			int t = K[i]; 
			K[i] = K[j];
			K[j] = t;
			i++;
			j--;
		}
	}
	cout <<j;
	
}
int main(){
	int K[10];  
	int j; 
	int a[6]={13,86,45,21,9,2} ;
	for(int i =0;i<6;i++){
			cout<<a[i]<<" ";}
			cout<<"\n"; 
	part(K,1,6,j);
	cout<<"\n" ;
	return 0;
}