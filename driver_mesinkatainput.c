#include <stdio.h>
#include "mesinkatainput.c"

int main(){
    STARTKATA();
    printf("%d",convertToInteger(CKata));
    inputCommand();
    printf("%d",check);
    return 0;
}