#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id,marks;
    char name[50];
};

int main()
{
    int i;
    struct student a[5];
    FILE *fp;
    fp=fopen("d:file.txt","w");
    printf("\nEnter deteails: ");
    for(i=0;i<5;i++)
    {
        scanf("%d%d%s",&a[i].id,&a[i].marks,a[i].name);
    }
    for(i=0;i<5;i++)
    {
        fprintf(fp,"%d %d %s\n",a[i].id,a[i].marks,a[i].name);
    }
    fclose(fp);

    return 0;
}
