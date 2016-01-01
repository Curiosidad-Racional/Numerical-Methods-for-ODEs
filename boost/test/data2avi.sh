#!/bin/bash
HEAD=test
if [ ! -z $1 ]
then
    HEAD="$1"
fi
N=$(ls -1 "$HEAD"*.dat | wc -l)
LIMITS=$(cat "$HEAD"*.dat | awk -f "${HEAD%/*}/maxmin2-4.awk")
echo "
set terminal pngcairo size 1024,768 enhanced font 'Verdana,10'
$LIMITS
do for [t=1:$N] {
  outfile = sprintf(\"$HEAD%04.0f.png\",t)
  ftitle = sprintf('b = %02.2f', 15. + (25.-15.)/($N.-1.)*(t-1.))
  set output outfile
  splot \"$HEAD\".t.\".dat\" using 2:3:4 with lines linecolor rgb 'blue' title ftitle
}
" | gnuplot
if [ $? == 0 ]
then
    avconv -y -r 15 -i "$HEAD"%04d.png -b:v libx264 -r 15 -b 3000k -crf 18 -s 1024x768 "$HEAD.mp4"
else
    echo "There were errors"
fi
