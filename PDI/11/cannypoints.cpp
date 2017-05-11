#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace cv;

//Definição de constantes

#define STEP 5
#define RAIO 3
#define JITTER 3

int main(int argc, char** argv){
  vector<int> yrange;
  vector<int> xrange;

  Mat image, borderImage;
  Mat pontilhismo;
  int width, height, gray, x, y;

  image= imread("ponte.jpg",CV_LOAD_IMAGE_GRAYSCALE);

  srand(time(0));

  if(!image.data){
    cout << "Impossível ler a imagem."<< endl;
    exit(0);
  }

  width = image.size().width;
  height = image.size().height;

  xrange.resize(height/STEP);
  yrange.resize(width/STEP);

  iota(xrange.begin(), xrange.end(), 0);
  iota(yrange.begin(), yrange.end(), 0);

  for(int i=0; i<xrange.size(); i++){
    xrange[i] = xrange[i]*STEP+STEP/2;
  }
  
  for(int j=0; j<yrange.size(); j++){
    yrange[j] = yrange[j]*STEP+STEP/2;
  }

  image.copyTo(pontilhismo);
  random_shuffle(xrange.begin(), xrange.end());

  for(auto i : xrange){
    random_shuffle(yrange.begin(), yrange.end());
    for(auto j : yrange){
      x = i+rand()%(2*JITTER)-JITTER+1;
      y = j+rand()%(2*JITTER)-JITTER+1;
      gray = image.at<uchar>(x,y);
      circle(pontilhismo,
             cv::Point(y,x),
             RAIO,
             CV_RGB(gray,gray,gray),
             -1,
             CV_AA);
    }
  }

  imshow("pontilhismo", pontilhismo);
  imwrite("pontilhismo.png", pontilhismo);

  for(int n = 0; n < 5; n++){
     Canny(image, borderImage, 10 * n, 50 * n);
     imshow("cannyborderImage", borderImage);
     imwrite("cannyborderImage.png", borderImage);     
     
     int raio = 5 - n;

     for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
           if(borderImage.at<uchar>(i,j)>0){
              gray = image.at<uchar>(i,j);
              circle(pontilhismo,
                     cv::Point(j,i),
                     raio,
                     CV_RGB(gray,gray,gray),
                     -1,
                     CV_AA);
           }
        }
     }
  }

  imshow("cannyPoints", pontilhismo);
  imwrite("cannyPoints.png", pontilhismo);

  waitKey();
  return 0;
}
