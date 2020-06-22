#include<iostream>
#include<time.h>
int main(){
    struct tm t;
    time_t t_of_day;
    t.tm_yday=1997-1900;
    t.tm_mon=6;
    t.tm_mday=1;
    t.tm_hour=0;
    t.tm_min=0;
    t.tm_sec=1;
    t.tm_isdst=0;
    t_of_day=mktime(&t);
    printf(ctime(&t_of_day));
    return 0;
}
/*int main(){
    struct tm *local;
    char str[80];
    time_t it;
    it = time(&it);
    local = localtime(&it);
    printf("%d\n%d\n%d\n",local->tm_mday,local->tm_mon,local->tm_year);
    printf("%s\n",ctime(&it));
    strftime(str,100,"now is %Y %B %d",local);
    printf(str);
    return 0; 
}*/