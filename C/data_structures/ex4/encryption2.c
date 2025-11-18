/*------------------------------------------------------
* Filename: [encryption2.c]
* Description: [encryptes]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN (128)

int compute_ascii_avg(char*password){
    double ascii_avg=0;
    int i =0;
    while(password[i]!='\0'){
        ascii_avg+=(int)password[i++];
    }
    ascii_avg/=strlen(password);
    ascii_avg=(int)ascii_avg;
}


void encrypt(char*sentence, char*password, char*encrypted_sentence){
    char safe[]="safe";
    int ascii_avg=compute_ascii_avg(password);
    int i=0;
    strcat(sentence,safe);
    while(sentence[i]!='\0'){
        encrypted_sentence[i]=sentence[i]+ascii_avg;
        i++;
    }
    printf("your data is safe");
}

// returns true if password is correct
int decrypt(char*password, char*encrypted_sentence){
    char safe[]="safe";
    char tmp[MAX_LEN];
    strcpy(tmp,encrypted_sentence); //to not corrupt for next iterations if password is bad
    int ascii_avg=compute_ascii_avg(password);
    int i=0;
    while(tmp[i]!='\0'){
        tmp[i++]-=ascii_avg;
    }
    int safe_idx=strlen(tmp)-4;
    if(strcmp(tmp+safe_idx, safe)){ //-4 to take in account for length of safe
        printf("wrong password");
        return 0;
    }
    tmp[safe_idx]='\0';
    printf("%s",tmp);
    return 1;
}


int main() {
    
    char sentence[MAX_LEN],password[MAX_LEN+4],tmp[MAX_LEN+4],encrypted_sentence[MAX_LEN]; //extra 4 for SAFE
    // i initilized
    int password_correct=0;
    printf("give me the sentence max %d chars", MAX_LEN);
    scanf("%s",sentence);
    printf("give me the password max %d chars", MAX_LEN);
    scanf("%s",password);
    printf("give me the password to verify");
    scanf("%s",tmp);
    if(strcmp(password,tmp)){ // i would rather implement my own strcmp to prevent TIMING ATTACKS
        printf("passwords dont match!");
        return 1;
    }

    // in real life id also encrypt the password using bycrypt
    encrypt(sentence,password,encrypted_sentence); 
    
    while(!password_correct){
        printf("give me your password to decrypt!");
        scanf("%s",tmp);
        decrypt(password,encrypted_sentence); 
    }

    return 0;
}