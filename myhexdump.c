#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        if(argc != 2){
            fprintf(stderr, "Usage: ./myhexdump <filename>\n");
            return EXIT_FAILURE;
        }

        FILE *fp = fopen(argv[1], "rb");
        if(!fp){
            perror(argv[1]);
            return EXIT_FAILURE;
        }

        int byte; // int allows EOF(macro for -1) usage
        printf("offset\t\tbyte\n");
        size_t offset = 0;
        size_t num_bytes_in_line = 0;
        
        printf("%08zX\t", offset); // Print initial offset
        while((byte = fgetc(fp)) != EOF){
            printf("0x%02X ", byte);
            ++num_bytes_in_line;
            ++offset; // Next byte's offset
            if(num_bytes_in_line % 16 == 0){
                printf("\n"); // Break into rows
                printf("%08zX\t", offset); // Position of next byte
            }
        }

        if(num_bytes_in_line % 16 != 0){
            printf("\n");
        }

        fclose(fp);
        return EXIT_SUCCESS;
}
