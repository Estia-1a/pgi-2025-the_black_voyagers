#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    unsigned char* data;
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
    free_image_data(data);
}

void max_component(char *filename, char* arg){

    unsigned char* data;
    int width, height, channel_count;
    char lettre = arg[0];

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
void min_component(char *filename, char* arg){

    unsigned char* data;
    int width, height, channel_count;
    char lettre = arg[0];
    

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        
        int x, y, i,min,a;
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

        min = data[a];

        for (i =0;i < height*width;i++){
            
            if ((data[i*3 + a]) < min){
                min = data[i*3 + a] ;
                y = i / width;
                x = i % width;
            }
            
        }
        printf("min_component %c (%d, %d): %d\n",lettre, x, y, min);
        free_image_data(data);
    }
}

void rotate_cw(char*filename){
    unsigned char* data;
    int w, h, n;
     read_image_data(filename, &data, &w, &h, &n);
     unsigned char* temp = malloc(w * h * n);
     memcpy(temp, data, w * h * n);
     for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int new_x = h - 1 - y;
            int new_y = x;
            for (int c = 0; c < n; c++) {
                int old_index = (y * w + x) * n + c;
                int new_index = (new_y * h + new_x) * n + c;
                data[new_index] = temp[old_index];
            }
        }
    }
    write_image_data("image_out.bmp", data, h, w);
}


void mirror_horizontal(char* filename){
    unsigned char* data;
    int width, height, channel_count;
    int R1, G1, B1;
    
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        int  i,j,  R,G,B;
        for (i =0;i < height;i++){

            for(j=0;j< width/2;j++){
            
                R = data[(i*width + j)*3];
                G = data[(i*width + j)*3+1];
                B = data[(i*width + j)*3+2];
                R1= data[(i* width + (width-1-j))*3];
                G1= data[(i* width + (width-1-j))*3+ 1];
                B1= data[(i* width + (width-1-j))*3+ 2];

                data[(i*width + j)*3] = R1;
                data[(i*width + j)*3+1]=G1;
                data[(i*width + j)*3+2]=B1;

                data[(i* width + (width-1-j))*3] = R;
                data[(i* width + (width-1-j))*3+1] = G;
                data[(i* width + (width-1-j))*3+ 2] = B;                
            }
        }
    }
    write_image_data("image_outh.bmp", data, width, height);
}

void rotate_acw(char*filename){
    unsigned char* data;
    int w, h, n;
     read_image_data(filename, &data, &w, &h, &n);
     unsigned char* temp = malloc(w * h * n);
     memcpy(temp, data, w * h * n);
     for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int new_x = y;
            int new_y = w - 1 - x;
            for (int c = 0; c < n; c++) {
                int old_index = (y * w + x) * n + c;
                int new_index = (new_y * h + new_x) * n + c;
                data[new_index] = temp[old_index];
            }
        }
    }
    write_image_data("image_out.bmp", data, h, w);
}

void mirror_vertical(char* filename){
    unsigned char* data;
    int width, height, channel_count;
    int R1, G1, B1;   

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        int  i,j,  R,G,B;
        for (i =0;i < height/2;i++){

            for(j=0;j< width;j++){
            
                R = data[(i*width + j)*3];
                G = data[(i*width + j)*3+1];
                B = data[(i*width + j)*3+2];
                R1= data[((height-1-i)*width + j)*3];
                G1= data[((height-1-i)*width + j)*3+ 1];
                B1= data[((height-1-i)*width + j)*3+ 2];

                data[(i*width + j)*3] = R1;
                data[(i*width + j)*3+1]=G1;
                data[(i*width + j)*3+2]=B1;

                data[((height-1-i)*width + j)*3] = R;
                data[((height-1-i)*width + j)*3+ 1] = G;
                data[((height-1-i)*width + j)*3+ 2] = B;              
            }
        }
    }
    write_image_data("image_outv.bmp", data, width, height);
}

void mirror_total(char* filename){
    unsigned char* data;
    int width, height, channel_count;
    int R1, G1, B1;


    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        int  i,j,  R,G,B;
        for (i =0;i < height/2;i++){

            for(j=0;j< width;j++){
            
                R = data[(i*width + j)*3];
                G = data[(i*width + j)*3+1];
                B = data[(i*width + j)*3+2];
                R1= data[((height-1-i)*width + j)*3];
                G1= data[((height-1-i)*width + j)*3+ 1];
                B1= data[((height-1-i)*width + j)*3+ 2];

                data[(i*width + j)*3] = R1;
                data[(i*width + j)*3+1]=G1;
                data[(i*width + j)*3+2]=B1;

                data[((height-1-i)*width + j)*3] = R;
                data[((height-1-i)*width + j)*3+ 1] = G;
                data[((height-1-i)*width + j)*3+ 2] = B;
            }
        }
        
        for (i =0;i < height;i++){

            for(j=0;j< width/2;j++){
            
                R = data[(i*width + j)*3];
                G = data[(i*width + j)*3+1];
                B = data[(i*width + j)*3+2];
                R1= data[(i* width + (width-1-j))*3];
                G1= data[(i* width + (width-1-j))*3+ 1];
                B1= data[(i* width + (width-1-j))*3+ 2];

                data[(i*width + j)*3] = R1;
                data[(i*width + j)*3+1]=G1;
                data[(i*width + j)*3+2]=B1;

                data[(i* width + (width-1-j))*3] = R;
                data[(i* width + (width-1-j))*3+1] = G;
                data[(i* width + (width-1-j))*3+ 2] = B;               
            }                
        }
        write_image_data("image_outt.bmp", data, width, height);
    }
}


unsigned char min3(unsigned char a, unsigned char b, unsigned char c) {
    unsigned char m = a < b ? a : b;
    return m < c ? m : c;
}

unsigned char max3(unsigned char a, unsigned char b, unsigned char c) {
    unsigned char M = a > b ? a : b;
    return M > c ? M : c;
}

void color_desaturate(char* filename){

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

            unsigned char mn = min3(r,g,b);
            unsigned char mx = max3(r,g,b);
            unsigned char new_val = (mn + mx) / 2;

            data[base + 0] = new_val;
            data[base + 1] = new_val;
            data[base + 2] = new_val;
        }

        const char *out = "image_out.bmp";
        if (write_image_data(out, data, width, height) == 0) {
            printf("Erreur écriture image : %s\n", out);
        }

        printf("Voir le document: %s\n", out);
        
        free_image_data(data);
    }
}


