clc;
clear;
close all;

% Read image
img = imread('imagleo.png');

% Convert to grayscale if RGB
if size(img,3) == 3
    img = rgb2gray(img);
end

% Convert to double
img = im2double(img);

% Approximate Poisson noise
noise = sqrt(img) .* randn(size(img));
noisy_img = img + noise;

% Keep values between 0 and 1
noisy_img(noisy_img < 0) = 0;
noisy_img(noisy_img > 1) = 1;

% Display images
figure;

subplot(1,2,1);
imshow(img);
title('Original Image');

subplot(1,2,2);
imshow(noisy_img);
title('Poisson Noise Image');

% Save output
imwrite(noisy_img,'poisson_noise_output.png');