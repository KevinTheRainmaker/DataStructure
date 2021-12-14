#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "ListBasedStack.h"

int GetOpPrec(char op){
    switch(op){
        case '*':
        case '/':
            return 3;    // 가장 높은 연산 우선 순위
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;   // 가장 낮은 연산 우선 순위
                        // )는 입력될 경우 종료하는 프로세스를 실행시키므로
                        // 연산자 우선 순위가 필요치 않음
    }

    return -1;   // 등록되지 않은 연산자
}

int RetrieveOpPrec(char op1, char op2){
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else    // 두 연산자의 우선 순위가 같다면
        return 0;
}

void ConvToPostfix(char exp[]){
    Stack stack;
    int expLen = strlen(exp);
    char * convExp = (char*)malloc(expLen+1);   // 변환된 수식을 담을 공간 마련

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char)*expLen+1);  // 할당된 배열 초기화
    StackInit(&stack);

    for(i=0; i<expLen; i++){
        tok = exp[i];   // exp로 전달된 수식을 한 문자씩 tok에 저장
        if(isdigit(tok)){   // tok에 저장된 문자가 숫자인지 확인 - 10진수라면 1 반환
            convExp[idx++] = tok;
        }
        else{   // 연산자
            switch(tok){
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while (1){
                        popOp = SPop(&stack);   // 스택에서 연산자 꺼내기
                        if(popOp == '(')    // ( 연산자 만날 때까지
                            break;
                        convExp[idx++] = popOp; // 배열 convExp에 저장
                    }
                    break;
                case '+': case '-':
                case '*': case '/':
                    while(!SIsEmpty(&stack) && RetrieveOpPrec(SPeek(&stack), tok) >= 0) // 정상적인 연산자인 경우 우선 순위 확인
                        convExp[idx++] = SPop(&stack);
                    SPush(&stack, tok); // 연산자가 저장될 스택의 위치를 찾았다면, 저장
                    break;
            }
        }
    }

    while (!SIsEmpty(&stack)){
        convExp[idx++] = SPop(&stack);  // 스택에 남아 있는 모든 연산자를 convExp로 이동
    }

    strcpy(exp, convExp);   // 변환된 수식을 exp에 복사
    free(convExp);
}