#include <iostream>
#include <fstream>  //文件流操作
#include <string>
#include <Windows.h>

using namespace std;

#define N 128

bool isPeak(int grid[N][N],int r,int c){
	if((grid[r][c] > grid[r-1][c]) && 
		(grid[r][c] > grid[r-1][c-1]) &&
		(grid[r][c] > grid[r-1][c+1]) &&
		(grid[r][c] > grid[r+1][c]) &&
		(grid[r][c] > grid[r+1][c-1]) &&
		(grid[r][c] > grid[r+1][c+1]) &&
		(grid[r][c] > grid[r][c-1]) &&
		(grid[r][c] > grid[r][c+1])){
			return true;
	}
	return false;
}

bool isValley(int grid[N][N],int r,int c){
	if((grid[r][c] < grid[r-1][c]) && 
		(grid[r][c] < grid[r+1][c]) &&
		(grid[r][c] < grid[r][c-1]) &&
		(grid[r][c] < grid[r][c+1])){
			return true;
	}
	return false;
}

void extremes(int grid[N][N], int a, int b){
	int max = grid[0][0];
	int min = grid[0][0];
	for(int i = 0;i<a;i++){
		for(int j = 0; j<b; j++){
			if(max < grid[i][j]){
				max = grid[i][j];
			}
			if(min > grid[i][j]){
				min = grid[i][j];
			}
		}
	}
	cout << min << endl;
	for(int i = 0;i<a;i++){
		for(int j = 0; j<b; j++){
			if (max == grid[i][j]){
				cout << "最高点的位置为行：" << i << " 列：" << j <<endl;
				cout << "最高点的海拔为：" << max << endl;
			}
			if (min == grid[i][j]){
				cout << "最低点的位置为行：" << i << " 列：" << j <<endl;
				cout << "最低点的海拔为：" << min << endl;
			}
		}
	}
}

int main(void){
	int nrows,ncols;
	int map[N][N];
	int count = 0;
	string filename;
	ifstream file;

	cout << "请输入文件名" << endl;
	cin >> filename;

	file.open(filename.c_str());
	if(file.fail()){
		cout << "打开输入文件出错" << endl;
		exit(1); //return 1;
	}

	file >> nrows >> ncols;

	if(nrows > N || ncols > N){
		cout << "网格太大，调整程序" << endl;
		exit(1);
	}

	//从数据文件读取到二维数组
	for(int i = 0;i < nrows;i++){
		for(int j=0; j<ncols;j++){
			file >> map[i][j];
		}
	}

	//判断并打印峰值的位置
	for(int i = 1; i<nrows-1; i++){
		for(int j = 1; j<ncols-1; j++){
			if(isPeak(map, i, j)){
				count++;
				cout << "峰点出现在行：" << i << " 列：" << j << endl;
			}
			else if(isValley(map, i, j)){
				cout << "谷点出现在行：" << i << " 列：" << j << endl;
			}

		}
		
	}

	cout << "共有" << count << "个峰点" << endl;
	extremes(map, nrows, ncols);


	system("pause");
	//关闭文件
	file.close();
	return 0;
}