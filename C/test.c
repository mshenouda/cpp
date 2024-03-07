#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void doFunc();
void doString();
void doStdio();
void doString();
void doStdlib();
void doCtype();

int main() {

    printf("Hello %d, %c, %s \n\n", 10, 'W', "World");
    //doFunc();
    //doStdio();
    //doString();
    //doStdlib();
    doCtype();    
    return 0;
}

void doCtype() {
    char str[]= "C3po45454...";
    int i=0;
    while(isalnum(str[i])) {
        i++;
    };
    printf("There are %d letters\n", i);

    i=0;
    char s[]="C++";
    while (s[i])
    {
        if (isalpha(s[i])) printf ("character %c is alphabetic\n",s[i]);
        else printf ("character %c is not alphabetic\n",s[i]);
        i++;
    }
}

void doStdlib() {
    const char* str = "1254";
    int i = atoi(str);
    printf("%d\n", i);
    const char* s = "125.356";
    float f = atof(s);
    printf("str %s=%f\n", s, f);

    char st[30] = "20.30300This is test";
    char *ptr;
    double ret;

    ret = strtod(st, &ptr);
    printf("The number(double) is %lf\n", ret);
    printf("String part is |%s|", ptr);
}

void doStdio() {
    FILE *fp;
    char ch;
    printf("Writing to the file...\n");
    fp = fopen("output.txt", "w");
    while((ch = getchar()) != EOF) {
        putc(ch, fp);
    };
    fclose(fp);
    printf("Reading from the file...\n");
    fp = fopen("output.txt", "r");
    while((ch = getc(fp)) != EOF) {
        putchar(ch);
    };
    fclose(fp);
}


void doFunc() {
    typedef struct
    {
        int id;
        char chr;
        //char str[10] {'H','E','L', '\0'};     
    } Object;
    
    printf("Input count of values\n");
    int count;
    scanf("%d",&count);    
    Object *Objs = (Object *) malloc(sizeof(Object) * count);
    
    //size_t n = sizeof(Objs)/sizeof(Objs[0]);
    for(int i=0; i<count; i++) {
        Objs[i].id = i;
        Objs[i].chr = (char)('a'+i);
        //Objs[i].str = 
    } 

    for(int i=0; i<count; i++) {
       printf("item%d = %d, %c\n", i, Objs[i].id, Objs[i].chr);
    }
    free(Objs);
    printf("\nExit, safely...\n");
}

void doString() {
    char str[12] = "Hello World\0";
    printf("%s, %d\n", str, strlen(str));
    char s[100];
    strcpy(s, "tutorials are good\0");
    puts(s);
    printf("length %d", strlen(s));
}