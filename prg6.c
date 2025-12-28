#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 20
int top=-1;
int G(char symb)
{
switch(symb)
{
case '+':
case '-':return 1;
case '*':
case '%':
case '/':return 3;
case '^':
case '$':return 6;
case '(':return 9;
case ')':return 0;
default:return 7;
}
}int F(char symb)
{
switch (symb)
{
case '+':
case '-':return 2;
case '*':
case '%':
case '/':return 4;
case '$':
case '^':return 5;case '(':return 0;
case '#':return -1;
default:return 8;
}
}void infix_postfix(char inf[],char pos[])
{
int i,j=0;
char symb;
char s[30];
s[++top]='#';
for(i=0;i<strlen(inf);i++)
{
symb=inf[i];
while(F(s[top])>G(symb))
{
pos[j++]=s[top--];
}
if(F(s[top])!=G(symb))
s[++top]=symb;
else
top--;
}
while(s[top]!='#')
{
pos[j++]=s[top--];
}
pos[j]='\0';
printf("Expression in Postfix Format: ");
for(i=0;i<strlen(inf);i++)
printf("%c",pos[i]);
}
void main()
{
char inf[30],pos[30];
printf("Enter an Expression in Infix format:\n");scanf("%s",inf);
infix_postfix(inf,pos);
}