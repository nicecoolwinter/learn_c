/***************************
    �ɦW:ch7_21.cpp
    �\��:�޼ƹw�]��
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SeqSearch(int Target, int* arr, int arr_index);
void generate_lotto(int* spec_num, int* arr, int arr_index = 6);

/**************�`�Ƿj�M**************/
int SeqSearch(int Target, int* arr, int arr_index)
{
    int i;

    for (i = 0; i < arr_index; i++)
        if (Target == arr[i]) {  /*  ���F  */
            return i;
        }

    return -1;                  /*  �����䤣��  */
}

/**************���ͼֳz���X**************/
void generate_lotto(int* spec_num, int* arr, int arr_index = 6)
{
    int i, generate_num;
    srand((unsigned) time(NULL));

    for (i = 0; i < arr_index; i++) {
        generate_num = rand() % 42 + 1;

        while (SeqSearch(generate_num, arr, i + 1) != -1) { /*  �O�_����  */
            generate_num = rand() % 42 + 1;
        }

        arr[i] = generate_num;
    }

    generate_num = rand() % 42 + 1;

    while (SeqSearch(generate_num, arr, i) != -1) { /*  �S�O���O�_�P��L���X����  */
        generate_num = rand() % 42 + 1;
    }

    *spec_num = generate_num;
}

/**************main()**************/
void main(void)
{
    int lotto[6], i, special;
    generate_lotto(&special, lotto);
    printf("�ֳz���X�p�U.....\n");

    for (i = 0; i < 6; i++) {
        printf("%d\t", lotto[i]);
    }

    printf("\n");
    printf("�S�O��:%d\n", special);
    /*  system("pause");  */
}
