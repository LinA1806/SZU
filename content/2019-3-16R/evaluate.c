/*���㹫ʽ*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int to_nums(char* c);   //��������
int evalRPN(char** tokens, int tokensSize);

int main(){
    char* s[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    char** str = s;     //��ʼ��
    //��֪��Ϊʲô������䲻���ö����м�����ķ�������ʼ��������
    //char** str = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    /*Ȼ���Ҳ���һ��
    **
        ��������Ϊ��������ͨ��ָ�����޸��ִ���������Ϊ�ִ�����������ȫ�������������ں����Ķ�ջ����
        ����Ա���ܻ���ڷǷ�����������ڴ����֡�ֻ�Ǿ�����ѡ�
        ��������Ļ���
        #pragma warning(disable : �����)
        ��ͷ�ļ��м�����ôһ��Ϳ����ˡ���
        ���С���������� ** ���ָ�룬����˵��öž�����ָ��ĳ��֡�


        */
    //printf("%c \n", *(*(str)));
    int len = 13;
    int result = evalRPN(str, len);
    if(result == -1)
        printf("wrong arithmetic expression!\n");
    else
        printf("the result is: %d\n", result);
    return 0;
}
int to_nums(char* c){       //���ַ�ת��Ϊ����
    int res=0;
    int flag = 0;
    if(*c == '-'){
        flag = 1;
        *c++;
    }
    while(*c != '\0'){
        res *= 10;
        res += *c - '0';
        *c++;
    }
    if(flag)
        res = -res;
    return res;
}


int evalRPN(char** tokens, int tokensSize) {
    if(tokensSize == 0)
        return 0;
    int stack[tokensSize];
    int i = -1,j = 0;
    int result = 0;
    while(j < tokensSize){
        switch(tokens[j][0]){
            case '+':
                if(i<1)
                    return -1;
                result = stack[i-1]+stack[i] ;
                i = i - 1;
                stack[i] = result;break;
            case '-':
                if(tokens[j][1] != '\0'){       //�����һ���ַ��Ǹ��ţ���Ҫ�ж����ǲ��Ǹ���
                    stack[++i] = to_nums(tokens[j]);
                    break;
                }
                if(i<1)
                    return -1;
                result = stack[i-1]-stack[i] ;
                i = i - 1;
                stack[i] = result;break;
            case '*':
                if(i<1)
                    return -1;
                result = stack[i-1]*stack[i] ;
                i = i - 1;
                stack[i] = result;break;
            case '/':
                if(i<1)
                    return -1;
                result = stack[i-1]/stack[i] ;
                i = i - 1;
                stack[i] = result;break;
            default:                            //��������ת��Ϊ����
                stack[++i] = to_nums(tokens[j]);
        }
        j++;
    }
    if(j == tokensSize && i == 0)
        return stack[0];
    else
        return -1;
}
