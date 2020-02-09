#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef enum _State {
    S_START,
    S_INVALID,
    S_VALID
} State;

#define S_END S_VALID

bool isDigit(char *input){
    if(*input >='0' && *input<='9') return true;
    return false;
}

bool isChar(char *input){
    if(*input>='A' && *input<='z' || *input=='_') return true;
    return false;
}

State dfa(State s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(isChar(input) && s==S_START) return dfa(S_VALID, input+1);
    else if(isDigit(input) && s==S_VALID) return dfa(S_VALID, input+1);
    else if(isChar(input) && s==S_VALID) return dfa(S_VALID, input+1);
    else return S_INVALID;
}

int main(){
    // char ch[1024];

    printf("Enter string : ");
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    State s = dfa(S_START, buffer);
    printf("The given string %s\n", s == S_END ? "is valid\n" : "is not valid\n");

    return 0;
}