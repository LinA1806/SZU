#include <stdio.h>
#include <stdlib.h>
//����h����ӡ��Ϊh���ϵ�Ϊh������
int main()
{
    int h;
    scanf("%d",&h);
    int margin;
    int i,j;
    int chara = h;
    margin = (h-1)*2;;
    while(h>0){
        for(i=0;i<margin;i++){
            printf(" ");
        }
        margin -=2;
        for(j=0;j<chara;j++){
            printf("*");
        }
        chara += 2;
        printf("\n");
        h--;
    }
    return 0;
}
