#include <estia-image.h>

#include "utils.h"
#include <stddef.h>
#include <stdio.h>

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB * get_pixel( unsigned char* data, 
                    const unsigned int width, 
                    const unsigned int height, 
                    const unsigned int n, 
                    const unsigned int x, 
                    const unsigned int y )

{
    if (data==NULL) {
        return NULL;
    }

    else if (x >= width || y >= height) {
        return NULL;
    }

    unsigned int idx = (y * width + x) * n;
    return (pixelRGB*)&data[idx];
}


void print_pixel(char *filename, int x, int y) {

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        pixelRGB *p = get_pixel(data, width, height, channel_count, x, y);

    
        if (p == NULL) {
            printf("Coordonnées (%d,%d) hors image de taille %dx%d\n", x, y, width, height);
        }
    
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, p->R, p->G, p->B);
        
        free_image_data(data);
    }
}
