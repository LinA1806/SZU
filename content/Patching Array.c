int minPatches(int* nums, int numsSize, int n) {
    int res = 0;    //����������
    int i = 0;
    long target = 1;    //��һ��sumĿ��
    while(target <= n){
        //Ŀ����n����ʱѭ��
        if(i < numsSize && nums[i] <= target){      //��ǰ����<=Ŀ�꣬���������ֿ������target
            target += nums[i++];    //��һ��sumĿ��
        }
        else{
            target += target;   //��һ��sumĿ��
            res++;  //��Ҫ����һ������
        }
    }
    return res;
}