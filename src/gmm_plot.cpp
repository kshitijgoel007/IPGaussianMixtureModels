
/* 
 * File:   gmm_plot.cpp
 * Author: dyutimoy
 *
 * Created on 5 March, 2017, 9:10 PM
 */

#include <cstdlib>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
 #include <fstream>
using namespace std;
using namespace cv;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    ifstream infile(argv[1]);
    float prob[256];
    int norm_prob[256];
    float min =1000 ;
    float max = 0;
    int i=0;
    while(i<256)
    {
        i++;
        infile >> prob[i];
        cout << prob[i]<<"  "<<i<<endl;
        if(prob[i]<min)
        {
            min=(prob[i]);
        }    
        if(prob[i]>max)
        {   max=prob[i];}
        
        
    }
    
    cout<<max<<" max"<<endl;
    cout<<min<<" min"<<endl;
    Mat img(400,256,CV_8UC1);
     for(int i= 0;i<img.cols;i++)
    {
      for(int j=0;j<img.rows;j++)
        {
           // if(img.at<Vec3b>(j, i)[2] == 255 )
           
               
               
               img.at<uchar>(j,i) = 0;
               // output<< i<<", "<<img.rows-j+1<<"\n";
             //   j=1000;
           // }
          
        }    
        
    }
    
    int j=0;
    Point center;
    
    while(j<256)
    {
        j++;
        norm_prob[j]=(int)((prob[j]-min)*400/(max-min));
        
        center.x=norm_prob[j];
        center.y=j;
        cout << norm_prob[j]<<"  "<<j<<endl;
        img.at<uchar>(400-norm_prob[j],j)=255;

        
        
    }
    //namedWindow("plot", CV_WINDOW_AUTOSIZE );
    imshow("plot",img);
     waitKey(0);
    
    
    
    
           
    return 0;
}

