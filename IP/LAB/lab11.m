%lab11
% Load image package
pkg load image

% Read the image (change filename as needed)
img = imread('panda.jpg');

% Convert to grayscale if RGB
if ndims(img) == 3
    img = rgb2gray(img);
end

% Convert image to double in range [0,1]
img = im2double(img);

% Salt & pepper noise density (0 to 1)
noise_density = 0.05;   % 5% of pixels corrupted

% Add salt & pepper noise
noisy_img = imnoise(img, 'salt & pepper', noise_density);

% Display original and noisy images
figure;
subplot(1,2,1);
imshow(img);
title('Original Image');

subplot(1,2,2);
imshow(noisy_img);
title('Image with Salt & Pepper Noise');
