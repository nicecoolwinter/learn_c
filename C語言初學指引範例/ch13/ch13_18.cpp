/*******************************
    �ɦW:ch13_18.cpp
    �\��:cin���󪺽m��
 *******************************/

#include <iostream>

using namespace std;

void main()
{
    int   a1, a2;
    float b;
    char* s;
    int* p;
    p = &a2;               // p���Va2
    cout << "�п�Ja1,a2:";
    cin >> a1 >> *p;
    cout << "�п�Jb:";
    cin >> b;
    cout << "�п�Js�r��:";
    cin >> s;
    cout << "a1=" << a1 << "\ta2=" << a2 << "\tb=" << b << "\ts=" << s << endl;
}
