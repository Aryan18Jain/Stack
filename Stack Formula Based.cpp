#include<iostream>
using namespace std;
#define maxsize 100
int top=-1;
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(top==maxsize)
	return 1;
	else
	return 0;
}
void create(int st[],int n)
{
	if(isfull() || n>maxsize)
	{
		cout<<"Cant create stack";
		return;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<"Enter "<<i+1<<" element:";
			top++;
			cin>>st[top];
		}
	}
}
void display(int st[])
{
	if(isempty())
	{
		cout<<"Empty stack.";
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			cout<<st[i]<<endl;
		}
	}
}
void push(int st[],int x)
{
	if(isfull())
	{
		cout<<"Cant push element";
	}
	else if(top==-1)
	{
		top++;
		st[top]=x;
	}
	else
	{
		top++;
		st[top]=x;
	}
}
void pop(int st[],int &x)
{
	x=st[top];
	top--;
}
void peak(int st[],int &x)
{
	x=st[top];
}
int main()
{
	int choice,x,n;
	int stack[maxsize];
    while(1)
    {
    	cout<<endl<<endl<<endl;
    	cout<<"1. Create"<<endl;
    	cout<<"2. Push"<<endl;
    	cout<<"3. Pop"<<endl;
    	cout<<"4. Output"<<endl;
    	cout<<"5. Isfull"<<endl;
    	cout<<"6. Isempty"<<endl;
    	cout<<"7. Peak"<<endl;
    	cout<<"8. Exit"<<endl<<endl<<endl<<endl;
    	cout<<"Enter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			{
    				cout<<"Enter size of stack to form:";
    				cin>>n;
    				create(stack,n);
    				break;
				}
			case 2:
				{
					cout<<"Enter the data to push: ";
					cin>>x;
					push(stack,x);
					break;
				}
			case 3:
				{
					pop(stack,x);
					cout<<"Poped Element:"<<x;
					break;
				}
			case 4:
				{
					display(stack);
					break;
				}
			case 5:
				{
					x=isfull();
					if (x==0)
					cout<<"Space is available to create more elements."<<endl;
					else
					cout<<"Space full."<<endl;
					break;
				}
			case 6:
				{
					x=isempty();
					if(x==0)
					cout<<"Stack is not empty."<<endl;
					else
					cout<<"Stack list is empty."<<endl;
					break;
				}
			case 7:
				{
					peak(stack,x);
					cout<<"Peak element:"<<x;
					break;
				}
			case 8:
				{
					exit(1);
				}
			default:
				{
					cout<<"Invalid choice."<<endl;
				}
		}
	}
	return 0;
}
