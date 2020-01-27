#include<stdio.h>
#include<stdlib.h>

typedef enum _State {
    S_START,
    S_DIGIT,
    S_INVALID,
    S_VALID
} State;

#define S_END S_VALID

State dfa(State s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(*input == '+' || *input=='-' && s==S_START) return dfa(S_DIGIT, input+1);
    else if(*input >='0' && *input<='9' && s==S_START) return dfa(S_END, input+1);
    else if(*input >='0' && *input<='9' && s==S_DIGIT) return dfa(S_END, input+1);
    else if(*input >='0' && *input<='9' && s==S_VALID) return dfa(S_END, input+1);
    else return S_INVALID;
}

int main(){
    char ch[1024];

    printf("Enter string : ");
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    State s = dfa(S_START, buffer);

    printf("The given string %s\n", s == S_END ? "is an integer\n" : "is not an integer\n");

    return 0;
}