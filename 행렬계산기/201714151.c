#include <stdio.h>

//함수 정의부
void readMatrix(int arr[10][10], int rows, int cols); // 행렬을 읽어오는 함수
void printMatrix(int arr[10][10], int rows, int cols); // 행렬을 출력해주는 함수
void matrixAddSub(int arr1[10][10], int arr2[10][10], int rows, int cols, int mul); //행렬의 덧셈과 뺄셈을 수행하는 함수
void matrixScalarMultiply(int arr[10][10], int scalar, int rows, int cols); //행렬의 스칼라 곱을 수행하는 함수
void matrixMultiply(int arr1[10][10], int arr2[10][10], int rowsA, int colsA, int colsB); //행렬의 곱을 수행하는 함수

//메인 함수
int main(void) {
	int matrixA[10][10]; // 행렬 연산에 필요한 행렬의 크기는 최대 10x10으로 제한한다.
	int matrixB[10][10]; // 행렬 연산에 필요한 행렬의 크기는 최대 10x10으로 제한한다.
	int rowA, colA; // A행렬의 행과 열 변수
	int rowB, colB; // B행렬의 행과 열 변수
	int operation;// 연산자를 선택하는 변수
	char again = 'Y'; // 첫 연산 이후 다음 연산을 수행할 건지에 대한 판단 변수
	int scalar = 0; // 스칼라곱 연산 수행 시 스칼라 값 초기화
	int add = 1; // 덧셈 뺄셈 연산자의 구분에서 필요한 변수
	int sub = -1; // 덧셈 뺄셈 연산자의 구분에서 필요한 변수

	while (again == 'Y') {

		//메뉴 선택창 
		printf("**********************************************************\n");
		printf("*                 Matrix Caculator                       *\n");
		printf("*                                                        *\n");
		printf("*                                                        *\n");
		printf("*             1. Add matrix A & matrix B                 *\n");
		printf("*                                                        *\n");
		printf("*           2. Subtract matrix A & matrix B              *\n");
		printf("*                                                        *\n");
		printf("*          3. Scalar Multiplication matrix A             *\n");
		printf("*                                                        *\n");
		printf("*        4. Multiplication matrix A & matrix B           *\n");
		printf("*                                                        *\n");
		printf("**********************************************************\n");

		printf("Tell Me What You Want (1 or 2 or 3 or 4) : ");
		scanf(" %d", &operation); //사용자가 원하는 연산이 무엇인지 입력받는다.

		switch (operation) {

		case 1:
			printf("\nEnter the #rows and #cols for matrix A (ex> 3 3) : ");
			scanf("%d%d", &rowA, &colA); //A 행렬의 크기를 입력받는다.

			printf("Enter the #rows and #cols for matrix B (ex> 3 3) : ");
			scanf("%d%d", &rowB, &colB); //B 행렬의 크기를 입력받는다.

			while ((rowA != rowB) && (colA != colB)) {
				printf("\nMatrices must be the same size!!!\n");
				printf("\nEnter the #rows and #cols for matrix A (ex> 3 3) : ");
				scanf("%d%d", &rowA, &colA);

				printf("Enter the #rows and #cols for matrix B (ex> 3 3) : ");
				scanf("%d%d", &rowB, &colB);

			} // A 행렬과 B 행렬의 크기가 다를 경우 사용자에게 다시 입력받는다.


			printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); //A 행렬의 원소를 입력받는다.
			readMatrix(matrixA, rowA, colA); //A 행렬을 읽어온다.
			printf("\n\t\tMatrix A\n\n"); 
			printMatrix(matrixA, rowA, colA); //A 행렬을 출력해준다.


			printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); //B 행렬의 원소를 입력받는다.
			readMatrix(matrixB, rowB, colB); // B 행렬을 읽어온다.
			printf("\n\t\tMatrix B\n\n");
			printMatrix(matrixB, rowB, colB); //B 행렬을 출력해준다.


			printf("\nSum of matrix A and matrix B is : \n"); //결과값을 출력한다.
			matrixAddSub(matrixA, matrixB, rowA, colA, add);

			break;

		case 2:

			printf("\nEnter the #rows and #cols for matrix A (ex> 3 3) : ");
			scanf("%d%d", &rowA, &colA);  //A 행렬의 크기를 입력받는다.

			printf("Enter the #rows and #cols for matrix B (ex> 3 3) : ");
			scanf("%d%d", &rowB, &colB);  //B 행렬의 크기를 입력받는다.

			while ((rowA != rowB) && (colA != colB)) {
				printf("\nMatrices must be the same size\n");
				printf("\nEnter the #rows and #cols for matrix A: ");
				scanf("%d%d", &rowA, &colA);

				printf("Enter the #rows and #cols for matrix B: ");
				scanf("%d%d", &rowB, &colB);
			}// A 행렬과 B 행렬의 크기가 다를 경우 사용자에게 다시 입력받는다.

			printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); //A 행렬의 원소를 입력받는다.
			readMatrix(matrixA, rowA, colA); //A 행렬을 읽어온다.
			printf("\n\t\tMatrix A\n\n");
			printMatrix(matrixA, rowA, colA); //A 행렬을 출력해준다.

			printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); //B 행렬의 원소를 입력받는다.
			readMatrix(matrixB, rowB, colB); //B 행렬을 읽어온다.
			printf("\n\t\tMatrix B\n\n");
			printMatrix(matrixB, rowB, colB); //B 행렬을 출력해준다.

			printf("\nSubtract matrix A to matrix B is : \n"); //결과값을 출력한다.
			matrixAddSub(matrixA, matrixB, rowA, colA, sub);
			break;

		case 3:

			printf("\nEnter the scalar (ex> 3) : "); //스칼라 수를 입력한다.
			scanf("%d", &scalar);
			printf("\nThe scalar is: %d ", scalar); //입력한 수를 출력한다.


			printf("\nEnter the #rows and #cols for matrix A: "); // 행렬의 행과 열의 크기를 입력한다.
			scanf("%d%d", &rowA, &colA);

			printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // 행렬의 원소를 입력한다.
			readMatrix(matrixA, rowA, colA);
			printf("\n\t\tMatrix A\n\n"); //입력한 행렬을 출력한다.
			printMatrix(matrixA, rowA, colA);

			printf("\nThe scalar multiplication between matrixA * %d is: \n", scalar); //결과 값을 출력한다.
			matrixScalarMultiply(matrixA, scalar, rowA, colA);

			break;

		case 4:
			
			printf("\nEnter the #rows and #cols for matrix A (ex> 3 3) : ");  //A 행렬의 크기를 입력받는다.
			scanf("%d%d", &rowA, &colA);

			printf("Enter the #rows and #cols for matrix B  (ex> 3 3) : ");  //B 행렬의 크기를 입력받는다.
			scanf("%d%d", &rowB, &colB);

			
			while (colA != rowB) //행렬 A의 열의 값과 행렬 B의 행의 값이 다른 경우 
			{
				printf("\n\nError! cols of first matrix not equal to row of second.\n\n");
				printf("\nEnter the #rows and #cols for matrix A (ex> 3 3): ");
				scanf("%d%d", &rowA, &colA);

				printf("Enter the #rows and #cols for matrix B(ex> 3 3): ");
				scanf("%d%d", &rowB, &colB);
			}//사용자에게 다시 입력을 받는다.

			printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // A 행렬의 원소를 입력받는다.
			readMatrix(matrixA, rowA, colA);
			printf("\n\t\tMatrix A\n\n"); // A 행렬을 출력해준다.
			printMatrix(matrixA, rowA, colA);

			printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); // B 행렬의 원소를 입력받는다.
			readMatrix(matrixB, rowB, colB);
			printf("\n\t\tMatrix A\n\n"); // B 행렬을 출력해준다.
			printMatrix(matrixB, rowB, colB);

			matrixMultiply(matrixA, matrixB, rowA, colA, colB); //결과값을 출력한다.

			break;

		default:
			printf("\n Wrong!!! You have to choose number 1 ~ 4 !!!!!"); //메뉴 선택을 잘못했을 경우 출력
			break;
		}

		printf("\n\nDo you want to calculate again? Y/N\n"); // 연산 수행을 마치고 다른 연산을 계속 수행할 것인지 사용자에게 묻는다.
		scanf(" %c", &again);
		again = toupper(again);
	}
	printf("\n\n***********************GOODBYE~!!!************************\n\n");

	system("pause");
	return 0;
}


