int numDecodings(char* s) {
    int len = strlen(s);    
    if(len == 0 || (len > 0 && s[0] == '0'))//��һ���ַ���������'0'
        return 0;
    int ways[len+1] ; // ways[1] �� ways[len +1] ���� s[0]��s[len-1]�������
    ways[0] = 1;
    for(int  i = 1; i <= len; ++i){
        if(s[i-1] == '0'){  //��ǰ�ַ�Ϊ��0�������ܵ�������
            ways[i] = 0;
        }            
        else{		//�������ʱ������ǰ��i-1�����������
            ways[i] = ways[i-1];
        }
        if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i-1] <= '6'))) {	//����ǰ�ַ��ܷ�����ǰһ���ַ����
            ways[i] += ways[i - 2];
        }
    }
    return ways[len];
}
