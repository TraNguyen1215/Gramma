//tim vi tri phan doan tu gia thuat quicksort
#include <iostream> 
using namespace std; 
// ham tim vi tri phan doan
void part (int K[10], int LB, int UB, int j) {
	int i = LB + 1; // i la vi tri sau LB
	j = UB;// gan j laf vi tri cuoi doan(UB)
	while(i <= j){
		while(K[i] < K[LB]) i++;
		while(K[j] > K[LB]) j--;
		// thuc hien dieu kien, thoa man thi doi cho
		if(i < j){
			int t = K[i]; 
			K[i] = K[j];
			K[j] = t;
			// sau khi doi cho i tang va j giam
			i++;
			j--;
		}
	}
	// In ra vi tri can tim 
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