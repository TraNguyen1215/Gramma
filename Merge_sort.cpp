/*Cho dãy số nguyên A có n phần tử cần được sắp xếp thành dãy số
không giảm theo phương pháp sắp sếp trộn MergeSort. Hãy thiết kế thuật toán
sắp xếp theo phương pháp chia để trị
note: tham khảo trên blogluyencode
*/
#include<iostream>
using namespace std;
//Ham nhap mang

void ImportArray(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]= ";
		cin>>arr[i];
	}
}

//Gop hai mang left va right
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;// số phần tử của mảng trái (Left)
    int n2 =  r - m;//Số phần tử của mảng phải (Right)
    // Tao cac mang tam de luu tru phan tu
    int L[n1], R[n2];
 
    // Copy du lieu sang cac mang tam
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
	}
    //Gop hai mang vua roi vao mang arr
    i = 0; //khởi tạo marg  con 1
    j = 0; //Khởi tạo mảng con 2
    k = l; //khởi tạo mảng lưu kết quả
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy các phan tu còn lai cua mang L vào arr neu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy các phan tu còn lai cua mang R vào arr neu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l là chi so trái và r là chi so phai cua mang can duoc sap xep 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tuong tu (l+r)/2, nhung cách này tránh tràn so khi l và r lon
        int m = l+(r-l)/2;
        // Goi hàm de quy tiep tuc chia dôi tung nua mang
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

/* Hàm xuat mang */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
int main()
{
	// int a[100],n;
	// cout<<"Nhap so phan tu cua mang: ";
	// cin>>n;
	// ImportArray(a,n);
   int a[] = {12, 11, 10, 14, 12, 13, 5, 6, 7};
   int n = sizeof(a)/sizeof(a[0]);
    printf("Mang da nhap: \n");
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    printf("\nSorted: \n");
    printArray(a, n);
    return 0;
}