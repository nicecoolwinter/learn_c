/**********************************
    �ɦW:ch13_11.cpp
    �\��:�[��ѫغc�禡������ɾ�
 **********************************/

#include <stdlib.h>
#include <stdio.h>

class myclass
{
public:
    myclass();           //�ŧi�غc�禡
    ~myclass();          //�ŧi�Ѻc�禡
};
myclass::myclass()    //�w�q�غc�禡
{
    printf("�غc�禡���椤..........\n");
}
myclass::~myclass()    //�w�q�Ѻc�禡
{
    printf("�Ѻc�禡���椤..........\n");
}

void main(void)
{
    printf("�{���}�l����\n");
    printf("�ǳƥͦ�����\n");
    myclass X;
    printf("����ͦ�����\n");
    printf("�{���Y�N����\n");
    /* system("pause"); */
}
