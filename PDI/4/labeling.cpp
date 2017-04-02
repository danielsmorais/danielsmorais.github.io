#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat image, mask;
    int width, height;
    int nobjects;

    CvPoint p;
    image = imread("../imagens/bolhas.png", CV_LOAD_IMAGE_GRAYSCALE);

    if (!image.data) {
        cout << "imagem nao carregou corretamente\n";
        return (-1);
    }
    width = image.size().width;         //colunas
    height = image.size().height;       //linhas

    p.x = 0;
    p.y = 0;

    // busca objetos com buracos presentes
    nobjects = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (image.at < uchar > (i, j) == 255) {
                // achou um objeto
                nobjects++;
                p.x = j;
                p.y = i;

                //Todos os objetos são rotulados no tom de cinza 200;
                floodFill(image, p, 200);
            }
        }
    }

    cout << "Número de objetos: " << nobjects << endl;

    imshow("image", image);
    imwrite("labeling.png", image);
    waitKey();
    return 0;
}