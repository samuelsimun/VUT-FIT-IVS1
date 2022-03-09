//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     SAMUEL ŠIMÚN <xsimun04@stud.fit.vutbr.cz>
// $Date:       $2022-03-04
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author SAMUEL ŠIMÚN
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"
#include <cstdlib>



class WhiteBoxTesting : public  ::testing::Test{

protected:
    Matrix matrix;

    Matrix Construct_Matrix10x10(){
        Matrix matrix = Matrix(10,10);
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                matrix.set(i,k,i+k);
            }
        }

        return matrix;
    }

    Matrix Construct_Matrix4x4(){
        Matrix matrix = Matrix(4,4);
        matrix.set(std::vector<std::vector<double>> {
                {8 , 5 , 4 , 3},
                {9, 8 , 6 , 7},
                {10, 7.3, 7.8, 5},
                {1.1, 0.1, 8.9, 5.8},
        }
        );
        return matrix;
    };


    Matrix Construct_Matrix2x2(){
        Matrix matrix = Matrix(2,2);
        matrix.set(0,0,5.8);
        matrix.set(0,1,6.9);
        matrix.set(1,0,7.1);
        matrix.set(1,1,8.7);

        return matrix;
    }

    Matrix Construct_Matrix3x3(){
        Matrix matrix = Matrix(3,3);
        matrix.set(std::vector<std::vector<double>> {
                           {2 , -4 , 6},
                           {3 , -5 , 8},
                           {-2 , 6 , -10}
                   }
        );
        return matrix;
    }

    Matrix Construct_Matrix100x100(){
        Matrix matrix = Matrix(100,100);
        for (int i = 0; i < 100; i++){
            for (int k = 0; k < 100; k++){
                matrix.set(i,k,rand());
            }
        }
        return matrix;
    }

    Matrix Construct_Matrix1000x1(){
        Matrix matrix = Matrix(1000,1);
        for(int i = 0; i<1000; i++){
            matrix.set(i,0, rand());
        }
        return matrix;
    }

    Matrix Construct_Matrix3x6(){
        Matrix matrix = Matrix(3,6);
        matrix.set(std::vector<std::vector<double>> {
                           {4 , 5 , 4 , 7.5 , 9.8 , 7.9 },
                           {9, 8 , 6 , 7 , 7.3, 7.8},
                           {10, 5, 1.1, 0.1, 8.9, 5.8}
                   }
        );
        return matrix;
    }

    Matrix Construct_Matrix6x2(){
        Matrix matrix = Matrix(6,2);
        matrix.set(std::vector<std::vector<double>> {
                           {4 , 5},
                           {2.1, 8.9},
                           {1 , 5.3},
                           {8.7, 6.4},
                           {0 ,8.4},
                           {9.1 , 2.03}
                   }
        );
        return matrix;
    }

};

TEST_F(WhiteBoxTesting, Construct_0_Matrix){

    // Construct matrices with 0 sizes
    ASSERT_NO_THROW(Matrix());
    EXPECT_EQ(matrix.get(0, 0), 0.0);

}

TEST_F(WhiteBoxTesting, Construct_non0_Matrix){

    //Creating correct matrix with non 0 sizes, expecting to create without error
    ASSERT_NO_THROW(Matrix(2,2));
    ASSERT_NO_THROW(Matrix(10,8));
    ASSERT_NO_THROW(Matrix(110,1000));
    ASSERT_NO_THROW(Construct_Matrix100x100());
    ASSERT_NO_THROW(Construct_Matrix2x2());

    //Creating non-correct matrix with at least one non 0 size, expecting to throw Error
    ASSERT_ANY_THROW(Matrix(0,15));
    ASSERT_ANY_THROW(Matrix(1000,0));
    ASSERT_ANY_THROW(Matrix(0,0));


}

