#include <stdio.h>
#include <stdlib.h>

/*��˳�����*/
int findNumInArr(int *a,int len,int target){
    int i;
    for(i=0;i<len;i++){
        if(*(a+i) == target)
            return 1;
    }
    return 0;
}


int main()
{
    int n;
    scanf("%d",&n);//����n����
    int i,j;//����ָ��
    int a[n];//����n������
    for(i=0;i<n;i++){//����n������
        scanf("%d",a+i);
    }

    int m;//������
    scanf("%d",&m);//����n����
    int b[m];
    for(i=0;i<m;i++){
        scanf("%d",b+i);
    }

    for(j=0;j<m;j++){
        int flag = findNumInArr(a,n,b[j]);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
