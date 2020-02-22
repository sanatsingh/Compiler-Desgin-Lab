#include<stdio.h>
#include<stdlib.h>

typedef enum _State {
    S_START,
    S_A,
    S_B,
    S_INVALID
} State_ab;

#define S_END S_B

void print_state(State_ab s){
    switch(s){
        case S_INVALID: printf("State : Invalid\n"); break;
        case S_A: printf("State : S_A\n"); break;
        case S_B: printf("State : S_B\n"); break;
    }
}

// a*b
State_ab dfa(State_ab s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(*input == 'a' && s==S_START) return dfa(S_A, input+1);
    else if(*input == 'a' && s==S_A) return dfa(S_A, input+1);
    else if(*input == 'b' && s==S_A) return dfa(S_END, input+1);
    else if(*input == 'b' && s==S_START) return dfa(S_END, input+1);
    else return S_INVALID;
}

// ab*
State_ab dfa_2(State_ab s, char *input) {
    if(*input == '\0' || *input == '\n') return s;
    if(*input == 'a' && s==S_START) return dfa_2(S_B, input+1);
    else if(*input == 'b' && s==S_B) return dfa_2(S_B, input+1);
    else return S_INVALID;
}

// a*b*
State_ab dfa_3(State_ab s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(*input == 'a' && s==S_START) return dfa_3(S_A, input+1);
    else if(*input == 'a' && s==S_A) return dfa_3(S_A, input+1);
    else if(*input == 'b' && s==S_A) return dfa_3(S_B, input+1);
    else if(*input == 'b' && s==S_B) return dfa_3(S_B, input+1);
    else if(*input == 'b' && s==S_START) return dfa_3(S_B, input+1);
    else return S_INVALID;
}

int main(int argc, char *argv[]) {
    char ch[1024];

    printf("Enter string : ");
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    //ab
    State_ab s = dfa(S_START, buffer);
    
    printf("The given string %s\n", s == S_B ? "matches re a*b\n" : "does not match\n");
    print_state(s);

    s = dfa_2(S_START, buffer);
    
    printf("The given string %s\n", s == S_B ? "matches re ab*\n" : "does not match\n");
    print_state(s);

    s = dfa_3(S_START, buffer);
    
    printf("The given string %s\n", s == S_B ? "matches re a*b*\n" : "does not match\n");
    print_state(s);

    return EXIT_SUCCESS;
}