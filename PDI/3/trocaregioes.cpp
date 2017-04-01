#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main(int, char **)
{

    Mat image, aux, aux2;
    image = imread("../imagens/biel.png", CV_LOAD_IMAGE_GRAYSCALE);

    if (!image.data) 
	{
        cout << "Não foi possível abrir ou encontrar a imagem." << endl;
        return 0;
    }

    aux = image(Rect(0, 0, 128, 128)).clone();  		//Rect(x0, y0, x, y ) x e y é o quanto eu quero pegar
    aux2 = image(Rect(128, 128, 128, 128)).clone();
    aux.copyTo(image(Rect(128, 128, 128, 128)));
    aux2.copyTo(image(Rect(0, 0, 128, 128)));

    aux = image(Rect(0, 128, 128, 128)).clone();        //Rect(x0, y0, x, y ) x e y é o quanto eu quero pegar        
    aux2 = image(Rect(128, 0, 128, 128)).clone();
    aux.copyTo(image(Rect(128, 0, 128, 128)));
    aux2.copyTo(image(Rect(0, 128, 128, 128)));

    namedWindow("Imagem", WINDOW_AUTOSIZE);
    imshow("Imagem", image);

    waitKey(0);

    return 0;
}




//http://pt.stackoverflow.com/questions/17328/edi%C3%A7%C3%A3o-b%C3%A1sica-de-imagens-utilizando-opencv
