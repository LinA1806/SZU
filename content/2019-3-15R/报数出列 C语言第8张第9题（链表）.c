/*������ÿ��5���У���ʣ���Ǹ�����������*/
#include<stdio.h>
struct Node{
    int val;
    struct Node* next;
};
int main(){
    printf("please input a number:");
    int n;
    scanf("%d", &n);
    if(n == 0){
        printf("wrong num!");
        return 0;
    }
    //��ʼ��������
    struct Node* head = (struct Node* )malloc(sizeof(struct Node));
    if(head==NULL){
        printf("no allocate!\n");
        return 0;
    }
    else
        printf("success!\n");
    struct Node* k = head;
    head->val = 1;
    printf("the head is %d \n", head->val);
    int i = 2;
    while(i <= n){
        struct Node*p = (struct Node*)malloc(sizeof(struct Node));
        p->val = i;
        k->next = p;
        k = k->next;
        i++;
    }
    k->next = head;
    int c = 0;
    while(head->next != head){      //ֻʣһ�����������Լ�ָ���Լ�
        c = 1;
        while(c<5-1){
            head = head->next;
            c++;
        }       //��ʱheadָ��Ҫ���еĽڵ��ǰһ���ڵ�
        k = head->next;     //kָ��Ҫɾ���Ľڵ�
        head->next = k->next;
        head = head->next;      //head�ǵ�Ҫָ����һ��
        //printf("delete %d\n", k->val);
        free(k);
    }
    printf("the last kid is %d\n", head->val);
    return 0;
}


