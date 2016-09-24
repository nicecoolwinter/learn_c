/**************************************
     �ɦW:lotto.h
     ���g�H:jhchen
     �γ~:���Ѽֳz�C�������禡
     ����:v1.0 (for C language)
 **************************************/

#include <stdlib.h>
#include <time.h>
#include "./useful_algorithm.h"

/***************�禡�ŧi��*************/
int generate_lotto(int* spec_num, int* arr, int arr_index);
int generate_lotto_sort(int* spec_num, int* arr, int arr_index);


/***************************���ͼֳz���X(���Ƨ�)************************
   �y�k�G  int generate_lotto(int *spec_num,int *arr,int arr_index);
   �\��G  �|�q1~42�����A�}�X���ƧǪ�arr_index�Ӳy�A�~�[�@�ӯS�O���C
   �޼ơG  arr[ ]���u�@�}�C�Aarr_index���u�@�}�C�j�p�C
           arr_index���}�y�ƥءA��������1~41�C
           spec_num���S�O���s���ܼ�(�ϥζǫ��ЩI�s)
   �^�ǭȡG0�����~,1�����楿�T�C
 ***********************************************************************/
int generate_lotto(int* spec_num, int* arr, int arr_index) {
    int i, generate_num;
    srand((unsigned) time(NULL));

    if (!((arr_index >= 1) && (arr_index <= 41))) {
        return 0;    /* �޼ƿ��~,�Ҧp��J�y�Ƭ��r��ӫD�Ʀr1~41 */
    }

    for (i = 0; i < arr_index; i++) {
        generate_num = rand() % 42 + 1;

        while (SeqSearch(generate_num, arr, i + 1) != -1) { /* �O�_���� */
            generate_num = rand() % 42 + 1;
        }

        arr[i] = generate_num;
    }

    generate_num = rand() % 42 + 1;

    while (SeqSearch(generate_num, arr, i) != -1) { /* �S�O���O�_�P��L���X���� */
        generate_num = rand() % 42 + 1;
    }

    *spec_num = generate_num;
    return 1;
}

/***************************���ͼֳz���X(�w�Ƨ�)***************************
   �y�k�G  int generate_lotto_sort(int *spec_num,int *arr,int arr_index);
   �\��G  �|�q1~42�����A�}�X�w�ƧǪ�arr_index�Ӳy�A�~�[�@�ӯS�O���C
   �޼ơG  arr[ ]���u�@�}�C�Aarr_index���u�@�}�C�j�p
           arr_index���}�y�ƥءA��������1~41�C
           spec_num���S�O���s���ܼ�(�ϥζǫ��ЩI�s)
   �^�ǭȡG0�����~,1�����楿�T�C
 **************************************************************************/
int generate_lotto_sort(int* spec_num, int* arr, int arr_index) {
    if (generate_lotto(spec_num, arr, arr_index)) {
        BubbleSort(arr, arr_index);
    } else {
        return 0;
    }

    return 1;
}
