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
void peak(stack * p , char &x)
{
	x=p->data;
}
int main()
{
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
			top=push(top,stmt[i]);
		}
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
