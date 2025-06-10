#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"
/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char* filename){

    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        printf("dimension : %d, %d\n",width,height);
        free_image_data(data);
    }
}

void tenth_pixel (char *filename) {

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        printf("tenth_pixel : %d, %d, %d\n", data[27], data[28], data[29]);
        free_image_data(data);
    }
}


void first_pixel (char *filename) {

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        printf("first_pixel : %d, %d, %d\n", data[0], data[1], data[2]);
        free_image_data(data);
    }
}

void second_line(char *filename){

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        printf("second_line: %d, %d, %d\n", data[width*3], data[width*3+1], data[width*3+2]);
        free_image_data(data);
    }
}

void max_pixel(char *filename){

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{

        int x, y, i, max = 0, R,G,B;
        for (i =0;i < height*width;i++){
            
            if ((data[i*3] + data[i*3+1] + data[i*3+2])> max){
                max = (data[i*3] + data[i*3+1] + data[i*3+2]);
                y = i / width;
                x = i % width;
                R = data[i*3];
                G = data[i*3+1];
                B = data[i*3+2];
            }
            
        }
        printf("max_pixel (%d, %d): %d, %d, %d\n", x, y, R, G, B);
        free_image_data(data);

    }
}


void min_pixel(char *filename){

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{

        int x, y, i, R,G,B;
        int min = data[0] + data[1] + data[2];
        for (i =0;i < height*width;i++){
            
            if ((data[i*3] + data[i*3+1] + data[i*3+2])< min){
                min = (data[i*3] + data[i*3+1] + data[i*3+2]);
                y = i / width;
                x = i % width;
                R = data[i*3];
                G = data[i*3+1];
                B = data[i*3+2];
            }
            
        }
        printf("min_pixel (%d, %d): %d, %d, %d\n", x, y, R, G, B);
        free_image_data(data);

    }
}

void color_red(char* filename){

    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        int pixel_count = width * height;
        for (int i = 0; i < pixel_count; i++) {
            int base = i * channel_count;
            data[base + 1] = 0;
            data[base + 2] = 0;
        }

        const char *out = "image_out.bmp";
        if (write_image_data(out, data, width, height) == 0) {
            printf("Erreur écriture image : %s\n", out);
        }

        printf("Voir le document: %s\n", out);
        
        free_image_data(data);
    }
}

void color_green(char* filename){

    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        int pixel_count = width * height;
        for (int i = 0; i < pixel_count; i++) {
            int base = i * channel_count;
            data[base] = 0;
            data[base + 2] = 0;
        }

        const char *out = "image_out.bmp";
        if (write_image_data(out, data, width, height) == 0) {
            printf("Erreur écriture image : %s\n", out);
        }

        printf("Voir le document: %s\n", out);
        
        free_image_data(data);
    }
}

void color_blue(char* filename){

    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        int pixel_count = width * height;
        for (int i = 0; i < pixel_count; i++) {
            int base = i * channel_count;
            data[base] = 0;
            data[base + 1] = 0;
        }

        const char *out = "image_out.bmp";
        if (write_image_data(out, data, width, height) == 0) {
            printf("Erreur écriture image : %s\n", out);
        }

        printf("Voir le document: %s\n", out);
        
        free_image_data(data);
    }
}

void color_gray(char* filename){

    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        int pixel_count = width * height;
        for (int i = 0; i < pixel_count; ++i) {
            int base = i * channel_count;
            unsigned char r = data[base + 0];
            unsigned char g = data[base + 1];
            unsigned char b = data[base + 2];
            unsigned char gray = (r + g + b) / 3;
            data[base + 0] = gray;
            data[base + 1] = gray;
            data[base + 2] = gray;
        }

        const char *out = "image_out.bmp";
        if (write_image_data(out, data, width, height) == 0) {
            printf("Erreur écriture image : %s\n", out);
        }

        printf("Voir le document: %s\n", out);
        
        free_image_data(data);
    }
}

void color_invert(char* filename){

    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        int pixel_count = width * height;
        for (int i = 0; i < pixel_count; ++i) {
            int base = i * channel_count;
            data[base + 0] = 255 - data[base + 0];
            data[base + 1] = 255 - data[base + 1];
            data[base + 2] = 255 - data[base + 2];
        }

        const char *out = "image_out.bmp";
        if (write_image_data(out, data, width, height) == 0) {
            printf("Erreur écriture image : %s\n", out);
        }

        printf("Voir le document: %s\n", out);
        
        free_image_data(data);
    }
}
void color_gray_luminance(char *filename){
    unsigned char* data = NULL;
    int w, h, n, x, y;
    read_image_data(filename, &data, &w, &h, &n);
    for(y=0; y<h; y++){
        for(x=0; x<w; x++){      
            pixelRGB * pixel = get_pixel(data, w, h, n, x, y);
            unsigned char value = 0.21 * pixel->R + 0.72 * pixel->G + 0.07 * pixel->B;
            pixel->R=value;
            pixel->G=value;
            pixel->B=value;
        }
    }
    write_image_data("image_out.bmp", data, w, h);
}

void max_component(char *filename, char* arg){

    unsigned char* data;
    int width, height, channel_count;
    char lettre = arg[0];
    //int value = atoi(argv[5]);

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        
        int x, y, i,max,a;
        if(lettre == 'R' || lettre == 'r'){
            a =0;
        }
        else if(lettre =='G' || lettre == 'g'){
            a = 1;
        }
        else if(lettre =='B' || lettre == 'b'){
            a = 2;
        }

        else{
            printf("Erreur : la composante n'est pas valide");
        }

        max = data[a];

        for (i =0;i < height*width;i++){
            
            if ((data[i*3 + a]) > max){
                max = data[i*3 + a] ;
                y = i / width;
                x = i % width;
            }
            
        }
        printf("max_component %c (%d, %d): %d\n",lettre, x, y, max);
        free_image_data(data);

    }
}