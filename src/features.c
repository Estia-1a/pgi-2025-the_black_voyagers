#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

        int x, y, i, max = -1 , R,G,B;
        y = 0;
        x = 0;
      

        for (i =0;i <= height*width;i++){
                        
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
        int min = 255 * 3 + 1;
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

        max = -1;

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

        min = 256;

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
    write_image_data("image_out.bmp", data, width, height);
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
    write_image_data("image_out.bmp", data, width, height);
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
        write_image_data("image_out.bmp", data, width, height);
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

void scale_nearest(char *filename, char* arg) {
    unsigned char* data;
    int width, height, channel_count;
    float scale_factor = atof(arg); 
    
    
    if (scale_factor <= 0) {
        printf("Erreur : facteur d'échelle doit être > 0\n");
        return;
    }
    
    
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }
    
    
    int new_width = (int)(scale_factor * width);
    int new_height = (int)(scale_factor * height);
    
    unsigned char* new_data = (unsigned char*)malloc(new_width * new_height * channel_count * sizeof(unsigned char));
    
  
    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {

            int orig_x = (int)((float)j / scale_factor);
            int orig_y = (int)((float)i / scale_factor);
            
            int new_index = (i * new_width + j) * channel_count;
            int orig_index = (orig_y * width + orig_x) * channel_count;
            
            for (int c = 0; c < channel_count; c++) {
                new_data[new_index + c] = data[orig_index + c];
            }
        }
    }
        
       
        const char *out = "image_out.bmp";
        if (write_image_data(out, new_data, new_width, new_height) == 0) {
            printf("Erreur écriture image : %s\n", out);
        }

        printf("Voir le document: %s\n", out);
        
        free_image_data(data);
       
}

void scale_bilinear(char *filename, char* arg) {
    unsigned char* data;
    int width, height, channel_count;
    float scale_factor = atof(arg); 
    
    
    if (scale_factor <= 0) {
        printf("Erreur : facteur d'échelle doit être > 0\n");
        return;
    }
    
    
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
        return;
    }
    
    
    int new_width = (int)(scale_factor * width);
    int new_height = (int)(scale_factor * height);
    
    unsigned char* new_data = (unsigned char*)malloc(new_width * new_height * channel_count * sizeof(unsigned char));
    
  
    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {

            float src_x = j / scale_factor;
            float src_y = i / scale_factor;

            int x1 = (int)floorf(src_x);
            int y1 = (int)floorf(src_y);
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            float dx = src_x - x1;
            float dy = src_y - y1;

            if (x1 < 0) x1 = 0;
            if (y1 < 0) y1 = 0;
            if (x2 >= width)  x2 = width - 1;
            if (y2 >= height) y2 = height - 1;

            int new_index  = (i * new_width  + j) * channel_count;
            int base11 = (y1 * width + x1) * channel_count;
            int base12 = (y1 * width + x2) * channel_count;
            int base21 = (y2 * width + x1) * channel_count;
            int base22 = (y2 * width + x2) * channel_count;

            for (int c = 0; c < channel_count; c++) {
                float Q11 = data[base11 + c];
                float Q12 = data[base12 + c];
                float Q21 = data[base21 + c];
                float Q22 = data[base22 + c];

                float val = Q11 * (1 - dx) * (1 - dy) + Q12 * dx * (1 - dy) + Q21 * (1 - dx) * dy + Q22 * dx * dy;

                if (val < 0) val = 0;
                else if (val > 255) val = 255;
                new_data[new_index + c] = (unsigned char)(val + 0.5f);
            }
        }
    }
        
       
        const char *out = "image_out.bmp";
        if (write_image_data(out, new_data, new_width, new_height) == 0) {
            printf("Erreur écriture image : %s\n", out);
        }

        printf("Voir le document: %s\n", out);
        
        free_image_data(data);
       
}
 

void scale_crop(char *source_path, int center_x, int center_y, int width, int height){
    unsigned char* data = NULL;
    int original_width, original_height, n, x, y;
    read_image_data(source_path, &data, &original_width, &original_height, &n);
    
    int first_x = center_x - width/2;
    int first_y = center_y - height/2;
    
    if (first_x < 0) {
        width = width + first_x; 
        first_x = 0;
    }
    if (first_y < 0) {
        height = height + first_y; 
        first_y = 0;
    }
    if (first_x + width > original_width) {
        width = original_width - first_x;
    }
    if (first_y + height > original_height) {
        height = original_height - first_y;
    }
    
    unsigned char* cropped_data = malloc(width * height * n);
    
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            pixelRGB* pixel_original = get_pixel(data, original_width, original_height, n, x + first_x, y + first_y);
            pixelRGB* pixel_crop = get_pixel(cropped_data, width, height, n, x, y);
            pixel_crop->R = pixel_original->R;
            pixel_crop->G = pixel_original->G;
            pixel_crop->B = pixel_original->B;
        }
    }
    
    write_image_data("image_out.bmp", cropped_data, width, height);
}