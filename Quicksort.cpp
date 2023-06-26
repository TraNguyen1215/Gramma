/*Cho dãy số nguyên A có n phần tử cần được sắp xếp thành dãy số
không giảm theo phương pháp sắp sếp nhanh QuickSort. Hãy thiết kế thuật
toán sắp xếp theo phương pháp chia để trị*/
// Quicksort là một trong những giải thuật theo phương pháp chia để trị
#include<iostream>
using namespace std;
// Ham doi cho hai so
void swapp(int a, int b){
	int tmp = a;
	a = b;
	b = tmp;
}
//Ham nhap mang
void importArray(int arr[], int n){
	//nhap mang 
	cout<<"Nhap mang: \n";
	for(int i = 0;i<n;i++){
		cout<<"arr["<<i<<"] = ";
		cin>>arr[i];
	}
}
// ham tim vi tri chia doan voi kieu dau ra la so nguyen
int partion(int arr[], int LB, int UB)// ham tim vi tri chia doan
{
	int i = LB + 1;// i la vi tri sau LB, LB la dau doan thuong la vi tri 0
	int j = UB; // goi j la vi tri cuoi doan va la vi tri can tim
	while(i<=j){
		while(arr[i] < arr[LB]) i++;// so sanh vi tri thu i voi vi tri dau doan cho den khi khong thoa man
		while(arr[j] > arr[LB]) j--;// so sanh vi tri thu j voi vi tri dau doan cho den khi khong thoa man
		if(i<j){
			// int tmp = arr[i];// doi cho cac so owr vi tri thu i va j
			// arr[i] = arr[j];
			// arr[j] = tmp;
            swapp(arr[i],arr[j]);// dung ham doi cho
			// sau khi doi cho thif i tang vaf j giam
			i++;
			j--;
		} 
	}
	// sau khi tim duoc vi tri chia doan thi doi vi tri dau doan voi vi tri j
	// int tmp = arr[LB];
	// arr[LB] = arr[j];
	// arr[j] = tmp;
    swapp(arr[LB],arr[j]);
	return j;// return ra vi tri phan doan
}
//ham thuc hien gia thuat quicksort
void quicksort(int arr[],int LB,int UB){
		if (LB < UB){
		int pivot = partion(arr, LB, UB); // gan bien pivot la vi tri phan doan
		//De quy sap xep hai mang con trai phai cua pivot
		quicksort (arr, LB,pivot-1);// trai 
		quicksort (arr, pivot+1,UB);//phai
	}	
}
//Ham xuat mang
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    	printf("\n");

}

int main(){
    /*Luu y nhap duoi 8 phan tu. tren 8 phan tu code chay lau*/
	int arr[100];
	int n;
	cout<<"Nhap so phan tu cua mang: ";
	cin>>n;
	importArray(arr,n);
	partion(arr,0,n-1);// LB =0, UB = n-1
	quicksort(arr,0,n-1);
	cout<<"Xuat mang da sap xep: \n";
	printArray(arr,n);
	return 0;
}