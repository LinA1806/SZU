/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool isPalin(char* s, int end);
void helper(char* s, char*** ret, int** colS, int* retS, char** cur, int k );


char*** partition(char* s, int** columnSizes, int* returnSize) {
    *returnSize = 0;    //          ��ʼ���ܽ����0
    if(s == NULL || !strcmp(s, "")) return NULL;  //�����ǿմ�
    
    
    /*Ԥ����ռ�*/
    *columnSizes = (int*)malloc(sizeof(int)*500);  //Ϊÿ�з���500�������ַ������ȵ�int�Ϳռ�
    char*** ret = (char***)malloc(sizeof(char**) * 500);    //������500�����ܵĲ�ͬ�ķ��䷽��
    char** cur = (char**)malloc(sizeof(char*) * 500);   //����ÿ��������500�����ִ�    
    int len = strlen(s) + 1;
    for(int i = 0; i<500; i++)      //ÿ�����ַ����������ԭ�ַ�����ô��������Ϊÿ�����ַ�������len���ַ�����
        cur[i] = (char*)malloc(len);
    
    /*���ݷ�*/
    helper(s, ret, columnSizes, returnSize, cur, 0);

    return ret;
        
}

void helper(char* s, char*** ret, int** columnSizes, int* returnSize, char** cur, int k ){
    if(*s == '\0'){    //sָ���ַ���β����˵���÷�������
        ret[*returnSize] = (char**)malloc(sizeof(char*)*k);   //��ʼ���µķ���
        for(int i = 0; i<k; i++){
            ret[*returnSize][i] = (char*)malloc(strlen(cur[i]) + 1);  //  ��ʼ��ÿ�����ַ���
            strcpy(ret[*returnSize][i], cur[i]);   //�����ַ�����ֵ
        }
        (*columnSizes)[(*returnSize)++] = k;    //��������1���÷������ַ�����Ϊk
        return;
    }
    /* ��ʼȡ�ִ� */
    int len = strlen(s);
    for(int i = 0; i < len; i++)  {
        if(isPalin(s, i)) {      /*  �����0��i���ִ��ǻ���  */
            strncpy(cur[k], s, i+1);  //���ִ����뵽�ݴ淽������ĵ�k���ݴ��ֶ�
            cur[k][i+1] = '\0';         //ǧ��ǵü���ֹ����
            
            /* ����һ���ַ���ʼ����һ�����Ĵ� */
            helper(s+i+1, ret, columnSizes, returnSize, cur, k+1);
        }
        //�����0��i���ִ����ǻ��ģ��򳤶ȼ�һ�������һ��Ĵ�
    }
}

bool isPalin(char* s, int end){
  /* printf("error: start %d, end %d\n", start, end); */
  if(end < 0)          return false;
  int start = 0;
  while(end > start)    //���������м����Ƿ���Ĵ�
  {
    if(s[start] != s[end]) return false;
    start++;   end--;
  }
  return true;
}




