/************************************
    �ɦW:ch13_21.cpp
    �\��:�Ѻc�禡�P�ʺA�O����t�m
 ************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

class student
{
public:

    ~student();
    int stu_size();
    void showdata();

private:
    struct stu {
        char   stu_id[12];
        int    ScoreComputer;
        int    ScoreMath;
        int    ScoreEng;
        float  ScoreAvg;
    };
    stu Entry;     //C++�y�k
};

student::~student()
{
    cout << "���b�R��1��student���O������" << endl;
    //�z�٥i�H�b�o�䰵��L�Ƴ�~
}

int student::stu_size()
{
    return sizeof(stu);   //C++�y�k
}

void student::showdata()
{
    cout << Entry.stu_id << "\t" << Entry.ScoreComputer << "\t" \
         << Entry.ScoreMath << "\t" << Entry.ScoreEng << "\t" \
         <<  Entry.ScoreAvg << endl;
}


FILE* fp;

/**************main**************/
void main(void)
{
    student* IM;
    IM = new student[10];
    int i;

    if ((fp = fopen("data4", "rb")) == NULL) {
        cout << "�ɮ׿��~" << endl;
        exit(0);
    }

    int num = fread(IM, sizeof(student), 2, fp); //C++�y�k
    fclose(fp);
    cout << "�G�i����Ū������,�e�ⵧ�ǥ͸�Ʀp�U" << endl;

    for (i = 0; i < 2; i++) {
        IM[i].showdata();
    }

    delete [] IM;
}
