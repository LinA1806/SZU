#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//��s��Ѱ��ch�ַ���index
int indexOfCh(char *s,char ch){
    char *p0 = s;
    while(*p0 != ch && *p0 != '\0') {
        p0++;
    }
    if(*p0 == '\0')
        return -100;
    return p0 - s;
}


double myAtof(char *s){
    double result;
    result = 0.0;
    int num,i;

    int iofe;
    int iofp;

    //Ѱ��e
    iofe = indexOfCh(s,'e');
    iofe = indexOfCh(s,'E');
    //Ѱ��.
    iofp = indexOfCh(s,'.');

    if(iofp != -100){
        //�ȶ�������
        i=1;//i-0 ��λ i-1 ʮλ
        while(s+iofp-i != s-1){
            num = *(s+iofp-i) - '0';
            result += num * pow(10,i-1);
            i++;
        }
        //��С������ұ�
        i=1;
        while(*(s+iofp+i) != '\0' && *(s+iofp+i) != 'e'){
            num = *(s+iofp+i) - '0';
            result += num * pow(10,-i);
            i++;
        }
    }
    //��e���� ��e���ұ�
    if(iofe != -100){
        int sign = 1;
        i =1;
        while(*(s+iofe+i) != '\0'){
            if(*(s+iofe+i) == '-'){
                sign = -1;
            }else{
                num = *(s+iofe+i) - '0';
            }
            i++;
        }
        result *= pow(10,sign*num);
    }
    return result;
}

//����
int main()
{
    char s[100];
    gets(s);
    double result = myAtof(s);
    printf("%.9f",result);
    return 0;
}
