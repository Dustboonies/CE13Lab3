// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CMPE13 Support Library
#include "BOARD.h"
#include "MatrixMath.h"

// Microchip libraries
#include <xc.h>
#include <plib.h>

// User libraries

// **** Set macros and preprocessor directives ****

// **** Define global, module-level, or external variables here ****

// **** Declare function prototypes ****

int main()
{
    BOARD_Init();
    printf("\n\nProgram Begin...\n");
    /******************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     *****************************************************************************/
    int successVar = 0;
    float testVal = 5;
    float test1[3][3] = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}
    };
    float test2[3][3] = {
        {-1, 0, -1},
        {0, -1, 0},
        {-1, 0, -1}
    };
    float test3[3][3] = {
        {.5, 0, .5},
        {0, .5, 0},
        {.5, 0, .5}
    };
    float invTest1[3][3] = {
        {1, 2, 0},
        {0, 1, 0},
        {2, 1, 1}
    };
    float invTest2[3][3] = {
        {2, 1, 0},
        {1, 0, 0},
        {2, 1, 1}
    };
    float result[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    float resultVar = 0;


    //  ******************************************MATRIX MATH TEST  
    MatrixMultiply(test1, test2, result);
    successVar = 0;
    float correct0[3][3] = {
        {-2, -2, -2,},
        {-4, -1, -4},
        {-2, -2, -2}
    };
    if (MatrixEquals(result, correct0) == 1) {
        successVar++;
    }
    float correct1[3][3] = {
        {1, 1, 1},
        {2, .5, 2},
        {1, 1, 1}
    };
    MatrixMultiply(test1, test3, result);
    if (MatrixEquals(result, correct1) == 1) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixMath()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixMath()\n");
    } else {
        printf("Failed (0/2): MatrixMath()\n");
    }


    //  *********************************************MATRIX SCALAR MATH TEST
    float correct2[3][3] = {
        {5, 10, 5,},
        {10, 5, 10},
        {5, 10, 5}
    };
    successVar = 0;
    MatrixScalarMultiply(testVal, test1, result);
    if (MatrixEquals(result, correct2) == 1) {
        successVar++;
    }
    float correct3[3][3] = {
        {2.5, 0, 2.5},
        {0, 2.5, 0},
        {2.5, 0, 2.5}
    };
    MatrixScalarMultiply(testVal, test3, result);
    if (MatrixEquals(result, correct3) == 1) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixScalarMultiply()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixScalarMultiply()\n");
    } else {
        printf("Failed (0/2): MatrixScalarMultiply()\n");
    }

    //  ***************************************MATRIX SCALAR ADD TEST

    float correct4[3][3] = {
        {6, 7, 6,},
        {7, 6, 7},
        {6, 7, 6}
    };
    successVar = 0;
    MatrixScalarAdd(testVal, test1, result);
    if (MatrixEquals(result, correct4) == 1) {
        successVar++;
    }
    float correct5[3][3] = {
        {5.5, 5, 5.5},
        {5, 5.5, 5},
        {5.5, 5, 5.5}
    };
    MatrixScalarAdd(testVal, test3, result);
    if (MatrixEquals(result, correct5) == 1) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixScalarAdd()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixScalarAdd()\n");
    } else {
        printf("Failed (0/2): MatrixScalarAdd()\n");
    }
    //  ******************************************MATRIX ADD TEST
    float correct6[3][3] = {
        {0, 2, 0,},
        {2, 0, 2},
        {0, 2, 0}
    };
    successVar = 0;
    MatrixAdd(test1, test2, result);
    if (MatrixEquals(result, correct6) == 1) {
        successVar++;
    }
    float correct7[3][3] = {
        {1.5, 2, 1.5},
        {2, 1.5, 2},
        {1.5, 2, 1.5}
    };
    MatrixAdd(test1, test3, result);
    if (MatrixEquals(result, correct7) == 1) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixAdd()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixAdd()\n");
    } else {
        printf("Failed (0/2): MatrixAdd()\n");
    }

    //  **************************************************MATRIX DETERMINANT TEST
    float correct8 = 0;
    successVar = 0;
    resultVar = MatrixDeterminant(test1);
    if (resultVar == correct8) {
        successVar++;
    }
    float correct9 = 0;
    resultVar = MatrixDeterminant(test3);
    if (resultVar == correct9) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixDeterminant()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixDeterminant()\n");
    } else {
        printf("Failed (0/2): MatrixDeterminant()\n");
    }

    //  ******************************************************MATRIX EQUALS TEST
    float correct10[3][3] = {
        {1, 2, 1,},
        {2, 1, 2},
        {1, 2, 1}
    };
    successVar = 0;
    if (MatrixEquals(test1, correct10) == 1) {
        successVar++;
    }
    float correct11[3][3] = {
        {0.5, 0, 0.5},
        {0, 0.5, 0},
        {0.5, 0, 0.5}
    };
    if (MatrixEquals(test3, correct11) == 1) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixEquals()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixEquals()\n");
    } else {
        printf("Failed (0/2): MatrixEquals()\n");
    }

    //  ****************************************************MATRIX TRACE TEST
    float correct12 = 3;
    successVar = 0;
    resultVar = MatrixTrace(test1);
    if (resultVar == correct12) {
        successVar++;
    }
    float correct13 = 1.5;
    resultVar = MatrixTrace(test3);
    if (resultVar == correct13) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixTrace()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixTrace()\n");
    } else {
        printf("Failed (0/2): MatrixDeterminant()\n");
    }

    //  *************************************************MATRIX TRANSPOSE TEST
    float correct14[3][3] = {
        {1, 2, 1,},
        {2, 1, 2},
        {1, 2, 1}
    };
    successVar = 0;
    MatrixTranspose(test1, result);
    if (MatrixEquals(result, correct14) == 1) {
        successVar++;
    }
    float correct15[3][3] = {
        {0.5, 0, 0.5},
        {0, 0.5, 0},
        {0.5, 0, 0.5}
    };
    MatrixTranspose(test3, result);
    if (MatrixEquals(result, correct15) == 1) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixTranspose()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixTranspose()\n");
    } else {
        printf("Failed (0/2): MatrixTranspose()\n");
    }

    //  *******************************************MATRIX INVERSE TEST
    float correct16[3][3] = {
        {1, -2, 0,},
        {0, 1, 0},
        {-2, 3, 1}
    };
    successVar = 0;
    MatrixInverse(invTest1, result);
    if (MatrixEquals(result, correct16) == 1) {
        successVar++;
    }
    float correct17[3][3] = {
        {0, 1, 0},
        {1, -2, 0},
        {-1, 0, 1}
    };
    MatrixInverse(invTest2, result);
    if (MatrixEquals(result, correct17) == 1) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixInverse()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixInverse()\n");
    } else {
        printf("Failed (0/2): MatrixInverse()\n");
    }


    //  *****************************************************MATRIX ADJUGATE TEST
    float correct18[3][3] = {
        {1, -2, 0},
        {0, 1, 0},
        {-2, 3, 1}
    };
    successVar = 0;
    MatrixAdjugate(invTest1, result);
    if (MatrixEquals(result, correct18) == 1) {
        successVar++;
    }
    float correct19[3][3] = {
        {0, -1, 0},
        {-1, 2, 0},
        {1, 0, -1}
    };
    MatrixAdjugate(invTest2, result);
    if (MatrixEquals(result, correct19) == 1) {
        successVar++;
    }
    if (successVar == 2) {
        printf("Passed (2/2): MatrixAdjugate()\n");
    } else if (successVar == 1) {
        printf("Failed (1/2): MatrixAdjugate()\n");
    } else {
        printf("Failed (0/2): MatrixAdjugate()\n");
    }
    //  ************************************************MATRIX PRINT EXAMPLE
    /*
     Printed matrix should look like
     * The Matrix is
     * 1.000000    2.000000   1.000000
     * 2.000000    1.000000   2.000000
     * 1.000000    2.000000   1.000000
     */
    MatrixPrint(test1);

    /******************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     *****************************************************************************/

    // Returning from main() is bad form in embedded environments. So we sit and spin.
    while (1);
}

