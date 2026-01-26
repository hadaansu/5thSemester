clear all;  % clear all variables
close all;  % close all figures
clc;        % clear command window
% import image package
pkg load image;

% read image for Image Enhancement
I = imread('dora.jfif');
subplot(4,2,1); imshow(I); title('Original Image');

g = rgb2gray(I);
subplot(4,2,5); imshow(g); title('Gray Image');

J = imadjust(g,[0.3 0.7],[]);
subplot(4,2,3); imshow(J); title('Enhanced Image');

D = imadjust(I,[0.2 0.3 0;  0.6 0.7 1],[]);
subplot(4,2,4); imshow(D); title('Enhanced Image 2');

% Histogram and Histogram Equalization
subplot(4,2,7); imhist(g); title('Histogram of Gray Image');

m = histeq(g);
subplot(4,2,6); imshow(m); title('Equalized Image');

subplot(4,2,8); imhist(m); title('Histogram of Equalized Image');

