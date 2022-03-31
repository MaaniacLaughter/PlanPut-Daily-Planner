#include<stdio.h>
#include<string.h>

int checkUser(char [],char []);
void encrypt(char* );
void decrypt(char*, char* );

int main()
{
    /*char s[] = "Maani";       Initial Setup to encrypt file manually. will change later. Must.
    encrypt(s);*/
    char us[20];
    char pw[10];
    printf("Enter Username: ");
    scanf("%s",&us);
    printf("Enter Password: ");
    scanf("%s",&pw);
    if(checkUser(us,pw)==1)
    {
        printf("Valid User, Welcome to your Inner Sanctum");
    }
    else
    {
        printf("new phone who dis");
    }
    return 0;
}

int checkUser(char u[],char p[])
{
    FILE* f1 = fopen("Login.txt","r");
    char s1[2][20],s[20];
    int i = 0;
    //fscanf(f1,"%s\n%s",&s1,&s2);
    while(fgets(s,20,f1)!=NULL && i<2)
    {
        printf("\n%s", s);
        //printf("Hello");                //Debugging
        strcpy(s1[i],s);
        i++;
    }
    printf("\nêyïïÅçè|");
    //fgets(s2,10,f1);
    printf("%s",s1[0]);                   //Error Checking
    printf("\n%s",s1[1]);
    decrypt(s1[0],s1[0]);
    decrypt(s1[1],s1[1]);
    /*printf("%s",s1[0]);                 //Error Checking
    printf("\n%s",s1[1]);*/
    if(strcmpi(u,s1[0])==0 && strcmpi(p,s1[1])==0)
        return 1;
    else return 0;
}

void encrypt(char *s)
{
    int l = strlen(s);
    printf("\n%d", l);
    for(int i = 0; i<l; i++)
    {
        s[i] = s[i]+(3*l)%256;
    }
    printf("\n%s",s);
}

void decrypt(char *s, char* res)
{
    int l = strlen(s);
    for(int i = 0; i<l; i++)
    {
        res[i] = s[i]-(3*l)%256;
    }
}                                       