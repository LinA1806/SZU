/*2019-3-17
**��Դ��C���Գ�����Ƶ�10��3
**��Ŀ����дһ��������Ƶĳ���
**������
**�������0~54�����ֱ�ʾÿһ����
**���ñ�����飬��ֹ���������ظ���
**2��JOKER������ɫ*/

#include<stdio.h>
#include<stdlib.h>
void dis_card();
static int c[54];
enum poker{
    spade,heart,diamond,club
}p[13];

main(){
    printf("����Ҫ�������ƣ�");
    int n;
    scanf("%d", &n);
    if(n < 1 || n > 54){
        printf("invalid number!\n");
        return 0;
    }
    printf("your cards:\n");
    for(int i = 0; i < n; i++){
        if(i%5 == 0)
            printf("\n");
        dis_card();
    }

}

void dis_card(){
    static int i = 0;
    do{
        i = rand()%54;
    }while(c[i] == 1);      //�Ѿ��������Ʊ�עΪ1
    c[i]=1;

    if(i==52){
        printf("blackJoker\t");
        return;
    }

    if(i==53){
        printf("redJoker\t");
        return;
    }

     int num = (i/4)%13 +1; //  ��ÿ�������
     enum poker suit;
    switch(i%4){    //��ÿ��滨ɫ
        case 0: suit = spade;break;
        case 1: suit = heart;break;
        case 2: suit = diamond;break;
        case 3: suit = club;break;
    }
    switch(suit){
        case spade: printf("  spade");break;
        case heart: printf("  heart");break;
        case diamond: printf("diamond");break;
        case club: printf("   club");break;
    }
    printf("%-2d\t",num);
}
