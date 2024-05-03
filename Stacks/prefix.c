#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 100
struct stack
{
    int top;
    char s[MAX];
};
void push(struct stack* st,char c)
{
    if(st->top==MAX-1)
    {
        printf("stack is full\n");
        return;
    }
    st->s[++(st->top)]=c;
}
char pop(struct stack* st)
{
    if(st->top==-1)
    {
        printf("stack underflow\n");
        return -1;
    }
    return st->s[(st->top)--];
}
int prec(char c)
{
    switch (c)
    {
    case '^':
    case '$':
        return 3;
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

char assoc(char c)
{
    if (c == '^' || c == '$')
        return 'r';
    return 'l';
}

int isOperand(char c)
{
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9');
}
void reverse(char* expr)
{
    int l=strlen(expr);
    int i=0;
    int j=l-1;
    while(i<j)
    {
        int temp=expr[i];
        expr[i]=expr[j];
       expr[j]=temp;
        i++;
        j--;
        
        
    }
}
void infxtoprefix(char* infix,char* prefix)
{
    struct stack st;
    st.top=-1;
    int l=strlen(infix);
    reverse(infix);
    int i;
    int index=0;
    char c;
    for(i=0;i<l;i++)
    {
        if(infix[i]=='(')
        {
        infix[i]=')';
            
        }
       else  if(infix[i]==')')
       {
        infix[i]='(';
           
       }
    }
    for(int i=0;i<l;i++)
    {
        c=infix[i];
        if(isOperand(c))
        {
            prefix[index++]=c;
        }
        else if(c=='(')
        {
            push(&st,c);
        }
        else if(c==')')
        {
            while(st.top>=0&&st.s[st.top]!='('){
            prefix[index++]=pop(&st);
            }
            pop(&st);
        }
        else
        {
         while(st.top>=0 &&(prec(st.s[st.top])>prec(c) ||(prec(st.s[st.top])==prec(c)&&assoc(c)=='r')))
         {
             prefix[index++]=pop(&st);
         }
         push(&st,c);
        }
    }
    while(st.top>=0)
    {
        prefix[index++]=pop(&st);
    }
    prefix[index]='\0';
    reverse(prefix);
    printf("prefix expression is %s",prefix);
}
void evalution(char* prefix)
{
    char c;
    int op1,op2;
    struct stack st;
    st.top=-1;
    int l=strlen(prefix);
    for(int i=l-1;i>=0;i--)
    {
        c=prefix[i];
        if(isOperand(c))
        {
            push(&st,c-'0');
        }
        else
        {
            op1=pop(&st);
            op2=pop(&st);
            switch(c)
            {
                case '+':push(&st,(op1+op2));
                  break;
              case '*':push(&st,(op1*op2));
                break;
                case '-':push(&st,(op1-op2));
                break;
                case '%':push(&st,(op1%op2));
                break;
                case '/':push(&st,(op1/op2));
                break;
                case '^':push(&st,pow(op1,op2));
                break;
                case '$':push(&st,pow(op1,op2));
                break;
            }
            
        }
    }
    int result=pop(&st);
    printf("%d",result);
}
int main()
{
    int choice;
    char prefix[MAX],infix[MAX];
    while(1){
    
        printf("\n0.Exit\n1.Conversion from infix to prefix\n2.Evalution of prefix expression\n");
        printf("enter your choice: ");
         scanf("%d", &choice);
        switch (choice)
        {
        case 0:return 0;
        case 1:
            printf("\nenter the infix expression:  ");
            scanf("%s", infix);
            infxtoprefix(infix, prefix);
            break;
         case 2:
         printf("enter the prefix expresion: ");
         scanf("%s",prefix);
         evalution(prefix);
         default:printf("\nChoose correct option");
       }
    }

    return 0;
  
}
