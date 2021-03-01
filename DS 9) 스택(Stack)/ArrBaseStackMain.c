# include <stdio.h>
# include "ArrBaseStack.h"

int main(){
    // 스택의 생성 및 초기화 ////
    Stack stack;
    StackInit(&stack);

    // 데이터 넣기 ////
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);

    while(!SIsEmpty(&stack))
        // 맨 위 데이터 확인 ////
        printf("PEEK: %d ", SPeek(&stack));
        
        // 데이터 꺼내기 ////
        printf("POP: %d ", SPop(&stack));

    return 0;
}