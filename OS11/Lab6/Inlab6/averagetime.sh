#!/bin/bash

cat words.txt 3x3.grid.txt

RUNNING_TIME1=`./a.out | tail -1`
RUNNING_TIME2=`./a.out | tail -1`
RUNNING_TIME3=`./a.out | tail -1`
RUNNING_TIME4=`./a.out | tail -1`
RUNNING_TIME5=`./a.out | tail -1`
AVERAGE=`(RUNNING_TIME1+RUNNING_TIME2+RUNNING_TIME3+RUNNING_TIME4+RUNNING_TIME5)/5`

echo ${AVERAGE}
