#include <iostream>
#include <fstream>  //�ļ�������
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
				cout << "��ߵ��λ��Ϊ�У�" << i << " �У�" << j <<endl;
				cout << "��ߵ�ĺ���Ϊ��" << max << endl;
			}
			if (min == grid[i][j]){
				cout << "��͵��λ��Ϊ�У�" << i << " �У�" << j <<endl;
				cout << "��͵�ĺ���Ϊ��" << min << endl;
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

	cout << "�������ļ���" << endl;
	cin >> filename;

	file.open(filename.c_str());
	if(file.fail()){
		cout << "�������ļ�����" << endl;
		exit(1); //return 1;
	}

	file >> nrows >> ncols;

	if(nrows > N || ncols > N){
		cout << "����̫�󣬵�������" << endl;
		exit(1);
	}

	//�������ļ���ȡ����ά����
	for(int i = 0;i < nrows;i++){
		for(int j=0; j<ncols;j++){
			file >> map[i][j];
		}
	}

	//�жϲ���ӡ��ֵ��λ��
	for(int i = 1; i<nrows-1; i++){
		for(int j = 1; j<ncols-1; j++){
			if(isPeak(map, i, j)){
				count++;
				cout << "���������У�" << i << " �У�" << j << endl;
			}
			else if(isValley(map, i, j)){
				cout << "�ȵ�������У�" << i << " �У�" << j << endl;
			}

		}
		
	}

	cout << "����" << count << "�����" << endl;
	extremes(map, nrows, ncols);


	system("pause");
	//�ر��ļ�
	file.close();
	return 0;
}