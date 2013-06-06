# set output
set term png
set output "plot.png"

# style the lines so they can be read more easily
set style line 1 lc rgb '#8b1a0e' pt 1 ps 1 lt 1 lw 1
set style line 2 lc rgb '#5e9c36' pt 2 ps 1 lt 1 lw 1
set style line 3 lc rgb '#268bd2' pt 3 ps 1 lt 1 lw 1
set style line 4 lc rgb '#000000' pt 4 ps 1 lt 1 lw 1

# set grid style
set style line 11 lc rgb '#808080' lt 1
set border 3 back ls 11
set tics nomirror

# display a slight grid
set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12

# set axis names
set ylabel "[ms]"
set xlabel "Eingabegröße n"

plot "messungen.data" using 1:2 with line ls 1 title 'C-time',\
     "messungen.data" using 1:3 with line ls 2 title 'C-clock()',\
     "messungen.data" using 1:4 with line ls 3 title 'Java-time',\
     "messungen.data" using 1:5 with line ls 4 title 'Java-nanoTime()'

# vim: syntax=gnuplot
