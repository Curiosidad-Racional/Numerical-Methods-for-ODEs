NR == 1 {
    xmax=$2; xmin=$2;
    ymax=$3; ymin=$3;
    zmax=$4; zmin=$4;
}
NR > 1 {
    if ($2 > xmax) { xmax = $2 };
    if ($2 < xmin) { xmin = $2 };

    if ($3 > ymax) ymax = $3;
    if ($3 < ymin) ymin = $3;

    if ($4 > zmax) zmax = $4;
    if ($4 < zmin) zmin = $4;
}
END{
    printf "set xrange [%f:%f]\n", xmin, xmax;
    printf "set yrange [%f:%f]\n", ymin, ymax;
    printf "set zrange [%f:%f]\n", zmin, zmax;
}
