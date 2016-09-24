/**************************************
     �ɦW:useful_algorithm.h
     ���g�H:jhchen
     �γ~:���h��Ƶ��c�������t��k
     ����:v1.0 (for C language)
 **************************************/

/***************�禡�ŧi��*************/
void BubbleSort(int* arr, int arr_index);
int SeqSearch(int Target, int* arr, int arr_index);
int BinarySearch(int Target, int* arr, int arr_index);


/*************************��w�Ƨ�****************************
   �y�k�G  void BubbleSort(int *arr,int arr_index);
   �޼ơG  arr[ ]���u�@�}�C�Aarr_index���u�@�}�C�j�p�C
   �^�ǭȡG�L�C
   ���ѡG  �禡���槹���Aarr[]�������|�̷ӥѤp�Ӥj�Ƨ�
 *************************************************************/
void BubbleSort(int* arr, int arr_index) {
    int k, times, i, temp;
    k = arr_index - 1;

    while (k != 0) {
        times = 0;

        for (i = 0; i <= k - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp; /* [i]�P[i+1]���� */
                times = i;
            }
        }

        k = times;
    }
}


/*************************�`�Ƿj�M****************************
   �y�k�G  int SeqSearch(int Target,int *arr,int arr_index);
   �޼ơG  Target���M��ؼСC
           arr[ ]���u�@�}�C�Aarr_index���u�@�}�C�j�p�C
   �^�ǭȡG�YTarget���arr[ ]�}�C���A�h�^�ǯ��ޭȡC
           �YTarget�����arr[ ]�}�C���A�h�^��-1�C
 *************************************************************/
int SeqSearch(int Target, int* arr, int arr_index) {
    int i;

    for (i = 0; i < arr_index; i++)
        if (Target == arr[i]) {  /*  ���F  */
            return i;
        }

    return -1;                  /*  �����䤣��  */
}


/*************************�G���j�M****************************
   �y�k�G  int BinarySearch(int Target,int *arr,int arr_index)
   �޼ơG  Target���M��ؼСC
           arr[ ]���w�ƧǪ��u�@�}�C�Aarr_index���u�@�}�C�j�p�C
   �^�ǭȡG�YTarget���arr[ ]�}�C���A�h�^�ǯ��ޭȡC
           �YTarget�����arr[ ]�}�C���A�h�^��-1�C
 *************************************************************/
int BinarySearch(int Target, int* arr, int arr_index) {
    int Low, Upper, m;
    Low = 0;
    Upper = arr_index - 1;

    while (Low <= Upper) {
        m = (Low + Upper) / 2; /* �p�⤤����m */

        if (arr[m] == Target) { /* ���F */
            return m;
        } else {
            if (arr[m] > Target) { /* Target���W�b�� */
                Upper = m - 1;
            } else {           /* Target���U�b�� */
                Low = m + 1;
            }
        }
    }

    return -1;
}
