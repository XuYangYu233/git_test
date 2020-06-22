#include<stdio.h>
#include<stdlib.h>

//返回值为最大子序列的和，开始位置和结束位置使用begin_position和end_position带出。array_lenth为数组的长度
int zixulie(int *array, int array_lenth, int *begin_position, int *end_position){
    int sum=0,max_sum=0;//sum用来存储每一次的子序列的和，max_sum用来存最大的和
    int begin,area_len,max_begin,max_end;//begin为每一次选定框的起点，area_len是框的长度，max_begin和max_end是当max_sum出现时选定框的前后下标
    begin = 0;
    area_len = array_lenth;//框的长度最初为数组全场，然后慢慢缩短
    while(area_len > 0){
        for(;begin + area_len <= array_lenth;begin++){//当框的后边界未到达数组末尾时
            for(int i = begin;i < begin + area_len;i++){//框内数字全部相加
                sum += array[i];
            }
            //printf("%d\n",sum);
            if(sum > max_sum){ //比较
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