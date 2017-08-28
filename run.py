import os


print "First partition and run"

os.system("nohup sh ./examples/INQ/alexnet/train_alexnet.sh >run1_log.out 2>&1")

print "Second partition and run"

os.system("sed -i \"s/(count_\*0.7)/(count_\*0.4)/g\" ./src/caffe/blob.cpp")
os.system("make all -j128")

os.system("sed -i \"s/original.caffemodel/alexnet_part1_iter_63000.caffemodel/g\" ./examples/INQ/alexnet/train_alexnet.sh")
os.system("sed -i \"s/part1/part2/g\" ./examples/INQ/alexnet/solver.prototxt")
os.system("nohup sh ./examples/INQ/alexnet/train_alexnet.sh >run2_log.out 2>&1")

print "Thrid partition and run"

os.system("sed -i \"s/(count_\*0.4)/(count_\*0.2)/g\" ./src/caffe/blob.cpp")
os.system("make all -j128")

os.system("sed -i \"s/alexnet_part1_iter_63000.caffemodel/alexnet_part2_iter_63000.caffemodel/g\" ./examples/INQ/alexnet/train_alexnet.sh")
os.system("sed -i \"s/part2/part3/g\" ./examples/INQ/alexnet/solver.prototxt")
os.system("nohup sh ./examples/INQ/alexnet/train_alexnet.sh >run3_log.out 2>&1")


print "Last partition and run"

os.system("sed -i \"s/(count_\*0.2)/(count_\*0.)/g\" ./src/caffe/blob.cpp")
os.system("make all -j128")
os.system("sed -i \"s/alexnet_part2_iter_63000.caffemodel/alexnet_part3_iter_63000.caffemodel/g\" ./examples/INQ/alexnet/train_alexnet.sh")
os.system("sed -i \"s/part3/part4/g\" ./examples/INQ/alexnet/solver.prototxt")
os.system("sed -i \"s/snapshot: 3000/snapshot: 1/g\" ./examples/INQ/alexnet/solver.prototxt")
os.system("sed -i \"s/max_iter: 63000/max_iter: 1/g\" ./examples/INQ/alexnet/solver.prototxt")
os.system("nohup sh ./examples/INQ/alexnet/train_alexnet.sh >run4_log.out 2>&1")

print "All quantization done and you can enjoy the power-of-two weights using check.py!"
