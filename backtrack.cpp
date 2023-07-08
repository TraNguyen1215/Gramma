/*Cho 1 bàn cờ nxn . Một quân mã được di chuyển tuân theo
luật chơi cờ vua được đặt trên bàn cờ tại ô đầu tiên có tọa độ x0, y0. Cần tìm 1
lộ trình gồm n^2 – 1 bước sao cho nó phủ toàn bộ bàn cờ ( mỗi ô được đi qua
đúng 1 lần). Thiết kế TT giải bài toán bằng phương pháp quay lui
*/
#include <iostream>
using namespace std;
#define MAX 8
int a[MAX][MAX] = {0};
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 0;// đếm các bước đi của con mã
int n;
// Hàm in các bước 
void PrintStep(){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n ; j++ ){
			printf("| %2d |", a[i][j]);
	}
	cout << endl;
	}
}
// Hàm di chuyển con mã (Thuật toán được thiết kế )
void backtrack(int x, int y){
	++dem;
	a[x][y] = dem;// gán vị trí của con mã đang đứng là số lần bước đi (Đánh dấu bước đi)
	for(int i = 0; i < 8 ;i++){
		// Kiểm tra con mã đã đi hết bàn cờ
		if(dem == n*n){
			cout<<"Cac buoc di la: \n";
			PrintStep();
			exit(0);
		}
		// Chưa đi hết thì tạo bước đi (tọa độ) mới cho con mã
		int nx = x + X[i];
		int ny = y + Y[i];
		//Ktra bước đi mới có phù hợp không
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 0)
			backtrack(nx, ny);// Hàm đệ quy di chuyển nếu bước đi phù hợp
	}
	//Nếu ko tìm được bước đi phải trả lại giá trị ban đầu
	--dem;// (Phần quay lui được thể hiện ở chỗ này )
	a[x][y] = 0;
}
int main(){
	cout<<"Nhap n: ";
	cin>>n;
	cout<<"Nhap toa do co ma ban dau: \n";
	int x,y;
	cout<<"Nhap toan do x: ";
	cin >> x;
	cout<<"Nhap toa do y: ";
	cin>>y;
	backtrack(x,y);
	//Nếu ko tìm được nước đi thì sẽ thông báo 
	cout << "Khong tim thay duong di.";
}