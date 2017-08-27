#ifndef CAFFE_UTIL_POWER2_H_
#define CAFFE_UTIL_POWER2_H_


#include "caffe/common.hpp"
#include "caffe/util/math_functions.hpp"

namespace caffe
{

template <typename Dtype>
void feature2power_gpu(Dtype* features,const int num);

template <typename Dtype>
double featureCluster(Dtype feature,const int n_max);

template <typename Dtype>
double weightCluster(Dtype weight,int M);

template <typename  Dtype>
double weightCluster_zero(Dtype weight,int M);
}
#endif
