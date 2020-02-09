#include<stdio.h>
#include<stdlib.h>

typedef enum _State {
    S_START,
    S_lt,
    S_gt,
    S_lte,
    S_gte,
    S_e,
    S_ee,
    S_nt,
    S_INVALID
} State_ab;

#define S_END S_B

void print_state(State_ab s){
    switch(s){
        case S_INVALID: printf("State : Invalid , Not a relational operator\n"); break;
        case S_lt: printf("State : S_lt\n"); break;
        case S_gt: printf("State : S_gt\n"); break;
        case S_lte: printf("State : S_lte\n"); break;
        case S_gte: printf("State : S_gte\n"); break;
        case S_e: printf("State : S_e , Not a relational operator\n"); break;
        case S_ee: printf("State : S_ee\n"); break;
        case S_nt: printf("State : S_nt\n"); break;
    }
}

// a*b
State_ab dfa(State_ab s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(*input == '<' && s==S_START) return dfa(S_lt, input+1);
    else if(*input == '>' && s==S_START) return dfa(S_gt, input+1);
    else if(*input == '>' && s==S_lt) return dfa(S_nt, input+1);
    else if(*input == '=' && s==S_START) return dfa(S_e, input+1);
    else if(*input == '=' && s==S_e) return dfa(S_ee, input+1);
    else if(*input == '=' && s==S_lt) return dfa(S_lte, input+1);
    else if(*input == '=' && s==S_gt) return dfa(S_gte, input+1);
    else return S_INVALID;
}


int main(int argc, char *argv[]) {
    char ch[1024];

    printf("Enter string : ");
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);

    //ab
    State_ab s = dfa(S_START, buffer);
    print_state(s);

    return EXIT_SUCCESS;
}