/*------------------------------------------------------
* Filename: [file_ops.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_SIZE (255)
// i think this is the NTFS standard

FILE* open_txt_file(char*fname, char*mode){
    char txt_str[]=".txt";
    char c;
    strcat(fname, txt_str);
    FILE * fp = fopen(fname,mode);
    if(fp==NULL){
        fprintf(stderr,"file error");
        return NULL;
    }
    return fp;
}

// A: get a txt file and print its content
void print_file(char* fname){
    FILE * fp = open_txt_file(fname, "r");
    char c;
    while((c=fgetc(fp))!=EOF){
        printf("%c",c);
    }
    fclose(fp);
}

// B: copy data
void copy_file(char*name_src, char* name_dest){
    FILE * fp_src = open_txt_file(name_src, "r");
    FILE * fp_dest = open_txt_file(name_dest, "w");
    if(fp_src==NULL)
        return;
    if(fp_dest==NULL){
        // suppose it doesnt exist
        fp_dest = open_txt_file(name_dest, "w");
        if(fp_dest==NULL){
            fprintf(stderr,"Dest file cannot be created and doesnt exist");
            return;
        }
    }
    char c;
    while((c=fgetc(fp_src))!=EOF){
        fprintf(fp_dest,"%c",c);
    }
    fclose(fp_src);
    fclose(fp_dest);
}

// i was told to count alphabet letters not any character
bool is_alpha(char c){
    return (c>='a' && c<='z' || c>='A' && c<='Z');
}

//C: print files stats:
// including num of lines, num of words, num of characters
void print_stats(char* fname){
    int line_count=1, word_count=1, char_count=0;
    FILE * fp = open_txt_file(fname, "r");
    char c;
    if((c=fgetc(fp))==EOF){ // empty file edge case. (becaues we rely on \n for line counting we have to distinguish between the case of empty file)
        line_count=0;
        word_count=0;
    }
    while(c!=EOF){
        if(is_alpha(c))
            char_count++;
        switch (c){
            case '\n':
                line_count++;
                break;
            case ' ':
                word_count++;
                break;
        }
        c=fgetc(fp);
    }
    fclose(fp);
    printf("Number of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of chars: %d\n", char_count);
}

// D: delete line in file
void delete_line(char* fname, int line_num){
    char tmp_fname[MAX_FILE_NAME_SIZE];
    strcpy(tmp_fname, fname);
    strcat(tmp_fname, "_tmp");
    FILE * fp = open_txt_file(fname, "r");
    FILE * tmp_fp = open_txt_file(tmp_fname, "w"); 

    int line_count=1;
    char c;
    while((c=fgetc(fp))!=EOF){
        if(line_count!=line_num){ // delete the target line
            fputc(c,tmp_fp);
        }
        if(c=='\n')
            line_count++;
    }
    fclose(fp); 
    remove(fname);
    fclose(tmp_fp);
    rename(tmp_fname,fname);
}

// E: number of times a string exists in a file
int count_word(char* fname, char*word){
    FILE * fp = open_txt_file(fname, "r");
    char count=0;
    char match_idx=0;
    int word_len=strlen(word);
    char c;
    while((c=fgetc(fp))!=EOF){
        if(c==word[match_idx]){
            match_idx++;

            if (match_idx==word_len){
                count++;
                match_idx=0;
            }
        }
        else{
            if (match_idx > 0) {
                fseek(fp, -match_idx, SEEK_CUR);//go back 
                match_idx=0;
            }
        }
    }
    fclose(fp);
    return count;
}

int main() {
    char name_src[MAX_FILE_NAME_SIZE]="src";
    printf("%d", count_word(name_src, "ab"));
    return 0;
}