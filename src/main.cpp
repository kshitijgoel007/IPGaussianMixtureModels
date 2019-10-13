#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
 #include <fstream>
using namespace std;
using namespace cv;
Mat histogram(Mat);
Mat gmm_data(Mat,Mat);


/**
 * @function main
 */
int main( int argc, char** argv )
{
  Mat src, dst;
  
  /// Load image
  src = imread( argv[1], 1 );

  if( !src.data )
    { return -1; }
  Mat histImage = histogram(src);
  //outputfile(histImage);
  Mat graph_plot=gmm_data(histImage,src);
  namedWindow("graphs", CV_WINDOW_AUTOSIZE );
  imshow("graphs",graph_plot);
  
          
  imshow("image",src);
  waitKey(0);

  return 0;
}
Mat histogram(Mat src)
{
    
  /// Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  /// Establish the number of bins
  int histSize = 256;

  
  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 256 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  Mat b_hist, g_hist, r_hist;

  /// Compute the histograms:
  calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

  // Draw the histograms for B, G and R
  int hist_w = 256; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );
  cout<<bin_w<<endl;
  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  /// Normalize the result to [ 0, histImage.rows ]
  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  /// Draw for each channel
  for( int i = 1; i < histSize; i++ )
  {
     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                     Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                     Scalar( 255, 0, 0), 2, 8, 0  );
     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                      Scalar( 0, 255, 0), 2, 8, 0  );
     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                      Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                       Scalar( 0, 0, 255), 2, 8, 0  );
  }

  /// Display
  namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
  imshow("calcHist Demo", histImage );
  return histImage;
}        
Mat gmm_data(Mat img,Mat src)

{
    
    ofstream output;
    output.open("output.txt");
    Mat graph(img.rows,img.cols, CV_8UC1);
     for(int i= 0;i<img.cols;i++)
    {
      for(int j=0;j<img.rows;j++)
        {
           // if(img.at<Vec3b>(j, i)[2] == 255 )
           // {
               
               
               graph.at<uchar>(j,i) = 0;
               // output<< i<<", "<<img.rows-j+1<<"\n";
             //   j=1000;
           // }
          
        }    
        
    }
     for(int i= 0;i<img.cols;i++)
    {
        for(int j=0;j<img.rows;j++)
        {
            
          if(img.at<Vec3b>(j, i)[2] == 255 || j==(img.rows-1) )
            {
               
              
            graph.at<uchar>(j,i) = 100;
           // output<< i<<", "<<img.rows-j+1<<"\n";
                j=1000;
            }
          
         
          
        }    
        
        
        
    }
    
    int count=0;
    for(int i= 0;i<src.cols;i++)
    {
        for(int j=0;j<src.rows;j++)
        {         
                output<< count<<", "<<(int)src.at<Vec3b>(j,i)[2]<<"\n";   
                count++;
                cout<<(int)src.at<Vec3b>(j,i)[2]<<"  "<<count<<endl;
        }    
        
    }
    //imshow("graph",graph);
    return graph;
}            