TEST_F(WhiteBoxTesting, Set){

    //Testing values in matrices with pre-defined values in functions
    Matrix matrix = Construct_Matrix2x2();

    EXPECT_DOUBLE_EQ(8.7 , matrix.get(1,1));
    EXPECT_DOUBLE_EQ(5.8 , matrix.get(0,0));
    EXPECT_DOUBLE_EQ(6.9 , matrix.get(0,1));

    matrix = Construct_Matrix10x10();

    EXPECT_DOUBLE_EQ(0.0 , matrix.get(0,0));
    EXPECT_DOUBLE_EQ(18.0 , matrix.get(9,9));
    EXPECT_DOUBLE_EQ(8.0 , matrix.get(4,4));
    EXPECT_DOUBLE_EQ(9.0, matrix.get(7,2));

    matrix = Construct_Matrix4x4();
    EXPECT_DOUBLE_EQ(8.0 , matrix.get(0,0));
    EXPECT_DOUBLE_EQ(7.3 , matrix.get(2,1));
    EXPECT_DOUBLE_EQ(5.8 , matrix.get(3,3));

    matrix = Construct_Matrix1000x1();
    matrix.set(987,0,5.4);
    EXPECT_DOUBLE_EQ(5.4 , matrix.get(987,0));


    // Setting values outside matrix - expecting
    // False

    EXPECT_FALSE(matrix.set(4,4,15.1));
    EXPECT_FALSE(matrix.set(-1,-1,5));


    //Dimensions of values and matrix size is not same
    matrix = Matrix(1,1);
    EXPECT_FALSE(matrix.set(std::vector<std::vector< double > > {{0},{1,2}} ));



    // Setting values into matrix - expecting
    // True

    matrix = Construct_Matrix10x10();

    EXPECT_TRUE(matrix.set(3,3,0.2));
    EXPECT_TRUE(matrix.set(0,0,5));
}

TEST_F(WhiteBoxTesting, Get){
    Matrix matrix = Construct_Matrix4x4();

    // Requesting value in matrix
    // Expecting - Value
    EXPECT_DOUBLE_EQ(8 , matrix.get(0,0));
    EXPECT_DOUBLE_EQ(5.8 , matrix.get(3,3));


    // Requesting value outside matrix
    // Expecting - False
    EXPECT_ANY_THROW(matrix.get(4,4));
    EXPECT_ANY_THROW(matrix.get(-1,-1));
}

TEST_F(WhiteBoxTesting, Compare){

    // Comparing matrices with same sizes

    Matrix matrix1 = Construct_Matrix4x4();
    Matrix matrix2 = Construct_Matrix4x4();
    EXPECT_TRUE(matrix1 == matrix2);


    matrix1 = Matrix();
    matrix2 = Matrix();
    EXPECT_TRUE(matrix1 == matrix2);


    matrix1 = Construct_Matrix100x100();
    matrix2 = matrix1;
    EXPECT_TRUE(matrix1 == matrix2);


    matrix1 = Construct_Matrix4x4();
    matrix2 = Construct_Matrix4x4();
    matrix2.set(1,3,6.2);
    EXPECT_FALSE(matrix1 == matrix2);

    matrix2.set(1,3,7.0);
    EXPECT_TRUE(matrix1 == matrix2);

    // Comparing matrices with non-same sizes

    matrix1 = Construct_Matrix3x6();
    matrix2 = Construct_Matrix6x2();
    EXPECT_ANY_THROW(matrix1 == matrix2);


    matrix1 = Construct_Matrix4x4();
    matrix2 = Construct_Matrix2x2();
    EXPECT_ANY_THROW(matrix1 == matrix2);

    // Comparing matrices with float error
    matrix2 = matrix1;
    matrix1.set(3,3,58/10);
    EXPECT_TRUE(matrix1 == matrix2);

}

