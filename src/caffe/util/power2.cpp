#include "caffe/util/power2.hpp"
#include "caffe/common.hpp"
#include <math.h>

namespace caffe
{
  template <typename Dtype>
  double weightCluster( Dtype weight, int M)
  {
    double min=100;
    double ind=0;
    double flag=1.0;
    if(min>std::abs(weight))
    {
      min=std::abs(weight);
      flag=0.0;
    }
          
    for(int i=(M-7);i<=M;i++)
      {
        if(min>std::abs(weight-pow(2,i)))
          {
            min=std::abs(weight-pow(2,i));
            ind=i;
            flag=1.0;
          }
        if(min>std::abs(weight+pow(2,i)))
          {
            min=std::abs(weight+pow(2,i));
            ind=i;
            flag=-1.0;
          }
      }
      return flag*pow(2,ind);
  }
  
    template <typename Dtype>
  double weightCluster_zero( Dtype weight, int M)
  {
    double min=100;
    double ind=0;
    double flag=1.0;
    if(min>std::abs(weight))
    {
      min=std::abs(weight);
      flag=0.0;
    }
          
    for(int i=(M-7);i<=M;i++)
      {
        if(min>std::abs(weight-pow(2,i)))
          {
            min=std::abs(weight-pow(2,i));
            ind=i;
            flag=1.0;
          }
        if(min>std::abs(weight+pow(2,i)))
          {
            min=std::abs(weight+pow(2,i));
            ind=i;
            flag=-1.0;
          }
      }
      return flag*pow(2,ind);
  }

  template double weightCluster<float>(float weight,int M);
  template double weightCluster<double>(double weight,int M);
  template double weightCluster<unsigned int>(unsigned int weight,int M);
  template double weightCluster<int>(int weight,int M);
  template double weightCluster_zero<float>(float weight,int M);
  template double weightCluster_zero<double>(double weight,int M);
  template double weightCluster_zero<unsigned int>(unsigned int weight,int M);
  template double weightCluster_zero<int>(int weight,int M);
}
