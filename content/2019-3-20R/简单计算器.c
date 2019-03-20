#include<stdio.h>

double to_num(char sen[], int i){
    double sum = sen[i] - '0';
    return sum;
}

double calcu(char c, double a, double b){
    double res = 0;
    switch(c){
    case '+':
        res = a + b;break;
    case '-':
        res = a - b;break;
    case '*':
        res = a * b;break;
    case '/':
        res = a / b;break;
    }
    return res;
}

int main(){
    char sen[200];  //��ű��е�����ʽ
    double tmp[200];    //  �����ʱ����������δ�������������
    char cal[100];  //  ��������
    int topt = -1, topc = -1, i = 0, sum;
    gets(sen);
    while(sen[0] != '0'){
        do{
            if(sen[i] >= '0' && sen[i] <= '9'){
                sum = 0;
                while(sen[i] >= '0' && sen[i] <= '9'){//����������ջ
                    sum *= 10;
                    sum += to_num(sen, i++);
                }
                tmp[++topt] = sum;
            }

            else{           //�������֣�����ǰһ��������߼������ȵ����������ֺ�һ��������������㣬���������ѹ�����
                while(topc > -1 && (sen[i] == '+' || sen[i] == '-' || ((sen[i] == '*' || sen[i] == '/') && (cal[topc] == '*' || cal[topc] == '/')))){
                    tmp[topt-1] = calcu(cal[topc--], tmp[topt-1], tmp[topt]);
                    topt--;
                }
                cal[++topc] = sen[i++];
            }
            if(sen[i] == ' ') ++i;

        }while(topt >= 0 && sen[i] != '\0');

        while(topc > -1){       //ջ�л��з��ţ�˵�����㻹û�н���
            tmp[topt-1] = calcu(cal[topc], tmp[topt-1], tmp[topt]);
            topt--;
            topc--;
        }

        printf("%.2f\n", tmp[0]);
        topt = topc = -1;
        i=0;
        gets(sen);      //�����µ�һ��
    }
    return 0;
}
