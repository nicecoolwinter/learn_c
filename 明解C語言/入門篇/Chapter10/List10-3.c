/*
�������Q�Ϋ��оާ@����
*/

#include  <stdio.h>

int main(void)
{
    int    soong   = 178;            /* ���p�쪺���� */
    int    chang   = 175;            /* �i�p�������� */
    int    chen    = 165;            /* ���p�󪺨��� */
    int    lin     = 179;            /* �L�p�������� */

    int* may, *lily;

    may   = &soong;  /* may����soong�]���w���p��^ */
    lily  = &lin;        /* lily����lin(���w�L�p���^ */

    printf("may���w���H�������G%d\n", *may);
    printf("lily���w���H�������G%d\n", *lily);

    may = &chang;       /* may����chang�]���ܤ߷N�^��*/

    *lily = 180;        /*�N180���w��lily�ҫ�������*/
    /*��glily���w���H������ */

    putchar('\n');
    printf("���p�쪺�����G%d\n", soong);
    printf("�i�p���������G%d\n", chang);
    printf("���p�󪺨����G%d\n", chen);
    printf("�L�p���������G%d\n", lin);
    printf("may���w���H�������G%d\n", *may);
    printf("lily���w���H�������G%d\n", *lily);

    return (0);
}
