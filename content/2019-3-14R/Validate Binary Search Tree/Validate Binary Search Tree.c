#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
// ����������
struct TreeNode * CreateBitree(struct TreeNode *root){
    int ch;
    scanf("%d",&ch);
    if(ch==0)
    {
        root=NULL;
        printf("a null!\n");
        return(root);
    }
    else
    {
        root=(struct TreeNode* )malloc(sizeof(struct TreeNode));
        root->val=ch;
        printf("root = %d\n", root->val);
        root->left = CreateBitree(root->left);              //ע��˾�Ⱥ�ǰ�治��ʡ�ԣ�ʡ������������������޸���Ч
        root->right = CreateBitree(root->right);        //�������ҵ����˺ܾ�
        return(root);
    }
}
//�ж��Ƿ�ΪBST
bool _isValidBST(struct TreeNode* root, int *min, int *max)
{
    if (!root)
        return 1;
    if (min && root->val <= *min) //��ǰ�������ڵ�С�ڵ�����Сֵ������ڵ������ֵ�����������bst
        return 0;
    if (max && root->val >= *max)
        return 0;
    return _isValidBST(root->left, min, &root->val) && _isValidBST(root->right, &root->val, max);//ֻҪ����һ����������bst�������Ͳ���BST��
}

bool isValidBST(struct TreeNode* root)
{
    return _isValidBST(root, NULL, NULL);
}

int main(){
    struct TreeNode *root;
    printf("this tree would be created by preorder.\n");
    printf("please input each point 's value(with 0 means null) : \n");
    root = CreateBitree(root);
    printf("\n this is a validBST:  ");
    //printf("\n % d", isValidBST(root));
    if(isValidBST(root))
        printf("true");
    else
        printf("false");
}
