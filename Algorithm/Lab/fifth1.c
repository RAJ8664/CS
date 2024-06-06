/*Author : RAJ ROY*/
/*Scholar id = 2212002*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX_SIZE 10


//Strassen’s algorithm for Matrix Multiplication;
 
/*

	A = |a  b|
		|c  d|	

	B = |e  f|
		|g  h|

	

	RES = |p5 + p4 - p2 + p6          		p1 + p2|
		  |p3 + p4				  p1 + p5 - p3 - p7|


where, 

	p1 = a * (f - h);
	p2 = (a + b) * h;
	p3 = (c + d) * e;
	p4 = d * (g - e);
	p5 = (a + d) * (e + h);
	p6 = (b - d) * (g + h);
	p7 = (a - c) * (e + f);

*/


int nextpowerof2(int k) {
    return pow(2, ceil(log2(k)));
}

void display(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) {
                printf("\t");
            }
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

void add(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void Strassen_algorithmA(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int size) {
	//base case
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    } 
    else {
        int new_size = size / 2;
        int a11[MAX_SIZE][MAX_SIZE], a12[MAX_SIZE][MAX_SIZE], a21[MAX_SIZE][MAX_SIZE], a22[MAX_SIZE][MAX_SIZE],
            b11[MAX_SIZE][MAX_SIZE], b12[MAX_SIZE][MAX_SIZE], b21[MAX_SIZE][MAX_SIZE], b22[MAX_SIZE][MAX_SIZE],
            c11[MAX_SIZE][MAX_SIZE], c12[MAX_SIZE][MAX_SIZE], c21[MAX_SIZE][MAX_SIZE], c22[MAX_SIZE][MAX_SIZE],
            p1[MAX_SIZE][MAX_SIZE], p2[MAX_SIZE][MAX_SIZE], p3[MAX_SIZE][MAX_SIZE], p4[MAX_SIZE][MAX_SIZE],
            p5[MAX_SIZE][MAX_SIZE], p6[MAX_SIZE][MAX_SIZE], p7[MAX_SIZE][MAX_SIZE],
            aResult[MAX_SIZE][MAX_SIZE], bResult[MAX_SIZE][MAX_SIZE];

        int i, j;


        //dividing the matrices into sub-matrices:
        for (i = 0; i < new_size; i++) {
            for (j = 0; j < new_size; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + new_size];
                a21[i][j] = A[i + new_size][j];
                a22[i][j] = A[i + new_size][j + new_size];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + new_size];
                b21[i][j] = B[i + new_size][j];
                b22[i][j] = B[i + new_size][j + new_size];
            }
        }


        // Calculating p1 to p7:

        add(a11, a22, aResult, new_size);	// a11 + a22
        add(b11, b22, bResult, new_size);	// b11 + b22
        Strassen_algorithmA(aResult, bResult, p1, new_size);
        // p1 = (a11+a22) * (b11+b22)


        add(a21, a22, aResult, new_size);	// a21 + a22
        Strassen_algorithmA(aResult, b11, p2, new_size);
        // p2 = (a21+a22) * (b11)


        sub(b12, b22, bResult, new_size);	 // b12 - b22
        Strassen_algorithmA(a11, bResult, p3, new_size);
        // p3 = (a11) * (b12 - b22)



        sub(b21, b11, bResult, new_size);	// b21 - b11
        Strassen_algorithmA(a22, bResult, p4, new_size);
        // p4 = (a22) * (b21 - b11)



        add(a11, a12, aResult, new_size);	// a11 + a12
        Strassen_algorithmA(aResult, b22, p5, new_size);
        // p5 = (a11+a12) * (b22)


        sub(a21, a11, aResult, new_size);	// a21 - a11
        add(b11, b12, bResult, new_size);

        // b11 + b12
        Strassen_algorithmA(aResult, bResult, p6, new_size);
        // p6 = (a21-a11) * (b11+b12)

        sub(a12, a22, aResult, new_size);	// a12 - a22
        add(b21, b22, bResult, new_size);

        // b21 + b22
        Strassen_algorithmA(aResult, bResult, p7, new_size);
         // p7 = (a12-a22) * (b21+b22)

        // calculating c21, c21, c11 e c22:

        add(p3, p5, c12, new_size);				// c12 = p3 + p5
        add(p2, p4, c21, new_size);				// c21 = p2 + p4

        add(p1, p4, aResult, new_size);			// p1 + p4
        add(aResult, p7, bResult, new_size);	// p1 + p4 + p7
        sub(bResult, p5, c11, new_size);		// c11 = p1 + p4 - p5 + p7	

        add(p1, p3, aResult, new_size);			// p1 + p3
        add(aResult, p6, bResult, new_size);   // p1 + p3 + p6
        sub(bResult, p2, c22, new_size);	// c22 = p1 + p3 - p2 + p6


         // Grouping the results obtained in a single matrix:
        for (i = 0; i < new_size; i++) {
            for (j = 0; j < new_size; j++) {
                C[i][j] = c11[i][j];
                C[i][j + new_size] = c12[i][j];
                C[i + new_size][j] = c21[i][j];
                C[i + new_size][j + new_size] = c22[i][j];
            }
        }
    }
}

void Strassen_algorithm(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int m, int n, int a, int b) {
    /* Check to see if these matrices are already square and have dimensions of a power of 2. If not,
 * the matrices must be resized and padded with zeroes to meet this criteria. */
    
    int k = fmax(fmax(m, n), fmax(a, b));
    int s = nextpowerof2(k);

    int Aa[MAX_SIZE][MAX_SIZE], Bb[MAX_SIZE][MAX_SIZE], Cc[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Aa[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            Bb[i][j] = B[i][j];
        }
    }

    Strassen_algorithmA(Aa, Bb, Cc, s);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d\t", Cc[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX_SIZE][MAX_SIZE] = {{1, 2, 1}, {5, 1, 1},{1, 1, 1}};
    int b[MAX_SIZE][MAX_SIZE] = {{1, 1, 1}, {7, 6, 1},{1, 1, 1}};
    Strassen_algorithm(a, b, 3, 3, 3, 3);
    return 0;
}
