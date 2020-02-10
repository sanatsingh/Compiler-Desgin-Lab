#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef enum _State {
    S_START,
    S_lt,
    S_gt,
    S_lte,
    S_gte,
    S_e,
    S_ee,
    S_nt,
    S_INVALID,
    S_i,
    S_f,
    S_dt
} State;

bool isOp(char input){
    if(input =='=' || input=='<' || input=='>') return true;
    return false;
}

bool isDigit(char input){
    if(input >='0' && input<='9') return true;
    return false;
}

bool isChar(char input){
    if(input>='A' && input<='z' || input=='_') return true;
    return false;
}
void print_state(State s){
    switch(s){
        case S_INVALID: printf("State : Invalid , Not a relational operator\n"); break;
        case S_lt: printf("State : S_lt, LT\n"); break;
        case S_gt: printf("State : S_gt, GT\n"); break;
        case S_lte: printf("State : S_lte, LTE\n"); break;
        case S_gte: printf("State : S_gte, GTE\n"); break;
        // case S_e: printf("State : S_e, Not a relational operator\n"); break;
        case S_ee: printf("State : S_ee, EE\n"); break;
        case S_nt: printf("State : S_nt, NT\n"); break;
    }
}

State dfa(State s, char input, FILE *fp) {
    if(input == '\0' || input == '\n' || input==EOF) return s;
    if(!isOp(input)) return s;

    if(input == '<' && s==S_START) return dfa(S_lt, fgetc(fp),fp);
    else if(input == '>' && s==S_START) return dfa(S_gt, fgetc(fp),fp);
    else if(input == '>' && s==S_lt) return dfa(S_nt, fgetc(fp),fp);
    else if(input == '=' && s==S_START) return dfa(S_e, fgetc(fp),fp);
    else if(input == '=' && s==S_e) return dfa(S_ee, fgetc(fp),fp);
    else if(input == '=' && s==S_lt) return dfa(S_lte, fgetc(fp),fp);
    else if(input == '=' && s==S_gt) return dfa(S_gte, fgetc(fp),fp);
    else return S_INVALID;
}

int main(){
    
    char ch;
    State s;
    FILE *fp;
    fp = fopen("trial.c","r");
    while((ch=fgetc(fp))!=EOF){
        if(isOp(ch)){
            s = dfa(S_START,ch,fp);
            print_state(s);
        }
	else if(isDigit(ch))
	    s = dfa_if(S_START,ch,fp);
	    print_if(s);
	}
    	else{
	    s=dfa_id(S_START,ch,fp);
	}
    }
}
