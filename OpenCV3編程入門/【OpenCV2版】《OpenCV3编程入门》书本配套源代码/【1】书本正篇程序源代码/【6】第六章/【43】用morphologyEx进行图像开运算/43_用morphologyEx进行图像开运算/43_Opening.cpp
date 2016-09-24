
//--------------------------------------【程序说明】-------------------------------------------
//      程序说明：《OpenCV3编程入门》OpenCV2版书本配套示例程序43
//      程序描述：用morphologyEx进行图像形态学开运算用法示例
//      开发测试所用操作系统： Windows 7 64bit
//      开发测试所用IDE版本：Visual Studio 2010
//      开发测试所用OpenCV版本：    2.4.9
//      2014年06月 Created by @浅墨_毛星云
//      2014年11月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------


//---------------------------------【头文件、命名空间包含部分】----------------------------
//      描述：包含程序所使用的头文件和命名空间
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

//-----------------------------------【main( )函数】--------------------------------------------
//      描述：控制台应用程序的入口函数，我们的程序从这里开始
//-----------------------------------------------------------------------------------------------
int main()
{
    //载入原始图
    Mat image = imread("1.jpg");  //工程目录下应该有一张名为1.jpg的素材图
    //创建窗口
    namedWindow("【原始图】开运算");
    namedWindow("【效果图】开运算");
    //显示原始图
    imshow("【原始图】开运算", image);
    //定义核
    Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
    //进行形态学操作
    morphologyEx(image, image, MORPH_OPEN, element);
    //显示效果图
    imshow("【效果图】开运算", image);

    waitKey(0);

    return 0;
}
