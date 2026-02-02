#include<stdio.h>

typedef struct {
    char model[20];
    int temp;
}boiler;

void heat_up(boiler *b){
    b -> temp += 1;
    printf("현재 온도 : %d도 ([%s] 난방 중)\n",b -> temp, b -> model);
}

int main(){
    boiler home = {"bing",20};

    heat_up(&home);
    heat_up(&home);
    heat_up(&home);

    return 0;

}

