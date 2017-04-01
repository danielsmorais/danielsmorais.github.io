#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

double alfa;
int alfa_slider = 0;
int alfa_slider_max = 100;

int top_slider = 0;
int top_slider_max = 100;

Mat image1, image2, blended;
Mat imageTop; 

Mat frame32f, frameFiltered;

float media[] = { 1, 1, 1,
                  1, 1, 1,
                  1, 1, 1
};
char TrackbarName[50];

void on_trackbar_blend(int, void*){
 alfa = (double) alfa_slider/alfa_slider_max ;
 addWeighted( image1, alfa, imageTop, 1-alfa, 0.0, blended);
 imshow("addweighted", blended);
}

void on_trackbar_line(int, void*){
  image1.copyTo(imageTop);
  int limit = top_slider*628/100;
  if(limit > 0){
	Mat tmp = image2(Rect(0, 0, 256, limit));
	tmp.copyTo(imageTop(Rect(0, 0, 256, limit)));
  }
  on_trackbar_blend(alfa_slider,0);
}

int main(int argvc, char** argv){
  image1 = imread("../imagens/woman.jpg");          //628x418
  image2 = imread("../imagens/woman.jpg");
  for(int i=0; i<10; i++)  
    GaussianBlur(image2, image2, Size(9,9),0,0);
      
  image2.copyTo(imageTop);
  
  
  namedWindow("addweighted", 1);
  
  sprintf( TrackbarName, "Alpha x %d", alfa_slider_max );
  createTrackbar( TrackbarName, "addweighted",
				  &alfa_slider,
				  alfa_slider_max,
				  on_trackbar_blend );
  on_trackbar_blend(alfa_slider, 0 );
  
  sprintf( TrackbarName, "Scanline x %d", top_slider_max );
  createTrackbar( TrackbarName, "addweighted",
				  &top_slider,
				  top_slider_max,
				  on_trackbar_line );
  on_trackbar_line(top_slider, 0 );
  
  sprintf( TrackbarName, "Decaimento x %d", top_slider_max );
  createTrackbar( TrackbarName, "addweighted",
				  &top_slider,
				  top_slider_max,
				  on_trackbar_line );
  on_trackbar_line(top_slider, 0 );

  waitKey(0);
  return 0;
}
