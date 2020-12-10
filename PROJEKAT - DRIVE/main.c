#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projekat.h"
#include <time.h>

int prijavljenost;

typedef struck folder{
    char link[6];
    char naziv[100];
    char vlasnik[25];
} folder;

void napraviFolder()
{
    int j;
    char c;
    printf("uneti naziv foldera: ");
    char naziv[100];
    gets(naziv);
    folder naziv;
    FILE*  naziv = fopen(naziv, "w+");
    strcpy(folder.naziv, naziv)
    strcpy(naziv.vlasnik, prijavljeniNalog);
    time_t t;
    srand(time(&t));
    for(j = 0; j < 100; j++)
    {
        naziv.link[6] = rand() % 91;
    }
    fprintf(naziv, folder.link);
    fprintf(naziv, "\n");
    fprintf(naziv, folder.naziv);
    fprintf(naziv, "\n");
    fprintf(naziv, folder.vlasnik);
    fclose(naziv);
}

void deliFolder()
{

}

void izmeniFolder()
{

}

void izbrisiFolder()
{

}

typedef struct nalog{
    char ime[15];
    char prezime[20];
    char email[100];
    char nadimak[25];
    char lozinka[1000];
    int prijavljenost;
} nalog;

void novNalog()
{
    int i, tacka = 0, et = 0;
    char privremeni1[1000], privremeni2[1000];
    nalog *nalog;
    printf("KREIRANJE NOVOG NALOGA:\n");
    fflush(stdin);
    printf("unesite ime: \n");
    gets(nalog->ime);
    fflush(stdin);
    printf("unesite prezime: \n");
    gets(nalog->prezime);
    fflush(stdin);
    printf("unesite email: \n");
    i = 0;
    email:
    gets(nalog->email);
    fflush(stdin);
    while(nalog->email[i] != '\0')
    {
        if(nalog->email[i] == '@')
            et = 1;
        if(nalog->email[i] == '.')
        {
            tacka = 1;
            if(et == 0)
            {
                printf("unesite email kako treba!");
                goto email;
            }
        }
    }
    printf("unesite nadimak");
    gets(nalog->nadimak);
    fflush(stdin);
    printf("unesite lozinku:");
    gets(nalog->lozinka);
    fflush(stdin);
    strcpy(privremeni1,nalog->lozinka);
    while(5)
    {
        printf("potvrdite lozinku:");
        gets(privremeni2);
        fflush(stdin);
        if(strcmp(privremeni1,privremeni2) == 0)
        {
            strcpy(privremeni2, nalog->lozinka);
            break;
        }
        else
        {
            printf("lozinke se ne poklapaju!\n");
        }
    }
    FILE* fp = fopen(nalog->nadimak, "w+");
    fputs(nalog->ime, fp);
    fputc('\n', fp);
    fputs(nalog->prezime, fp);
    fputc('\n', fp);
    fputs(nalog->email, fp);
    fputc('\n', fp);
    fputs(nalog->nadimak, fp);
    fputc('\n', fp);
    fputs(nalog->lozinka, fp);
    fputc('\n', fp);
}

void izbrisiNalog()
{
    remove(prijavljeniNalog);
    prijavljenost = 0;
}

