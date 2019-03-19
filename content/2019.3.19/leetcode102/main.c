#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#define MAXSIZE 50
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//��target��i��Ԫ�أ�malһ�������飬�ŵ�buf��
void attach(int *buf[],int *target,int i,int level){
    int *temp = malloc(sizeof(int)*i);
    int j;//work pointer
    for(j=0;j<i;j++){
        temp[j] = target[j];
    }
    //ճ
    buf[level] = temp;

}


int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
        if(!root){
            return NULL;
        }
        struct TreeNode *que[MAXSIZE];
        int *buff[MAXSIZE];//��ʱ����ֵ
        int arr1[MAXSIZE];//��ʱÿ��洢���
        int columnSizesResult[MAXSIZE];//��ӦcolumnSizes
        int i = 0;//��һ��
        int rear = 0, front = 0;
        int level = 0;
        int last = 1;
        struct TreeNode *p;//����ָ��
        //����һ�� ����ѭ�������� ����˳���
        que[rear++] = root;
        //ֻҪ�Ӳ��� �͸�����
        while(rear != front){
            p = que[front++];
            arr1[i++] = p-> val;//�ݴ�
            //�Ѻ����ǽ���
            if(p ->left )
                que[rear++] = p->left;
            if(p -> right)
                que[rear++] = p->right;
            if(last == front){//����һ�� ճ��buff��
                attach(buff,arr1,i,level);

                columnSizesResult[level] = i;//ÿһ���Ԫ�ظ���

                level++;//һ��

                last = rear;

                i = 0;//ÿ��Ԫ�ظ�����0


            }
        }
        //��α��������������С�Լ�ȷ��
        int **result = (int**)malloc(sizeof(int*)*level);
        for(i=0;i<level;i++){
            *(result+i) = *(buff+i);
        }

        int *czResult = (int*)malloc(sizeof(int)*level);
        for(i=0;i<level;i++){
            czResult[i] = columnSizesResult[i];
        }

        *returnSize = level;
        *columnSizes = czResult;
        return result;
}




void inOrder(struct TreeNode *p){
    if(p != NULL){
        inOrder(p->left);
        printf("%d ",p->val);
        inOrder(p->right);
    }
}
//����
int main()
{
    char *pre = "12453678";
    char *in = "42513786";
    struct TreeNode *root = createBT(pre,in,0,7,0,7);
    //inOrder(root);
    int *columnSizes;
    int returnSize;
    int **result = levelOrder(root,&columnSizes,&returnSize);

    int i ,j;
    for(i=0;i<returnSize;i++){
        for(j=0;j<columnSizes[i];j++){
            printf("%d ",*(*(result+i)+j));
        }
        printf("\n");
    }

    return 0;
}
