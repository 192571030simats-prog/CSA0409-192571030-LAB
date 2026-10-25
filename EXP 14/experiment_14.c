#include <stdio.h>
#include <string.h>
int main(void) {
    char files[20][40], name[40];
    int n=0, choice, i, found;
    do {
        printf("\n1.Create file  2.List files  3.Exit\nChoice: ");
        scanf("%d",&choice);
        if(choice==1){
            printf("File name: "); scanf("%39s",name);
            found=0; for(i=0;i<n;i++) if(strcmp(files[i],name)==0) found=1;
            if(found) printf("File already exists.\n");
            else if(n<20){strcpy(files[n++],name);printf("File created.\n");}
            else printf("Directory full.\n");
        } else if(choice==2){
            printf("Files in directory:\n");
            for(i=0;i<n;i++) printf("%s\n",files[i]);
        }
    } while(choice!=3);
    return 0;
}
