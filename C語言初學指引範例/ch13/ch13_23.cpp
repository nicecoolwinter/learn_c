/*******************************************************
    �ɦW:ch13_23.cpp
    �\��:�ƻs�ɮ�(�ϥ�ifstream.get()�Pofstream.put()
 *******************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main(void)
{
    ifstream readfile;
    ofstream writefile;
    string filename1, filename2;
    char c;
    cout << "�п�J�ӷ��ɦW:";
    cin >> filename1;
    cout << "�п�J�ت��ɦW:";
    cin >> filename2;
    readfile.open(filename1.c_str());
    writefile.open(filename2.c_str(), ios::out | ios::trunc);

    if (readfile.fail() || writefile.fail()) { //�}�ɥ���
        cout << "�ɮ׵o�Ϳ��~" << endl;
        exit(1); //�j�������{��
    }

    cout << "Ū���üg�J��......" << endl;

    while (readfile.get(c)) { //�ϥΰj��Ū���ӷ��ɤ��e
        cout << c;
        writefile.put(c); //�ϥΰj��g�J�ت��ɤ��e
    }

    cout << "\nŪ���üg�J����......" << endl;
    readfile.close();
    writefile.close();
}