void izmeniNalog()
{
    printf(" MENJANJE NALOGA: \n izaberite deo naloga koji zelite da izmenite: \n ime - 1 \n prezime - 2 \n email - 3 \n nadimak - 4 \n lozinka - 5 \n");
    char privremeni11[1000];
    char privremeni12[1000];
    char privremeni21[1000];
    char privremeni22[1000];
    char privremeni31[1000];
    char privremeni32[1000];
    char privremeni41[1000];
    char privremeni42[1000];
    char privremeni51[1000];
    char privremeni52[1000];
    char privremeni53[1000];
    int b, i;
    char znak;
    nalog *nalog;
    FILE* fp = fopen(prijavljeniNalog, "w+");
    fseek(fp, 0, SEEK_SET);
    do
    {
        scanf("%i", &b);
        switch(b)
        {
            case 1:
                printf("unesite novo ime:\n");
                scanf("%s", privremeni11);
                fflush(stdin);
                fgets(privremeni12, 16, fp);
                fflush(stdin);
                strcpy(privremeni12, privremeni11);
                strcpy(nalog->ime, privremeni12);
                fputs(nalog->ime, fp);
                fputc('\n', fp);
                break;
            case 2:
                for(i = 0; i < b; i++)
                {
                    do
                    {
                        znak = fgetc(fp);
                        fseek(fp, 1, SEEK_CUR);
                    }while(znak == '\0');
                }
                printf("unesite novo prezime:\n");
                scanf("%s", privremeni21);
                fflush(stdin);
                fgets(privremeni22, 21, fp);
                fflush(stdin);
                strcpy(privremeni22, privremeni21);
                strcpy(nalog->prezime, privremeni22);
                fputs(nalog->prezime, fp);
                fputc('\n', fp);
                break;
            case 3:
                for(i = 0; i < b; i++)
                {
                    do
                    {
                        znak = fgetc(fp);
                        fseek(fp, 1, SEEK_CUR);
                    }while(znak == '\0');
                }
                printf("unesite novi email:\n");
                scanf("%s", privremeni31);
                fflush(stdin);
                fgets(privremeni32, 100, fp);
                fflush(stdin);
                strcpy(privremeni32, privremeni31);
                strcpy(nalog->email, privremeni32);
                fputs(nalog->email, fp);
                fputc('\n', fp);
                break;
            case 4:
                for(i = 0; i < b; i++)
                {
                    do
                    {
                        znak = fgetc(fp);
                        fseek(fp, 1, SEEK_CUR);
                    }while(znak == '\0');
                }
                printf("unesite novi nadimak:\n");
                scanf("%s", privremeni41);
                fflush(stdin);
                fgets(privremeni42, 26, fp);
                fflush(stdin);
                strcpy(privremeni42, privremeni41);
                strcpy(nalog->ime, privremeni42);
                fputs(nalog->nadimak, fp);
                fputc('\n', fp);
                break;
            case 5:
                for(i = 0; i < b; i++)
                {
                    do
                    {
                        znak = fgetc(fp);
                        fseek(fp, 1, SEEK_CUR);
                    }while(znak == '\0');
                }
                case5:
                printf("unesite staru lozinku:\n");
                scanf("%s", privremeni51);
                fflush(stdin);
                fgets(privremeni52, 1001, fp);
                fflush(stdin);
                if(strcmp(privremeni51, privremeni52) == 0)
                {
                    printf("unesite novu lozinku:\n");
                    scanf("%s", privremeni53);
                    fflush(stdin);
                    strcpy(privremeni52, privremeni53);
                    strcpy(privremeni51, privremeni52);
                }
                else
                {
                    printf("lozinka je netacna!");
                    goto case5;
                }
                fputs(nalog->lozinka, fp);
                fputc('\n', fp);
                break;
            default:
                printf("uneli ste nevazeci broj!");
        }
    }while(b<1 || b>5);





}

void login()
{
    char prijavljenNalog[25];
    nalog *nalog;
    char emailLogin[100], lozinkaLogin[1000];
    printf("LOGIN: \n");
    email:
    printf("unesite email: \n");
    gets(emailLogin);
    if(strcmp(emailLogin, nalog->email) != 0)
    {
        printf("email je pogresan!\n");
        goto email;
    }
    lozinka:
    printf("unesite lozinku: \n");
    gets(lozinkaLogin);
    if(strcmp(lozinkaLogin, nalog->lozinka) != 0)
    {
        printf("nadimak je pogresan!\n");
        goto lozinka;
    }
    strcpy(prijavljenNalog, nalog->nadimak);
    prijavljenost = 1;
}

void logout()
{
    int* prijavljenNalog;
    prijavljenost = 0;
}

int main()
{
    int a, prijavljenost = 0;
    do{
        printf("MAIN MENU:\n");
        printf("Dodaj nalog - 1\n");
        if(prijavljenost == 1)
        {
            printf("izmeni nalog - 2\n");
            printf("izbrisi nalog - 3\n");
            printf("prijavljeni kao: %s\n", prijavljeniNalog);
        }
        printf("login - 4\n");
        if(prijavljenost == 1)
        {
            printf("logout - 5\n");
        }

        if(prijavljenost == 1)
        {
            printf("------------------------------");
            printf("dodaj folder - 6");
            printf("deli folder - 7");
            printf("menjaj folder - 8");
            printf("izbrisi folder - 9");
        }
        printf("izadji iz programa - 10\n");
        scanf("%i", &a);
        fflush(stdin);
        switch(a)
        {
            case 1:
                novNalog();
                break;
            case 2:
                if(prijavljenost == 1)
                {
                    izbrisiNalog();
                }
                else
                {
                    printf("nevazeca opcija");
                }
                break;
            case 3:
                if(prijavljenost == 1)
                {
                    izmeniNalog();
                }
                else
                {
                    printf("nevazeca opcija");
                }
                break;
            case 4:
                login();
                break;
            case 5:
                if(prijavljenost == 1)
                {
                    logout();
                }
                else
                {
                    printf("nevazeca opcija");
                }
                break;
            case 6:
                if(prijavljenost == 1)
                {
                    napraviFolder();
                }
                else
                {
                    printf("nevazeca opcija");
                }
                break;
            case 7:
                if(prijavljenost == 1)
                {
                    deliFolder();
                }
                else
                {
                    printf("nevazeca opcija");
                }
                break;
            case 8:
                if(prijavljenost == 1)
                {
                    izmeniFolder();
                }
                else
                {
                    printf("nevazeca opcija");
                }
                break;
            case 9:
                if(prijavljenost == 1)
                {
                    izbrisiFolder();
                }
                else
                {
                    printf("nevazeca opcija");
                }
                break;
            case 10:
                return 0;
                break;
            default:
                printf("uneli ste nevazeci broj\n\n");
        }
    }while((a < 1) || (a > 6));
    return 0;
}
