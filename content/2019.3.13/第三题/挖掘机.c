#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN -10000
//PAT

int getMaxTotal(int *arr,int len){
    int maxIndex;
    int maxTotal = MIN;
    int i;
    for(i=1;i<len;i++){
        if(*(arr+i) > maxTotal){
            maxIndex = i;
            maxTotal = *(arr+i);
        }
    }
    return maxIndex;
}



int main(){

    int i;
    int n;
    int numChoose;
    int score;
    int topNum;
    int total;
scanf("%d",&n);
    int data[n+1];


    for(i=0;i<n+1;i++){//��ʼ��
        data[i] = 0;
    }

    for(i=1;i<n+1;i++){//��1��ʼ
        scanf("%d %d",&numChoose,&score);
        if(numChoose >n){
            printf("��Ų��ܳ���n");
        }
        data[numChoose] += score;
    }
    topNum = getMaxTotal(data,n+1);
    total = data[topNum];


    printf("%d %d",topNum,total);

    return 0;
}
