#include<stdio.h>
#include<stdlib.h>

//����ֵΪ��������еĺͣ���ʼλ�úͽ���λ��ʹ��begin_position��end_position������array_lenthΪ����ĳ���
int zixulie(int *array, int array_lenth, int *begin_position, int *end_position){
    int sum=0,max_sum=0;//sum�����洢ÿһ�ε������еĺͣ�max_sum���������ĺ�
    int begin,area_len,max_begin,max_end;//beginΪÿһ��ѡ�������㣬area_len�ǿ�ĳ��ȣ�max_begin��max_end�ǵ�max_sum����ʱѡ�����ǰ���±�
    begin = 0;
    area_len = array_lenth;//��ĳ������Ϊ����ȫ����Ȼ����������
    while(area_len > 0){
        for(;begin + area_len <= array_lenth;begin++){//����ĺ�߽�δ��������ĩβʱ
            for(int i = begin;i < begin + area_len;i++){//��������ȫ�����
                sum += array[i];
            }
            //printf("%d\n",sum);
            if(sum > max_sum){ //�Ƚ�
                max_sum = sum;
                max_begin = begin+1;
                max_end = begin + area_len;
            }
            sum = 0;
        }
        area_len--;
        begin = 0;
    }


    *begin_position = max_begin;
    *end_position = max_end;
    return max_sum;
}

int main(){
    int array[7]={0,6,-1,1,-6,7,-5};
    int array_len=7;
    int sum;
    int begin=0,end=0;
    sum = zixulie(array,array_len,&begin,&end);
    printf("It is %d,%d,%d",sum,begin,end);

    return 0;
}