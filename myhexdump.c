#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        if(argc != 2){
            fprintf(stderr, "Usage: ./myhexdump <filename.fileextension>\n");
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
        // size_t num_bytes_in_line = 0;
        while((byte = fgetc(fp)) != EOF){
              printf("%08zX\t0x%02X\n", offset, byte);
              offset++;
        }

        fclose(fp);
        return EXIT_SUCCESS;
}
