/*******************************
    �ɦW:ch13_01.cpp
    �\��:�ŧi�T�����O�P3�Ӫ���
 *******************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class car
{
public:
    int wheel;
    int person;
    char name[20];
private:
    char engine[20];
};

void main(void)
{
    car bus, truck, taxi;
    strcpy(bus.name, "����");
    bus.wheel = 6;
    bus.person = 40;
    strcpy(truck.name, "�d��");
    truck.wheel = 8;
    truck.person = 3;
    strcpy(taxi.name, "�p�{��");
    taxi.wheel = 4;
    taxi.person = 5;
    //strcpy(taxi.engine,"V16");         ���i�s���p�Ϋ��A���ܼ�
    printf("%s��%d�ӽ��l,�i��%d�H\n", bus.name, bus.wheel, bus.person);
    printf("%s��%d�ӽ��l,�i��%d�H\n", truck.name, truck.wheel, truck.person);
    printf("%s��%d�ӽ��l,�i��%d�H\n", taxi.name, taxi.wheel, taxi.person);
    /* system("pause"); */
}
