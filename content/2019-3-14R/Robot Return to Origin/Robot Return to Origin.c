#include<stdio.h>
#define bool int  //��Ϊc����û��bool�ͣ�Ҫ�Լ�����
#define false 0
#define true 1
bool judgeCircle(char* moves) {
    int cu,cd,cl,cr;
    cu = cd = cl  = cr = 0;
    while(*moves){ //movesָ������ݲ��ǡ�\0��
        switch(*moves){   //ͳ������ָ�������
            case 'U': cu++;break;
            case 'D': cd++;break;
            case 'L': cl++;break;
            case 'R': cr++;break;
        }
        moves++;
    }
    if(cu == cd && cl == cr)  //ֻҪ����ָ������ȣ�������ָ������ȣ� �Ϳ϶��ܷ���ԭ��
        return true;
    else
        return false;
}

int main(){
    char tmp[100];
    printf("please input a string of instructions: ");//����ָ�ֻ����LRUD���ֶ���ֻ���Ǵ�д
    scanf("%s", tmp);
    printf("\nthe robot returns to the origin : ");//�ж��ܷ񷵻�ԭ��
    if( judgeCircle(tmp))
        printf("true");
    else
        printf("false");
}
