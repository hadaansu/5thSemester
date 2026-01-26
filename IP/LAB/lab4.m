pkg load image;
a=imread('jelly.png');
 subplot(2,2,1);
imshow(a);
 title 'original image';
 b=im2double(a);
 a1= input('enter value a');
enter value a 10
 ga1=input('enter value gamma');
enter value gamma 9
 s=(a1*(b.^ga1))*256;
 s1=uint8(s);
 subplot(2,2,2);
 imshow(s1);
 title 'image 1';
 a2= input('enter value a');
enter value a 5
 ga2=input('enter value gamma');
enter value gamma 7
 sp=(a2*(b.^ga2))*256;
 s2=uint8(sp);
 subplot(2,2,3);
 imshow(s2);
 title 'image 2';
 a3= input('enter value a');
enter value a8
 ga3=input('enter value gamma');
enter value gamma9
 sp2=(a3*(b.^ga3))*256;
 sp3=uint8(sp2);
 subplot(2,2,4);
 imshow(s3);
 title 'image 3';

