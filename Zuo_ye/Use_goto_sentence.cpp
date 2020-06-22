#include<iostream>
//利用goto语句可以方便地从多层循环中跳出
int main(){
    int a,b,c,token=0;
    label:
        if(token==0){
            for(a=1;a<10;a++){
                for(b=1;b<10;b++){
                    for(c=1;c<10;c++){
                        printf("exist point (%d,%d,%d)\n",a,b,c);
                        if(a==2&&b==3&&c==4){
                            token = 1;
                            printf("dao_tou_le\n");
                            goto label;
                        }
                    }
                }
            }
        }
    else printf("end\n");
    system("PAUSE");
    return 0;
}//实际上一般没人会写这么多循环，也不需要从里面跳出
//所以说这个goto就是逊啦