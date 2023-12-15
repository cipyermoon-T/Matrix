
#ifndef PROJETO_MATRIZES_FINAL_FUNCTIONS_H
#define PROJETO_MATRIZES_FINAL_FUNCTIONS_H

#define ANSI_COLOR_RED      "\e[0;31m"
#define ANSI_COLOR_GREEN     "\e[0;32m"
#define ANSI_COLOR_YELLOW     "\e[0;33m"
#define ANSI_COLOR_BLUE     "\e[0;34m"
#define ANSI_COLOR_MAGENTA     "\e[0;35m"
#define ANSI_COLOR_CYAN     "\e[0;36m"
#define ANSI_COLOR_RESET     "\033[0;0m"

// Declarando Funções
void show_logo();
void matrix_Sum(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result);
void matrix_Sub(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result);
void matrix_Mult_Num(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result, int num);
void print_Matrix_Mult_Num(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result, int i, int j);
void print_Sum(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result, int i, int j);
void print_Sub(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result, int i, int j);
void matrix_Mult_Matrix(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result);
void print_Matrix_Mult_Matrix(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result, int i, int j);
void matrix_Transposed(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result);
void normal_Matrix(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result);
void print_Matrix_Transposed(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result, int i, int j);
void inverse_Matrix(float **Matrix_A, float **Matrix_Result, int matrix_Size);
void print_Inverse_Matrix(int matrix_Size, float **Matrix_A, float **Matrix_Result, int i, int j);
int calc_Determinant(int matrix_Size, int **Matrix_A);
void print_Calc_Determinant(int matrix_Size, int **Matrix_A, int **Matrix_Result, int i, int j);

#endif //PROJETO_MATRIZES_FINAL_FUNCTIONS_H
