/*������ÿ��5���У���ʣ���Ǹ��������鷨��*/

#include<stdio.h>

int main(){
    int n;
    printf("please input a number: ");
    scanf("%d" ,&n);
    int arr[n];
    for(int i = 0; i < n ;i++){
        arr[i] = i+1;   //  ��һ�������¼ÿ���˵ı��
    }
    for(int i = 0; i < n ;i++){
        printf("%d ",arr[i]);   //  ��һ�������¼ÿ���˵ı��
    }
    int c = 0;  //  ��¼��������
    int i = 0, k = 0;   //k��5
    while(c < n-1){
            k = 0;
        while(k < 5){
            i = i % n;
            if(arr[i]!=0){
                k++;
            }
            i++;
        }
        arr[i-1] = 0;     //�߳�ȥһ����
        c++;
        i = i%n;
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] != 0){
            printf("\nthe last child is %d\n", arr[i]);
            break;
        }
    }

    return 0;
}
