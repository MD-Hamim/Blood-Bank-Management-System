#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>

struct contact

{

    long ph;

    char name[20],add[40],email[30],blood_group[10];

} list;

char query[20],name[20],blood_group[10];

FILE *fp, *ft;

int i,n,ch,l,found,main_exit;


void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
    k=i;
}


int main()
{
    char pass[15],password[15]="theangrybirds";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Matched!\nLOADING");
        for(i=0;i<=8;i++)
        {
            fordelay(100000000);
            printf(".....");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        menu();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    }
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}

void menu()

{

main:

    system("cls");

    system("color 2F");
    printf("\n\n\t\tThe Angry Birds Blood Bank management system");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t[ 1 ] Create new donor account\n\t\t[ 2 ] Update information of existing donor\n\t\t[ 3 ] Search an existing donor\n\t\t[ 4 ] Removing existing donor\n\t\t[ 5 ] View donor's list\n\t\t[ 0 ] Exit\n\n\n\n\n\t\t Enter your choice: ");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* *********************Add new donor************  */

    case 1:

        system("cls");

        fp=fopen("Record.txt","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input\nName (Use identical): ");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Blood type: ");

            scanf("%[^\n]",&list.blood_group);

            fflush(stdin);

            printf("Phone: ");

            scanf("%ld",&list.ph);

            fflush(stdin);

            printf("Address: ");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("Email address: ");

            gets(list.email);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;

               /* *********************edit donor************************/

    case 2:

        system("cls");

        fp=fopen("Record.txt","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Edit donor\n===============================\n\n\t..::Enter the name of donor to edit:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);

        printf("..::Name(Use identical):");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::Blood type: ");

        scanf("%[^\n]",&list.blood_group);

        fflush(stdin);

        printf("..::Phone:");

        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("..::address:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("..::email address:");

        gets(list.email);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("Record.txt");

        rename("temp.dat","Record.txt");

        break;

                /* *******************search donor**********************  */

    case 3:

        system("cls");

        do

        {

            found=0;

            printf("\n\n\t..::SEARCH DONOR\n\t===========================\n\t..::Type of blood to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("Record.txt","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    blood_group[i]=list.blood_group[i];

                blood_group[l]='\0';

                if(stricmp(blood_group,query)==0)

                {

                    printf("\n..::Name\t\t: %s\n..::Blood type\t\t: %s\n..::Phone\t\t: %ld\n..::Address\t\t: %s\n..::Email\t\t: %s\n",list.name,list.blood_group,list.ph,list.add,list.email);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

              /* ********************delete donor**********************/

    case 4:

        system("cls");

        fflush(stdin);

        printf("\n\n\t..::REMOVE A DONOR\n\t==========================\n\t..::Enter the name of donor to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("Record.txt","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("Record.txt");

        rename("temp.dat","Record.txt");

        break;

    default:

        printf("Invalid choice");

        break;

        /* *********************list of donor*************************  */

    case 5:

        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF DONOR\n\t\t================================\n\nName\t\tBlood type\t\tPhone No\t\tAddress\t\tE-mail ad.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("Record.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t\t: %s\nBlood Type\t: %s\nPhone\t\t: %ld\nAddress\t\t: %s\nEmail\t\t: %s\n",list.name,list.blood_group,

                           list.ph,list.add,list.email);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;

    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:
        printf("\n\n\n\nThis Project is developed by The Angry Bids (^-^)\n\n");

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}

