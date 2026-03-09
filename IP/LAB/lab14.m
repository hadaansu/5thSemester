clc;
clear;
close all;

img = imread('cap.png');

if size(img,3) == 3
    img = rgb2gray(img);
end

img = im2double(img);

sigma = 0.1;
U = rand(size(img));
rayleigh_noise = sigma * sqrt(-2 * log(1-U));

noisy_img = img + rayleigh_noise;

noisy_img(noisy_img < 0) = 0;
noisy_img(noisy_img > 1) = 1;

figure;
subplot(1,2,1);
imshow(img);
title('Original Image');

subplot(1,2,2);
imshow(noisy_img);
title('Rayleigh Noise');

imwrite(noisy_img,'rayleigh_noise.png');