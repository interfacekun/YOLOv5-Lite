#!/bin/bash
#YOLO_PATH=/Volumes/outDisk/git/IoT/YOLOv5-Lite

HOST=`whoami`
if [ "$HOST" == "interface" ]
then
    echo "[interface]"
    YOLO_PATH=/Volumes/outDisk/git/IoT/YOLOv5-Lite
elif [ "$HOST" == "xmk" ]
then
    echo "[xmk]"
    YOLO_PATH=/Users/${HOST}/git/IoT/YOLOv5-Lite
else
    echo "[pi]"
fi


./ncnnv5lite $YOLO_PATH/cpp_demo/ncnn/images/horse.jpg