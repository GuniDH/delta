/*------------------------------------------------------
* Filename: [file_ops.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get a txt file and print its content
void print_file(FILE *fp){
    char c;
    while((c=fgetc(fp))!=EOF){
        printf("%c",c);
    }
}

// copy data
void copy_file(char name_src[], char name_dest[]){
    printf("451");
    char txt_str[]=".txt";
    strcat(name_src, txt_str);
    strcat(name_dest, txt_str);
    printf("452");
    FILE * fp_src = fopen(name_src,"r");
    if(fp_src==NULL){
        fprintf(stderr,"Source file cannot be opened");
        return;
    }
    FILE * fp_dest = fopen(name_dest,"w");
    if(fp_dest==NULL){
        // suppose it doesnt exist
        fp_dest = fopen(name_dest,"r");
        if (fp_dest == NULL){
            fprintf(stderr,"Dest file cannot be created");
            return;
        }
    }
    printf("454");
    char c;
    while((c=fgetc(fp_src))!=EOF){
        fprintf(fp_dest,"%c",c);
    }

    fclose(fp_src);
    fclose(fp_dest);
}

int main() {
    copy_file("test","dest");
    return 0;
}