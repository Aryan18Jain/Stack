#include<iostream>
#include<string>
using namespace std;
struct stack
{
	char data;
	stack * link;	
};
int isempty(stack * p)
{
	if(p==NULL)
	return 1;
	else
	return 0;
}
int isfull()
{
	stack * temp=new stack;
	if(temp!=NULL)
	{
		delete (temp);
		return 0;
	}
	else
	return 1;
}
stack * create(stack * p , int n)
{
	for(int i=1;i<=n;i++)
	{
		int x;
		stack * temp=new stack;
		cout<<"Enter "<<i<<" element";
		cin>>x;
		temp->data=x;
		temp->link=p;
		p=temp;
	}
	return p;
}
stack * push(stack * p, char x)
{
	stack * temp=new stack;
	temp->data=x;
	temp->link=p;
	p=temp;
	return p;
}
stack * pop(stack * p, char &x)
{
	stack * q=p;
	x=q->data;
	q=q->link;
	delete(p);
	return q;
}
void display(stack * p)
{
	if(isempty(p))
	{
		cout<<"Empty Stack";
	}
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->link;
		
	}
}
char peak(stack * p)
{
	return p->data;
}
int priority(char ch)
{
    switch (ch)
    {
        case '$': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '%': return 2;
    }
    return-1;
}
int main()
{
    char p,q;
	stack * top=NULL;
	top=push(top,'$');
	string stmt;
	cout<<"Enter statement:";
	cin>>stmt;
	int i,j=0,len = stmt.length();
	char outcome[len];
	for(i=0;i<len;i++)
	{
		if(stmt[i]!='(' && stmt[i]!=')' && stmt[i]!='*' && stmt[i]!='-' && stmt[i]!='/' && stmt[i]!='%' && stmt[i]!='+')	
		{
			outcome[j]=stmt[i];
			j++;
		}
		else
		{
		    if(stmt[i]=='(')
		    top=push(top,stmt[i]);
		    else if (priority(stmt[i])>priority(peak(top)) || peak(top)=='(')
			top=push(top,stmt[i]);
			else if(peak(top)==')')
			{
			    top=pop(top,q);
			    while(peak(top)!='(')
			    {
			        top=pop(top,p);
			        outcome[j]=p;
			        j++;
			    }
			    top=pop(top,q);
			}
			else if(priority(stmt[i])==priority(peak(top)))
			{
			    top=pop(top,p);
			    outcome[j]=p;
			    j++;
			    top=push(top,stmt[i]);
			}
			else
			{
			    top=pop(top,p);
			    top=push(top,stmt[i]);
			    outcome[j]=p;
			    j++;
			}
		}
	}
	while(peak(top)!='$')
			{
			    top=pop(top,p);
			    outcome[j]=p;
			    j++;
			}
	outcome[j]='@';
	j=0;
	while(outcome[j]!='@')
	{
		cout<<outcome[j]<<" ";
		j++;
	}
	cout<<endl;
	display(top);
	return 0;
}
