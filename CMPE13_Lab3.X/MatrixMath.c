/* ************************************************************************** */
//    Matrix Math implementing functions
/* ************************************************************************** */
#include <stdio.h>

/**
 * MatrixMultiply performs a matrix-matrix multiplication operation on two 3x3
 * matrices and returns the result in the third argument.
 */
void MatrixMultiply(float mat1[3][3], float mat2[3][3], float result[3][3])
{
    int a, b, c;
    float d;
    for (a = 0; a <= 2; a++) {
        for (b = 0; b <= 2; b++) {
            d = 0;
            for (c = 0; c <= 2; c++) {
                d = d + mat1[a][c] * mat2[c][b];
            }
            result[a][b] = d;
        }
    }
}

/**
 * MatrixAdd performs a matrix addition operation on two 3x3 matrices and 
 * returns the result in the third argument.
 */
void MatrixAdd(float mat1[3][3], float mat2[3][3], float result[3][3])
{
    int a, b;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            result[a][b] = mat1[a][b] + mat2[a][b];
        }
    }
}

/**
 * MatrixEquals checks if the two matrix arguments are equal. The result is
 * 0 if FALSE and 1 if TRUE to follow the standard C conventions of TRUE and
 * FALSE.
 */
int MatrixEquals(float mat1[3][3], float mat2[3][3])
{
    int a, b;
    int c = 1;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            if (mat1[a][b] != mat2[a][b]) {
                c = 0;
            }
        }
    }
    return c;
}
/**********************
 ********************************************************
 * Matrix - Scalar Operations
 *****************************************************************************/

/**
 * MatrixScalarMultiply performs the multiplication of a matrix by a scalar.
 * The result is returned in the third argument.
 */
void MatrixScalarMultiply(float x, float mat[3][3], float result[3][3])
{
    int a, b;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            result[a][b] = mat[a][b] * x;
        }
    }
}

/**
 * MatrixScalarAdd performs the addition of a matrix by a scalar. The result
 * is returned in the third argument.
 */
void MatrixScalarAdd(float x, float mat[3][3], float result[3][3])
{
    int a, b;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            result[a][b] = mat[a][b] + x;
        }
    }
}

/******************************************************************************
 * Unary Matrix Operations
 *****************************************************************************/

/**
 * MatrixDeterminant calculates the determinant of a matrix and returns the
 * value as a float.
 */
float MatrixDeterminant(float mat[3][3])
{
    float det1, det2, det3;
    float det = 0;
    det1 = mat[0][0]*(mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]);
    det2 = mat[0][1]*(mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]);
    det3 = mat[0][2]*(mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
    det = det1 - det2 + det3;
    return det;
}

/**
 * MatrixTrace calculates the trace of a matrix. The result is returned as a
 * float.
 */
float MatrixTrace(float mat[3][3])
{
    float a;
    a = mat[0][0] + mat[1][1] + mat[2][2];
    return a;
}

/**
 * MatrixTranspose calculates the transpose of a matrix and returns the
 * result through the second argument
 */
void MatrixTranspose(float mat[3][3], float result[3][3])
{
    int a, b;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 3; b++) {
            result[b][a] = mat[a][b];
        }
    }
}

/******************************************************************************
 * Extra Credit Matrix Operations
 *****************************************************************************/

/**
 * Calculate the adjugate matrix of a 3x3 matrix. This is the transpose of the cofactor matrix.
 * @param mat The input 3x3 matrix.
 * @param result The output 3x3 matrix.
 */
void MatrixAdjugate(float mat[3][3], float result[3][3])
{
    int x, y;
    float a, b, c, d, e, f, g, h, i;
    a = mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];
    b = mat[0][2] * mat[2][1] - mat[2][2] * mat[0][1];
    c = mat[0][1] * mat[1][2] - mat[1][1] * mat[0][2];
    d = mat[1][2] * mat[2][0] - mat[2][2] * mat[1][0];
    e = mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0];
    f = mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2];
    g = mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1];
    h = mat[0][1] * mat[2][0] - mat[2][1] * mat[0][0];
    i = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    float mat1[3][3] = {
        {a, b, c},
        {d, e, f},
        {g, h, i}};
    for (y = 0; y < 3; y++) {
        for (x = 0; x < 3; x++) {
            result[y][x] = mat1[y][x];
        }
    }
}

/**
 * MatrixInverse calculates the inverse of a matrix and returns the
 * result through the second argument.
 */
void MatrixInverse(float mat[3][3], float result[3][3])
{
 //   float a, b, c, d, e, f, g, h, i;
    float det = 0;
    det = MatrixDeterminant(mat);
    det = 1 / det;
/*    a = mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];
    b = mat[0][2] * mat[2][1] - mat[2][2] * mat[0][1];
    c = mat[0][1] * mat[1][2] - mat[1][1] * mat[0][2];
    d = mat[1][2] * mat[2][0] - mat[2][2] * mat[1][0];
    e = mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0];
    f = mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2];
    g = mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1];
    h = mat[0][1] * mat[2][0] - mat[2][1] * mat[0][0];
    i = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    float mat1[3][3] = {
        {a, b, c},
        {d, e, f},
        {g, h, i}
    };  */
    MatrixAdjugate(mat,result);
    MatrixScalarMultiply(det, result, result);
}

/**
 * MatrixPrint sends a 3x3 array to standard output with clean formatting.
 * The formatting does not need to look like the expected output given to you
 * in MatricMath.c but each element of the matrix must be separated and have
 * distinguishable position (more than a single line of output).
 */
void MatrixPrint(float mat[3][3])
{
    int a, b;
    printf("\nThe matrix is");
    for (a = 0; a < 3; a++) {
        printf("\n");
        for (b = 0; b < 3; b++) {
            printf("mat[%d][%d]: %f\t", a, b, (double) mat[a][b]);
        }
    }
}



