set term gif animate
set yrange [0:1]
set output 'output/O.gif'
do for [i=1:30]{
plot 'output/kni_P.txt' u i w lines t 'kni','output/kr_P.txt' u i w lines t 'kr','output/gt_P.txt' u i w lines t 'gt','output/hb_P.txt' u i w lines t 'hb' 
set title sprintf("%d",i)
}

