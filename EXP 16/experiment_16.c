#include <stdio.h>
typedef struct { int id; char name[30]; float salary; } Employee;
int main(void) {
    FILE *fp=fopen("employees.dat","rb+");
    if(!fp) fp=fopen("employees.dat","wb+");
    if(!fp){perror("employees.dat");return 1;}
    Employee e; int id;
    printf("Enter employee ID, name and salary: ");
    scanf("%d %29s %f",&e.id,e.name,&e.salary);
    fseek(fp,(long)(e.id-1)*sizeof(Employee),SEEK_SET);
    fwrite(&e,sizeof(Employee),1,fp);
    printf("Employee record saved.\n");
    printf("Enter ID to read: "); scanf("%d",&id);
    fseek(fp,(long)(id-1)*sizeof(Employee),SEEK_SET);
    if(fread(&e,sizeof(Employee),1,fp)==1)
        printf("ID: %d Name: %s Salary: %.2f\n",e.id,e.name,e.salary);
    else printf("Record not found.\n");
    fclose(fp);
    return 0;
}
