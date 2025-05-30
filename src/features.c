#include <estia-image.h>
#include <stdio.h>

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
