#include<stdio.h>
#include<string.h>


typedef struct entry
{
    int n;
    char date[12];
}entry;

int checkUser(char [],char []);
void encrypt(char* );
void decrypt(char*, char* );
void readHandler( FILE*, entry*);

int main()
{
    /*char x = 'a';
    printf("%c\n", x+200000009);*/ //To check Possible encryptions
    /*char s[] = "password";       //Initial Setup to encrypt file manually. will change later. Must.
    encrypt(s);*/
    char us[20];
    char pw[10];
    printf("Enter Username: ");
    scanf("%s",&us);
    printf("Enter Password: ");
    scanf("%s",&pw);
    if(checkUser(us,pw)==1)
    {
        printf("\nValid User, Welcome to your Inner Sanctum");
    }
    else
    {
        printf("\nnew phone who dis");
        return 0;
    }
    FILE* f1 = fopen("fileHandler.txt", "r");
    entry top;
    readHandler(f1, &top);
    if(top.n==0)
    {
        printf("\nNo entries yet. ");
    }
    else
    {
        printf("\nThe last entry (number %d) was dated %s. ", top.n, top.date);
    }
    printf("\nWould you like to create a new entry for today? Or want to view an older entry?");

    return 0;
}

void readHandler(FILE* f1, entry* e)
{
    int n1;
    int n2;
    char buf[50];
    fscanf(f1,"%d\n",&n1);
    if(n1==0)
    {
        e->n = 0;
    }
    else
    {
        //printf("%d", n1);
        fscanf(f1, "%d %s\n",&n2, &buf);
        strcpy(e->date,buf);
        e->n = n2;
        //printf("\n%d %s", e->n, e->date);

    }
}

int checkUser(char u[],char p[])
{
    FILE* f1 = fopen("Login.txt","r");
    char s1[2][20],s[20];
    int i = 0;
    fscanf(f1,"%s\n%s",&s1[0],&s1[1]);
    /*while(fgets(s,20,f1)!=NULL && i<2)
    {
        printf("\n%s", s);
        //printf("Hello");                //Debugging
        strcpy(s1[i],s);
        i++;
    }*/
    //printf("\nêyïïÅçè|");
    //fgets(s2,10,f1);
    //printf("%s",s1[0]);                   //Error Checking
    //printf("\n%s",s1[1]);
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
    //printf("\n%d", l);
    for(int i = 0; i<l; i++)
    {
        //s[i] = s[i]+(3*l)%4;
        s[i] = s[i]+i;
    }
    printf("%s\n",s);
}

void decrypt(char *s, char* res)
{
    int l = strlen(s);
    for(int i = 0; i<l; i++)
    {
        //res[i] = s[i]-(3*l)%4;
        res[i] = s[i]-i;
    }
    //printf("%s\n",res);
}                                       
