#include <iostream> 
using namespace std; 
int main(){
	int a[6]={23,67,5,31,89,20} ;
	cout<<"Danh sach da cho: ";
	for(int i =0;i<6;i++){
			cout<<a[i]<<" ";}
			cout<<"\n";
	for (int i = 0; i < 6; i++){
		bool swapped= true;
		for (int j = 5; j >=i+1; j--){
			if (a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				swapped = false;
			}
		}
		for(int i =0;i<6;i++){
			cout<<a[i]<<" ";}
			cout<<"\n";
}
	
	return 0;
}