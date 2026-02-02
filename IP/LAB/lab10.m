%lab10
% Make sure the image package is loaded
pkg load image

% Read the image (change filename as needed)
img = imread('dog.png');

% Convert to grayscale if it's RGB
if ndims(img) == 3
    img = rgb2gray(img);
end

% Convert image to double in range [0,1]
img = im2double(img);

% Gaussian noise parameters
mean_noise = 0;
variance = 0.01;
sigma = sqrt(variance);

% Add Gaussian noise
noisy_img = img + sigma * randn(size(img));

% Clip values to [0,1]
noisy_img = min(max(noisy_img, 0), 1);

% Display original and noisy images
figure;
subplot(1,2,1);
imshow(img);
title('Original Image');

subplot(1,2,2);
imshow(noisy_img);
title('Image with Gaussian Noise');
