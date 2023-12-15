#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include "functions.h"

int main() {

// Apenas motivo estetico, mudar o titulo do console
    SetConsoleTitle("..:: MATRIX ::..");

    int matrix_Height = 2; // valores padrões para linha
    int matrix_Width = 2; // valores padrões para coluna

    char opc; // variavel da opção selecionada pelo usuario

    //definindo matrizes como ponteiros e declarando valores a principio como nulos já que não teve nenhuma entrada ainda.
    int **Matrix_A = NULL;
    int **Matrix_B = NULL;
    int **Matrix_Result = NULL;
    float **Matrix_aA = NULL;
    float **Matrix_rResult = NULL;

    system("cls");
    show_logo();

    while (1) {

        printf(ANSI_COLOR_RED"\nCommand:~$  " ANSI_COLOR_RESET);
        fflush(stdin); // fflush para limpar a entrada de dados no scanf e não vir nenhum caracter indesejado como \n ou \0 por exemplo.
        scanf("%c", &opc);

        // isdigit verifica se a entrada do tipo char é um numero, caso não seja, sera solicitado ao usuario para que reenviar a opção novamente
        if (isdigit(opc)) {

            switch (opc) {
                case '1': // soma de matrizes
                    print_Sum(matrix_Height, matrix_Width, Matrix_A, Matrix_B, Matrix_Result, 0, 0);
                    break;
                case '2': // subtração de matrizes
                    print_Sub(matrix_Height, matrix_Width, Matrix_A, Matrix_B, Matrix_Result, 0, 0);
                    break;
                case '3': // produto de um numero por uma matriz
                    print_Matrix_Mult_Num(matrix_Height, matrix_Width, Matrix_A, Matrix_Result, 0, 0);
                    break;
                case '4': // produto de matrizes
                    print_Matrix_Mult_Matrix(matrix_Height, matrix_Width, Matrix_A, Matrix_B, Matrix_Result, 0, 0);
                    break;
                case '5': // calculo de determinante
                    print_Calc_Determinant( 3, Matrix_A, Matrix_Result, 0, 0);
                    break;
                case '6': // matriz inversa
                    print_Inverse_Matrix(3, Matrix_aA, Matrix_rResult, 0, 0);
                    break;
                case '7': // matriz transposta
                    print_Matrix_Transposed(matrix_Height, matrix_Width, Matrix_A, Matrix_Result, 0, 0);
                    break;
                case '8': // sair do programa
                    return 0;
                case '9': // limpar o terminal
                    system("cls");
                    show_logo();
                    break;
                case '0': // informações adicionais sobre as operações
                    printf(ANSI_COLOR_YELLOW"\n1. Soma de matrizes so pode ser feita se as duas variaveis forem equivalentes, logo o programa ira pedir uma unica quantidade de linhas e colunas.\n\n2. Subtracao de matrizes so pode ser feita se as duas variaveis forem equivalentes, logo o programa ira pedir uma unica quantidade de linhas e colunas\n\n3. Feita a multiplicacao de matriz usando um numero como base\n\n4. Feita a multiplicacao de matriz com outra matriz\n\n5. Calculo de determinante feita com a formula de laplace\n\n6. faz o calculo de matriz inversa, caso o calculo resulte em numeros e simbolos aleatorios, significa que a matriz nao e inversivel\n\n7. Matriz transposta troca as linhas pela as colunas\n\n8. Finaliza o programa\n\n9. Limpa o terminal\n\n"ANSI_COLOR_RESET);
                    break;
            }
        }
        else{
            printf(ANSI_COLOR_RED"\nOPCAO INVALIDA. TENTE NOVAMENTE\n"ANSI_COLOR_RESET);
        }
    }
    return 0;
}

