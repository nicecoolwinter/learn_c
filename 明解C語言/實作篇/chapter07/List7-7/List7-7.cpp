//
//  C++�����c
//

#include  <iostream>

struct Complex {                    // �bC++����Complex��
private:
    double  re, im;
public:
    Complex(double r, double i)     // �غc�l
    {
        re = r;
        im = i;
    }

    double Real(void)
    {
        return (re);
    }
    double Image(void)
    {
        return (im);
    }
};

using namespace  std;

int main(void)
{
    Complex  a(0, 0);
    Complex*  pa = &a;

    cout << "  a = (" << a.Real()   << ", " << a.Image()   << ")\n";
    cout << "*pa = (" << pa->Real() << ", " << pa->Image() << ")\n";

    system("PAUSE");
    return (0);
}
