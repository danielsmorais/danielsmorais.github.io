#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
    Mat image;
    image = imread(argv[1],CV_LOAD_IMAGE_COLOR);

    if(!image.data)
    {
        cout << "Não foi possível abrir ou encontrar a imagem 1" << endl;
    }
    else
    {
        namedWindow("Display window 1", WINDOW_AUTOSIZE);
        imshow("Display window 1", image);
    }

    image = imread(argv[2], CV_LOAD_IMAGE_COLOR);
    if(!image.data)
    {
        cout << "Não foi possível abrir ou encontrar a imagem 2" << endl;
    }
    else
    {
        namedWindow("Display window 2", WINDOW_AUTOSIZE);
        imshow("Display window 2", image);
    }

    waitKey();
    return 0;
}
