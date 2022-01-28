#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void out(char arr[3][3]);
void tictoe();
int cekMenang(char arr[3][3]);

// where AI opponent? idk man
int main(){
	//code by Mr Shimmer
	char c;
	while(c!='q'){
		system("cls");
		printf("a. TicTacToe\n");
		printf("q. Exit\n");
		c = getch();
		if(c == 'a')tictoe();
	}
	return 0;
}

void out(char arr[3][3]){
	printf("-----\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c ",arr[i][j]);
		}printf("\n");
	}
	printf("-----\n\n");
	return;
}

void tictoe(){
	char k='0';
	
	char arr[3][3];
	bool vis[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			k++;
			arr[i][j] = k;
			vis[i][j] = false;
		}
	}

	int counter=0;
	
	while(counter != 9){
		system("cls");
		if(counter%2 == 0){
			printf("it's O's turn\n");
			out(arr);
			// input
			int a  = getch();
			a-=48;
			int x=0,y=0;
			// ubah integer jadi koordinat array
			for(int i=0;i<a;i++){
				if(i%3 != 0){
					y++;
				}else{
					y = 0;
					x++;
				}
			}
			// cek giliran
			if(vis[x-1][y] == true){
				printf("this is not your place\n");
				Sleep(1000);
				goto jump;
			}
			arr[x-1][y] = 'O';
			vis[x-1][y] = true;
			// cek menang
			int r = cekMenang(arr);
			if(r == 1)goto selesai;
			else if(r ==2 && counter == 8){
				system("cls");
				printf("fin~\n");
				out(arr);
				printf("Nobody wins\n");
				goto selesai;
			}
		}
		else{
			printf("it's X's turn\n");
			out(arr);
			// input
			int a  = getch();
			a-=48;
			int x=0,y=0;
			// ubah integer jadi koordinat array
			for(int i=0;i<a;i++){
				if(i%3 != 0){
					y++;
				}else{
					y = 0;
					x++;
				}
			}
			// cek giliran
			if(vis[x-1][y] == true){
				printf("this is not your place\n");
				Sleep(1000);
				goto jump;
			}
			arr[x-1][y] = 'X';
			vis[x-1][y] = true;
			//cek menang
			int r = cekMenang(arr);
			if(r == 1)goto selesai;
			else if(r ==2 && counter == 8){
				system("cls");
				printf("fin~\n");
				out(arr);
				printf("Nobody wins\n");
				goto selesai;
			}
		}
		counter++;
		jump:;
	}
	system("cls");
	printf("fin~\n");
	out(arr);
	selesai:;
	printf("\n\n");
	system("pause");
}

int cekMenang(char arr[3][3]){
	// untuk X
	if(arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nX won this game\n");
		return 1;
	}
	else if(arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nX won this game\n");
		return 1;
	}
	else if(arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nX won this game\n");
		return 1;
	}
	else if(arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nX won this game\n");
		return 1;
	}
	else if(arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nX won this game\n");
		return 1;
	}
	else if(arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nX won this game\n");
		return 1;
	}
	else if(arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nX won this game\n");
		return 1;
	}
	else if(arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nX won this game\n");
		return 1;
	}
	// untuk O
	else if(arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nO won this game\n");
		return 1;
	}
	else if(arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nO won this game\n");
		return 1;
	}
	else if(arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nO won this game\n");
		return 1;
	}
	else if(arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nO won this game\n");
		return 1;
	}
	else if(arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nO won this game\n");
		return 1;
	}
	else if(arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nO won this game\n");
		return 1;
	}
	else if(arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nO won this game\n");
		return 1;
	}
	else if(arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O'){
		system("cls");
		printf("fin~\n");
		out(arr);
		printf("\nO won this game\n");
		return 1;
	}
	else{//ketika belum ada yang menang
		return 2;
	}
}

// logic untuk 1-9 menjadi index
//int a  = getch();
//			a-=48;
//		int x=0,y=0;
//			
//			for(int i=0;i<a;i++){
//				if(i%3 != 0){
//					y++;
//				}else {
//					y = 0;
//					x++;
//				}
//			}
//		printf("x = %d y = %d\n",x-1,y);

