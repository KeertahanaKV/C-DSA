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
void infxtopostfix(char* infix,char* postfix)
{
    struct stack st;
    st.top=-1;
    int l=strlen(infix);
    int i;
    int index=0;
    char c;
    for(int i=0;i<l;i++)
    {
        c=infix[i];
        if(isOperand(c))
        {
            postfix[index++]=c;
        }
        else if(c=='(')
        {
            push(&st,c);
        }
        else if(c==')')
        {
            while(st.top>=0&&st.s[st.top]!='('){
            postfix[index++]=pop(&st);
            }
            pop(&st);
        }
        else
        {
         while(st.top>=0 &&(prec(st.s[st.top])>prec(c) ||(prec(st.s[st.top])==prec(c)&&assoc(c)=='l')))
         {
             postfix[index++]=pop(&st);
         }
         push(&st,c);
        }
    }
    while(st.top>=0)
    {
        postfix[index++]=pop(&st);
    }
    postfix[index]='\0';
    printf("postfix expression is %s",postfix);
}
void evalution(char* postfix)
{
    char c;
    int op1,op2;
    struct stack st;
    st.top=-1;
    int l=strlen(postfix);
    for(int i=0;i<l;i++)
    {
        c=postfix[i];
        if(isOperand(c))
        {
            push(&st,c-'0');
        }
        else
        {
            op2=pop(&st);
            op1=pop(&st);
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
    char postfix[MAX],infix[MAX];
    while(1){
    
        printf("\n0.Exit\n1.Conversion from infix to postfix\n2.Evalution of postfix expression\n");
        printf("enter your choice: ");
         scanf("%d", &choice);
        switch (choice)
        {
        case 0:return 0;
        case 1:
            printf("\nenter the infix expression:  ");
            scanf("%s", infix);
            infxtopostfix(infix,postfix);
            break;
         case 2:
         printf("enter the postfix expresion: ");
         scanf("%s",postfix);
         evalution(postfix);
         default:printf("\nChoose correct option");
       }
    }

    return 0;
  
}
