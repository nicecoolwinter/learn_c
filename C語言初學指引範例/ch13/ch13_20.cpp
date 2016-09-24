/*******************************
    �ɦW:ch13_20.cpp
    �\��:new��delete������
 *******************************/

#include <stdlib.h>
#include <iostream>
#include "./lotto.h"

using namespace std;

/**************main()**************/
int main(int argc, char* argv[])
{
    int i, special, ball_qty = 6, temp;
    int* lotto;

    if (argc > 1) {
        ball_qty = atoi(argv[1]); /* atoi���ޤJstdlib.h */

        if (ball_qty == 0) {
            cout << "�Ѽƿ��~,�Ҧp��J�y�ƫD�Ʀr\n";
            return -1;
        }

        if (!((ball_qty >= 1) && (ball_qty <= 41))) {
            cout << "�Ѽƿ��~,�Ҧp��J�y�ƫD1~41\n";
            return -1;
        }
    }

    lotto = new int[ball_qty];
    generate_lotto_sort(&special, lotto, ball_qty);
    cout << "�ֳz���X�p�U.....\n";

    for (i = 0; i < ball_qty; i++) {
        if ((i % 6 == 0) && (i != 0)) {
            cout << "\n";
        }

        cout << lotto[i] << "\t";
    }

    if (ball_qty == 1) {
        delete lotto;
    } else {
        delete [] lotto;
    }

    cout << "\n";
    cout << "�S�O��:" << special << endl;
    return 1;
}
