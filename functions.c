#include "functions.h"
#include <stdio.h>
#include <stdlib.h>


#define ANSI_COLOR_RED      "\e[0;31m"
#define ANSI_COLOR_GREEN     "\e[0;32m"
#define ANSI_COLOR_YELLOW     "\e[0;33m"
#define ANSI_COLOR_BLUE     "\e[0;34m"
#define ANSI_COLOR_MAGENTA     "\e[0;35m"
#define ANSI_COLOR_CYAN     "\e[0;36m"
#define ANSI_COLOR_RESET     "\033[0;0m"

// Logo do programa e as funções do mesmo. Função apenas de print
void show_logo(){
    printf(ANSI_COLOR_MAGENTA"                  __           .__          \n"
           "  _____  _____  _/  |_ _______ |__|___  ___ \n"
           " /     \\ \\__  \\ \\   __\\\\_  __ \\|  |\\  \\/  / \n"
           "|  Y Y  \\ / __ \\_|  |   |  | \\/|  | >    <  \n"
           "|__|_|  /(____  /|__|   |__|   |__|/__/\\_ \\ \n"
           "      \\/      \\/                         \\/ \n"
           "                                            " ANSI_COLOR_RESET);

    printf(ANSI_COLOR_CYAN "\n\n1. Soma de Matrizes \n2. Subtracao de matrizes\n3. Produto de um numero por uma matriz\n4. Produto de matrizes\n5. Calculo de Determinante\n6. Matriz inversa\n7. Matriz transposta\n8. Sair do programa\n9. Clear nos comandos\n0. Informacoes adicionais sobre as operacoes\n\n" ANSI_COLOR_RESET);
}

// height = altura; width = largura;

/*
    A função matrix_sum obtem altura e largura e usa as mesmas nas variaveis Matrix_A e MatrixB, logo querendo ou não, as matrizes terão o mesmo tamanho e não será
    preciso ser feita uma verificação adicional dentro da função para que saiba se são do mesmo tamanho, tendo apenas uma verificação para caso a matriz seja menor
    ou igual a zero.
    return 0; (ou False) significa que a operação foi mal sucedida e irá retornar 0, caso deseje pode ser usado para informar ao usuario se a operação foi bem sucedida
    ou mal sucedida. Todas as outras funçoes são feitas da mesma forma
*/

// adição de matrizes
void matrix_Sum(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result){

    int i, j;

    // se a matriz tiver um tamanho e largura menor que 0 obviamente ela não vai existir, então logicamente retornará erro, o mesmo serve para as demais funções escritas
    if(matrix_Height <= 0 || matrix_Width <= 0){
        printf("Algo deu errado na soma de matrizes. ");
    }
    else{

        printf("\n");

        // percorre cada elemento da linha de uma coluna e insere os resultados das duas matrizes em outra variavel feita somente para resultados, os mesmo serve para as outras funçoes escritas
        for(i = 0; i < matrix_Height; i++){
            for(j = 0; j < matrix_Width; j++){
                Matrix_Result[i][j] = Matrix_A[i][j] + Matrix_B[i][j];
            }
        }

        // percorre matrix_Result para poder printar o resultado na tela
        for (i = 0; i < matrix_Height; i++) {
            for (j = 0; j < matrix_Width; j++) {
                printf("%d\t", Matrix_Result[i][j]);
            }
            printf("\n");
        }
    }
}

