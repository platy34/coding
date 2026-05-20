#include <stdio.h>


int main(){

    FILE *pFile = fopen("c:\\Users\\User\\Desktop\\output.txt", "w");

    char text[] = "BOOTY BOOTY BOOTY\nROCKIN' EVERYWHERE!";

    if (pFile == NULL){
        printf("Error opening file\n");
        return 1;
    }

    fprintf(pFile, "%s", text);

    printf("File was written successfully!\n");

    fclose(pFile);

    return 0;
}