void readMatrix(int arr[10][10], int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		printf("\t%d entries for row %d: ", cols, i + 1);
		for (j = 0; j < cols; j++) {
			scanf("%d", &arr[i][j]);
		}
	}//각 행 별로 행렬을 읽어온다.

	return;
}

void printMatrix(int arr[10][10], int rows, int cols) {
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}// 사용자가 입력한 원소를 바탕으로 전체 행렬을 출력해준다.
}


void matrixAddSub(int arr1[10][10], int arr2[10][10], int rows, int cols, int mul) {
	int i, j;
	int sumM[10][10];
	int scaM[10][10];
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			scaM[i][j] = mul * arr2[i][j];
		}
	}


	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			sumM[i][j] = arr1[i][j] + scaM[i][j];
			printf("\t%d", sumM[i][j]);
		}
		printf("\n");
	}
} // mul 변수의 값에 따라 1 인 경우 덧셈 연산, -1 인 경우 뺄셈 연산을 수행한다.


void matrixScalarMultiply(int arr[10][10], int scalar, int rows, int cols) {
	int i, j;
	int scaM[10][10];
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			scaM[i][j] = scalar * arr[i][j];
			printf("%d\t", scaM[i][j]);
		}// 각 원소에 scalar 값을 곱한다.
		printf("\n");
	}

}

void matrixMultiply(int arr1[10][10], int arr2[10][10], int rowsA, int colsA, int colsB) {
	int i, j, k;
	int mulM[10][10];

	// 행렬의 모든 값을 0으로 초기화한다.
	for (i = 0; i < rowsA; ++i)
		for (j = 0; j < colsB; ++j)
		{
			mulM[i][j] = 0;
		}

	for (i = 0; i < rowsA; ++i)
		for (j = 0; j < colsB; ++j)
			for (k = 0; k < colsA; ++k)
			{
				mulM[i][j] += arr1[i][k] * arr2[k][j];
			}
	printf("\nOutput Matrix:\n");
	for (i = 0; i < rowsA; ++i)
		for (j = 0; j < colsB; ++j)
		{
			printf("\t%d ", mulM[i][j]);
			if (j == colsB - 1)
				printf("\n\n");
		}
}