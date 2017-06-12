#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    if (argv[1] == NULL) {
        fprintf(stderr, "Provide a valid file\n");
        return 2;
    }
    
    const int SIZE = 512;
    
    FILE *img = fopen(argv[1], "r");
    
    
    uint8_t buffer[SIZE];
    int counter = 0;
    
    FILE *jpg = NULL;
    
    //EOF will not be 512 bytes, Source: Walkthrough / http://docs.cs50.net/problems/recover/recover.html
    while(fread(buffer, SIZE, 1, img)) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
                if (jpg != NULL) fclose(jpg);
                
                
                char filename[8];
                sprintf(filename, "%03i.jpg", counter);
                
                jpg = fopen(filename, "w");
                counter++;
                
            }
            
        if (jpg != NULL)
            fwrite(buffer, SIZE, 1, jpg);
            
    }
    
    if (jpg != NULL) fclose(jpg);
    
    fclose(img);
    return 0; 
}