clc;
clear;
close all;

img = imread('dogg.png');

if size(img,3) == 3
    img = rgb2gray(img);
end

img = im2double(img);

noise = randn(size(img));
noisy_img = img + img .* noise;

noisy_img(noisy_img < 0) = 0;
noisy_img(noisy_img > 1) = 1;

figure;
subplot(1,2,1);
imshow(img);
title('Original Image');

subplot(1,2,2);
imshow(noisy_img);
title('Speckle Noise');

imwrite(noisy_img,'speckle_noise.png');