// função matrix_sum dentro de outra funçao print para diminuir o codigo dentro da função main, facilitando o uso do codigo posteriormente. O mesmo para as demais.
void print_Sum(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result, int i, int j){
    // requerimento de dados do usuario para formação das matrizes;
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de linhas para as variaveis A e B: "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Height);
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de colunas para as variaveis A e B:  "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Width);

    // Alocando memória para as matrizes com base nas dimensões fornecidas pelo usuário
    Matrix_A = (int **)malloc(matrix_Height * sizeof(int *));
    Matrix_B = (int **)malloc(matrix_Height * sizeof(int *));
    Matrix_Result = (int **)malloc(matrix_Height * sizeof(int *));

    for (i = 0; i < matrix_Height; i++) {
        Matrix_A[i] = (int *)malloc(matrix_Width * sizeof(int));
        Matrix_B[i] = (int *)malloc(matrix_Width * sizeof(int));
        Matrix_Result[i] = (int *)malloc(matrix_Width * sizeof(int));
    }

    // entrada dos valores para as matriz A
    for(i = 0; i < matrix_Height; i++){
        for(j = 0; j < matrix_Width; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix A[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_A[i][j]);
        }
    }
    printf("\n\n");

    // entrada dos valores para a matriz B
    for(i = 0; i < matrix_Height; i++){
        for(j = 0; j < matrix_Width; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix B[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_B[i][j]);
        }
    }
    printf(ANSI_COLOR_BLUE"\nMatrix A: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Height, matrix_Width, Matrix_A, Matrix_Result);
    printf(ANSI_COLOR_BLUE"\nMatrix B: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Height, matrix_Width, Matrix_B, Matrix_Result);
    printf(ANSI_COLOR_BLUE"\nMatrix somada: "ANSI_COLOR_RESET);
    matrix_Sum(matrix_Height, matrix_Width, Matrix_A, Matrix_B, Matrix_Result);

    // Liberando a memória alocada
    for (i = 0; i < matrix_Height; i++) {
        free(Matrix_A[i]);
        free(Matrix_B[i]);
        free(Matrix_Result[i]);
    }
    free(Matrix_A);
    free(Matrix_B);
    free(Matrix_Result);
}

// subtração de matrizes
void matrix_Sub(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result){

    int i, j;

    if(matrix_Height <= 0 || matrix_Width <= 0){
        printf("Algo deu errado na subtracao de matrizes. ");
    }
    else{

        printf("\n");

        for(i = 0; i < matrix_Height; i++){
            for(j = 0; j < matrix_Width; j++){
                Matrix_Result[i][j] = Matrix_A[i][j] - Matrix_B[i][j];
            }
        }
        for (i = 0; i < matrix_Height; i++) {
            for (j = 0; j < matrix_Width; j++) {
                printf("%d\t", Matrix_Result[i][j]);
            }
            printf("\n");
        }
    }
}

// função matrix_Sub dentro de outra funçao print para diminuir o codigo dentro da função main, facilitando o uso do codigo posteriormente.
void print_Sub(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result, int i, int j){
    // requerimento de dados do usuario para formação das matrizes;
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de linhas para as variaveis A e B: "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Height);
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de colunas para as variaveis A e B:  "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Width);

    // Alocando memória para as matrizes com base nas dimensões fornecidas pelo usuário
    Matrix_A = (int **)malloc(matrix_Height * sizeof(int *));
    Matrix_B = (int **)malloc(matrix_Height * sizeof(int *));
    Matrix_Result = (int **)malloc(matrix_Height * sizeof(int *));

    for (i = 0; i < matrix_Height; i++) {
        Matrix_A[i] = (int *)malloc(matrix_Width * sizeof(int));
        Matrix_B[i] = (int *)malloc(matrix_Width * sizeof(int));
        Matrix_Result[i] = (int *)malloc(matrix_Width * sizeof(int));
    }

    // entrada dos valores para as matriz A
    for(i = 0; i < matrix_Height; i++){
        for(j = 0; j < matrix_Width; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix A[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_A[i][j]);
        }
    }
    printf("\n\n");

    // entrada dos valores para as matriz B
    for(i = 0; i < matrix_Height; i++){
        for(j = 0; j < matrix_Width; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix B[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_B[i][j]);
        }
    }
    printf(ANSI_COLOR_BLUE"\nMatrix A: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Height, matrix_Width, Matrix_A, Matrix_Result);
    printf(ANSI_COLOR_BLUE"\nMatrix B: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Height, matrix_Width, Matrix_B, Matrix_Result);
    printf(ANSI_COLOR_BLUE"\nMatrix subtraida: "ANSI_COLOR_RESET);
    matrix_Sub(matrix_Height, matrix_Width, Matrix_A, Matrix_B, Matrix_Result);

    // Liberando a memória alocada
    for (i = 0; i < matrix_Height; i++) {
        free(Matrix_A[i]);
        free(Matrix_B[i]);
        free(Matrix_Result[i]);
    }
    free(Matrix_A);
    free(Matrix_B);
    free(Matrix_Result);
}

// multiplicação de uma matrix por um numero
void matrix_Mult_Num(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result, int num){
    int i, j;

    if(matrix_Height <= 0 || matrix_Width <= 0){
        printf("Algo deu errado na multiplicacao um numero por uma matriz. ");
    }
    else{

        printf("\n");

        for(i = 0; i < matrix_Height; i++){
            for(j = 0; j < matrix_Width; j++){
                Matrix_Result[i][j] = Matrix_A[i][j] * num;
            }
        }
        for (i = 0; i < matrix_Height; i++) {
            for (j = 0; j < matrix_Width; j++) {
                printf("%d\t", Matrix_Result[i][j]);
            }
            printf("\n");
        }
    }
}

// função que solicita dados e printa o resultado
void print_Matrix_Mult_Num(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result, int i, int j){
    // requerimento de dados do usuario para formação das matrizes;
    int num;
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de linhas para a variavel A: "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Height);
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de colunas para as variaveis A:  "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Width);

    // Alocando memória para as matrizes com base nas dimensões fornecidas pelo usuário
    Matrix_A = (int **)malloc(matrix_Height * sizeof(int *));
    Matrix_Result = (int **)malloc(matrix_Height * sizeof(int *));

    for (i = 0; i < matrix_Height; i++) {
        Matrix_A[i] = (int *)malloc(matrix_Width * sizeof(int));
        Matrix_Result[i] = (int *)malloc(matrix_Width * sizeof(int));
    }

    // entrada dos valores para as matrizes A e B
    for(i = 0; i < matrix_Height; i++){
        for(j = 0; j < matrix_Width; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix A[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_A[i][j]);
        }
    }
    printf(ANSI_COLOR_YELLOW"\nDigite um unico numero inteiro para a multiplicacao: "ANSI_COLOR_RESET);
    scanf("%i", &num);
    printf(ANSI_COLOR_BLUE"\nMatrix A: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Height, matrix_Width, Matrix_A, Matrix_Result);
    printf(ANSI_COLOR_BLUE"\nNumero: "ANSI_COLOR_RESET);
    printf("%i", num);
    printf(ANSI_COLOR_BLUE"\nMatrix multiplicada: "ANSI_COLOR_RESET);
    matrix_Mult_Num(matrix_Height, matrix_Width, Matrix_A, Matrix_Result, num);

    // Liberando a memória alocada
    for (i = 0; i < matrix_Height; i++) {
        free(Matrix_A[i]);
        free(Matrix_Result[i]);
    }
    free(Matrix_A);
    free(Matrix_Result);
}

// multiplicação de matrix por outra matrix
void matrix_Mult_Matrix(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result){

    int i, j;

    if(matrix_Height <= 0 || matrix_Width <= 0){
        printf("Algo deu errado na multiplicacao de matrizes. ");
    }
    else{

        printf("\n");

        // Mesma logica de soma e subtração, mudando apenas o sinal
        for(i = 0; i < matrix_Height; i++){
            for(j = 0; j < matrix_Width; j++){
                Matrix_Result[i][j] = Matrix_A[i][j] * Matrix_B[i][j];
            }
        }
        for (i = 0; i < matrix_Height; i++) {
            for (j = 0; j < matrix_Width; j++) {
                printf("%d\t", Matrix_Result[i][j]);
            }
            printf("\n");
        }
    }
}

// função que solicita dados e printa o resultado
void print_Matrix_Mult_Matrix(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_B, int **Matrix_Result, int i, int j){
    // requerimento de dados do usuario para formação das matrizes;
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de linhas para as variaveis A e B: "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Height);
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de colunas para as variaveis A e B:  "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Width);

    // Alocando memória para as matrizes com base nas dimensões fornecidas pelo usuário
    Matrix_A = (int **)malloc(matrix_Height * sizeof(int *));
    Matrix_B = (int **)malloc(matrix_Height * sizeof(int *));
    Matrix_Result = (int **)malloc(matrix_Height * sizeof(int *));

    for (i = 0; i < matrix_Height; i++) {
        Matrix_A[i] = (int *)malloc(matrix_Width * sizeof(int));
        Matrix_B[i] = (int *)malloc(matrix_Width * sizeof(int));
        Matrix_Result[i] = (int *)malloc(matrix_Width * sizeof(int));
    }

    // entrada dos valores para as matrizes A e B
    for(i = 0; i < matrix_Height; i++){
        for(j = 0; j < matrix_Width; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix A[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_A[i][j]);
        }
    }
    printf("\n\n");
    for(i = 0; i < matrix_Height; i++){
        for(j = 0; j < matrix_Width; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix B[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_B[i][j]);
        }
    }
    printf(ANSI_COLOR_BLUE"\nMatrix A: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Height, matrix_Width, Matrix_A, Matrix_Result);
    printf(ANSI_COLOR_BLUE"\nMatrix B: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Height, matrix_Width, Matrix_A, Matrix_Result);
    printf(ANSI_COLOR_BLUE"\nMatrix multiplicada: "ANSI_COLOR_RESET);
    matrix_Mult_Matrix(matrix_Height, matrix_Width, Matrix_A, Matrix_B, Matrix_Result);

    // Liberando a memória alocada
    for (i = 0; i < matrix_Height; i++) {
        free(Matrix_A[i]);
        free(Matrix_B[i]);
        free(Matrix_Result[i]);
    }
    free(Matrix_A);
    free(Matrix_B);
    free(Matrix_Result);
}

// função feita apenas para printar a matriz antes de ser feita alguma operação, para ser compara posteriormente no output do terminal
void normal_Matrix(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result){
    int i, j;

    if(matrix_Height <= 0 || matrix_Width <= 0){
        printf("Algo deu errado na matriz. ");
    }
    else{

        printf("\n");

        for(i = 0; i < matrix_Height; i++){
            for(j = 0; j < matrix_Width; j++){
                Matrix_Result[i][j] = Matrix_A[i][j];
            }
        }
        for (i = 0; i < matrix_Height; i++) {
            for (j = 0; j < matrix_Width; j++) {
                printf("%d\t", Matrix_Result[i][j]);
            }
            printf("\n");
        }
    }
}


// matrix_transposed, basicamente troca a linha por colunas, antes esteva dando erro pois se trocar apenas as variaveis width e height alguns valores vao vir errados
// pois estavam nas posições antigas de i e j, então também foi trocado as posiçoes de i e j comparadas com as outras variaveis
void matrix_Transposed(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result){
    int i, j;

    if(matrix_Height <= 0 || matrix_Width <= 0){
        printf("Algo deu errado na transposicao da matriz. ");
    }
    else{

        printf("\n");

        for(i = 0; i < matrix_Height; i++){
            for(j = 0; j < matrix_Width; j++){
                Matrix_Result[j][i] = Matrix_A[i][j];
            }
        }
        printf(ANSI_COLOR_BLUE"\nMatrix transposta: "ANSI_COLOR_RESET);
        for (i = 0; i < matrix_Width; i++) {
            for (j = 0; j < matrix_Height; j++) {
                printf("%d\t", Matrix_Result[i][j]);
            }
            printf("\n");
        }
    }
}

// funçao apenas pra requisição de entrada de dados e print dos resultados
void print_Matrix_Transposed(int matrix_Height, int matrix_Width, int **Matrix_A, int **Matrix_Result, int i, int j){
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de linhas para a variavel A: "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Height);
    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de colunas para as variaveis A:  "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Width);

    // Alocando memória para as matrizes com base nas dimensões fornecidas pelo usuário
    Matrix_A = (int **)malloc(matrix_Height * sizeof(int *));
    Matrix_Result = (int **)malloc(matrix_Width * sizeof(int *));
    for (i = 0; i < matrix_Width; i++) {
        Matrix_Result[i] = (int *)malloc(matrix_Height * sizeof(int));
    }

    for (i = 0; i < matrix_Height; i++) {
        Matrix_A[i] = (int *)malloc(matrix_Width * sizeof(int));
        Matrix_Result[i] = (int *)malloc(matrix_Width * sizeof(int));
    }

    // entrada dos valores para as matrizes A e B
    for(i = 0; i < matrix_Height; i++){
        for(j = 0; j < matrix_Width; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix A[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_A[i][j]);
        }
    }

    printf(ANSI_COLOR_BLUE"\nMatrix normal: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Height, matrix_Width, Matrix_A, Matrix_Result);
    matrix_Transposed(matrix_Height, matrix_Width, Matrix_A, Matrix_Result);

    // Liberando a memória alocada
    for (i = 0; i < matrix_Height; i++) {
        free(Matrix_A[i]);
        free(Matrix_Result[i]);
    }
    free(Matrix_A);
    free(Matrix_Result);
}

void inverse_Matrix(float **Matrix_A, float **Matrix_Result, int matrix_Size){

    float pivo, m;
    int i, j, k;

    // Definindo a Matriz Identidade
    for(i = 0; i < matrix_Size; i++)
    {
        for(j = 0; j < matrix_Size; j++)
        {
            Matrix_Result[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }

    // Calculando a Matriz Inversa
    for(j = 0; j < matrix_Size; j++)
    {
        pivo = Matrix_A[j][j];

        // Normalizando a linha atual
        for(k = 0; k < matrix_Size; k++)
        {
            Matrix_A[j][k] /= pivo;
            Matrix_Result[j][k] /= pivo;
        }

        for(i = 0; i < matrix_Size; i++)
        {
            if(i != j)
            {
                m = Matrix_A[i][j];

                // Zerando elementos acima e abaixo da diagonal principal
                for(k = 0; k < matrix_Size; k++)
                {
                    Matrix_A[i][k] -= m * Matrix_A[j][k];
                    Matrix_Result[i][k] -= m * Matrix_Result[j][k];
                }
            }
        }
    }

    printf(ANSI_COLOR_BLUE"\nMatriz Identidade A:\n"ANSI_COLOR_RESET);
    for(i = 0; i < matrix_Size; i++)
    {
        for (j = 0; j < matrix_Size; j++)
        {
            printf("%.2f", Matrix_A[i][j]);
            if(j < matrix_Size - 1) printf("\t");
            else printf("\n");
        }
    }

    printf(ANSI_COLOR_BLUE"\nMatriz Inversa:\n"ANSI_COLOR_RESET);
    for(i = 0; i < matrix_Size; i++)
    {
        for (j = 0; j < matrix_Size; j++)
        {
            printf("%.2f", Matrix_Result[i][j]);
            if(j < matrix_Size - 1) printf("\t");
            else printf("\n");
        }
    }
}

void print_Inverse_Matrix(int matrix_Size, float **Matrix_A, float **Matrix_Result, int i, int j){

    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de linhas e colunas para a variavel A: "ANSI_COLOR_RESET);
    scanf("%i", &matrix_Size);

    // Alocando memória para as matrizes com base nas dimensões fornecidas pelo usuário
    Matrix_A = (float **)malloc(matrix_Size * sizeof(float *));
    Matrix_Result = (float **)malloc(matrix_Size * sizeof(float *));
    for (i = 0; i < matrix_Size; i++) {
        Matrix_A[i] = (float *)malloc(matrix_Size * sizeof(float));
        Matrix_Result[i] = (float *)malloc(matrix_Size * sizeof(float));
    }

    // entrada dos valores para as matrizes A
    for(i = 0; i < matrix_Size; i++){
        for(j = 0; j < matrix_Size; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix A[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%f", &Matrix_A[i][j]);
        }
    }

    inverse_Matrix(Matrix_A, Matrix_Result, matrix_Size);

    for (i = 0; i < matrix_Size; i++) {
        free(Matrix_A[i]);
        free(Matrix_Result[i]);
    }
    free(Matrix_A);
    free(Matrix_Result);

}

// para fazer a função do calculo de determinante foi usado a a formula de laplace (print da formula neste link https://prnt.sc/tmhKjx1ke4U8)
int calc_Determinant(int matrix_Size, int **Matrix_A){
    int i, j, k;
    if (matrix_Size == 1) {
        return Matrix_A[0][0];
    } else if (matrix_Size == 2) {
        return Matrix_A[0][0] * Matrix_A[1][1] - Matrix_A[0][1] * Matrix_A[1][0];
    } else {
        int det = 0;
        for (k = 0; k < matrix_Size; k++) {
            int **submatrix = (int **)malloc((matrix_Size - 1) * sizeof(int *));
            for (i = 0; i < matrix_Size - 1; i++) {
                submatrix[i] = (int *)malloc((matrix_Size - 1) * sizeof(int));
            }

            for (i = 1; i < matrix_Size; i++) {
                int col = 0;
                for (j = 0; j < matrix_Size; j++) {
                    if (j != k) {
                        submatrix[i - 1][col] = Matrix_A[i][j];
                        col++;
                    }
                }
            }

            det += (k % 2 == 0 ? 1 : -1) * Matrix_A[0][k] * calc_Determinant(matrix_Size - 1, submatrix);

            for (i = 0; i < matrix_Size - 1; i++) {
                free(submatrix[i]);
            }
            free(submatrix);
        }
        return det;
    }
}

void print_Calc_Determinant(int matrix_Size, int **Matrix_A, int **Matrix_Result, int i, int j){
    int num;

    printf(ANSI_COLOR_YELLOW"\nDigite a quantidade de linhas e colunas para a variavel A: "ANSI_COLOR_RESET);
    scanf("%i", &num);

    matrix_Size = num;

    // Alocando memória para as matrizes com base nas dimensões fornecidas pelo usuário
    Matrix_A = (int **)malloc(matrix_Size * sizeof(int *));
    Matrix_Result = (int **)malloc(matrix_Size * sizeof(int *));
    for (i = 0; i < matrix_Size; i++) {
        Matrix_Result[i] = (int *)malloc(matrix_Size * sizeof(int));
    }

    for (i = 0; i < matrix_Size; i++) {
        Matrix_A[i] = (int *)malloc(matrix_Size * sizeof(int));
        Matrix_Result[i] = (int *)malloc(matrix_Size * sizeof(int));
    }

    // entrada dos valores para as matrizes A e B
    for(i = 0; i < matrix_Size; i++){
        for(j = 0; j < matrix_Size; j++){
            printf(ANSI_COLOR_GREEN"\nMatrix A[%i][%i]: "ANSI_COLOR_RESET, i, j);
            scanf("%i", &Matrix_A[i][j]);
        }
    }

    printf(ANSI_COLOR_BLUE"\nMatrix normal: "ANSI_COLOR_RESET);
    normal_Matrix(matrix_Size, matrix_Size, Matrix_A, Matrix_Result);
    printf(ANSI_COLOR_BLUE"\nDeterminante: "ANSI_COLOR_RESET);
    printf("%i", calc_Determinant(matrix_Size, Matrix_A));

    for (i = 0; i < matrix_Size; i++) {
        free(Matrix_A[i]);
        free(Matrix_Result[i]);
    }
    free(Matrix_A);
    free(Matrix_Result);
}