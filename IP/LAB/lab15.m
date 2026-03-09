clc;
clear;
close all;

% Read image
img = imread('buu.jpg');

% Convert to grayscale if RGB
if size(img,3)==3
    img = rgb2gray(img);
end

% Convert to double
img = im2double(img);

% Roberts operator masks
Gx = [1 0; 0 -1];
Gy = [0 1; -1 0];

% Apply convolution
edge_x = conv2(img, Gx, 'same');
edge_y = conv2(img, Gy, 'same');

% Edge magnitude
edge_img = sqrt(edge_x.^2 + edge_y.^2);

% Display images
figure;

subplot(1,2,1);
imshow(img);
title('Original Image');

subplot(1,2,2);
imshow(edge_img);
title('Roberts Edge Detection');

% Save output
imwrite(edge_img,'roberts_edge_output.png');