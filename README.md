# Incremental-Network-Quantization
Caffe Implementation for Incremental network quantization, we modify the original caffe, the Installation is follow [caffe](http://caffe.berkeleyvision.org/install_apt.html).

the default source code is 5 bits weights-only quantization, you can by changing parameter "partition"(/src/caffe/blob.cpp) to control the quantization step. 

# INQ usage

0.you must be farmilar with caffe training [imagenet tutorial](http://caffe.berkeleyvision.org/gathered/examples/imagenet.html)

1.Train 5 bits Alexnet with Imagenet:

	python run.py

[BaiduYun](https://pan.baidu.com/s/1qYHkbus)

2. Each partition step output log correspond respectively run1_log.out, run2_log.out, run3_log.out, run4_log.out.

### Citing INQ

If you find INQ useful in your research, please consider citing:

	@inproceedings{zhou2017,
	title={Incremental Network Quantization: Towards Lossless CNNs with Low-Precision Weights},
	author={Aojun Zhou, Anbang Yao, Yiwen Guo, Lin Xu, Yurong Chen},
	booktitle={International Conference on Learning Representations,ICLR2017},
	year={2017},
	}
	

## Tips:

1. Real-time data shuffling is useful



usage come soon....
