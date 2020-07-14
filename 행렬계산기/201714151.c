#include <stdio.h>

//�Լ� ���Ǻ�
void readMatrix(int arr[10][10], int rows, int cols); // ����� �о���� �Լ�
void printMatrix(int arr[10][10], int rows, int cols); // ����� ������ִ� �Լ�
void matrixAddSub(int arr1[10][10], int arr2[10][10], int rows, int cols, int mul); //����� ������ ������ �����ϴ� �Լ�
void matrixScalarMultiply(int arr[10][10], int scalar, int rows, int cols); //����� ��Į�� ���� �����ϴ� �Լ�
void matrixMultiply(int arr1[10][10], int arr2[10][10], int rowsA, int colsA, int colsB); //����� ���� �����ϴ� �Լ�

//���� �Լ�
int main(void) {
	int matrixA[10][10]; // ��� ���꿡 �ʿ��� ����� ũ��� �ִ� 10x10���� �����Ѵ�.
	int matrixB[10][10]; // ��� ���꿡 �ʿ��� ����� ũ��� �ִ� 10x10���� �����Ѵ�.
	int rowA, colA; // A����� ��� �� ����
	int rowB, colB; // B����� ��� �� ����
	int operation;// �����ڸ� �����ϴ� ����
	char again = 'Y'; // ù ���� ���� ���� ������ ������ ������ ���� �Ǵ� ����
	int scalar = 0; // ��Į��� ���� ���� �� ��Į�� �� �ʱ�ȭ
	int add = 1; // ���� ���� �������� ���п��� �ʿ��� ����
	int sub = -1; // ���� ���� �������� ���п��� �ʿ��� ����

	while (again == 'Y') {

		//�޴� ����â 
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
		scanf(" %d", &operation); //����ڰ� ���ϴ� ������ �������� �Է¹޴´�.

		switch (operation) {

		case 1:
			printf("\nEnter the #rows and #cols for matrix A (ex> 3 3) : ");
			scanf("%d%d", &rowA, &colA); //A ����� ũ�⸦ �Է¹޴´�.

			printf("Enter the #rows and #cols for matrix B (ex> 3 3) : ");
			scanf("%d%d", &rowB, &colB); //B ����� ũ�⸦ �Է¹޴´�.

			while ((rowA != rowB) && (colA != colB)) {
				printf("\nMatrices must be the same size!!!\n");
				printf("\nEnter the #rows and #cols for matrix A (ex> 3 3) : ");
				scanf("%d%d", &rowA, &colA);

				printf("Enter the #rows and #cols for matrix B (ex> 3 3) : ");
				scanf("%d%d", &rowB, &colB);

			} // A ��İ� B ����� ũ�Ⱑ �ٸ� ��� ����ڿ��� �ٽ� �Է¹޴´�.


			printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); //A ����� ���Ҹ� �Է¹޴´�.
			readMatrix(matrixA, rowA, colA); //A ����� �о�´�.
			printf("\n\t\tMatrix A\n\n"); 
			printMatrix(matrixA, rowA, colA); //A ����� ������ش�.


			printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); //B ����� ���Ҹ� �Է¹޴´�.
			readMatrix(matrixB, rowB, colB); // B ����� �о�´�.
			printf("\n\t\tMatrix B\n\n");
			printMatrix(matrixB, rowB, colB); //B ����� ������ش�.


			printf("\nSum of matrix A and matrix B is : \n"); //������� ����Ѵ�.
			matrixAddSub(matrixA, matrixB, rowA, colA, add);

			break;

		case 2:

			printf("\nEnter the #rows and #cols for matrix A (ex> 3 3) : ");
			scanf("%d%d", &rowA, &colA);  //A ����� ũ�⸦ �Է¹޴´�.

			printf("Enter the #rows and #cols for matrix B (ex> 3 3) : ");
			scanf("%d%d", &rowB, &colB);  //B ����� ũ�⸦ �Է¹޴´�.

			while ((rowA != rowB) && (colA != colB)) {
				printf("\nMatrices must be the same size\n");
				printf("\nEnter the #rows and #cols for matrix A: ");
				scanf("%d%d", &rowA, &colA);

				printf("Enter the #rows and #cols for matrix B: ");
				scanf("%d%d", &rowB, &colB);
			}// A ��İ� B ����� ũ�Ⱑ �ٸ� ��� ����ڿ��� �ٽ� �Է¹޴´�.

			printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); //A ����� ���Ҹ� �Է¹޴´�.
			readMatrix(matrixA, rowA, colA); //A ����� �о�´�.
			printf("\n\t\tMatrix A\n\n");
			printMatrix(matrixA, rowA, colA); //A ����� ������ش�.

			printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); //B ����� ���Ҹ� �Է¹޴´�.
			readMatrix(matrixB, rowB, colB); //B ����� �о�´�.
			printf("\n\t\tMatrix B\n\n");
			printMatrix(matrixB, rowB, colB); //B ����� ������ش�.

			printf("\nSubtract matrix A to matrix B is : \n"); //������� ����Ѵ�.
			matrixAddSub(matrixA, matrixB, rowA, colA, sub);
			break;

		case 3:

			printf("\nEnter the scalar (ex> 3) : "); //��Į�� ���� �Է��Ѵ�.
			scanf("%d", &scalar);
			printf("\nThe scalar is: %d ", scalar); //�Է��� ���� ����Ѵ�.


			printf("\nEnter the #rows and #cols for matrix A: "); // ����� ��� ���� ũ�⸦ �Է��Ѵ�.
			scanf("%d%d", &rowA, &colA);

			printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // ����� ���Ҹ� �Է��Ѵ�.
			readMatrix(matrixA, rowA, colA);
			printf("\n\t\tMatrix A\n\n"); //�Է��� ����� ����Ѵ�.
			printMatrix(matrixA, rowA, colA);

			printf("\nThe scalar multiplication between matrixA * %d is: \n", scalar); //��� ���� ����Ѵ�.
			matrixScalarMultiply(matrixA, scalar, rowA, colA);

			break;

		case 4:
			
			printf("\nEnter the #rows and #cols for matrix A (ex> 3 3) : ");  //A ����� ũ�⸦ �Է¹޴´�.
			scanf("%d%d", &rowA, &colA);

			printf("Enter the #rows and #cols for matrix B  (ex> 3 3) : ");  //B ����� ũ�⸦ �Է¹޴´�.
			scanf("%d%d", &rowB, &colB);

			
			while (colA != rowB) //��� A�� ���� ���� ��� B�� ���� ���� �ٸ� ��� 
			{
				printf("\n\nError! cols of first matrix not equal to row of second.\n\n");
				printf("\nEnter the #rows and #cols for matrix A (ex> 3 3): ");
				scanf("%d%d", &rowA, &colA);

				printf("Enter the #rows and #cols for matrix B(ex> 3 3): ");
				scanf("%d%d", &rowB, &colB);
			}//����ڿ��� �ٽ� �Է��� �޴´�.

			printf("\n\tEnter elements of Matrix A a %d x %d matrix.\n", rowA, colA); // A ����� ���Ҹ� �Է¹޴´�.
			readMatrix(matrixA, rowA, colA);
			printf("\n\t\tMatrix A\n\n"); // A ����� ������ش�.
			printMatrix(matrixA, rowA, colA);

			printf("\n\tEnter elements of Matrix B a %d x %d matrix.\n", rowB, colB); // B ����� ���Ҹ� �Է¹޴´�.
			readMatrix(matrixB, rowB, colB);
			printf("\n\t\tMatrix A\n\n"); // B ����� ������ش�.
			printMatrix(matrixB, rowB, colB);

			matrixMultiply(matrixA, matrixB, rowA, colA, colB); //������� ����Ѵ�.

			break;

		default:
			printf("\n Wrong!!! You have to choose number 1 ~ 4 !!!!!"); //�޴� ������ �߸����� ��� ���
			break;
		}

		printf("\n\nDo you want to calculate again? Y/N\n"); // ���� ������ ��ġ�� �ٸ� ������ ��� ������ ������ ����ڿ��� ���´�.
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
	}//�� �� ���� ����� �о�´�.

	return;
}

void printMatrix(int arr[10][10], int rows, int cols) {
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}// ����ڰ� �Է��� ���Ҹ� �������� ��ü ����� ������ش�.
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
} // mul ������ ���� ���� 1 �� ��� ���� ����, -1 �� ��� ���� ������ �����Ѵ�.


void matrixScalarMultiply(int arr[10][10], int scalar, int rows, int cols) {
	int i, j;
	int scaM[10][10];
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			scaM[i][j] = scalar * arr[i][j];
			printf("%d\t", scaM[i][j]);
		}// �� ���ҿ� scalar ���� ���Ѵ�.
		printf("\n");
	}

}

void matrixMultiply(int arr1[10][10], int arr2[10][10], int rowsA, int colsA, int colsB) {
	int i, j, k;
	int mulM[10][10];

	// ����� ��� ���� 0���� �ʱ�ȭ�Ѵ�.
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