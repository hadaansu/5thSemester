clear all;   % clear all variables
close all;  % close all figures
clc;        % clear command window

% import image package
pkg load image;

% read image
% Median Filters
I = imread('hatori.jpg');
K = rgb2gray(I);

J = imnoise(K, 'salt & pepper', 0.05);

f  = medfilt2(J, [3,3]);
f1 = medfilt2(J, [10,10]);

subplot(3,2,1); imshow(I);  title('Original Image');
subplot(3,2,2); imshow(K);  title('Gray Image');
subplot(3,2,3); imshow(J);  title('Noise added Image');
subplot(3,2,4); imshow(f);  title('3x3 Image');
subplot(3,2,5); imshow(f1); title('10x10 Image');

