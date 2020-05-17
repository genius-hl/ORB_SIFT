//
// Created by bene on 2020/5/11.
//

#ifndef ORB_SIFT_ORBTEST_H
#define ORB_SIFT_ORBTEST_H

#include<opencv2/core/core.hpp>
#include<opencv2/features2d/features2d.hpp>
#include <opencv/cv.h>

#include <vector>

#include "../include/ORBextractor.h"
#include "../include/Frame.h"
#include "../include/ORBmatcher.h"

namespace ORB_SIFT{
    class ORBTest{
    public:
        ORBTest();
        ORBTest(std::string strSettingPath);
        ~ORBTest(){delete mpORBextractor;}
        void Extract_ORB(const cv::Mat &im);
        void Match_ORB();
        void GetROIOrigin(cv::Rect roi);
        void GrabImage(const cv::Mat &img, const double &timestamp);
        void Compute_HW_ROI();
        void WarpROI();
        void DrawMatches();
        void SaveResult(const string& SaveFileName);
    protected:
        void Shift_Keys_From_ROI_To_Origin();


        void DrawROI(const cv::Mat& image,
                const double lower_row,const double middle_col,
                 cv::Mat& ROIimage);

        void ORBMatch();
        void CopyKeys();
    public:
        //camera parameter
        cv::Mat mK;
        cv::Mat mDistCoef;
        float mbf;
        bool mbRGB;
        ORBextractor* mpORBextractor;

        std::vector<cv::KeyPoint> Last_mvKeysROI;
        std::vector<cv::KeyPoint> Curr_mvKeysROI;
        cv::Mat mDescriptors;

        Frame mCurrentFrame;
        Frame mLastFrame;
        vector<int> vnMatches12;

        cv::Mat mCurrentImg;
        cv::Mat mLastImg;
        cv::Mat mROI_Img;

        cv::Rect mROI;

        bool mbFirstImg;
    protected:
        cv::Point mROIOrigin;    //兴趣区域的原点在原图中坐标
        int mImg_HEIGHT;
        int mImg_WIDTH;


    };
}

#endif //ORB_SIFT_ORBTEST_H
