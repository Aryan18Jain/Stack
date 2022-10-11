#include<iostream>
using namespace std;
struct stack
{
	int data;
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
stack * push(stack * p, int x)
{
	stack * temp=new stack;
	temp->data=x;
	temp->link=p;
	p=temp;
	return p;
}
stack * pop(stack * p, int &x)
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
void peak(stack * p , int &x)
{
	x=p->data;
}
int main()
{
	int choice,x,n;
	stack * top=NULL;
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
    				top=create(top,n);
    				break;
				}
			case 2:
				{
					cout<<"Enter the data to push: ";
					cin>>x;
					top=push(top,x);
					break;
				}
			case 3:
				{
					top=pop(top,x);
					cout<<"Poped Element:"<<x;
					break;
				}
			case 4:
				{
					display(top);
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
					x=isempty(top);
					if(x==0)
					cout<<"Stack is not empty."<<endl;
					else
					cout<<"Stack list is empty."<<endl;
					break;
				}
			case 7:
				{
					peak(top,x);
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
