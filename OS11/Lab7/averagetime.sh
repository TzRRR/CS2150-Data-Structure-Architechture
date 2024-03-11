#Tianze Ren, tr2bx, 10/25/2022, averagetime.sh
#!/bin/bash

echo 'enter the exponent for counter.cpp:'
read number
i=1
if [[ "$number" == 'quit' ]]; then
    exit 0
else
    while [[ $i -lt 6 ]]; do
	time=`./a.out $number| tail -1`
	echo 'Running iteration '${i}' ...'
	echo 'time taken: '${time}' ms'
	TOTAL_TIME=$((TOTAL_TIME+time))
	let i=i+1
    done
fi

AVERAGE=$((TOTAL_TIME/5))

echo '5 iterations took' ${TOTAL_TIME} 'ms'
echo 'Average time was' ${AVERAGE} 'ms'