TEST_F(WhiteBoxTesting, Plus){

    // Comparing if matrix * 2 = matrix + matrix
    // Expect TRUE
    Matrix matrix1 = Construct_Matrix10x10();
    Matrix matrix2 = Construct_Matrix10x10();
    EXPECT_TRUE((matrix1 * 2)  == (matrix1+matrix2));

    matrix1 = Construct_Matrix100x100();
    matrix2 = matrix1;
    EXPECT_TRUE((matrix1 * 2) == (matrix1+matrix2));

    matrix1 = Construct_Matrix4x4();
    matrix2 = matrix1;
    matrix2.set(std::vector<std::vector<double>> {
    {16 , 10 , 8 , 6},
    {18, 16 , 12 , 14},
    {20, 14.6, 15.6, 10},
    {2.2, 0.2, 17.8, 11.6},
    });
    EXPECT_TRUE((matrix1 + matrix1) == matrix2);


    // Testing for matrix1 + matrix2 - two non-same matrices

    Matrix matrix3 = Construct_Matrix4x4();
    matrix3.set(std::vector<std::vector<double>>{
    {24 , 15 , 12 , 9},
    {27, 24 , 18 , 21},
    {30, 21.9, 23.4, 15},
    {3.3, 0.3, 26.7, 17.4},
    });
    for (int i = 0; i<4; i++){
        for (int k = 0; k<4 ; k++){
            EXPECT_DOUBLE_EQ(matrix3.get(i,k), (matrix1+matrix2).get(i,k));
        }
    }


    // Testing for 0 matrices
    matrix1 = Matrix();
    matrix2 = Matrix();
    EXPECT_NO_THROW(matrix1+matrix2);

    // Testing for non-same sized matrices
    // Expecting ERROR
    matrix1 = Construct_Matrix2x2();
    matrix2 = Construct_Matrix4x4();
    EXPECT_ANY_THROW(matrix1 + matrix2);

    matrix1 = Construct_Matrix3x6();
    matrix2 = Construct_Matrix6x2();
    EXPECT_ANY_THROW(matrix1 + matrix2);
}

TEST_F(WhiteBoxTesting, multiplication_of_two_matrices){

    //Testing for [6x3] * [3x2] --> TRUE and [3x2] * [6x3] --> ERROR
    Matrix matrix1 = Construct_Matrix3x6();
    Matrix matrix2 = Construct_Matrix6x2();
    EXPECT_NO_THROW(matrix1 * matrix2);
    EXPECT_ANY_THROW(matrix2 * matrix1);


    // Multiplication of [6x3] * [3x2]
    Matrix matrix3 = Matrix(3,2);
    matrix3.set(std::vector<std::vector<double>> {
    {167.64 , 232.057},
    {190.68, 269.954},
    {105.25, 187.504}
    });
    for(int i = 0; i< 3; i++){
        for (int k = 0; k < 2; k++){
            EXPECT_DOUBLE_EQ(matrix3.get(i,k),(matrix1*matrix2).get(i,k));
        }
    }

    // Multiplication of [4x4] * [4x4]
    matrix1 = Construct_Matrix4x4();
    matrix2 = matrix1;
    matrix3 = Matrix(4,4);
    matrix3.set(std::vector<std::vector<double>> {
    {152.3 , 109.5 , 119.9 , 96.4},
    {211.7 , 153.5 , 193.1 , 153.6},
    {229.2 , 165.84 , 189.14 , 149.1},
    {105.08 , 71.85 , 126.04 , 82.14}
    });
    for(int i = 0; i< 4; i++){
        for (int k = 0; k < 4; k++){
            EXPECT_DOUBLE_EQ(matrix3.get(i,k),(matrix1*matrix2).get(i,k));
        }
    }
}

TEST_F(WhiteBoxTesting, Multiplication_by_vector){

    // Multiplication of matrix with vector 2
    Matrix matrix = Construct_Matrix4x4();
    for (int i = 0; i<4; i++){
        for (int k = 0; k<4; k++){
            EXPECT_DOUBLE_EQ((matrix*2).get(i,k),matrix.get(i,k)*2);
        }
    }

    // Multiplication of matrix with vector 2.5
    matrix = Construct_Matrix6x2();
    for (int i = 0; i<6;i++){
        for (int k = 0; k<2; k++){
            EXPECT_DOUBLE_EQ((matrix * 2.5).get(i,k), matrix.get(i,k)*2.5);
        }
    }

    // Multiplication of matrix with vector 0 --> Expecting 0-matrix
    matrix = Construct_Matrix100x100();
    Matrix ex_matrix = matrix * 0; // ---> Expected matrix, added for faster processing
    for (int i=0; i<100; i++){
        for (int k=0; k<100; k++){
            EXPECT_DOUBLE_EQ((ex_matrix.get(i,k)),0);
        }
    }
}

