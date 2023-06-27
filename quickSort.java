package quick_sort;
import java.util.Scanner;
// Mang nhap khong dung ArrayList
public class quickSort {
	public int arr[];
	public int LB;
	public int KB;
	Scanner sc = new Scanner(System.in);
	public static int partion(int arr[], int LB, int UB) {
		int i = LB + 1;
		int j = UB; 
		while(i<=j){
			while(arr[i] < arr[LB]) i++;
			while(arr[j] > arr[LB]) j--;
			if(i<j){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
				j--;
			} 
		}
		int tmp = arr[LB];
		arr[LB] = arr[j];
		arr[j] = tmp;
		return j;
	}
	public static void qSort(int arr[], int LB,int UB) {
		if (LB < UB){
			int pivot = partion(arr, LB, UB);
			qSort (arr, LB,pivot-1);
			qSort (arr, pivot+1,UB);
		}	
	}
	public void printArray(int arr[], int n){
		for (int i = 0; i < n; i++){
            System.out.println("arr["+i+"] = ");

        }
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.println("Nhap so phan tu cua mang: ");
	    n = sc.nextInt();
	    int[] arr = new int[n];
	    System.out.println("Nhap phan tu cua mang");
		for (int i = 0; i < n; i++){
            System.out.println("arr["+i+"] = ");
            arr[i] = sc.nextInt();
        }
		partion(arr,0,n-1);
		qSort(arr,0,n-1);
		System.out.println("Mang da sap xep: ");
		for (int i = 0; i < n; i++){
            System.out.print(arr[i]+" ");
        }
	}
}
