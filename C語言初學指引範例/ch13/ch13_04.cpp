/*******************************
    �ɦW:ch13_04.cpp
    �\��:��ʳ]�w�����ܼƪ��
 *******************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
public:
    int VarA;
    void ShowVar();
private:
    int VarB;
};
void myclass::ShowVar()
{
    printf("VarA=%d\n", VarA);
    printf("VarB=%d\n", VarB);
}

void main(void)
{
    int i;
    myclass X[3];
    printf("�]�w��ȫe\n");

    for (i = 0; i < 3; i++) {
        X[i].ShowVar();
    }

    for (i = 0; i < 3; i++) {
        X[i].VarA = 0;
        //X[i].VarB=0;    //�L�k���Ψp�Φ����ܼ�
    }

    printf("�]�w��ȫ�\n");

    for (i = 0; i < 3; i++) {
        X[i].ShowVar();
    }

    /* system("pause"); */
}