TEST_F(WhiteBoxTesting, solveEquation){

    // Testing with determinate = 0
    Matrix matrix = Matrix(3,3);
    matrix.set(std::vector<std::vector<double>> {
    {5 , 6 , 7 },
    {8, 9 , 10 },
    {11 , 12 , 13}
    });
    EXPECT_ANY_THROW(matrix.solveEquation({0,0,0}));


    // Testing for non-square matrix
    matrix = Construct_Matrix6x2();
    EXPECT_ANY_THROW(matrix.solveEquation({0,0,0}));


    // Testing for determinate != 0
    // Singular matrix
    matrix = Matrix(3,3);
    matrix.set(std::vector<std::vector<double>> {
    {1 , 2 , 3 },
    {3 , -4 , 5 },
    {2 , 5 , -7}
    });
    std::vector<double> result = {0,0,0};
    EXPECT_EQ(matrix.solveEquation({0,0,0}),result);

    //Non-Singular matrices
    matrix = Matrix(3,3);
    matrix.set(std::vector<std::vector<double>> {
    {1 , -3 , 1 },
    {2 , 1 , -1 },
    {1 , -1 , -1}
    });
    result = {2,3,-1};
    EXPECT_EQ(matrix.solveEquation({-8,8,0}), result);


    matrix = Matrix(4,4);
    matrix.set(std::vector<std::vector<double>> {
    {1 , 1 , 1 , 1 },
    {2 , 3 , 0 , -1 },
    {-3 , 4 , 1 , 2},
    {1 , 2 , -1 , 1}
    });
    result = {2,0,6,5};
    EXPECT_EQ(matrix.solveEquation({13,-1,10,1}), result);

}

TEST_F(WhiteBoxTesting, Transpose){


    // Transpose big matrix
    Matrix matrix = Construct_Matrix100x100();
    Matrix matrix_trans = matrix.transpose();
    for (int i = 0 ; i<100; i++){
        for (int k = 0 ; k<100; k++){
            EXPECT_DOUBLE_EQ(matrix.get(i,k), matrix_trans.get(k,i));
        }
    }

    // Transpose non-squared matrix
    matrix = Construct_Matrix3x6();
    matrix_trans = matrix.transpose();
    for (int i = 0; i<3 ; i++){
        for (int k=0; k<6 ;k++){
            EXPECT_DOUBLE_EQ(matrix.get(i,k), matrix_trans.get(k,i));
        }
    }

    // Transpose big linear matrix
    matrix = Construct_Matrix1000x1();
    matrix_trans = matrix.transpose();
    for (int i = 0; i<1000 ; i++){
        EXPECT_DOUBLE_EQ(matrix.get(i,0), matrix_trans.get(0,i));
        }

    // Transpose 0-matrix
    matrix = Matrix();
    matrix = matrix.transpose();
    EXPECT_DOUBLE_EQ(matrix.get(0,0),0);
}

TEST_F(WhiteBoxTesting,Inverse){

    // Testing 3x3 matrices

    Matrix matrix = Construct_Matrix3x3();
    matrix = matrix.inverse();
    Matrix result = Matrix(3,3);
    result.set(std::vector<std::vector<double>> {
    {-0.5 , 1 , 0.5 },
    {-3.5 , 2 , -0.5 },
    {-2 , 1, -0.5}
    });
    for (int i = 0; i<3; i++){
        for (int k = 0; k<3; k++){
            EXPECT_DOUBLE_EQ(matrix.get(i,k),result.get(i,k));
        }
    }

    matrix.set(std::vector<std::vector<double>> {
    {1 , 1 , 1},
    {0 , 1 , 0},
    {0 , 0 , 0}
    });
    EXPECT_ANY_THROW(matrix.inverse());

    // Testing 2x2 matrices

    matrix = Matrix(2,2);
    matrix.set(std::vector<std::vector<double>> {
        {1 , 8},
        {3 , 4}
    });
    matrix = matrix.inverse();
    result = Matrix(2,2);
    result.set(std::vector<std::vector<double>> {
        {-0.2 , 0.4},
        {0.15 , -0.05}
    });
    for (int i = 0; i<2; i++){
        for (int k = 0; k<2; k++){
            EXPECT_DOUBLE_EQ(matrix.get(i,k),result.get(i,k));
        }
    }

    matrix.set(std::vector<std::vector<double>> {
        {0 , 0},
        {3 , 5}
    });
    EXPECT_ANY_THROW(matrix.inverse());


    // Testing not supported matrices
    matrix = Construct_Matrix4x4();
    EXPECT_ANY_THROW(matrix.inverse());

}


/*** Konec souboru white_box_tests.cpp ***/
