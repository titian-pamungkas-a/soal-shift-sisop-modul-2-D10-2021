#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int conc(int y, int M, int d, int h, int m, int s){
    char ye[5], Mon[5], day[5], hour[5], min[5], sec[5];

    sprintf(ye,"%d",y);
    sprintf(Mon,"%02d",M);
    sprintf(day,"%02d",d);
    sprintf(hour,"%02d",h);
    sprintf(min,"%02d",m);
    sprintf(sec,"%02d",s);

    strcat(ye,"-");
    strcat(Mon,"-");
    strcat(day,"_");
    strcat(hour,":");
    strcat(min,":");

    strcat(ye,Mon);
    strcat(day,hour);
    strcat(min,sec);

    strcat(ye,day);
    strcat(ye,min);

    return atoi(ye);
}


int main(){
    time_t time_curr;
    char* time_string;

    //create folder
    while(1){
         //mendapatkan waktu sekarang
        time_curr = time(NULL);

        //comvert 
        struct tm *time_string = localtime(&time_curr);

        int y=time_string->tm_year+1900, M=time_string->tm_mon+1, d=time_string->tm_mday, h=time_string->tm_hour, m=time_string->tm_min, s=time_string-> tm_sec;


        // conc(y,M,d,h,m,s);

        printf("%d-%02d-%02d_%02d:%02d:%02d\n",time_string->tm_year+1900,time_string->tm_mon+1,time_string->tm_mday, time_string->tm_hour, time_string->tm_min, time_string-> tm_sec);
        //mkdir(time_string,0777);
        // printf("%s",ye);
        
        sleep(3);
        // break;
    }

}

