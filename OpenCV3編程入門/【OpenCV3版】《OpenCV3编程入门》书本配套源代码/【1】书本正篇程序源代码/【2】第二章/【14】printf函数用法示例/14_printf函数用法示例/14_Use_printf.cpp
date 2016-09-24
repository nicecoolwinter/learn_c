//--------------------------------------【程序说明】-------------------------------------------
//      程序说明：《OpenCV3编程入门》OpenCV3版书本配套示例程序14
//      程序描述：printf函数用法示例
//      开发测试所用操作系统： Windows 7 64bit
//      开发测试所用IDE版本：Visual Studio 2010
//      开发测试所用OpenCV版本：    2.4.9
//      2014年06月 Created by @浅墨_毛星云
//      2014年12月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------

#include <opencv2/opencv.hpp>
using namespace cv;

void main()
{
    int a = 66, b = 68;
    printf("\n\t%d %d\n", a, b); //输出十进制整型
    printf("\n\t%06d,%06d\n", a, b); //输出6位十进制整型
    printf("\n\t%c,%c\n", a, b); //按字符型输出
    printf("\n\t结果为：a=%d,b=%d", a, b); //可以配合其他内容一同输出
    getchar();//等待读入任意字符而结束，在此用于保持窗口显示，直到任意按键按下
}
