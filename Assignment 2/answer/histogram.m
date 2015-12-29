close all, clear all, clc

font_size = 16;
font_type = 'Helvetica';
histogram=importdata('task3.dat');
bar(histogram.data(:,1),histogram.data(:,2));
t=title('Title');
x_l=xlabel('Intensity');
y_l=ylabel('Count');
set(gca, 'FontSize', font_size, 'FontName', font_type)
set(t, 'FontSize', font_size, 'FontName', font_type)
set(x_l, 'FontSize', font_size, 'FontName', font_type)
set(y_l, 'FontSize', font_size, 'FontName', font_type)
print -depsc2 histogram_matlab.eps
print -dpng histogram_matlab.png