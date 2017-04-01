#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main(int, char**){

    Mat image;    
    image = imread("../imagens/biel.png", CV_LOAD_IMAGE_GRAYSCALE);

    if(!image.data)
        cout << "Não foi possível abrir ou encontrar a imagem." << endl;
    
    //uint8_t altura = image.size().height;
    //uint8_t largura = image.size().width;
        
    namedWindow("Imagem Original",WINDOW_AUTOSIZE);
    imshow("Imagem Original", image);
    //waitKey(0);    
    
    
    Point p1, p2;
    
    cout << "Informe as coordenadas de dois pontos entre (0, 0) e (255, 255):" << endl;
    do{
        cout << "P1.x: ";
        cin >> p1.x;
        cout << "P1.y: ";
        cin >> p1.y;        
        cout << "P2.x: ";
        cin >> p2.x;
        cout << "P2.y: ";
        cin >> p2.y;        
    }while(p1.x > 255 || p1.x < 0 || p1.y > 255 || p1.y < 0 || 
           p2.x > 255 || p2.x < 0 || p2.y > 255 || p2.y < 0 || 
           p1.x > p2.x || p1.y > p2.y);
    
    cout << "Pontos selecionados: "<< "P1("<<p1.x<<", "<<p1.y<<") e P2("<<p2.x<<", "<<p2.y<<")"<< endl;      
   
    
    for(int i=p1.x;i<p2.x;i++){
        for(int j=p1.y;j<p2.y;j++){
            image.at<uchar>(i,j)= 255 - image.at<uchar>(i,j);
        }
    }
    
    namedWindow("Imagem Negativo",WINDOW_AUTOSIZE);
    imshow("Imagem Negativo", image);
    waitKey(0);
    
    return 0;
}