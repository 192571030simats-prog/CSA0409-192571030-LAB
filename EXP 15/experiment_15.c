#include <stdio.h>
#include <string.h>
int main(void) {
    char users[10][30], files[10][10][30], name[30];
    int counts[10]={0}, nu=0, choice, u, i;
    do {
        printf("\n1.Add user  2.Add file  3.List directory  4.Exit\nChoice: ");
        scanf("%d",&choice);
        if(choice==1 && nu<10){
            printf("User name: "); scanf("%29s",users[nu]);
            counts[nu++]=0; printf("User directory created.\n");
        } else if(choice==2){
            printf("User number (1-%d): ",nu); scanf("%d",&u); u--;
            if(u<0 || u>=nu) {printf("Invalid user.\n");continue;}
            if(counts[u]>=10){printf("Directory full.\n");continue;}
            printf("File name: "); scanf("%29s",name);
            strcpy(files[u][counts[u]++],name); printf("File added.\n");
        } else if(choice==3){
            for(u=0;u<nu;u++){printf("%s/:\n",users[u]);for(i=0;i<counts[u];i++)printf("  %s\n",files[u][i]);}
        }
    } while(choice!=4);
    return 0;
}
